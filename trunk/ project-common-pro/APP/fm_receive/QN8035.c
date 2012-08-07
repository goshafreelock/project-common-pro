#include "Custom_config.h"
#include "qn8035.h"
//#include "entry.h"
#include "iic.h" 
#ifdef USE_QN8035_FM
//if antenna match circuit uses a inductor，macro USING_INDUCTOR will be set to 1
#define USING_INDUCTOR		1
#define SCAN_NOISE_FLOOR 	0
#define INVERSE_IMR		    1


	
UINT8 _xdata qnd_PreNoiseFloor = 40,qnd_NoiseFloor = 40;


extern void delay_10ms(u8 delay);
extern bool iic_busy;
u16 _xdata aa;
u8   _xdata qnd_PrevMode;
u8   _xdata qnd_CH_STEP  = 1;
u8 _xdata qnd_ChipID;

//u8 _xdata  qn8035_rssi;
//u8 _xdata  qn8035_if2;
//u8 _xdata qn8035_snr;

//extern bool hp_in_busy;

u8 _code qn8035_vol_tabl[17]=
{
    0x40,/*,0x59,*/0x41,0x42,0x5b,0x43,0x44,0x54,0x5d,0x45,0x55,0x56,0x5e,0x46,0x57,0x5f,0x47
};

u8 QND_ReadReg(u8 iic_addr)
{
	u8  byte;
	
//	while(hp_in_busy);
    iic_busy = 1;
    iic_start();                    //I2C启动
    iic_sendbyte(0x20);             //写命令
    iic_sendbyte(iic_addr);         //写地址
    iic_start();                    //写转为读命令，需要再次启动I2C
    iic_sendbyte(0x21);             //读命令
    byte = iic_revbyte(1);
    iic_stop();                     //I2C停止
    iic_busy = 0;
    return  byte;
}


void QND_WriteReg(u8 Regis_Addr,u8 Data)
{   
	iic_write(0x20,Regis_Addr,&Data,1);
 	//return dat;
}

  

/**********************************************************************
int QND_Delay()
**********************************************************************
Description: Delay for some ms, to be customized according to user
             application platform

Parameters:
        ms: ms counts
Return Value:
        None
            
**********************************************************************/
void QND_Delay(u16 ms) 	  //1ms延时
{
//	Delay(25*ms);   		//rc
	Delay(2000*ms);   // 1500
}  
#define QNF_SetMute(x) 	QN8035_MUTE(x)
/**********************************************************************
void QNF_SetMute(u8 On)
**********************************************************************
Description: set register specified bit

Parameters:
On:        1: mute, 0: unmute
Return Value:
None
**********************************************************************/
void QN8035_MUTE(bit On)	/////////////////////////
{	
	QND_WriteReg(REG_DAC, On?0x1B:0x10);  
}

#if SCAN_NOISE_FLOOR
 /***********************************************************************
Description: scan a noise floor from 87.5M to 108M by step 200K
Parameters:
Return Value:
 1: scan a noise floor successfully.                                                                                         
 0: chip would not normally work. 
**********************************************************************/
UINT8 QND_ScanNoiseFloor(void)
{
	UINT8 regValue;
	UINT8 timeOut = 255; //time out is 2.55S      
	
	QND_WriteReg(CCA_SNR_TH_1,0x00);
	QND_WriteReg(CCA_SNR_TH_2,0x05);
	QND_WriteReg(0x40,0xf0);
	//config CCS from 87.5M to 108M by step 200KHZ
	QND_WriteReg(CH_START,0x26);
	QND_WriteReg(CH_STOP,0xc0);
	QND_WriteReg(CH_STEP,0xb8);
	//enter CCA mode,channel index is decided by internal CCA 
	QND_WriteReg(SYSTEM1,0x12);	
    while(1)
    {
        regValue = QND_ReadReg(SYSTEM1);        
        //if it seeks a potential channel, the loop will be quited     
        if((regValue & CHSC) == 0) break;
        QND_Delay(10);   //delay 5ms
        //if it was time out,chip would not normally work.
        if((timeOut--) == 0) return 0;
    }	
	QND_WriteReg(0x40,0x70);
	qnd_NoiseFloor = QND_ReadReg(0x3f);	
	if(((qnd_PreNoiseFloor-qnd_NoiseFloor) > 2) ||((qnd_NoiseFloor-qnd_PreNoiseFloor) > 2))
	{
		qnd_PreNoiseFloor = qnd_NoiseFloor;
	}
	//TRACE("NF:%d,timeOut:%d\n",qnd_NoiseFloor,255-timeOut);
	return 1;
}
#endif

