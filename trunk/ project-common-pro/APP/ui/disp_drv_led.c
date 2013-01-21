#include "Custom_config.h"
#include "config.h"
#include "disp.h"
#include "lcd.h"
#include "resource.h"
#include "decode.h"
#include "mp3mode.h"


#include "led_drv.h"
#include "PT2313.h"

#if defined(LED_DRV_USE_SM1628)
extern _xdata u8 drv_led_buf[MAX_LED_BUF];
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

xd_u8 led_spark_protect=0;

#ifdef SUPPORT_PT2313
extern xd_u8  PT_Bass_Val;
extern xd_u8  PT_Treble_Val;
extern xd_u8  PT_Balence_Val;
extern xd_u8  PT_Fade_Val;
extern xd_u8  PT_Subw_Val;
#ifdef SUPPORT_M62429
extern xd_u8  M62429_ch1_vol;
extern xd_u8  M62429_ch2_vol;
#endif
#endif
extern _xdata u8 filename_buff[100];
extern void disp_buf_clear(void);

#ifdef NEW_RTC_SETTING_CTRL
extern xd_u8 new_rtc_setting;
#endif


#define ICON_RIGHT_BAR(n,m,v)	if(n==1){drv_led_buf[m]|=v;}else{drv_led_buf[6]&=~(0x20);}

#define ICON_PLAY(n)			if(n==1){drv_led_buf[12]|=0x20;}else{drv_led_buf[12]&=~(0x20);}
#define ICON_PAUSE(n)		if(n==1){drv_led_buf[10]|=0x20;}else{drv_led_buf[10]&=~(0x20);}

#define ICON_DVD(n)			if(n==1){drv_led_buf[0]|=0x20;}else{drv_led_buf[0]&=~(0x20);}
#define ICON_USB(n)			if(n==1){drv_led_buf[6]|=0x40;}else{drv_led_buf[6]&=~(0x40);}
#define ICON_SD(n)			if(n==1){drv_led_buf[8]|=0x40;}else{drv_led_buf[8]&=~(0x40);}
#define ICON_FM(n)			if(n==1){drv_led_buf[4]|=0x40;}else{drv_led_buf[4]&=~(0x40);}
#define ICON_FM_POINT(n)	if(n==1){drv_led_buf[8]|=0x04;}else{drv_led_buf[8]&=~(0x04);}

#define ICON_MAIN_VOL(n)	if(n==1){drv_led_buf[8]|=0x20;}else{drv_led_buf[8]&=~(0x20);}
#define ICON_TREBLE(n)		if(n==1){drv_led_buf[6]|=0x20;}else{drv_led_buf[6]&=~(0x20);}
#define ICON_SW_VOL(n)		if(n==1){drv_led_buf[4]|=0x20;}else{drv_led_buf[4]&=~(0x20);}
#define ICON_BASS_VOL(n)	if(n==1){drv_led_buf[2]|=0x20;}else{drv_led_buf[2]&=~(0x20);}
#define ICON_MIC_VOL(n)		if(n==1){drv_led_buf[12]|=0x40;}else{drv_led_buf[12]&=~(0x40);}
#define ICON_ECHO(n)		if(n==1){drv_led_buf[10]|=0x40;}else{drv_led_buf[10]&=~(0x40);}


#define ICON_RIGHT_BAR_1(n)		if(n==1){drv_led_buf[0]|=0x10;}else{drv_led_buf[0]&=~(0x10);}
#define ICON_RIGHT_BAR_2(n)		if(n==1){drv_led_buf[8]|=0x10;}else{drv_led_buf[8]&=~(0x10);}
#define ICON_RIGHT_BAR_3(n)		if(n==1){drv_led_buf[12]|=0x10;}else{drv_led_buf[12]&=~(0x10);}
#define ICON_RIGHT_BAR_4(n)		if(n==1){drv_led_buf[2]|=0x08;}else{drv_led_buf[2]&=~(0x08);}
#define ICON_RIGHT_BAR_5(n)		if(n==1){drv_led_buf[6]|=0x08;}else{drv_led_buf[6]&=~(0x08);}
#define ICON_RIGHT_BAR_6(n)		if(n==1){drv_led_buf[10]|=0x08;}else{drv_led_buf[10]&=~(0x08);}


#define ICON_LEFT_BAR_1(n)		if(n==1){drv_led_buf[4]|=0x10;}else{drv_led_buf[4]&=~(0x10);}
#define ICON_LEFT_BAR_2(n)		if(n==1){drv_led_buf[10]|=0x10;}else{drv_led_buf[10]&=~(0x10);}
#define ICON_LEFT_BAR_3(n)		if(n==1){drv_led_buf[0]|=0x08;}else{drv_led_buf[0]&=~(0x08);}
#define ICON_LEFT_BAR_4(n)		if(n==1){drv_led_buf[4]|=0x08;}else{drv_led_buf[4]&=~(0x08);}
#define ICON_LEFT_BAR_5(n)		if(n==1){drv_led_buf[8]|=0x08;}else{drv_led_buf[8]&=~(0x08);}
#define ICON_LEFT_BAR_6(n)		if(n==1){drv_led_buf[12]|=0x08;}else{drv_led_buf[12]&=~(0x08);}



