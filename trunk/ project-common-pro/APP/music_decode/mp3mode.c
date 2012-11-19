/*--------------------------------------------------------------------------*/
/**@file     mp3mode.c
   @brief    解码任务模块
   @details
   @author
   @date   2011-3-7
   @note
*/
/*----------------------------------------------------------------------------*/

/*mp3mode.c*/
#include "Custom_config.h"

#include "mp3mode.h"
#include "rtc_mode.h"
#include "PT2313.h"

#include "fat_memory.h"
#include "config.h"
#include "voice_time.h"
//#include "common.h"
extern u8 _xdata buffer[1024];              //<解码BUFF
extern u8 _xdata win_buffer[512];           //<文件系统读BUFF
extern FSAPIMSG _pdata fs_msg;              //<带有文件文件系统信息的结构体变量
extern _xdata u8 filename_buff[];
extern bool get_filename( u8 _xdata *p );
extern MAD_DECODE_INFO _pdata mad_decode_dsc;
extern xd_u8 return_cnt;
extern u16 cfilenum;
extern xd_u8 curr_menu;
extern u8 device_active;
extern u8 decode_cmd;
extern void set_play_flash(u8 led_status);
extern xd_u8 IR_Type;
extern bool IR_KEY_Detect;
extern bool pwr_up_flag;
extern _xdata SYS_WORK_MODE work_mode;
extern SYS_WORK_MODE Next_Func();
#if defined(TWO_PLAY_LED_IN_USE)
extern bool led_open_enable;
#endif
#if defined(TIME_FORCE_SHOW_ON_SCREEN)
extern xd_u8 time_show_return_cnt; 
#endif
#ifdef USB_SD_DEV_PLUG_MEM
extern xd_u8 last_plug_dev;
#endif

#ifdef VOL_ADJ_SPARK_LED
extern bool vol_adj_spark_bit;
extern xd_u8 last_led_play_mod;
#endif

#if defined(PLAY_ICON_FLASH)
extern void disp_play_icon_flash();
#endif

#if defined(K619_FXK_619_V001)
extern bool config_led_by_gpio;
#endif
#if defined(NEW_VOLUME_KEY_FEATURE)||defined(VOL_TUNE_NEW_VOLUME_KEY_FEATURE)
extern bool new_vol_feature;
extern u8 last_disp_menu;
#endif

#ifdef DEVICE_SEL_MANUAL_ONLY
extern xd_u8 device_selected;
#endif
#if defined(DEFAULT_GO_TO_CUSTOM_MODE)
bool custom_first_time_pwr_flag=0;
#endif

#ifdef PREV_KEY_SKIP_SONG_DELAY
bool prev_skip_timer=0;
#endif

#ifdef USB_SD_PWR_UP_AND_PLUG_NOT_PLAY
bool dev_first_plugged_flag=0;
#endif

extern u8 _idata  my_music_vol;
extern FSINFO _xdata fs_info;

extern s8 _idata ff_fr_step;  ///<快进 快退步径 负数为快退 正数为快进
//bool play_status;       ///< 播放状态 1:播放;0:暂停;
u8 play_status;			///< 播放状态 0：暂停；1：播放；2：快进/快退；

u8 given_device = 0x02;        ///< 指定需要获取的设备 1 SD ; 2 USB; 0:不知道设备；其他：非法值
/** 音效模式 */
u8 eq_mode;
/** 循环模式 */
u8 play_mode _at_ 0x71;
/** 指定找到的文件号 */
u16 given_file_number _at_ 0x72;
/** 当前解码播放的文件的格式 */
u8 music_type _at_ 0x74;
/** 文件信息滚动显示的计数值 */
//u16 filenameCnt _at_ 0x75;

#ifdef MP3_SELECT_SONG_WHILE_PLAY
xd_u8 select_file_timer=0;
#endif

#if defined(TURN_ON_PLAY_BREAK_POINT_MEM)
bool playpoint_flag;
extern u16 playpoint_filenum;
extern PLAYPOINT_TIME playpoint_time;
extern u8 _idata music_vol;
extern FSINFO _xdata fs_info;
#endif
#if defined(USE_LONG_PLAY_KEY_TO_RESET_SONG_NUM)
extern  xd_u8 reset_key_cnt;
#endif

#if defined(SYS_GO_IN_IDLE_IN_30_SEC)
xd_u8 sys_idle_cnt =0;
bool sys_timer_idle_hdlr()
{
            if (!play_status){
			if(sys_idle_cnt++>60){
				sys_idle_cnt =0;
	                    //put_msg_fifo(INFO_POWER | KEY_SHORT_UP);
	                    	Mute_Ext_PA(MUTE);
				work_mode =SYS_IDLE;
       			put_msg_fifo(INFO_SYS_IDLE);
       			pwr_up_flag =1;		   					
       			return 1;
			}
            }
	     else{
				sys_idle_cnt =0;
				return 0;
		}
}
	