/**********************************************************************
void QNF_SetRegBit(u8 reg, u8 bitMask, u8 data_val)
**********************************************************************
Description: set register specified bit

Parameters:
    reg:        register that will be set
    bitMask:    mask specified bit of register
    data_val:    data will be set for specified bit
Return Value:
  None
***********************************************************************/
#if defined(QN_SCAN_HIGH_SENSE)
#define RSSI_FACTOR		4
#define CCA_FACTOR		0x05
#define SNR_FACTOR		8
#else
#define RSSI_FACTOR		5		// 8 //8	越小台多0-
#define CCA_FACTOR		0x04	 //0x03	  // 大台多 1-5
#define SNR_FACTOR		9		// 9 //小台多 8-12 //setting SNR threshold for CCA  9
#endif
void QND_RXSetTH(void)
{	
	UINT8 rssi_th;
	if(qnd_PreNoiseFloor>=28)                  //20110829
	rssi_th = qnd_PreNoiseFloor - 28 + RSSI_FACTOR;    // 8 //8	越小台多0-
	else
	rssi_th = 20;

	///increase reference PLL charge pump current.
	QND_WriteReg(REG_REF,0x7a);
	//NFILT program is enabled
	QND_WriteReg(0x1b,0x78);
	//using Filter3
	QND_WriteReg(CCA1,0x75);
	//setting CCA IF counter error range value(768).
	QND_WriteReg(CCA_CNT2,CCA_FACTOR);  //0x03	  // 大台多 1-5
#if PILOT_CCA
	QND_WriteReg(PLT1,0x00);
#endif
	//selection the time of CCA FSM wait SNR calculator to settle:20ms
	//0x00:	    20ms(default)
	//0x40:	    40ms
	//0x80:	    60ms
	//0xC0:	    100m
	//    QNF_SetRegBit(CCA_SNR_TH_1 , 0xC0, 0x00);
	//selection the time of CCA FSM wait RF front end and AGC to settle:20ms
	//0x00:     10ms
	//0x40:     20ms(default)
	//0x80:     40ms
	//0xC0:     60ms
	//    QNF_SetRegBit(CCA_SNR_TH_2, 0xC0, 0x40);
	//    QNF_SetRegBit(CCA, 30);  //setting CCA RSSI threshold is 30
	QND_WriteReg(CCA,QND_ReadReg(CCA)&0xc0|rssi_th);
	QND_WriteReg(CCA_SNR_TH_2,0xc5);    // edit by yewuyun at 2011.11.16
#if PILOT_CCA
	QND_WriteReg(CCA_SNR_TH_1,0x48); //setting SNR threshold for CCA
#else
	QND_WriteReg(CCA_SNR_TH_1,SNR_FACTOR); // 9 //小台多 8-12 //setting SNR threshold for CCA  9
#endif
}


