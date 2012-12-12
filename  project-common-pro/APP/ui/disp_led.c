#include "Custom_config.h"
#include "config.h"
#include "disp.h"
#include "lcd.h"
#include "resource.h"
#include "decode.h"
#include "mp3mode.h"

#ifdef LED_1651_DRV
#include "led_1651.h"
#else
#include "led.h"

#endif
#if defined(LED_GPIO_DRV)||defined(LED_DRVER_USE_SM1628)||defined(LED_1651_DRV)
extern _xdata u8 LED_BUFF[5];
extern u8 _idata  my_music_vol;  
extern FSAPIMSG _pdata fs_msg;
extern u16 given_file_number;
extern u8 play_mode;
extern u8 eq_mode;
extern u16 cfilenum;
extern u8 device_active,given_device;
//extern _code u8 _code * chars_table_l;
extern xd_u8 all_channl;
extern xd_u16 frequency;
extern xd_u8 fre_channl;
extern xd_u8 fre_point[];
extern MAD_DECODE_INFO _pdata mad_decode_dsc;
extern u8 play_status;
#if defined(K619_FXK_619_V001)
extern bool config_led_by_gpio;
#endif
//extern u16 filenameCnt;
//extern u16 filenameNum;
#ifdef ALARM_SEL_SOURCE		
extern xd_u8 alm_source;
#endif
extern _xdata SYS_WORK_MODE work_mode;

#ifdef SUPPORT_PT2313
extern xd_u8  PT_Bass_Val;
extern xd_u8  PT_Treble_Val;
extern xd_u8  PT_Balence_Val;
extern xd_u8  PT_Fade_Val;
#endif
extern _xdata u8 filename_buff[100];
extern void disp_buf_clear(void);

#ifdef NEW_RTC_SETTING_CTRL
extern xd_u8 new_rtc_setting;
#endif

#if defined(EXTENED_LED_NUM_SCAN)
#ifdef K4005_AJR_105_V001
#define EXTENED_NUM 	7

#else
#define EXTENED_NUM 	8
#endif
extern xd_u8 LED_BUFF_2[EXTENED_NUM-5];

void set_extend_led_buf_icon()
{
	static u8 flick_timer=0;

	if(flick_timer++<200)return;
	flick_timer=0;
#ifdef K4005_AJR_105_V001
	LED_BUFF_2[0] =0x00;
	LED_BUFF_2[1] =0x00;

	if(work_mode<SYS_FMREV){

		if(play_status==MUSIC_PLAY){
			LED_BUFF_2[1] |=BIT(LED_F);
		}
		else if(play_status==MUSIC_PAUSE){
			LED_BUFF_2[1] |=BIT(LED_A);
		}
	}	
#else
	LED_BUFF_2[2] =0x00;

	if(work_mode<SYS_FMREV){
		LED_BUFF_2[2] |=0x01;
	}
	else if(work_mode ==SYS_FMREV){
		LED_BUFF_2[2] |=0x02;

	}
	else if(work_mode == SYS_AUX){
		LED_BUFF_2[2] |=0x04;

	}
#ifdef USE_RTC_FUNCTION	
	else if(work_mode == SYS_RTC){
		LED_BUFF_2[2] |=0x08;
	}	
#endif	
#endif	
}
#endif

u8 _code playmodestr[4][7] =
{
#if defined(LED_USE_1X888)
    {" ALL"},
    {" FoL"},
    {" ONE"},
    {" RAN"}
#else
    {"ALL"},
    {"FoLdER"},
    {"ONE"},
    {"RANdOM"}
#endif
};
u8 _code LED_NUMBER[10] =
{
    0x3f,0x06,0x5b,0x4f,0x66,  ///<0~4
    0x6d,0x7d,0x07,0x7f,0x6f   ///<5~9
};

u8 _code LED_LETTER[26*2] =
{
    0x77,0x7f,0x39,0x5e,0x79,///<ABCDE
    0x71,0x40,0x76,0x06,0x40,///<FGHIJ
    0x40,0x38,0x40,0x37,0x3f,///<KLMNO
    0x73,0x67,0x50,0x6d,0x07,///<PQRST
    0x3e,0x3e,0x40,0x76,0x40,///<UVWXY
    0x40,///<Z

    0x77,0x7C,0x40,0x5e,0x79,///<abcde
    0x71,0x40,0x40,0x30,0x40,///<fghij
    0x40,0x38,0x40,0x54,0x5c,///<klmno
    0x73,0x67,0x50,0x40,0x07,///<pqrst
    0x3e,0x3e,0x40,0x76,0x40,///<uvwxy
    0x40///<z
};
void Disp_Null(void)
{
}