#endif
void set_fast_play_cmd(u8 cmd)
{
	if(play_status){

		if(cmd==1){

			ff_fr_step = FF_FF_STEP;
			play_status = MUSIC_FF_FR;
#if defined(FF_FR_TURN_ON_MUSIC)
			if(0 == decode_cmd)
#endif
			{			
				analog_vol_set(0);
				decode_cmd = 0xf0;
			}
		}
		else if(cmd==2){

			ff_fr_step = FF_FR_STEP;
			play_status = MUSIC_FF_FR;
#if defined(FF_FR_TURN_ON_MUSIC)
			if(0 == decode_cmd)
#endif					
			{
				analog_vol_set(0);
				decode_cmd = 0xf1;
			}
		}
	}
}
/*----------------------------------------------------------------------------*/
/**@brief MUSIC解码信息初始化
   @param 无
   @return  无
   @note void music_info_init(void)
*/
/*----------------------------------------------------------------------------*/
void music_info_init(void)
{
#ifdef K619_FXK_619_V001
	if(config_led_by_gpio==0){
	    Disp_Con(DISP_START);
	    delay_10ms(60);		
	}
#endif

#if !defined(TURN_ON_PLAY_BREAK_POINT_MEM)			
#if defined(USB_SD_PLAY_INFO_DIV)
	if(given_device==0x01){
	    ((u8  *)(&given_file_number))[0] = read_info(MEM_FILENUM_SD);
	    ((u8  *)(&given_file_number))[1] = read_info(MEM_FILENUM_SD+1);		
	}
	else if(given_device==0x02){
	    ((u8  *)(&given_file_number))[0] = read_info(MEM_FILENUM_USB);
	    ((u8  *)(&given_file_number))[1] = read_info(MEM_FILENUM_USB+1);	
	}
#else
    ((u8  *)(&given_file_number))[0] = read_info(MEM_FILENUM);
    ((u8  *)(&given_file_number))[1] = read_info(MEM_FILENUM+1);
#endif
#endif
    if (given_file_number == 0)
        given_file_number = 1;

#if defined( PLAY_MODE_MEM_RECOVER)
    play_mode = read_info(MEM_PLAY_MODE);
    if (play_mode > REPEAT_RANDOM)
    {
        play_mode = REPEAT_ALL;
    }
#elif defined(PLAY_MODE_REPEAT_ALL)
        play_mode = REPEAT_ALL;
#elif defined(PLAY_MODE_REPEAT_ONE)
        play_mode = REPEAT_ONE;

#elif defined(PLAY_MODE_REPEAT_FOLDER)
        play_mode = REPEAT_FOLDER;
#else
        play_mode = REPEAT_DEV_ALL;
#endif
    if (given_device == 0)
    {
        given_device = read_info(MEM_ACTIVE_DEV);
        if ((given_device != 0x01) && (given_device != 0x02))
        {
    		if(work_mode == SYS_MP3DECODE_USB){
           		given_device = 0x02;	
		}
		else{
	            given_device = 0x01;
		}			
            given_file_number = 1;
        }
#if defined(USB_SD_PLAY_INFO_DIV)
	if(given_device==0x01){
	    ((u8  *)(&given_file_number))[0] = read_info(MEM_FILENUM_SD);
	    ((u8  *)(&given_file_number))[1] = read_info(MEM_FILENUM_SD+1);		
	}
	else if(given_device==0x02){
	    ((u8  *)(&given_file_number))[0] = read_info(MEM_FILENUM_USB);
	    ((u8  *)(&given_file_number))[1] = read_info(MEM_FILENUM_USB+1);			
	}
#endif	
    }
    else
    {
        if (given_device != read_info(MEM_ACTIVE_DEV))
        {
#if defined(USB_SD_PLAY_INFO_DIV)
		if(given_device==0x01){
		    ((u8  *)(&given_file_number))[0] = read_info(MEM_FILENUM_SD);
		    ((u8  *)(&given_file_number))[1] = read_info(MEM_FILENUM_SD+1);		
		}
		else if(given_device==0x02){
		    ((u8  *)(&given_file_number))[0] = read_info(MEM_FILENUM_USB);
		    ((u8  *)(&given_file_number))[1] = read_info(MEM_FILENUM_USB+1);			
		}
#else
            given_file_number = 1;
#endif
        }		
    }
#ifdef DEVICE_SEL_MANUAL_ONLY
    device_selected=given_device;
#endif			

    eq_mode = read_info(MEM_EQ_MODE);

#if defined(EQ_MODE_DEFUALT_JAZZ)
    eq_mode = JAZZ;		//reset EQ mode
#elif defined(EQ_MODE_DEFUALT_POP)
    eq_mode = POP;		//reset EQ mode    
#elif defined(EQ_MODE_DEFUALT_ROCK)
    eq_mode = ROCK;		//reset EQ mode
#else
    eq_mode = NORMAL;	//reset EQ mode
#endif

     	  play_status = MUSIC_PLAY;            

 //   if (eq_mode > CLASSIC)
 //   {
 //       eq_mode = NORMAL;
 //   }

}
/*----------------------------------------------------------------------------*/
/**@brief   停止解码
   @param   无
   @return  无
   @note   stop_decode
*/
/*----------------------------------------------------------------------------*/
void stop_decode(void)
{
#if defined(SPECTRUM_FUNC_ENABLE)
     	set_spectrum_lock(LOCK);
#endif		  
    	play_status = MUSIC_STOP;
    //main_vol_set(0, CHANGE_VOL_NO_MEM);//digital_fade_out();
    	read_usb_remain_data();
    	disable_decode_isr();
    	disable_softint();
    	cfilenum = 0;
#ifdef PREV_KEY_SKIP_SONG_DELAY
	prev_skip_timer=0;
#endif
	
}

/*----------------------------------------------------------------------------*/
/**@brief  开始解码
   @param  无
   @return 无
   @note   start_decode
*/
/*----------------------------------------------------------------------------*/
//#define DEBUG_ID3
bool start_decode(void)
{
#ifdef DEBUG_ID3
 u8 i;
 char *fname;
#endif
#if FILE_ENCRYPTION
    if((fs_msg.fname[8]== 'S')&&(fs_msg.fname[9]== 'M')&&(fs_msg.fname[10]== 'P'))
    {
        password_start(1);
    }
    else
    {
        password_start(0);
    }
#endif
    Disp_Con(DISP_FILENUM);
    mad_control(0,(u16)buffer);
    set_eq(eq_mode);                             //必须在每首歌曲播放前初始化EQ
    music_type = musice_format_check(buffer);
#if EQ_WORK_USE == DSP_EQ
    sysclock_div2(0);
    sd_speed_init(1, 100);
#else
	if (music_type == 2) 							//wav
	{
    	sysclock_div2(0);
    	sd_speed_init(1, 100);
	}
	else
	{
		sysclock_div2(1);
    	sd_speed_init(0, 50);
	}
#endif
    get_filetag(buffer);
    my_memset(win_buffer, 0, 512);              //解码前，必须清除buffer

#ifdef DEBUG_ID3
#if 0
	printf("\r\n******ID3 ***********\r\n");

	for(i=0;i<100;i++){
		fname=&filename_buff[i];
		printf(fname);
		if(*fname=='-')printf("\r\n$$$$$$$$$$$$$\r\n");
		if(*fname==' ')break;
	}
	printf("\r\n*******ID3************\r\n");

#endif	
#if 0
	printf("fs_get_filenum fileTotal =%d\r\n",(u16)fs_msg.fileTotal);
	printf("fs_get_filenum dirTotal =%d\r\n",(u16)fs_msg.dirTotal);
	printf("fs_get_filenum fileTotalInDir =%d\r\n",(u16)fs_msg.fileTotalInDir);
	printf("fs_get_filenum fileTotalOutDir =%d\r\n",(u16)fs_msg.fileTotalOutDir);
	printf("fs_get_filenum file_index =%d\r\n",(u16)fs_msg.file_index);
	printf("fs_get_filenum dir_index =%d\r\n",(u16)fs_msg.dir_index);

	printf("*****FILE NAME***********\r\n");

	for(i=0;i<12;i++){
		fname=&fs_msg.fname[i];
		printf(fname);
		if(fname==' ')break;
	}
	printf("*********************\r\n");

	
	printf("-----DIR NAME-----------\r\n");
		for(i=0;i<12;i++){
			fname=&fs_msg.dname[i];
			printf(fname);
			if(fname==' ')break;
	}
#endif	
#endif	

    write_info(MEM_ACTIVE_DEV,device_active);

#if !defined(TURN_ON_PLAY_BREAK_POINT_MEM)			
#if defined(USB_SD_PLAY_INFO_DIV)
	if(device_active==0x01){
	    write_info(MEM_FILENUM_SD,((u8 *)(&given_file_number))[0] );
	    write_info(MEM_FILENUM_SD+1,((u8 *)(&given_file_number))[1]);
	}
	else if(device_active==0x02){
	    write_info(MEM_FILENUM_USB,((u8 *)(&given_file_number))[0] );
	    write_info(MEM_FILENUM_USB+1,((u8 *)(&given_file_number))[1]);	
	}
#else	
    write_info(MEM_FILENUM,((u8 *)(&given_file_number))[0] );
    write_info(MEM_FILENUM+1,((u8 *)(&given_file_number))[1]);
#endif	
#endif	

#if defined(TURN_ON_PLAY_BREAK_POINT_MEM)
//breakpoint
	load_playpoint();
	write_playpoint_info(device_active);
    update_playpoint(&playpoint_time);		//半秒更新断点进度，不写入存储器
	write_dev_playtime(device_active);			 //更新断点信息
       playpoint_filenum = 0;
//breakpoint
#endif

    flush_low_msg();
    play_status = MUSIC_PLAY;
    decode_cmd = 0;
    decode_user_exit(0);				  //非正常歌曲可通过按键强行停止解码,每次播放前必须清除	
    enable_softint();
    enable_decode_isr();
    if (2 == music_type)                   //wav文件，
    {
      delay_10ms(5);
    }
    cfilenum = 0;
#if defined(TWO_PLAY_LED_IN_USE)
	 led_open_enable = 0;
#endif	
#if defined(K202_WEISI_KL202_V00100000000000)
    set_led_enable_bit(1);
#endif
    set_play_flash(LED_FLASH_ON);

    Mute_Ext_PA(UNMUTE);//zdy add
 #if defined(USE_SPECTRUM_PARTTERN)		  
    set_lcd_flash_lock(UNLOCK);    
 #endif
#if defined(SPECTRUM_FUNC_ENABLE)
    set_spectrum_lock(UNLOCK);
#endif		  

//    printf("play\n");
    return 1;
}
#ifdef DECODE_STOP_MODE_ENABLE
u8 decode_in_stop_state()
{
    	u8 key,sys_mod_temp=0,half_sec_cnt=0;

#if defined(SPECTRUM_FUNC_ENABLE)
	set_spectrum_lock(UNLOCK);
#endif		  
	sys_mod_temp = work_mode;
	stop_decode();
#ifdef K000_HG_898_V001	
    	play_status = MUSIC_PLAY;
	clear_super_mute_lock();
#endif	
#if defined(STOP_MODE_SHOW_STOP)
	Disp_Con(DISP_STOP);		
#else
	Disp_Con(DISP_FILENUM);		
#endif

       set_play_flash(LED_FLASH_ON);
	while(1){
		
        	key = get_msg();
		switch(key)
		{
#ifdef STOP_KEY_FOR_REPLAY_FROM_START
        		case INFO_STOP| KEY_SHORT_UP :
#endif
        		case INFO_PLAY | KEY_SHORT_UP :
#ifdef STOP_REPLAY_FROM_FIRST_FILE
				given_file_number =1;
#endif
				put_msg_lifo(INIT_PLAY);
				return INIT_PLAY;				
			break;
		    	case MSG_USB_DISK_OUT:
				if(work_mode ==SYS_MP3DECODE_USB)
					return 0x66;
				else
					break;
		    	case MSG_SDMMC_OUT:
				if(work_mode ==SYS_MP3DECODE_SD)
					return 0x66;
				else
					break;			
#ifdef NEXT_PREV_REPLAY_IN_STOP_DECODE_MODE
	        	case INFO_NEXT_FIL | KEY_SHORT_UP:
				IR_KEY_Detect =0;
	            		get_music_file1(GET_NEXT_FILE);
				Disp_Con(DISP_FILENUM);		
				return INIT_PLAY; 				
		            	break;
					
	        	case INFO_PREV_FIL | KEY_SHORT_UP:
				IR_KEY_Detect =0;
	            		get_music_file1(GET_PREV_FILE);
				Disp_Con(DISP_FILENUM);
				return INIT_PLAY; 
		            	break;	
#endif		
			case INFO_HALF_SECOND :

#ifdef USE_USB_HOTPLUG_FUNC
				usb_hotplug_hdlr();
#endif
#ifdef DISP_BACKLIGHT_AUTO_SAVE_POWER
	 			Disp_BL_time_out();
#endif
				
				if(half_sec_cnt++>3){
					half_sec_cnt = 0;
#if defined(STOP_MODE_SHOW_STOP)
				Disp_Con(DISP_STOP);		
#else					
				Disp_Con(DISP_FILENUM);		
#endif
				}
				
			break;
			default:
				if(((key&KEY_HOLD)>0)&&(key!=0xff))half_sec_cnt=0;
       	     		if (!ap_handle_hotkey(key))
                		break; 
		}
		if(sys_mod_temp !=work_mode){
			return 0x66;
		}
	}
}
#endif

