/*--------------------------------------------------------------------------*/
/**@file     msgfor_usb.c
   @brief    usb 从机任务模块
   @details
   @author
   @date   2011-3-7
   @note
*/
/*----------------------------------------------------------------------------*/

/* msgfor usb */
#include "Custom_config.h"
#ifndef REMOVE_USE_DEVICE_MODE
#include "msgfor_usb.h"
#include "fat_memory.h"
#include "voice_time.h"


extern xd_u8 my_music_vol;  
extern u8 _idata music_vol;  
extern u8 eq_mode;
extern xd_u8 return_cnt;
extern xd_u8 curr_menu;
extern _xdata SYS_WORK_MODE work_mode;
extern bit pc_connect;
extern void main_vol(u8 vol);
extern u16 cfilenum;
extern bool IR_KEY_Detect;
extern u8 last_work_mode;
extern void set_play_flash(u8 led_status);
#ifdef USB_AUDIO_PLAY_LED_FLASH
bool usb_audio_pp=0;
#endif

#ifdef USE_USB_HOTPLUG_FUNC
bool usb_hot_plug_protect=0;
void init_usb_hotplug(void)
{
	usb_hot_plug_protect=0;
}
void set_usb_hotplug_protect(bool protectbit)
{
	usb_hot_plug_protect=protectbit;
}
void usb_hotplug_hdlr()
{


  //  if(work_mode == SYS_MP3DECODE_USB)return;
    if(usb_hot_plug_protect)return;
	
    EA = 0;
    usb_pcin_detect();
    Delay(100);
    usb_pcin_detect();
    device_check();
    EA = 1;
	
    if(pc_connect){
	put_msg_lifo(INFO_PC_HOTPLUG);
    }
}
#elif defined(USE_PC_DC_POWER_ON_ONLY)
bool  get_usb_pc_status()
{	
    EA = 0;
    usb_pcin_detect();
    Delay(100);
    usb_pcin_detect();
    device_check();
    EA = 1;

    if(pc_connect){
	return 1;
    }
     return 0;
}
#endif

u8 const _code ufi_inquiry_str[24] =	///<UFI设备信息，必须填充24个字符
{
	'K',    //供应商信息 8个字符 -- Vender information start
    	'P',
	'L', 
	'T', 
	'K',
	' ',    //需填充空字符
    ' ',    
    ' ',    
    'M',    //产品标识 16个字符 -- Production Identification start	
    'P',    
    '3',
    ' ',
    'P',    
    'L',    
    'A',    
    'Y',    
    'E',
    'R',
    ' ',	//需填充空字符
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',    //Production Identification end	   31
};

