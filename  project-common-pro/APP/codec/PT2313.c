/*--------------------------------------------------------------------------
   @file   display_common.c
   @brief    显示模块头文件
   @details
   @author
   @date   2010-04-20
   @note

----------------------------------------------------------------------------*/
#include "Custom_config.h"
#include "iic.h"
#include "config.h"
#include "PT2313.h"

#ifdef SUPPORT_M62429
#include "m62429.h"
extern void M62429_config_Data(u8 adj_dir,u8 adj_channel,u16 reg_data);
extern void M62429_Init(void);
#endif
//#define  UART_ENABLE_PT2313

#ifdef SUPPORT_PT2313
bool PT_Mute_flag = 0;
extern u8 eq_mode;
extern u8 _idata my_music_vol;
xd_u8 PT_Channel_Val = 0;
xd_u8  PT_Bass_Val=PT_MAX_VOL/2;
xd_u8  PT_Treble_Val=PT_MAX_VOL/2;
xd_u8  PT_Balence_Val=PT_MAX_VOL/2;
xd_u8  PT_Fade_Val=PT_MAX_VOL/2;
xd_u8  PT_Subw_Val=PT_MAX_VOL/2;
xd_u8 PT_max_eq=0;

_code u8 VOL_Table[36] = {63,63,63,63,63,63,50,44,38,34,30,28,26,24,22,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
_code u8   IMPACT_TABLE[5][3]=
{
 	{19,32,35},
	{28,26,32},
	{30,31,50},
	{36,33,43},
	{26,32,35},
};
_code u8  BalanceTable[]={
	0x1f,0x19,0x15,0x11,0x0d,0x09,0x04,0x00
};
_code u8 EQTable1[]=
{
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,		//0x07,
     // -14 -12  -10    -8      -6    -4      -2   0
	0x0f,0x0e,0x0d,0x0c,0x0b,0x0a,0x09,0x08
    //  0      2      4      6       8     10     12     14		
};

#ifdef K2081_DM_007_V001
_code u8 PT_EQ_Table[9][2]={

	{0x6f,0x7f},
	{0x6e,0x7c},
	{0x6f,0x7f},
	{0x6d,0x7b},
	{0x6b,0x7d},
	{0x68,0x78},	
	{0x60,0x78},	
	{0x68,0x70},	
	{0x6a,0x7a},	
};
#else
//const u8 EQDataTable[5][2]={
_code u8 PT_EQ_Table[6][2]={	
	{0x6f,0x7f},
	{0x6e,0x7c},
	{0x6f,0x7f},
	{0x6d,0x7b},
	{0x6b,0x7d},
	{0x68,0x78},	
};
#endif
void PT2313WriteByte(u8 cDevAddr,u8 cData)
{
    /* start condition */
    iic_start();                //I2C启动
    cDevAddr &= 0xFE;   // Force WRITE address
    /* send device ID and write data */
    iic_sendbyte(cDevAddr);   //写地址
    //r_ack();
    iic_sendbyte(cData);      //写数据
    //r_ack();	
    iic_stop();                 //I2C停止时序	
}
static bool PT_Londness_Flag =0;
bool get_pt_2313_londness_flag()
{
	return PT_Londness_Flag;
}
void PT_2313_Loudness_config()
{
	PT_Londness_Flag =~PT_Londness_Flag;
	
	if(PT_Londness_Flag){

		PT_Channel_Val &=~PT_LOUDNESS_ADDR;
		//PT_Channel_Val &=~(0x18);
	}
	else{
		PT_Channel_Val |=PT_LOUDNESS_ADDR;
		//PT_Channel_Val |=(0x18);
	}
#ifdef UART_ENABLE_PT2313
	printf(" PT_2313_Loudness_config   -->PT_Londness_Flag  %d \r\n",(u16)PT_Londness_Flag);
#endif

	PT2313WriteByte(PT_2313_ADDR, PT_Channel_Val);
}
void PT_2313_Treble_config(PT_CTRL_CMD PT_CMD)
{

	u8 temp_var =0;

	if(PT_CMD ==PT_UP){
		if((PT_Treble_Val++)>=PT_TABLE_MAX)PT_Treble_Val =PT_TABLE_MAX;
	}
	else if(PT_CMD ==PT_DW){
		
		if((PT_Treble_Val--)==0)PT_Treble_Val =0;
	}

	if(PT_TABLE_MAX>14){

		temp_var=PT_Treble_Val/2;
	}
	
	PT2313WriteByte(PT_2313_ADDR,EQTable1[temp_var]|PT_TRABLE_ADDR);

	write_info(MEM_TREB,PT_Treble_Val);

#ifdef UART_ENABLE_PT2313
	printf(" PT_2313_Treble_config   -->PT_Treble_Val  %d \r\n",(u16)PT_Treble_Val);
#endif
}
void PT_2313_Bass_config(PT_CTRL_CMD PT_CMD)
{
	u8 temp_var =0;
	if(PT_CMD ==PT_UP){
		if((PT_Bass_Val++)>=PT_TABLE_MAX)PT_Bass_Val =PT_TABLE_MAX;
	}
	else if(PT_CMD ==PT_DW){
		
		if((PT_Bass_Val--)==0)PT_Bass_Val =0;
	}

	if(PT_TABLE_MAX>14){

		temp_var=PT_Bass_Val/2;
	}
	
	PT2313WriteByte(PT_2313_ADDR,EQTable1[temp_var]|PT_BASS_ADDR);

	write_info(MEM_BASE,PT_Bass_Val);

#ifdef UART_ENABLE_PT2313
	printf(" PT_2313_Bass_config   -->PT_Bass_Val  %d \r\n",(u16)PT_Bass_Val);
#endif
	
}
u8 SPK_FR=PT_MIN_VOL,SPK_FL=PT_MIN_VOL,SPK_BR=PT_MIN_VOL,SPK_BL=PT_MIN_VOL;
void get_audio_effect_para()
{
	u8 Fad_factor =0,Bal_factor=0,Fad_factor_temp=0;
	u8 cord_location =0;
	
	if((PT_Balence_Val>=PT_MIN_VOL)&&(PT_Fade_Val>=PT_MIN_VOL)){
		
		cord_location  = 0x01;
		
		Fad_factor = PT_Fade_Val-PT_MIN_VOL;
		Bal_factor = PT_Balence_Val-PT_MIN_VOL;
	}
	else if((PT_Balence_Val<=PT_MIN_VOL)&&(PT_Fade_Val>=PT_MIN_VOL)){

		cord_location  = 0x02;
		
		Fad_factor = PT_Fade_Val-PT_MIN_VOL;
		Bal_factor = PT_MIN_VOL-PT_Balence_Val;
	}
	else if((PT_Balence_Val<=7)&&(PT_Fade_Val<=PT_MIN_VOL)){

		cord_location  = 0x03;
		
		Fad_factor = PT_MIN_VOL-PT_Fade_Val;
		Bal_factor = PT_MIN_VOL-PT_Balence_Val;
	}
	else if((PT_Balence_Val>=PT_MIN_VOL)&&(PT_Fade_Val<=PT_MIN_VOL)){

		cord_location  = 0x04;
		
		Fad_factor = PT_MIN_VOL- PT_Fade_Val;
		Bal_factor = PT_Balence_Val - PT_MIN_VOL;
	}

	if((Fad_factor == PT_MIN_VOL)||(Bal_factor==PT_MIN_VOL)){

		Fad_factor_temp = PT_MIN_VOL;
	}
	else if(Fad_factor>Bal_factor){
		
		Fad_factor_temp = Fad_factor;
	}
	else{
		
		Fad_factor_temp = Bal_factor;
	}

	switch(cord_location)
	{
		case 0x01:
			SPK_FR=PT_MIN_VOL;SPK_FL=PT_MIN_VOL-Bal_factor;SPK_BR=PT_MIN_VOL-Fad_factor;
			SPK_BL=PT_MIN_VOL-Fad_factor_temp;//((Bal_factor+Fad_factor)>>1);
			break;
		case 0x02:
			SPK_FR=PT_MIN_VOL-Bal_factor;SPK_FL=PT_MIN_VOL;SPK_BL=PT_MIN_VOL-Fad_factor;
			SPK_BR=PT_MIN_VOL-Fad_factor_temp;//((Bal_factor+Fad_factor)>>1);
			break;		
		case 0x03:
			SPK_FL=PT_MIN_VOL-Fad_factor;SPK_BR=PT_MIN_VOL-Bal_factor;SPK_BL=PT_MIN_VOL;
			SPK_FR=PT_MIN_VOL-Fad_factor_temp;//((Bal_factor+Fad_factor)>>1);
			break;
		case 0x04:
			SPK_FR=PT_MIN_VOL-Fad_factor;SPK_BR=PT_MIN_VOL;SPK_BL=PT_MIN_VOL-Bal_factor;
			SPK_FL=PT_MIN_VOL-Fad_factor_temp;//((Bal_factor+Fad_factor)>>1);
			break;
	}
}
void PT_2313_Balance_config(PT_CTRL_CMD PT_CMD)
{
	u8 SPK_FR_REG =0,SPK_FL_REG =0,SPK_RR_REG =0,SPK_RL_REG =0;
	if(PT_CMD ==PT_UP){
		if((PT_Balence_Val++)>=PT_TABLE_MAX)PT_Balence_Val =PT_TABLE_MAX;
	}
	else if(PT_CMD ==PT_DW){
		
		if((PT_Balence_Val--)==0)PT_Balence_Val =0;
	}
	
	get_audio_effect_para();

	if(PT_TABLE_MAX>14){

		SPK_FR_REG=SPK_FR/2;
		SPK_FL_REG=SPK_FL/2;
		SPK_RR_REG=SPK_BR/2;
		SPK_RL_REG=SPK_BL/2;
	}
	
	PT2313WriteByte(PT_2313_ADDR, BalanceTable[SPK_FR_REG]|PT_SPK_R_ADDR);
	PT2313WriteByte(PT_2313_ADDR, BalanceTable[SPK_FL_REG]|PT_SPK_L_ADDR);
#ifdef USE_REAR_CHANNEL
	PT2313WriteByte(PT_2313_ADDR, BalanceTable[SPK_RR_REG]|PT_REAR_R_ADDR);
	PT2313WriteByte(PT_2313_ADDR, BalanceTable[SPK_RL_REG]|PT_REAR_L_ADDR);	
#endif

	write_info(MEM_BAL,PT_Balence_Val);
#ifdef UART_ENABLE_PT2313
	printf(" PT_2313_Balance_config   -->PT_Balence_Val  %x \r\n",(u16)PT_Balence_Val);
#endif

}
void PT_2313_Fade_config(PT_CTRL_CMD PT_CMD)
{
	//u8 BAL_R =0,BAL_L =0;
	
	if(PT_CMD ==PT_UP){
		if((PT_Fade_Val++)>=PT_TABLE_MAX)PT_Fade_Val =PT_TABLE_MAX;
	}
	else if(PT_CMD ==PT_DW){
		
		if((PT_Fade_Val--)==0)PT_Fade_Val =0;
	}

	get_audio_effect_para();


	PT2313WriteByte(PT_2313_ADDR, BalanceTable[SPK_FR]|PT_SPK_R_ADDR);
	PT2313WriteByte(PT_2313_ADDR, BalanceTable[SPK_FL]|PT_SPK_L_ADDR);
#ifdef USE_REAR_CHANNEL
	PT2313WriteByte(PT_2313_ADDR, BalanceTable[SPK_BR]|PT_REAR_R_ADDR);
	PT2313WriteByte(PT_2313_ADDR, BalanceTable[SPK_BL]|PT_REAR_L_ADDR);	
#endif
	write_info(MEM_FADE,PT_Fade_Val);
	
#ifdef UART_ENABLE_PT2313
	printf(" PT_2313_Fade_config   -->PT_Fade_Val  %x \r\n",(u16)PT_Fade_Val);
#endif

}
void PT_2313_EQ_config(void)
{
	if(eq_mode==0)
	{
		PT2313WriteByte(PT_2313_ADDR,EQTable1[PT_Bass_Val]|PT_BASS_ADDR);
		PT2313WriteByte(PT_2313_ADDR,EQTable1[PT_Treble_Val]|PT_TRABLE_ADDR);
	}
	else
	{
		PT2313WriteByte(PT_2313_ADDR,PT_EQ_Table[eq_mode][0]);
		PT2313WriteByte(PT_2313_ADDR,PT_EQ_Table[eq_mode][1]);
	} 
#ifdef UART_ENABLE_PT2313
	printf(" PT_2313_EQ_config   -->eq_mode  %x \r\n",(u16)eq_mode);
#endif
}
void PT_2313_Vol_config(u8 PT_PARA)
{
#ifdef UART_ENABLE_PT2313		
#if defined(VOLUME_CUSTOMER_DEFINE_63)
	printf(" PT2313_Config -------> VOL_ADJ =%d DB \r\n",(u16)PT_PARA);

#else
	printf(" PT2313_Config PT_PARA =%d----> VOL_ADJ =%d DB \r\n",(u16)PT_PARA,(u16)VOL_Table[PT_PARA]);
#endif
#endif
#if 0
	if((PT_Mute_flag == PT_MUTE)&&(PT_PARA>0)){
		PT_Mute_flag = PT_UNMUTE;
		PT2313WriteByte(PT_2313_ADDR, PT_SPK_L_ADDR);						
		PT2313WriteByte(PT_2313_ADDR, PT_SPK_R_ADDR);
#ifdef USE_REAR_CHANNEL
		PT2313WriteByte(PT_2313_ADDR, PT_REAR_L_ADDR);						
		PT2313WriteByte(PT_2313_ADDR, PT_REAR_R_ADDR);	
#endif	
	}
#endif	

#if defined(VOLUME_CUSTOMER_DEFINE_63)
	PT2313WriteByte(PT_2313_ADDR, PT_MAIN_VOL_ADDR|(63-PT_PARA));
#else
	PT2313WriteByte(PT_2313_ADDR, PT_MAIN_VOL_ADDR|VOL_Table[PT_PARA]);
#endif
}
void PT_2313_sw_config(PT_CTRL_CMD PT_CMD)
{
	u8 reg_vol=0;
#if 1
	if((PT_Mute_flag == PT_UNMUTE)){


	if(PT_CMD ==PT_UP){
		if((PT_Subw_Val++)>=63)PT_Subw_Val =63;
	}
	else if(PT_CMD ==PT_DW){
		
		if((PT_Subw_Val--)==0)PT_Subw_Val =0;
	}
	
#if defined(VOLUME_CUSTOMER_DEFINE_63)
	reg_vol=63-PT_Subw_Val;
	reg_vol =reg_vol/2;
#else
	reg_vol=PT_Subw_Val;
#endif

#ifdef UART_ENABLE_PT2313		
	printf(" PT_2313_sw_config ----> PT_Subw_Val =%d DB \r\n",(u16)reg_vol);
#endif

#ifdef USE_REAR_CHANNEL_FOR_SUBWOOFER
		PT2313WriteByte(PT_2313_ADDR, PT_REAR_L_ADDR|reg_vol);						
		PT2313WriteByte(PT_2313_ADDR, PT_REAR_R_ADDR|reg_vol);	
#endif	

	}
#endif	

}

void PT_2313_mic_config(PT_CTRL_CMD PT_CMD)
{
#ifdef UART_ENABLE_PT2313		
	//printf(" PT2313_Config PT_PARA =%d----> VOL_ADJ =%d DB \r\n",(u16)PT_PARA,(u16)VOL_Table[PT_PARA]);
#endif

#ifdef SUPPORT_M62429
	if(PT_CMD ==PT_UP){		
		M62429_config_Data(ADJ_UP,CHAN_SEL_B,0xFF);
	}
	else if(PT_CMD ==PT_DW){	
		M62429_config_Data(ADJ_DOWN,CHAN_SEL_B,0xFF);		
	}
#endif
}
void PT_2313_echo_config(PT_CTRL_CMD PT_CMD)
{
#ifdef SUPPORT_M62429
	if(PT_CMD ==PT_UP){		
		M62429_config_Data(ADJ_UP,CHAN_SEL_A,0xFF);
	}
	else if(PT_CMD ==PT_DW){	
		M62429_config_Data(ADJ_DOWN,CHAN_SEL_A,0xFF);		
	}
#endif
}
void PT_2313_Mute_config(u8 PT_PARA)
{
	if(PT_PARA == PT_MUTE){
		PT_Mute_flag = PT_MUTE;
#ifdef USE_FRONT_CHANNEL				
		PT2313WriteByte(PT_2313_ADDR, PT_SPK_L_ADDR|0x1F);						
		PT2313WriteByte(PT_2313_ADDR, PT_SPK_R_ADDR|0x1F);			
#endif
#ifdef USE_REAR_CHANNEL
		PT2313WriteByte(PT_2313_ADDR, PT_REAR_L_ADDR|0x1F);						
		PT2313WriteByte(PT_2313_ADDR, PT_REAR_R_ADDR|0x1F);	
#endif				
	}
	else{
		PT_Mute_flag = PT_UNMUTE;
#ifdef USE_FRONT_CHANNEL				
		PT2313WriteByte(PT_2313_ADDR, PT_SPK_L_ADDR);						
		PT2313WriteByte(PT_2313_ADDR, PT_SPK_R_ADDR);
#endif
#ifdef USE_REAR_CHANNEL
		PT2313WriteByte(PT_2313_ADDR, PT_REAR_L_ADDR);						
		PT2313WriteByte(PT_2313_ADDR, PT_REAR_R_ADDR);	
#endif				
	}
}
void PT_2313_Chan_config(u8 PT_PARA)
{
	u8 reg_temp=0;
#ifdef UART_ENABLE_PT2313
	printf(" PT2313_Config   -->CHAN_ADJ  %x \r\n",(u16)PT_PARA);
#endif
#ifdef PT_2313_OUT_GAIN_11DB
	reg_temp = (PT_PATH_ADDR|0x00|PT_PARA);
#else
	reg_temp = (PT_PATH_ADDR|0x18|PT_PARA);
#endif
	if(!PT_Londness_Flag){

		reg_temp|=(PT_LOUDNESS_ADDR);
	}
	
	PT_Channel_Val = reg_temp;
			
	PT2313WriteByte(PT_2313_ADDR, PT_Channel_Val);
}
void PT2312_reset(void)
{

	PT_Treble_Val = PT_MIN_VOL;
	PT_Bass_Val = PT_MIN_VOL;
	my_music_vol= 25;
	PT_Subw_Val = 52;
	PT_Bass_Val = PT_MIN_VOL;
	
	PT2313_Config(0xFF,MUTE_ADJ);
	PT2313_Config(0xFF,TRELBE_ADJ);
	PT2313_Config(0xFF,BASS_ADJ);
	PT2313_Config(0xFF,SW_ADJ);	
	PT2313_Config(my_music_vol,VOL_ADJ);	
	
#ifdef SUPPORT_M62429
	M62429_Init();
#endif	

}
void PT2313_Init(void)
{	
#ifdef UART_ENABLE_PT2313
    	sys_printf("PT2313_Init .....");
#endif

 	PT2313WriteByte(PT_2313_ADDR,PT_SPK_L_ADDR);
	PT2313WriteByte(PT_2313_ADDR,PT_SPK_R_ADDR);

#ifdef USE_REAR_CHANNEL
 	PT2313WriteByte(PT_2313_ADDR,PT_REAR_L_ADDR);
	PT2313WriteByte(PT_2313_ADDR,PT_REAR_R_ADDR);
#endif

#ifdef SOUND_EFFECT_USE_EPPROM

#if 1
	PT_Bass_Val = read_info(MEM_BASE);
	PT_Balence_Val = read_info(MEM_BAL);
	PT_Treble_Val = read_info(MEM_TREB);
	PT_Fade_Val = read_info(MEM_FADE);
	PT_Subw_Val = read_info(MEM_SUBW);
#endif
	if(PT_Bass_Val>PT_MAX_VOL){PT_Bass_Val=PT_MIN_VOL;}
	if(PT_Balence_Val>PT_MAX_VOL){PT_Balence_Val=PT_MIN_VOL;}
	if(PT_Treble_Val>PT_MAX_VOL){PT_Treble_Val=PT_MIN_VOL;}
	if(PT_Fade_Val>14){PT_Fade_Val=PT_MIN_VOL;}
	if(PT_Subw_Val>63){PT_Subw_Val=52;}
	
#endif

	//eq_mode =0;
	PT_max_eq =((u8)((sizeof(PT_EQ_Table))/2)-1);

#ifdef UART_ENABLE_PT2313
	printf(" PT2313_Config   -->PT_max_eq  %x \r\n",(u16)PT_max_eq);
#endif


#ifdef K2081_DM_007_V001
	PT2312_reset();
#endif
	PT2313_Config(0xFF,MUTE_ADJ);
	PT2313_Config(0xFF,TRELBE_ADJ);
	PT2313_Config(0xFF,BASS_ADJ);
	PT2313_Config(0xFF,BAL_ADJ);
	PT2313_Config(0xFF,EQ_ADJ);
	
#ifdef USE_REAR_CHANNEL_FOR_SUBWOOFER
	PT2313_Config(0xFF,SW_ADJ);
#endif
#ifdef SUPPORT_M62429
	M62429_Init();
#endif	
}
void PT2313_Config(u8 PT_PARA,PT2313_CTRL PT_CMD)
{
	switch(PT_CMD)
		{
		case CHAN_ADJ:
			PT_2313_Chan_config(PT_PARA);
			break;
		case MUTE_ADJ:
			PT_2313_Mute_config(PT_PARA);
			break;	
		case VOL_ADJ:
			PT_2313_Vol_config(PT_PARA);
			break;
		case FADE_ADJ:
			PT_2313_Fade_config(PT_PARA);
			break;			
		case BAL_ADJ:
			PT_2313_Balance_config(PT_PARA);
			break;
		case BASS_ADJ:
			PT_2313_Bass_config(PT_PARA);
			break;
		case TRELBE_ADJ:
			PT_2313_Treble_config(PT_PARA);
			break;	
		case EQ_ADJ:			
			PT_2313_EQ_config();
			break;	
		case LOUD_ADJ:			
			PT_2313_Loudness_config();
			break;	
		case SW_ADJ:
			PT_2313_sw_config(PT_PARA);
			break;	
		case MIC_ADJ:
			PT_2313_mic_config(PT_PARA);
			break;	
		case ECHO_ADJ:
			PT_2313_echo_config(PT_PARA);
			break;				
		default:
			break;			
		}
}
#endif

