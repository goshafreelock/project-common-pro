//*********************************************************
//  File Name: KT_AMFMdrv.c
//  Function:  KT AM-FM products driver for customer
//  Rev:       3.9
//  Date:      2011/03/03
//*********************************************************
//        Revision History
//  Version	Date		Description
//  V1.0	2010-01-31	Initial draft.
//	V2.0	2010-05-07	Initial draft for KT0913.
//  V2.1	2010-05-21	Disable the feature of fast gain up in baseband AGC in KT_AMTune function.
//  V2.2	2010-05-25	Modified the "KT_FMGetSNR" function.
//  V2.3	2010-05-27	A pre-compile option DISABLE_FAST_GAIN_UP is added.
//						A pre-compile option AMSMUTE is added.
//  V2.4    2010-06-01	Modify the AGC_FAST_WIN<1:0> to 00 (fastest) in  KT_AMFMInit() function
//						Modify the KT0913_SwitchMode () in main.c to preserve channel when switching band.
//  V2.5    2010-07-20	A pre-compile option LOWFM_MODE is added.
//  V2.6    2010-07-22	A pre-compile option MANUAL_SEPARATION is added.
//						A patch about RFAGC is added in KT_AMFMInit function.
//  V2.7    2010-07-23	A pre-compile option AM_SOFTMUTE is added.
//  V2.8    2010-07-27	A pre-compile option FM_SOFTMUTE is added.
//						KT_AM_TUNING_LIGHT function is added.
//						KT_FM_TUNING_LIGHT function is added.
//						Fixed a bug about AM SOFTMUTE in main.c when switching band.
//  V2.9    2010-08-03	A pre-compile option AM_GAIN is added.
//  V3.0    2010-08-04	Modified the "KT_AMSetBW" function.
//  V3.1    2010-08-06	Fixed the define of I2C address in KT_AMFMdrv.h.
//						Clean up.
//  V3.2    2010-08-17	Modified the KT_FM_SOFTMUTE_SETTING function.
//	V3.3	2010-08-27	Added the "KT_FM_ST_Indicator()" function.
//						A pre-compile option AUDIO_LEVEL_BOOST is added.
//	V3.4	2010-09-09	Added the pre-compile option of X32P768K, R32P768K, X38K, R38K, R7P6M, R13M, R24M and R26M.
//	V3.5	2010-10-16	Added the pre-compile option of "AM_ABC"(Automatic Bandwidth Control).
//	V3.6	2010-11-11	Added the pre-compile option of "FM_HIGHLEVER_RF_SIGAL_INPUT".
//						Modified the "KT_AM_SOFTMUTE" and "KT_FM_SOFTMUTE" function.
//	V3.7	2010-11-17	Modified the "KT_FMTune", "KT_AMTune", "KT_FMGetFreq" and "KT_AMGetFreq" function.
//	V3.8	2010-12-09	Modified the "KT_FMTune", "KT_AMFMSetMode" and "KT_FMGetFreq" function..
//						Added the pre-compile option of "AM_SOFTMUTE_AFCMODE".
//	V3.9	2011-03-03	Clean up.
//						Added the SW mode for KT0915. Added the pre-compile option of "KT0915".

#include "Custom_config.h"
#include "KT_AMFMdrv.h"
#include "iic.h"



#if defined(FM_USE_KT0913)
//global variables
xd_u8 mem_afc[3];			  //Rememberred afc values for previous, current and next stations
xd_u16 mem_freq[3];			  //Rememberred channel frequencies for previous, current and next stations
//xd_u8 mem_vol;				  //Rememberred volume before mute
#ifdef SEEK_WITH_SNR
xd_u8 mem_snr[3];			  //Rememberred SNR values for previous, current and next stations
#endif

#define I2C
#ifdef I2C

void I2C_Word_Write(u8 device_address, u8 reg_add, u16 writedata)
{
#if 1
	xd_u8 write_reg_data[2]={0};

	write_reg_data[1]=(u8)(writedata&0x00FF);
	write_reg_data[0]=(u8)(writedata>>8);
	
	iic_write((device_address),reg_add,&write_reg_data,2);
#else
	I2C_Start();
	I2C_Senddata(device_address & 0xFE);
	I2C_Ack();
	if (Ack_Flag == 0)
	{
		I2C_Senddata(reg_add);
		I2C_Ack();
		if (Ack_Flag == 0)
		{
			I2C_Senddata(writedata);
			I2C_Ack();
		}
		else
			SCL = 0;			
	}
	else
		SCL = 0;
	I2C_Stop();
#endif	
	
}

//------------------------------------------------------------------------------------
//I2C Read Byte
//------------------------------------------------------------------------------------
u16 I2C_Word_Read(u8 device_address, u8 reg_add)
{
	xd_u16 readdata;

#if 1
    iic_start();                    //I2C∆Ù∂Ø
    iic_sendbyte((device_address));             //–¥√¸¡Ó
    iic_sendbyte(reg_add);         //–¥µÿ÷∑
    iic_start();                    //–¥◊™Œ™∂¡√¸¡Ó£¨–Ë“™‘Ÿ¥Œ∆Ù∂ØI2C
    iic_sendbyte((device_address|0x01));             //∂¡√¸¡Ó
    readdata = iic_revbyte(0);
    readdata=readdata<<8;
    readdata |= iic_revbyte(1);
    iic_stop();                     //I2CÕ£÷π
#else
	iic_start();
	IiC_Senddata(device_address & 0xFE);
	I2C_Ack();
	if (Ack_Flag == 0)	//7.12 edit
	{
		I2C_Senddata(reg_add);
		I2C_Ack();
		if (Ack_Flag == 0)	//7.12 edit
		{
			I2C_Start();
			I2C_Senddata(device_address | 0x01);
			I2C_Ack();
			if (Ack_Flag == 0)
			{
//	SDA pin is high Z
				readdata = I2C_Receivedata();
				I2C_Ack();
			}
			else
			{
				SCL=0;
				return(0x00);
			}
		}
		else
		{
			SCL = 0;
		 	return(0x00);
		}			
	}
	else
	{
		SCL = 0;
		return(0x00);
	}

	I2C_Stop();	
#endif	
	return(readdata);
}
#endif
void KT_Bus_Write(u8 Register_Address, u16 Word_Data)
{
#ifdef SPI3
	SPI_Write(Register_Address,Word_Data);
#endif
#ifdef I2C
	I2C_Word_Write(KTAMw_address,Register_Address,Word_Data);
#endif
}

u16 KT_Bus_Read(u8 Register_Address)
{
#ifdef SPI3
	return( SPI_Read_3wire(Register_Address) );
#endif
#ifdef I2C
	return( I2C_Word_Read(KTAMw_address, Register_Address) );
#endif
}

