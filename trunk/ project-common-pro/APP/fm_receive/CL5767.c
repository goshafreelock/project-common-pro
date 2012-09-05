/*
********************************************************************************************
* Version: V2.0 for FM5767
* Description: the reference code include I2C protocol between FM tuner and MCU of main chip 
* by GPIO method, and how to implement FM tuner power up initialization/power down/tune/seek 
* functions
********************************************************************************************
*/	

#include "Custom_config.h"

#ifdef USE_CL5767_FM	

#include "CL6017.h"
#define FM5767_RD_CTRL   	0x21 
#define FM5767_WR_CTRL   	0x20

/**************************************************************************************
* macro definition for slave address of I2C protocol control, i.e. FM tuner address
**************************************************************************************/
 


xd_u8 FM5767ControlData[24];

#if 0
void  SetSDAState(u8 state) 
{
	SDA=(bool)(state);
}

u8  GetSDAState(void)
{
	return (u8)SDA;
}


/**************************************************************************************
* how to implement I2C protocol control between FM tuner and MCU of main chip by GPIO method
**************************************************************************************/
void DelayXus(u8 X)
{
	u8 i;
	for(i = X/2; i >= 1; i--)
		delay_nops(CurrCpuFreq);
}


void I2C_Start(void)
{
   SCL_HIGH;		SDA_HIGH;				
   DelayXus(1);
   SDA_OUT;											//enable output																							

   DelayXus(50);
   SDA_LOW;
   DelayXus(30);
   SCL_LOW;
   DelayXus(20);
}

void I2C_Stop(void)
{
	SCL_LOW;
	SDA_LOW;
	DelayXus(2);
    SDA_OUT;
    
	DelayXus(2);
	SCL_LOW;
	SDA_LOW;
	DelayXus(10);
	SCL_HIGH;
	DelayXus(20);
	SDA_HIGH;
	DelayXus(20);
}

void I2C_SendAck(u8 ack)
{
		SetSDAState(ack);
   	DelayXus(1);
  	SDA_OUT;

  	SCL_HIGH;
  	DelayXus(20);
  	SCL_LOW;
  	DelayXus(20);
}

u8  I2C_SendByte(u8 byte)
{
 	int i;
 	u8 ack = 0;
 	
 	SetSDAState(byte&0x80);  	
  SDA_OUT;
  
	DelayXus(10);
  	for(i=7;i>=0;i--)
	{
		SetSDAState(byte&0x80);
		
	 	byte <<= 1;
	  DelayXus(20);
	  
	  SCL_HIGH;
	  DelayXus(40);
	  
	  SCL_LOW;
	  DelayXus(20);
	}
  
  	SDA_IN;
  	DelayXus(10);
  
  	SCL_HIGH;
  	DelayXus(40);		
 		ack=GetSDAState();
  	SCL_LOW;
 	DelayXus(40);
  	return ack;
}

u8 I2C_ReadByte(void)
{
 	int i;
 	u8 byte = 0;
 	SDA_IN;
 	DelayXus(10);
 	for(i=7;i>=0;i--)
	{
	   SCL_HIGH;
	   DelayXus(20);

	  byte <<= 1;
	  byte |= GetSDAState();
	  DelayXus(20);
	  
	  SCL_LOW;
	  DelayXus(40);
	}
  	return byte;
}
#endif
void I2C_ReadFM5767Reg(u8 *buf,u8 size)	//state=0->success  state=1->fail 
{
#if 0
  	u8 i,state = 0;
  	I2C_Start();
  	if(I2C_SendByte(FM5767_RD_CTRL))
  	{
	  state = 1;
	  goto I2C_STOP;
  	}

  	for(i=0;i<size-1;i++)
	{
	  data[i] = I2C_ReadByte();
	  I2C_SendAck(0);
	}
   	data[i] = I2C_ReadByte();
   	I2C_SendAck(1);
  
   I2C_STOP:
	 I2C_Stop();
	 return state;
#else		
    iic_readn(FM5767_RD_CTRL,0xff,buf,size);
#endif	 
}

