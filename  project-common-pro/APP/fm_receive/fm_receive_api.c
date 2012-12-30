/*--------------------------------------------------------------------------*/
/**@file     fm_receive_api.c
   @brief    FM任务应用接口
   @details
   @author
   @date   2011-3-7
   @note
*/
/*----------------------------------------------------------------------------*/
#include "Custom_config.h"

#include "fm_api.h"
#include "led.h"
#include "RDA_FM_drv.h"
#include "bk1080.h"
#include "bk1088.h"
#include "CL6017.h"
#include "QN8035.h"
#include "sp_3777_drv.h"
#include "KT0830EG.h"
#include "AR1019.h"
#include "KT_AMFMdrv.h"
#include "main.h"

#ifdef FM_USE_BK1086
#undef USE_BK1080_FM
#endif

extern void set_play_flash(u8 led_status);
extern xd_u8 fre_point[];
//extern bit key_voice_disable;
extern u8 device_active;                           ///< 当前活动的设备
extern xd_u8 all_channl;                              ///< FM收音当前搜索到的台总数
extern xd_u16 frequency;                              ///< 当前频率
extern xd_u8 fre_channl;                              ///< FM收音当前所在的台号
static xd_u16  FM_chip_id=0xFFFF;
extern u8 _idata  my_music_vol;  
extern u8 given_device;
extern u8 play_status;

#if defined(K619_FXK_619_V001)
extern bool config_led_by_gpio;
#endif
extern _xdata SYS_WORK_MODE work_mode;