u8 KT_AMFMPreInit(void)			  
//This function should be called just after power-up (within 50ms) when crystal is used
//or before reference clock is applied
{
	//xd_u16 regx;
	//mem_vol= 30;
	
#ifdef X32P768K
	KT_Bus_Write(0x16, 0x0002);       				//reference clock=32.768K; XTALD=0
#endif

#ifdef R32P768K
	KT_Bus_Write(0x16, 0x1002);       				//reference clock=32.768K; XTALD=1
#endif

#ifdef X38K
	KT_Bus_Write(0x16, 0x0902);       				//reference clock=38K; XTALD=0
#endif

#ifdef R38K
	KT_Bus_Write(0x16, 0x1902);       				//reference clock=38K; XTALD=1
#endif

#ifdef R7P6M
	KT_Bus_Write(0x16, 0x1202);       				//reference clock=7.6M; XTALD=1
#endif

#ifdef R12M
	KT_Bus_Write(0x16, 0x1302);       				//reference clock=12M; XTALD=1
#endif

#ifdef R13M
	KT_Bus_Write(0x16, 0x1402);       				//reference clock=13M; XTALD=1
#endif

#ifdef R24M
	KT_Bus_Write(0x16, 0x1702);       				//reference clock=24M; XTALD=1
#endif

#ifdef R26M
	KT_Bus_Write(0x16, 0x1802);       				//reference clock=26M; XTALD=1
#endif

#ifdef R12288KHz
	regx = KT_Bus_Read(0x16);
	KT_Bus_Write(0x16, regx | 0x1000);				//XTALD=1
	regx = KT_Bus_Read(0x16);
	KT_Bus_Write(0x16, regx | 0x2000);				//CTCLK=1
	regx = KT_Bus_Read(0x1E);
	KT_Bus_Write(0x1E, regx & 0x0000 | 0x0140);		//DIVIDERP<9:0>=320
	regx = KT_Bus_Read(0x1F);
	KT_Bus_Write(0x1F, regx & 0x0000 | 0x023A);		//DIVIDERN<9:0>=570
#endif
	return(1);
}
u16 KT_AMFM_Read_ID(void)
{
	xd_u16 regx=0;

	regx=KT_Bus_Read(0x01);           			//Read Manufactory ID 

	//printf("-->KT_AMFM_Read_ID  %x \r\n ",(u16)regx);

	return regx;
}
u8 KT_AMFMInit(void)                            //0->Fail 1->Success
{
	xd_u16 regx;
	xd_u8 i;

	KT_AMFMPreInit();
	
	regx=KT_Bus_Read(0x0F);
	KT_Bus_Write(0x0F, regx&0xe000);			//Write Standby bit to 0
	
	for (i=0;i<INIT_FAIL_TH;i++)
	{
 		delay_10ms(50);
		regx=KT_Bus_Read(0x12);						//Read power-up indicator
		if ((regx&0x8000)!=0x8000) continue;
		break;
	}
	if (i==INIT_FAIL_TH) return(0);
	KT_Bus_Write(0x10,0x6000);						// re-cali
	regx=KT_Bus_Read(0x0a);
	KT_Bus_Write(0x0a, regx & 0xFEFF);      		//Turn On FM AFC function
	regx=KT_Bus_Read(0x22);
	KT_Bus_Write(0x22, regx & 0xFCFF | 0x0200);		//AM AGC short win=slowest

	regx=KT_Bus_Read(0x0A);
	KT_Bus_Write(0x0a, regx | 0x0400);      		//LO_LDO= highest

	regx=KT_Bus_Read(0x22);
	KT_Bus_Write(0x22, regx & 0xF3FF);      		//AGC_FAST_WIN<1:0>=00(fastest)

	regx=KT_Bus_Read(0x23);
	KT_Bus_Write(0x23,regx | 0x1C00);				//Low_TH_B<2:0>=111
	regx=KT_Bus_Read(0x05);
	KT_Bus_Write(0x05, regx | 0x0800);				//De_emphasis time = 50us

#ifdef LOWFM_MODE
	regx=KT_Bus_Read(0x0C);
	KT_Bus_Write(0x0C, regx | 0x0008);      		//LOWFM_MODE=1(32MHz-110MHz)
#endif

	regx=KT_Bus_Read(0x3F);
	KT_Bus_Write(0x3F, regx & 0xFF88 | 0x0013);		// RFAGC Patch

#ifdef AM_GAIN
	regx = KT_Bus_Read(0x22);
	KT_Bus_Write(0x22, (regx & 0xFFCF) | 0x0020 );	// AM_GAIN = 12dB
#endif

#ifdef AUDIO_LEVEL_BOOST
	regx = KT_Bus_Read(0x16);
	KT_Bus_Write(0x16, (regx & 0xFF3F) | 0x0040 );	// AU_GAIN = 6dB
#endif

#ifdef FM_HIGHLEVER_RF_SIGAL_INPUT
	regx = KT_Bus_Read(0x09);
	KT_Bus_Write(0x09, (regx & 0xFCFF));			//
#endif

//	regx = KT_Bus_Read(0x0A);
//	KT_Bus_Write(0x0A, (regx | 0x6000));			//

//	regx = KT_Bus_Read(0x16);
//	KT_Bus_Write(0x16, (regx | 0x0001));			//

	return(1);
}

u8 KT_AMFMSetMode(u8 AMFM_MODE)
{
	xd_u16 regx;
	if (AMFM_MODE==FM_MODE)
	{
		regx=KT_Bus_Read(0x16);
		KT_Bus_Write(0x16,regx & 0x7FFF);				//AM_FM=0
	}
	else
	{
		regx=KT_Bus_Read(0x16);
		KT_Bus_Write(0x16,regx | 0x8000);				//AM_FM=1

		KT_Bus_Write(0x18,0x0000);			// Enable  
//		KT_Bus_Write(0x18,0x8000);			//cali_dis=1; osc_en=0; cap=0;
	}
	return(1);
}

u8 KT_AMSetBW(u8 AMBW)				//AM Channel Bandwidth=2 for 2KHz; 4 for 4KHz; 6 for 6KHz
{
	xd_u16 regx;
	regx=KT_Bus_Read(0x22);
	if (AMBW==2) KT_Bus_Write(0x22, (regx & 0xFF3F) | 0x0000);
	else if (AMBW==4) KT_Bus_Write(0x22, (regx & 0xFF3F) | 0x0080);
	else if (AMBW==6) KT_Bus_Write(0x22, (regx & 0xFF3F) | 0x00C0);
	else return(0);
	return(1);
}

u8 KT_AMFMStandby(void)					//0->Fail 1->Success
{
	xd_u16 regx;
	regx=KT_Bus_Read(0x0F);
	KT_Bus_Write(0x0F, regx | 0x1000);		//Write Standby bit to 1
	delay_10ms(2);
	return(1);
}

