#include "Custom_config.h"
#include "config.h"
#include "decode.h"
#include "mp3mode.h"
#include "lcd_tm1721_drv.h"

#if defined(USE_LCD_DRV_TM1721)
extern u8 _idata  my_music_vol;  
extern _xdata u8 filename_buff[100];
extern FSAPIMSG _pdata fs_msg;
extern volatile u8 play_mode;
extern volatile u8 eq_mode;
extern xd_u8 all_channl;                              ///< FM收音当前搜索到的台总数
extern u16 cfilenum;
extern volatile u8 device_active;
extern  xd_u16 frequency;
extern xd_u8 fre_channl;
extern xd_u8 fre_point[];
extern xd_u8  PT_Bass_Val;
extern xd_u8  PT_Treble_Val;
extern xd_u8  PT_Balence_Val;
extern _xdata SYS_WORK_MODE work_mode;

_code u8 playmodestr[4][7] = 
{
	{"ALL"},
	{"FOD"},	
	{"ONE"},	
	{"RAN"}
};

xd_u8 tm1721_buf[MAX_SEG_NUM/2 ];

u8 _code letter_tab[] = 
{
    0x77,0x7f,0x39,0x5E,0x79,///<ABCDE
    0x71,0x40,0x76,0x06,0x40,///<FGHIJ
    0x40,0x38,0x40,0x37,0x3F,///<KLMNO
    0x73,0x67,0x50,0x6d,0x31,///<PQRST
    0x3e,0x3e,0x40,0x76,0x40,///<UVWXY
    0x40,///<Z

    0x77,0x40,0x79,0x5E,0x79,///<abcde
    0x71,0x40,0x40,0x30,0x40,///<fghij
    0x40,0x38,0x40,0x54,0x3F,///<klmno
    0x73,0x67,0x50,0x40,0x31,///<pqrst
    0x3e,0x3e,0x40,0x76,0x40,///<uvwxy
    0x40///<z
};
u8 _code figure_tab[] = 
{
    0x3f,0x06,0x5b,0x4f,0x66,  ///<0~4
    0x6d,0x7d,0x07,0x7f,0x6f   ///<5~9
};


#define SD_ICON_ON  		tm1721_buf[8] |= 0x40
#define SD_ICON_OFF 	tm1721_buf[8] &= ~0x40
#define USB_ICON_ON  	tm1721_buf[10] |= 0x40
#define USB_ICON_OFF 	tm1721_buf[10] &= ~0x40
#define MP3_ICON_ON  	tm1721_buf[6] |= 0x04
#define MP3_ICON_OFF 	tm1721_buf[6] &= ~0x04
#define P1_ICON_ON  		tm1721_buf[8] |= 0X80
#define P1_ICON_OFF 	tm1721_buf[8] &= ~0X80
#define P2_ICON_ON  		tm1721_buf[8] |= 0X08
#define P2_ICON_OFF 	tm1721_buf[8] &= ~0X08
#define REP_ICON_ON  	tm1721_buf[12] |= 0X08
#define REP_ICON_OFF 	tm1721_buf[12] &= ~0X08
//#define RAM_ICON_ON  	tm1721_buf[8] |= 0X80
//#define RAM_ICON_OFF 	tm1721_buf[8] &= ~0X80
#define L1_ICON_ON  		tm1721_buf[4] |= 0X40
#define L1_ICON_OFF 	tm1721_buf[4] &= ~0X40
#define L2_ICON_ON  		tm1721_buf[4] |= 0X20
#define L2_ICON_OFF 	tm1721_buf[4] &= ~0X20
#define L3_ICON_ON  		tm1721_buf[4] |= 0X04
#define L3_ICON_OFF 	tm1721_buf[4] &= ~0X04
#define L4_ICON_ON  		tm1721_buf[4] |= 0X02
#define L4_ICON_OFF 	tm1721_buf[4] &= ~0X02
#define L5_ICON_ON  		tm1721_buf[4] |= 0X01
#define L5_ICON_OFF 	tm1721_buf[4] &= ~0X01
#define L6_ICON_ON  		tm1721_buf[4] |= 0X10
#define L6_ICON_OFF 	tm1721_buf[4] &= ~0X10
#define L7_ICON_ON  		tm1721_buf[4] |= 0X01
#define L7_ICON_OFF 	tm1721_buf[4] &= ~0X01
#define T1_ICON_ON  		tm1721_buf[5] |= 0X40
#define T1_ICON_OFF 	tm1721_buf[5] &= ~0X40
#define T2_ICON_ON  		tm1721_buf[5] |= 0X20
#define T2_ICON_OFF 	tm1721_buf[5] &= ~0X20
#define T3_ICON_ON  		tm1721_buf[5] |= 0X10
#define T3_ICON_OFF 	tm1721_buf[5] &= ~0X10
#define T4_ICON_ON  		tm1721_buf[13] |= 0X04
#define T4_ICON_OFF 	tm1721_buf[13] &= ~0X04
#define T5_ICON_ON  		tm1721_buf[13] |= 0X02
#define T5_ICON_OFF 	tm1721_buf[13] &= ~0X02