#ifdef RADIO_AM_WM_ENABLE
extern xd_u16 am_fre_point[MAX_AM_CHANNL];    //4 AM收音搜索到的台的缓存
extern bool radio_mode;
void Save_AM_Freq(u16 am_freq,u8 ch)
{
	
	xd_u8 freq_reg=0;

	if((ch&AM_FREQ_MAGIC_NUM)>0){
		
		freq_reg =(u8)am_freq&(0x00FF);
	      	write_info(MEM_AM_FRE, freq_reg);

		freq_reg =(u8)(am_freq>>8);
	      	write_info(MEM_AM_FRE+1, freq_reg);
	}
	else{

		freq_reg =(u8)am_freq&(0x00FF);
	      	write_info(MEM_AM_CHANNL +ch , freq_reg);

		freq_reg =(u8)(am_freq>>8);
	      	write_info(MEM_AM_CHANNL +ch+1, freq_reg);
	}
}
u16 Read_AM_Freq(u8 ch)
{
	
	xd_u8 freq_reg=0;
	xd_u16 freq_reg_2=0;

	if((ch&AM_FREQ_MAGIC_NUM)>0){
		freq_reg_2 = read_info(MEM_AM_FRE +1);
		freq_reg_2=freq_reg_2<<8;
		freq_reg_2 |= read_info(MEM_AM_FRE);
	}
	else{
	
		freq_reg= read_info(MEM_AM_CHANNL +ch);
		freq_reg_2=freq_reg;

		freq_reg = read_info(MEM_AM_CHANNL+ch+1);
		freq_reg_2|=freq_reg<<8;
	}
	return freq_reg_2;	
}
bool is_AMFM_online(void)
{

#ifdef FM_USE_BK1086
	if(FM_chip_id  == BK1088_ID){
		return 1;
	}
#endif	

#ifdef FM_USE_KT0913
	if(FM_chip_id== KT0913_CHIP_ID){
		
		return 1;
	}
#endif	
	return 0;
}
void FM_AM_chip_mode_sel(u8 modsel)
{
	if(modsel==RADIO_FM){		// SEL FM
#ifdef FM_USE_BK1086
		if(FM_chip_id  == BK1088_ID){
	    		BK1088_Intialization(0);
			return;
		}
#endif
#ifdef FM_USE_KT0913
		if(FM_chip_id== KT0913_CHIP_ID){
			KT_AMFMSetMode(1);
			return;			
		}
#endif
	}
	else{			// SEL  AM
#ifdef FM_USE_BK1086
		if(FM_chip_id  == BK1088_ID){			
		    	BK1088_Intialization(1);
			return;
		}
#endif
#ifdef FM_USE_KT0913
		if(FM_chip_id== KT0913_CHIP_ID){
			KT_AMFMSetMode(2);
			return;
		}
#endif
	}
}
#endif
u16 get_fm_id()
{
#if 0
		FM_chip_id = BK1088_ID;
		return FM_chip_id;
#endif

#ifdef USE_RDAs_FM
	FM_chip_id= RDA5807P_Get_ID();
	
	if((FM_chip_id  == RDAFM_ID1)||(FM_chip_id  == RDAFM_ID2)||(FM_chip_id  == RDAFM_ID3)||(FM_chip_id  == RDAFM_ID4)||(FM_chip_id  == RDAFM_ID5)){
		FM_chip_id  = RDAFM_ID;
		return FM_chip_id;
	}
#endif

#ifdef FM_USE_BK1086
	FM_chip_id=BK1088_Get_ID();
	
	if(FM_chip_id  == BK1088_ID){
		return FM_chip_id;
	}
#endif

#ifdef USE_BK1080_FM
	FM_chip_id=BK1080_Get_ID();
	
	if(FM_chip_id  == BK1080_ID){
		return FM_chip_id;
	}
#endif

#ifdef USE_CL6017G_FM
	FM_chip_id=CL6017G_Read_ID();

	if(FM_chip_id  == CL6017G_ID){
		return FM_chip_id;
	}
#endif

#ifdef  FM_USE_AR1015
	FM_chip_id=AR1000_Get_ID();
	
	if(FM_chip_id  == AR1000_ID){
		return FM_chip_id;
	}
#endif

#ifdef USE_SP3777_FM
	FM_chip_id=Read_SP3777_ID();

	if(FM_chip_id  == SP3777_ID){
		return FM_chip_id;
	}
#endif
#ifdef USE_QN8035_FM
	FM_chip_id = QN8035_Read_ID();
	if(FM_chip_id  == QN8035_ID){
		return FM_chip_id;
	}
#endif
#ifdef FM_USE_KT0830EG
	FM_chip_id = KT0830EG_ChipID();
	if(FM_chip_id  == KT0830EQ_ID){
		return FM_chip_id;
	}
#endif
#ifdef FM_USE_KT0913
	FM_chip_id = KT_AMFM_Read_ID();
	if(FM_chip_id  == KT0913_CHIP_ID){
		return FM_chip_id;
	}
#endif
	return 0xFFFF;
	//return init_rda5807();
}
/*----------------------------------------------------------------------------*/
/**@brief   FM模块初始化接口函数
   @param
   @return
   @note    void init_fm_rev(void)
*/
/*----------------------------------------------------------------------------*/
void init_fm_rev(void)
{
//	u16 rtvar;
	get_fm_id();

#ifdef USE_RDAs_FM
	if(FM_chip_id  == RDAFM_ID)
	{
    		RDA5807P_Intialization();
	}
#endif

#ifdef FM_USE_BK1086
	 if(FM_chip_id  == BK1088_ID)
	{
	    	BK1088_Intialization(0);
	}
#endif	

#ifdef USE_BK1080_FM
	if(FM_chip_id  == BK1080_ID)
	{
	    	BK1080_Intialization();
	}
#endif	
#ifdef USE_CL6017G_FM
	if(FM_chip_id  == CL6017G_ID)
	{
		init_CL6017G();
	}
#endif	
#ifdef  FM_USE_AR1015
	 if(FM_chip_id  == AR1000_ID)
	{
    		AR1000_Intialization();
	}
#endif

#ifdef USE_SP3777_FM
	if(FM_chip_id  == SP3777_ID){

		SP3777_init();
	}
#endif		
#ifdef USE_QN8035_FM
	if(FM_chip_id  == QN8035_ID){

		init_QN8035();
	}
#endif		
#ifdef FM_USE_KT0830EG
	if(FM_chip_id  == KT0830EQ_ID){

		KT_FMWakeUp();
	}
#endif
#ifdef FM_USE_KT0913
	if(FM_chip_id  == KT0913_CHIP_ID){

		KT_AMFMWakeUp();
	}
#endif		

    //printf("RDA5807P_Intialization %x \r\n",rtvar);
    //init_rda5807();
}
/*----------------------------------------------------------------------------*/
/**@brief   关闭FM模块电源
   @param
   @return
   @note    void fm_rev_powerdown(void
*/
/*----------------------------------------------------------------------------*/
void fm_rev_powerdown(void)
{
#ifdef USE_RDAs_FM
	if(FM_chip_id  == RDAFM_ID)
	{
		RDA5807P_PowerOffProc();
	}
#endif

#ifdef FM_USE_BK1086	
	 if(FM_chip_id==BK1088_ID)
	{
		BK1088_PowerOffProc();
	}
#endif	

#ifdef USE_BK1080_FM	
	if(FM_chip_id==BK1080_ID)
	{
		BK1080_PowerOffProc();
	}
#endif	
#ifdef USE_CL6017G_FM	
	if(FM_chip_id  == CL6017G_ID)
	{
		CL6017G_PowerOff();
	}
#endif	
#ifdef  FM_USE_AR1015
	if(FM_chip_id  == AR1000_ID)
	{
    		AR1000_PowerOff();
	}
#endif

#ifdef USE_SP3777_FM	
	if(FM_chip_id  == SP3777_ID)
	{
		SP3777_Powerdown();
	}	
#endif
#ifdef USE_QN8035_FM
	if(FM_chip_id  == QN8035_ID){

		QN8035_powerdown();
	}
#endif		
#ifdef FM_USE_KT0830EG
	if(FM_chip_id  == KT0830EQ_ID){

		KT_FMStandby();
	}
#endif
#ifdef FM_USE_KT0913
	if(FM_chip_id  == KT0913_CHIP_ID){

		KT_AMFMStandby();
	}
#endif	
    //rda5807_poweroff();
}
/*----------------------------------------------------------------------------*/
/**@brief   设置一个FM频点的接口函数
   @param   fre：频点
   @return  1：有台；0：无台
   @note    bool set_fre(u16 fre, u8 mode)
*/
/*----------------------------------------------------------------------------*/
bool set_fre(u16 fre, u8 mode)
{
	bool rtvar;
	mode=mode;

#ifdef UART_ENABLE
	printf("----->set_fre  %4u \r\n ",(u16)fre);
#endif
	
#if SDMMC_CMD_MODE   
	sd_chk_ctl(DIS_SD_CMD_CHK);
#endif
	
#ifdef USE_RDAs_FM	
	if(FM_chip_id  == RDAFM_ID)
	{
		rtvar = RDA5807P_ValidStop(fre);
       	RDA5807P_SetMute(FALSE);
	}
#endif

#ifdef FM_USE_BK1086
	 if(FM_chip_id  == BK1088_ID){

               BK1088_SetFreq(fre);
       	 BK1088_SetMute(FALSE);
	}
#endif	

#ifdef USE_BK1080_FM		
	if(FM_chip_id==BK1080_ID)
	{
		rtvar = BK1080_ValidStop(fre,875);
       	BK1080_SetMute(FALSE);
	}
#endif	
#ifdef USE_CL6017G_FM		
	if(FM_chip_id  == CL6017G_ID)
	{
		CL6017G_TUNE(fre);
		MuteCL6017(FALSE);
	}
#endif	
#ifdef  FM_USE_AR1015
	if(FM_chip_id  == AR1000_ID)
	{
    		rtvar=set_fre_AR1000(fre,1);
		AR1000_SetMute(FALSE);
	}
#endif

#ifdef USE_SP3777_FM		
	if(FM_chip_id  == SP3777_ID){

		rtvar =SP3777_FMSeek_TuneMethod(fre);
		SP3777_MUTE(FALSE);
	}
#endif
#ifdef USE_QN8035_FM
	if(FM_chip_id  == QN8035_ID){
		QND_TuneToCH(fre*10);
		QN8035_MUTE(FALSE);
	}
#endif		
#ifdef FM_USE_KT0830EG
	if(FM_chip_id  == KT0830EQ_ID){

		KT_FMTune(fre*10);
	}
#endif	
#ifdef FM_USE_KT0913
	if(FM_chip_id  == KT0913_CHIP_ID){

#ifdef RADIO_AM_WM_ENABLE
		if(work_mode==SYS_FMREV){	//3FM
		
			KT_FMTune(fre*10);
		}
		else	{	//4AM
			
			KT_MWTune(fre);
		}
		KT_Mute_Ctrl(FALSE);
#else
		KT_FMTune(fre*10);
#endif
	}
#endif	

#if SDMMC_CMD_MODE   
	sd_chk_ctl(EN_SD_CMD_CHK);
#endif

#if defined(FM_PLAY_KEY_PAUSE)      
	  if(play_status ==MUSIC_PAUSE){
	     	my_main_vol(my_music_vol);
	       play_status = MUSIC_PLAY;
    		Mute_Ext_PA(UNMUTE); 					
	  }			
#endif

	return rtvar;
    //return set_fre_rda5807(fre, mode);
}