/*----------------------------------------------------------------------------*/
/**@brief
   @param
   @return
   @note
*/
/*----------------------------------------------------------------------------*/
u8 dispchar(u8 chardata,u8 offset)
{
    /**/
    if (offset >= 4)
    {
        return 0;
    }
    if (( chardata >= 'A')&&(chardata <= 'Z'))
    {
        LED_BUFF[3-offset] = LED_LETTER[chardata - 'A'];
    }
    else if (( chardata >= 'a')&&(chardata <= 'z'))
    {
        LED_BUFF[3-offset] = LED_LETTER[chardata-'a' + 26];
    }
        else if ( chardata ==' ')
   {
        LED_BUFF[3-offset] = 0X00;
    }	
    else
    {
        LED_BUFF[3-offset]	= BIT(LED_G);
        return 0;
    }
    return 1;

}

/*----------------------------------------------------------------------------*/
/**@brief
   @param
   @return
   @note
*/
/*----------------------------------------------------------------------------*/
void dispstring(u8 *str,u8 offset0)
{
    u8 cnt = 3;
    str = str+offset0;
    do
    {
        dispchar(*str,cnt);
        str++;

    }
    while ((0 != *str) && cnt--);
}
/*----------------------------------------------------------------------------*/
/**@brief
   @param
   @return
   @note
*/
/*----------------------------------------------------------------------------*/
u8 dispNum(u8 chardata,u8 cnt)
{
    /**/
#if defined(LED_USE_1X888)
/*最高位不是1不显示 */
    if((chardata !=0x01)&&(cnt==3))return 0;
#endif	
    if (cnt < 4){
        LED_BUFF[3-cnt] = LED_NUMBER[chardata];
    }
    else{		
  #if defined(EXTENED_LED_NUM_SCAN)
	   if(cnt<(EXTENED_NUM-1))
          LED_BUFF_2[cnt-4] = LED_NUMBER[chardata];
  #endif	
    }
	
    return 1;
}
void disp_active(void)
{

    if (device_active == BIT(USB_DISK))
    {
#if defined(DISP_DEV_AT_PLAY)
	 dispstring(" USB",0);
#endif

        LED_STATUS |= LED_USB;
    }
    else if (device_active == BIT(SDMMC))
    {
#if defined(DISP_DEV_AT_PLAY)
	 dispstring(" SD",0);
#endif    

#if defined(KPL_BIG_LED_MODULE)
        LED_STATUS_SD|= LED_SD;
#else
        LED_STATUS |= LED_SD;
#endif
    }

}
void Disp_Num(void)
{

    dispNum((u8)((cfilenum/1000)%10),3);
    dispNum((u8)((cfilenum/100)%10),2);
    dispNum((u8)((cfilenum/10)%10),1);
    dispNum(cfilenum%10,0);
}

void Disp_Filenum(void)
{
#if defined(K619_FXK_619_V001)

	disp_active();
	if(config_led_by_gpio==0){

		if(given_file_number>999)
		    dispNum((u8)((given_file_number/1000)%10),3);
		if(given_file_number>99)
		    dispNum((u8)((given_file_number/100)%10),2);
		if(given_file_number>9)
		    dispNum((u8)((given_file_number/10)%10),1);

		    dispNum(given_file_number%10,0);
	}
	else{
	    dispNum((u8)((given_file_number/1000)%10),3);
	    dispNum((u8)((given_file_number/100)%10),2);
	    dispNum((u8)((given_file_number/10)%10),1);
	    dispNum(given_file_number%10,0);
	}
#elif defined(DISP_DEV_AT_PLAY)
	disp_active();

#elif defined(DISP_FILE_NUM_NEW_TYPE)
	if(given_file_number>999)
	    dispNum((u8)((given_file_number/1000)%10),3);
	if(given_file_number>99)
	    dispNum((u8)((given_file_number/100)%10),2);
	if(given_file_number>9)
	    dispNum((u8)((given_file_number/10)%10),1);

	    dispNum(given_file_number%10,0);

    disp_active();		
#else

    dispNum((u8)((given_file_number/1000)%10),3);
    dispNum((u8)((given_file_number/100)%10),2);
    dispNum((u8)((given_file_number/10)%10),1);
    dispNum(given_file_number%10,0);
    disp_active();
	
#endif

#if defined(K189_JM_201_V001)
    LED_STATUS |= LED_MP3;
    LED_STATUS |= LED_PLAY;
#elif defined(K619_FXK_619_V001)
	if(config_led_by_gpio==0){

    		LED_STATUS |= LED_PLAY;
	}
#elif defined(K000_HG_898_V001)
    LED_STATUS |= LED_MP3;
#endif
	
}