#define POPS_ICON_ON  	tm1721_buf[12] |= 0X04
#define POPS_ICON_OFF 	tm1721_buf[12] &= ~0X04
#define JAZZ_ICON_ON  	tm1721_buf[13] |= 0X10
#define JAZZ_ICON_OFF 	tm1721_buf[13] &= ~0X10
#define CLAS_ICON_ON  	tm1721_buf[13] |= 0X20
#define CLAS_ICON_OFF 	tm1721_buf[13] &= ~0X20
#define ROCK_ICON_ON  	tm1721_buf[13] |= 0X40
#define ROCK_ICON_OFF 	tm1721_buf[13] &= ~0X40
#define LOUD_ICON_ON  	tm1721_buf[13] |= 0X10
#define LOUD_ICON_OFF 	tm1721_buf[13] &= ~0X10
#define CH_ICON_ON  		tm1721_buf[3] |= 0X80
#define CH_ICON_OFF 	tm1721_buf[3] &= ~0X80
#define FM1_ICON_ON  	tm1721_buf[11] |= 0x40
#define FM1_ICON_OFF 	tm1721_buf[11] &= ~0x40
#define FM2_ICON_ON  	tm1721_buf[11] |= 0x40
#define FM2_ICON_OFF 	tm1721_buf[11] &= ~0x40
#define FM3_ICON_ON  	tm1721_buf[11] |= 0x40
#define FM3_ICON_OFF 	tm1721_buf[11] &= ~0x40
#define POINT_ICON_ON  	tm1721_buf[9] |= 0x04
#define POINT_ICON_OFF 	tm1721_buf[9] &= ~0x04
#define	NUM9_1			tm1721_buf[14] |= 0x08
#define	NUM9_2			tm1721_buf[14] |= 0x08
#define	NUM9_3			tm1721_buf[14] |= 0x04

void disp_buf_clear(void)
{
	my_memset(&tm1721_buf[0], 0x0, (MAX_SEG_NUM / 2));
}
_code Digit_Tab Digit_Buf[TOTAL_DISP_NUM]=
{
	0,
	7,8,7,
	0x02,0x20,0x40,0x08,0xFF,0x40,0x20,0xFF,0x04,0xFF,0xFF,

	1,
	9,8,9,
	0x20,0xFF,0x02,0x04,0xFF,0x80,0x04,0x02,0x40,0xFF,0xFF,

	2,
	10,11,10,
	0x02,0x20,0x40,0x08,0xFF,0x40,0x20,0xFF,0x04,0xFF,0xFF,

	3,
	12,11,12,
	0x20,0xFF,0x02,0x04,0xFF,0x80,0x04,0x02,0x40,0xFF,0xFF,

	4,
	13,14,13,
	0x02,0x20,0x40,0x08,0xFF,0x40,0x20,0xFF,0x04,0xFF,0xFF,
};
void align_digit_buf(u8 align_num,u8 raw_data)
{
	u8 i=0,j=0;
    	u8 bit_flag=0,bit_stop_flag=0;

	for(i=0;i<LED_BIT_IDX_LEN;i++){

		bit_flag = Digit_Buf[align_num].digit_bit_tab[i];

		//printf(" align_digit_buf  bit_flag %x---i  %x \r\n",(u16)bit_flag,(u16)i);
		
		if(bit_flag == 0xFF){

			if(bit_stop_flag++>STOP_NUM)break;
		}
		else{
			//printf(" align_digit_buf  bit_flag %x---jj  %x \r\n",(u16)bit_flag,(u16)j);
			if(raw_data==0xFF){

				 tm1721_buf[Digit_Buf[align_num].buf_idx[bit_stop_flag]] &=~bit_flag;
			}
			else if((raw_data&(0x01<<j))>0){

				 tm1721_buf[Digit_Buf[align_num].buf_idx[bit_stop_flag]] |= bit_flag;
			}
			
			j++;
		}
	}
}
void dispNum(u8 chardata,u8 cnt)
{
#if 0	
   if((cnt==4)||(cnt==6)){

	if((cnt ==4)&&(chardata ==1)){
		
		tm1721_buf[1] |=0x01; 
	}
	else{
   		tm1721_buf[1] &=~0x01;
	}
	
	if((cnt ==6)&&(chardata ==1)){

		tm1721_buf[13] |=0x10; 
	}
	else{
		tm1721_buf[13] &=~0x10; 		
	}
	 
	return;
   }
#endif   
    align_digit_buf(cnt,0xFF);	//clear buf

    align_digit_buf(cnt,figure_tab[chardata]);

}
void dispChar(u8 chardata,u8 cnt)
{
    u8 letter_temp;

    align_digit_buf(cnt,0xFF);
	
    if((chardata>='a')&&(chardata<='z'))
    {
        chardata -= 'a';
        letter_temp = letter_tab[chardata+26];        
    }
    else if((chardata>='A')&&(chardata<='Z'))
    {
        chardata -= 'A';
        letter_temp = letter_tab[chardata];
    }
 
    align_digit_buf(cnt,letter_tab[chardata]);

}