#define ICON_5_LED(n)		if(n==1){drv_led_buf[0]|=0x02;\
									drv_led_buf[4]|=0x01;\
									drv_led_buf[6]|=0x01;\
							}\
							else{\
									drv_led_buf[0]&=~0x02;\
									drv_led_buf[4]&=~0x01;\
									drv_led_buf[6]&=~0x01;\
							}


#define ICON_VOL_IND_LED(n)		if(n==1){\
									drv_led_buf[0]|=0x01;\
									drv_led_buf[4]|=0x02;\
								}\
								else{\
									drv_led_buf[0]&=~0x01;\
									drv_led_buf[4]&=~0x02;\
								}


#define ICON_FM_IND_LED(n)		if(n==1){\
									drv_led_buf[2]|=0x03;\
								}\
								else{\
									drv_led_buf[2]&=~0x03;\
								}

#define ICON_BAR_IND_LED(n)		if(n==1){\
									drv_led_buf[0]|=0x04;\
									drv_led_buf[2]|=0x04;\
								}\
								else{\
									drv_led_buf[0]&=~0x04;\
									drv_led_buf[2]&=~0x04;\
								}								

#define ICON_MEDIA_IND_LED(n)		if(n==1){\
									drv_led_buf[4]|=0x04;\
									drv_led_buf[6]|=0x04;\
								}\
								else{\
									drv_led_buf[4]&=~0x04;\
									drv_led_buf[6]&=~0x04;\
								}									
