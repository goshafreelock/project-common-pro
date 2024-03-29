/*--------------------------------------------------------------------------*/
/**@file     main.c
   @brief    主流程
   @details
   @author
   @date   2010-12-13
   @note   AC209N
*/
/*----------------------------------------------------------------------------*/
#include "Custom_config.h"
#include "main.h"
#include "device.h"
#include "lcd.h"
#include "led.h"
#include "fm_rev.h"
#include "fat_memory.h"
#include "uart.h"
#include "voice_time.h"
#include "aux_fun.h"
#include "aux_fun.h"
#include "msgfor_usb.h"
#include "rtc_mode.h"
#if OTP_MUSIC_ENABLE
#include "decode_otp.h"
#include "music_resource.h"
#endif
#ifdef FM_TRANSMITTER
#include "bk1085.h"
#endif
#include "bluetooth.h"

#if defined(KPL_MSG_COMPATIBLE)
#include "kpl_msg.h"
#endif

#include "PT2313.h"

extern u8 _idata  my_music_vol;  
extern xd_u8 curr_menu;
extern bit pc_connect;
extern bit iic_busy;

extern u16 digital_max_vol;
_xdata SYS_WORK_MODE work_mode;
u8 _xdata win_buffer[512] _at_ 0x600;
u16 cfilenum;
bool aux_online=0;
extern bool key_scan_en;
extern xd_u8 IR_Type;
extern bool pwr_up_flag;
extern u8 play_status;
extern xd_u8 dac_cnt;
extern u8  return_cnt;
#ifdef AC_SLAVE_ENABLE
extern void DSA_init(void);
extern bool DSA_GETHERING_DATA_ENABLE_BIT;
#endif
extern bool IR_KEY_Detect;

#ifdef LED_DRV_USE_SM1628_KEY_FUNC
extern void Read_key();
#endif

#ifdef BLUE_TOOTH_GPIO_STATUS
extern bool blue_tooth_detect;
#endif

#ifdef USE_SYS_MODE_RECOVER
bool sys_mode_recove=0;
#endif
#ifdef SPECTRUM_FUNC_ENABLE
extern bool spectrum_reflesh_en;
#endif
#if defined(DC_HW_POWER_UP_IN_IDLE_MODE)|| defined(USB_SD_PORTABLE_BAT_CHARGER)
extern bool dc_hw_pwer_up_sel_mode;
#endif

#if defined(DEFAULT_GO_TO_CUSTOM_MODE)
extern bool custom_first_time_pwr_flag;
#endif

#if defined(SYS_DEFAULT_IN_PWR_OFF_FOR_LED_PROTECTION)||defined(SYS_LED_PROTECTION_UNTILL_PWR_ON)
extern bool sys_pwr_on_led_protect_bit;
#endif

#if defined(FM_TRANSMITTER)
extern void bk1085_init(void);
#endif
#if defined(TWO_PLAY_LED_IN_USE)
extern bool led_open_enable;
#endif
#if defined(EEPROM_RTC_RAM_COMPATIBLE)
extern void check_eeprom_status(void);
#endif

#ifdef USE_CUSTOMIED_GPIO_KEY
extern bool gpio_key_scan_bit;
#endif

#ifdef GPIO_SWITCH_SELECT_MODE
extern bool gpio_select_enable;
#endif

#if defined(K619_FXK_619_V001)
extern bool config_led_by_gpio;
#endif

#if defined(USE_BAT_MANAGEMENT)		
extern xd_u8 LDO_IN_Volt;
#endif

#if defined(POWER_KEY_ON_WAIT_FOR_3_SEC	)||defined(USE_PWR_KEY_LONG_PWR_ON)
extern xd_u8 pwr_key_cnt;
#endif
#if defined(SYS_GO_IN_IDLE_IN_30_SEC)
extern xd_u8 sys_idle_cnt;
#endif

#ifndef VOLUME_DEFUALT
#define VOLUME_DEFUALT 	0
#endif
extern void main_vol(u8 vol);
extern void set_play_flash(u8 led_status);
extern void check_earphone_gpio(void);
#if defined(IPONE_INDEPENDENT_MODE)&&defined(IPHONE_DETECT_IN_USE)
void iphone_tx_detect_polling();
#endif

#if defined(CUSTOMIZED_KEY_FUNC_ENABLE)
void gpio_ctrl_if(bool ctrl_f);
#endif

#if defined(CUSTOM_FUNC_POLLING)
extern bool custom_func_tick;
#endif

#ifdef GPIO_SEL_M62429_FUNC
extern bool select_m62429;
#endif 

//u8 _idata bP0IE;
/*----------------------------------------------------------------------------*/
/**@brief 	P0IE初始化函数
   @param 	无
   @return  无
   @note 	void P0IE_init(void)
*/
/*----------------------------------------------------------------------------*/
void P0IE_init(void)
{
	//bP0IE = 0xff;		 	//P0IE reset:0xff
}
/*----------------------------------------------------------------------------*/
/**@brief 	P0IE控制函数(由于P0IE寄存器不能读,不建议用户使用&=/|=这样的操作)
   @param 	sel:置位/清零；dat：写入P0IE的位
   @return  无
   @note 	void P0IE_ctl(u8 sel, u8 dat)
*/
/*----------------------------------------------------------------------------*/
#if 0
void P0IE_ctl(u8 sel, u8 dat)
{
	if (sel)
	{
		bP0IE |= BIT(dat);
	}
	else
	{
		bP0IE &= ~(BIT(dat));
	}
	P0IE = bP0IE;		
}
#endif
/*----------------------------------------------------------------------------*/
/**@brief LINE IN 在线检测
   @param 无
   @return  无
   @note void aux_check(void)
*/
/*----------------------------------------------------------------------------*/
#ifdef USE_BT_GPIO_DETECTION
bool bt_online=0;
static void bt_check(void)
{
    static u8 bt_cnt_online;

#if defined(BT_DETECT_SHARE_WITH_IIC)
    if (iic_busy)
    {
        return;
    }
#endif	

    BT_GPIO_INIT();
    _nop_();  _nop_();

    if (!BT_GPIO_READ)
    {
        bt_cnt_online = 0;
        if (bt_online)
        {
            bt_online = 0;
            //put_msg_lifo(INFO_BT_MOD | KEY_SHORT_UP);
        }
    }
    else
    {
        bt_cnt_online++;
        if (bt_cnt_online > 6)
        {
            if (!bt_online)
            {
#ifdef BLUE_TOOTH_DETECTION_FOR_POWER_OFF
                put_msg_lifo(INFO_POWER| KEY_SHORT_UP);

#else
                put_msg_lifo(INFO_BT_MOD | KEY_SHORT_UP);
#endif
                bt_online = 1;
            }
        }
    }
    BT_GPIO_RELEASE(); //linein check port
}
#endif