#ifdef DISP_DEV_STR_BEFOR_PLAY
void Disp_curr_Dev()
{
    disp_active();
	
    if (given_device== BIT(USB_DISK))
    {
	 dispstring(" USb",0);
    }
    else if (given_device == BIT(SDMMC))
    {
	 dispstring(" Sd",0);
    }
    LED_STATUS &=~LED_2POINT;
}
#endif
/*----------------------------------------------------------------------------*/
/**@brief
   @param
   @return
   @note
*/
/*----------------------------------------------------------------------------*/
void Disp_Nofile(void)
{
    dispstring("....",0);
}
/*----------------------------------------------------------------------------*/
/**@brief
   @param
   @return
   @note
*/
/*----------------------------------------------------------------------------*/
void Disp_Waiting(void)
{
    dispstring(".....",0);
}
/*----------------------------------------------------------------------------*/
/**@brief
   @param
   @return
   @note
*/
/*----------------------------------------------------------------------------*/
void Disp_Nodevice(void)
{
#ifdef DISP_BAR_ICON
    dispchar('-',3);
    dispchar('-',0);

#endif
    dispchar('N',2);
    dispchar('O',1);
}

/*----------------------------------------------------------------------------*/
/**@brief
   @param
   @return
   @note
*/
/*----------------------------------------------------------------------------*/
void Disp_Vol(void)
{
#if defined(K000_HG_898_V001)
	if(get_super_mute_lock()){
    		dispchar('V',2);
    		dispNum((0/10),1);
    		dispNum(0%10,0);
			return;
	}
#endif
#if defined(DISP_VOL_V_CHAR)||defined(K015_983_1_SW005_V001)||defined(K000_HG_898_V001)||defined(K566_JLH_566_V001)||defined(K769_JinRui_769_V001)||defined(K668_YJH_815_V001)||defined(K812_DingChuangXin_D903_V001)||defined(K566_JinRui_566_V001)||defined(K568_JinRui_568_V001)
    dispchar('V',2);
#elif defined(DISP_VOL_V_CHAR_ALIGN_LEFT)
    dispchar('V',3);
#endif
    dispNum((my_music_vol/10),1);
    dispNum(my_music_vol%10,0);
#ifdef VOL_DISP_COL_ICON
    LED_STATUS |= LED_2POINT;
#endif

}

#if defined(AD_MEASURE_TEMP_FUNC)
extern xd_u8 curr_temp;
void Disp_temp(void)
{
    dispNum((curr_temp/10),5);
    dispNum(curr_temp%10,4);
}
#endif
void Disp_Playmode(void)
{

    dispstring(&playmodestr[play_mode][0],0);

}
/*----------------------------------------------------------------------------*/
/**@brief
   @param
   @return
   @note
*/
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/**@brief
   @param
   @return
   @note
*/
/*----------------------------------------------------------------------------*/
#if defined(PLAY_ICON_FLASH)
void disp_play_icon_flash()
{
	static bool flash_bit=0;
	
	flash_bit =~flash_bit;
	
	if(flash_bit){
		LED_STATUS &= ~LED_PLAY;	
	}
	else{
		LED_STATUS |= LED_PLAY;	
	}
}
#endif
void disp_file_time(void)
{

    u16 sec;
    u16 min;
    u32 file_play_time;
    //mad_decode_dsc.total_time;

    file_play_time = get_music_play_time();

    sec = file_play_time % 60;
    min = (file_play_time/60) % 60;
#if defined(LED_USE_1X888)
    LED_STATUS |= LED_2POINT;
#else
    LED_STATUS |= LED_2POINT;
#endif

#if defined(COMMON_CATHODE)	
	LED_BUFF[2] |= BIT(LED_H);
#endif
    dispNum((u8)((min/10)%10),3);
    dispNum(min%10,2);
    dispNum((u8)((sec/10)%10),1);
    dispNum(sec%10,0);

#if defined(LED_USE_COMMON_4X8)	
    LED_STATUS |= LED_2POINT;
#elif defined(KPL_BIG_LED_MODULE)
    LED_STATUS &=~LED_2POINT;
    LED_STATUS_COL|=LED_2POINT;
#endif

    disp_active();

    /*
    sec = mad_decode_dsc.total_time % 60;
    min = (mad_decode_dsc.total_time/60) % 60;
    dispNum((u8)((min/10)%10));
    dispNum(min%10);
    dispNum((u8)((sec/10)%10));
    dispNum(sec%10);
    */
}