void FM_Chip_SetMute(bool flag)
{
#ifdef USE_RDAs_FM	
	if(FM_chip_id  == RDAFM_ID)
	{
	 	RDA5807P_SetMute(flag);
		return;		
	}
#endif

#ifdef FM_USE_BK1086		
	 if(FM_chip_id==BK1088_ID)
	{
		 BK1088_SetMute(flag);
		return;		
	}
#endif

#ifdef USE_BK1080_FM		
	if(FM_chip_id==BK1080_ID)
	{
		 BK1080_SetMute(flag);
		return;		
	}
#endif	
#ifdef USE_CL6017G_FM	
	if(FM_chip_id  == CL6017G_ID)
	{
		MuteCL6017(flag);
		return;		
	}
#endif	
#ifdef  FM_USE_AR1015
	if(FM_chip_id  == AR1000_ID)
	{
    		AR1000_SetMute(flag);
		return;		
	}
#endif

#ifdef USE_SP3777_FM			
	if(FM_chip_id  == SP3777_ID){

		SP3777_MUTE(flag);
		return;		
	}	
#endif	
#ifdef USE_QN8035_FM
	if(FM_chip_id  == QN8035_ID){

		QN8035_MUTE(flag);
		return;		
	}
#endif		
#ifdef FM_USE_KT0830EG
	if(FM_chip_id  == KT0830EQ_ID){

		//KT_FMMute(flag);
		return;		
	}
#endif
#ifdef FM_USE_KT0913
	if(FM_chip_id  == KT0913_CHIP_ID){

		KT_Mute_Ctrl(flag);
		return;		
	}
#endif	

}

