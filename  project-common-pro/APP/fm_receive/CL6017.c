/* CL6017 */
#include "Custom_config.h"
#ifdef USE_CL6017G_FM	
#include "CL6017.h"

#define FM_CL6017G_WRITE                0x20
#define FM_CL6017G_READ                 0x21

//#define FM_CL6017G_RSSILEV              170	   //	160~190	 越大，信号弱的电台就会被屏蔽
//#define FM_CL6017G_ENVELOPELEV          608	  //   480~640   越小，	信号弱的电台就会被屏蔽
//#define FM_CL6017G_FDLEV                40   //    25~50     基准的频偏，越小越严格


//extern u8 _xdata fm_cl6017_rssilev;
//extern u8 _xdata fm_cl6017_envelopelev;
//extern u8 _xdata fm_cl6017_fdlev;
//extern u8 _xdata key_tone_change;

//extern u8 _xdata set_fm_clock;


//_xdata u16  g_seek_frequency = 875;

u8 _xdata  CL6017G_ControlData[47]={0};

//void CL6017G_FreqToReg(u8 ulFreq);

/*															   
用法说明
(1).上电
(2).调用EnableWire2模式选择
(3).调用Chip_wire2_Initialize或者Chip_wire3_Initialize对CL6017初始化
(4).如果用户要调台，就调用set_fre_CL6017函数；如果用户要自动搜索台，就调用CL6017_SearchByTune进行搜索

*/


//CL6017 initialization value
//CODE u8 CL6017G_ControlData[47]=
//{
//0x64,     //index + 22 ---- reg correct index
//0x69,
//0x78,
//0x10,    //0x10 -->32.768K,0X11-->12M,0X15-->24M,
//0x02,
//0xff,
//0x1f,    //R28_bit<5:4>=01 0x2f
//0xb2,
//0x9b,  
//0x05,
//0x00,
//0x90,
//0x00,
//0xaa,
//0xb2,    //0XBC
//0x15,
//0x96,
//0x80,
//0x00,  
//0x00, 
//0x00,  
//0x00,  
//0x00, 
//0x00,  
//0x60,  
//0x02,  
//0xfe,  
//0x02,  
//0xa0,
//0x00,
//0x00,
//0x02,
//0x80,
//0x00,
//0x60,
//0x25,
//0x90,
//0x0f,
//0x5f,
//0xbc,
//0xa3,
//0x28,
//0x27,
//0x80,
//0x10,     //R66=00010000 0x02
//0x80,
//0xc0,     //R68_bit4=1 0xc0  
//};

void CL6017G_READ_REG(u8 *pBuf,u8 size)
{

#if 0
  	u16 i;

  	iic_start();
    	iic_sendbyte(FM_CL6017G_READ);

  	for(i=0;i<size-1;i++)
	{
	  	pBuf[i] = iic_revbyte_io();
    		s_ack(0);	
	}
	pBuf[i] = iic_revbyte_io();    
	s_ack(1);	
	
    	iic_stop();
#else		
    iic_readn(FM_CL6017G_READ,0xff,pBuf,size);
#endif
    delay_10ms(1);
}
void I2C_WriteCL6017GReg(u8 *pBuf,u8 num)
{ 
#if 0
	u16 i;
	iic_start();
	iic_sendbyte(FM_CL6017G_WRITE);
	 
    	for(i=0;i<num;i++)
	{
	   iic_sendbyte(pBuf[i]);
    	}
    	iic_stop();
#else
   	iic_write(FM_CL6017G_WRITE,0xff,pBuf,num);     
#endif
    delay_10ms(1);
}
/**************************************************         
Function: CL6017_FreqToChan()
Parameter: 
	frequency: FM frequency *10 ,such as  1017,933,1077..                                      

Description:
	change from frequency to channel
/**************************************************/ 

//u16 CL6017_FreqToChan(u16 frequency)
//{
//	u16 bottomOfBand;
//	u8 channelSpacing;
//	u16 channel;
//	
//	bottomOfBand = 875;
//	channelSpacing=1;
//		
//	channel = (frequency - bottomOfBand) / channelSpacing;
//	return (channel);	
//
//}

/**************************************************         
Function: Chip_wire2_Initialize()
Parameter: 
	None                                         
Description:
	CL6017 I2C mode initialization
/**************************************************/ 
//void Chip_wire2_Initialize()
//void init_CL6017(void)
//{