void Disp_Pause(void)
{
    #if defined(LED_USE_PLAY_MODE)

    #else
	LED_STATUS |= LED_PAUSE;
    #endif
    disp_file_time();
    disp_active();
#if defined(K189_JM_201_V001)||defined(K000_HG_898_V001)
    LED_STATUS |= LED_MP3;
#endif
#if defined(DISP_PAUS_STRING)||defined(K745_SUOERSI_745_V001)
    	dispstring("PAUS",0);
    	LED_STATUS &= ~LED_2POINT;
#elif defined(DISP_PAU_STRING)||defined(K000_AOKAILIN_G01_V001)||defined(K000_AOKAILIN_537B_V001)||defined(K000_AOKAILIN_535B_V001)||defined(K000_JLH_2402_V001)
    	dispstring(" PAU",0);
    	LED_STATUS &=~LED_2POINT;
#endif

#ifdef K619_FXK_619_V001
	if(config_led_by_gpio==0){
    		dispstring("   P",0);
	}
	else{
    		LED_STATUS |=BIT(LED_F);
    		LED_STATUS |=BIT(LED_E);
	}
#endif
}
void Disp_Stop()
{
    dispstring("StOp",0);

}
void Disp_Play(void)
{
#if defined(LED_USE_PLAY_MODE)
#if defined(K223_BTL_CP153_V001)||defined(K2041_XFW_2041_V001)||defined(K2041_XFW_2041_V002)||defined(K000_XinLei_LC2092_V004)||defined(K1051_JIAMEI_1051_V001)||defined(K1051_JIAMEI_1051C_V001)||defined(K000_XinLei_LC2092_V001)||defined(K000_XinLei_LC2092_V002)||defined(K000_AOKAILIN_535B_V001)||defined(K1025_AIPU_1025_V001)||defined(K000_AOKAILIN_537B_V001)||defined(K1007_JinYiHeLi_1007_V001)||defined(K591_JiaLe_591_V001)||defined(K795_JinYeHeLi_795_V001)||defined(K796_JinYeHeLi_796_V001)||defined(K1025_JinYeHeLi_1025_V001)||defined(K762_JinYiHeLi_762_V001)||defined(K763_JinYiHeLi_763_V001)||defined(K585_YJH_585_V001)||defined(K737_JinYiHeLi_737_V001)||defined(K756_JinYiHeLi_756_V001)||defined(K000_AOKAILIN_G01_V001)||defined(K000_AOKAILIN_508_V001)

#else	
    LED_STATUS |= LED_MP3;
#endif
#else
    LED_STATUS |= LED_PLAY;
    LED_STATUS |= LED_MP3;
#endif
    disp_file_time();
    disp_active();

#ifdef K619_FXK_619_V001
	if(config_led_by_gpio){
    		LED_STATUS |=BIT(LED_F);
	}
#endif
}

void Disp_File_Name(void)
{

}
/*----------------------------------------------------------------------------*/
/**@brief
   @param
   @return
   @note
*/
/*----------------------------------------------------------------------------*/
void Disp_Eq(void)
{
#ifdef DISP_EQ_STR
    dispchar('E',3);
    dispchar('Q',2);
    dispNum(eq_mode,0);
#else
    dispchar('E',2);
    dispNum(eq_mode,1);
#endif
}
void Disp_USB_Slave(void)
{
#ifdef DISP_PC_STR
    dispstring(" PC",0);
#else
    dispstring("U-d",0);
#endif

}
#if defined(IPONE_DOCK_FUNC_ENABLE)
void Disp_IPOD(void)
{
    dispstring("IPOD",0);
}
#endif

#if defined(BLUE_TOOTH_FUNC)
void Disp_BT(void)
{
#ifdef DISP_BLUE_STR
    dispstring("blue",0);
#else
    dispstring(" bT",0);
#endif
}
#endif