u8 _code playmodestr[5][7] =
{
#if 1//defined(LED_USE_1X888)
    {" ALL"},
    {" FoL"},
    {" ONE"},
    {" RAN"},
    {" OFF"},
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
void aligh_disp_buf(u8 chardat,u8 idx)
{

#if 0
	//ICON_RIGHT_BAR(1,  0   ,0x04);
	//ICON_RIGHT_BAR(1,  2   ,0x02);
	//ICON_RIGHT_BAR(1,  5   ,0x01);
	//ICON_RIGHT_BAR(1,  6   ,0x04);
	return ;
	//chardat=1;
	//idx =3;
#endif

	ICON_MEDIA_IND_LED(1);
	ICON_BAR_IND_LED(1);
	ICON_5_LED(1);
	ICON_FM_IND_LED(1);

	if(idx==0){

		if((chardat&BIT(LED_A))>0){drv_led_buf[12] |=0x80;}else{drv_led_buf[12] &=~(0x80);}
		if((chardat&BIT(LED_B))>0){drv_led_buf[10] |=0x80;}else{drv_led_buf[10] &=~(0x80);}
		if((chardat&BIT(LED_C))>0){drv_led_buf[8] |=0x80;}else{drv_led_buf[8] &=~(0x80);}
		if((chardat&BIT(LED_D))>0){drv_led_buf[6] |=0x80;}else{drv_led_buf[6] &=~(0x80);}
		if((chardat&BIT(LED_E))>0){drv_led_buf[4] |=0x80;}else{drv_led_buf[4] &=~(0x80);}
		if((chardat&BIT(LED_F))>0){drv_led_buf[2] |=0x80;}else{drv_led_buf[2] &=~(0x80);}
		if((chardat&BIT(LED_G))>0){drv_led_buf[0] |=0x80;}else{drv_led_buf[0] &=~(0x80);}

	}
	else if(idx==1){

		if((chardat&BIT(LED_A))>0){drv_led_buf[13] |=0x01;}else{drv_led_buf[13] &=~(0x01);}
		if((chardat&BIT(LED_B))>0){drv_led_buf[11] |=0x01;}else{drv_led_buf[11] &=~(0x01);}
		if((chardat&BIT(LED_C))>0){drv_led_buf[9] |=0x01;}else{drv_led_buf[9] &=~(0x01);}
		if((chardat&BIT(LED_D))>0){drv_led_buf[7] |=0x01;}else{drv_led_buf[7] &=~(0x01);}
		if((chardat&BIT(LED_E))>0){drv_led_buf[5] |=0x01;}else{drv_led_buf[5] &=~(0x01);}
		if((chardat&BIT(LED_F))>0){drv_led_buf[3] |=0x01;}else{drv_led_buf[3] &=~(0x01);}
		if((chardat&BIT(LED_G))>0){drv_led_buf[1] |=0x01;}else{drv_led_buf[1] &=~(0x01);}

	}
	else if(idx==2){

		if((chardat&BIT(LED_A))>0){drv_led_buf[13] |=0x02;}else{drv_led_buf[13] &=~(0x02);}
		if((chardat&BIT(LED_B))>0){drv_led_buf[11] |=0x02;}else{drv_led_buf[11] &=~(0x02);}
		if((chardat&BIT(LED_C))>0){drv_led_buf[9] |=0x02;}else{drv_led_buf[9] &=~(0x02);}
		if((chardat&BIT(LED_D))>0){drv_led_buf[7] |=0x02;}else{drv_led_buf[7] &=~(0x02);}
		if((chardat&BIT(LED_E))>0){drv_led_buf[5] |=0x02;}else{drv_led_buf[5] &=~(0x02);}
		if((chardat&BIT(LED_F))>0){drv_led_buf[3] |=0x02;}else{drv_led_buf[3] &=~(0x02);}
		if((chardat&BIT(LED_G))>0){drv_led_buf[1] |=0x02;}else{drv_led_buf[1] &=~(0x02);}
	}
	else if(idx==3){

		if(chardat==LED_NUMBER[1])
			drv_led_buf[12]|=0x04;
		else
			drv_led_buf[12]&=~(0x04);
			
	}
}

void disp_led_flash()
{
	static bool led_spark=0;

	led_spark=~led_spark;
	
	if(led_spark){
		ICON_VOL_IND_LED(0);
		

	}
	else{
		ICON_VOL_IND_LED(1);		
	}
}

void disp_FM_led_flash()
{
	static bool led_spark=0;

	led_spark=~led_spark;
	
	if(led_spark){
		ICON_FM_IND_LED(0);
		ICON_VOL_IND_LED(0);
		ICON_5_LED(0);	
	}
	else{
		ICON_FM_IND_LED(1);
		ICON_VOL_IND_LED(1);
		ICON_5_LED(1);
	}
}
/*----------------------------------------------------------------------------*/
/**@brief
   @param
   @return
   @note
*/
/*----------------------------------------------------------------------------*/
void dispchar(u8 chardata,u8 offset)
{
    if (offset >= 4)
    {
        return;
    }
    if (( chardata >= 'A')&&(chardata <= 'Z'))
    {
        aligh_disp_buf( LED_LETTER[chardata - 'A'],offset);
    }
    else if (( chardata >= 'a')&&(chardata <= 'z'))
    {
        aligh_disp_buf(LED_LETTER[chardata-'a' + 26],offset);
    }
    else if ( chardata =='-')
   {
   	 if(offset==0)
	        drv_led_buf[0]|=0x80;
	 else if(offset ==1)
	        drv_led_buf[1]|=0x02;
	 else if(offset ==2)
	        drv_led_buf[1]|=0x01;
    }	
    else
    {

    }


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
void dispNum(u8 chardata,u8 offset)
{
	aligh_disp_buf( LED_NUMBER[chardata],offset);
}
void disp_active(void)
{

    if (device_active == BIT(USB_DISK))
    {
#if defined(DISP_DEV_AT_PLAY)
	 dispstring(" USB",0);
#endif

		ICON_USB(1);
	}
    else if (device_active == BIT(SDMMC))
    {
#if defined(DISP_DEV_AT_PLAY)
	 dispstring(" SD",0);
#endif    
		ICON_SD(1);
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
    //LED_STATUS |= LED_MP3;
    //LED_STATUS |= LED_PLAY;
#elif defined(K619_FXK_619_V001)
	if(config_led_by_gpio==0){

    		//LED_STATUS |= LED_PLAY;
	}
#elif defined(K000_HG_898_V001)
    //LED_STATUS |= LED_MP3;
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
    //LED_STATUS &=~LED_2POINT;
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
	ICON_MAIN_VOL(1);	
	//disp_led_flash();
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
    //LED_STATUS |= LED_2POINT;
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
		//LED_STATUS &= ~LED_PLAY;	
	}
	else{
		//LED_STATUS |= LED_PLAY;	
	}
}
#endif

void disp_file_time(void)
{

    u16 sec;
    u16 min;
    u32 file_play_time;

#ifdef LED_DRV_MUTE_ON_FLASH_WHOLE_SCREEN
	if(get_super_mute_lock()){
		return;
	}
#endif

    file_play_time = get_music_play_time();

    sec = file_play_time % 60;
    min = (file_play_time/60) % 60;

    dispNum((u8)((min/10)%10),3);
    dispNum(min%10,2);
    dispNum((u8)((sec/10)%10),1);
    dispNum(sec%10,0);


    disp_active();

}

void Disp_Pause(void)
{
    //ICON_PAUSE(1);
    disp_file_time();
    disp_active();
}
void Disp_Stop()
{
    dispstring("StOp",0);
    ICON_PLAY(0);
    ICON_PAUSE(0);
}
void Disp_Play(void)
{
    disp_file_time();
    disp_active();
    //ICON_PLAY(1);
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
    if(eq_mode==0){

	dispstring(" OFF",0);

    }
    else{
	dispchar('E',2);
    	dispNum(eq_mode,1);
    }
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
	ICON_DVD(1);

#ifndef AUX_ICON_FOR_RTC_ALM
#if defined(LED_USE_PLAY_MODE)||defined(LED_USE_ROUND_LED)||defined(LED_USE_PLAY_MODE_WITH_BAT_ICON)||defined(K745_SUOERSI_745_V001)||defined(LED_USE_PLAY_MODE_MIXED)
    //LED_STATUS |= LED_AUX;
#endif
#endif
#if defined(LED_USE_1X888)
    dispstring(" LIN",0);
#elif defined(DISP_AUX_STRING)
    dispstring(" AUX",0);
#else	
    dispstring("LINE",0);
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
		//LED_STATUS &= ~LED_PAUSE;
		//LED_STATUS |= LED_PLAY;
	}
	else{
		//LED_STATUS |= LED_PAUSE;
		//LED_STATUS &= ~LED_PLAY;
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
	//LED_STATUS = 0xFF;
       dispstring("BBBB",0);
	delay_10ms(20);
	//LED_STATUS = 0x00;

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

	ICON_VOL_IND_LED(1);

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

	ICON_VOL_IND_LED(1);

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
    drv_led_buf[0] = 0xff;	  /* 千位 */
    drv_led_buf[1] = 0xff;	  /* 百位 */
    drv_led_buf[2] = 0xff;	  /* 十位 */
    drv_led_buf[3] = 0xff;	  /* 个位 */
    drv_led_buf[4] = 0xff;	  /* 状态位 */
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


	ICON_FM_POINT(1);
	ICON_FM(1);

	if(led_spark_protect>0){

		disp_FM_led_flash();

	}	
#if defined(FM_PLAY_KEY_PAUSE)    
#if defined(DISP_PAU_STRING_ONLY_IN_FM_MODE)
      if (play_status==0){
    		dispstring(" PAU",0);
#ifndef DISP_FM_STR_WHEN_PAUS			
		//LED_STATUS &=~LED_FM;
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
    		//LED_STATUS |=BIT(LED_G);
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
    ////LED_STATUS |= LED_FM;

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
    ////LED_STATUS |= LED_FM;
    ICON_VOL_IND_LED(1);
    ICON_FM_IND_LED(1);
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

#if defined(SPECTRUM_FUNC_ENABLE)
void clear_spect_disp_buf(void)
{
	ICON_RIGHT_BAR_1(0);ICON_LEFT_BAR_1(0);
	ICON_RIGHT_BAR_2(0);ICON_LEFT_BAR_2(0);
	ICON_RIGHT_BAR_3(0);ICON_LEFT_BAR_3(0);
	ICON_RIGHT_BAR_4(0);ICON_LEFT_BAR_4(0);
	ICON_RIGHT_BAR_5(0);ICON_LEFT_BAR_5(0);
	ICON_RIGHT_BAR_6(0);ICON_LEFT_BAR_6(0);
}
u8 disp_rolling_mode=0,disp_rolling_bar=0,disp_div_timer=0,spilt_timer=10,loop_timer=1;
#ifdef PARTTERN_ROLLING_ACTIVATOR_FUNC
void parttern_rolling_activator(void)
{
	static u8 activator_timer=0;
	
	if((work_mode== SYS_AUX)){

		if(!adc_signal_online_judge()){

			if(activator_timer<60){
				activator_timer++;
			}
			else{
				set_spectrum_lock(LOCK);
			     	//printf("---->parttern_rolling_activator  %d, \r\n",(u16)disp_rolling_mode);
			}
		}
		else{

			if(activator_timer>0)activator_timer--;
			else{
				set_spectrum_lock(UNLOCK);

			}
		}
		
	}
	else if(((work_mode== SYS_MP3DECODE_SD)||(work_mode== SYS_MP3DECODE_USB))){

		if(play_status == MUSIC_PAUSE){
			set_spectrum_lock(LOCK);
		}
		else{
			set_spectrum_lock(UNLOCK);
		}
	}	
}
#endif

extern u8 select_disp_rolling_mode;

void spect_rolling_pattern_disp()
{
	disp_div_timer++;

     	//printf("---->spect_rolling_pattern_disp  %d, \r\n",(u16)disp_div_timer);
	
	if(disp_div_timer<spilt_timer)return;

	disp_div_timer =0;

	disp_rolling_bar++;

     	//printf("---->spect_rolling_pattern_disp  %d,    %d   \r\n",(u16)disp_rolling_mode,(u16)disp_rolling_bar);

	clear_spect_disp_buf();

	if(disp_rolling_mode==1){

		if(disp_rolling_bar==0){

			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
			
		}	
		else if(disp_rolling_bar==1){
			
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
			ICON_RIGHT_BAR_2(1);ICON_LEFT_BAR_2(1);

		}
		else if(disp_rolling_bar==2){
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
			ICON_RIGHT_BAR_2(1);ICON_LEFT_BAR_2(1);
			ICON_RIGHT_BAR_3(1);ICON_LEFT_BAR_3(1);
		}
		else if(disp_rolling_bar==3){
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
			ICON_RIGHT_BAR_2(1);ICON_LEFT_BAR_2(1);
			ICON_RIGHT_BAR_3(1);ICON_LEFT_BAR_3(1);
			ICON_RIGHT_BAR_4(1);ICON_LEFT_BAR_4(1);
		}
		else if(disp_rolling_bar==4){
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
			ICON_RIGHT_BAR_2(1);ICON_LEFT_BAR_2(1);
			ICON_RIGHT_BAR_3(1);ICON_LEFT_BAR_3(1);
			ICON_RIGHT_BAR_4(1);ICON_LEFT_BAR_4(1);
			ICON_RIGHT_BAR_5(1);ICON_LEFT_BAR_5(1);
		}		
		else if(disp_rolling_bar==5){
			
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
			ICON_RIGHT_BAR_2(1);ICON_LEFT_BAR_2(1);
			ICON_RIGHT_BAR_3(1);ICON_LEFT_BAR_3(1);
			ICON_RIGHT_BAR_4(1);ICON_LEFT_BAR_4(1);
			ICON_RIGHT_BAR_5(1);ICON_LEFT_BAR_5(1);
			ICON_RIGHT_BAR_6(1);ICON_LEFT_BAR_6(1);	
		}		
		else if(disp_rolling_bar==6){

			ICON_RIGHT_BAR_2(1);ICON_LEFT_BAR_2(1);
			ICON_RIGHT_BAR_3(1);ICON_LEFT_BAR_3(1);
			ICON_RIGHT_BAR_4(1);ICON_LEFT_BAR_4(1);
			ICON_RIGHT_BAR_5(1);ICON_LEFT_BAR_5(1);
			ICON_RIGHT_BAR_6(1);ICON_LEFT_BAR_6(1);				
		}		
		else if(disp_rolling_bar==7){

			ICON_RIGHT_BAR_3(1);ICON_LEFT_BAR_3(1);
			ICON_RIGHT_BAR_4(1);ICON_LEFT_BAR_4(1);
			ICON_RIGHT_BAR_5(1);ICON_LEFT_BAR_5(1);
			ICON_RIGHT_BAR_6(1);ICON_LEFT_BAR_6(1);				
		}
		else if(disp_rolling_bar==8){

			ICON_RIGHT_BAR_4(1);ICON_LEFT_BAR_4(1);
			ICON_RIGHT_BAR_5(1);ICON_LEFT_BAR_5(1);
			ICON_RIGHT_BAR_6(1);ICON_LEFT_BAR_6(1);					
		}	
		else if(disp_rolling_bar==9){

			ICON_RIGHT_BAR_5(1);ICON_LEFT_BAR_5(1);
			ICON_RIGHT_BAR_6(1);ICON_LEFT_BAR_6(1);					
		}	
		else if(disp_rolling_bar==10){

			ICON_RIGHT_BAR_6(1);ICON_LEFT_BAR_6(1);					
			
		}	
		else if(disp_rolling_bar==11){

			loop_timer--;
			disp_rolling_bar = 0;
			spilt_timer=2;

			if((loop_timer==0)&&(select_disp_rolling_mode==0)){
				disp_rolling_mode = 2;
				loop_timer=3;
			}
		}			
	}
	else if(disp_rolling_mode==2){
		
		if(disp_rolling_bar==1){
			ICON_RIGHT_BAR_1(1);				
		}	
		else if(disp_rolling_bar==2){
			ICON_RIGHT_BAR_2(1);				
		}
		else if(disp_rolling_bar==3){
			ICON_RIGHT_BAR_3(1);				
		}
		else if(disp_rolling_bar==4){
			ICON_RIGHT_BAR_4(1);				
		}		
		else if(disp_rolling_bar==5){
			ICON_RIGHT_BAR_5(1);				
		}
		else if(disp_rolling_bar==6){
			ICON_RIGHT_BAR_6(1);				
		}	
		else if(disp_rolling_bar==7){
			ICON_LEFT_BAR_1(1);				
		}	
		else if(disp_rolling_bar==8){
			ICON_LEFT_BAR_2(1);				
		}	
		else if(disp_rolling_bar==9){
			ICON_LEFT_BAR_3(1);				
		}			
		else if(disp_rolling_bar==10){
			ICON_LEFT_BAR_4(1);				
		}	
		else if(disp_rolling_bar==11){
			ICON_LEFT_BAR_5(1);				
		}	
		else if(disp_rolling_bar==12){
			ICON_LEFT_BAR_6(1);			
		}
		else if(disp_rolling_bar==13){
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
		}
		else if(disp_rolling_bar==14){
			ICON_RIGHT_BAR_2(1);ICON_LEFT_BAR_2(1);
		}
		else if(disp_rolling_bar==15){
			ICON_RIGHT_BAR_3(1);ICON_LEFT_BAR_3(1);
		}
		else if(disp_rolling_bar==16){
			ICON_RIGHT_BAR_4(1);ICON_LEFT_BAR_4(1);
		}
		else if(disp_rolling_bar==17){
			ICON_RIGHT_BAR_5(1);ICON_LEFT_BAR_5(1);
		}
		else if(disp_rolling_bar==18){
			ICON_RIGHT_BAR_6(1);ICON_LEFT_BAR_6(1);
		}
		else if(disp_rolling_bar==19){

			disp_rolling_bar = 0;
			spilt_timer=2;

			loop_timer--;
			if((loop_timer==0)&&(select_disp_rolling_mode==0)){
				disp_rolling_mode = 3;
				loop_timer=2;				
			}			
		}		
	}
	else if(disp_rolling_mode==3){
		
		if(disp_rolling_bar==1){
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
		}
		else if(disp_rolling_bar==2){
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_2(1);
		}
		else if(disp_rolling_bar==3){
			ICON_RIGHT_BAR_2(1);ICON_LEFT_BAR_2(1);
		}
		else if(disp_rolling_bar==4){
			ICON_RIGHT_BAR_2(1);ICON_LEFT_BAR_3(1);
		}
		else if(disp_rolling_bar==5){
			ICON_RIGHT_BAR_3(1);ICON_LEFT_BAR_3(1);
		}
		else if(disp_rolling_bar==6){
			ICON_RIGHT_BAR_4(1);ICON_LEFT_BAR_3(1);
		}		
		else if(disp_rolling_bar==7){
			ICON_RIGHT_BAR_4(1);ICON_LEFT_BAR_4(1);
		}
		else if(disp_rolling_bar==8){
			ICON_RIGHT_BAR_5(1);ICON_LEFT_BAR_4(1);
		}
		else if(disp_rolling_bar==9){
			ICON_RIGHT_BAR_5(1);ICON_LEFT_BAR_5(1);
		}
		else if(disp_rolling_bar==10){
			ICON_RIGHT_BAR_6(1);ICON_LEFT_BAR_5(1);
		}		
		else if(disp_rolling_bar==10){
			ICON_RIGHT_BAR_6(1);ICON_LEFT_BAR_6(1);
		}			
		else if(disp_rolling_bar==11){
			ICON_RIGHT_BAR_6(1);
		}
		else if(disp_rolling_bar==12){

		}
		else if(disp_rolling_bar==13){
			
			disp_rolling_bar = 0;
			spilt_timer=2;

			loop_timer--;
			if((loop_timer==0)&&(select_disp_rolling_mode==0)){
				disp_rolling_mode = 4;
				loop_timer=3;	
			}				
		}		
	}
	else if(disp_rolling_mode==4){

		if(disp_rolling_bar==1){
			ICON_RIGHT_BAR_1(1);				
		}	
		else if(disp_rolling_bar==2){
			ICON_RIGHT_BAR_2(1);				
		}
		else if(disp_rolling_bar==3){
			ICON_RIGHT_BAR_3(1);				
		}
		else if(disp_rolling_bar==4){
			ICON_RIGHT_BAR_4(1);				
		}		
		else if(disp_rolling_bar==5){
			ICON_RIGHT_BAR_5(1);				
		}
		else if(disp_rolling_bar==6){
			ICON_RIGHT_BAR_6(1);				
		}	
		else if(disp_rolling_bar==7){
			ICON_LEFT_BAR_6(1);				
		}	
		else if(disp_rolling_bar==8){
			ICON_LEFT_BAR_5(1);				
		}	
		else if(disp_rolling_bar==9){
			ICON_LEFT_BAR_4(1);				
		}			
		else if(disp_rolling_bar==10){
			ICON_LEFT_BAR_3(1);				
		}	
		else if(disp_rolling_bar==11){
			ICON_LEFT_BAR_2(1);				
		}	
		else if(disp_rolling_bar==12){
			ICON_LEFT_BAR_1(1);			
		}
		else if(disp_rolling_bar==13){
			
			disp_rolling_bar = 0;
			spilt_timer=2;

			loop_timer--;
			if((loop_timer==0)&&(select_disp_rolling_mode==0)){
				disp_rolling_mode = 1;
				loop_timer=3;
				spilt_timer=5;				
			}				
		}			
	}
	else if(disp_rolling_mode==5){

	}
	
	update_led_buf();

}
xd_u8 disp_spect_level=0;
void spect_pattern_disp()
{
	clear_spect_disp_buf();
	switch(disp_spect_level)
	{
		case 0:
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
			break;
		case 1:
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
			ICON_RIGHT_BAR_2(1);ICON_LEFT_BAR_2(1);
			break;
		case 2:
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
			ICON_RIGHT_BAR_2(1);ICON_LEFT_BAR_2(1);
			ICON_RIGHT_BAR_3(1);ICON_LEFT_BAR_3(1);
			break;
		case 3:
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
			ICON_RIGHT_BAR_2(1);ICON_LEFT_BAR_2(1);
			ICON_RIGHT_BAR_3(1);ICON_LEFT_BAR_3(1);
			ICON_RIGHT_BAR_4(1);ICON_LEFT_BAR_4(1);
			break;
		case 4:
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
			ICON_RIGHT_BAR_2(1);ICON_LEFT_BAR_2(1);
			ICON_RIGHT_BAR_3(1);ICON_LEFT_BAR_3(1);
			ICON_RIGHT_BAR_4(1);ICON_LEFT_BAR_4(1);
			ICON_RIGHT_BAR_5(1);ICON_LEFT_BAR_5(1);
			break;	

		case 5:
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
			ICON_RIGHT_BAR_2(1);ICON_LEFT_BAR_2(1);
			ICON_RIGHT_BAR_3(1);ICON_LEFT_BAR_3(1);
			ICON_RIGHT_BAR_4(1);ICON_LEFT_BAR_4(1);
			ICON_RIGHT_BAR_5(1);ICON_LEFT_BAR_5(1);
			ICON_RIGHT_BAR_6(1);ICON_LEFT_BAR_6(1);
			break;	
	}

	update_led_buf();
}
void spect_pattern_disp_reflesh(u8  spec_fresh)
{	

	if(spec_fresh==DISP_STOP_SPECT){

		clear_spect_disp_buf();
		return;
	}
	else if(spec_fresh ==DISP_RUN_SPECT){

		disp_spect_level = get_spect_power();
		//printf("__----spect_pattern_disp_reflesh  %d, \r\n",(u16)disp_spect_level);
		spect_pattern_disp();

	}
	else if(spec_fresh ==DISP_SPECT_ROLLING){

		spect_rolling_pattern_disp();
	}
}
#endif
#if defined(USE_SPECTRUM_PARTTERN)
xd_u8 patern_idx=0;
extern bool get_lcd_flash_lock(void);
void Disp_Patern()
{

	ICON_RIGHT_BAR_1(0);ICON_LEFT_BAR_1(0);
	ICON_RIGHT_BAR_2(0);ICON_LEFT_BAR_2(0);
	ICON_RIGHT_BAR_3(0);ICON_LEFT_BAR_3(0);
	ICON_RIGHT_BAR_4(0);ICON_LEFT_BAR_4(0);
	ICON_RIGHT_BAR_5(0);ICON_LEFT_BAR_5(0);
	ICON_RIGHT_BAR_6(0);ICON_LEFT_BAR_6(0);

#ifdef USE_RTC_FUNCTION
	if(work_mode >= SYS_RTC)return;
#endif	
	if(patern_idx++>7)patern_idx =0;
	if(get_lcd_flash_lock())patern_idx = 7;
	switch(patern_idx)
	{
		case 0:
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
			break;
		case 1:
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
			ICON_RIGHT_BAR_2(1);ICON_LEFT_BAR_2(1);
			break;
		case 2:
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
			ICON_RIGHT_BAR_2(1);ICON_LEFT_BAR_2(1);
			ICON_RIGHT_BAR_3(1);ICON_LEFT_BAR_3(1);

			break;
		case 3:
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
			ICON_RIGHT_BAR_2(1);ICON_LEFT_BAR_2(1);
			ICON_RIGHT_BAR_3(1);ICON_LEFT_BAR_3(1);
			ICON_RIGHT_BAR_4(1);ICON_LEFT_BAR_4(1);
		
			break;
		case 4:
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
			ICON_RIGHT_BAR_2(1);ICON_LEFT_BAR_2(1);
			ICON_RIGHT_BAR_3(1);ICON_LEFT_BAR_3(1);
			ICON_RIGHT_BAR_4(1);ICON_LEFT_BAR_4(1);
			ICON_RIGHT_BAR_5(1);ICON_LEFT_BAR_5(1);
			
			break;	

		case 5:
			ICON_RIGHT_BAR_1(1);ICON_LEFT_BAR_1(1);
			ICON_RIGHT_BAR_2(1);ICON_LEFT_BAR_2(1);
			ICON_RIGHT_BAR_3(1);ICON_LEFT_BAR_3(1);
			ICON_RIGHT_BAR_4(1);ICON_LEFT_BAR_4(1);
			ICON_RIGHT_BAR_5(1);ICON_LEFT_BAR_5(1);
			ICON_RIGHT_BAR_6(1);ICON_LEFT_BAR_6(1);

			break;	

		case 6:
			ICON_RIGHT_BAR_1(0);ICON_LEFT_BAR_1(0);
			ICON_RIGHT_BAR_2(0);ICON_LEFT_BAR_2(0);
			ICON_RIGHT_BAR_3(0);ICON_LEFT_BAR_3(0);
			ICON_RIGHT_BAR_4(0);ICON_LEFT_BAR_4(0);
			ICON_RIGHT_BAR_5(0);ICON_LEFT_BAR_5(0);
			ICON_RIGHT_BAR_6(0);ICON_LEFT_BAR_6(0);
			break;				
	}	
}
#endif

#ifdef SUPPORT_PT2313
void Disp_Treble(void)
{
	u8 disp_temp=0;
#ifndef NO_PT_STR_DISPLAY
	dispstring("TA",0);
#endif

	ICON_TREBLE(1);

	//disp_led_flash();

	if(PT_Treble_Val<PT_MIN_VOL){
		dispchar('-',1);
		//dispNum(PT_MIN_VOL-PT_Treble_Val,0);
		disp_temp = PT_MIN_VOL-PT_Treble_Val;
	}
	else{
		disp_temp = PT_Treble_Val -PT_MIN_VOL;
	}

    	dispNum((disp_temp/10),1);
	dispNum(disp_temp%10,0);	
}
void Disp_Bass(void)
{

	u8 disp_temp=0;

#ifndef NO_PT_STR_DISPLAY
	dispstring("BA",0);
#endif

	ICON_BASS_VOL(1);

	//disp_led_flash();

	if(PT_Bass_Val<PT_MIN_VOL){
		dispchar('-',1);
		//dispNum(PT_MIN_VOL-PT_Bass_Val,0);
		disp_temp = PT_MIN_VOL-PT_Bass_Val;
	}
	else{

		disp_temp = PT_Bass_Val -PT_MIN_VOL;	
		//dispNum(PT_Bass_Val-PT_MIN_VOL,0);
	}

    	dispNum((disp_temp/10),1);
	dispNum(disp_temp%10,0);		
}
void Disp_Balence(void)
{
#ifndef NO_PT_STR_DISPLAY
	dispstring("BA",0);
#endif
	if(PT_Balence_Val<PT_MIN_VOL){
		dispchar('-',1);
		dispNum(PT_MIN_VOL-PT_Balence_Val,0);
	}
	else{
		dispNum(PT_Balence_Val-PT_MIN_VOL,0);
	}	
}
extern bool get_pt_2313_londness_flag();
void Disp_loudness(void)
{

	if(get_pt_2313_londness_flag()){
		dispstring(" ON",0);
	}
	else{
		dispstring(" OFF",0);
	}	
}

void Disp_Fade(void)
{
#ifndef NO_PT_STR_DISPLAY
	dispstring("Fd",0);
#endif
	if(PT_Fade_Val<PT_MIN_VOL){
		dispchar('W',1);
		dispNum(PT_MIN_VOL-PT_Fade_Val,0);
	}
	else{
		dispNum(PT_Fade_Val-PT_MIN_VOL,0);
	}	
}
void Disp_Sw_Vol(void)
{
#ifndef NO_PT_STR_DISPLAY
	dispstring("Fd",0);
#endif

	ICON_SW_VOL(1);
	//disp_led_flash();

    	dispNum((PT_Subw_Val/10),1);
	dispNum(PT_Subw_Val%10,0);			
}
void Disp_Mic_Vol(void)
{
#ifndef NO_PT_STR_DISPLAY
	dispstring("Fd",0);
#endif

	ICON_MIC_VOL(1);
	//disp_led_flash();

   	dispNum((M62429_ch2_vol/10),1);
	dispNum(M62429_ch2_vol%10,0);			
}
void Disp_Echo(void)
{
#ifndef NO_PT_STR_DISPLAY
	dispstring("Fd",0);
#endif

	ICON_ECHO(1);
	//disp_led_flash();

    	dispNum((M62429_ch1_vol/10),1);
	dispNum(M62429_ch1_vol%10,0);		
}

#endif

#ifdef LED_DRV_MUTE_ON_FLASH_WHOLE_SCREEN
void led_spart_automatic()
{
	static bool led_update=0;

	led_update=~led_update;
	if(led_update){
		
		ICON_VOL_IND_LED(1);
	}
	else{
		ICON_VOL_IND_LED(0);
	}	
}

void play_status_led_spark_automatic()
{
	static bool led_update0=0;
	static u8 spark_timer0=0;

	if((work_mode == SYS_MP3DECODE_USB)||(work_mode == SYS_MP3DECODE_SD)){

		spark_timer0++;
		if(spark_timer0==250){

		spark_timer0=0;
		led_update0=~led_update0;
		
		if(play_status==MUSIC_PLAY){

				ICON_PAUSE(0);
				
				if(led_update0){
					
					ICON_PLAY(1);
				}
				else{
					ICON_PLAY(0);
				}	
			}	
			else if(play_status==MUSIC_PAUSE){

				ICON_PLAY(0);

				if(led_update0){
					
					ICON_PAUSE(1);
				}
				else{
					ICON_PAUSE(0);
				}
			}
		}
	}	
}
void led_drv_spark_all()
{
	static bool led_buf_update = 0,disp_restore=0;
	static u8 spark_timer=0;

	play_status_led_spark_automatic();


	if(get_super_mute_lock()){

		spark_timer++;
		if(spark_timer==250){
			spark_timer=0;			
			led_buf_update=~led_buf_update;					
			update_led_buf();	
		}

		disp_restore=1;
		if(led_buf_update){

			disp_buf_clear();
			//ICON_BAR_IND_LED(0);						
			ICON_5_LED(0);
			ICON_VOL_IND_LED(0);
			ICON_FM_IND_LED(0);
		}
		else{

			disp_buf_clear();
			//ICON_BAR_IND_LED(1);			
			ICON_5_LED(1);
			ICON_VOL_IND_LED(1);
			ICON_FM_IND_LED(1);			
			dispstring(" ---",0);
		}		
	}
	else if(led_spark_protect>0){
		
		spark_timer++;
		if(spark_timer==100){
			spark_timer=0;			
			led_spart_automatic();
		}	

	}
	else{
		

		ICON_VOL_IND_LED(1);
		//ICON_FM_IND_LED(1);
	
		spark_timer =0;
		if(disp_restore){
			disp_restore=0;
            		put_msg_fifo(INFO_RESTORE_SCREEN);							
		}
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
			drv_led_buf[0]=0;
			drv_led_buf[1]=0;			
			drv_led_buf[2]=0;
			drv_led_buf[3]=0;	
			break;
		case 1:
			drv_led_buf[0]=0;
			drv_led_buf[1]=0;
			break;		
		case 2:
			drv_led_buf[2]=0;
			drv_led_buf[3]=0;			
			break;
		case 3:
			drv_led_buf[0]=0;
			drv_led_buf[1]=0;			
			break;
		case 4:			
			drv_led_buf[2]=0;
			drv_led_buf[3]=0;				
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
		    	//LED_STATUS_COL&=~LED_2POINT;
#else				
	    		//LED_STATUS &= ~LED_2POINT;			
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
		    	//LED_STATUS_COL|=LED_2POINT;
#else				
	    		//LED_STATUS |= LED_2POINT;				
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
		    	//LED_STATUS_COL|=LED_2POINT;
#else				
	    		//LED_STATUS |= LED_2POINT;					
#endif
		break;
		case 5:
  				setting_buff_low = curr_date.date;
	    		//LED_STATUS &= ~LED_2POINT;					
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
	    //LED_STATUS_COL|=LED_2POINT;
#else			
	    //LED_STATUS |= LED_2POINT;
#endif
	}
	else{
		
	    LED_Point = 1;
#if defined(KPL_BIG_LED_MODULE)
    //LED_STATUS_COL&= ~LED_2POINT;
#else			
	    //LED_STATUS &= ~LED_2POINT;
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
	    	//LED_STATUS &= ~LED_2POINT;		
	}
	else if(new_rtc_setting==2){

		setting_buff_high=curr_date.month;
		setting_buff_low = curr_date.day;
	    	//LED_STATUS |= LED_2POINT;		
	}
	else if(new_rtc_setting==3){
		setting_buff_high=curr_alm.hour;
		setting_buff_low =curr_alm.minutes;	
	    	//LED_STATUS |= LED_2POINT;				
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
    //LED_STATUS_COL&= ~LED_2POINT;
#else	
	  //LED_STATUS &= ~LED_2POINT;
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

#endif