void init_CL6017G(void)
{


	//read reg
	CL6017G_ControlData[0] = 0x64;     // index + 22 ---- reg correct index
	CL6017G_ControlData[1] = 0x69;
	CL6017G_ControlData[2] = 0x78;
//	if(set_fm_clock == 0)
//	{
//		WKUPPND = 0x10;  //set bit[5:4] = 01, output OSC frequancy to P05
//   		P0DIR &= ~(1<<5);  //P05 set output 
//		CL6017G_ControlData[3] = 0x15;     //0x10 -->32.768K,0X11-->12M,0X15-->24M,
//	}
//	else 
//	{
		CL6017G_ControlData[3] = 0x10;     //0x10 -->32.768K,0X11-->12M,0X15-->24M,
//	}
	CL6017G_ControlData[4] = 0x32;
	CL6017G_ControlData[5] = 0xff;	//VOLUME
	CL6017G_ControlData[6] = 0x1f;     //R28_bit<5:4>=01 0x2f
	CL6017G_ControlData[7] = 0xb2;
	CL6017G_ControlData[8] = 0x9b;  
	CL6017G_ControlData[9] = 0x05;
	CL6017G_ControlData[10] = 0x00;
	CL6017G_ControlData[11] = 0x90;
	CL6017G_ControlData[12] = 0x00;
	CL6017G_ControlData[13] = 0x9a;    //0xaa //modi by alpha110119
	CL6017G_ControlData[14] = 0xb2;    //0XBC
	CL6017G_ControlData[15] = 0x15;
	CL6017G_ControlData[16] = 0x96;
	CL6017G_ControlData[17] = 0x80;
	CL6017G_ControlData[18] = 0x00;  
	CL6017G_ControlData[19] = 0x00; 
	CL6017G_ControlData[20] = 0x00;  
	CL6017G_ControlData[21] = 0x00;  
	CL6017G_ControlData[22] = 0x00; 
	CL6017G_ControlData[23] = 0x00;  
	CL6017G_ControlData[24] = 0x60;  
	CL6017G_ControlData[25] = 0x02;  
	CL6017G_ControlData[26] = 0xfe;  
	CL6017G_ControlData[27] = 0x02;  
	CL6017G_ControlData[28] = 0xa0;
	CL6017G_ControlData[29] = 0x00;
	CL6017G_ControlData[30] = 0x00;
	CL6017G_ControlData[31] = 0x02;
	CL6017G_ControlData[32] = 0x80;
	CL6017G_ControlData[33] = 0x00;
	CL6017G_ControlData[34] = 0x60;
	CL6017G_ControlData[35] = 0x25;
	CL6017G_ControlData[36] = 0x90;
	CL6017G_ControlData[37] = 0xff;//0x0f //modi by alpha110119
	CL6017G_ControlData[38] = 0x5f;
	CL6017G_ControlData[39] = 0xbc;//0xbc //modi by alpha110119			24 --0xbe		  32768 --0xbc
	CL6017G_ControlData[40] = 0xa3;
	CL6017G_ControlData[41] = 0x28;
	CL6017G_ControlData[42] = 0x27;
	CL6017G_ControlData[43] = 0x80;
	CL6017G_ControlData[44] = 0x10;//R66=00010000 0x02
	CL6017G_ControlData[45] = 0x80;
	CL6017G_ControlData[46] = 0xc0;//  R68_bit4=1 0xc0  
 
	// if initially set to 94.2mhz radio
	//CL6017G_FreqToReg(94200);
	
	// power up and initial operation
	CL6017G_ControlData[5] &= 0xfe; //power up reg27
	I2C_WriteCL6017GReg(CL6017G_ControlData, 47);	
	
	delay_10ms(40); // wait 800ms for crystal oscillate stable


	CL6017G_ControlData[0] &= 0xdf;   // mute off reg22
	I2C_WriteCL6017GReg(CL6017G_ControlData, 1);	

#if 0
	    CL6017G_READ_REG(Temp,40);	//ID=TEMP[0]
	sys_printf("-------------init_CL6017G------------------");
	for(i=0;i<40;i++){
	printf("--%x----> 0x%x  \r\n",(u16)i,(u16)Temp[i]);

	}
	sys_printf("------------init_CL6017G------------------");
#endif	

}