#ifdef USE_MICPHONE_GPIO_DETECTION
bool mic_online=0;
static void mic_check(void)
{
    static u8 mic_cnt_online;

#if defined(MIC_DETECT_SHARE_WITH_IIC)
    if (iic_busy)
    {
        return;
    }
#endif	

    MICPHONE_GPIO_INIT();
    _nop_();  _nop_();
#ifdef MIC_HIGH_LEVEL_DETECT_FUNC
    if (!MICPHONE_GPIO_READ)
#else
    if (MICPHONE_GPIO_READ)
#endif		
    {
        mic_cnt_online = 0;
        if (mic_online)
        {
            mic_online = 0;
            put_msg_lifo(MSG_MIC_OUT);
        }
    }
    else
    {
        mic_cnt_online++;
        if (mic_cnt_online > 6)
        {
            if (!mic_online)
            {
                put_msg_lifo(MSG_MIC_IN);
                //mic_online = 1;
            }
        }
    }
    MICPHONE_GPIO_RELEASE(); //linein check port
}
bool get_mic_online_status(void)
{
	return mic_online;
}
#endif

#if defined(USE_GPIO_DETECT_EARPHONE_PLUGGED)
#ifndef USE_ADKEY_DETECT_HP
extern bool earphone_plugged_flag;
void hpone_check(void)
{
    static u8 hp_cnt_online;

#ifdef HP_DETECT_SHARE_WITH_IIC_SCL
    if (iic_busy)
    {
        return;
    }
#endif	

#if defined(INDEPENDENT_EARPHONE_DETECT_GPIO)

#if !defined(USE_IR_VPP_PORT_FOR_DETECTION)
	EARPHONE_DETECT_GPIO=1;
#endif

#else
	if(EARPHONE_DETECT_GPIO==0)return;
#endif

    hp_detect_begin();
	
    //DACCON0 |= 0x80;
    _nop_();
    _nop_();
    _nop_();
    if (EARPHONE_DETECT_GPIO)
    {
        hp_cnt_online = 0;

        if (earphone_plugged_flag)
        {
            //put_msg_lifo(MSG_AUX_OUT);
            earphone_plugged_flag = 0;
        }
    }
    else
    {
        hp_cnt_online++;
        if (hp_cnt_online > 12)
        {
            if (!earphone_plugged_flag)
            {
                //put_msg_lifo(MSG_AUX_IN);
                earphone_plugged_flag = 1;
            }
        }
    }
    hp_detect_in_off(); //linein check port
}
#endif
#endif