/**********************************************************************
u8 QNF_SetCh(u16 freq)
**********************************************************************
Description: set channel frequency 

Parameters:
    freq:  channel frequency to be set
Return Value:
    1: success
**********************************************************************/
void QNF_SetCh(u16 freq)    //////////////////
{
    // calculate ch parameter used for register setting
//    u8 tStep;
//    u8 tCh;
//   u16 f; 
//    
//
//   // QNF_SetRegBit(SYSTEM1, CCA_CH_DIS, CCA_CH_DIS); 
//	QND_WriteReg(0x00, 0x11);
//    f = FREQ2CHREG(freq); 
//    // set to reg: CH
//    tCh = (u8) f;
//    QND_WriteReg(CH, tCh);
//    // set to reg: CH_STEP
//    tStep = QND_ReadReg(CH_STEP);
//    tStep &= ~CH_CH;
//    tStep |= ((u8) (f >> 8) & CH_CH);
//    QND_WriteReg(CH_STEP, tStep);

  u8 temp;

	 freq = FREQ2CHREG(freq); 
	//writing lower 8 bits of CCA channel start index
	QND_WriteReg(CH_START, (u8)freq);
	//writing lower 8 bits of CCA channel stop index
	QND_WriteReg(CH_STOP, (u8)freq);
	//writing lower 8 bits of channel index
	QND_WriteReg(CH, (u8)freq);
	//writing higher bits of CCA channel start,stop and step index
	temp = (u8) ((freq >> 8) & CH_CH);
	temp |= ((u8)(freq >> 6) & CH_CH_START);
	temp |= ((u8) (freq >> 4) & CH_CH_STOP);
	temp |= QND_STEP_CONSTANT;//(step << 6);
	QND_WriteReg(CH_STEP, temp);
}

/**********************************************************************
void QNF_ConfigScan(u16 start,u16 stop, u8 step)
**********************************************************************
Description: config start, stop, step register for FM/AM CCA or CCS

Parameters:
    start
        Set the frequency (10kHz) where scan to be started,
        eg: 7600 for 76.00MHz.
    stop
        Set the frequency (10kHz) where scan to be stopped,
        eg: 10800 for 108.00MHz
    step        
        1: set leap step to (FM)100kHz / 10kHz(AM)
        2: set leap step to (FM)200kHz / 1kHz(AM)
        0:  set leap step to (FM)50kHz / 9kHz(AM)
Return Value:
         None
**********************************************************************/
void QNF_ConfigScan(u16 fre) ///
{
  // calculate ch para
    u8 tStep = 0;
    u8 tS;
    u16 fStart;
    
    fStart = FREQ2CHREG(fre);
    // set to reg: CH_START
    tS = (u8) fStart;
    QND_WriteReg(CH_START, tS);
    tStep |= ((u8) (fStart >> 6) & CH_CH_START);
    // set to reg: CH_STOP
 //   tS = (UINT8) fStart;
    QND_WriteReg(CH_STOP, tS);
    tStep |= ((u8) (fStart >> 4) & CH_CH_STOP);
    // set to reg: CH_STEP
//    tStep |= QND_FSTEP_100KHZ << 6;
    tStep |= 0x40;
    QND_WriteReg(CH_STEP, tStep); 
}
	  
void init_QN8035(void)
{
	//put_str("init_QN8035 \n");
	delay_10ms(10);
	QND_WriteReg(0x00, 0x81);
	//QND_Delay(10);
	delay_10ms(1);

	/*********User sets chip working clock **********/
	//Following is where change the input clock wave type,as sine-wave or square-wave.
	//default set is 32.768KHZ square-wave input.
#ifdef QN_SHARE_MCU_CRYSTAL	
	QND_WriteReg(0x01,QND_SINE_WAVE_CLOCK);
#else
	QND_WriteReg(0x01,QND_DIGITAL_CLOCK);
#endif

#if defined(SYS_CRYSTAL_USE_12M)
	//Following is where change the input clock frequency.
	QND_WriteReg(XTAL_DIV0, QND_XTAL_DIV0);
	QND_WriteReg(XTAL_DIV1, QND_XTAL_DIV1);
	QND_WriteReg(XTAL_DIV2, QND_XTAL_DIV2);
#endif
	/********User sets chip working clock end ********/

	QND_WriteReg(0x54, 0x47);//mod PLL setting
	//select SNR as filter3,SM step is 2db
	QND_WriteReg(0x19, 0xc4);
	QND_WriteReg(0x33, 0x9e);//set HCC and SM Hystersis 5db
	QND_WriteReg(0x2d, 0xd6);//notch filter threshold adjusting
	QND_WriteReg(0x43, 0x10);//notch filter threshold enable
	QND_WriteReg(0x47,0x39);
	//QND_WriteReg(0x57, 0x21);//only for qn8035B test
	//enter receiver mode directly
	QND_WriteReg(0x00, 0x11);
	//Enable the channel condition filter3 adaptation,Let ccfilter3 adjust freely
	QND_WriteReg(0x1d,0xa9);
	QND_WriteReg(0x2c,0x12);
	QND_WriteReg(0x4f, 0x40);//dsiable auto tuning
	QNF_SetMute(1);
}