bool FM_Chip_ValidStop(fre)
{
#ifdef USE_RDAs_FM	
	if(FM_chip_id  == RDAFM_ID)
	{
		return  RDA5807P_ValidStop(fre);
	}
#endif
#ifdef FM_USE_BK1086
 if(FM_chip_id  == BK1088_ID){

#ifdef RADIO_AM_WM_ENABLE

		if(work_mode==SYS_FMREV)
		return BK1088_FMValidStop(frequency,MIN_FRE);
		else
		return BK1088_AMValidStop(frequency,AM_MIN_FRE);
#else
		return BK1088_FMValidStop(frequency,MIN_FRE);
#endif

	}
#endif	

#ifdef USE_BK1080_FM		
	if(FM_chip_id==BK1080_ID)
	{
		return  BK1080_ValidStop(fre,MIN_FRE);
	}
#endif	
#ifdef USE_CL6017G_FM	
	if(FM_chip_id  == CL6017G_ID)
	{
		return CL6017G_ValidStop(fre);
	}
#endif	
#ifdef  FM_USE_AR1015
	if(FM_chip_id  == AR1000_ID)
	{
		return AR1000_ValidStop(frequency);
          // return set_fre_AR1000(frequency,0);
	}
#endif

#ifdef USE_SP3777_FM			
	if(FM_chip_id  == SP3777_ID)
	{
		return SP3777_FMSeek_TuneMethod(fre);
	}
#endif
#ifdef USE_QN8035_FM
	if(FM_chip_id  == QN8035_ID){

		return set_fre_QN8035(fre);
	}
#endif		
#ifdef FM_USE_KT0830EG
	if(FM_chip_id  == KT0830EQ_ID){

		return KT0830EG_ValidStop(fre*10);
	}
#endif
#ifdef FM_USE_KT0913
	if(FM_chip_id  == KT0913_CHIP_ID){

#ifdef RADIO_AM_WM_ENABLE
		if(work_mode==SYS_FMREV)
			return KT_FMValidStation(fre*10);
		else
			return KT_AMValidStation(fre);
#else
		return KT_FMValidStation(fre*10);
#endif
	}
#endif	

	return 0;	
}
void FM_Chip_Set_Vol(u8 fm_vol)
{
	u16 vol_temp=0;
	printf(" FM_Chip_Set_Vol %d \r\n",(u16)fm_vol);
#if defined(CUSTOM_VOL_LIMIT_AT_VOL_DEF)
	vol_temp = (15*fm_vol);
	vol_temp =(vol_temp/VOLUME_DEFUALT);
	if(vol_temp >15)vol_temp =15;
#else	
	vol_temp = (15*fm_vol);
	vol_temp =(vol_temp/MAX_VOL_SHOW);
#endif
	printf(" FM_Chip_Set_Vol %d \r\n",vol_temp);
	
#ifdef USE_RDAs_FM	
	if(FM_chip_id  == RDAFM_ID)
	{
		RDA5807P_SetVolumeLevel((u8)vol_temp);
		return;		
	}
#endif

#ifdef FM_USE_BK1086		
	if(FM_chip_id==BK1088_ID)
	{
		BK1088_SetVolume((u8)vol_temp);
		return;		
	}
#endif	

#ifdef USE_BK1080_FM		
	if(FM_chip_id==BK1080_ID)
	{
		BK1080_SetVolume((u8)vol_temp);
		return;		
	}
#endif
#ifdef USE_QN8035_FM
	if(FM_chip_id  == QN8035_ID){

		QN8035_set_vol((u8)vol_temp);
		return;		
	}
#endif	
#ifdef  FM_USE_AR1015
	if(FM_chip_id  == AR1000_ID)
	{

		  AR1000_SetVolume((u8)vol_temp);
		return;		
	}
#endif
#ifdef FM_USE_KT0913
	if(FM_chip_id  == KT0913_CHIP_ID){
		
		KT_AMFMVolumeSet((u8)(vol_temp<<1));
		return;		
	}
#endif	

}

