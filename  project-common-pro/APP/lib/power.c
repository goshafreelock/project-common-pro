/*--------------------------------------------------------------------------*/
/**@file    power.c
   @brief   电源管理
   @details
   @author
   @date   2011-3-7
   @note
*/
/*----------------------------------------------------------------------------*/
#include "Custom_config.h"
#include "power.h"
#include "main.h"
#include "msgfor_usb.h"

bool sys_clock_flag;  ///<AD
u8 clock_change_delay;
#if defined(POWER_KEY_ON_WAIT_FOR_3_SEC	)||defined(USE_PWR_KEY_LONG_PWR_ON)
xd_u8 pwr_key_cnt = 0;
#if defined(K223_BTL_CP153_V001)||defined(USE_PWR_KEY_LONG_PWR_ON)
#define PWR_KEY_TIMER	2		
#elif defined(PWR_ON_DELAY_2_SECOND)
#define PWR_KEY_TIMER	2
#elif defined(PWR_ON_DELAY_1_SECOND)
#define PWR_KEY_TIMER	1		
#else
#define PWR_KEY_TIMER	2*3		
#endif
#endif
#if defined(USE_BAT_MANAGEMENT)	
#if defined(CHARGER_DETECT_INDICATOR)
extern bool charger_in_flag;
#endif
bool key_pwr_up_flag=0;
#endif
extern _xdata u8 alm_flag;
extern _xdata SYS_WORK_MODE work_mode;

extern void lcd_power_down(void);
extern void stop_decode(void);
extern void my_main_vol(u8 my_vol);
extern void set_play_flash(u8 led_status);
extern void fm_rev_powerdown(void);


#ifdef DC_HW_POWER_UP
#define DC_HW_POWER_PORT	P17
#define Init_dc_hw_if()		P17 =0;P1PU  &= ~(BIT(7)); P1PDA |= (BIT(7));P1DIR |= (BIT(7));
#endif