/*----------------------------------------------------------------------------*/
/**@brief   usb hid 命令接口函数
   @param   Audio_Flag ：  hid 命令
   @return  无
   @note    void usb_hid_control(u8 Audio_Flag)
*/
/*----------------------------------------------------------------------------*/
void usb_hid_control(u8 Audio_Flag)
{
    usb_hid_key(Audio_Flag);
    usb_hid_key(0);
}
/*----------------------------------------------------------------------------*/
/**@brief   usb Audio 接口函数
   @param   无
   @return  无
   @note    void USB_Audio_Vol_set(void)
*/
/*----------------------------------------------------------------------------*/
void USB_Audio_Vol_set(void)
{
    u8 vol;
    vol = USB_Audio_Volume(1, 0); //0~255
    music_vol = vol >> 3;   	
    music_vol = (music_vol > 30) ? 30 : music_vol;
    if (vol == 0)
	{
		if (vol == 0)
			music_vol = 0;
		else
			music_vol = 1;
	}
	if (music_vol == 0)
    {
        if (usb_audio_mute_status() == 0)
		{
			Usb_Audio_Mute_Ctl();
		}
    }
    else
    {
        if (usb_audio_mute_status() == 1)
		{
            Usb_Audio_Mute_Ctl();
		}
    }
	write_info(MEM_VOL, music_vol);
		
}
/*----------------------------------------------------------------------------*/
/**@brief   usb 从机任务 主循环函数
   @param   无
   @return  无
   @note    void usb_device(void)
*/
/*----------------------------------------------------------------------------*/
void usb_device(void)
{
    u8 key;

//    printf("pc online\n");
    Disp_Con(DISP_USBDEV);
    usb_config(USB_DEVICE_CFG);
    dac_out_select(DAC_DECODE);
    write_protect_set(0);                           //不使用写保护功能,如果需要，请根据卡座写保护的状态改变配置
    USB_Audio_Volume(0, music_vol);
    init_usb_device_hardware();
    flush_low_msg();
    dac_mute_control(0, 1);
#ifdef USB_AUDIO_PLAY_LED_FLASH	
    usb_audio_pp= 0;
#endif
    music_vol =my_music_vol;
    main_vol_set(0, SET_USE_CURRENT_VOL);
#ifdef USB_AUDIO_PLAY_LED_FLASH
    set_play_flash(LED_FLASH_NOR);
#endif

	Mute_Ext_PA(UNMUTE);						

    while (1)
    {
#if ((USB_DEVICE_CFG & USB_MASS) == USB_MASS)
        UFI_massstorage();
#endif
#if ((USB_DEVICE_CFG & USB_SPEAKER) == USB_SPEAKER)
		dac_out_select(DAC_DECODE);
#endif	
        key = get_msg();

        switch (key)
        {
#ifdef USE_USB_HOTPLUG_FUNC
#if defined(USE_LONG_PLAY_KEY_TO_SWITCH_MODE)
        case INFO_PLAY | KEY_LONG :
#elif defined(USE_LONG_PLAY_MODE_KEY_TO_SWITCH_MODE)			
        case INFO_PLAY_MODE | KEY_LONG :
#elif defined(USE_POWER_KEY_TO_SWITCH_MODE)			
        case INFO_POWER| KEY_SHORT_UP :
#else			
	case INFO_MODE|KEY_SHORT_UP:
#endif	
#ifdef RADIO_MODE_HOT_KEY_ENABLE	
	     Set_Curr_Func(SYS_MP3DECODE_SD);
#else
	     Set_Curr_Func(last_work_mode);
#endif
	     set_usb_hotplug_protect(1);
            flush_all_msg();		 
	     return;
#endif

#ifdef  USE_POWER_KEY	
#ifndef USE_USB_HOTPLUG_FUNC
    case INFO_MODE | KEY_SHORT_UP:
#endif				
    case INFO_POWER | KEY_LONG:
#ifdef USE_RTC_FUNCTION
	     	Set_Curr_Func(SYS_RTC);
#endif
		return;
		break;
#endif		
#if ((USB_DEVICE_CFG & USB_SPEAKER) == USB_SPEAKER)
        case MSG_PC_MUTE:
            dac_mute_control(1, 1);
	     Mute_Ext_PA(MUTE);				
            break;
        case MSG_PC_UNMUTE:
		dac_mute_control(0, 1);
		Mute_Ext_PA(UNMUTE);						
            break;
        case INFO_VOL_PLUS :
        case INFO_VOL_PLUS | KEY_HOLD :
#if !defined(INDEPENDENT_VOLUME_KEY)							
        case INFO_NEXT_FIL | KEY_HOLD:
#endif			
		 	if(IR_KEY_Detect){
			IR_KEY_Detect =0;
			break;
			}
            my_music_vol += 2;
        case INFO_VOL_MINUS :
        case INFO_VOL_MINUS | KEY_HOLD :
#if !defined(INDEPENDENT_VOLUME_KEY)				
        case INFO_PREV_FIL | KEY_HOLD:
#endif			
            if (my_music_vol)
                my_music_vol--;

            if (my_music_vol > MAX_VOL)
            {
                my_music_vol = MAX_VOL;
            }
            if (my_music_vol == 0)
            {
                if (usb_audio_mute_status() == 0)
                    Usb_Audio_Mute_Ctl();
			   Mute_Ext_PA(MUTE);	
            }
            else
            {
                if (usb_audio_mute_status() == 1)
                    Usb_Audio_Mute_Ctl();
		      Mute_Ext_PA(UNMUTE);						
            }
	    music_vol =my_music_vol;
           write_info(MEM_VOL,my_music_vol);
           main_vol_set(0, SET_USE_CURRENT_VOL);

	    Disp_Con(DISP_VOL);
            break;
#endif
        case MSG_USB_PC_OUT:
#ifdef USE_USB_HOTPLUG_FUNC
     	 Set_Curr_Func(last_work_mode);
        flush_all_msg();
	 set_usb_hotplug_protect(0);
#endif
            return;

#if ((USB_DEVICE_CFG & USB_HID) == USB_HID)
#ifdef POWE_KEY_PLAY_KEY_IN_ONE_KEY
        case INFO_POWER| KEY_SHORT_UP :
#endif 
        case INFO_PLAY | KEY_SHORT_UP :
            usb_hid_control(USB_AUDIO_PP);
#ifdef USB_AUDIO_PLAY_LED_FLASH
		usb_audio_pp = ~usb_audio_pp;
		if(usb_audio_pp){
    			set_play_flash(LED_FLASH_ON);
		}
		else{
		    set_play_flash(LED_FLASH_NOR);
		}
#endif			
            break;

        case INFO_HALF_SECOND :
#if ((USE_DEVICE == MEMORY_STYLE)&&(FAT_MEMORY))           
            updata_fat_memory();
#endif
#ifdef DISP_BACKLIGHT_AUTO_SAVE_POWER
	 	Disp_BL_time_out();
#endif
            return_cnt++;
            if (RETURN_TIME == return_cnt)
            {
                if (DISP_DWORD_NUMBER == curr_menu)
                {
                    cfilenum = 0;
                }
                if (DISP_USBDEV != curr_menu)
                {
                    Disp_Con(DISP_USBDEV);
                }
            }
#if defined(USE_BAT_MANAGEMENT)
		bmt_hdlr();
#endif			
            break;

        case INFO_NEXT_FIL | KEY_SHORT_UP:
        //case INFO_NEXT_FIL | KEY_HOLD:
            usb_hid_control(USB_AUDIO_NEXTFILE);
            break;

        case INFO_PREV_FIL | KEY_SHORT_UP:
        //case INFO_PREV_FIL | KEY_HOLD:
            usb_hid_control(USB_AUDIO_PREFILE);
            break;

#endif
#if RTC_ENABLE 
		case INFO_ALM_BELL :			 ///<闹钟响消息，进入闹钟循环
			set_usb_audio_receive(1); 
			if(alm_bell_mode())
			{
				set_usb_audio_receive(0);
				return;
			}
			set_usb_audio_receive(0);
			break;
#endif
        default :
            if (!ap_handle_hotkey(key))
                return;
        }
    }

}
/*----------------------------------------------------------------------------*/
/**@brief   usb 从机任务 入口函数
   @param   无
   @return  无
   @note    void usb_audio_massstorage(void)
*/
/*----------------------------------------------------------------------------*/
void usb_audio_massstorage(void)
{
#if defined(USE_USB_HOTPLUG_FUNC)||defined(USE_PC_DC_POWER_ON_ONLY)
    if (pc_connect){
		goto _USB_DEV;
    }
#endif
#if USB_DEVICE_OTG
    device_check();
#else 
    EA = 0;
    if(usb_diskin_detect())
    {
	EA = 1;
	return;
    }	
    usb_pcin_detect();
    Delay(100);
    usb_pcin_detect();
    device_check();
    EA = 1;
#endif

    if (pc_connect)
    {
#if defined(USE_USB_HOTPLUG_FUNC)||defined(USE_PC_DC_POWER_ON_ONLY)
_USB_DEV:    
#endif
        work_mode = SYS_USBDEVICE;
        sysclock_div2(0);
        sd_speed_init(1, 100);
        flush_all_msg();
	 set_scsiinquiry(ufi_inquiry_str);
	 set_max_vol(MAX_ANALOG_VOL, MAX_DIGITAL_VOL);			//设置USB Slave模式的音量上限		
        usb_device();
        IE1 &= ~(BIT(1));
        disable_usb();	
    }
#if USB_DEVICE_OTG
    else
    {
        work_mode++;
    }
#endif
}

#endif





