/*--------------------------------------------------------------------------*/
/**@file     rtc_mode.c
   @brief    RTC
   @details
   @author
   @date   2011-3-7
   @note    AC209N
*/
/*----------------------------------------------------------------------------*/
#include "config.h"
#include "fat_memory.h"
#if RTC_ENABLE
#include "rtc_mode.h"
#include "rtc_cpu.h"
#include "rtc_fun.h"
#include "voice_time.h"
extern u16 cfilenum;
extern xd_u8 curr_menu;
extern xd_u8  return_cnt;
extern bit aux_online;
extern _xdata SYS_WORK_MODE work_mode;
//extern bit key_voice_disable;
//extern void disp_rtc(void);
extern u8 _idata  my_music_vol;  
//extern u8 power_down_cnt;

extern u8 given_device;
_xdata RTC_TIME curr_date;
_xdata ALM_TIME curr_alm;
_xdata u8 rtc_mode; //_at_ 0x71;			///<0：正常显示；1：设置时间模式；2：设置闹钟模式
_xdata u8 rtc_set; //_at_ 0x72;			///<RTC设置界面的方位选择计数器
_xdata u8 alm_set;// _at_ 0x73;
_xdata u8 alm_flag;
#ifdef ALARM_SEL_SOURCE		
xd_u8 alm_source=ALM_SOUR_USB;
#endif
bool alm_sw;

#ifdef NEW_RTC_SETTING_CTRL
xd_u8 new_rtc_setting=0;
#endif


#ifdef ALM_ON_FLASH_SCR
bool alm_flash_flag=0;
#endif
void fond_alm_clk(void);
#ifdef USE_MICPHONE_GPIO_DETECTION
extern bool get_mic_online_status(void);
#endif
extern void set_play_flash(u8 led_status);


/*----------------------------------------------------------------------------*/
/**@brief 检测闹钟
   @param 	无
   @return  无
   @note void check_alm(void)
*/
/*----------------------------------------------------------------------------*/
void check_alm(void)
{
    u8 rtc_reg;
    rtc_reg = read_rtc_reg();
    if (rtc_reg & BIT(7))
    {
        alm_flag = 1;
		put_msg_lifo(INFO_ALM_BELL);
    }
}

/*----------------------------------------------------------------------------*/
/**@brief 获取现在时间
   @param 	void
   @return  void
   @note void get_curr_date(void)
*/
/*----------------------------------------------------------------------------*/
void get_curr_date(void)
{
    sec_date(&curr_date,read_rtc_sec());
}
/*----------------------------------------------------------------------------*/
/**@brief 闹钟跟随当前日期
   @param 	void
   @return  void
   @note void fond_alm_clk(void)
*/
/*----------------------------------------------------------------------------*/

void fond_alm_clk(void)
{
    u8 i;
    RTC_TIME temp_date;
    get_curr_date();
    //memcpy(&temp_date,&curr_date,7);
    for (i = 0; i < sizeof(RTC_TIME); i++)
    {
        ((u8 *)(&temp_date))[i] =  ((u8 *)(&curr_date))[i];
    }
    if ((curr_alm.hour<curr_date.hour)||((curr_alm.hour==curr_date.hour)&&(curr_alm.minutes<=curr_date.minutes)))
        temp_date.day+=1;
    temp_date.second=0;
    temp_date.hour=curr_alm.hour;
    temp_date.minutes=curr_alm.minutes;
    send_alm_sec(date_sec(&temp_date,0));
}

/*----------------------------------------------------------------------------*/
/**@brief 设置闹钟时间
   @param 	void
   @return  void
   @note void set_alm_sec(void)
*/
/*----------------------------------------------------------------------------*/
void set_alm_sec(void)
{

    if (alm_sw)	enable_alm();
    else   disable_alm();
    fond_alm_clk();
    write_info(MEM_ALM_HOUR,curr_alm.hour);
    write_info(MEM_ALM_MIN,curr_alm.minutes);
}