u8 KT_AMFMWakeUp(void) //0->Fail 1->Success
{
	xd_u16 regx;
	regx=KT_Bus_Read(0x0F);
	KT_Bus_Write(0x0F, regx&0xeFFF);			//Write Standby bit to 0
	return (KT_AMFMInit());
}

u8 KT_AMFMVolumeSet(u8 vol)			//Input: 0~31
{
	xd_u16 regx;
	//mem_vol=vol;
	regx=KT_Bus_Read(0x0F); 
	KT_Bus_Write(0x0F, regx & 0xFFE0 | vol);
	return(1);
}

u8 KT_AMFMMute(void)
{
	u16 regx;
	regx = KT_Bus_Read(0x0F);       
	KT_Bus_Write(0x0F, regx & 0xFFE0 );		//Write volume to 0
	return(1);
}

u8 KT_AMFMUnMute(void)
{
	u16 regx;
	regx=KT_Bus_Read(0x0f); 
	KT_Bus_Write(0x0f, regx & 0xFFE0 | 0x1f); 
	return(1);
}
void KT_Mute_Ctrl(bool m_f)
{
	u16 regx;

	regx = KT_Bus_Read(0x0F);       
	if(m_f){
		KT_Bus_Write(0x0F, regx & 0xFFE0 );		//Write volume to 0
	}
	else{
		KT_Bus_Write(0x0f, regx & 0xFFE0 | 0x1F); 
	}
}
#ifdef C32P768K
/*
u8 KT_FMTune(u16 Frequency) //87.5MHz-->Frequency=8750; Mute the chip and Tune to Frequency
{
	u16 reg3,regA;

	KT_AMFMMute();

	regA=KT_Bus_Read(0x0A);
	if((Frequency ==10230) || (Frequency == 10240))
	{
		KT_Bus_Write(0x0A, regA | 0x0040);
	}
	else
	{
		KT_Bus_Write(0x0A, regA & 0xFFBF);
	}
	reg3=KT_Bus_Read(0x03);
	KT_Bus_Write(0x03, (reg3 & 0xF000) | 0x8000 | (Frequency/5));	   		//set tune bit to 1

	delay_10ms(50);
	return(1);
}
*/

u8 KT_FMTune(u16 Frequency) //87.5MHz-->Frequency=8750; Mute the chip and Tune to Frequency
{
	u16 reg3,reg16;

	KT_AMFMMute();

	reg3=KT_Bus_Read(0x03);
	if((Frequency ==10230) || (Frequency == 10240)|| (Frequency == 10520))
	{
		KT_Bus_Write(0x1E, 0x0001);								//DIVIDERP<9:0>=1
		KT_Bus_Write(0x1F, 0x029B);								//DIVIDERN<9:0>=667
		reg16 = KT_Bus_Read(0x16);
		KT_Bus_Write(0x16, (reg16 & 0xD0FF) | 0x2000);			//CTCLK=1;reference clock=32.768K;
		KT_Bus_Write(0x03, 0x8000 | (Frequency+15)/5 );	   		//set tune bit to 1
	}
	else if((Frequency ==9860))
	{
		KT_Bus_Write(0x1E, 0x0001);								//DIVIDERP<9:0>=1
		KT_Bus_Write(0x1F, 0x029D);								//DIVIDERN<9:0>=669
		reg16 = KT_Bus_Read(0x16);
		KT_Bus_Write(0x16, (reg16 & 0xD0FF) | 0x2000);			//CTCLK=1;reference clock=32.768K;
		KT_Bus_Write(0x03, 0x8000 | (Frequency-15)/5 );	   		//set tune bit to 1
	}
	else if((Frequency ==8780))
	{
		KT_Bus_Write(0x1E, 0x0001);								//DIVIDERP<9:0>=1
		KT_Bus_Write(0x1F, 0x029E);								//DIVIDERN<9:0>=670
		reg16 = KT_Bus_Read(0x16);
		KT_Bus_Write(0x16, (reg16 & 0xD0FF) | 0x2000);			//CTCLK=1;reference clock=32.768K;
		KT_Bus_Write(0x03, 0x8000 | (Frequency-25)/5 );	   		//set tune bit to 1
	}
	else if((Frequency ==4380) || (Frequency == 4390))
	{
		KT_Bus_Write(0x1E, 0x0001);								//DIVIDERP<9:0>=1
		KT_Bus_Write(0x1F, 0x029F);								//DIVIDERN<9:0>=671
		reg16 = KT_Bus_Read(0x16);
		KT_Bus_Write(0x16, (reg16 & 0xD0FF) | 0x2000);			//CTCLK=1;reference clock=32.768K;
		KT_Bus_Write(0x03, 0x8000 | (Frequency-20)/5 );	   		//set tune bit to 1
	}
	else if((Frequency ==5260) || (Frequency == 5850))
	{
		KT_Bus_Write(0x1E, 0x0001);								//DIVIDERP<9:0>=1
		KT_Bus_Write(0x1F, 0x029E);								//DIVIDERN<9:0>=670
		reg16 = KT_Bus_Read(0x16);
		KT_Bus_Write(0x16, (reg16 & 0xD0FF) | 0x2000);			//CTCLK=1;reference clock=32.768K;
		KT_Bus_Write(0x03, 0x8000 | (Frequency-15)/5 );	   		//set tune bit to 1
	}
	else if((Frequency ==6570) || (Frequency == 6580) || (Frequency == 6590) || (Frequency == 7310)|| (Frequency == 7890))
	{
		KT_Bus_Write(0x1E, 0x0001);								//DIVIDERP<9:0>=1
		KT_Bus_Write(0x1F, 0x029A);								//DIVIDERN<9:0>=666
		reg16 = KT_Bus_Read(0x16);
		KT_Bus_Write(0x16, (reg16 & 0xD0FF) | 0x2000);			//CTCLK=1;reference clock=32.768K;
		KT_Bus_Write(0x03, 0x8000 | (Frequency+20)/5 );	   		//set tune bit to 1
	}
	else
	{
		KT_Bus_Write(0x1E, 0x0001);								//DIVIDERP<9:0>=1
		KT_Bus_Write(0x1F, 0x029C);								//DIVIDERN<9:0>=668
		reg16 = KT_Bus_Read(0x16);
		KT_Bus_Write(0x16, 	reg16 & 0xD0FF);       				//reference clock=32.768K;
		KT_Bus_Write(0x03, 0x8000 | (Frequency/5) );	   		//set tune bit to 1
	}
	delay_10ms(1);

	KT_AMFMUnMute();


	return(1);
}