//}
/**************************************************         
Function: MuteCL6017(bool flag)
Parameter: 
	flag: true :mute, flash :no mute                                      

Description:
	mute CL6017
/**************************************************/
void MuteCL6017(bool flag)
{
	if(flag)
	{
		CL6017G_ControlData[0]|=0x20;
	}
	else
	{
		CL6017G_ControlData[0]&=0xdf;
	}
	I2C_WriteCL6017GReg(CL6017G_ControlData, 1);	
       delay_10ms(2); // delay 1ms
}

/**************************************************         
Function: CL6017G_TUNE()
Parameter: 
	                                      

Description:

/**************************************************/ 
void CL6017G_TUNE(unsigned int unFreq)//875~1080 unit:100kHz
{
		// frequency transfer to channel number,ch unit:kHz---change
	//in some mcu unsigned int maybe 2Bytes,but unsigned long is always 4bytes
	unsigned long ulFreq;
//	unFreq = 918;
	 ulFreq= (unsigned long) unFreq * 100;  //modi by alpha 100827 
	// set frequency
	ulFreq >>= 2;//右移两位
	CL6017G_ControlData[2] = (u8) (ulFreq % 256);//reg24
	CL6017G_ControlData[1] = (u8) (ulFreq >> 8);//reg23	
	// tune function
	//CL6017G_ControlData[0] &= 0xdf;// mute off reg22
	CL6017G_ControlData[4] &= 0xf3;//tune=0,seek=0 reg26
	CL6017G_ControlData[6] = 0x1f;//tune=0,seek=0 reg26
	I2C_WriteCL6017GReg(CL6017G_ControlData, 7);

	CL6017G_ControlData[4] |= 0x08;//tune=1, begin tune operaton reg26
	I2C_WriteCL6017GReg(CL6017G_ControlData,5);
	delay_10ms(5); // wait for 50ms
	//kal_sleep_task(50);
	
}
/**************************************************         
Function: CL6017_SetFreq()
Parameter: 
	curFreq: FM frequency *10 ,such as  1017,933,1077..                                      

Description:
	set FM to a frequency
/**************************************************/ 
//u8 _xdata TmpData8[4];
//bool CL6017G_ValidStop(unsigned int unFreq)//875~1080 unit:100kHz
bool  CL6017G_ValidStop(u16 unFreq)
{  
	bool   bStcFlag = 0;
	bool   bSt = 0;
	_xdata u16 unLoop = 0;
	int nRssi;
	_xdata u16 unEnvelope;
	_xdata u16 unFd;
	_xdata u8 ucPga;
	_xdata u8 temp[22]={0};

	unsigned long ulFreq;
//	unFreq = 918;
	 ulFreq= (unsigned long) unFreq * 100;  //modi by alpha 100827 
	 
	if(unFreq<875)return 0;

	// set frequency
	ulFreq >>= 2;//右移两位
	CL6017G_ControlData[2] = (u8) (ulFreq % 256);//reg24
	CL6017G_ControlData[1] = (u8) (ulFreq >> 8);//reg23	
	CL6017G_ControlData[4] &= 0xf3;//tune=0,seek=0 reg26
	CL6017G_ControlData[6] = 0xdf;//tune=0,seek=0 reg26
	I2C_WriteCL6017GReg(CL6017G_ControlData, 7);

	CL6017G_ControlData[4] |= 0x08;//tune=1, begin tune operaton reg26
	I2C_WriteCL6017GReg(CL6017G_ControlData,5);
	delay_10ms(5); // wait for 50ms
	
	do
	{
		delay_10ms(1);
		CL6017G_READ_REG(temp, 4);  //modi by alpha100827 old is 22
		bStcFlag = (bool) (temp[3] & 0x10); // STC indicator
		unLoop++;
	}while((!bStcFlag) && (unLoop != 0x4f/5)); //modi by alpha100827 old is 0xff

   if(bStcFlag)   //modi by alpha100827
   	{
	    delay_10ms(2);
   	    CL6017G_READ_REG(temp, 22);   //add by alpha100827 
		nRssi = temp[5];
		ucPga = temp[21];
		switch(ucPga)
		{
		case 0x01:
		case 0x03:
		case 0x07:
	
				nRssi -= 2;
				break;
		case 0x0f:
		case 0x3f:
				nRssi -= 3;
				break;
		case 0x1f:
		case 0x7f:
				nRssi -= 4;
				break;
		case 0xff:
				nRssi -= 7;  //modi by alpha110119  //0ld is 9
				break;
		default:
				break;
		}
			
		if(nRssi < 0)
		{
			nRssi = 0;
		}
		unEnvelope = ((unsigned int)temp[6] << 2) + (temp[7] >> 6);
		unFd = temp[4] + (((unsigned int)temp[3] & 0x01) << 8); //reg4/reg3 bit0
		if(unFd > 255)
		{
			unFd = 512 - unFd;
		}
		if((nRssi >= 155+5/*fm_cl6017_rssilev*/)  //155-190 默认163
			&& (unEnvelope <=(480+128/*fm_cl6017_envelopelev*2*/))
			&& (unFd <= 25+15/*fm_cl6017_fdlev*/)/*&&((temp[3]&0x02)==0x02)*/)
		{
			bSt = 1;
		}
		else
		{
			bSt = 0;					      
		}
   	}

	//MuteCL6017(0);	

	return bSt;
	
}