/*----------------------------------------------------------------------------*/
/**@brief    获取一个已经存下的台号
   @param    flag ：台号
   @return
   @note     void get_channl(u8 flag)
*/
/*----------------------------------------------------------------------------*/
void get_channl(u8 flag)
{
#ifdef RADIO_AM_WM_ENABLE

if(work_mode==SYS_AMREV){
    frequency = am_fre_point[flag-1] + AM_MIN_FRE;
    if ( frequency > AM_MAX_FRE)
    {
        frequency = AM_MIN_FRE;
    }
    else if (frequency < AM_MIN_FRE)
    {
        frequency = AM_MAX_FRE;
    }					
    write_info(MEM_AM_FRE_CHANNL,fre_channl);
    Save_AM_Freq((frequency - AM_MIN_FRE),(AM_FREQ_MAGIC_NUM));
}
else
#endif
{
    frequency = fre_point[flag-1] + MIN_FRE;
    if ( frequency > MAX_FRE)
    {
        frequency = MIN_FRE;
    }
    else if (frequency < MIN_FRE)
    {
        frequency = MAX_FRE;
    }					
    write_info(MEM_FRE_CHANNL,fre_channl);
    write_info(MEM_FRE,frequency - MIN_FRE);
}	
    Disp_Con(DISP_CH_NO);

#ifndef DISABLE_FM_CH_SEL_MUTE	
    Mute_Ext_PA(MUTE);
#endif

    my_main_vol(0);		
    //set_fre_rda5807(frequency,1);
    set_fre(frequency,0);

    delay_10ms(20);
    my_main_vol(my_music_vol);	
    Mute_Ext_PA(UNMUTE);

}
/*----------------------------------------------------------------------------*/
/**@brief    全频段搜索
   @param
   @return
   @note     void scan_fre(void)
*/
/*----------------------------------------------------------------------------*/
#ifdef USE_POWER_KEY_SHORT_SCAN
#define FM_SCAN_STOP_KEY_1 		INFO_POWER
#elif defined(USE_MODE_KEY_LONG_SCAN)

#ifdef USE_PWR_KEY_FOR_SCAN_STOP
#define FM_SCAN_STOP_KEY_1 		INFO_POWER
#else
#define FM_SCAN_STOP_KEY_1 		INFO_MODE
#endif

#elif defined(USE_EQ_KEY_SHORT_SCAN)
#define FM_SCAN_STOP_KEY_1 		INFO_EQ_UP
#elif defined(K120_YJH_120_V001)||defined(IR_INFO_EQ_DOWN_SCAN)
#define FM_SCAN_STOP_KEY_1 		INFO_EQ_DOWN
#elif defined(USE_STOP_KEY_SHORT_SCAN)
#define FM_SCAN_STOP_KEY_1 		INFO_STOP
#else
#define FM_SCAN_STOP_KEY_1 		INFO_PLAY
#endif

#if defined(IR_USER_CODE_0x7F80)

#if defined(K722_YJH_722_V001)
#define FM_SCAN_STOP_KEY_2 	0x00
#else
#define FM_SCAN_STOP_KEY_2 	INFO_EQ_DOWN
#endif
#elif defined(EQ_DOWN_SCAN_ALL)
#define FM_SCAN_STOP_KEY_2 	INFO_EQ_DOWN
#elif defined(IR_PLAY_KEY_SCAN_FREQ_ALL)
#define FM_SCAN_STOP_KEY_2 	INFO_PLAY
#else
#define FM_SCAN_STOP_KEY_2 	0x00
#endif