u8 KT_MWTune(u16 Frequency) //1710KHz --> Frequency=1710; Mute the chip and Tune to Frequency
{
	u16 reg16,reg23;
	KT_AMFMMute();

#ifdef DISABLE_FAST_GAIN_UP
	reg23=KT_Bus_Read(0x23);
	KT_Bus_Write(0x23, reg23 & 0xDFFF);							//Enable fast gain function
#endif

/*	if((Frequency ==1368) || (Frequency ==1404))
	{
		KT_Bus_Write(0x1F, 0x029D);								//DIVIDERN<9:0>=669
		KT_Bus_Write(0x17, 0x8000 | (Frequency-2));	   			//set tune bit to 1
	}
*/
	if(Frequency ==1370)
	{
		KT_Bus_Write(0x1E, 0x0001);								//DIVIDERP<9:0>=1
		KT_Bus_Write(0x1F, 0x029F);								//DIVIDERN<9:0>=671
		reg16 = KT_Bus_Read(0x16);
		KT_Bus_Write(0x16, (reg16 & 0xD0FF) | 0x2000);			//CTCLK=1;reference clock=32.768K;
		KT_Bus_Write(0x17, 0x8000 | (Frequency-6));	   			//set tune bit to 1
	}
	else if((Frequency ==1368) || (Frequency ==1370) || (Frequency ==1404))
	{
		KT_Bus_Write(0x1E, 0x0001);								//DIVIDERP<9:0>=1
		KT_Bus_Write(0x1F, 0x029E);								//DIVIDERN<9:0>=670
		reg16 = KT_Bus_Read(0x16);
		KT_Bus_Write(0x16, (reg16 & 0xD0FF) | 0x2000);			//CTCLK=1;reference clock=32.768K;
		KT_Bus_Write(0x17, 0x8000 | (Frequency-4));	   			//set tune bit to 1
	}
	else if(Frequency ==1629)
	{
		KT_Bus_Write(0x1E, 0x0001);								//DIVIDERP<9:0>=1
		KT_Bus_Write(0x1F, 0x029E);								//DIVIDERN<9:0>=670
		reg16 = KT_Bus_Read(0x16);
		KT_Bus_Write(0x16, (reg16 & 0xD0FF) | 0x2000);			//CTCLK=1;reference clock=32.768K;
		KT_Bus_Write(0x17, 0x8000 | (Frequency-5));	   			//set tune bit to 1
	}
	else
	{
		KT_Bus_Write(0x1E, 0x0001);								//DIVIDERP<9:0>=1
		KT_Bus_Write(0x1F, 0x029C);								//DIVIDERN<9:0>=668
		reg16=KT_Bus_Read(0x16);
		KT_Bus_Write(0x16, 	reg16 & 0xD0FF);       				//reference clock=32.768K;
		KT_Bus_Write(0x17, 0x8000 | Frequency);	   				//set tune bit to 1
	}
	delay_10ms(1);
	KT_AMFMUnMute();

#ifdef DISABLE_FAST_GAIN_UP
	reg23=KT_Bus_Read(0x23);
	KT_Bus_Write(0x23, reg23 & 0xDFFF | 0x2000);				//disable the function of fast up in baseband AGC, by chend, 2010-05-21
#endif

	return(1);
}
#if 0
u16 KT_FMGetFreq(void)
{
	u16 reg1F,regx;
	reg1F=KT_Bus_Read(0x1F);
	if(reg1F == 0x029B)
	{
		regx= KT_Bus_Read(0x13);
		return( regx*5 - 15 );
	}
	else if(reg1F == 0x029D)
	{
		regx= KT_Bus_Read(0x13);
		if( (regx*5) == 9845 )
		{
			return( regx*5 + 15 );
		}
		else
		{
			return( regx*5 + 10 );
		}
	}
	else if(reg1F == 0x029E)
	{
		regx= KT_Bus_Read(0x13);
		if( (regx*5) ==8755)
		{
			return( regx*5 + 25 );
		}
		else if(((regx*5) ==6550) || ((regx*5) == 6560) || ((regx*5) == 6570) || ((regx*5) == 7290) || ((regx*5) == 7870) )
		{
			return(regx*5 + 20);
		}

		else
		{
			return( regx*5 + 15 );
		}
	}
	else if(reg1F == 0x029A)
	{
		regx= KT_Bus_Read(0x13);
		return(regx*5 - 20);
	}

	else if(reg1F == 0x029F)
	{
		regx= KT_Bus_Read(0x13);
		return( regx*5 + 20 );
	}
	else
	{
		regx= KT_Bus_Read(0x13);
		return( regx*5 );
	}
}

u16 KT_AMGetFreq(void)
{
	u16 reg1F,regx;
	reg1F=KT_Bus_Read(0x1F);
	if(reg1F == 0x029E)
	{
		regx= KT_Bus_Read(0x13);
		if(regx==1624)
		{
			return( regx  + 5 );
		}
		else
		{
			return( regx  + 4 );
		}
	}
	else if(reg1F == 0x029F)
	{
		regx= KT_Bus_Read(0x13);
		return( regx  + 6 );
	}
	else
	{
		regx= KT_Bus_Read(0x13);
		return( regx );
	}
}
#endif
#else
u8 KT_FMTune(u16 Frequency) //87.5MHz-->Frequency=8750; Mute the chip and Tune to Frequency
{
	u16 reg3;

	KT_AMFMMute();

	reg3=KT_Bus_Read(0x03);
	KT_Bus_Write(0x03, 0x8000 | (Frequency/5) );	   		//set tune bit to 1

	delay_10ms(5);
	KT_AMFMUnMute();

	
	return(1);
}

u8 KT_MWTune(u16 Frequency) //1710KHz --> Frequency=1710; Mute the chip and Tune to Frequency
{

	KT_AMFMMute();

#ifdef DISABLE_FAST_GAIN_UP
	reg23=KT_Bus_Read(0x23);
	KT_Bus_Write(0x23, reg23 & 0xDFFF);							//Enable fast gain function
#endif

	KT_Bus_Write(0x17, 0x8000 | Frequency);	   				//set tune bit to 1
	delay_10ms(10);

#ifdef DISABLE_FAST_GAIN_UP
	reg23=KT_Bus_Read(0x23);
	KT_Bus_Write(0x23, reg23 & 0xDFFF | 0x2000);				//disable the function of fast up in baseband AGC, by chend, 2010-05-21
#endif
	KT_AMFMUnMute();

	return(1);
}

u16 KT_FMGetFreq(void)
{
	u16 regx;
	regx= KT_Bus_Read(0x13);
	return( regx * 5 );
}

u16 KT_AMGetFreq(void)
{
	xd_u16 reg1F,regx;
	reg1F=KT_Bus_Read(0x1F);
	if(reg1F == 0x029D)
	{
		regx= KT_Bus_Read(0x13);
		return( regx + 2 );
	}
	else if(reg1F == 0x029E)
	{
		regx= KT_Bus_Read(0x13);
		return( regx  + 5 );
	}
	else
	{
		regx= KT_Bus_Read(0x13);
		return( regx );
	}
}
#endif