#ifdef DC_HW_POWER_UP_IN_IDLE_MODE
#define DC_HW_POWER_PORT	P11
#define Init_dc_hw_if()		P11 =0;P1PU  &= ~(BIT(1));P1DIR |= (BIT(1));
#endif
/*----------------------------------------------------------------------------*/
/**@brief 系统进入省电(sleep)模式
   @param 无
   @return  无
   @note 系统进入省电模式后，芯片功耗为200uA以下，通过P00,P05,P07,P34可以唤醒芯片，芯片起来后，按reset模式运行(不会接着运行后面的程序)\n
   系统晶振为24M时，不支持此功能\n
   如果芯片的供电是通过一个软件开关(如MOS管)，当需要关机时，不需要调用此函数，直接关掉MOS管就可以了。
*/
/*----------------------------------------------------------------------------*/
void system_sleep(void)
{
#if OSC_CLOCK == 24000000L
#else
    dac_off();				//关闭DAC，需要约3S钟才没有杂音，如果功放有mute功能，也可以将此句换成mute功放.由于dac_off()调用了delay_10ms，所以在这之前不能关中断
    EA = 0;
    DACCON0 = 0xc0;			//再次关DAC，如果没有执行dac_off(),DAC同样可以被关掉，只是会有杂音，但如果控制了功放的mute，也不会有杂音
    DACCON1 = 0;
    DACCON2 = 0;
    Delay(20000);
    USBCON0 = 0;			//关USB
    ADCCON = 0;				//关ADC
    P0DIR = 0xFF;			//关IO，具体的原则为：所有IO必须为数字功能，并设成输出，如果IO已经被外围电路拉成了固定状态（如一个用于选择FM芯片的IO口，已经通过外部电阻接到地），
    P1DIR = 0xFF;			//则不用再作其它处理，但如果IO是悬空的，则需要将其上拉或下拉打开，保证其电平不会处于浮空。
    P2DIR = 0xFF;
    P3DIR = 0xFF;
    P4DIR = 0xFF;

    P0IE = 0xff;
    P0PU = 0;
    P1PU = 0;
    P2PU = 0xff;
    P3PU = 0;
    P4PU = 0xff;

    P0PD = 0x7f;			//本例中，P07正常时作为ADKEY使用，sleep后，作为数字口，通过下降沿来reset系统，因ADKEY外部有上拉，所以内部不能开上，下拉
    P1PDB = 0;
    P1PDA = 0xff;
    P3PD = 0xff;

#if OSC_CLOCK == 7600000L
    PLL_input(PLL_IN_76M);
#endif

#if OSC_CLOCK == 12000000L
    PLL_input(PLL_IN_12M);
#endif

    Delay(1000);
    P3IE = 0x7F;

#if OSC_CLOCK == 32768L
    mainclock_select(MAIN_CLK_32K);
#else
    CLKCON |= 0X4;
    mainclock_select(MAIN_CLK_RC);
#endif

    CLKCON &= ~0x36;
    WKUPPND &= 0xf0;
    WKUPCON |= BIT(2) | BIT(6);			//本例使用P07作为唤醒IO
    PCON = 1;
#endif
}
#if defined(PWR_CTRL_WKUP)||defined(WKUP_PIN_USE_ENABLE)
/***
RTC 控制寄存器，BIT4 = 1时　或　闹钟有效时　打开WKUP的1.8V输出；BIT4 = 0　且　闹钟无效时　关闭WKUP的1.8V输出。在对BIT4操作时必须位操作，不能改动到该寄存器其他位的值。
　　读写RTC 控制寄存器的函数分别是：
　　u8 read_rtc_reg(void)
　　void write_rtc_reg(u8 cmd)
---------------------------------------------------------------------------------------------------
*********************************/
/**@brief        WKUP输出控制函数
@param     dir:1输出1.8V；0：关闭输出
@return
@note        void wkup_ctl(bool dir) 
/*********************************/
#define IRTC_CSEN_LIB    IRTCON |= BIT(0)
#define IRTC_CSDIS_LIB   IRTCON &= ~(BIT(0))
void wkup_pin_ctrl(bool dir)    
{
	u8 tmp;
	IRTC_CSEN_LIB;
	irtc_sr_byte(0x3b);
	tmp = irtc_sr_byte(0);
	IRTC_CSDIS_LIB;
	if(dir)
	{
		IRTC_CSEN_LIB;
		irtc_sr_byte(0x3a);
		irtc_sr_byte(tmp|BIT(4));
		IRTC_CSDIS_LIB;
	}
	else
	{
		IRTC_CSEN_LIB;
		irtc_sr_byte(0x3a);
		irtc_sr_byte(tmp&~(BIT(4)));
		IRTC_CSDIS_LIB;
	 }
}
#endif
/*----------------------------------------------------------------------------*/
/**@brief   设置系统时钟工作在RC上
   @param   无
   @return  无
   @note    void sys_clock_rc(void)
*/
/*----------------------------------------------------------------------------*/
#pragma disable
void sys_clock_rc(void)
{
#if !defined(USE_AUTO_FREQ)
   return;
#endif
    mainclock_select(MAIN_CLK_RC);
    sd_speed_init(0, 3);
    SPIBAUD = 0x0;
    sys_clock_flag = 0;
}

/*----------------------------------------------------------------------------*/
/**@brief   设系统时钟工作在PLL上
   @param   无
   @return  无
   @note    void sys_clock_pll(void)
*/
/*----------------------------------------------------------------------------*/
#pragma disable
void sys_clock_pll(void)
{
    SPIBAUD = 0x04;
    sd_speed_init(1, 200);
    mainclock_select(MAIN_CLK_PLL);
    sys_clock_flag = 1;
    clock_change_delay = 0;
}
/*----------------------------------------------------------------------------*/
/**@brief   等待开机的电源按键抬起
   @param    无
   @return   无
   @note    void waiting_power_key()
*/
/*----------------------------------------------------------------------------*/
#if defined(USE_TIMER_POWER_OFF_FUNC)
void timer_pwr_off()
{
	lcd_power_down();
#ifdef USE_PWR_KEY_LONG_PWR_ON
	key_pwr_up_flag =0;
	flush_all_msg();
     	Mute_Ext_PA(MUTE);
     	main_vol(0);
	EA = 0;
#if defined(PWR_CTRL_WKUP)
    	wkup_pin_ctrl(0);
#else
    	power_ctl(0);
#endif

#endif
		
}
#endif
#ifdef  USE_POWER_KEY