#ifdef PLAY_MODE_USE_INTRO_MODE
bool intro_play_enable=0;
xd_u8 intro_play_timer=0;
void init_intro_play_mode(void)
{
	intro_play_enable=~intro_play_enable;
	stop_decode();
	set_play_flash(LED_FLASH_ON);		

	given_file_number =1;
	intro_play_timer=0;
	play_mode = REPEAT_DEV_ALL;
	put_msg_lifo(INIT_PLAY);		
}
void intro_play_stop(void)
{
	if(intro_play_enable){
		stop_decode();
		set_play_flash(LED_FLASH_ON);		
		intro_play_enable=0;
		put_msg_lifo(INIT_PLAY);			
	}

}
void intro_play_hdlr(void)
{
	if(intro_play_enable){

		set_play_flash(LED_FLASH_VERY_FAST);		
		if(intro_play_timer++>20){
			intro_play_timer=0;
            		get_music_file1(GET_NEXT_FILE);
		}
	}
}
#endif
/*----------------------------------------------------------------------------*/
/**@brief  解码播放主循环,并处理信息
   @param  无
   @return 无
   @note   void music_play(void)
*/
/*----------------------------------------------------------------------------*/
/* for get ir user code
extern u16 debug_ir;
*/
#if defined(KPL_MSG_COMPATIBLE)
#include "kpl_msg.h"
#endif