#ifdef KT0915
u8 KT_SWTune(u16 Frequency) //1710KHz --> Frequency=1710; Mute the chip and Tune to Frequency
{
	xd_u16 reg16,reg23;
	KT_AMFMMute();

#ifdef DISABLE_FAST_GAIN_UP
	reg23=KT_Bus_Read(0x23);
	KT_Bus_Write(0x23, reg23 & 0xDFFF);							//Enable fast gain function
#endif

	KT_Bus_Write(0x17, 0x8000 | Frequency);	   				//set tune bit to 1
	KT_Bus_Write(0x17, 0x8000 | Frequency);	   				//set tune bit to 1
	delay_10ms(10);

#ifdef DISABLE_FAST_GAIN_UP
	reg23=KT_Bus_Read(0x23);
	KT_Bus_Write(0x23, reg23 & 0xDFFF | 0x2000);				//disable the function of fast up in baseband AGC, by chend, 2010-05-21
#endif

	return(1);
}
#endif
#if 0
u8 KT_FMGetST(void)
{
	xd_u16 regx;

	regx= KT_Bus_Read(0x06);

	//printf("-->KT_FMGetST  %x \r\n ",(u16)(regx&0x7F00));
	
	return ((regx&0x7F00)<TST_TH);
}

u8 KT_FMReadRSSI(char *RSSI) //range from -100 to -6, unit is dbm
{
	xd_u16 regx;
	regx = KT_Bus_Read(0x12);
	*RSSI=-(100 - ( ( ( regx >> 3 ) & 0x001F ) * 3 ));
	return(1);
}

u8 KT_AMReadRSSI(char *RSSI) //range from -90 to -6, unit is dbm
{
	xd_u16 regx;
	regx = KT_Bus_Read(0x24);
	*RSSI=-(90 - ( ( ( regx >> 8 ) & 0x001F ) * 3 ));
	return(1);
}
#endif
u8 KT_FMGetSNR(void)
{
	xd_u16 regx;
	regx = KT_Bus_Read( 0x14 );
//	regx = (regx & 0x1FC0) >> 6;
//	regx = regx <<1;
	return( (regx & 0x1FC0) >> 5);								// 1)SNR>>6 2)SNR<<1
}
#if 0
u8 KT_FMSeekFromCurrentCh(u16 seekDir, u16 *Frequency)   //     seekDir: 0-->seek down 1-->seek up
{
	xd_u16 NextFreq;
	mem_afc[0]=0;mem_afc[1]=0;mem_afc[2]=0;
	mem_freq[0]=0;mem_freq[1]=0;mem_freq[2]=0;
	if (seekDir==SEEKUP)
	{
		if ((*Frequency)==SEEK_UP_LIMIT)		//if current channel reaches 108MHz, then start seeking from 87.5MHz
			NextFreq=SEEK_DOWN_LIMIT;
		else									//else start from 100KHz after current channel
			NextFreq=(*Frequency)+CHANNEL_STEP;
		while (1)
		{
			if (KT_FMValidStation(NextFreq))	//if nextfreq is a true channel, then stop seeking and return seek success
			{
				*Frequency=NextFreq;
				return(1);
			}
			else
			{
				if (NextFreq==SEEK_UP_LIMIT)	//if current channel reach 108MHz, then stop seeking and return seek fail
				{
					*Frequency=NextFreq;
					return(0);
				}
				NextFreq+=CHANNEL_STEP;			//Try next channel
			}
		}
	}
	else
	{
		if ((*Frequency)==SEEK_DOWN_LIMIT)		//if current channel reaches 87.5MHz, then start seeking from 108MHz
			NextFreq=SEEK_UP_LIMIT;
		else									//else start from 100KHz before current channel
			NextFreq=(*Frequency)-CHANNEL_STEP;
		while (1)
		{
			if (KT_FMValidStation(NextFreq))	//if nextfreq is a true channel, then stop seeking and return seek success
			{
				*Frequency=NextFreq;
				return(1);
			}
			else
			{
				if (NextFreq==SEEK_DOWN_LIMIT)	//if current channel reach 87.5MHz, then stop seeking and return seek fail
				{
					*Frequency=NextFreq;
					return(0);
				}
				NextFreq-=CHANNEL_STEP;			//Try next channel
			}
		}
	}
}
#endif
u8 KT_FMValidStation(u16 Frequency) //0-->False Station 1-->Good Station //check AFC_DELTA only
{
	xd_u16 nextfreq;
	char afc[3];							//AFC value for previous, current and next channels
	xd_u16 freq[3];							//frequency values for previous, current and next channels
#ifdef SEEK_WITH_SNR
	xd_u8 snr[3];							//SNR for previous, current and next channels
#endif
	char i,j;
	xd_u8 snr2,snr3;
 //   Display_Channel(Frequency);	 			//display current channel frequency
	afc[0]=0;afc[1]=0;afc[2]=0;				//initialize
	freq[0]=0;freq[1]=0;freq[2]=0;			//initialize
#ifdef SEEK_WITH_SNR
	snr[0]=0;snr[1]=0;snr[2]=0;				//initialize
#endif
	nextfreq=Frequency-CHANNEL_STEP;		
	//Get AFC values of previous, current and next channels
	for (i=0;i<3;i++){
		//get AFC values for the last station's information
		for (j=0;j<3;j++)
			if (mem_freq[j]==nextfreq) {
				afc[i]=mem_afc[j];
				freq[i]=mem_freq[j];
#ifdef SEEK_WITH_SNR
				snr[i]=mem_snr[j];
#endif
			}
		//get new AFC value if the station information is not investigated in the last run
		if (!freq[i]) {
		    KT_FMTune(nextfreq);
				delay_10ms(5);

			afc[i]=KT_FMGetAFC();
#ifdef SEEK_WITH_SNR
			snr[i]=KT_FMGetSNR();
#endif
			freq[i]=nextfreq;
		}
		nextfreq+=CHANNEL_STEP;
	}
	//Record AFC values
	mem_afc[0]=afc[0];mem_afc[1]=afc[1];mem_afc[2]=afc[2];
	mem_freq[0]=freq[0];mem_freq[1]=freq[1];mem_freq[2]=freq[2];
#ifdef SEEK_WITH_SNR
	mem_snr[0]=snr[0];mem_snr[1]=snr[1];mem_snr[2]=snr[2];
#endif
	//Determine the validation of current station
	if ((afc[0]<afc[1]) && (afc[1]<afc[2]) && (afc[0]<-FM_AFCTH_PREV) && (afc[1]>-FM_AFCTH) && (afc[1]<FM_AFCTH) && (afc[2]>FM_AFCTH_NEXT)) {
#ifdef SEEK_WITH_SNR
		KT_FMTune(Frequency);
		delay_10ms(5);

		snr2=KT_FMGetSNR();
		if ((snr[1]>=FM_SNR_TH) && (snr2>=FM_SNR_TH)) return(1);
		if ((snr[1]<FM_SNR_TH) && (snr2<FM_SNR_TH)) return(0);
		delay_10ms(5);
		snr3=KT_FMGetSNR();
		if (snr3>=FM_SNR_TH) return(1);
		else return(0);
#else
		return(1);
#endif
	}
	else return(0);
}
#if 0
u8 KT_MWSeekFromCurrentCh(u16 seekDir, u16 *Frequency)   //	seekDir: 0-->seek down 1-->seek up
{
	xd_u16 NextFreq;
	mem_afc[0]=0;mem_afc[1]=0;mem_afc[2]=0;
	mem_freq[0]=0;mem_freq[1]=0;mem_freq[2]=0;

	if (seekDir == SEEKUP)
	{
		if ((*Frequency) == MW_SEEK_UP_LIMIT)			//if current channel reaches 1710KHz, then start seeking from 504KHz
			NextFreq = MW_SEEK_DOWN_LIMIT;
		else											//else start from 9KHz after current channel
			NextFreq = (*Frequency) + MW_CHANNEL_STEP;
		while (1)
		{
			if (KT_AMValidStation(NextFreq))			//if nextfreq is a true channel, then stop seeking and return seek success
			{
				*Frequency = NextFreq;
				return(1);
			}
			else
			{
				if (NextFreq == MW_SEEK_UP_LIMIT)		//if current channel reach 108MHz, then stop seeking and return seek fail
				{	
					*Frequency = NextFreq;
					return(0);
				}
				NextFreq = NextFreq + MW_CHANNEL_STEP;	//Try next channel
			}
		}
	}
	else
	{
		if ((*Frequency) == MW_SEEK_DOWN_LIMIT)			//if current channel reaches 504KHz, then start seeking from 1710KHz
			NextFreq = MW_SEEK_UP_LIMIT;
		else											//else start from 9kHz before current channel
			NextFreq = (*Frequency) - MW_CHANNEL_STEP;
		while (1)
		{
			if (KT_AMValidStation(NextFreq))			//if nextfreq is a true channel, then stop seeking and return seek success
			{
				*Frequency = NextFreq;
				return(1);
			}
			else
			{
				if (NextFreq == MW_SEEK_DOWN_LIMIT)		//if current channel reach 504KHz, then stop seeking and return seek fail
				{
 					*Frequency = NextFreq;
					return(0);
				}
				NextFreq = NextFreq - MW_CHANNEL_STEP;	//Try next channel
			}
		}
	}
}
#endif
#ifdef	KT0915
u8 KT_SWSeekFromCurrentCh(u16 seekDir, u16 *Frequency)   //	seekDir: 0-->seek down 1-->seek up
{
	xd_u16 NextFreq;
	mem_afc[0]=0;mem_afc[1]=0;mem_afc[2]=0;
	mem_freq[0]=0;mem_freq[1]=0;mem_freq[2]=0;

	if (seekDir == SEEKUP)
	{
		if ((*Frequency) == SW_SEEK_UP_LIMIT)			//if current channel reaches 1710KHz, then start seeking from 504KHz
			NextFreq = SW_SEEK_DOWN_LIMIT;
		else											//else start from 9KHz after current channel
			NextFreq = (*Frequency) + SW_CHANNEL_STEP;
		while (1)
		{
			if (KT_AMValidStation(NextFreq))			//if nextfreq is a true channel, then stop seeking and return seek success
			{
				*Frequency = NextFreq;
				return(1);
			}
			else
			{
				if (NextFreq == SW_SEEK_UP_LIMIT)		//if current channel reach 108MHz, then stop seeking and return seek fail
				{	
					*Frequency = NextFreq;
					return(0);
				}
				NextFreq = NextFreq + SW_CHANNEL_STEP;	//Try next channel
			}
		}
	}
	else
	{
		if ((*Frequency) == SW_SEEK_DOWN_LIMIT)			//if current channel reaches 504KHz, then start seeking from 1710KHz
			NextFreq = SW_SEEK_UP_LIMIT;
		else											//else start from 9kHz before current channel
			NextFreq = (*Frequency) - SW_CHANNEL_STEP;
		while (1)
		{
			if (KT_AMValidStation(NextFreq))			//if nextfreq is a true channel, then stop seeking and return seek success
			{
				*Frequency = NextFreq;
				return(1);
			}
			else
			{
				if (NextFreq == SW_SEEK_DOWN_LIMIT)		//if current channel reach 504KHz, then stop seeking and return seek fail
				{
 					*Frequency = NextFreq;
					return(0);
				}
				NextFreq = NextFreq - SW_CHANNEL_STEP;	//Try next channel
			}
		}
	}
}
#endif