/*----------------------------------------------------------------------------*/
/**@brief 设置现在时间
   @param 	void
   @return  void
   @note void set_date_sec(void)
*/
/*----------------------------------------------------------------------------*/
void set_date_sec(void)
{
    u32 sec;
    sec = date_sec(&curr_date,1);
    send_rtc_sec(sec);
}
/*----------------------------------------------------------------------------*/
/**@brief 日期超限校验
   @param 	void
   @return  void
   @note void chk_date_err(void)
*/
/*----------------------------------------------------------------------------*/
void chk_date_err(void)
{
    if (curr_date.year>2135)
    {
        send_rtc_sec(0);
        sec_date(&curr_date,0);
        fond_alm_clk();
    }
}
/*----------------------------------------------------------------------------*/
/**@brief RTC 初始化
   @param 	void
   @return  void
   @note void init_rtc(void)
*/
/*----------------------------------------------------------------------------*/
#if 0
void alarm_service()
{
	if(alm_flag==1){


	}
	else if(alm_flag >60){

	}
	else{


	}

}
#endif
#ifdef PWR_OFF_WAKEUP_FUNC
extern void wkup_pin_ctrl(bool dir);
#endif

bool init_rtc(void)
{
    u8 rtc_con;
    bool alm_wkup;

    curr_alm.hour = read_info(MEM_ALM_HOUR);
    curr_alm.minutes = read_info(MEM_ALM_MIN);
    if (curr_alm.hour > 23)
    {
#ifdef USE_RTC_ALM_CUSTOM_INIT    
        curr_alm.hour = 0;
#else
        curr_alm.hour = 12;
#endif
    }
    if (curr_alm.minutes > 59)
    {
        curr_alm.minutes = 0;
    }
    alm_sw = 0;
    rtc_con=read_rtc_reg();			 //读出IRTCON = 0x05；32KHz enable,32KHz output

    alm_wkup = 0;

    //printf("%u\n",(u16)rtc_con);
    if (rtc_con & BIT(6))   ///<RTC是否完全掉电
    {
        send_rtc_sec(0);
    }
    else
    {
        if (rtc_con & (1<<1))    ///<RTC是否开闹钟
        {
            alm_sw = 1;
        }
        if (rtc_con & BIT(7))   ///<闹钟唤醒
        {
#ifdef PWR_OFF_WAKEUP_FUNC
#if defined(PWR_CTRL_WKUP)
			    wkup_pin_ctrl(1);
#else
			    power_ctl(1);
#endif
#endif
        
            alm_wkup=1;
            alm_flag = 1;

        }
    }
    get_curr_date();
    chk_date_err();
    fond_alm_clk();

    rtc_con &= ~BIT(6); 				 //清零PDGLG
    write_rtc_reg(rtc_con);
    return alm_wkup;
}
/*----------------------------------------------------------------------------*/
/**@brief 关闹钟闹铃
   @param 	void
   @return  void
   @note void close_alm_bell(void)
*/
/*----------------------------------------------------------------------------*/
void close_alm_bell(void)
{
	if (alm_flag)
	{
	      sys_clock_pll();
	      set_alm_sec();
	      alm_flag = 0;
	      my_main_vol(0);	
	 	//key_voice_disable = 0;
		rtc_mode = RTC_PLAY_MODE;
		Mute_Ext_PA(MUTE);		     
	}
}
/*----------------------------------------------------------------------------*/
/**@brief 打开闹钟
   @param 	void
   @return  void
   @note bool alm_bell(void)
*/
/*----------------------------------------------------------------------------*/
bool alm_bell(void)
{
    if (alm_flag>=60)
    {
        close_alm_bell();
        return_cnt = RETURN_TIME - 1;
    }
    else if (alm_flag)
    {
		rtc_mode = ALM_UP_MODE;
        alm_flag++;
        //key_voice_disable = 1;
        sys_clock_pll();
		dac_sw(1);								//闹钟时打开DAC EN0/1
        main_vol(30);	
        write_dsp(-3, 10, 0x10);
#ifdef ALM_UP_DISP_TIME
        Disp_Con(DISP_RTC);
#else
        Disp_Con(DISP_ALM_UP);
#endif
        return 1;//break;
    }
    return 0;
}
/*----------------------------------------------------------------------------*/
/**@brief 闹钟 模式响应的消息
   @param 	void
   @return  void
   @note u8 alm_bell_key(void)
*/
/*----------------------------------------------------------------------------*/
u8 alm_bell_key(u8 key)
{
#if 0
    switch (key)
    {
    case MSG_USB_DISK_OUT: 
        Disp_Con(DISP_USBOUT);
		return 1;
    case MSG_SDMMC_OUT:
        Disp_Con(DISP_SDOUT);
		return 1;
	case MSG_AUX_IN :
		if (work_mode != SYS_USBDEVICE)
        {
            work_mode = SYS_AUX;
            return 2;
        }
		return 1;
	case MSG_AUX_OUT :
		if (SYS_AUX == work_mode)
        {
            work_mode = SYS_MP3DECODE;
			return 2;
        }
		return 1;
    case MSG_SDMMC_IN :
		if (work_mode == SYS_MP3DECODE)
		{
			given_device = BIT(SDMMC);
        	put_msg_lifo(SEL_GIVEN_DEVICE_GIVEN_FILE);
		}
        if ((work_mode != SYS_MP3DECODE) && (work_mode != SYS_USBDEVICE))
        {	
			given_device = BIT(SDMMC);
        	put_msg_lifo(SEL_GIVEN_DEVICE_GIVEN_FILE);
            work_mode = SYS_MP3DECODE;
            return 2;
        }
		return 1;
    case MSG_USB_DISK_IN  : 
		if (work_mode == SYS_MP3DECODE)
		{
			given_device = BIT(USB_DISK);
        	put_msg_lifo(SEL_GIVEN_DEVICE_GIVEN_FILE);
		}
        if ((work_mode != SYS_MP3DECODE) && (work_mode != SYS_USBDEVICE))
        {
			given_device = BIT(USB_DISK);
        	put_msg_lifo(SEL_GIVEN_DEVICE_GIVEN_FILE);
            work_mode = SYS_MP3DECODE;
            return 2;
        }
		return 1;
    case INFO_EQ_UP | KEY_SHORT_UP :
		return 1;

	case MSG_USB_PC_OUT:
		return 2;
    }
	#endif
	return 0;	
}