void music_play(void)
{
    u8 key;
    u8 file_end_time;
    static u8 cnt_rt=0;
#ifdef USE_SYS_MODE_RECOVER
    if((get_device_online_status()&0x03)==0){

		Set_Curr_Func(SYS_FMREV);		
		return;
    }
#endif	
    while (1)
    {
        key = get_msg();

#if defined(KEY_PRESS_LED_INDICATOR)
		key_press_led_indicator(key);
#elif defined(CUSTOM_KEY_FEATURE_USE)
		custom_key_hdlr(key);
#endif


#if defined(KPL_MSG_COMPATIBLE)
	kpl_msg_hdlr(key);
#endif

#if 0
	if(key!=0xff&&key!=0x1f)
	printf(" music_play get_msg %x \r\n",(u16)key);
#endif
        switch (key)
        {
        case INIT_PLAY:                                 //开始解码播放
            file_end_time = 0;
            stop_decode();
			
#ifdef USB_SD_PWR_UP_AND_PLUG_NOT_PLAY
		if(dev_first_plugged_flag){
			dev_first_plugged_flag=0;
		   	play_status = MUSIC_STOP;  

#if defined(PLAY_STATUS_LED_PLAY_NO_SPARK)
	  		set_play_flash(LED_FLASH_ON);
#endif
			flush_all_msg();
			break;
		}
#endif

#if defined(TURN_ON_PLAY_BREAK_POINT_MEM)
	     playpoint_flag = 0;
            if(playpoint_filenum)
	     {
		    playpoint_flag = 1;
		    given_file_number = playpoint_filenum;
	     }
#endif

#ifdef DEVICE_ON_LINE_LED_IND

	//printf(" music_play last_plug_dev %x \r\n",(u16)last_plug_dev);
	//printf(" music_play given_device %x \r\n",(u16)device_active);

		if((get_device_online_status()&0x03)==0){

	  		set_play_flash(LED_FLASH_STOP);

			flush_all_msg();
			break;
		}
		else{

			if((device_active==BIT(SDMMC))){

				if((get_device_online_status()&0x01)==0){

#ifdef USB_SD_DEV_PLUG_MEM
					if((get_device_online_status()&0x02)>0){
				 		last_plug_dev=0;
					}
#endif
					set_play_flash(LED_FLASH_STOP);
					flush_all_msg();
					break;
				}

			}
			
			if((device_active==BIT(USB_DISK))){

				if((get_device_online_status()&0x02)==0){

#ifdef USB_SD_DEV_PLUG_MEM
					if((get_device_online_status()&0x01)>0){
				 		last_plug_dev=0;
					}
#endif
					set_play_flash(LED_FLASH_STOP);
					flush_all_msg();
					break;
				}

			}
		}
#endif		

#if FILE_ENCRYPTION
            password_start(0);
#endif


            if (!fs_getfile_bynumber(given_file_number))
            {
                //printf("err next file\n");
                put_msg_lifo(INFO_NEXT_FIL | KEY_SHORT_UP);
                break;
            }
            //printf("decode\n");
            if (!start_decode())
            {
                //printf("decode err\n");
                put_msg_lifo(INFO_NEXT_FIL | KEY_SHORT_UP);
            }
#if defined(USE_LONG_PLAY_KEY_TO_RESET_SONG_NUM)
		reset_key_cnt=0;
#endif
#if defined(DEFAULT_GO_TO_CUSTOM_MODE)
	if(custom_first_time_pwr_flag){
#ifdef DEVICE_SEL_MANUAL_ONLY
    		device_selected=device_active;
#endif			
		custom_first_time_pwr_flag=0;
	}
#endif

#ifdef DEVICE_SEL_MANUAL_ONLY

		  //printf(" device_selected %x--- device_active %x \r\n",(u16)device_selected,(u16)device_active);

	    	    if(device_selected!=device_active){
		  		set_play_flash(LED_FLASH_ON);	
				stop_decode();
				break;
				//Set_Curr_Func(SYS_IDLE);
				//return;
		    }
#endif						

	       my_main_vol(my_music_vol);	
		 
		Mute_Ext_PA(UNMUTE);//zdy 0320 set mute  after music play
		if(device_active ==0x01)
			Set_Curr_Func(SYS_MP3DECODE_SD);		
		else if(device_active ==0x02)
			Set_Curr_Func(SYS_MP3DECODE_USB);

#if defined(PLAY_STATUS_LED_IN_SLOW_MODE)
	  	set_play_flash(LED_FLASH_SLOW);
#elif defined(PLAY_STATUS_LED_PLAY_NO_SPARK)
	  	set_play_flash(LED_FLASH_ON);
#else
		set_play_flash(LED_FLASH_NOR);
#endif

#ifdef CUSTOMIED_LED_GPIO_CTRL
		gpio_ctrl_if(1);
#endif
#if defined(LED_RUN_FAST_WHEN_PLAY_MODE_AT_REP_ONE)	
		if(play_mode == REPEAT_ONE)
		  	set_play_flash(LED_FLASH_FAST);
#elif defined(LED_RUN_SLOW_WHEN_PLAY_MODE_AT_REP_ONE)
		if(play_mode == REPEAT_ONE)
		  	set_play_flash(LED_FLASH_SLOW);
#elif defined(LED_RUN_SLOW_WHEN_PLAY_MODE_AT_REP_ONE_ONLY)
		if(play_mode == REPEAT_DEV_ALL)
		  set_play_flash(LED_FLASH_ON);
		else
		  set_play_flash(LED_FLASH_NOR);		
#endif		
            break;

        case SEL_GIVEN_DEVICE_GIVEN_FILE:              ///<获取指定设备的指定文件
            get_music_file2();
#ifdef MUSIC_STANDBY_AT_POWER_ON
	if(get_pwr_on_rsp()){
	    flush_all_msg();
           put_msg_lifo(INFO_STOP|KEY_SHORT_UP);	    
	}
#endif
            break;

        case INFO_NEXT_FIL | KEY_SHORT_UP:
		IR_KEY_Detect =0;
#if defined(NEW_VOLUME_KEY_FEATURE)
		if(new_vol_feature){
			break;
		}
#endif

#ifdef MP3_SELECT_SONG_WHILE_PLAY
		if(select_file_timer>0){

			select_file_timer=30;
			cfilenum++;		
			if(cfilenum>fs_msg.fileTotal){
				cfilenum=1;
			}
			Disp_Con(DISP_DWORD_NUMBER);
			break;
		}			
#endif

#ifdef NEXT_PREV_KEY_NO_RSP_WHEN_REP_ONE
		if(play_mode == REPEAT_ONE){
			break;
		}
#elif defined(NEXT_PREV_KEY_RESTART_WHEN_REP_ONE)
		if(play_mode == REPEAT_ONE){
			stop_decode();
                	put_msg_lifo(INIT_PLAY);
			break;
		}		
#endif

#ifdef MUTE_EXAMP_AT_NEXT_PREV
		Mute_Ext_PA(MUTE);
#endif
            get_music_file1(GET_NEXT_FILE);
#if defined(MUTE_ON_FLASH_WHOLE_SCREEN)
#if 1//defined(MP3_PUASE_FLASH_FIGURE)
	     if(get_super_mute_lock()){
			clear_super_mute_lock();
	      }
#endif
#endif
            break;

        case INFO_PREV_FIL | KEY_SHORT_UP:
		IR_KEY_Detect =0;
#if defined(NEW_VOLUME_KEY_FEATURE)
		if(new_vol_feature){
			break;
		}
#endif

#ifdef MP3_SELECT_SONG_WHILE_PLAY
		if(select_file_timer>0){

			select_file_timer=30;

			cfilenum--;		
			if(cfilenum==0){
				cfilenum=fs_msg.fileTotal;
			}

			Disp_Con(DISP_DWORD_NUMBER);
			break;		
		}			
#endif

#ifdef PREV_KEY_SKIP_SONG_DELAY
		if(prev_skip_timer){
			put_msg_lifo(INIT_PLAY);			
			prev_skip_timer=0;
			break;
		}
#endif


#ifdef NEXT_PREV_KEY_NO_RSP_WHEN_REP_ONE
		if(play_mode == REPEAT_ONE){
			break;
		}
#elif defined(NEXT_PREV_KEY_RESTART_WHEN_REP_ONE)
		if(play_mode == REPEAT_ONE){
			stop_decode();
                	put_msg_lifo(INIT_PLAY);
			break;
		}
#endif

#ifdef MUTE_EXAMP_AT_NEXT_PREV
		Mute_Ext_PA(MUTE);
#endif
            get_music_file1(GET_PREV_FILE);
#if defined(MUTE_ON_FLASH_WHOLE_SCREEN)
#if 1//defined(MP3_PUASE_FLASH_FIGURE)
	     if(get_super_mute_lock()){
			clear_super_mute_lock();
	      }
#endif
#endif
            break;

#ifdef IR_NEXT_PREV_KEY_LONG_SEL_DIR
        case INFO_NEXT_FIL | KEY_LONG:
		if(IR_KEY_Detect){			
			select_folder_file(FIND_NEXT_DIR);
		}
		break;
        case INFO_PREV_FIL | KEY_LONG:
		if(IR_KEY_Detect){			
			select_folder_file(FIND_PREV_DIR);			
		}
		break;
#endif

#ifdef ADKEY_NEXT_PREV_LONG_SEL_FOLDER		
        case INFO_NEXT_FIL | KEY_LONG:
		select_folder_file(FIND_NEXT_DIR);
		break;
        case INFO_PREV_FIL | KEY_LONG:
		select_folder_file(FIND_PREV_DIR);	
		break;
#endif

#ifdef ADKEY_NEXT_PREV_15_SONG	
        case INFO_PLUS | KEY_SHORT_UP:

		if((given_file_number+15)<fs_msg.fileTotal){
			given_file_number=given_file_number+15;
			stop_decode();
                	put_msg_lifo(INIT_PLAY);			
		}

		break;
        case INFO_MINUS | KEY_SHORT_UP:

		if((given_file_number>15)){
			given_file_number=given_file_number-15;
			stop_decode();
                	put_msg_lifo(INIT_PLAY);			
		}		
		break;
#endif


#if defined(K015_983_SW005_ZhuoXin_FB001_V001)
        case INFO_PLUS |KEY_SHORT_UP:
        case INFO_PLUS | KEY_HOLD:
           //printf("INFO_PLUS\n");			
#elif defined(SEPARATED_FAST_FORDWORD_KEY)          
        case INFO_PLUS |KEY_SHORT_UP:
        case INFO_PLUS | KEY_HOLD:
#else			
        case INFO_NEXT_FIL | KEY_HOLD:
#endif

#if defined(INDEPENDENT_VOLUME_KEY)

#if defined(NEXT_PREV_HOLD_SEL_FILE)	
            get_music_file1(GET_NEXT_FILE);
		break;
#elif defined(NEXT_PREV_HOLD_DO_NOTHING)		  
		break;
#endif		
	     IR_KEY_Detect =0;
#if 1
	set_fast_play_cmd(1);
#else
            main_vol(0);							///<快进快退过程中，关闭主音量				
            decode_cmd = 0xf0;
#endif

            break;
#elif defined(NEXT_PREV_HOLD_DO_NOTHING)		  
		break;
#elif defined(NEXT_PREV_HOLD_SEL_FILE)	
            get_music_file1(GET_NEXT_FILE);
		break;
		
#elif defined(NEXT_PREV_HOLD_USE_VOL_TUNE)

			IR_KEY_Detect =0;
			goto __hot_key;
			break;
			
#else

#if defined(IR_NEXT_PREV_KEY_HOLD_TUNE_VOL)
		IR_KEY_Detect =0;
		goto __hot_key;
#endif

		if(IR_KEY_Detect){
			//IR_KEY_Detect =0;
#ifdef IR_NEXT_PREV_KEY_HOLD_DO_NOTHING
			
#else			
			set_fast_play_cmd(1);
            		//main_vol(0);							///<快进快退过程中，关闭主音量				
            		//decode_cmd = 0xf0;
#endif					
            		break;
		}
		else{

#if defined(NEXT_PREV_HOLD_FOR_MUSIC_FFR)
			set_fast_play_cmd(1);
			break;
#else			
			IR_KEY_Detect =0;
			goto __hot_key;
#endif			
		}

		
#endif

#if defined(K015_983_SW005_ZhuoXin_FB001_V001)
        case INFO_MINUS|KEY_SHORT_UP:
        case INFO_MINUS| KEY_HOLD:
          // printf("INFO_MINUS\n");
#elif defined(SEPARATED_FAST_FORDWORD_KEY)
        case INFO_MINUS|KEY_SHORT_UP:
        case INFO_MINUS | KEY_HOLD:          
#else
        case INFO_PREV_FIL | KEY_HOLD:
#endif

#if defined(INDEPENDENT_VOLUME_KEY)

#if defined(NEXT_PREV_HOLD_SEL_FILE)

#ifdef PREV_KEY_SKIP_SONG_DELAY
		if(prev_skip_timer){
			put_msg_lifo(INIT_PLAY);
			prev_skip_timer=0;
			break;
		}
#endif
            get_music_file1(GET_PREV_FILE);
		break;
#elif defined(NEXT_PREV_HOLD_DO_NOTHING)		  
		break;		
#endif		

	      IR_KEY_Detect = 0;
#if 1
		set_fast_play_cmd(2);
#else
	      main_vol(0);							///<快进快退过程中，关闭主音量			
             decode_cmd = 0xf1;
#endif			 
	      break;
#elif defined(NEXT_PREV_HOLD_DO_NOTHING)		  
		break;
#elif defined(NEXT_PREV_HOLD_SEL_FILE)	

#ifdef PREV_KEY_SKIP_SONG_DELAY
		if(prev_skip_timer){
			put_msg_lifo(INIT_PLAY);			
			prev_skip_timer=0;
			break;
		}
#endif

            get_music_file1(GET_PREV_FILE);
		break;
#elif defined(NEXT_PREV_HOLD_USE_VOL_TUNE)
			IR_KEY_Detect =0;
			goto __hot_key;
			break;			
#else

#if defined(IR_NEXT_PREV_KEY_HOLD_TUNE_VOL)
		IR_KEY_Detect =0;
		goto __hot_key;
#endif

		if(IR_KEY_Detect){
			//IR_KEY_Detect =0;
#ifdef IR_NEXT_PREV_KEY_HOLD_DO_NOTHING
			
#else	
			set_fast_play_cmd(2);
            		//main_vol(0);							///<快进快退过程中，关闭主音量			
            		//decode_cmd = 0xf1;
#endif					
			break;				
		}
		else{			

#if defined(NEXT_PREV_HOLD_FOR_MUSIC_FFR)
			set_fast_play_cmd(2);
			break;
#else
			IR_KEY_Detect =0;
			goto __hot_key;
#endif			
		}
#endif
        case DECODE_MSG_DISK_ERR:
            //printf("device err-----------------------------\n");
            get_music_file3();
            break;

        case DECODE_MSG_FILE_END:               ////*将文件结束的消息放到半秒消息中处理，防止单曲循环遇到错误歌曲无法手动切换下一首,或遇到错误歌曲无法到上一首,每首歌曲至少播放约5S*/
            //printf("end\n");
#ifdef CUSTOMIED_LED_GPIO_CTRL
		gpio_ctrl_if(0);
		stop_decode();
#elif defined(CUSTOM_WAIT_FOR_MCU_CMD_FOR_NEXT_MUSIC)		
		stop_decode();
		break;
#elif defined(CUSTOM_WAIT_FOR_MCU_CMD_FOR_NEXT_MUSIC_HOLD_IN_STOP_MODE)
	if(get_pwr_on_rsp()){
	    flush_all_msg();
           put_msg_lifo(INFO_STOP|KEY_SHORT_UP);	    
	}
	
#endif   

#ifndef REP_ONE_SELECT_SONG_IMPROVE
	     if (get_music_play_time() < 3)
                file_end_time = 4 -  (u8)get_music_play_time();
            else
#endif				
                get_music_file1(GET_PLAY_FILE);
            break;

        case INFO_NEXTMODE:                     ///<下一个模式	


#ifdef DEFAULT_GO_TO_AUX
		work_mode = SYS_AUX;
#elif defined(DEFAULT_HOLD_IN_DECODE_MODE)			
	  		set_play_flash(LED_FLASH_ON);	
			break;
#elif defined(DEFAULT_GO_TO_CUSTOM_MODE)
		if(custom_first_time_pwr_flag){
			custom_first_time_pwr_flag=0;
#if defined(DEFAULT_GO_TO_CUSTOM_MODE_POWER_ON_FIRST_TIME_IN_AUX)
			Set_Curr_Func(SYS_AUX);
#elif defined(DEFAULT_GO_TO_CUSTOM_MODE_POWER_ON_FIRST_TIME_IN_RTC_MODE)
			Set_Curr_Func(SYS_RTC);
#else
			Set_Curr_Func(SYS_IDLE);
#endif
		}
		else{
#if defined(DEFAULT_GO_TO_CUSTOM_MODE_POWER_ON_AFTER_TIME_IN_IDLE)
	  		set_play_flash(LED_FLASH_ON);	
			break;
#else			
			Set_Curr_Func(SYS_FMREV);
#endif
		}
#elif defined(DEFAULT_GO_TO_TIME_MODE)
		Set_Curr_Func(SYS_RTC);
#elif defined(DEFAULT_GO_TO_FM)
		if(IR_Type == WITH_FM_CHIP)
			work_mode = SYS_FMREV;
		else
			work_mode = SYS_AUX;
#elif defined(DEFAULT_GO_HOLD_IN_DECODE_MODE)		
		break;
#elif defined(DEFAULT_GO_TO_IDLE)		
		Set_Curr_Func(SYS_IDLE);
#else
		work_mode = Next_Func();
#endif

#ifdef GPIO_SWITCH_SELECT_MODE
		work_mode = SYS_AUX;
		return;
#endif

#if defined( K186_LM_186_V001)||defined(K000_Zhongwei_SP_016_V001)
		work_mode = SYS_IDLE;
#endif
		//printf("  INFO_NEXTMODE %d \r\n",(u16)work_mode);
		if(work_mode==SYS_IDLE){
			put_msg_lifo(INFO_NO_DEV);
		}

#if defined(USE_SPECTRUM_PARTTERN)		  		
		set_lcd_flash_lock(UNLOCK);
#endif

            return;
#ifdef POWE_KEY_PLAY_KEY_IN_ONE_KEY
    case INFO_POWER | KEY_SHORT_UP :	
#endif
#ifdef USE_IR_POWER_KEY_TO_POWER_OFF
		if(IR_KEY_Detect){
			IR_KEY_Detect =0;
			goto __hot_key;	
		}
#endif
        case INFO_PLAY | KEY_SHORT_UP :
			
#ifdef PLAY_KEY_USE_FOR_STOP_FUNC
	    goto __PLAY_KEY_STOP;
#endif

#ifdef MP3_SELECT_SONG_WHILE_PLAY
		select_file_timer=0;
#endif			
            if (DISP_DWORD_NUMBER == curr_menu)
            {
                put_msg_fifo(INFO_PICK_SONG | KEY_SHORT_UP);
                break;
            }

            if (play_status == MUSIC_PAUSE)
            {
        	  play_status = MUSIC_PLAY;            
                //Disp_Con(DISP_PLAY);
		  //my_main_vol(my_music_vol);			  //打开主音量
                mad_control(MAD_PLAY,0);
		  if(music_type == 1)
			enable_decodeint();
		  else if(music_type == 2)
			enable_softint();
                Disp_Con(DISP_PLAY);
#if defined(LED_RUN_FAST_WHEN_PLAY_MODE_CHANGE)	
		if(play_mode == REPEAT_FOLDER){
		  set_play_flash(LED_FLASH_NOR);
		}
		else{
		  set_play_flash(LED_FLASH_FAST);
		}
#elif defined(LED_RUN_FAST_WHEN_PLAY_MODE_AT_REP_ONE)	
		if(play_mode == REPEAT_DEV_ALL)
		  set_play_flash(LED_FLASH_NOR);
		else
		  set_play_flash(LED_FLASH_FAST);
//#endif
#elif defined(LED_RUN_SLOW_WHEN_PLAY_MODE_AT_REP_ONE)
		if(play_mode == REPEAT_DEV_ALL)
		  set_play_flash(LED_FLASH_NOR);
		else
		  set_play_flash(LED_FLASH_SLOW);
#elif defined(LED_RUN_SLOW_WHEN_PLAY_MODE_AT_REP_ONE_ONLY)
		if(play_mode == REPEAT_DEV_ALL)
		  set_play_flash(LED_FLASH_ON);
		else
		  set_play_flash(LED_FLASH_NOR);		
#elif defined(PLAY_STATUS_LED_IN_SLOW_MODE)
	  	set_play_flash(LED_FLASH_SLOW);
#else			
		  set_play_flash(LED_FLASH_NOR);
#endif

#if defined(SPECTRUM_FUNC_ENABLE)
		 set_spectrum_lock(UNLOCK);
#endif

#ifdef CUSTOMIED_LED_GPIO_CTRL
		gpio_ctrl_if(1);
#endif            

  		  Mute_Ext_PA(UNMUTE);

#if defined(USE_SPECTRUM_PARTTERN)		  
		  set_lcd_flash_lock(UNLOCK);
#endif
            }
            else if (play_status == MUSIC_PLAY)
            {
		   play_status = MUSIC_PAUSE;            
                if(music_type == 1)
			disable_decodeint();
                //Disp_Con(DISP_PAUSE);
		  //main_vol(0);					  //关闭主音量
                mad_control(MAD_PAUSE,0);
                read_usb_remain_data();

#if defined(TURN_ON_PLAY_BREAK_POINT_MEM)			
		  write_playtime(&playpoint_time);	   	//暂停时记忆断点信息（EEPROM）
#endif				
                Disp_Con(DISP_PAUSE);
		  set_play_flash(LED_FLASH_ON);	
#ifndef NO_MUTE_WHEN_PAUSE		  
		  Mute_Ext_PA(MUTE);
#endif
#if defined(USE_SPECTRUM_PARTTERN)		  		  
		  set_lcd_flash_lock(LOCK);
#endif
#ifdef CUSTOMIED_LED_GPIO_CTRL
		gpio_ctrl_if(0);
#endif            

#if defined(SPECTRUM_FUNC_ENABLE)
		 set_spectrum_lock(LOCK);
#endif		  
            }
            else if (play_status == MUSIC_STOP){

		if((get_device_online_status()&0x03)==0)break;

#ifdef DEVICE_ON_LINE_LED_IND
		if((get_device_online_status()&0x03)==0x03){

			if(last_plug_dev ==0){

				if(given_device==BIT(SDMMC)){

					given_file_number =1;

				}
				else{
					given_file_number =1;
				}
			}
			else{
				
				if(last_plug_dev!=BIT(SDMMC)){
					given_file_number =1;
		        		given_device = BIT(SDMMC);

				}
				else{
					given_file_number =1;
		        		given_device = BIT(USB_DISK);

				}
			}
			 // printf(" last_plug_dev %x--- device_active %x \r\n",(u16)last_plug_dev,(u16)device_active);

	            	put_msg_lifo(SEL_GIVEN_DEVICE_GIVEN_FILE);
			break;
		}
		else{

				if((get_device_online_status()&0x01)>0){

					given_file_number =1;
	        			given_device = BIT(SDMMC);
	       		     	put_msg_lifo(SEL_GIVEN_DEVICE_GIVEN_FILE);
					break;						
					
				}

				if((get_device_online_status()&0x02)>0){

					given_file_number =1;
	        			given_device = BIT(USB_DISK);
	       		     	put_msg_lifo(SEL_GIVEN_DEVICE_GIVEN_FILE);
					break;		
				}

		}
#endif
			
                	put_msg_lifo(INIT_PLAY);

	     }
#if 1//ined(MUTE_ON_FLASH_WHOLE_SCREEN)
#if defined(MP3_PUASE_FLASH_FIGURE)||defined(PAUSE_FLASH_WHOLE_SCREEN)

#ifdef NO_FLASH_MP3_SCREEN
		set_led_flash_tpye(0);
		break;
#endif
            if (play_status == MUSIC_PAUSE)
			set_led_flash_tpye(2);
	     else{
			set_led_flash_tpye(0);
			if(get_super_mute_lock()){
				set_led_flash_tpye(1);
			       Disp_Con(DISP_VOL);
			}
	     }
#endif
#endif
//            printf("play\n");
            break;

        case INFO_PICK_SONG | KEY_SHORT_UP :
            given_file_number = (u16)cfilenum;
            cfilenum = 0;
//            printf(" given_file_number : %5u \n" ,given_file_number);
            if ((given_file_number > 0) && (given_file_number <= fs_msg.fileTotal))
            {
                put_msg_lifo(INIT_PLAY);
                break;
            }
            Disp_Con(DISP_ERROR);
            break;

        case INFO_DISP_FILENAME:
            if (DISP_PLAY == curr_menu)
            {
                //Disp_Con(DISP_FILE_NAME);
               // draw_lcd(2, 4);
            }
            break;

        case INFO_HALF_SECOND :
#if ((USE_DEVICE == MEMORY_STYLE)&&(FAT_MEMORY))      
            updata_fat_memory();
#endif
			
#if defined(TURN_ON_PLAY_BREAK_POINT_MEM)			
		update_playpoint(&playpoint_time);		//半秒更新断点进度，不写入存储器
#endif
#ifdef DISP_BACKLIGHT_AUTO_SAVE_POWER
	 	Disp_BL_time_out();
#endif

#ifdef VOL_ADJ_SPARK_LED
		if(vol_adj_spark_bit){
			vol_adj_spark_bit=0;
			restore_led_flash_mod(last_led_play_mod);		
		}
#endif	 

#ifdef PLAY_MODE_USE_INTRO_MODE
		intro_play_hdlr();
#endif
            if (file_end_time)
            {

#ifdef CUSTOMIED_LED_GPIO_CTRL
		gpio_ctrl_if(0);
		stop_decode();
		break;
#endif            
                file_end_time--;
                if(file_end_time == 0)
                    get_music_file1(GET_PLAY_FILE);
            }
#if defined(FF_FR_TURN_ON_MUSIC)	   ///在每一次快进完成之后，播出半秒左右的声音
		if ((2 == decode_cmd)&&(play_status == MUSIC_FF_FR))
		{
			decode_cmd = 0;				
			set_eq(eq_mode);
			play_status = MUSIC_PLAY;
		       my_main_vol(my_music_vol);			  //打开主音量			
      		       IR_KEY_Detect =0;				
		}
#else
            if ((decode_cmd != 0) && (decode_cmd <= 2))		///<快进快退结束后1S，打开主音量
            {
                decode_cmd--;
		  set_eq(eq_mode);
                if (decode_cmd == 0){
		  {
			play_status = MUSIC_PLAY;
		   }
 		      IR_KEY_Detect =0;				
		      my_main_vol(my_music_vol);			  //打开主音量					
  		      Mute_Ext_PA(UNMUTE);
                }		
            }
#endif

#ifdef USE_USB_HOTPLUG_FUNC
		usb_hotplug_hdlr();
#endif

#ifdef MP3_SELECT_SONG_WHILE_PLAY
		if(select_file_timer>0){
			
			select_file_timer--;
			if(select_file_timer ==0){

		                if (DISP_DWORD_NUMBER == curr_menu)
		                {
               	              //    Disp_Con(DISP_PLAY);
		                    //put_msg_fifo(INFO_PICK_SONG | KEY_SHORT_UP);
		                }
			}
			else{
				
				break;

			}
		}
#endif			

#if defined(TIME_FORCE_SHOW_ON_SCREEN)

            if ((DISP_PLAY == curr_menu)||(DISP_PAUSE== curr_menu)){

	            if (time_show_return_cnt>RETURN_TIME_SHOW_TIME){
	                    get_curr_date();
	                    Disp_Con(DISP_RTC_POINT);
				break;
		    }	
		     else{
#if defined(MANUAL_SWITCH_TIME_DISPLAY)
	                    Disp_Con(DISP_PLAY);
#else		 	
	                if(DISP_RTC != curr_menu){
				time_show_return_cnt++;
	                }
#endif		 
					
		     }
	     }
#endif		
            if (DISP_FILENUM == curr_menu)
            {
            		if(cnt_rt++>1){
			Disp_Con(DISP_PLAY);
			cnt_rt =0;
            		}
	     }
			
#if defined(PLAY_ICON_FLASH)
	     if(DISP_PAUSE== curr_menu)
	     {
			disp_play_icon_flash();
	     }
#endif
            if (DISP_PLAY == curr_menu)
            {

#ifdef PREV_KEY_SKIP_SONG_DELAY
		   prev_skip_timer=1;
#endif            
                 disp_file_time();
              //  draw_lcd(0, 1);
            }
#if defined(USE_BAT_MANAGEMENT)
		bmt_hdlr();
#endif
            return_cnt++;

            if (RETURN_TIME == return_cnt)
            {
#ifdef SUPPORT_PT2313
		  clr_aud_effect_state();
#endif            

                if (DISP_DWORD_NUMBER == curr_menu)
                {
                    put_msg_fifo(INFO_PICK_SONG | KEY_SHORT_UP);
                }
                else
                {
                    if (!play_status)
                    {
                        if (curr_menu != DISP_PAUSE)
                            Disp_Con(DISP_PAUSE);
                    }
                    else
                    {
                        if (curr_menu != DISP_PLAY)
                            Disp_Con(DISP_PLAY);
                    }
                }
#if defined(NEW_VOLUME_KEY_FEATURE)||defined(VOL_TUNE_NEW_VOLUME_KEY_FEATURE)
		if(new_vol_feature){
			new_vol_feature =0;
			if(last_disp_menu!=DISP_NULL)
                     Disp_Con(last_disp_menu);
		}
#endif				
            }

#if defined(TURN_ON_PLAY_BREAK_POINT_MEM)			
#if 1//USE_RTC_RAM
			save_playpoint(2);	   	//2*0.5 = 1s 1s记录一次播放进度,
#endif
#endif

#if defined(AD_MEASURE_TEMP_FUNC)
	adc_diode_temp_measure_hdlr();
#endif

	     Disp_Update();
#if defined(SYS_GO_IN_IDLE_IN_30_SEC)
	if(sys_timer_idle_hdlr())return;
#endif
            break;

#if 0// defined(USE_FOLDER_SELECT_FUNC)
        case INFO_EQ_UP|KEY_SHORT_UP:
			select_folder_file(FIND_NEXT_DIR);
			break;
#endif


#if defined(CUSTOMIZED_EQ_MODE)
        case INFO_REP_ONE|KEY_SHORT_UP:
               play_mode = REPEAT_ONE;
            	write_info(MEM_PLAY_MODE,play_mode);
            	Disp_Con(DISP_PLAYMODE);	
				
		break;

        case INFO_REP_ALL|KEY_SHORT_UP:
#if defined(PLAY_MODE_REPEAT_ALL)
                play_mode = REPEAT_ALL;
#else    
	    	 play_mode =REPEAT_DEV_ALL;
#endif    
            	write_info(MEM_PLAY_MODE,play_mode);
            	Disp_Con(DISP_PLAYMODE);		

		break;
        case INFO_REP_CHANGE|KEY_SHORT_UP:

            	write_info(MEM_PLAY_MODE,play_mode);
            	Disp_Con(DISP_PLAYMODE);		

		break;		
#endif

#if defined(USE_LONG_MODE_KEY_PLAY_MODE)
        case INFO_MODE | KEY_LONG :
#elif defined(USE_LONG_EQ_KEY_PLAY_MODE)
        case INFO_EQ_UP| KEY_LONG :
#elif defined(USE_LONG_PLAY_KEY_PLAY_MODE)
        case INFO_PLAY | KEY_LONG :
		if(IR_KEY_Detect){
			IR_KEY_Detect=0;
			break;
		}
#endif			
        case INFO_PLAY_MODE :

#if defined(PLAY_MODE_USE_REP_ONE_ALL)
            if(play_mode == 0){
	    	 	play_mode =REPEAT_ONE;
	     }
	     else {
#if defined(PLAY_MODE_REPEAT_ALL)
                play_mode = REPEAT_ALL;
#else    
	    	 play_mode =REPEAT_DEV_ALL;
#endif    
	     }
#if defined(LED_RUN_FAST_WHEN_PLAY_MODE_AT_REP_ONE)	
		if(play_mode == REPEAT_DEV_ALL)
		  set_play_flash(LED_FLASH_NOR);
		else
		  set_play_flash(LED_FLASH_FAST);
#elif defined(LED_RUN_SLOW_WHEN_PLAY_MODE_AT_REP_ONE)
		if(play_mode == REPEAT_DEV_ALL)
		  set_play_flash(LED_FLASH_NOR);
		else
		  set_play_flash(LED_FLASH_SLOW);
#elif defined(LED_RUN_SLOW_WHEN_PLAY_MODE_AT_REP_ONE_ONLY)
		if(play_mode == REPEAT_DEV_ALL)
		  set_play_flash(LED_FLASH_ON);
		else
		  set_play_flash(LED_FLASH_NOR);		
#endif

#elif defined(PALY_MODE_USE_RAN_ALL)

            if(play_mode == 0){
	    	 	play_mode =REPEAT_RANDOM;
	     }
	     else {
		 	
#if defined(PLAY_MODE_REPEAT_ALL)
                play_mode = REPEAT_ALL;
#else    
	    	 play_mode =REPEAT_DEV_ALL;
#endif  


	     }	

#elif defined(PALY_MODE_USE_RAN_ONE_ALL)

            if(play_mode == 0){
	    	 	play_mode =REPEAT_ONE;
	     }
	     else if(play_mode == REPEAT_ONE){
	    	 	play_mode =REPEAT_RANDOM;
	     }
	     else {
		 	
#if defined(PLAY_MODE_REPEAT_ALL)
                play_mode = REPEAT_ALL;
#else    
	    	 play_mode =REPEAT_DEV_ALL;
#endif  
	     }	
#else



            play_mode++;

#if defined(LED_RUN_FAST_WHEN_PLAY_MODE_CHANGE)	
		if(play_mode == REPEAT_FOLDER)
		  set_play_flash(LED_FLASH_NOR);
		else
		  set_play_flash(LED_FLASH_FAST);
#endif

#if defined(PALY_MODE_USE_RAN_ALL_ONE)	
		if(play_mode == REPEAT_FOLDER)
			play_mode = REPEAT_ONE;
#endif
	///		printf("0 play mode %u %u\r\n",(u16)play_mode,(u16)REPEAT_RANDOM);
            if (play_mode > REPEAT_RANDOM)
            {
#if defined(PLAY_MODE_REPEAT_ALL)
                play_mode = REPEAT_ALL;
#else    
	    	 play_mode =REPEAT_DEV_ALL;
#endif    
            }
#endif    
#ifdef PLAY_MODE_USE_INTRO_MODE
	     intro_play_stop();
#endif
            write_info(MEM_PLAY_MODE,play_mode);

#ifndef PLAY_MODE_NO_STR_DISP
            Disp_Con(DISP_PLAYMODE);
#endif
            break;

#ifdef MP3_SELECT_SONG_WHILE_PLAY
#ifdef MP3_HOT_KEY_LONG_SELECT_SONG
    	case INFO_MP3_MOD| KEY_LONG:
		if(select_file_timer==0)
		    select_file_timer=30;

		cfilenum=given_file_number;
		Disp_Con(DISP_DWORD_NUMBER);
			
	    break;	
#endif
#endif
			
#if defined(DECODE_STOP_MODE_ENABLE)
#if defined(PLAY_LONG_PRESS_STOP)
    	case INFO_PLAY| KEY_LONG:
#elif defined(MP3_HOT_KEY_LONG_PRESS_STOP)			
    	case INFO_MP3_MOD| KEY_LONG:
#else
    	case INFO_STOP | KEY_SHORT_UP :
#endif			
#ifdef PLAY_KEY_USE_FOR_STOP_FUNC
	    __PLAY_KEY_STOP:
#endif
		key = decode_in_stop_state();
		
		if(key == INIT_PLAY){
			break;
		}
		else if(key==0x66){
			/*mode switched*/
			return;
		}
#endif
	 case INFO_NO_DEV:
	 		Disp_Con(DISP_NODEVICE);
	 		break;			
        default :
__hot_key:			
            if (!ap_handle_hotkey(key))
                return;
            if ((!play_status) && (!device_check()))
            {
            	//sys_printf("DEVICE CHECK  OUT");
                play_status = MUSIC_PLAY;
                return;
            }
        }
    }


}