char KT_FMGetAFC(void) // returned value's range is from -127 to 127, unit is KHz
{
	char afc_delta;
	u16 regx;
	regx = KT_Bus_Read(0x3C);								// read AFC_DELTAF
	afc_delta = regx & 0x00FF;
	return (afc_delta);	
}

u8 KT_AMValidStation(u16 Frequency) //0-->False Station 1-->Good Station //check AFC_DELTA only
{
	char AM_afc[3];							//AFC value for previous, current and next channels
	AM_afc[0]=0;AM_afc[1]=0;AM_afc[2]=0;	//initialize

//    Display_Channel_AM(Frequency);			//display current channel frequency

	KT_MWTune( Frequency - 1 );
	delay_10ms(20);
	AM_afc[0] = KT_AMGetAFC();

	if( AM_afc[0] < -AM_AFCTH_PREV )
	{
		KT_MWTune( Frequency );
		delay_10ms(2);		
		AM_afc[1] = KT_AMGetAFC();
		
		if( (AM_afc[1] > -AM_AFCTH) && (AM_afc[1] < AM_AFCTH) )
		{
			KT_MWTune( Frequency + 1 );
			AM_afc[2] = KT_AMGetAFC();
		
			if( AM_afc[2] > AM_AFCTH_NEXT )
			{
				if ( (AM_afc[0] < AM_afc[1]) && (AM_afc[1] < AM_afc[2]) )
					return(1);
				else
					return(0);
			}
			else
			{
				return(0);
			}
		}
		else
		{
			return(0);
		}
	}
	else
	{
		return(0); 
	}
}

char KT_AMGetAFC(void) // returned value's range is from -127 to 127, unit is KHz
{
	char afc_delta;
	u16 regx;
	regx = KT_Bus_Read(0x25);								// read AFC_DELTAF
	afc_delta = regx & 0x00FF;
	return (afc_delta);	
}