void Disp_AUX(void)
{

#ifndef AUX_ICON_FOR_RTC_ALM
#if defined(LED_USE_PLAY_MODE)||defined(LED_USE_ROUND_LED)||defined(LED_USE_PLAY_MODE_WITH_BAT_ICON)||defined(K745_SUOERSI_745_V001)||defined(LED_USE_PLAY_MODE_MIXED)
    LED_STATUS |= LED_AUX;
#endif
#endif
#if defined(LED_USE_1X888)
    dispstring(" LIN",0);
#elif defined(DISP_AUX_STRING)
    dispstring(" AUX",0);
#else	
    dispstring("LINE",0);
#endif

#ifdef K619_FXK_619_V001
	if(config_led_by_gpio){
    		LED_STATUS &=~LED_AUX;
	}
#endif

#ifdef NO_AUX_ICON_DISP
	LED_STATUS &=~LED_AUX;
#endif
#if defined(LINE_IN_PLAY_KEY_PAUSE)

#if defined(DISP_PAUS_STRING)
#ifndef LINE_IN_NO_DISP_PAUS
	if(play_status == MUSIC_PAUSE){
	    	dispstring("PAUS",0);
	}
#endif	
#else
#if !defined(LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR)
	if(play_status){
		LED_STATUS &= ~LED_PAUSE;
		LED_STATUS |= LED_PLAY;
	}
	else{
		LED_STATUS |= LED_PAUSE;
		LED_STATUS &= ~LED_PLAY;
	}
#endif
#endif
#endif
}
#ifdef USE_MICPHONE_GPIO_DETECTION
void Disp_Mic()
{
      dispstring(" NIC",0);
}
#endif

void Disp_Load(void)
{
       dispstring("LOAd",0);
}
void Disp_Start(void)
{
#ifdef K619_FXK_619_V001
	if(config_led_by_gpio==0){
       	dispstring(" SCH",0);
	}
	else{
	       dispstring(" HI",0);
	}
#elif defined(DISP_HIFI_STR_AT_POWER_ON)	
       dispstring("HIFI",0);
#elif defined(K000_HG_898_V001)||defined(MP3_DISP_LOAD_STRING_AT_PWR_ON)
       dispstring("LOAd",0);
#elif defined(K668_YJH_815_V001)
       dispstring("-HI-",0);
#elif defined(K1069_AJE_1069_V001)||defined(DISP_HIFI_ANIMIATION_AT_PWR_ON)||defined(K1069_AJE_1069_V002)
	LED_STATUS = 0xFF;
       dispstring("BBBB",0);
	delay_10ms(20);
	LED_STATUS = 0x00;

       dispstring("   H",0);
	delay_10ms(20);
	
       dispstring("  HI",0);
	delay_10ms(20);
	
       dispstring(" HIF",0);
	delay_10ms(20);
	
       dispstring("HIFI",0);
	delay_10ms(20);	
#elif defined(K000_JR_210_V001)
       dispstring(" -- ",0);
#else
       dispstring(" HI",0);
#endif
}
void Disp_PwrOFF(void)
{
#if defined(K015_983_1_SW005_V001)||defined(K000_XinLei_LC2092_V006)||defined(DISP_OFF_STR_AT_PWR_DOWN)
       dispstring("OFF",0);
	delay_10ms(20);
#elif defined(K000_JR_210_V001)
       dispstring(" -- ",0);
#elif defined(K1069_AJE_1069_V001)||defined(DISP_OFF_ANIMIATION_AT_PWR_DOWN)||defined(K1069_AJE_1069_V002)
       dispstring("   O",0);
	delay_10ms(20);

       dispstring("  OF",0);
	delay_10ms(20);

       dispstring(" OFF",0);

	delay_10ms(20);

#endif

	disp_buf_clear();
}
#ifdef USE_TIMER_POWER_OFF_FUNC
extern u8 timer_disp;
void Disp_Timer_OFF(void)
{
    dispchar('S',3);
    dispchar('L',2);
	
    dispNum((timer_disp/10)%10,1);
    dispNum(timer_disp%10,0);
}
#endif 
void Disp_Error(void)
{
       dispstring("err",0);

}
void Disp_CLR(void)
{
       dispstring("    ",0);

}
/*----------------------------------------------------------------------------*/
/**@brief
   @param
   @return
   @note
*/
/*----------------------------------------------------------------------------*/
void Disp_Power_up(void)
{
    LED_BUFF[0] = 0xff;	  /* 千位 */
    LED_BUFF[1] = 0xff;	  /* 百位 */
    LED_BUFF[2] = 0xff;	  /* 十位 */
    LED_BUFF[3] = 0xff;	  /* 个位 */
    LED_BUFF[4] = 0xff;	  /* 状态位 */
}