void dispstring(u8 *str,u8 offset0)
{
    u8 cnt = 4;
	cnt = cnt-offset0;	
	do
	{
	    dispChar(*str,cnt);
		str++;
		
	}while((0 != *str) && cnt--);
}
void disp_active(void)
{

    if (device_active == BIT(USB_DISK))
    {
        USB_ICON_ON;
        SD_ICON_OFF;
    }
    else if (device_active == BIT(SDMMC))
    {
        USB_ICON_OFF;
        SD_ICON_ON;
    }

}
void Disp_Null()
{
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
	dispNum((u8)((fs_msg.fileNumber/1000)%10),3);
	dispNum((u8)((fs_msg.fileNumber/100)%10),2);
	dispNum((u8)((fs_msg.fileNumber/10)%10),1);
	dispNum(fs_msg.fileNumber%10,0);

	disp_active();
}
void Disp_Freq(void )
{
	if(frequency > 999)
	{
		dispNum((u8)((frequency/1000)%10),4);	
	}

	dispNum((u8)((frequency/100)%10),3);
	dispNum((u8)((frequency/10)%10),2);
	dispNum(frequency%10,1);
	FM1_ICON_ON;
	POINT_ICON_ON;		
}
void Disp_Update_EQ_Icon()
{
	POPS_ICON_OFF;
	ROCK_ICON_OFF;
	JAZZ_ICON_OFF;
	CLAS_ICON_OFF;

//printf(" Disp_Update_EQ_Icon   %d \r\n",(u16)eq_mode);
	switch(eq_mode)
	{
		case NORMAL:
			break;
		case POP:
			POPS_ICON_ON;
			break;
		case ROCK:
			ROCK_ICON_ON;
			break;
		case CLASSIC:
			CLAS_ICON_ON;
			break;			
		case JAZZ:
			JAZZ_ICON_ON;
			break;
		default:
			break;

	}
}
void Disp_Eq()
{

	Disp_Update_EQ_Icon();
	dispstring("EQ",2);
}
#ifdef SUPPORT_PT2313
void Disp_Treble(void)
{
	dispstring("TAE",0);
	if(PT_Treble_Val<7){
		dispChar('Z',1);
		dispNum(7-PT_Treble_Val,0);
	}
	else{
		dispNum(PT_Treble_Val-7,0);
	}
	POINT_ICON_ON;		
}
void Disp_Bass(void)
{
	dispstring("BAS",0);
	if(PT_Bass_Val<7){
		dispChar('Z',1);
		dispNum(7-PT_Bass_Val,0);
	}
	else{
		dispNum(PT_Bass_Val-7,0);
	}
	POINT_ICON_ON;		
}
void Disp_Balence(void)
{
	dispstring("BAL",0);	
	if(PT_Balence_Val<7){
		dispChar('Z',1);
		dispNum(7-PT_Balence_Val,0);
	}
	else{
		dispNum(PT_Balence_Val-7,0);
	}	
	POINT_ICON_ON;		
}
#endif
void Disp_Nofile()
{
}

void disp_file_time(void)
{	
	u16 sec,min;
 	u32 file_play_time;

	file_play_time = get_music_play_time();
	sec = file_play_time % 60;
	min = (file_play_time/60) % 60;

	dispNum((u8)((min/10)%10),3);
	dispNum(min%10,2);
	dispNum((u8)((sec/10)%10),1);
	dispNum(sec%10,0);
	POINT_ICON_ON;
	MP3_ICON_ON;
	disp_active();
}
void Disp_Nodevice()
{
}
void Disp_Play()
{
//	disp_file_time();
	Disp_Filenum();
}