#ifdef AM_SOFTMUTE
void KT_AM_SOFTMUTE(u16 Frequency)
{
	u16 reg4;

	reg4=KT_Bus_Read(0x04);

	if(KT_AMValidStation(Frequency))
	{
//		KT_AM_SOFTMUTE_SETTING(2,3,2,5);					// SMUTEA=4,SMUTER=60ms,AM_SMTH=3,VOLUMET=5,SMMD=RSSI mode
		KT_Bus_Write(0x04,reg4 | 0x4000);					// AM Softmute Disable
	}
	else
	{
		KT_AM_SOFTMUTE_SETTING(0,3,7,5);					// SMUTEA=16,SMUTER=60ms,AM_SMTH=8,VOLUMET=5,SMMD=RSSI mode
		KT_Bus_Write(0x04,reg4 & 0xBFFF);					// AM Softmute Enable
	}
//	reg4=KT_Bus_Read(0x04);									// AM Softmute Enable
//	KT_Bus_Write(0x04,reg4 & 0xBFFF);
}

void KT_AM_SOFTMUTE_SETTING(u8 SMUTEA, u8 SMUTER, u8 AM_SMTH, u8 VOLUMET)
{
	u16 reg2E;
	reg2E=KT_Bus_Read(0x2E);
	KT_Bus_Write(0x2E,(reg2E & 0x0007) | (SMUTEA<<14) | (SMUTER<<12) | (AM_SMTH<<9) | (VOLUMET<<4) | 0x0000 );
//									SMUTEA=4,SMUTER=120ms,AM_SMTH=3,VOLUMET=1,SMMD=RSSI mode
}
#endif

#ifdef FM_SOFTMUTE
void KT_FM_SOFTMUTE(u16 Frequency)
{
	u16 reg4;

	reg4=KT_Bus_Read(0x04);

	if(KT_FMValidStation(Frequency))
	{
//		KT_FM_SOFTMUTE_SETTING(2,3,4,5);					// SMUTEA=4,SMUTER=60ms,SMMD=SNR mode,FM_SMTH=9,VOLUMET=5
		KT_Bus_Write(0x04,reg4 | 0x8000);					// FM Softmute Disable

	}
	else
	{
		KT_FM_SOFTMUTE_SETTING(0,3,7,5);					// SMUTEA=16,SMUTER=60ms,SMMD=SNR mode,FM_SMTH=12,VOLUMET=5
		KT_Bus_Write(0x04,reg4 & 0x7FFF);					// FM Softmute Enable
	}
//	reg4=KT_Bus_Read(0x04);									// FM Softmute Enable
//	KT_Bus_Write(0x04,reg4 & 0x7FFF);
}

void KT_FM_SOFTMUTE_SETTING(u8 SMUTEA, u8 SMUTER, u8 FM_SMTH, u8 VOLUMET)
{
	u16 reg2E;
	reg2E=KT_Bus_Read(0x2E);
	KT_Bus_Write(0x2E,(reg2E & 0x0E00) | (SMUTEA<<14) | (SMUTER<<12) | (VOLUMET<<4) | 0x0008 | FM_SMTH );
//									SMUTEA=4,SMUTER=120ms,VOLUMET=1,SMMD=SNR mode,FM_SMTH=3
}
#endif
#if 0
bit KT_AM_TUNING_LIGHT(void)
{
	u16 reg1C;
	char AM_AFC;
	reg1C = KT_Bus_Read(0x1C);
	reg1C = reg1C & 0x3F00;
	reg1C = reg1C>>8;
	AM_AFC = KT_AMGetAFC();

#ifdef AM_ABC
	if( ( reg1C <= AM_TUNING_LIGHT_TH ) && ( AM_AFC > -2 ) && ( AM_AFC < 2 ) )
		KT_AMSetBW(4);
	else
		KT_AMSetBW(2);
#endif

	if( ( reg1C <= AM_TUNING_LIGHT_TH ) && ( AM_AFC > -AM_AFCTH ) && ( AM_AFC < AM_AFCTH ) )
		return(1);
	else
		return(0);
}

bit KT_FM_TUNING_LIGHT(void)
{
	char FM_AFC;
	FM_AFC=KT_FMGetAFC();
	if( ( KT_FMGetSNR() >= FM_SNR_TH ) && ( FM_AFC > -FM_AFCTH ) && ( FM_AFC < FM_AFCTH ) ) 
		return(1);
	else
		return(0);
}

bit KT_FM_ST_Indicator(void)
{
#ifdef MANUAL_SEPARATION
	u16 reg5;
	char xdata rssi_value;

	KT_FMReadRSSI(&rssi_value);

	if(rssi_value >= SEPARATION_POINT)
	{
		reg5=KT_Bus_Read(0x05);					// BLEND DISABLE
		KT_Bus_Write(0x05, reg5 | 0x0020);
		if ( KT_FMGetST() )
	 	{
			return(1);
		}
		else 
		{
			CODE_Send(0x98);					// LCDœ‘ æ"mono"∑˚∫≈
			return(0);
		}
	}
	if(rssi_value <= BLEND_POINT)
	{
		reg5=KT_Bus_Read(0x05);					// BLEND ENABLE
		KT_Bus_Write(0x05, reg5 & 0xFFDF);
		return(0);
	}
#else
	if ( KT_FMGetST() )
	{
		return(1);
	}
	else 
	{
		return(0);
	}
#endif
}

#endif
#ifdef AM_SOFTMUTE_AFCMODE