/**************************************************         
Function: CL6017_SearchByTune()

Parameter:	 
	searched_freq:a buffer for search frequency list
Description:
	search all the frequency.
Return:
	the number of the searched frequency.
/**************************************************/
//u8 CL6017_SearchByTune(u16* searched_freq)
//{
//	u16 freq;
//	u8 i=0;
//
//	for(freq=875;freq<1080;freq++)
//	{
//		if(CL6017_ValidStop(freq,875))
//		{
//			searched_freq[i++]=freq;
//		}
//	}
//	
//	return i;
//
//}
#if 1
u16 CL6017G_Read_ID(void)
{

    u8 _xdata Temp[2] = { 0x00 };

   	CL6017G_ControlData[0] = 0x64;    // index + 22 ---- reg correct index
	CL6017G_ControlData[1] = 0x69;
	CL6017G_ControlData[2] = 0x78;
	CL6017G_ControlData[3] = 0x10;   //0x10 -->32.768K,0X11-->12M,0X15-->24M,
	CL6017G_ControlData[4] = 0x02;
	CL6017G_ControlData[5] = 0xff;
	CL6017G_ControlData[6] = 0x1f;   //R28_bit<5:4>=01 0x2f
	CL6017G_ControlData[7] = 0xb2;
	CL6017G_ControlData[8] = 0x9b;  
	CL6017G_ControlData[9] = 0x05;
	CL6017G_ControlData[10] = 0x00;
	CL6017G_ControlData[11] = 0x90;
	CL6017G_ControlData[12] = 0x00;
	CL6017G_ControlData[13] = 0xaa;
	CL6017G_ControlData[14] = 0xb2;//0XBC
	CL6017G_ControlData[15] = 0x15;
	CL6017G_ControlData[16] = 0x96;
	CL6017G_ControlData[17] = 0x80;
   I2C_WriteCL6017GReg(CL6017G_ControlData,18);
   CL6017G_ControlData[5] &= 0xfe;   //POWER ON
   I2C_WriteCL6017GReg(CL6017G_ControlData,6);
   delay_10ms(15);  //delay 150ms
   CL6017G_READ_REG(Temp,2);	//ID=TEMP[0]
   CL6017G_ControlData[5] |= 0x01;   //POWER DOWN
    I2C_WriteCL6017GReg(CL6017G_ControlData,6);

#if 0
	    CL6017G_READ_REG(Temp,40);	//ID=TEMP[0]
	sys_printf("---------------CL6017G_Read_ID------------------");
	for(i=0;i<40;i++){
	printf("--%x----> 0x%x  \r\n",(u16)i,(u16)Temp[i]);

	}
	sys_printf("---------------CL6017G_Read_ID-----------------");
#endif	

	printf("CL6017G_Read_ID %x  \r\n",(u16)Temp[0]);

   return (u16)Temp[0];
}

void CL6017G_PowerOff(void)
{
//	if(set_fm_clock == 0)
//	{
// 		WKUPPND = 0x10;  //set bit[5:4] = 01, output OSC frequancy to P05
//    	P0DIR |= (1<<5);  //P05 set input 
//	 }
	CL6017G_ControlData[0] |= 0x20;//mute on
	CL6017G_ControlData[4] &= 0xf3;//tune=0,seek=0
	I2C_WriteCL6017GReg(CL6017G_ControlData,5);

	CL6017G_ControlData[5] |= 0x01; // set DISABLE=1 to power down
	I2C_WriteCL6017GReg(CL6017G_ControlData,6);
}
#endif

#endif