void I2C_WriteFM5767Reg(u8 *buf,u8 size) //state=0->success  state=1->fail
{
#if 0
	u8 i,state = 0;;
	I2C_Start();
	if(I2C_SendByte(FM5767_WR_CTRL)) 
	  {
	    state = 1;
	    goto I2C_STOP;
	  }
    for(i=0;i<size;i++)
	{
	   if(I2C_SendByte(data[i]))
	   	{
	   	 state = 1;
		 break;
	   	}
	}
  I2C_STOP:
   I2C_Stop();
   return state;
#else
   	iic_write(FM5767_WR_CTRL,0xff,buf,size);     
#endif
}



/**************************************************************************************
* how to implement FM tuner initialization/tune/seek/stereo indicator functions
**************************************************************************************/


/**************************************************************************************
*   函数名称：FM5767_FMInit
*   功    能：
*   输入参数：
*   输出参数：
*   说    明：  initial definition of FM5767 READ/WRITE registers, FM power up and initialization operation
**************************************************************************************/
void FM5767_FMInit(void)
{
	// initial default value of FM5767 READ/WRITE registers 03h~0Eh
  	FM5767ControlData[0] = 0xe4;  //e4
  	FM5767ControlData[1] = 0x81;  //81-->83(auto HLSI)
  	FM5767ControlData[2] = 0x3e;
  	FM5767ControlData[3] = 0xf8;
	FM5767ControlData[4] = 0x1f;  //	1f-1d		
	FM5767ControlData[5] = 0x40; 
	FM5767ControlData[6] = 0x38;
	FM5767ControlData[7] = 0x5a;
	FM5767ControlData[8] = 0xe8;
	FM5767ControlData[9] = 0xac;
	FM5767ControlData[10] = 0xb0;
	FM5767ControlData[11] = 0xf1;  
	FM5767ControlData[12] = 0x8b;
	FM5767ControlData[13] = 0xaa;   
	FM5767ControlData[14] = 0xc6;
	FM5767ControlData[15] = 0x04;
	FM5767ControlData[16] = 0x6d;
	FM5767ControlData[17] = 0x25;
	FM5767ControlData[18] = 0xff;
	FM5767ControlData[19] = 0xfc;
	FM5767ControlData[20] = 0x12; 
	FM5767ControlData[21] = 0x0f;
	FM5767ControlData[22] = 0x45;
	FM5767ControlData[23] = 0x1d;
	
	// power up and initial operation
	// if initially set to 94.2mhz radio, channel = (94.2-70)/0.05=484
	FM5767ControlData[2] &= 0xFC; 
	FM5767ControlData[2] |= (484 & 0x0300)>>8;
	FM5767ControlData[3] = 484 & 0xFF;
	//

	FM5767ControlData[0] &= 0x7f; //power up
	I2C_WriteFM5767Reg(FM5767ControlData,24);	
	
	delay_10ms(80); // wait 800ms for crystal oscillate stable

	FM5767ControlData[0] |= 0x02; // TUNE=1, begin tune operation
	I2C_WriteFM5767Reg(FM5767ControlData,1);
	delay_10ms(10); // delay 100ms

	FM5767ControlData[0] &= 0xdf;  // mute off
	I2C_WriteFM5767Reg(FM5767ControlData,1);	
}


/**************************************************************************************
*   函数名称：FM5767_FMTune
*   功    能：
*   输入参数：TunerFrequency, the unit is 10khz
*   输出参数：
*   说    明： tune to certain frequency and output audio
**************************************************************************************/
void FM5767_FMTune(u8 TunerFrequency)
{
	u8 ch = 0;

	// frequency transfer to channel number,  channel=(frequencyMhz-70)/0.05, e.g. 87.5Mhz->350, 108Mhz->760
	ch = (TunerFrequency - 7000)/5; 

	// set channel number 
	if(TunerFrequency>10000)
		FM5767ControlData[1] &= 0xfe;
	else
		FM5767ControlData[1] |= 0x01;
	FM5767ControlData[2] &= 0xfc;
	FM5767ControlData[2] |= (ch & 0x0300)>>8;
	FM5767ControlData[3] =	ch & 0xff;
	//

	// tune function
	FM5767ControlData[0] &= 0xdf;// mute off
	FM5767ControlData[0] &= 0xfd;// tune=0
	I2C_WriteFM5767Reg(FM5767ControlData,4);

	FM5767ControlData[0] |= 0x02;//tune=1, begin tune operaton
	I2C_WriteFM5767Reg(FM5767ControlData,1);
	delay_10ms(5); // wait for 50ms

}    




