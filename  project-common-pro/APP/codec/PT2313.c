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

//#define  PT_DBG

#ifdef SUPPORT_PT2313
bool PT_Mute_flag = 0;
extern u8 eq_mode;
xd_u8 PT_Channel_Val = 0;
xd_u8  PT_Bass_Val=7;
xd_u8  PT_Treble_Val=7;
xd_u8  PT_Balence_Val=7;
xd_u8  PT_Fade_Val=7;

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
//const u8 EQDataTable[5][2]={
_code u8 PT_EQ_Table[6][2]={	
	{0x6f,0x7f},
	{0x6e,0x7c},
	{0x6f,0x7f},
	{0x6d,0x7b},
	{0x6b,0x7d},
	{0x68,0x78},	
};
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
	}
	else{
		PT_Channel_Val |=PT_LOUDNESS_ADDR;
	}

	PT2313WriteByte(PT_2313_ADDR, PT_Channel_Val);
}
void PT_2313_Treble_config(PT_CTRL_CMD PT_CMD)
{
	if(PT_CMD ==PT_UP){
		if((PT_Treble_Val++)>=PT_TABLE_MAX)PT_Treble_Val =PT_TABLE_MAX;
	}
	else if(PT_CMD ==PT_DW){
		
		if((PT_Treble_Val--)==0)PT_Treble_Val =0;
	}
		
	PT2313WriteByte(PT_2313_ADDR,EQTable1[PT_Treble_Val]|PT_TRABLE_ADDR);

	write_info(MEM_TREB,PT_Treble_Val);

#ifdef PT_DBG
	printf(" PT_2313_Treble_config   -->PT_Treble_Val  %d \r\n",(u16)PT_Treble_Val);
#endif
}
void PT_2313_Bass_config(PT_CTRL_CMD PT_CMD)
{
	if(PT_CMD ==PT_UP){
		if((PT_Bass_Val++)>=PT_TABLE_MAX)PT_Bass_Val =PT_TABLE_MAX;
	}
	else if(PT_CMD ==PT_DW){
		
		if((PT_Bass_Val--)==0)PT_Bass_Val =0;
	}
	
	PT2313WriteByte(PT_2313_ADDR,EQTable1[PT_Bass_Val]|PT_BASS_ADDR);

	write_info(MEM_BASE,PT_Bass_Val);

#ifdef PT_DBG
	printf(" PT_2313_Bass_config   -->PT_Bass_Val  %d \r\n",(u16)PT_Bass_Val);
#endif
	
}
u8 SPK_FR=7,SPK_FL=7,SPK_BR=7,SPK_BL=7;
void get_audio_effect_para()
{
	u8 Fad_factor =0,Bal_factor=0,Fad_factor_temp=0;
	u8 cord_location =0;
	
	if((PT_Balence_Val>=7)&&(PT_Fade_Val>=7)){
		
		cord_location  = 0x01;
		
		Fad_factor = PT_Fade_Val-7;
		Bal_factor = PT_Balence_Val-7;
	}
	else if((PT_Balence_Val<=7)&&(PT_Fade_Val>=7)){

		cord_location  = 0x02;
		
		Fad_factor = PT_Fade_Val-7;
		Bal_factor = 7-PT_Balence_Val;
	}
	else if((PT_Balence_Val<=7)&&(PT_Fade_Val<=7)){

		cord_location  = 0x03;
		
		Fad_factor = 7-PT_Fade_Val;
		Bal_factor = 7-PT_Balence_Val;
	}
	else if((PT_Balence_Val>=7)&&(PT_Fade_Val<=7)){

		cord_location  = 0x04;
		
		Fad_factor = 7- PT_Fade_Val;
		Bal_factor = PT_Balence_Val - 7;
	}

	if((Fad_factor == 7)||(Bal_factor==7)){

		Fad_factor_temp = 7;
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
			SPK_FR=7;SPK_FL=7-Bal_factor;SPK_BR=7-Fad_factor;
			SPK_BL=7-Fad_factor_temp;//((Bal_factor+Fad_factor)>>1);
			break;
		case 0x02:
			SPK_FR=7-Bal_factor;SPK_FL=7;SPK_BL=7-Fad_factor;
			SPK_BR=7-Fad_factor_temp;//((Bal_factor+Fad_factor)>>1);
			break;		
		case 0x03:
			SPK_FL=7-Fad_factor;SPK_BR=7-Bal_factor;SPK_BL=7;
			SPK_FR=7-Fad_factor_temp;//((Bal_factor+Fad_factor)>>1);
			break;
		case 0x04:
			SPK_FR=7-Fad_factor;SPK_BR=7;SPK_BL=7-Bal_factor;
			SPK_FL=7-Fad_factor_temp;//((Bal_factor+Fad_factor)>>1);
			break;
	}
}
void PT_2313_Balance_config(PT_CTRL_CMD PT_CMD)
{
	u8 BAL_R =0,BAL_L =0;
	if(PT_CMD ==PT_UP){
		if((PT_Balence_Val++)>=PT_TABLE_MAX)PT_Balence_Val =PT_TABLE_MAX;
	}
	else if(PT_CMD ==PT_DW){
		
		if((PT_Balence_Val--)==0)PT_Balence_Val =0;
	}
	
	get_audio_effect_para();
		
	PT2313WriteByte(PT_2313_ADDR, BalanceTable[SPK_FR]|PT_SPK_R_ADDR);
	PT2313WriteByte(PT_2313_ADDR, BalanceTable[SPK_FL]|PT_SPK_L_ADDR);
#ifdef USE_REAR_CHANNEL
	PT2313WriteByte(PT_2313_ADDR, BalanceTable[SPK_BR]|PT_REAR_R_ADDR);
	PT2313WriteByte(PT_2313_ADDR, BalanceTable[SPK_BL]|PT_REAR_L_ADDR);	
#endif

	write_info(MEM_BAL,PT_Balence_Val);
#ifdef PT_DBG
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
	
#ifdef PT_DBG
	printf(" PT_2313_Balance_config   -->PT_Balence_Val  %x \r\n",(u16)PT_Balence_Val);
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
#ifdef PT_DBG
	printf(" PT_2313_EQ_config   -->eq_mode  %x \r\n",(u16)eq_mode);
#endif
}
void PT_2313_Vol_config(u8 PT_PARA)
{
#ifdef PT_DBG		
	printf(" PT2313_Config PT_PARA =%d----> VOL_ADJ =%d DB \r\n",(u16)PT_PARA,(u16)VOL_Table[PT_PARA]);
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
	PT2313WriteByte(PT_2313_ADDR, PT_MAIN_VOL_ADDR|VOL_Table[PT_PARA]);
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
#ifdef PT_DBG
	printf(" PT2313_Config   -->CHAN_ADJ  %x \r\n",(u16)PT_PARA);
#endif
#ifdef PT_2313_OUT_GAIN_11DB
	reg_temp = (PT_PATH_ADDR|0x00|PT_PARA);
#else
	reg_temp = (PT_PATH_ADDR|0x18|PT_PARA);
#endif
	if(!PT_Londness_Flag)reg_temp|=PT_LOUDNESS_ADDR;
	PT_Channel_Val = reg_temp;
			
	PT2313WriteByte(PT_2313_ADDR, PT_Channel_Val);
}
void PT2313_Init(void)
{	
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
#endif
	if(PT_Bass_Val>14){PT_Bass_Val=7;}
	if(PT_Balence_Val>14){PT_Balence_Val=7;}
	if(PT_Treble_Val>14){PT_Treble_Val=7;}
	if(PT_Fade_Val>14){PT_Fade_Val=7;}
	
#endif
	PT2313_Config(0xFF,MUTE_ADJ);
	PT2313_Config(0xFF,TRELBE_ADJ);
	PT2313_Config(0xFF,BASS_ADJ);
	PT2313_Config(0xFF,BAL_ADJ);
	PT2313_Config(0xFF,EQ_ADJ);
	
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
		default:
			break;			
		}
}
#endif