#if defined(DC_HW_POWER_UP_IN_IDLE_MODE)|| defined(USB_SD_PORTABLE_BAT_CHARGER)
bool dc_hw_pwer_up_sel_mode=0;
#endif
void waiting_power_key()
{
 #if defined(USE_PWR_KEY_LONG_PWR_ON)
 	u8 key=0,power_down_cnt=0;
#endif
    Pwr_Key_output();
    Pwr_Key_Init();
#if defined( DC_HW_POWER_UP	)||defined(DC_HW_POWER_UP_IN_IDLE_MODE)
	Init_dc_hw_if();
#endif

#if defined(BT_CONFIG_POWER_ON_ENABLE)
	BT_CONFIG_PORT_INIT();
	BT_CONFIG_ON();
#endif

#if defined(POWER_KEY_ON_WAIT_FOR_3_SEC	)
	 set_play_flash(LED_FLASH_STOP);	
	pwr_key_cnt = 0;
#if defined(USE_BAT_MANAGEMENT)	
	key_pwr_up_flag =0;
#endif

    while (GPIO_POWER_KEY)
    {
	if(pwr_key_cnt >PWR_KEY_TIMER)
		goto __PWR_ON;
    }
	
// key release 	
	if(pwr_key_cnt >=PWR_KEY_TIMER)
	{
		//break;
	}
	else{
		
	    //sys_printf("sys_power_down");
	    EA = 0;
#if defined(PWR_CTRL_WKUP)
	    wkup_pin_ctrl(0);
#else
	    power_ctl(0);
#endif
	    while (1);

	}
__PWR_ON:	
	//printf(" waiting_power_key %d \r\n",(u16)pwr_key_cnt);
	set_play_flash(LED_FLASH_ON);
    	Disp_Con(DISP_START);//zdy 0321 add  dispay "HI" when power on 
#if defined(USE_BAT_MANAGEMENT)	
	key_pwr_up_flag =1;
#endif
	pwr_key_cnt = 0;



#else




#if defined(USE_ONLY_POWER_HOLD_CTRL)
#if defined(USE_PWR_KEY_LONG_PWR_ON)
#if defined(USE_BAT_MANAGEMENT)	
     key_pwr_up_flag =0;
#endif
     set_play_flash(LED_FLASH_STOP);
#ifndef NO_LED_DISPLAY
     lcd_power_down();
#endif
     flush_all_msg();
     Mute_Ext_PA(MUTE);
     pwr_key_cnt = 0;
    set_play_flash(LED_FLASH_STOP);
     while(1){
		key = get_msg();
#ifdef DC_HW_POWER_UP	
		if(DC_HW_POWER_PORT){
			if(pwr_key_cnt >1)
				goto __PWR_UP;
		}
#elif defined(USE_PC_DC_POWER_ON_ONLY)
		//delay_10ms(6);
		if(get_usb_pc_status()){
			if(pwr_key_cnt >1)
				goto __PWR_UP;
		}
	
#elif defined(USB_SD_PORTABLE_BAT_CHARGER)

		BATT_CHARGER_PORT_INIT();
		if(BATT_CHRG_PORT){		

			dc_hw_pwer_up_sel_mode=1;			
			power_ctl(1);
			goto __PWR_UP;
		}

#endif

#ifdef DC_HW_POWER_UP_IN_IDLE_MODE
		if(DC_HW_POWER_PORT){
			dc_hw_pwer_up_sel_mode=1;
			//if(pwr_key_cnt >1)
				goto __PWR_UP;
		}
#endif

#ifdef PWR_OFF_WAKEUP_FUNC
		   if(alm_flag>0){
#if defined(PWR_CTRL_WKUP)
			    wkup_pin_ctrl(1);
#else
			    power_ctl(1);
#endif
				goto __PWR_UP;
		   }
#endif

		if(key == (INFO_POWER|KEY_HOLD)){

#if defined(BT_CONFIG_POWER_ON_ENABLE)
			power_down_cnt = 0;
			if(pwr_key_cnt>2){

				if(pwr_key_cnt>=3){
					set_play_flash(LED_FLASH_ON);
				}
				
				if(pwr_key_cnt>12){
					goto __PWR_UP;
				}
			}
#else
			if(pwr_key_cnt >1)
				goto __PWR_UP;
			power_down_cnt = 0;
#endif			

		}
		else if(key==0xFF){
#if defined(BT_CONFIG_POWER_ON_ENABLE)
			power_down_cnt++;
			if(power_down_cnt>120){
				
				if(pwr_key_cnt>=3){
					goto __PWR_UP;
				}
				else{
					    EA = 0;
#if defined(PWR_CTRL_WKUP)
					    wkup_pin_ctrl(0);
#else
					    power_ctl(0);
#endif
					    while (1);
				}
			}

#else			
			if(power_down_cnt++>250){
			    EA = 0;
#if defined(PWR_CTRL_WKUP)
			    wkup_pin_ctrl(0);
#else
			    power_ctl(0);
#endif
			    while (1);
				
			}
#endif
			
		    delay_10ms(1);
		}
    }
 __PWR_UP:

#if defined(BT_CONFIG_POWER_ON_ENABLE)
	BT_CONFIG_PORT_INIT();
	BT_CONFIG_OFF();
#endif
	
	set_play_flash(LED_FLASH_ON);
    	Disp_Con(DISP_START);
#if defined(USE_BAT_MANAGEMENT)	
	key_pwr_up_flag =1;
#endif		
#endif

#else
    while (GPIO_POWER_KEY)
    {
    }
#endif

#endif
}
#endif
/*----------------------------------------------------------------------------*/
/**@brief  设置RC时钟分频
   @param   无
   @return  无
   @note    void adc_clock(void)
*/
/*----------------------------------------------------------------------------*/
void adc_clock(void)
{
    if (sys_clock_flag)
    {
        ADCCON |= 0x30;
    }
}