void QN8035_powerdown(void)
{
//	QND_SetSysMode(0);
 QND_WriteReg(SYSTEM1, 0x20); 
}


/**********************************************************************
void QND_TuneToCH(u16 ch)
**********************************************************************
Description: Tune to the specific channel. call QND_SetSysMode() before 
call this function
Parameters:
ch
Set the frequency (10kHz) to be tuned,
eg: 101.30MHz will be set to 10130.
Return Value:
None
**********************************************************************/
void QND_TuneToCH(u16 ch)	   //设置频点
{
	UINT8 reg;
	
	//increase reference PLL charge pump current.
	QND_WriteReg(REG_REF,0x7a);
	
	/********** QNF_RXInit ****************/
	QND_WriteReg(0x1b,0x70);  //Let NFILT adjust freely
	//QNF_SetRegBit(0x2C,0x3F,0x12);  ///When SNR<ccth31, ccfilt3 will work
	//setting the threshold of Filter3 will be worked.
	QND_WriteReg(0x2c,0x52);
	//QNF_SetRegBit(0x1D,0x40,0x00);  ///Let ccfilter3 adjust freely
	//QNF_SetRegBit(0x41,0x0F,0x0A);  ///Set a hcc index to trig ccfilter3's adjust
	QND_WriteReg(0x45,0x50);        ///Set aud_thrd will affect ccfilter3's tap number
	//QNF_SetRegBit(0x40,0x70,0x70);  ///snc/hcc/sm snr_rssi_sel; snc_start=0x40; hcc_start=0x30; sm_start=0x20
	QND_WriteReg(0x40,0x70);
	//QNF_SetRegBit(0x19,0x80,0x80);  ///Use SNR for ccfilter selection criterion
	//selecting SNR as filter3 filter condition
	//QND_WriteReg(0x19, 0xC2);
	//QNF_SetRegBit(0x3E,0x80,0x80);  ///it is decided by programming this register
	//QNF_SetRegBit(0x41,0xE0,0xC0);  ///DC notching High pass filter bandwidth; remove low freqency dc signals
	QND_WriteReg(0x41,0xca);
	QND_WriteReg(0x34,SMSTART_VAL); ///set SMSTART
	QND_WriteReg(0x35,SNCSTART_VAL); ///set SNCSTART
	QND_WriteReg(0x36,HCCSTART_VAL); ///set HCCSTART
	/********** End of QNF_RXInit ****************/
#if INVERSE_IMR
	reg = QND_ReadReg(CCA)&~0x40;
	if((ch == 9530)||(ch == 9980)||(ch == 10480))
	{
		reg |= 0x40;	// inverse IMR.
	}
	else
	{
		reg &= ~0x40;
	}
	QND_WriteReg(CCA, reg);
#endif
	QNF_SetMute(1);
	QNF_SetCh(ch);
	//enable CCA mode with user write into frequency
	QND_WriteReg(0x00, 0x13);
#if USING_INDUCTOR	
	//Auto tuning
	QND_WriteReg(0x4f, 0x80);
	reg = QND_ReadReg(0x4f);
	reg >>= 1;
	QND_WriteReg(0x4f, reg);
#endif	
	///avoid the "POP" noise.
	QND_Delay(500);
	///decrease reference PLL charge pump current.
	QND_WriteReg(REG_REF,0x70);
	QNF_SetMute(0);	 
	
}
				   				   