/*----------------------------------------------------------------------------*/
/**@brief 闹钟 模式主循环
   @param 	void
   @return  void
   @note u8 alm_bell_mode(void)
*/
/*----------------------------------------------------------------------------*/
u8 alm_bell_mode(void)
{
	u8 key;
	u8 flag;
	alm_flag = 2;
    fond_alm_clk();
	
	while(1)
	{
#if ((USB_DEVICE_CFG & USB_MASS) == USB_MASS)
        if(SYS_USBDEVICE == work_mode)
		{
		    UFI_massstorage();
		}
#endif
		key = get_msg();

		switch (key)
		{
		case INFO_HALF_SECOND :
			if(alm_bell())
			{
				break;
			}
			return 0;

		default :
			flag = alm_bell_key(key);
            if (flag)
            {
                close_alm_bell();
				//return_cnt = RETURN_TIME - 1;		  //
				if(flag == 2)
					return 1;
				if(flag == 1)
					return 0;
            }
		}
	}	
}

#if defined(USE_SNOOZE_FUNC)        
u16 snooze_cnt=0;
bool snooze_en=0;
#define SNOOZE_TIME		5
void set_snooze_func(void)
{
	snooze_en =~snooze_en;	
}
void snooze_hdlr()
{
	if(snooze_en){
		if(snooze_cnt++>(SNOOZE_TIME*60)){
			snooze_en =0;
			snooze_cnt =0;
			alm_flag =1;
		}
	}
}
#endif

#if defined(MINI_DIGIT_BOX)||defined(RTC_SETTING_OP_TIMER_ENABLE)
u8 op_timer=0;
void rtc_setting_key_hdlr(void)
{
	if((rtc_mode==RTC_SET_MODE)||(rtc_mode==ALM_SET_MODE)){

		op_timer++;		
		if(op_timer>12){
			op_timer =0;
#if defined(NEW_RTC_SETTING_CTRL)
			new_rtc_setting=0;
#endif						
	              rtc_mode = RTC_PLAY_MODE;
	              Disp_Con(DISP_RTC);
		}
	}
}
#endif

/*----------------------------------------------------------------------------*/
/**@brief RTC 模式主循环
   @param 	void
   @return  void
   @note void deal_rtc(void)
*/
/*----------------------------------------------------------------------------*/
extern u8 timer_pwr_idx,timer_disp;