#ifndef NOT_USE_LINE_IN_FUNC
#ifdef USE_LINE_IN_DETECT_FUNC
#ifndef USE_ADKEY_DETECT_AUX
#include "gpio_config.h"
void aux_check(void)
{
    static u8 aux_cnt_online;

#ifdef AUX_DETECT_SHARE_WITH_IIC_SCL
    if (iic_busy)
    {
        return;
    }
#endif	

#ifdef SYS_LED_PROTECTION_UNTILL_PWR_ON
#ifdef AUX_LED_PROTECTION_BEFORE_PWR_ON
	 if(sys_pwr_on_led_protect_bit)return;
#endif	 
#endif

#ifdef AUX_DETECT_HIGH_LEVEL
	AUX_DETECT_GPIO=0;

#else
#if defined(INDEPENDENT_AUX_DETECT_GPIO)
	AUX_DETECT_GPIO=1;
#elif defined(AUX_DETECT_USE_VPP)

#elif defined(LINE_IN_DETECT_SHARE_LED_STATUS_PORT)
	if(AUX_DETECT_GPIO==0)return;
#else
	//if(AUX_DETECT_GPIO==0)return;
#endif
#endif
    aux_detect_in();
	
    //DACCON0 |= 0x80;
    _nop_();
    _nop_();
    _nop_();

#ifdef AUX_DETECT_HIGH_LEVEL
    if (!AUX_DETECT_GPIO)
#else
    if (AUX_DETECT_GPIO)
#endif		
    {
        aux_cnt_online = 0;

        if (aux_online)
        {
            put_msg_lifo(MSG_AUX_OUT);
            aux_online = 0;
        }
    }
    else
    {
        aux_cnt_online++;
        if (aux_cnt_online > 20)
        {
            if (!aux_online)
            {
                put_msg_lifo(MSG_AUX_IN);
                aux_online = 1;
            }
        }
    }
    aux_detect_in_off(); //linein check port
}
#endif
#endif
#endif
/*----------------------------------------------------------------------------*/
/**@brief   使用独立的GPIO检测SD card在线
   @param   void
   @return  void
   @note    void sdmmc_detect(void)
*/
/*----------------------------------------------------------------------------*/
#if SDMMC_GPIO_MODE
void sdmmc_detect(void)
{
    static u8 sdmmc_cnt_online;
    P3IE |= BIT(3);
    P3DIR |= BIT(3); //linein check port
    P3PU |= BIT(3);
    _nop_();
    _nop_();
    _nop_();
	_nop_();
	_nop_();
    if (P33)
    {
        sdmmc_cnt_online = 0;
		sdmmc_chk_io(0);
    }
    else
    {
        if(sdmmc_cnt_online<51)
		{
		    sdmmc_cnt_online++;
        }
		if (sdmmc_cnt_online > 50)
        {
		    sdmmc_chk_io(1);
        }
		else
		{
		    sdmmc_chk_io(0xff);
		}
    }
}
#endif
extern bool drv_key_scan_bit;
/*----------------------------------------------------------------------------*/
/**@brief 10MS中断
   @param
   @return
   @note void timer0isr(void)
*/
/*----------------------------------------------------------------------------*/
void timer0isr(void) interrupt 0 using 1
{
    static u8 isr0_ms_cnt=0;
    static u8 isr0_ms_cnt2=0;

    _push_(DPCON);
    _push_(DP0L);
    _push_(DP0H);
    DPCON = 0x00;
    T0CON &= ~(BIT(7));
    dac_cnt++;
    isr0_ms_cnt++;
#ifdef SPECTRUM_FUNC_ENABLE
    	isr0_ms_cnt2++;	
	if(isr0_ms_cnt2==20){
		isr0_ms_cnt2=0;
		spectrum_reflesh_en=1;
	}
#endif

   if(isr0_ms_cnt==10)
   {
   	isr0_ms_cnt =0;
#ifdef LED_DRV_USE_SM1628_KEY_FUNC

drv_key_scan_bit = 1;
	//Read_key();
#endif

	
#ifdef USE_MICPHONE_GPIO_DETECTION
	 mic_check();
#endif    
#ifdef USE_BT_GPIO_DETECTION
	bt_check();
#endif

#ifdef USE_CUSTOMIED_GPIO_KEY
	gpio_key_scan_bit=1;
#endif

#ifdef LED_MODE_INDICATOR_ENABLE
	LED_MODE_INDICATOR();
#endif
#if defined(IPONE_INDEPENDENT_MODE)&&defined(IPHONE_DETECT_IN_USE)
	iphone_tx_detect_polling();
#endif

   }
    _pop_(DP0H);
    _pop_(DP0L);
    _pop_(DPCON);   
}
void timer1isr(void)
{
    static u8 ms_cnt=0, /*cnt_disp=0,*/ counter=0;

    _push_(DPCON);
    _push_(DP1L);
    _push_(DP1H);

    DPCON = 0x0;
    T1CON &= ~(BIT(7));
    counter++;

    Disp_Scan();
	
#ifndef JOY_STICK_DEBUG    
#ifdef JOG_STICK_FUNC
    JogDetect();
#ifdef K523_DeYun_523_V001
    JogDetect_c();
#endif
#endif
#endif

#ifdef BLUE_TOOTH_GPIO_STATUS
	blue_tooth_detect=1;
#endif
	
#ifdef MATRIX_KEY_ENABLE
	key_scan_en=1;
#endif	
    if (counter == 5)
    {

#ifdef AC_SLAVE_ENABLE
	DSA_GETHERING_DATA_ENABLE_BIT=1;
#endif
        counter = 0;

        adc_scan();

#if USB_DEVICE_OTG       
   usb_otg_polling();
#else
        udisk_disconnect_check();
        usb_diskin_detect();
#endif


#if defined(USE_GPIO_DETECT_EARPHONE_PLUGGED)||defined(LINE_IN_DETECT_SHARE_LED_STATUS_PORT)
#ifndef USE_ADKEY_DETECT_HP
	hpone_check();
#endif
#endif
	
#ifndef NOT_USE_LINE_IN_FUNC		
#ifdef USE_LINE_IN_DETECT_FUNC
#if !defined(LINE_IN_DETECT_SHARE_LED_STATUS_PORT)
#ifndef USE_ADKEY_DETECT_AUX
        aux_check();
#endif
#endif
#endif
#endif

#ifdef GPIO_SWITCH_SELECT_MODE
	 gpio_select_enable=1;
#endif

#if defined(TWO_ADKEY_ENABLE)
#if !defined(ADKEY_NEW_METHOD)
	keyScan_ADKEY();
#endif
#endif
        keyScan();

        dec_delay_counter();
#if SDMMC_CMD_MODE
	sd_online_check();
#elif SDMMC_CLK_MODE
	sdmmc_online_chk();
#elif SDMMC_GPIO_MODE
	sdmmc_detect();
#endif

#if 0
        if (DISP_PLAY == curr_menu)
        {
        
            cnt_disp++;
            if (cnt_disp == 10)
            {
                cnt_disp = 0;
                put_msg_fifo(INFO_DISP_FILENAME);
            }
        }
#endif
        ms_cnt++;
        if (ms_cnt ==  50)
        {
            ms_cnt = 0;
#if defined(CUSTOM_FUNC_POLLING)
  		custom_func_tick =1;
#endif
			
#if defined(MUTE_ON_FLASH_WHOLE_SCREEN)||defined(MP3_PUASE_FLASH_FIGURE)||defined(PAUSE_FLASH_WHOLE_SCREEN)
		Led_flash_screen_hdlr();
#endif
            put_msg_fifo(INFO_HALF_SECOND);
#if defined(USE_BAT_MANAGEMENT)
#ifdef IMPROVED_BAT_MEASURE
		bat_val_arg();
#else
            LDO_IN_Volt =ldoin_voltage();
#endif
#endif

#if RTC_ENABLE
            check_alm();
#endif
#if defined(POWER_KEY_ON_WAIT_FOR_3_SEC	)||defined(USE_PWR_KEY_LONG_PWR_ON)
	if((pwr_key_cnt&0x1F)>0x0F){
		pwr_key_cnt &=0x80; 
	}
	else{
		pwr_key_cnt++; 
	};
#endif

        }
        adc_start();
    }

    _pop_(DP1H);
    _pop_(DP1L);
    _pop_(DPCON);
}

/*----------------------------------------------------------------------------*/
/**@brief   PLL初始化
   @param   无
   @return  无
   @note
*/
/*----------------------------------------------------------------------------*/
void pll_init(void)
{
#if defined(K000_ZG_HA8919_BT_V001)
	P0DIR &= ~(BIT(2));
	 P0PU |= BIT(2);P3DIR |= (BIT(4));
	P3PU &= ~(BIT(4));
	P3PD&= ~(BIT(4));
	P02 = 1;	   
#endif

#if defined(K0000_JK_PORTABLE_CHARGER_V001)
	P1DIR &= ~(0x0F);
	P1 =0xFF;	   
#endif

    P0PU = 0;
    PCON = 0;
#ifndef DISABLE_USE_DECODE_FUNC	
    USBCON0 |= BIT(0);							//usb io is port
    P3PD |= 0xc0;
    P3PU &= ~0xC0;
#endif
#if defined(COMMON_CATHODE)	
    led_com_out();
#endif	
    CLKGAT = 0;
    CLKCON = 0x01;
    DACCON1 |= BIT(6);                  //DAC高阻
#ifdef  USE_POWER_KEY	    
    sys_power_up();
#endif
    Disp_Init();						//在芯片上电后，马上显示初始界面

#if OSC_CLOCK == 24000000L
    PLL_input(PLL_IN_OTHER);
    PLL_output(PLL_OUT_DOUBLE);
    mainclock_select(MAIN_CLK_PLL);
#endif

#if OSC_CLOCK == 12000000L
    PLL_input(PLL_IN_12M);
    PLL_output(PLL_OUT_48M);
    mainclock_select(MAIN_CLK_PLL);
#endif

#if OSC_CLOCK == 7600000L
    PLL_input(PLL_IN_76M);
    PLL_output(PLL_OUT_48M);
    mainclock_select(MAIN_CLK_PLL);
#endif

#if OSC_CLOCK == 32768L
    PLL_input(PLL_IN_32K);
    PLL_output(PLL_OUT_48M);
    mainclock_select(MAIN_CLK_PLL);
#endif

}

