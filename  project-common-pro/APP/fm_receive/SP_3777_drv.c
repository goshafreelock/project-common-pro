
#include "iic.h"
#include "config.h"
#ifdef USE_SP3777_FM
#define CS1000_RD_CTRL   0x21 
#define CS1000_WR_CTRL   0x20 

_xdata u8 dat[32];
_xdata u8 readdata[32]; 

void SP3777_Write(u16 size);
void  SP3777_Read(u16 size);
void Freq_Write(u16 TunerFrequency);
 void FM_volume(u16 Vol_FM);
/*******************************************************


********************************************************/
void SP3777_init()
{
	dat[0] = 0xe4;  //0x64    standby
    	dat[1] = 0x81;   
    	dat[2] = 0x42; 
    	dat[3] = 0x30;
	dat[4] = 0x19; 			
	dat[5] = 0xc0; 
	dat[6] = 0x38; 
	dat[7] = 0x56;
	dat[8] =  0x05;
	dat[9] =  0x73;
	dat[10] = 0xB4;
	dat[11] = 0xf4;  
    	dat[12] = 0xad; //cd
    	dat[13] = 0xc1;
	dat[14] = 0xc2; 			
	dat[15] = 0x04; 
	dat[16] = 0x01; 
	dat[17] = 0x25;
	dat[18] = 0xff;
	dat[19] = 0xfd;
	dat[20] = 0x06;
   	dat[21] = 0x0f;   
    	dat[22] = 0x41; 
    	dat[23] = 0x1d;
	dat[24] = 0x21; 			
	dat[25] = 0x0d; 
	dat[26] = 0x3f; 
	dat[27] = 0x6f;
	dat[28] = 0x00;
	dat[29] = 0x00;

    	dat[0] |= 0x20;	
	dat[0] &= 0x7f; //power up	

	SP3777_Write(1);
    	delay_10ms(10);
    	SP3777_Write(30); // write the initial values for all R/W registers	
	delay_10ms(20);

	FM_volume(0xff);
	#if 0
    	my_memset((u8 _xdata*)readdata,0,32);
	SP3777_Read(32);
	sys_printf("---------------------------------------------------------------");
	for(i=0;i<32;i++)
		printf("-->SP3777_Read %x <---\r\n",(u16)readdata[i]);
	sys_printf("---------------------------------------------------------------");
	#endif
}

/***************************************************************************


***************************************************************************/
 void SP3777_Powerdown()
{
	dat[0] |= 0x20;  // mute on
	dat[0] |= 0x80;  // power down
	SP3777_Write(1);	
}

/**************************************************************************************
*   函数名称：CS1000_FM_SET_volume
*   功    能：
*   输入参数：unsigned int volume
*   输出参数：
*   说    明：Set CS1000 FM Volume
**************************************************************************************/
 void FM_volume(u16 Vol_FM)
{
	u16 temp;
	u16 vol;
	vol=Vol_FM/2;
	if(vol > 0x0f)
		{
		   vol = 0x0f;			
		}
	dat[2] &=0xC3;
	temp = vol<<2;
	temp &= 0x3c; //0x3c=00111100
	dat[2] |= temp;

	if(vol == 0)
		dat[0] |= 0x20;	
	else
		dat[0] &= 0xDF;
	SP3777_Write(3);			
}
/***************************************************************************


**************************************************************************/
 void SP3777_MUTE(bool flag)
{
    if(flag)
	dat[0] |= 0x20;
    else
	dat[0] &= 0xDF;
	
	SP3777_Write(1);
       delay_10ms(2); // delay 2ms
	
}

/**************************************************************************************
*   函数名称：CS1000_FMSeek_TuneMethod
*   功    能：
*   输入参数：unsigned int TunerFrequency, the frequency unit is 10kHz           
*   输出参数：bool seekover, return the indicator if the seek operation is completed
*	      signed short *pryFD,return current channel's fd
*   说    明：seek operation with tune method step by step, judge the threshold by the software
**************************************************************************************/
//----------------------------------------------------------------------------
//rssi=176 snr=38(默认值)
//rssi越大，snr越小，灵敏度越小 搜得的台就越少
//----------------------------------------------------------------------------	

 bool SP3777_FMSeek_TuneMethod(u16 TunerFrequency)
{
    u8 seekover=0;
    u16 stcflag=0;	
    u8 loop=0;
    u16 rssi=0;
    u16 snr=0;
    u16 fd=0;
    u8 fm_rx_stereo=0;
    Freq_Write(TunerFrequency);
    SP3777_MUTE(1); 
    delay_10ms(5);; // delay 70ms
    do
    {
     SP3777_Read(6);		  
     stcflag=readdata[0]&0x0004; // STC bit
   
     loop++;
     delay_10ms(1); // delay 1ms
     }while((!stcflag)&&(loop!=0x1f));   
    
    if(stcflag)  //STC=1
    {  		
        rssi=readdata[1];
	 snr=readdata[2]/4;	 	 
        fd=readdata[5];
        fm_rx_stereo = readdata[0] & 0x01; // st/mono bit

#if 0
	printf("----->stcflag 0x%x \r\n",stcflag);
	printf("----->rssi %d \r\n",rssi);
	printf("----->snr %d \r\n",snr);
	printf("----->fd %d \r\n",fd);
	printf("----->fm_rx_stereo 0x%x \r\n",fm_rx_stereo);
#endif
       if(fd > 127)
        {
          fd = 256 - fd;	 		
        }
       if((rssi >= 170) && (fd <= 20) && (snr <= 38)/*&&(fm_rx_stereo&0x01)*/) //seek threshold judgement      
       {
           if(((TunerFrequency*10) != 9600))
              seekover=1;            
           else
              seekover=0;
       } 
       else
       {
        seekover=0;
       }
                    
    }
       SP3777_MUTE(0);
     return seekover; 
}