void Disp_Freq(void )
{
    /*
    dispNum((u8)((fre_channl/10)%10),0);
    dispNum(fre_channl%10,0);
    dispchar(' ',0,0);
    dispNum((u8)((all_channl/10)%10),0);
    dispNum(all_channl%10,0);
    */
    if (frequency > 999)
    {
        dispNum((u8)((frequency/1000)%10),3);
    }
    else{
#if defined(FM_DISP_CH_STR)
    dispchar(' ',3);
#endif	
    }
    dispNum((u8)((frequency/100)%10),2);
    dispNum((u8)((frequency/10)%10),1);
    dispNum(frequency%10,0);

#ifdef RADIO_AM_WM_ENABLE
	if(work_mode == SYS_FMREV){
    		LED_STATUS |= LED_FM;
	}
	else if(work_mode == SYS_AMREV){
#if defined(KPL_BIG_LED_MODULE)
		LED_STATUS_AM |=LED_AM;
#endif
	}
#else	

#if defined(LED_USE_COMMON_4X8)
    LED_STATUS_FM |= LED_FM;
#else
    LED_STATUS |= LED_FM;
#endif

#endif

#if defined(FM_PLAY_KEY_PAUSE)    
#if defined(DISP_PAU_STRING_ONLY_IN_FM_MODE)
      if (play_status==0){
    		dispstring(" PAU",0);
#ifndef DISP_FM_STR_WHEN_PAUS			
		LED_STATUS &=~LED_FM;
      	}
#endif	  
#elif defined(DISP_PAUS_STRING)
      if (play_status==0){
    		dispstring("PAUS",0);

      }
#endif
#endif
	
#ifdef K619_FXK_619_V001
	if(config_led_by_gpio){
    		LED_STATUS |=BIT(LED_G);
	}
#endif
	
#ifdef UART_ENABLE
	printf("-----> Disp_Freq  %4u \r\n ",frequency);
#endif

}
void Disp_CH_NO(void )
{
#if defined(FM_DISP_CH_STR)
    dispchar('C',3);
    dispchar('H',2);
#else
    dispchar('P',2);
#endif
    dispNum((u8)((fre_channl/10)%10),1);
    dispNum(fre_channl%10,0);
    //LED_STATUS |= LED_FM;

}
void Disp_Scan_NO(void )
{
#if defined(FM_DISP_CH_STR)
    dispchar('C',3);
    dispchar('H',2);
#else	
    dispchar('P',2);
#endif
    dispNum((u8)((all_channl/10)%10),1);
    dispNum(all_channl%10,0);
    //LED_STATUS |= LED_FM;

}
#ifdef DISP_SCH_AT_FM_SCAN		
void Disp_Sch(void)
{
      	dispstring(" SCH",0);
}
#endif
void Disp_Dev_Change(u8 flag)
{
    if (2 == flag)
    {
        dispstring("USB OUT",0);
    }
    else if (1 == flag)
    {
        dispstring("SD OUT",0);
    }

}
#ifdef SUPPORT_PT2313
void Disp_Treble(void)
{
#ifndef NO_PT_STR_DISPLAY
	dispstring("TA",0);
#endif
	if(PT_Treble_Val<7){
		dispchar('Z',1);
		dispNum(7-PT_Treble_Val,0);
	}
	else{
		dispNum(PT_Treble_Val-7,0);
	}
}
void Disp_Bass(void)
{
#ifndef NO_PT_STR_DISPLAY
	dispstring("BA",0);
#endif
	if(PT_Bass_Val<7){
		dispchar('Z',1);
		dispNum(7-PT_Bass_Val,0);
	}
	else{
		dispNum(PT_Bass_Val-7,0);
	}
}
void Disp_Balence(void)
{
#ifndef NO_PT_STR_DISPLAY
	dispstring("BA",0);
#endif
	if(PT_Balence_Val<7){
		dispchar('Z',1);
		dispNum(7-PT_Balence_Val,0);
	}
	else{
		dispNum(PT_Balence_Val-7,0);
	}	
}
void Disp_Fade(void)
{
#ifndef NO_PT_STR_DISPLAY
	dispstring("Fd",0);
#endif
	if(PT_Fade_Val<7){
		dispchar('W',1);
		dispNum(7-PT_Fade_Val,0);
	}
	else{
		dispNum(PT_Fade_Val-7,0);
	}	
}
#endif

#if(RTC_ENABLE)
#include "rtc_mode.h"
extern _xdata RTC_TIME curr_date;
extern _xdata ALM_TIME curr_alm;