/*----------------------------------------------------------------------------*/
/**@brief  timer1 初始化函数，产生5ms中断
   @param  无
   @return 无
   @note   void timer1Init(void)
*/
/*----------------------------------------------------------------------------*/
void timer0Init(void)
{
#if (OSC_CLOCK == 12000000L)

    T1SCA = 9;//1/(2^n)分频
    T1PRD = 46;   //约等于2MS
    T1CNT = 0;
    T1CON = 0x29;//设置为TIMER模式，并将其相应的中断打开
    ET1	= 1;
	
#else

    T0SCA = 0;//1/(2^n)分频
   T0PRD = 64;//32;//64;   //约等于2MS
    T0CNT = 0;
    T0CON = 0x2d;//设置为TIMER模式，并将其相应的中断打开
    ET0	= 1;
	
#endif	
}
void timer1Init(void)
{
#if (OSC_CLOCK == 12000000L)

    T1SCA = 9;//1/(2^n)分频
    T1PRD = 46;   //约等于2MS
    T1CNT = 0;
    T1CON = 0x29;//设置为TIMER模式，并将其相应的中断打开
    ET1	= 1;
	
#else

    T1SCA = 0;//1/(2^n)分频
    T1PRD = 64;   //约等于2MS
    T1CNT = 0;
    T1CON = 0x2d;//设置为TIMER模式，并将其相应的中断打开
    ET1	= 1;
	
#endif	
}
/*----------------------------------------------------------------------------*/
/**@brief  timer3 初始化函数
   @param
   @return
   @note
*/
/*----------------------------------------------------------------------------*/
void timer3Init(void)
{
#ifndef USE_IR_VPP_PORT_FOR_DETECTION

#if (OSC_CLOCK == 12000000L)

    WKUPPND |= (1<<6);  //开VPP的上拉
    PT3 = 1;
    T3SCA = 0x25;      // 1/(2^n)分频
    T3CNTL = 0;
    T3CNTH = 0;
    T3PRD = 0xa1;		//0xa1;
    T3PRD = 0X22;		//0x22;
    T3CON = 0x3A;       //设置为capture模式，并将其相应的中断打开
    ET3 = 1;
	
#else
    WKUPPND |= (1<<6);  //开VPP的上拉
    PT3 = 1;
    T3SCA = 0x20;      // 1/(2^n)分频
    T3CNTL = 0;
    T3CNTH = 0;
    T3PRD = 0x13;		//0xa1;
    T3PRD = 0x88;		//0x22;
    T3CON = 0x3e;       //设置为capture模式，并将其相应的中断打开
    ET3 = 1;
#endif

#endif	
}

#ifdef PWM3_IN_USE
void pwm_setting(u8 level_setting)
{
	switch(level_setting)
	{
		case 0:	T3PWM=0x00; T3PWM=0x00; break;
		case 1:	T3PWM=0x00; T3PWM=0x01; break;
		case 2:	T3PWM=0x00; T3PWM=0x02; break;
		case 3:	T3PWM=0x00; T3PWM=0x04; break;
		case 4:	T3PWM=0x00; T3PWM=0x06; break;
		case 5:	T3PWM=0x00; T3PWM=0x08; break;
		case 6:	T3PWM=0x00; T3PWM=0x0A; break;
		case 7:	T3PWM=0x00; T3PWM=0x0C; break;
		case 8:	T3PWM=0x00; T3PWM=0x0E; break;
		case 9:	T3PWM=0x00; T3PWM=0x0F; break;
		case 10:	T3PWM=0x00; T3PWM=0x10; break;
	}
}
void pwm3_Init(void)
{
    PT3 = 1;
    T3SCA = 0x00;      // 1/(2^n)分频
    T3CNTL = 0;
    T3CNTH = 0;
    T3PRD = 0x00;		//0xa1;
    T3PRD = 0x10;		//0x22;
    
    T3CON = 0x0f;       //设置为pwm模式，并将其相应的中断打开

    pwm_setting(0);	
//T3PWM=0x00;
//T3PWM=0x06;
    ET3 = 1;
}