/*********************************************************


***************************************************************/
 void Freq_Write(u16 TunerFrequency)
{		
        u16 ch=0;
	printf("------------------->TunerFrequency %d \r\n",TunerFrequency);

    	ch = (TunerFrequency*10 - 7000) / 5;

	printf("------------------->ch 0x%x \r\n",ch);
		
    	dat[2] &= 0xfc;
    	dat[2] |= ((ch & 0x0300) >> 8);
    	dat[3] = ch & 0xff;

    	// seek operation
    	dat[0] &= 0xDF;
    	dat[0] &= 0xfd; // tune=0
    	//writedata[0] |= 0x0020; // mute
    	dat[0] &= ~0x20; // unmute
    	SP3777_Write(4);
    	
    	dat[0] |= 0x02; // TUNE=1, begin tune operation

    	SP3777_Write(1);

	delay_10ms(1);
	#if 1

	sys_printf("-------------");
	printf("000-->Freq_Write %x \r\n",(u16)dat[0]);
	printf("000-->Freq_Write %x \r\n",(u16)dat[1]);
	printf("000-->Freq_Write %x \r\n",(u16)dat[2]);
	printf("000-->Freq_Write %x \r\n",(u16)dat[3]);
	
	SP3777_Read(6);
	sys_printf("-------------");
	printf("111-->Freq_Write %x \r\n",(u16)readdata[0]);
	printf("222-->Freq_Write %x \r\n",(u16)readdata[1]);
	printf("333-->Freq_Write %x \r\n",(u16)readdata[2]);
	printf("444-->Freq_Write 0x%x \r\n",(u16)((((readdata[2]&0x01)<<8)|((readdata[3]&0xFF)))/*50+70*/));//((((readdata[2]&0x01))|((readdata[3]&0xFF)<<8))/*50+70*/)
	printf("555-->Freq_Write %x \r\n",(u16)readdata[4]);
	printf("666-->Freq_Write %x \r\n",(u16)readdata[5]);
	#endif
}





/**********************************************************************


********************************************************************/
 void  SP3777_Read(u16 size)	//state=0->success  state=1->fail 
{
  	u16 i;

  	iic_start();
    	iic_sendbyte(CS1000_RD_CTRL);

  	for(i=0;i<size-1;i++)
	{
	  	readdata[i] = iic_revbyte_io();
    		s_ack(0);	
	}
	readdata[i] = iic_revbyte_io();    
	s_ack(1);	
	
    	iic_stop();
 
}
/************************************************************



*************************************************************/
 void SP3777_Write(u16 size) //state=0->success  state=1->fail
{
	u16 i;
	iic_start();
	iic_sendbyte(CS1000_WR_CTRL);
	 
    	for(i=0;i<size;i++)
	{
	   iic_sendbyte(dat[i]);
    	}
    	iic_stop();
}

u16 Read_SP3777_ID()
{
	u16 module_ID =0xFFFF;
	SP3777_Read(6);
	module_ID = readdata[4];
	#if 0
	sys_printf("-------------");
	printf("111-->Read_module_ID %x \r\n",(u16)readdata[0]);
	printf("222-->Read_module_ID %x \r\n",(u16)readdata[1]);
	printf("333-->Read_module_ID %x \r\n",(u16)readdata[2]);
	printf("444-->Read_module_ID %x \r\n",(u16)readdata[3]);
	printf("555-->Read_module_ID %x \r\n",(u16)readdata[4]);
	printf("666-->Read_module_ID %x \r\n",(u16)readdata[5]);
	#endif
	printf("Read_SP3777_ID %x \r\n",module_ID);
	return  module_ID;
}
#endif