/*----------------------------------------------------------------------------*/
/**@brief   播放解码模式入口
   @param   无
   @return  无
   @note    decode_play
*/
/*----------------------------------------------------------------------------*/
void decode_play(void)
{
#if defined(NEW_VOLUME_KEY_FEATURE)||defined(VOL_TUNE_NEW_VOLUME_KEY_FEATURE)
	last_disp_menu=DISP_NULL;
#endif		

#ifdef USB_SD_PWR_UP_AND_PLUG_NOT_PLAY
	dev_first_plugged_flag=1;
#endif

#if defined(MP3_DISP_LOAD_STRING)
      if((get_device_online_status()&0x03)>0)
      Disp_Con(DISP_LOAD);
#endif
    sysclock_div2(1);
    sd_speed_init(0, 50);
    decodeclock_div2(DECODE_CLK_DIV2);				//decoder分频，可以减少功耗
    PT1 = 1;										//timer1 interrupt 高优先级
    music_info_init();
    dsp_hi_pro();
    decodeint_hi_pro();
    device_active = 0;

    dac_out_select(DAC_DECODE);

#ifdef SUPPORT_PT2313
    PT2313_Config(MP3_CHAN,CHAN_ADJ);
#endif


    put_msg_lifo(SEL_GIVEN_DEVICE_GIVEN_FILE);

#ifdef CUSTOM_OUTPUT_LIMIT
    set_max_vol(MAX_ANALOG_VOL-CUSTOM_OUTPUT_VAL, MAX_DIGITAL_VOL);
#else
    set_max_vol(MAX_ANALOG_VOL, MAX_DIGITAL_VOL);			//设置Music模式的音量上限
#endif

#ifdef LED_LIGHT_ON_ENABLE_IN_IDLE_MODE
    set_play_flash(LED_FLASH_ON);
#else
#ifndef 	NO_DEV_LED_IMPROVE
    set_play_flash(LED_FLASH_NOR);
#endif
#endif


#ifdef BLUETOOTH_GPIO_CTRL
    BT_PWR_OFF();
#endif 

#ifdef ASSIGN_GIVEN_DEVICE_AT_PWR_ON
	if((get_device_online_status()&0x03)==0x03){
      		given_device = BIT(SDMMC);
 		last_plug_dev=BIT(USB_DISK);

#ifdef DEVICE_ON_LINE_LED_IND
		set_play_flash(LED_FLASH_NOR);
#endif	
	}
#endif

    music_play();
#ifdef NO_DEV_LED_IMPROVE
    set_play_flash(LED_FLASH_ON);
#else
    set_play_flash(LED_FLASH_STOP);
#endif
    stop_decode();
#if(MEMORY_STYLE != USE_DEVICE)
    usb_suspend();			//Entered Suspend mode	
#endif
#if defined(TURN_ON_PLAY_BREAK_POINT_MEM)			    
    write_playtime(&playpoint_time);				//记录断点信息（EEPROM）
#endif	
    main_vol_set(0, CHANGE_VOL_NO_MEM);

#if defined(USE_SPECTRUM_PARTTERN)		  	
    set_lcd_flash_lock(UNLOCK);
#endif

   //sys_printf("END DECODE PLAY");
}