void Disp_Pause()
{
    disp_active();
    dispstring("PAUSE",0);
}
void Disp_Stop()
{
    dispstring("STOP",0);
    disp_active();
}
void Disp_File_Name()
{
}
void Disp_Vol()
{
       dispstring("VOL",0);
	dispNum((my_music_vol/10),1);
	dispNum(my_music_vol%10,0);
	POINT_ICON_ON;	
}
extern bool get_super_mute_lock();
void Disp_Mute()
{
	if(get_super_mute_lock()){
		T3_ICON_ON;
	}
	else{
		T3_ICON_OFF;
	}
}
void Disp_Power_up()
{
}
void Disp_Playmode()
{
	dispstring(&playmodestr[play_mode][0],1);
}   
void Disp_Waiting()
{
}
void Disp_USB_Slave()
{
}
void Disp_CH_NO()
{
    dispstring("CHZ",0);
    dispNum((u8)((fre_channl/10)%10),1);
    dispNum(fre_channl%10,0);
}	
void Disp_CH_Sel()
{
    dispstring("CHZ",0);
    dispNum((u8)((cfilenum/10)%10),1);
    dispNum(cfilenum%10,0);
}
void Disp_Scan_NO()
{
    dispstring("CHZ",0);
    dispNum((u8)((all_channl/10)%10),1);
    dispNum(all_channl%10,0);
}		
void Disp_Dev_Change(u8 flag)
{
}
void Disp_AUX()
{
    dispstring("AUX",1);
}
void Disp_Error(void)
{
       dispstring("err",0);

}
void Disp_CLR(void)
{
       dispstring("    ",0);

}
#if defined(IPONE_DOCK_FUNC_ENABLE)
void Disp_IPOD(void)
{
    dispstring("IPOD",0);
}
#endif