#ifdef K1166_JM_YT_V001
#undef FM_SCAN_STOP_KEY_1
#define FM_SCAN_STOP_KEY_1 		INFO_PLAY
#endif
void scan_fre(void)
{
    u16 i;
    u8 key=0;
#ifdef RADIO_AM_WM_ENABLE
    xd_u16 freq_max_range=0;
    xd_u8 max_channel=0;
#endif	
    //key_voice_disable = 1;
    Mute_Ext_PA(MUTE);
#ifdef FM_BY_PASS
    FM_Chip_SetMute(TRUE);
#endif
#if defined(USE_SPECTRUM_PARTTERN)		  		
    set_lcd_flash_lock(LOCK);
#endif

#ifdef USE_QN8035_FM
	if(FM_chip_id  == QN8035_ID){
    		QND_RXSetTH();
	}
#endif

#if defined(FM_PLAY_KEY_PAUSE)
	play_status =MUSIC_PLAY;
#endif		

    my_main_vol(0);	
    all_channl = 0;
	
#ifdef RADIO_AM_WM_ENABLE

	if(work_mode==SYS_FMREV){	//3FM

		max_channel  = MAX_CHANNL;
		freq_max_range = MAX_FRE-MIN_FRE;
    		my_memset((u8 _xdata*)fre_point,0,30);
		frequency = MIN_FRE;
	}
	else{
		max_channel  = MAX_AM_CHANNL;
    		my_memset((u8 _xdata*)am_fre_point,0,30);
		freq_max_range = AM_MAX_FRE-AM_MIN_FRE;
    		frequency = AM_MIN_FRE;
	}

#else	
    frequency = MIN_FRE;
    my_memset((u8 _xdata*)fre_point,0,30);
#endif

#ifdef LED_STATUS_FLASH_VERY_FAST_AT_FM_SCAN
    set_play_flash(LED_FLASH_VERY_FAST);	
#else
    set_play_flash(LED_FLASH_FAST);	
#endif
#ifndef FM_BY_PASS
    DACCON2 &= ~(1<<5);	//AMUX disable
#endif
    Disp_Con(DISP_FREQ);

#ifdef RADIO_AM_WM_ENABLE
    for (i = 0;i <= (freq_max_range);i++)
#else	
    for (i = 0;i <= (1080-MIN_FRE);i++)
#endif		
    {
//        printf("----------- fre %4u -----------------\n",(u16)(fre));
        //if (set_fre(frequency, 0))
        if(FM_Chip_ValidStop(frequency))
        {
        
#if !defined(KEEP_SILENT_WHEN_SCAN_CHANNEL)
#ifndef FM_BY_PASS
      	     FM_Chip_SetMute(FALSE);
#endif
	     my_main_vol(my_music_vol);
            delay_10ms(1);		 
	     Mute_Ext_PA(UNMUTE);
#endif		 
#ifdef RADIO_AM_WM_ENABLE

	if(work_mode==SYS_FMREV){	//3FM
            fre_point[all_channl] = i;
	}
	else{
            am_fre_point[all_channl] = i*MW_CHANNEL_STEP;
	}
        all_channl++;
#else
            fre_point[all_channl] = i;
            all_channl++;
#endif			
	     Disp_Con(DISP_SCAN_NO);
#if defined(KEEP_SILENT_WHEN_SCAN_CHANNEL)
	     Mute_Ext_PA(MUTE);
	     my_main_vol(0);
            delay_10ms(100);
#else
#ifdef FM_BY_PASS
      	     FM_Chip_SetMute(FALSE);
#endif
#ifndef FM_BY_PASS
	     DACCON2 |= (1<<5);	//AMUX enable	
#endif

#if defined(LED_STATUS_STOP_AT_VALID_STATION)
    	   set_play_flash(LED_FLASH_ON);	
#endif

#ifdef K302_ZhengYang_ZY302_V001	
            delay_10ms(80);
#else
            delay_10ms(180);
#endif
	     Mute_Ext_PA(MUTE);
            delay_10ms(1);		 		 
	     my_main_vol(0);
#ifndef FM_BY_PASS	 
	     DACCON2 &= ~(1<<5);	//AMUX disable
#endif	     
	     FM_Chip_SetMute(TRUE);	 
#endif	
            delay_10ms(20);
#if defined(LED_STATUS_STOP_AT_VALID_STATION)
    	   set_play_flash(LED_FLASH_FAST);	
#endif
        }

#ifdef RADIO_AM_WM_ENABLE
	if(work_mode==SYS_FMREV){	//3FM

		 if(frequency++ >MAX_FRE){
		 	frequency = MAX_FRE;
	          	Disp_Con(DISP_FREQ);
			break;
		 }
	}
	else{
		frequency+=MW_CHANNEL_STEP;
		 if(frequency>AM_MAX_FRE){
		 	frequency = AM_MAX_FRE;
	          	Disp_Con(DISP_FREQ);
			break;
		 }
	 }
#else

#if defined(FM_STEP_50K)	
	 frequency=frequency+5;
	 if(frequency >MAX_FRE){
	 	frequency = MAX_FRE;
          	Disp_Con(DISP_FREQ);
		break;
	 }
#else
	 if(frequency++ >MAX_FRE){
	 	frequency = MAX_FRE;
          	Disp_Con(DISP_FREQ);
		break;
	 }
#endif

#endif	 
	 #if defined(USE_LCD_DRV_HT1621)||defined(LCD_GPIO_DRV)
        	Disp_Con(DISP_FREQ);	 
	 #else
        	Disp_Con(DISP_FREQ|CLS_BUF_MAGIC_NUM);
	 #endif
	 
	 key=get_msg();
	 
#ifdef FM_SCAN_DEV_SMOOTH_FUNC
	 if((key== MSG_SDMMC_IN)||(key== MSG_USB_DISK_IN)||(key== MSG_AUX_IN)){

	     //sys_printf(" -------->FM_SCAN_DEV_SMOOTH_FUNC");
            flush_low_msg();
	     put_msg_lifo((key));			
            break;	
	 }
#endif
#ifdef FM_SCAN_MODE_KEY_SMOOTH_FUNC
	 if(key== (INFO_MODE | KEY_SHORT_UP)){

	     //sys_printf(" -------->FM_SCAN_MODE_KEY_SMOOTH_FUNC");
            flush_low_msg();
	     put_msg_lifo((INFO_MODE | KEY_SHORT_UP));
            break;	
	 }
#endif
#ifdef RADIO_AM_WM_ENABLE
        if(all_channl >= max_channel||( key==(FM_SCAN_STOP_KEY_1 | KEY_SHORT_UP))||(key==(FM_SCAN_STOP_KEY_2|KEY_SHORT_UP)))
#else
        if(all_channl >= MAX_CHANNL||( key==(FM_SCAN_STOP_KEY_1 | KEY_SHORT_UP))||(key==(FM_SCAN_STOP_KEY_2|KEY_SHORT_UP)))
#endif			
        {
            flush_low_msg();
            break;
        }
    }
#ifndef FM_BY_PASS	 
	DACCON2 |= (1<<5);	//AMUX enable
#endif	
    //key_voice_disable = 0;
    for (i = 0; i < all_channl; i++)
    {
#ifdef RADIO_AM_WM_ENABLE
	if(work_mode==SYS_FMREV){	//3FM

		write_info(MEM_CHANNL + i , fre_point[i]);
	}
	else{

		
        	Save_AM_Freq(am_fre_point[i],i*2);
	}
#else    
        write_info(MEM_CHANNL + i , fre_point[i]);
#endif
    }
#ifdef RADIO_AM_WM_ENABLE
	if(work_mode==SYS_FMREV){	//3FM

	    write_info(MEM_ALL_CHANNL , all_channl);
	}
	else{
		
	    write_info(MEM_AM_ALL_CHANNL , all_channl);
	}
#else
    write_info(MEM_ALL_CHANNL , all_channl);
#endif
    FM_Chip_SetMute(FALSE);
    my_main_vol(my_music_vol);		
    set_play_flash(LED_FLASH_ON);

#if defined(USE_SPECTRUM_PARTTERN)		  		
    set_lcd_flash_lock(UNLOCK);
#endif
	
}