extern _xdata u8 rtc_set;
extern _xdata u8 alm_set;
extern _xdata u8 rtc_mode;
extern bool alm_sw;
void oppo_area_rtc(u8 setting)
{
	static bit led_flash = 0;
	if(led_flash){
		led_flash =0;
		return;
	}
	led_flash =1;
	switch(setting)
	{
		case 0:
			LED_BUFF[0]=0;
			LED_BUFF[1]=0;			
			LED_BUFF[2]=0;
			LED_BUFF[3]=0;	
			break;
		case 1:
			LED_BUFF[0]=0;
			LED_BUFF[1]=0;
			break;		
		case 2:
			LED_BUFF[2]=0;
			LED_BUFF[3]=0;			
			break;
		case 3:
			LED_BUFF[0]=0;
			LED_BUFF[1]=0;			
			break;
		case 4:			
			LED_BUFF[2]=0;
			LED_BUFF[3]=0;				
			break;		
		default:break;			
	}

}
void get_curr_setting_data(u8 setting)
{
	u8  setting_buff_high=0,setting_buff_low=0;
	switch(setting)
	{
		case 0:
			setting_buff_high=curr_date.year/100%100;
			setting_buff_low=curr_date.year%100;
#if defined(KPL_BIG_LED_MODULE)
		    	LED_STATUS_COL&=~LED_2POINT;
#else				
	    		LED_STATUS &= ~LED_2POINT;			
#endif
			break;
		case 1:
		case 2:
			if(rtc_mode == ALM_SET_MODE){
				setting_buff_high=curr_alm.hour;
				setting_buff_low =curr_alm.minutes;				
			}				
			else{
				setting_buff_high=curr_date.month;
				setting_buff_low = curr_date.day;
			}	
#if defined(KPL_BIG_LED_MODULE)
		    	LED_STATUS_COL|=LED_2POINT;
#else				
	    		LED_STATUS |= LED_2POINT;				
#endif
			break;
		case 3:
		case 4:
			if(rtc_mode == ALM_SET_MODE){
				setting_buff_high=curr_alm.hour;
				setting_buff_low =curr_alm.minutes;	
 			}
			else{
				setting_buff_high=curr_date.hour;
				setting_buff_low =curr_date.minutes;	
			}
#if defined(KPL_BIG_LED_MODULE)
		    	LED_STATUS_COL|=LED_2POINT;
#else				
	    		LED_STATUS |= LED_2POINT;					
#endif
		break;
		case 5:
  				setting_buff_low = curr_date.date;
	    		LED_STATUS &= ~LED_2POINT;					
			break;		
		default:break;			
	}	    

	    dispNum(((setting_buff_high/10)%10),3);
	    dispNum((setting_buff_high%10),2);
		
	    dispNum(((setting_buff_low/10)%10),1);
	    dispNum((setting_buff_low%10),0);

}
/*----------------------------------------------------------------------------*/
/**@brief  RTC设置界面
   @param  无
   @return 无
   @note   void disp_rtc(void)
*/
/*----------------------------------------------------------------------------*/
void Disp_RTC_POINT()
{
    	static bit LED_Point = 0;
		
	if(LED_Point){
	    LED_Point = 0;		
#if defined(KPL_BIG_LED_MODULE)
	    LED_STATUS_COL|=LED_2POINT;
#else			
	    LED_STATUS |= LED_2POINT;
#endif
	}
	else{
		
	    LED_Point = 1;
#if defined(KPL_BIG_LED_MODULE)
    LED_STATUS_COL&= ~LED_2POINT;
#else			
	    LED_STATUS &= ~LED_2POINT;
#endif
	}
}
#if defined(USE_RTC_YEAR_FUNCTION)||defined(NEW_RTC_SETTING_CTRL)
void Disp_RTC_Date()
{
#if defined(NEW_RTC_SETTING_CTRL)
	u8  setting_buff_high=0,setting_buff_low=0;

	if(new_rtc_setting==1){

		setting_buff_high=curr_date.year/100%100;
		setting_buff_low=curr_date.year%100;
	    	LED_STATUS &= ~LED_2POINT;		
	}
	else if(new_rtc_setting==2){

		setting_buff_high=curr_date.month;
		setting_buff_low = curr_date.day;
	    	LED_STATUS |= LED_2POINT;		
	}
	else if(new_rtc_setting==3){
		setting_buff_high=curr_alm.hour;
		setting_buff_low =curr_alm.minutes;	
	    	LED_STATUS |= LED_2POINT;				
	}
	else if(new_rtc_setting==4){

	    	  if (alm_sw)
       	     dispstring("ON",0);
       	 else
            		dispstring("OFF",0);
		 return;
	}


    dispNum(((setting_buff_high/10)%10),3);
    dispNum((setting_buff_high%10),2);
	
    dispNum(((setting_buff_low/10)%10),1);
    dispNum((setting_buff_low%10),0);
#else
	static _xdata u8 date_show=0;

	if(date_show++>4)date_show=0;
	get_curr_setting_data(date_show);
#endif
}
#endif
void Disp_RTC()
{
    if ((rtc_mode == RTC_PLAY_MODE)||(rtc_mode==ALM_UP_MODE))
    {
	    dispNum((u8)((curr_date.hour/10)%10),3);
	    dispNum(curr_date.hour%10,2);
	    dispNum((u8)((curr_date.minutes/10)%10),1);
	    dispNum(curr_date.minutes%10,0);
	   Disp_RTC_POINT();
    }	
    else if(rtc_mode == RTC_SET_MODE)
    {
	    get_curr_setting_data(rtc_set);
	    oppo_area_rtc(rtc_set);	

    }
    else if(rtc_mode == ALM_SET_MODE)
    {
    	if(alm_set==0){

#if defined(KPL_BIG_LED_MODULE)
    LED_STATUS_COL&= ~LED_2POINT;
#else	
	  LED_STATUS &= ~LED_2POINT;
#endif

#if defined(MINI_DIGIT_BOX)
    	  if (alm_sw)
            dispstring("A ON",0);
        else
            dispstring("AOFF",0);
#else
#ifdef RIGHT_ALIGN_DISP
    	  if (alm_sw)
            dispstring(" ON",0);
        else
            dispstring(" OFF",0);
#else
    	  if (alm_sw)
            dispstring("ON",0);
        else
            dispstring("OFF",0);
#endif
	#ifdef ALARM_ADJ_FLASH_ON_OFF
	    oppo_area_rtc(0);	
	#endif		
#endif				
    	}
#ifdef ALARM_SEL_SOURCE		
       else if(alm_set==3){

			if(alm_source==0){
            			dispstring("beep",0);
			}
			else if(alm_source==1){
            			dispstring("USB",0);

			}	
			else if(alm_source==2){
            			dispstring("FM",0);
			}		
	 }
#elif defined(ALARM_ADJ_VOL)
       else if(alm_set==3){
	    Disp_Vol();
	    oppo_area_rtc(2);	
	}
#endif	   
	else{
	    get_curr_setting_data(alm_set);
	    oppo_area_rtc(alm_set);	
	}
    }

}
void Disp_Alm_Up(void)
{
#ifdef DISP_ALM_UP_SPARK_TIME
	static bool scr_spark=0;

	scr_spark=~scr_spark;
	
	if(scr_spark){
		disp_buf_clear();
	}
	else{
		Disp_RTC();	
	}
#else
    dispstring("----",0);
#endif
}
#endif
#if 0
/*----------------------------------------------------------------------------*/
/**@brief
   @param
   @return
   @note
*/
/*----------------------------------------------------------------------------*/
void Disp_Con(u8 LCDinterf)
{
    ///*
    return_cnt = 0;
    curr_menu = LCDinterf;

    if (DISP_NULL == LCDinterf)
    {
        return;
    }
    clear_led();
    switch (LCDinterf)
    {
    case DISP_NULL:
        Disp_Play();
        break;
    case DISP_DWORD_NUMBER:
        Disp_Num();
        break;
    case DISP_FILENUM:
        Disp_Filenum();
        break;
    case DISP_NOFILE:
        Disp_Nofile();
        break;
    case DISP_NODEVICE:
        Disp_Nodevice();
        break;
    case DISP_PLAY:
        Disp_Play();
        break;
    case DISP_PAUSE:
        Disp_Pause();
        break;
    case DISP_VOL:
        Disp_Vol();
        break;
    case DISP_EQ:
        Disp_Eq();
        break;
    case DISP_POWER_UP:
        Disp_Power_up();
        break;
    case DISP_PLAYMODE:
        Diap_Playmode();
        break;
    case DISP_WAIT:
        Disp_Waiting();
        break;
    case DISP_USBDEV:
        Disp_USB_Slave();
        break;
    case DISP_FREQ:
        Disp_Freq();
        break;
    case DISP_CH_NO:
	 Disp_CH_NO();		
	break;
    case DISP_SCAN_NO:
	 Disp_Scan_NO();		
	break;	
    case DISP_USBOUT:
        disp_devchange(2);
        break;
    case DISP_SDOUT:
        disp_devchange(1);
        break;
    case DISP_AUX:
        Disp_AUX();
     	 break;		
    case DISP_START:
	 Disp_Start();
	 break;
    case DISP_PWR_OFF:
	 Disp_PwrOFF();
	 break;
#if RTC_ENABLE
	case DISP_RTC_POINT:
        Disp_RTC_POINT();
        Disp_RTC();		
	break;
#ifdef USE_RTC_YEAR_FUNCTION	
    case DISP_RTC_DATE:
        Disp_RTC_Date();
        break;
#endif
    case DISP_RTC:
        Disp_RTC();
        break;		
    case DISP_RTC_PWD:
        break;
    case DISP_ALM_UP:
        Disp_Alm_Up();
        break;
#endif
	 
    default:break;
    }
}
#endif
#endif