void deal_rtc(void)
{
    u8 key;
#ifdef USE_RTC_YEAR_FUNCTION
    bool date_show_active=0;
#endif
#ifdef TURN_OFF_PLAY_STATUS_LED_IN_RTC_MODE
	set_play_flash(LED_FLASH_STOP);
#endif

#ifdef PWR_OFF_IN_RTC_MODE_AFTER_30_MIN
#if defined(USE_TIMER_POWER_OFF_FUNC)
	timer_pwr_idx=3;
	timer_disp=30;
#endif
#endif
    while (1)
    {
        key = get_msg();
        switch (key)
        {
#if defined(K820_LHD_820_V001)
    	case INFO_EQ_DOWN| KEY_SHORT_UP :

		  if(rtc_set==0){

                	rtc_mode = RTC_SET_MODE;
	            	rtc_set=3;
		  }
                else if (rtc_set==4)
                {
	            	rtc_set=0;
                	rtc_mode = RTC_PLAY_MODE;
		  }
		  else if(rtc_set==3){
	            	rtc_set=4;
		  }

		Disp_Con(DISP_RTC);
			
		break;
#endif

#if defined(K686_ZhengYang_686_V001)||defined(USE_MODE_LONG_FOR_RTC_SETTING)
        case INFO_MODE | KEY_LONG:				//4RTC闹钟设置模式
#elif defined(CUSTOM_KEY_LONG_FOR_RTC_HOTKEY)
    case INFO_CUS_KEY_1 | KEY_LONG:  
#elif defined(USE_PLAY_LONG_FOR_RTC_SETTING)
    case INFO_PLAY | KEY_LONG:    		
#elif defined(USE_PREV_LONG_FOR_RTC_SETTING)
        case INFO_PREV_FIL | KEY_LONG:				//4RTC闹钟设置模式
#elif defined(USE_PLAY_MODE_LONG_FOR_RTC_SETTING)
        case INFO_PLAY_MODE | KEY_LONG:				//4RTC闹钟设置模式
#elif defined(MINI_DIGIT_BOX)        
	case INFO_1|KEY_LONG:        
#elif defined(RTC_MODE_HOT_KEY_ENABLE)		
    case INFO_RTC_MOD | KEY_SHORT_UP:        
#else
        case INFO_PLAY | KEY_LONG:				//4RTC闹钟设置模式
#endif

#ifdef INDEPENDENT_KEY_ADJ_TIME

		if (rtc_mode != ALM_UP_MODE)
		{
	           if (rtc_mode==RTC_PLAY_MODE)
	           {
#ifdef USE_RTC_TIME_ONLY
		            	rtc_set=3;
#else
		            	rtc_set=0;
#endif
	                	rtc_mode = RTC_SET_MODE;
	           }
		    else if(rtc_mode==RTC_SET_MODE){
				goto __TIME_ADJ_POS;	
		    }
	           else if (rtc_mode == ALM_SET_MODE)
	           {
				goto __TIME_ADJ_POS;	
		    } 
			   
		    Disp_Con(DISP_RTC);			
		}	
#elif defined(NEW_RTC_SETTING_CTRL)
		if (rtc_mode != ALM_UP_MODE)
		{
			if(new_rtc_setting==0){
				rtc_mode=RTC_SET_MODE;
		            	rtc_set=3;
			}
			else if(new_rtc_setting==1){

				rtc_mode=RTC_SET_MODE;
		            	rtc_set=0;
			}
			else if(new_rtc_setting==2){

				rtc_mode=RTC_SET_MODE;
		            	rtc_set=1;
			}
			else if(new_rtc_setting==3){
				
				rtc_mode=ALM_SET_MODE;
		            	alm_set=1;			

			}
			else if(new_rtc_setting==4){
				
				rtc_mode=ALM_SET_MODE;
		            	alm_set=0;			
			}

	            	Disp_Con(DISP_RTC);
        	}
#else

#if defined(K820_LHD_820_V001)
			break;
#endif
		if (rtc_mode != ALM_UP_MODE)
		{
#if defined(MINI_DIGIT_BOX)   
            	if (rtc_mode==RTC_SET_MODE)
            	{
                	rtc_mode = RTC_PLAY_MODE;
            	}
		else{
			rtc_mode=RTC_SET_MODE;
		}
		op_timer=0;	
#else		
            	rtc_mode++;
	#ifdef USE_RTC_ALARM_FUNCTION				
            	if (rtc_mode>ALM_SET_MODE)
            	{
                	rtc_mode = RTC_PLAY_MODE;
            	}
	#else
            	if (rtc_mode>RTC_SET_MODE)
            	{
                	rtc_mode = RTC_PLAY_MODE;
            	}	
	#endif
#endif

#ifdef USE_RTC_TIME_ONLY
            	rtc_set=3;
#else
            	rtc_set=0;
#endif
            	alm_set=0;

            	Disp_Con(DISP_RTC);
		}
#endif		
            break;
#if defined(MINI_DIGIT_BOX)        
 			
	case INFO_6|KEY_LONG:
		if (rtc_mode != ALM_UP_MODE)
		{
	            	//rtc_mode++;		
	            	if (rtc_mode==ALM_SET_MODE)
	            	{
	                	rtc_mode = RTC_PLAY_MODE;
	            	}
			else{

	                	rtc_mode = ALM_SET_MODE;
		            	alm_set=1;

			}
            	}
		op_timer=0;			

            	  Disp_Con(DISP_RTC);
		break;
	case INFO_2|KEY_LONG:
                rtc_mode = ALM_SET_MODE;
	         alm_set=0;
		  alm_sw =~alm_sw;
            	  Disp_Con(DISP_RTC);
		op_timer=0;			
				  
		break;
#endif

#ifdef INDEPENDENT_KEY_ADJ_TIME

#ifdef RTC_MODE_HOT_KEY_ENABLE
    	case INFO_RTC_MOD | KEY_LONG: 
#else
	case INFO_PLAY | KEY_SHORT_UP:		
#endif		
            	if (rtc_mode==RTC_PLAY_MODE)
            	{
	            	alm_set=0;
                	rtc_mode = ALM_SET_MODE;
            	}
		Disp_Con(DISP_RTC);
		   
		break;
#elif defined(USE_NEXT_LONG_FOR_ALM_SETTING)
        case INFO_NEXT_FIL | KEY_LONG:				//4RTC闹钟设置模式	
                    	if (rtc_mode==RTC_PLAY_MODE)
            	{
	            	alm_set=0;
                	rtc_mode = ALM_SET_MODE;
            	}
		Disp_Con(DISP_RTC);
		   
		break;
#endif

#if defined(K686_ZhengYang_686_V001)||defined(USE_POWER_KEY_TO_ADJ_HOUR_AND_MIN)
        case INFO_POWER| KEY_SHORT_UP:
#elif defined(USE_MODE_LONG_FOR_RTC_SETTING)
        case INFO_MODE| KEY_SHORT_UP:
		if(rtc_mode == RTC_PLAY_MODE){
			goto _HOT_KEY_HDLR;
		}
#elif defined(CUSTOM_KEY_LONG_FOR_RTC_HOTKEY)
    case INFO_CUS_KEY_1 | KEY_SHORT_UP:       
#elif defined(MINI_DIGIT_BOX)        
	case INFO_1|KEY_SHORT_UP:
	case INFO_6|KEY_SHORT_UP:	
		op_timer=0;			
#else
        case INFO_PLAY| KEY_SHORT_UP:
#endif

#if defined(NEW_RTC_SETTING_CTRL)
		if ((rtc_mode != ALM_UP_MODE)&&(rtc_mode !=RTC_PLAY_MODE))
		{
			if(new_rtc_setting==0){
				rtc_mode=RTC_SET_MODE;
	            		rtc_set++;

				if(rtc_set>4){
					rtc_mode=RTC_PLAY_MODE;
				}
			}
			else if(new_rtc_setting==1){

				rtc_mode=RTC_PLAY_MODE;
				Disp_Con(DISP_RTC_DATE);	
				break;				
			}
			else if(new_rtc_setting==2){

				rtc_mode=RTC_SET_MODE;
	            		rtc_set++;

				if(rtc_set>2){

					Disp_Con(DISP_RTC_DATE);
					rtc_mode=RTC_PLAY_MODE;
					break;
				}
			}
			else if(new_rtc_setting==3){
				
				rtc_mode=ALM_SET_MODE;
		            	alm_set++;			
				if(alm_set>2){

					Disp_Con(DISP_RTC_DATE);
					rtc_mode=RTC_PLAY_MODE;
					break;					
				}
			}
			else if(new_rtc_setting==4){

				Disp_Con(DISP_RTC_DATE);	
				rtc_mode=RTC_PLAY_MODE;
				alm_set=0;	
				break;
			}

			  Disp_Con(DISP_RTC);

        	}
#else
#if defined(K820_LHD_820_V001)
			break;
#endif
__TIME_ADJ_POS:
            if (rtc_mode == RTC_SET_MODE)
            {
                rtc_set++;
                if (rtc_set>4)
                {
#ifdef USE_RTC_TIME_ONLY
	            	rtc_set=3;
#else
	            	rtc_set=0;
#endif                
#ifdef RTC_SETTING_NO_CYC
			rtc_mode = RTC_PLAY_MODE;
#endif
		  }
			Disp_Con(DISP_RTC);
            }
            else if (rtc_mode == ALM_SET_MODE)
            {
                alm_set++;
#if defined(ALARM_SEL_SOURCE)
                if (alm_set>3)
#elif defined(ALARM_ADJ_VOL)
                if (alm_set>3)
#else
                if (alm_set>2)
#endif					
                {
                    alm_set=0;
#ifdef RTC_SETTING_NO_CYC
			rtc_mode = RTC_PLAY_MODE;
#endif					
                }
		  Disp_Con(DISP_RTC);
            } 
#endif			
            break;
#ifdef ADJ_TIME_USE_VOL_KEY			
        case INFO_VOL_PLUS:
#ifdef RTC_ADJ_VOL
            if (rtc_mode==RTC_PLAY_MODE)
		goto _HOT_KEY_HDLR;
#endif						
			break;
        case INFO_VOL_PLUS | KEY_SHORT_UP:
        case INFO_VOL_PLUS | KEY_HOLD :			  //4RTC 设置模式下的时间选择（增加）
#else        
        case INFO_NEXT_FIL | KEY_SHORT_UP:
        case INFO_NEXT_FIL | KEY_HOLD:
			
#endif

#ifdef USE_NEXT_PREV_KEY_HOLD_FUNC_SKIP
		if(key==(INFO_NEXT_FIL | KEY_HOLD)) break;
#endif

#if defined(MINI_DIGIT_BOX)        
		op_timer=0;			
#endif
            if (rtc_mode==RTC_SET_MODE)
            {
                curr_date_plus();
                set_date_sec();
                fond_alm_clk();
		  Disp_Con(DISP_RTC);
            }
            else if (rtc_mode==ALM_SET_MODE)
            {
#ifdef ALARM_SEL_SOURCE
                if (alm_set==3){

			alm_source++;
			if(alm_source>ALM_SOUR_FM){
				alm_source=ALM_SOUR_USB;
			}
		   	Disp_Con(DISP_RTC);
			break;
		  }
#elif defined(ALARM_ADJ_VOL)
                if(alm_set==3){

		        my_music_vol++;

			 clear_super_mute_lock();

		        if (my_music_vol > MAX_VOL)
		        {
		            my_music_vol = MAX_VOL;
		        }
	  	}
#endif
                 alm_time_plus();
                 set_alm_sec();
		   Disp_Con(DISP_RTC);
            }
            else
	     {
#ifdef RTC_ADJ_VOL
		goto _HOT_KEY_HDLR;
#endif
#ifdef NEW_RTC_SETTING_CTRL

		new_rtc_setting++;

		if(new_rtc_setting>4){
			new_rtc_setting=0;
		}
				
		if(new_rtc_setting==0){
			
			Disp_Con(DISP_RTC);
		}
		else{
			
			Disp_Con(DISP_RTC_DATE);
		}
#else
#ifdef USE_RTC_YEAR_FUNCTION
		date_show_active = 1;	
		Disp_Con(DISP_RTC_DATE);	
#endif
#endif
	    }
            break;
#ifdef ADJ_TIME_USE_VOL_KEY			
        case INFO_VOL_MINUS:
#ifdef RTC_ADJ_VOL
            if (rtc_mode==RTC_PLAY_MODE)
		goto _HOT_KEY_HDLR;
#endif			
			break;
        case INFO_VOL_MINUS| KEY_SHORT_UP:
        case INFO_VOL_MINUS | KEY_HOLD :		   //4RTC 设置模式下的时间选择（减少）
#else			
        case INFO_PREV_FIL | KEY_SHORT_UP:
        case INFO_PREV_FIL | KEY_HOLD:
#endif

#ifdef USE_NEXT_PREV_KEY_HOLD_FUNC_SKIP
		if(key==(INFO_PREV_FIL | KEY_HOLD)) break;
#endif

#if defined(MINI_DIGIT_BOX)        
		op_timer=0;			
#endif
            if (rtc_mode==RTC_SET_MODE)
            {
                curr_date_minus();
                set_date_sec();
                fond_alm_clk();
		  Disp_Con(DISP_RTC);
            }
            else if (rtc_mode==ALM_SET_MODE)
            {
#ifdef ALARM_SEL_SOURCE
                if (alm_set==3){
					
			if(alm_source--==ALM_SOUR_USB){
				alm_source=ALM_SOUR_FM;
			}
		   	Disp_Con(DISP_RTC);
			break;
		  }
#elif defined(ALARM_ADJ_VOL)
                if(alm_set==3){
					
		        if (my_music_vol)
		            my_music_vol--;

			 clear_super_mute_lock();

			 if(my_music_vol == MIN_VOL){
				Mute_Ext_PA(MUTE);
			 }
	 	}				
#endif
                	alm_time_minus();
               	set_alm_sec();
			Disp_Con(DISP_RTC);
            }
            else
	     {
#ifdef NEW_RTC_SETTING_CTRL

		new_rtc_setting--;
		if(new_rtc_setting>4){
			new_rtc_setting=4;
		}
		
		if(new_rtc_setting==0){
			
			Disp_Con(DISP_RTC);
		}
		else{
			
			Disp_Con(DISP_RTC_DATE);
		}
#else
#ifdef USE_RTC_YEAR_FUNCTION
		date_show_active = 1;		
		Disp_Con(DISP_RTC_DATE);
#endif
#endif
	    }
            break;

#if defined(MINI_DIGIT_BOX)   			
#if defined(USE_SNOOZE_FUNC)        
	case INFO_7|KEY_SHORT_UP:
            if (alm_flag>0)						 //4闹钟响后默认增加一天秒数
            {
		  set_snooze_func();				            
                close_alm_bell();
                Disp_Con(DISP_RTC);
            }
            break;		
#endif		
#endif		

        case INFO_EQ_UP | KEY_SHORT_UP:			 //4清除闹钟
            if (alm_flag)						 //4闹钟响后默认增加一天秒数
            {
#if defined(USE_SNOOZE_FUNC)        
		  set_snooze_func();				            
#endif		
                close_alm_bell();
                Disp_Con(DISP_RTC);
            }
            break;

        case INFO_HALF_SECOND :
#if ((USE_DEVICE == MEMORY_STYLE)&&(FAT_MEMORY))          
             updata_fat_memory();
#endif            
			
#if defined(AD_MEASURE_TEMP_FUNC)
		adc_diode_temp_measure_hdlr();
#endif
#ifdef DISP_BACKLIGHT_AUTO_SAVE_POWER
	 	Disp_BL_time_out();
#endif

#if defined(USE_SNOOZE_FUNC)        
		snooze_hdlr();
#endif
#if defined(USE_TIMER_POWER_OFF_FUNC)
	       timer_pwr_off_hdlr();
#endif

#ifdef USE_MICPHONE_GPIO_DETECTION
		if(get_mic_online_status()){
			Disp_Con(DISP_MIC);
			break;
		}
#endif
            if ((DISP_ALM_UP == curr_menu) || (alm_flag>0))
            {
                if (alm_flag>=60)
                {
                    close_alm_bell();
                    return_cnt = (RETURN_TIME);
		      
                }
                else if (alm_flag)
                {
			rtc_mode = ALM_UP_MODE;
                    alm_flag++;
                    //key_voice_disable = 1;
    		      Mute_Ext_PA(UNMUTE);
    		      set_max_vol(MAX_ANALOG_VOL, MAX_DIGITAL_VOL);			//设置RTC模式的音量上限
    			dac_out_select(DAC_DECODE);				  
                    sys_clock_pll();
		      my_main_vol(my_music_vol);	
                    write_dsp(-3, 10, 0x10);
#ifdef ALM_UP_DISP_TIME
                    Disp_Con(DISP_RTC_POINT);
#else
                    Disp_Con(DISP_ALM_UP);
#endif
#ifdef ALM_ON_FLASH_SCR
			alm_flash_flag=~alm_flash_flag;
		     if(alm_flash_flag){
                    	  Disp_Con(DISP_PWR_OFF);
		      }
#endif
#if defined(USE_BAT_MANAGEMENT)
			bmt_hdlr();
#endif
		      //delay_10ms(10);
                    break;
                }					
            }


            if ((rtc_mode==RTC_PLAY_MODE)||(rtc_mode==ALM_UP_MODE))					//4除闹钟模式外一直更新now_time
            {
                  get_curr_date();
                  chk_date_err();
                    //Disp_Con(DISP_RTC);
            }
#if defined(MINI_DIGIT_BOX)||defined(RTC_SETTING_OP_TIMER_ENABLE)
	     rtc_setting_key_hdlr();
#endif
            if (return_cnt < (RETURN_TIME))
            {
                return_cnt++;
            }
            if ((RETURN_TIME) == return_cnt)
            {
                if ((DISP_RTC != curr_menu) || (0 != rtc_mode))
                {
		      rtc_set = 0;
    		      alm_set = 0;
                    rtc_mode = 0;
#if defined(NEW_RTC_SETTING_CTRL)
			new_rtc_setting=0;
#endif			
                    get_curr_date();
                    Disp_Con(DISP_RTC);
                }
		
#ifdef USE_RTC_YEAR_FUNCTION			
	     date_show_active=0;
#endif				
            }	

#ifdef RTC_ADJ_VOL
		  if(DISP_VOL == curr_menu){
		  }
		  else
#endif				
			
#ifdef USE_RTC_YEAR_FUNCTION			
	     if(!date_show_active)
#elif defined(NEW_RTC_SETTING_CTRL)
	     if((rtc_mode == RTC_PLAY_MODE)&&(new_rtc_setting>0)){
			break;
		 }
		 	
#endif
		{
            		Disp_Con(DISP_RTC_POINT);
		}
#if defined(USE_BAT_MANAGEMENT)
		bmt_hdlr();
#endif

            break;

        default :
_HOT_KEY_HDLR:			
            if (!ap_handle_hotkey(key))
            {
                close_alm_bell();
                return;
            }
        }
    }
}