/*----------------------------------------------------------------------------*/
/**@brief    PLL延时，完毕后恢复到RC时钟模式
   @param    无
   @return   无
   @note     void rc_pll_delay(void)
*/
/*----------------------------------------------------------------------------*/
void rc_pll_delay(void)
{
    if (clock_change_delay < 2)
    {
        clock_change_delay++;
    }
    else if (clock_change_delay<6)
    {
        clock_change_delay = 100;
        sys_clock_rc();
    }
}
/*----------------------------------------------------------------------------*/
/**@brief    系统掉电函数
   @param    无
   @return   无
   @note     void sys_power_down(void)
*/
/*----------------------------------------------------------------------------*/
#ifdef  USE_POWER_KEY
void sys_power_down(void)
{
#if defined(USE_ONLY_POWER_HOLD_CTRL)
	u8 key=0;
	static u8 power_down_cnt=0;
#endif

    //lcd_power_down();
#if defined(POWER_KEY_ON_WAIT_FOR_3_SEC)
	if((pwr_key_cnt&0x80)==0x00){
		
		pwr_key_cnt|=0x80;
		pwr_key_cnt&=0xF0;
		return;
	}
	
	if((pwr_key_cnt&0x0F) <PWR_KEY_TIMER)
	{
		return ;
	}
	else{
    		//sys_printf("pre  sys_power_down");
#if defined(USE_BAT_MANAGEMENT)	
		key_pwr_up_flag =0;
#endif    		
    		Disp_Con(DISP_PWR_OFF);
		set_play_flash(LED_FLASH_STOP);	
    		stop_decode();
		my_main_vol(0);
		
		if(work_mode!= SYS_IDLE)
			
    		Pwr_Key_output();
	    	Pwr_Key_Init();
		while(GPIO_POWER_KEY);//untill key up to power down the device
		//power down
	}
#endif

    //sys_printf("sys_power_down");
	
#if defined(USE_ONLY_POWER_HOLD_CTRL)

	power_down_cnt++;

	if(power_down_cnt++<12){
		
		return ;
	}
	else{
		
		//goto __PWR_DOWN;
	}
//__PWR_DOWN:	
     flush_all_msg();
     Mute_Ext_PA(MUTE);
     my_main_vol(0);
#if defined(USE_BAT_MANAGEMENT)	
	key_pwr_up_flag =0;
#endif
    set_play_flash(LED_FLASH_STOP);
#endif
#if defined(K1069_AJE_1069_V001)||defined(K1069_AJE_1069_V002)||defined(DISP_OFF_STR_AT_PWR_DOWN)||defined(DISP_OFF_ANIMIATION_AT_PWR_DOWN)
	Disp_Con(DISP_PWR_OFF);
#endif	

#ifndef NO_LED_DISPLAY    
    lcd_power_down();
    //delay_10ms(20);
#endif

    main_vol_set(0, CHANGE_VOL_NO_MEM);

    fm_rev_powerdown();

#ifdef BLUETOOTH_GPIO_CTRL
    BT_PWR_OFF();
#endif 

    delay_10ms(10);//4 wait for  all off

    EA = 0;

#if defined(PWR_CTRL_WKUP)
       wkup_pin_ctrl(0);
	//write_rtc_reg((read_rtc_reg()&0xef));
#else
    power_ctl(0);
#endif
    while (1);
}

/*----------------------------------------------------------------------------*/
/**@brief   系统上电函数
   @param   无
   @return  无
   @note    void sys_power_up(void)
*/
/*----------------------------------------------------------------------------*/
void sys_power_up(void)
{
#if defined(PWR_CTRL_WKUP)
    wkup_pin_ctrl(1);
	//write_rtc_reg((read_rtc_reg()|0x10));
#else
    power_ctl(1);
#endif
   
}
#endif