void KT_AM_SOFTMUTE_SETTING(u8 SMUTEA, u8 SMUTER, u8 AM_SMTH, u8 VOLUMET)
{
	u16 reg2E;
	reg2E=KT_Bus_Read(0x2E);
	KT_Bus_Write(0x2E,(reg2E & 0x0007) | (SMUTEA<<14) | (SMUTER<<12) | (AM_SMTH<<9) | (VOLUMET<<4) | 0x0000 );
}
/*
//-----------AM SOFTMUTE AFC MODE A:-----------// 
void KT_AM_SOFTMUTE_AFCMODE(bit Valid)
{
	char xdata rssi_value;
	u8 am_afc;
	u16 reg4,regF;

	reg4=KT_Bus_Read(0x04);
 	am_afc = abs(KT_AMGetAFC());

	if(Valid == 1)
	{
		KT_AMReadRSSI(&rssi_value);
		if(rssi_value>-60)
		{
			KT_Bus_Write(0x04,reg4 | 0x4000);					// AM Softmute Disable
			KT_AM_AFC_VolumeSet(am_afc);
		}
		if(rssi_value<-66)
		{
			if((reg4 & 0x4000) == 0x4000)						// if softmute disable
			{
				KT_AM_SOFTMUTE_SETTING(2,2,7,15);				// SMUTEA=4,SMUTER=30ms,AM_SMTH=8,VOLUMET=15,SMMD=RSSI mode
				KT_Bus_Write(0x04,reg4 & 0xBFFF);				// AM Softmute Enable
			}
		}
		CODE_Send(0x9B);										// œ‘ æB0-B3
		DATA_Send('V');
		DATA_Send('C');
	}
	else
	{
		KT_Bus_Write(0x04,reg4 | 0x4000);						// AM Softmute Disable
		if(am_afc<13)
		{
			KT_AMReadRSSI(&rssi_value);
			if(rssi_value<-72)
			{
				regF=KT_Bus_Read(0x0F); 
				KT_Bus_Write(0x0F, regF & 0xFFE0 | 0x000F); 
			}
			if(rssi_value>-63)
			{
				KT_AMFMUnMute();
			}
		}
		else
		{
			KT_AM_AFC_VolumeSet(am_afc);
		}		
		CODE_Send(0x9B);										// œ‘ æB0-B3
		DATA_Send(' ');
		DATA_Send(' ');
	}
}


void KT_AM_AFC_VolumeSet(u8 afc)			//Input: 0~128
{
	u16 regx;
	char afc_volume;

	regx=KT_Bus_Read(0x0F); 

	if(afc >= 60)					//+-8
	{
		KT_AMFMMute();
	}
	if( (afc < 60) && (afc >= 52) )	//+-7
	{
		afc_volume = mem_vol-28;
		if(afc_volume<15)
			afc_volume = 15;
		KT_Bus_Write(0x0F, regx & 0xFFE0 | afc_volume);
	}
	if( (afc < 52) && (afc >= 44) )	//+-6
	{
		afc_volume = mem_vol-24;
		if(afc_volume<15)
			afc_volume = 15;
		KT_Bus_Write(0x0F, regx & 0xFFE0 | afc_volume);
	}
	if( (afc < 44) && (afc >= 36) )	//+-5
	{
		afc_volume = mem_vol-20;
		if(afc_volume<15)
			afc_volume = 15;
		KT_Bus_Write(0x0F, regx & 0xFFE0 | afc_volume);
	}
	if( (afc < 36) && (afc >= 28) )	//+-4
	{
		afc_volume = mem_vol-16;
		if(afc_volume<15)
			afc_volume = 15;
		KT_Bus_Write(0x0F, regx & 0xFFE0 | afc_volume);
	}
	if( (afc < 28) && (afc >= 20) )	//+-3
	{
		afc_volume = mem_vol-6;
		if(afc_volume<15)
			afc_volume = 15;
		KT_Bus_Write(0x0F, regx & 0xFFE0 | afc_volume);
	}
	if( (afc < 20) && (afc >= 12) )//+-2
	{
		afc_volume = mem_vol-5;
		if(afc_volume<15)
			afc_volume = 15;
		KT_Bus_Write(0x0F, regx & 0xFFE0 | afc_volume);
	}
	if( (afc < 12) && (afc >= 4) )	//+-1
	{
		afc_volume = mem_vol-1;

		if(afc_volume<15)
			afc_volume = 15;
		KT_Bus_Write(0x0F, regx & 0xFFE0 | afc_volume);
	}
	if(afc < 4)						//+-0
	{
		KT_Bus_Write(0x0F, regx & 0xFFE0 | mem_vol);
	}
}
//-----------AM SOFTMUTE AFC MODE A END-----------// 
*/

//-----------AM SOFTMUTE AFC MODE B-----------// 
void KT_AM_SOFTMUTE_AFCMODE(void)
//void KT_AM_SOFTMUTE_AMTUNINGLIGHTMODE(bit Valid)
{
	char xdata rssi_value;
	u8 am_afc;
	u16 reg4;

	reg4=KT_Bus_Read(0x04);
 	am_afc = abs(KT_AMGetAFC());

	if(KT_AM_TUNING_LIGHT())
	{
		KT_AMReadRSSI(&rssi_value);
		if(rssi_value>-60)
		{
			KT_Bus_Write(0x04,reg4 | 0x4000);					// AM Softmute Disable
		}
		if(rssi_value<-66)
		{
			if((reg4 & 0x4000) == 0x4000)						// if softmute disable
			{
				KT_AM_SOFTMUTE_SETTING(2,2,7,15);				// SMUTEA=4,SMUTER=30ms,AM_SMTH=8,VOLUMET=15,SMMD=RSSI mode
				KT_Bus_Write(0x04,reg4 & 0xBFFF);				// AM Softmute Enable
			}
		}
		//CODE_Send(0x9B);										// œ‘ æB0-B3
		//DATA_Send('V');
		//DATA_Send('C');
	}
	else
	{
		KT_Bus_Write(0x04,reg4 | 0x4000);						// AM Softmute Disable
		KT_AM_AFC_VolumeSet(am_afc);
		
		//CODE_Send(0x9B);										// œ‘ æB0-B3
		//DATA_Send(' ');
		//DATA_Send(' ');
	}
}

void KT_AM_AFC_VolumeSet(u8 afc)			//Input: 0~128
{
	u16 regx;
	char afc_volume;

	regx=KT_Bus_Read(0x0F); 

	if(afc >= 60)					//+-8
	{
		KT_AMFMMute();
	}
	if( (afc < 60) && (afc >= 52) )	//+-7
	{
		afc_volume = mem_vol-28;
		if(afc_volume<15)
			afc_volume = 15;
		KT_Bus_Write(0x0F, regx & 0xFFE0 | afc_volume);
	}
	if( (afc < 52) && (afc >= 44) )	//+-6
	{
		afc_volume = mem_vol-24;
		if(afc_volume<15)
			afc_volume = 15;
		KT_Bus_Write(0x0F, regx & 0xFFE0 | afc_volume);
	}
	if( (afc < 44) && (afc >= 36) )	//+-5
	{
		afc_volume = mem_vol-20;
		if(afc_volume<15)
			afc_volume = 15;
		KT_Bus_Write(0x0F, regx & 0xFFE0 | afc_volume);
	}
	if( (afc < 36) && (afc >= 28) )	//+-4
	{
		afc_volume = mem_vol-16;
		if(afc_volume<15)
			afc_volume = 15;
		KT_Bus_Write(0x0F, regx & 0xFFE0 | afc_volume);
	}
	if( (afc < 28) && (afc >= 20) )	//+-3
	{
		afc_volume = mem_vol-6;
		if(afc_volume<15)
			afc_volume = 15;
		KT_Bus_Write(0x0F, regx & 0xFFE0 | afc_volume);
	}
	if( (afc < 20) && (afc >= 12) )//+-2
	{
		afc_volume = mem_vol-5;
		if(afc_volume<15)
			afc_volume = 15;
		KT_Bus_Write(0x0F, regx & 0xFFE0 | afc_volume);
	}
	if( (afc < 12) && (afc >= 4) )	//+-1
	{
		afc_volume = mem_vol-1;

		if(afc_volume<15)
			afc_volume = 15;
		KT_Bus_Write(0x0F, regx & 0xFFE0 | afc_volume);
	}
	if(afc < 4)						//+-0
	{
		afc_volume = 15;
		KT_Bus_Write(0x0F, regx & 0xFFE0 | afc_volume);
	}
}
//-----------AM SOFTMUTE AFC MODE B END-----------// 
#endif
#endif