/*----------------------------------------------------------------------------*/
/**@brief RTC 模式
   @param 	void
   @return  void
   @note void rtc_function(void)
*/
/*----------------------------------------------------------------------------*/
void rtc_function(void)
{
#if !defined(MINI_DIGIT_BOX)        
    rtc_mode = RTC_PLAY_MODE;
    rtc_set = 0;
    alm_set = 0;
#endif	
    flush_low_msg();
    PT1 = 1;
    Mute_Ext_PA(MUTE);		     

    if (alm_flag)	 //闹钟响时默认进入闹钟模式
    {
		rtc_mode = ALM_UP_MODE;
#ifdef ALM_UP_DISP_TIME
          	Disp_Con(DISP_RTC);
#else
        	Disp_Con(DISP_ALM_UP);
#endif
        	goto _deal_rtc0;
    }
    else
    {
        get_curr_date();
        Disp_Con(DISP_RTC);
    }

    set_max_vol(MAX_ANALOG_VOL, MAX_DIGITAL_VOL);			//设置RTC模式的音量上限
    dac_out_select(DAC_DECODE);
    sysclock_div2(1);
#if 0			
		printf(" -----> RTC MODE %x rtc_set   %x\r\n",(u16)rtc_mode,(u16)rtc_set);
			
		printf(" --0000-->RTC MODE ==%d \r\n",(u16)curr_date.year);
		printf(" --1111--->RTC MODE ==%d \r\n",(u16)curr_date.month);
		printf(" --3333--->RTC MODE ==%d \r\n",(u16)curr_date.day);
		printf(" --4444--->RTC MODE ==%d \r\n",(u16)curr_date.hour);
		printf(" --5555--->RTC MODE ==%d \r\n",(u16)curr_date.minutes);

		printf(" --date--->RTC MODE ==%d \r\n",(u16)curr_date.date);
#endif		

_deal_rtc0:
    deal_rtc();

#if defined(NEW_RTC_SETTING_CTRL)
	new_rtc_setting=0;
#endif			
	
    main_vol_set(0, CHANGE_VOL_NO_MEM);
	
    sys_clock_pll();
}
#endif