/***********************************************************************
u16 QND_RXValidCH(u16 freq);
***********************************************************************
Description: to validate a ch (frequency)(if it's a valid channel)
Freq: specific channel frequency, unit: 10Khz
  eg: 108.00MHz will be set to 10800.
Step:  
  FM:
  QND_FMSTEP_100KHZ: set leap step to 100kHz
  QND_FMSTEP_200KHZ: set leap step to 200kHz
  QND_FMSTEP_50KHZ:  set leap step to 50kHz
Return Value:
  0: not a valid channel
  other: a valid channel at this frequency
***********************************************************************/
bool QND_RXValidCH(u16 freq)  //判断真假台
{
	UINT8 _xdata regValue;
	UINT8 _xdata timeOut;
	UINT8 _xdata isValidChannelFlag;
//	UINT8 _xdata snr,snc,temp1,temp2;
#if PILOT_CCA
	UINT8 _xdata snr,readCnt,stereoCount=0;
#endif
	
	QNF_SetCh(freq);
#if USING_INDUCTOR
	//Auto tuning
	QND_WriteReg(0x00, 0x11);
	QND_WriteReg(0x4f, 0x80);
	regValue = QND_ReadReg(0x4f);
	regValue = (regValue >> 1);
	QND_WriteReg(0x4f, regValue);
#endif 
	//entering into RX mode and CCA mode,channels index decide by CCA.
	QND_WriteReg(0x00, 0x12);
	timeOut = 20;  // time out is 100ms
	while(1)
	{
		regValue = QND_ReadReg(SYSTEM1);        
		//if it seeks a potential channel, the loop will be quited     
		if((regValue & CHSC) == 0) break;
		QND_Delay(5);   //delay 5ms
		//if it was time out,chip would not normally work.
		//if((timeOut--) == 0) return -1;
		if((timeOut--) == 0) return 0;
	}   
	//reading out the rxcca_fail flag of RXCCA status
	isValidChannelFlag = (QND_ReadReg(STATUS1) & RXCCA_FAIL ? 0:1);  
	if(isValidChannelFlag)
	{
#if PILOT_CCA
		QND_Delay(100);
		snr = QND_ReadReg(SNR);
		if(snr> 25) return 1;
		for(readCnt=10;readCnt>0;readCnt--)
		{
			QND_Delay(2);
			stereoCount += ((QND_ReadReg(STATUS1) & ST_MO_RX) ? 0:1);
			if(stereoCount >= 5) return 1; // 3
		}
#else
		return 1;
#endif
	}
	return 0;
}	



bool set_fre_QN8035(u16 fre)
{
#if 0
	if(mode)
	{ 
	  QND_TuneToCH(fre*10); 
	  return 1;	
	}
	else
	{   
	    QN8035_MUTE(1);
	  QND_RXSetTH(); 
	  
	  return QND_RXValidCH(fre*10);
	} 
#else
	if(QND_RXValidCH(fre*10))
	{
		QND_TuneToCH(fre*10);
		return TRUE;	
	} 
	return FALSE;
#endif	
}

/**********************************************************************/
void QN8035_set_vol(u8 vol)
{
#if 1
	u8 sVol;
	u8 regVal;
	sVol=vol*3+2;
    regVal = QND_ReadReg(VOL_CTL);
	regVal = (regVal&0xC0)|(sVol/6)|(5-sVol%6<<3);
	QND_WriteReg(VOL_CTL,regVal);
#else
    vol /= 2;
    if(vol > 15)
        vol = 15;
        
    QND_WriteReg(VOL_CTL, qn8035_vol_tabl[vol]);
#endif	
}
#if defined(USE_FM_GPIO)
void QN8075__gpio_ctrl(bool fm_ctrl_flag,u8 gpio_num)
{

}
#endif
u8 QN8035_Read_ID(void)
{
	u8  xdata cChipID;
	cChipID = QND_ReadReg(CID2);
       cChipID &= 0xfc;

	return cChipID;

}
#endif	
//void QN8035_setch(u8 db)
//{
//	QND_RXSetTH(db);
//}