void Disp_Start()
{
	lcd_backlight_ctrl(TRUE);
#if defined(K105_SWD_2901A_V001)
       dispstring("HELLO",0);
#else
       dispstring("HI",2);
#endif
}
void Disp_PwrOFF()
{
	disp_buf_clear();
	lcd_backlight_ctrl(FALSE);
}
#if defined(USE_SPECTRUM_PARTTERN)
xd_u8 patern_idx=0;
extern bool get_lcd_flash_lock(void);
void Disp_Patern()
{
	if(work_mode == SYS_IDLE)return;
	
	if(patern_idx++>6)patern_idx =0;
	if(get_lcd_flash_lock())patern_idx = 6;
	switch(patern_idx)
	{
		case 0:
			L1_ICON_ON;
			break;
		case 1:
			L1_ICON_ON;
			L2_ICON_ON;
			break;
		case 2:
			L1_ICON_ON;
			L2_ICON_ON;			
			L3_ICON_ON;
			break;
		case 3:
			L1_ICON_ON;
			L2_ICON_ON;			
			L3_ICON_ON;			
			L4_ICON_ON;
			break;
		case 4:
			L1_ICON_ON;
			L2_ICON_ON;			
			L3_ICON_ON;			
			L4_ICON_ON;			
			L5_ICON_ON;
			break;
		case 5:
			L1_ICON_ON;
			L2_ICON_ON;			
			L3_ICON_ON;			
			L4_ICON_ON;			
			L5_ICON_ON;			
			L6_ICON_ON;
			break;	
		case 6:
			L1_ICON_OFF;
			L2_ICON_OFF;
			L3_ICON_OFF;
			L4_ICON_OFF;
			L5_ICON_OFF;
			L6_ICON_OFF;
		break;	
	}	
}
#endif
#if(RTC_ENABLE)
#include "rtc_mode.h"
extern _xdata RTC_TIME curr_date;
extern _xdata ALM_TIME curr_alm;
xd_u16 lcd_buff[4];

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
	//printf("oppo_area_rtc %x \r\n",(u16)setting);
	led_flash =1;
	switch(setting)
	{
		case 0:
			lcd_buff[0]&=~(0x00F0);
			lcd_buff[1]&=~(0x00F0);			
			lcd_buff[2]&=~(0x00F0);
			lcd_buff[3]&=~(0x00F0);	
			break;
		case 1:
			lcd_buff[0]&=~(0x003);
			lcd_buff[1]&=~(0x003);			
			lcd_buff[2]&=~(0x003);
			lcd_buff[3]&=~(0x003);	
			break;		
		case 2:
			lcd_buff[0]&=~(0x003<<2);
			lcd_buff[1]&=~(0x003<<2);			
			lcd_buff[2]&=~(0x003<<2);
			lcd_buff[3]&=~(0x003<<2);			
			break;
		case 3:
			lcd_buff[0]&=~(0x00C);
			lcd_buff[1]&=~(0x00C);			
			lcd_buff[2]&=~(0x00C|0x02);
			lcd_buff[3]&=~(0x00C);			
			break;
		case 4:			
			lcd_buff[0]&=~(0x00F0);
			lcd_buff[1]&=~(0x00F0);			
			lcd_buff[2]&=~(0x00F0);
			lcd_buff[3]&=~(0x00F0);					
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
	    		//F_POINTS &= ~POINTS_MASK;			
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
	    		//F_POINTS |= POINTS_MASK;		
			break;
		case 3:
		case 4:
			if(rtc_mode == ALM_SET_MODE){
				setting_buff_high=curr_alm.hour;
				setting_buff_low =curr_alm.minutes;	

			}
			else{
				if(curr_date.hour>12){
					setting_buff_high=curr_date.hour-12;
				}
				else{
					setting_buff_high=curr_date.hour;
				}
				setting_buff_low =curr_date.minutes;	
			}
	    		//F_POINTS |= POINTS_MASK;				
		break;
		case 5:
  				setting_buff_low = curr_date.date;
	    		//F_POINTS &= ~POINTS_MASK;					
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
		
	if(rtc_mode != RTC_PLAY_MODE)return;
	
	if(LED_Point){
	    LED_Point = 0;			
	    //F_POINTS |= POINTS_MASK;
	}
	else{
		
	    LED_Point = 1;
  	    //F_POINTS &= ~POINTS_MASK;
	}
}
void Disp_Show_AMPM()
{
	if(curr_date.hour>12){
	    //F_RTC_PM |= RTC_PM_MASK;
	    //F_RTC_AM&= ~RTC_AM_MASK;
	}
	else{
	    //F_RTC_AM |= RTC_AM_MASK;
	    //F_RTC_PM &= ~RTC_PM_MASK;
	}
}
void Disp_Show_ALM_Flag()
{
	if(alm_sw){
	   // F_RTC_ALM|= RTC_ALM_MASK;
	}
	else{
	   // F_RTC_ALM&= ~RTC_ALM_MASK;
	}
}
#ifdef USE_RTC_YEAR_FUNCTION
void Disp_RTC_Date()
{
	static _xdata u8 date_show=0;

	if(date_show++>4)date_show=0;
	get_curr_setting_data(date_show);

}
#endif
void Disp_RTC()
{
	u8  setting_buff_high=0;

    if (rtc_mode == RTC_PLAY_MODE)
    {
    		if(curr_date.hour>12){
			setting_buff_high=curr_date.hour-12;
		}
		else{
			setting_buff_high=curr_date.hour;
	 	}
	    dispNum((u8)((setting_buff_high/10)%10),3);
	    dispNum(setting_buff_high%10,2);
	    dispNum((u8)((curr_date.minutes/10)%10),1);
	    dispNum(curr_date.minutes%10,0);

    }	
    else if(rtc_mode == RTC_SET_MODE)
    {
	    get_curr_setting_data(rtc_set);
	    oppo_area_rtc(rtc_set);	

    }
    else if(rtc_mode == ALM_SET_MODE)
    {
    	if(alm_set==0){
			
    	  if (alm_sw)
            dispstring("ON",0);
        else
            dispstring("OFF",0);
    	}
	else{
	    get_curr_setting_data(alm_set);
	    oppo_area_rtc(alm_set);	
	}
    }
	Disp_RTC_POINT();	
	Disp_Show_AMPM();
	Disp_Show_ALM_Flag();
}
void Disp_Alm_Up(void)
{
    dispstring("----",0);
}
#endif
void Lcd_check_buf(void)
{   
	Disp_Mute();
	Disp_Patern();
	Disp_Update_EQ_Icon();
#if 0
	disp_buf_clear();
	//tm1721_buf[7]=0x0b;
	//tm1721_buf[8]=0x0c;
	if(play_mode++>9)play_mode=0;
	dispNum(play_mode,0);	
	dispNum(play_mode,1);	
	dispNum(play_mode,2);	
	dispNum(play_mode,3);	
	dispNum(play_mode,4);	
	//dispNum(0,1);	
#if 0	
	play_mode++;
	dispNum(play_mode,0);
	dispNum(play_mode,1);
	dispNum(play_mode,2);
	dispNum(play_mode,3);
	dispNum(play_mode,4);
#endif

#endif
}


#endif