/**************************************************************************************
*   函数名称：FM5767_FMSeekFromCurrentCh
*   功    能：
*   输入参数：bool seekUp: 0-seek up, 1-seek down
*   输入参数：u8 *TunedFrequency: the radio frequency stay in when seeking process complete, the frequency unit is 10khz	 

*   输出参数：bool sfflag: 0-Seek successful  1-Seek failure
*   说    明： seek from current channel automaticly,if want to seek from certain channel,  use FM5767_FMTune to certain channel ahead
**************************************************************************************/
bool FM5767_FMSeekFromCurrentCh(bool seekUp, u8 *TunedFrequency)
{
	u8 ch = 0;
  	u8  loop,loopSt=0;
	bool   stcflag,bSt;
  	u8 Temp[6];
	u8 rssi, envelope,fd;

	I2C_ReadFM5767Reg(Temp,6);	
	ch = (Temp[2]&0x03)*256 + Temp[3]&0xff;
	
	do
	{
		if (seekUp)
		{
			if(ch>=760)  // 108M
				ch = 350;  // 87.5
			else
				ch = ch +2; // +100k
		}
		else
		{
			if(ch<=350)
				ch = 760;
			else
				ch = ch -2;
		}

		if(ch>600)  // if freq>100M, Low Injection
			FM5767ControlData[1] &= 0xfe;
		else
			FM5767ControlData[1] |= 0x01;

		FM5767ControlData[2] &= 0xfc;
		FM5767ControlData[2] |= (ch & 0x0300)>>8;
		FM5767ControlData[3] =	ch & 0xff;

		// seek operation
		FM5767ControlData[0] |= 0x20; // mute on
		FM5767ControlData[0] &= 0xfd; //tune=0
		FM5767ControlData[0] &= 0xfe; //seek=0
		I2C_WriteFM5767Reg(FM5767ControlData,2);

		FM5767ControlData[0] |= 0x02; //tune=1, 
		I2C_WriteFM5767Reg(FM5767ControlData,1);
		delay_10ms(5); // delay 50ms

		// waiting seek completed
		stcflag=0;
		loop=0;
		rssi = 0;
		envelope = 0;
		fd = 0;
	    do
		{	
			I2C_ReadFM5767Reg(Temp,6);		  
	        	stcflag=Temp[0]&0x04; // STC indicator			
	  		loop++;
	   	}while((!stcflag)&&(loop!=0xff));

		rssi = Temp[1]&0xff;
		envelope = (Temp[2]&0xff)/4;
		fd = Temp[5]&0xff;
		if(fd>127)
			fd = 256 - fd;
		if((rssi>172)&&(envelope<=38)&&(fd<=14))
		{
			bSt = 1;
			*TunedFrequency=ch*5+7000;
		}
		else
		{
			bSt = 0;
		}
		
		loopSt++;	
		
	}while((!bSt)&&(loopSt++<=0xff));
	
	

	FM5767ControlData[0] &= 0xdf;// mute off, audio output
	I2C_WriteFM5767Reg(FM5767ControlData,1);

	return bSt;
}

void FM5767_FMPowerdown(void)
{
	FM5767ControlData[0] |= 0x20;  // mute on
	I2C_WriteFM5767Reg(FM5767ControlData,1);	

	FM5767ControlData[0] |= 0x80; // set DISABLE=1 to power down
	I2C_WriteFM5767Reg(FM5767ControlData,1);
}
void MuteFM5767(bool flag)
{
	if(flag)
	{
		FM5767ControlData[0]|=0x20;
	}
	else
	{
		FM5767ControlData[0]&=0xdf;
	}
	I2C_WriteCL6017GReg(FM5767ControlData, 1);	
       delay_10ms(2); // delay 1ms
}

#endif