#endif
/*----------------------------------------------------------------------------*/
/**@brief  系统初始化
   @param  无
   @return 无
   @note   void sys_init(void)
*/
/*----------------------------------------------------------------------------*/
void sys_init(void)
{
#ifdef UART_ENABLE
    uartInit();
    printf("power up \r\n");
 #endif
    Mute_Ext_PA(MUTE);
 
 #ifdef USE_AMP_MODE_SELECT
    D_CLASS_AMP_GPIO_INIT(); 
    D_CLASS_AMP_HIGH();
 #endif
 
#if RTC_ENABLE
    if (init_rtc())
    {
        work_mode = SYS_RTC;
    }
#endif
	P0IE_init();
 #ifdef K800_MingYang_800_V001

	P0DIR &= ~(BIT(2));
	 P0PU |= BIT(2);P3DIR |= (BIT(4));
	P3PU &= ~(BIT(4));
	P3PD&= ~(BIT(4));
	P02 = 1;	   
#endif
#ifdef K0000_MC_A6B_V001
	DACCON0|=0x80;
	P2DIR &= ~(BIT(7));
	P2PU |= BIT(7);
	P27 =0;		
#endif
#if defined(K619_FXK_619_V001)

	P1DIR &=~(BIT(7));P1PU|=(BIT(7));P17 = 1;
	P1DIR |=(BIT(7));
	Delay(20);
	
	if(P17)config_led_by_gpio=1;
	else config_led_by_gpio=0;
	
#endif

#if defined(K0000_GW_118B_V001)||defined(K0000_GW_ZX015_V001)
	P0DIR &= ~(BIT(2));
	P0PU |= BIT(2);
	P02 = 1;	   
#endif

#if defined(CUSTOMIZED_KEY_FUNC_ENABLE)
     gpio_ctrl_if(0);
#endif

#ifndef NO_LED_DISPLAY
    Disp_Init_2();
#endif
    keyInit();
    timer0Init();
    timer1Init();
#if defined(TWO_PLAY_LED_IN_USE)
	 led_open_enable = 1;
#endif

#if defined(LED_LIGHT_ON_ENABLE_IN_IDLE_MODE)||defined(SYS_DEFAULT_IN_IDLE_POWER_DOWN_MODE)
    set_play_flash(LED_FLASH_STOP);
#else
    set_play_flash(LED_FLASH_ON);
#endif
#ifndef NO_LED_DISPLAY
#if !defined(POWER_KEY_ON_WAIT_FOR_3_SEC)
#if !defined(USE_PWR_KEY_LONG_PWR_ON)
    Disp_Con(DISP_START);//zdy 0321 add  dispay "HI" when power on 
#endif    
#endif    
#endif    
    timer3Init();
#ifndef DISABLE_SD_MMC_CARD_DECODE_FUNC
    sd_speed_init(1,100);
    init_port_sd();
#if SDMMC_CMD_MODE
	sd_chk_ctl(SET_SD_H_CHK);
#endif
#endif

#ifdef PWM3_IN_USE	
    pwm3_Init();
#endif

#ifdef AC_SLAVE_ENABLE
	DSA_init();
#endif
#ifdef FM_TRANSMITTER	
    bk1085_init();	
#endif	
    DACCON0 |= 0x05;	//打开DSP
    EA = 1;

#ifdef SYS_LED_PROTECTION_UNTILL_PWR_ON
	    sys_pwr_on_led_protect_bit=1;
#endif

#if defined(DEFAULT_GO_TO_CUSTOM_MODE)
	custom_first_time_pwr_flag=1;
#endif
#if defined(KPL_MSG_COMPATIBLE)	
    kpl_msg_preinit_setting(MSG_TYPE_1,0xF0);
#endif
#ifdef UART_ENABLE_MAIN_FLOW	
    delay_10ms(220);
    sys_printf("sys_init phase one finish");
#endif
}
/*----------------------------------------------------------------------------*/
/**@brief  系统共用信息的初始化
   @param  无
   @return 无
   @note   void sys_info_init(void)
*/
/*----------------------------------------------------------------------------*/
void sys_info_init(void)
{
#if defined(EEPROM_RTC_RAM_COMPATIBLE)
	check_eeprom_status();
#endif

#ifdef SYS_LED_PROTECTION_UNTILL_PWR_ON
	    sys_pwr_on_led_protect_bit=0;
#endif

#ifdef SYS_DEFAULT_IN_PWR_OFF_FOR_LED_PROTECTION
	    sys_pwr_on_led_protect_bit=1;
#endif

    my_music_vol = read_info(MEM_VOL);

#if defined(KPL_MSG_COMPATIBLE)
	init_kpl_msg();
#endif

#if defined(K000_XINGLEI_2092_V001)
	if(my_music_vol <=8){
		my_music_vol =15;
	}
#elif defined(K000_XinLei_LC2092_V006)
	if(my_music_vol <=5){
		my_music_vol =10;
	}
#elif defined(K1226_AP_750_V001)||defined(K2125_AP_751C_V001)
	if(my_music_vol <=10){
		my_music_vol =20;
	}
#elif defined(K015_983_SW005_ZhuoXin_V002)||defined(K568_ZX_568_V002)
	if(my_music_vol <10){
		my_music_vol =10;
	}	
#endif

    if ((my_music_vol > MAX_VOL) || (my_music_vol == 0))              //每次开机时，不要超过最大音量的一半，以免开机音量过大
    {
        my_music_vol = 20;
    }
#if VOLUME_DEFUALT
        my_music_vol = VOLUME_DEFUALT;
#endif

#ifdef K5018_JK_5018_V001
    Disp_Con(DISP_START);//zdy 0321 add  dispay "HI" when power on 
#endif
#if 1
#ifdef FAST_DEV_INIT
	delay_10ms(2);	
#else
	delay_10ms(50);					//4保证U盘/SD卡能有足够时间通过在线检测,稳定接入
#endif
	dac_init();
#else
    digital_max_vol = MAX_DIGITAL_VOL;
#if 1
    dac_on(60);							  //打开DAC，同时给系统提供上电延时，让USB主机稳定接入
#endif

#endif
#if DEVICE_ENCRYPTION
    device_password_init(0x12345678);  //输入加密设备的密码
#endif 
#if ((USE_DEVICE == MEMORY_STYLE)&&(FAT_MEMORY))    
	get_info_memory();
	get_info();
#endif  

#ifdef SUPPORT_PT2313
	PT2313_Init();
#endif

#if OTP_MUSIC_ENABLE
    decode_opt_music_file(0);
#ifdef PLAY_OTP_MUSIC_OTHER_TIME
    decode_opt_music_file(0);
#endif
#endif
#if RTC_ENABLE
    if (work_mode != SYS_RTC)
#endif
    {
#ifndef REMOVE_USE_DEVICE_MODE   
#if USB_DEVICE_OTG
        device_check();
        if (pc_connect)
        {
            work_mode = SYS_USBDEVICE;
        }
        else
#else  
        usb_audio_massstorage();									//每次上电判断是否连接电脑
#endif
#endif

#if defined(AUX_MODE_HOT_KEY_ENABLE)||defined(MUSIC_MODE_HOT_KEY_ENABLE)||defined(RADIO_MODE_HOT_KEY_ENABLE)||defined(RTC_MODE_HOT_KEY_ENABLE)
	if(get_mod_hotkey_protect_status())
	{
	}
	else
#endif
	{
#ifdef USE_SYS_MODE_RECOVER
	work_mode = read_info(MEM_SYSMODE);
	
	if(work_mode >= SYS_IDLE){
		work_mode = SYS_MP3DECODE_USB;
	}
#else
		work_mode = SYS_MP3DECODE_USB;
#endif
	}
    }
    Init_Func_List();
    clear_super_mute_lock();

#if defined(USE_SPECTRUM_PARTTERN)		  	
    set_lcd_flash_lock(UNLOCK);
#endif

#ifdef USE_MICPHONE_GPIO_DETECTION
	 mic_online=0;
#endif

#if defined(K3031_AP_668_V001)
	if(work_mode ==  SYS_AUX){
		work_mode = SYS_RTC;
	}
	else if(work_mode ==  SYS_RTC){
		work_mode = SYS_MP3DECODE_USB;
	}
	else if(work_mode ==  SYS_FMREV){
		sys_mode_recove=1;		
		work_mode = SYS_MP3DECODE_USB;
	}
#endif

#ifdef BLUE_TOOTH_FUNC
#ifdef BLUETOOTH_GPIO_CTRL		
     	BT_PWR_OFF();	
#endif
#endif

#ifdef UART_ENABLE_MAIN_FLOW	
    sys_printf("sys_init phase two finish");
#endif
}
void custom_gpio_setting()
{
#if defined(K5008_JK_5008_V001)||defined(K5058_JK_5058_V001)
	P0DIR &= ~(BIT(7));
	P0PU |= BIT(7);
	P07 = 0;	   
#endif
#ifdef K5068_JK_5068_V001
	P0DIR &= ~((BIT(3))|(BIT(2)));
	P0PU |= ((BIT(3))|(BIT(2)));
	P03 = 0;	   
	P02 = 0;	   
#endif
#ifdef GPIO_SEL_M62429_FUNC
	MIC_DET_PORT_INIT();
	_nop_();
	_nop_();
	if(MIC_DET_PORT){
		select_m62429=1;		
	}
	else{

		select_m62429=0;
		MIC_DET_PORT_RELEASE();
	}
#endif

#ifdef K000_JK_HY_SM001_V001
	P0DIR &= ~(BIT(1));
	P0PU |= BIT(1);
	P01 = 1;	 

	P2DIR &= ~(BIT(7));
	P2PU |= BIT(7);
	P27 = 1;	 
#endif
#ifdef K000_XC_BC_BT_V001
	P0DIR &= ~(BIT(4));
	P0PU   |= BIT(4);
	P04     = 0;	   
#endif
#ifdef BLUE_TOOTH_FUNC
#ifdef BLUETOOTH_GPIO_CTRL		
	BT_PWR_PORT_INIT();
	BT_PP_PORT_INIT();
	BT_RST_PORT_INIT();
	BT_NEXT_PORT_INIT();
	BT_PREV_PORT_INIT();
	BT_VOLU_PORT_INIT();
	BT_VOLD_PORT_INIT();
#endif
#endif
}
void Idle_hdlr()
{
    u8 key;	
	clear_super_mute_lock();	
#ifndef USE_MANUAL_IDLE_FUNC
    set_play_flash(LED_FLASH_STOP);
    Mute_Ext_PA(MUTE);
#endif	

#if defined(SYS_DEFAULT_IN_IDLE_POWER_DOWN_MODE)
	put_msg_lifo(INFO_SYS_IDLE);
#endif

#ifndef PLAY_STATUS_LED_OFF_AT_IDLE_NODEV
#ifdef LED_LIGHT_ON_ENABLE_IN_IDLE_MODE
    set_play_flash(LED_FLASH_ON);
#endif	
#endif	

#if defined(SPECTRUM_FUNC_ENABLE)
    set_spectrum_lock(LOCK);
#endif	

#ifdef SUPPORT_PT2313
    my_main_vol(0);	
#endif

#ifdef DAC_MUTE_IN_IDLE_MODE
  my_main_vol(0);
#endif

#ifdef IDLE_MODE_NO_MUTE
    Mute_Ext_PA(UNMUTE);
#else
    Mute_Ext_PA(MUTE);
#endif

    while (1)
    {
        key = get_msg();
#ifdef  USE_POWER_KEY			
#if defined(DC_HW_POWER_UP_IN_IDLE_MODE)|| defined(USB_SD_PORTABLE_BAT_CHARGER)
		if(dc_hw_pwer_up_sel_mode){

			if(key==(INFO_POWER | KEY_HOLD)){
				
				dc_hw_pwer_up_sel_mode =0;				
				Set_Curr_Func(SYS_MP3DECODE_USB);
				return;
			}			
			else if(key!= INFO_HALF_SECOND){
				
				key = NO_KEY;
			}
		}
#endif
#endif

#if defined(KPL_MSG_COMPATIBLE)
	kpl_msg_hdlr(key);
#endif
		
        switch (key)
        {
        case INFO_NO_DEV:
#ifdef NO_DEV_SHOW_HI_STR
                Disp_Con(DISP_START);
#else
                Disp_Con(DISP_NODEVICE);
#endif
		  set_play_flash(LED_FLASH_ON);				
	         flush_all_msg();
#ifdef PLAY_STATUS_LED_OFF_AT_IDLE_NODEV
		  set_play_flash(LED_FLASH_STOP);				
#endif
            break;	
        case INFO_SYS_IDLE:
			
#ifndef LED_LIGHT_ON_ENABLE_IN_IDLE_MODE			
	         set_play_flash(LED_FLASH_STOP);
#if defined(TWO_PLAY_LED_IN_USE)		 
		  set_play_flash_no2(LED_FLASH_STOP);
#endif
#endif
                Disp_Con(DISP_PWR_OFF);
    		  Mute_Ext_PA(MUTE);
		  my_main_vol(0);

#ifdef LOW_BAT_POWER_OFF_MODE
		if(get_low_bat_power_lock()){
			EA =0;
			while(1);
		}
#endif
		  
            break;
			
    	case MSG_USB_DISK_OUT:
    	case MSG_SDMMC_OUT:
    	case MSG_SDMMC_IN :
	case MSG_USB_DISK_IN  :
    	case MSG_AUX_OUT :
    	case MSG_AUX_IN :
#if defined(SYS_DEFAULT_IN_IDLE_POWER_DOWN_MODE)	
	if(pwr_up_flag)break;
#endif
		goto __HOT_MSG_HDL;

        	break;			

	case INFO_HALF_SECOND :	
#ifdef USE_USB_HOTPLUG_FUNC
		usb_hotplug_hdlr();
#endif
#ifdef DISP_BACKLIGHT_AUTO_SAVE_POWER
	 	Disp_BL_time_out();
#endif

#ifdef  USE_POWER_KEY			
#if defined(USB_SD_PORTABLE_BAT_CHARGER)
		if(dc_hw_pwer_up_sel_mode){

			BATT_CHARGER_PORT_INIT();
			_nop_();	_nop_();	_nop_();	_nop_();
			if(!BATT_CHRG_PORT){		
#if defined(PWR_CTRL_WKUP)
				wkup_pin_ctrl(0);
#else
				power_ctl(0);
#endif
				 EA = 0;
				 while (1);
			}
		}
#endif
#endif

#if defined(USE_BAT_MANAGEMENT)

#if defined(BAT_LEVEL_GPIO_DRV_LED_IND)||defined(BAT_LEVEL_LED_ICON_IND)
		if(!pwr_up_flag)
#endif
		if((curr_menu!=DISP_PWR_OFF))

		bmt_hdlr();
#endif		
#ifdef K000_HG_898_V001
            return_cnt++;
            if (RETURN_TIME == return_cnt)
            {
			if(pwr_up_flag){
			}
			else{
		                Disp_Con(DISP_NODEVICE);
			}
	     }
#endif	

	if((curr_menu!=DISP_PWR_OFF))

	     Disp_Update();			

            break;			
#if 0//def POWE_KEY_PLAY_KEY_IN_ONE_KEY
       case INFO_POWER| KEY_HOLD:	
		goto __HOT_MSG_HDL;
#endif	
#if defined(USE_LONG_MODE_FOR_POWER_KEY)
        case INFO_MODE | KEY_LONG :
#endif
       case INFO_CH_DOWN|KEY_SHORT_UP:	//Power key on remoter when no FM 
#if defined(SYS_DEFAULT_IN_IDLE_POWER_DOWN_MODE)
		if(pwr_up_flag){
			return;
		}
		else{

		   	pwr_up_flag = 1;			
			put_msg_lifo(INFO_SYS_IDLE);

		}		
#else
	   	pwr_up_flag = 1;
#endif
	   	return;
#ifdef  USE_POWER_KEY	

#ifdef USE_IR_LONG_POWER_KEY_TO_FAKE_POWER_OFF
    case INFO_POWER | KEY_LONG:
		if(IR_KEY_Detect){
			IR_KEY_Detect =0;

#ifdef NO_DEV_SHOW_HI_STR		
			if(curr_menu==DISP_START){
#else
			if(curr_menu==DISP_NODEVICE){
#endif
				put_msg_lifo(INFO_SYS_IDLE);
				break;
			}
		
			Set_Curr_Func(SYS_MP3DECODE_USB);			
		   	pwr_up_flag = 1;			
		   	return;
		}
		break;
#endif

    	case INFO_POWER | KEY_HOLD:
#ifdef USE_IR_LONG_POWER_KEY_TO_FAKE_POWER_OFF
		if(IR_KEY_Detect){
			IR_KEY_Detect =0;
			break;
		}
#endif			
        	sys_power_down();
        	break;
#endif
#if defined(POWER_KEY_LONG_POWER_OFF)		
    	case INFO_POWER| KEY_LONG:
		pwr_up_flag=1;
		return;
#endif
#ifdef USE_PLAY_KEY_TO_POWER_OFF
    	case INFO_PLAY| KEY_SHORT_UP :
		return;
#endif
    	case INFO_POWER | KEY_SHORT_UP :
#ifdef USE_IR_POWER_KEY_TO_POWER_OFF

#if defined(IR_POWER_KEY_SHORT_TRUE_POWER_OFF)
		sys_pwr_off();
#else
		if(IR_KEY_Detect){
			IR_KEY_Detect =0;
			pwr_up_flag=1;
			return;
		}
#endif
#endif
#ifdef USE_POWER_KEY_TO_SWITCH_MODE
	goto __HOT_MSG_HDL;
#endif
#if defined(K723_LUOMAO_723_V001)
	goto __HOT_MSG_HDL;
#endif
#if defined( K186_LM_186_V001)||defined(POWER_KEY_ON_WAIT_FOR_3_SEC)||defined(USE_PWR_KEY_LONG_PWR_ON)
	break;
#endif		
		if(curr_menu == DISP_NODEVICE){
            		put_msg_fifo(INFO_SYS_IDLE);				
			break;			
		}
        default :
#ifndef  GPIO_SWITCH_SELECT_MODE	
	     if((key!=(INFO_POWER| KEY_SHORT_UP))&&(pwr_up_flag))break;
#endif		 
__HOT_MSG_HDL:
            if (!ap_handle_hotkey(key))
                return;
        }
    }
}
//#define IR_DEBUG
#ifdef IR_DEBUG
extern u16 _idata user_code;   ///<红外遥控提取的用户码
extern u8 _idata irStep;      ///<IR当前状态
extern u16 _idata irBuffer;   ///<IR读取读取出的数据
void IR_Debug_func()
{
	u8 key=0;
	while(1){
		if(irStep == 32){
			  printf("IR_Debug_func user_code %x \r\n",(user_code));
			  printf("IR_Debug_func irBuffer  %x \r\n",(irBuffer & 0xff));
			  
		}
#if 1
		        key = get_msg();
			if((key!=0xff)&&(key!=0x1f))
			printf(" music_play get_msg %x \r\n",(u16)key);
#endif

	}
		
}
#endif

#ifdef JOY_STICK_DEBUG
void JOY_Stick_Debug_func()
{
	while(1){
#ifdef JOG_STICK_FUNC
    		JogDetect();
		delay_10ms(1);
#endif		
	}
		
}
#endif

#ifdef ADKEY_DEBUG
extern u8  key_value;   ///<红外遥控提取的用户码
//extern u8  key_value_2;   ///<红外遥控提取的用户码
//extern xd_u8 vol_reg;

void AD_Debug_func()
{
	while(1){

		//printf("use_adkey_port_for_volume_adj   -->  %d  \r\n",(u16)((vol_reg)));
			
		printf("ad read value %x \r\n",(u16)((key_value)));
		//printf("ad read value %d \r\n",(u16)((key_value*33)/255));
		delay_10ms(20);
	}		
}
#endif

/*----------------------------------------------------------------------------*/
/**@brief  主函数
   @param  无
   @return 无
   @note   void main(void)
*/
/*----------------------------------------------------------------------------*/
void main(void)
{
//u16 pwm_cnt=0;
    custom_gpio_setting();
    sys_clock_pll();//(MAIN_CLK_PLL);
    sys_init();
#ifdef  USE_POWER_KEY
    waiting_power_key();/*等待POWER按键松开，此处在使用的时候需要打开*/
#endif    
    sys_info_init();
    flush_all_msg();
#if FILE_ENCRYPTION
    password_init(0xaa);  //输入加密文件的密码
#endif   
    //custom_gpio_setting();
#ifdef IR_DEBUG
	IR_Debug_func();
#endif

#ifdef JOY_STICK_DEBUG
	JOY_Stick_Debug_func();
#endif

#ifdef ADKEY_DEBUG
	AD_Debug_func();
#endif

#if 0
	while(1){
		SM1628_Key_Scan();
		delay_10ms(5);
	}
#endif

#ifdef GPIO_SWITCH_SELECT_MODE
	gpio_select_mode();
#endif

#ifdef SYS_DEFAULT_IN_IDLE
	Set_Curr_Func(SYS_IDLE);
#elif defined(SYS_DEFAULT_IN_AUX_MODE)
	Set_Curr_Func(SYS_AUX);
#elif defined(SYS_DEFAULT_IN_AUX_MODE_WITH_DETECTION)
	if(aux_online)
	Set_Curr_Func(SYS_AUX);
#elif defined(SYS_DEFAULT_IN_BLUETOOTH_MODE)

#if !defined(USE_BT_GPIO_SEL_MODE)
	Set_Curr_Func(SYS_BT);
#endif

#elif defined(SYS_POWER_ON_DEFAULT_RTC_MODE)
	Set_Curr_Func(SYS_RTC);
#elif defined(SYS_DEFAULT_IN_IDLE_POWER_DOWN_MODE)
	pwr_up_flag=1;
	Set_Curr_Func(SYS_IDLE);
	put_msg_lifo(INFO_SYS_IDLE);
#elif defined(SYS_POWER_ON_DEFAULT_IN_BT_AUX_ALTERNATIVE_MODE)

#ifdef USE_LINE_IN_DETECT_FUNC
	if(aux_online){
		Set_Curr_Func(SYS_AUX);
	}
	else{
		Set_Curr_Func(SYS_BT);
	}
#endif

#elif defined(SYS_POWER_ON_NODEV_SEL_MODE)

#ifdef SYS_POWER_ON_NODEV_SEL_MODE_AT_TIME_MODE
      if((get_device_online_status()&0x03)==0){
		Set_Curr_Func(SYS_RTC);
      }
#endif
#elif defined(AD_DETECT_SELECT_OUTSIDE_SOURCE)

	delay_10ms(160);
	if(adc_signal_online_judge()){
		Set_Curr_Func(SYS_AUX);
	}
	
#endif

#if defined(DC_HW_POWER_UP_IN_IDLE_MODE)|| defined(USB_SD_PORTABLE_BAT_CHARGER)
	if(dc_hw_pwer_up_sel_mode){
		Set_Curr_Func(SYS_IDLE);
	}
#endif

#if 0
	pwmInit();

	while(1){
		pwm_cnt++;
    		T3PWM=(pwm_cnt>>8);
    		T3PWM=pwm_cnt&0xFF;

		if(pwm_cnt>0x0200)pwm_cnt=0;
               	Disp_Con(DISP_PWR_OFF);
			//key_matrix_scan();
	    		//JogDetect();
	    		//JogDetect_c();
			delay_10ms(1);
	}
#endif

    while (1)
    {
	Set_Curr_Func(work_mode);

        switch (work_mode)
        {
        case SYS_MP3DECODE_USB :
	 case SYS_MP3DECODE_SD:
#ifdef UART_ENABLE_MAIN_FLOW	
	     sys_printf("main work go in decode play");
#endif
            decode_play();
            break;

        case SYS_FMREV:
#ifdef RADIO_AM_WM_ENABLE
	 case SYS_AMREV:
#endif    		
#ifdef UART_ENABLE_MAIN_FLOW	
	     sys_printf("main work go in  FM  ");
#endif
            fm_radio();
            break;
			
#ifndef NOT_USE_LINE_IN_FUNC
        case SYS_AUX:
#ifdef USE_AUX_2
        case SYS_AUX_2:
#endif			
#ifdef UART_ENABLE_MAIN_FLOW				
	     sys_printf("main work go in AUX ");
#endif
            aux_function();
            break;
#endif

#if defined(IPONE_INDEPENDENT_MODE)
        case SYS_IPH:
#ifdef UART_ENABLE_MAIN_FLOW					 	
	     sys_printf("main work go in IPH ");
#endif
            iphone_func();
            break;	
#endif
#if defined(BLUE_TOOTH_FUNC)	
        case SYS_BT:
#ifdef UART_ENABLE_MAIN_FLOW					 	
	     sys_printf("main work go in BT ");
#endif
            blue_tooth_hdlr();
            break;	
#endif

#if RTC_ENABLE
        case SYS_RTC:
#ifdef UART_ENABLE_MAIN_FLOW					 	
	    sys_printf("main work go in RTC ");
#endif			
            rtc_function();
            break;		
#endif
	 case SYS_IDLE:
#ifdef UART_ENABLE_MAIN_FLOW					 	
		sys_printf("main work go in IDLE ");
#endif
	     Idle_hdlr();
#ifdef LED_LIGHT_ON_ENABLE_IN_IDLE_MODE
    	     set_play_flash(LED_FLASH_STOP);
#endif
	     if(pwr_up_flag){
		 pwr_up_flag  =0;

#ifdef UART_ENABLE_MAIN_FLOW					 	
		sys_printf("power on from  IDLE ");
#endif

#if defined(TWO_PLAY_LED_IN_USE)
		 led_open_enable = 1;
#endif		 
 	     	 Disp_Con(DISP_START);//zdy 0321 add  dispay "HI" when power on 
		 sys_info_init();
#ifndef LED_LIGHT_ON_ENABLE_IN_IDLE_MODE		 
		 set_play_flash(LED_FLASH_ON);
#endif
#ifdef SYS_DEFAULT_IN_PWR_OFF_FOR_LED_PROTECTION
	    sys_pwr_on_led_protect_bit=0;
#endif

#ifndef FAST_DEV_INIT		 
 	     	 delay_10ms(10);
#endif
	     }
            break;
#ifdef USE_USB_HOTPLUG_FUNC			
	case SYS_USBDEVICE:
		usb_audio_massstorage();
		break;
#endif		
        default:
            work_mode = SYS_MP3DECODE_USB;
            break;
        }
#ifdef USE_SYS_MODE_RECOVER
	if(work_mode !=SYS_IDLE){
		//sys_printf("Write EEPROM in main While !! ");
              write_info(MEM_SYSMODE,work_mode);
    	}
#endif	
    }

}