/*----------------------------------------------------------------------------*/
/**@brief   存一个频点为台
   @param
   @return
   @note     void save_fre(u16 fre)
*/
/*----------------------------------------------------------------------------*/
void save_fre(u16 fre)
{
    if (all_channl < MAX_CHANNL-1)
    {
        fre_point[all_channl] = fre - MIN_FRE;
        write_info(MEM_CHANNL + all_channl , fre - MIN_FRE);
        all_channl++;
    }
    write_info(MEM_ALL_CHANNL , all_channl);
    //delay_10ms(3);

    //delay_10ms(3);
    fre_channl = all_channl;
    get_channl(fre_channl);
}
#define SEMI_SACN_KEY1		INFO_NEXT_FIL|KEY_SHORT_UP
#define SEMI_SACN_KEY2		INFO_PREV_FIL|KEY_SHORT_UP
void auto_scan(AUTO_DIR Dir)
{
    u16 fre_old=0;
    u8 key=0;
#ifdef RADIO_AM_WM_ENABLE
    xd_u16 freq_max=0,freq_min=0;
	if(work_mode==SYS_FMREV){	//3FM
		freq_max = MAX_FRE;
		freq_min = MIN_FRE;
	}
	else{
		
		freq_max = AM_MAX_FRE;
		freq_min = AM_MIN_FRE;		
	}
#endif	

#if defined(USE_SPECTRUM_PARTTERN)		  		
	set_lcd_flash_lock(LOCK);
#endif
	
    //key_voice_disable = 1;
    fre_old = frequency;
	
#ifdef K619_FXK_619_V001
	if(config_led_by_gpio==0){
	    Disp_Con(DISP_START);
	    delay_10ms(60);		
	}
#endif

#ifdef USE_QN8035_FM
	if(FM_chip_id  == QN8035_ID){
	    	QND_RXSetTH();
	}
#endif


    set_play_flash(LED_FLASH_FAST);
    Mute_Ext_PA(MUTE);	
    my_main_vol(0);
	

#if defined(FM_PLAY_KEY_PAUSE)      
	play_status = MUSIC_PLAY;
#endif

    flush_low_msg();

    FM_Chip_SetMute(TRUE);
    DACCON2 &= ~(1<<5);	//AMUX disable
    sys_clock_rc();

    do   
    {
	 key = get_msg();	

#ifdef FM_SCAN_DEV_SMOOTH_FUNC
	 if((key== MSG_SDMMC_IN)||(key== MSG_USB_DISK_IN)||(key== MSG_AUX_IN)){

	      //sys_printf(" -------->FM_SCAN_DEV_SMOOTH_FUNC");
             flush_low_msg();
             FM_Chip_SetMute(FALSE);
             break;
	 }
#endif
#ifdef FM_SCAN_MODE_KEY_SMOOTH_FUNC
	 if(key== (INFO_MODE | KEY_SHORT_UP)){
	     //sys_printf(" -------->FM_SCAN_MODE_KEY_SMOOTH_FUNC");
            flush_low_msg();
	     put_msg_lifo((INFO_MODE | KEY_SHORT_UP));
            FM_Chip_SetMute(FALSE);	 
            break;	
	 }
#endif

        if ((key==(FM_SCAN_STOP_KEY_2|KEY_SHORT_UP))||( key==(FM_SCAN_STOP_KEY_1 | KEY_SHORT_UP))||
		( key==(SEMI_SACN_KEY1))||( key==(SEMI_SACN_KEY2))
	     )
        {
             FM_Chip_SetMute(FALSE);
            break;
        }
		
	if(Dir == SEARCH_UP)
	{
#ifdef RADIO_AM_WM_ENABLE
	if(work_mode==SYS_FMREV){	//3FM
          if(frequency++>freq_max)frequency = freq_min;

	}
	else{

		frequency=frequency+MW_CHANNEL_STEP;
          	if(frequency>freq_max){
#ifdef SEMI_SCAN_BAND_BREAK_AT_FREQ_LIMIT
		  	frequency = freq_max;
			break;
#else
		  	frequency = freq_min;
#endif
          	}
	}
#else
          if(frequency++>MAX_FRE)frequency = MIN_FRE;
#endif		  
          Disp_Con(DISP_FREQ);
	}
	else
	{
#ifdef RADIO_AM_WM_ENABLE
	if(work_mode==SYS_FMREV){	//3FM
          if(frequency--<freq_min)frequency =freq_max;

		}
	else{

		frequency=frequency-MW_CHANNEL_STEP;
          	if(frequency<freq_min){
#ifdef SEMI_SCAN_BAND_BREAK_AT_FREQ_LIMIT
		  	frequency = freq_min;
			break;
#else				
		  	frequency = freq_max;
#endif
		}

	}
#else	
          if(frequency--<MIN_FRE)frequency =MAX_FRE;
#endif		  
          Disp_Con(DISP_FREQ);
	}
	
        Disp_Con(DISP_FREQ|CLS_BUF_MAGIC_NUM);

	if(fre_old ==frequency)
	{
		break;
	}        

	if(FM_Chip_ValidStop(frequency))
        {
            Disp_Con(DISP_FREQ);
	     FM_Chip_SetMute(FALSE);
	     break;
        }

    }while(1);

     DACCON2 |= (1<<5);	//AMUX enable		
     my_main_vol(my_music_vol);		
     Mute_Ext_PA(UNMUTE);

#if defined(USE_SPECTRUM_PARTTERN)		  		
	set_lcd_flash_lock(UNLOCK);
#endif
	 
    //key_voice_disable = 0;
    set_play_flash(LED_FLASH_ON);
}
#if defined(USE_FM_GPIO)
extern void RDA5807P_gpio_ctrl(bool fm_ctrl_flag,u8 gpio_num);
extern void BK1080__gpio_ctrl(bool fm_ctrl_flag,u8 gpio_num);
extern void QN8075__gpio_ctrl(bool fm_ctrl_flag,u8 gpio_num);
void fm_chip_gpio_ctrl(bool fm_ctrl_flag)
{
#ifdef USE_RDAs_FM	
	if(FM_chip_id  == RDAFM_ID)
	{
		RDA5807P_gpio_ctrl(fm_ctrl_flag,FM_GPIO_2);
	}
#endif
#ifdef USE_BK1080_FM		
	else if(FM_chip_id==BK1080_ID)
	{
		BK1080__gpio_ctrl(fm_ctrl_flag,FM_GPIO_2);
	}
#endif
#ifdef USE_QN8035_FM
	else if(FM_chip_id==QN8035_ID)
	{
		QN8075__gpio_ctrl(fm_ctrl_flag,FM_GPIO_2);
	}
#endif	

}
#endif
