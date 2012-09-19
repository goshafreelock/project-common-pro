#include "Custom_config.h"
#include "bk1080.h"
#include "clock.h"
#include"uart.h"
#include "config.h"
#include "fm_rev.h"

#include "entry.h"

#ifdef FM_USE_BK1086
#undef USE_BK1080_FM
#endif

#ifdef USE_BK1080_FM		
extern bool iic_busy;
 extern bool  sys_clock_flag;
//BK1080 initialization value
_code  u16 HW_Reg[]=
{
0x0008,
0x1080,
#ifdef XTAL_CLOCK	//reg2
0x1201,	//for crystal clock
#else
0x0201,	//for extern clock share crystal with mcu
#endif
0x0000,
0x40C0,
0x0A5F,
0x002E,
0x02FF,
0x5B11,
0x0000,
0x411E,
0x0000,
0xCE00,
0x0000,
0x0000,
0x1000,
0x0010,//reg16
0x0002,//0x0002,//
0x13FF,
0x9852,
0x2000,//0000
0x0000,
0x4008,  //0008
0x0000,
0x51E1,
0x38bc,//0x20bC,
0x2645,
0x00E4,
0x1CD8,
0x3A50,
0xEAF0,
0x3000,//31
0x0200,
0x0000,
0x0001,  //for 1084evc1
0x0000,  //for 1084evc1
0x00c2,  //for 1084evc1
};

void Delay1us()//please revise this function according to your system
{
	u16 i;
	if (!sys_clock_flag) return;
	for(i=0;i<10;i++);
}
/*************************************************
  Function:       BEKEN_I2C_init
  Description:    BEKEN I2C initialize
  Input:          None
                          
  Output:         None
  Return:         None
*************************************************/
void BEKEN_I2C_init(void)
{
    SDADIROUT();                  //SDA output
    SCLDIROUT();                  //SCL output
    BK_CLK_HIGH();
    BK_DATA_HIGH();
}

/*************************************************
  Function:       BEKEN_I2C_Start
  Description:    BEKEN I2C transaction start
  Input:          None
                          
  Output:         None
  Return:         None
*************************************************/
void BEKEN_I2C_Start(void)
{
    BEKEN_I2C_init();
    Delay1us();
    BK_DATA_LOW();
    Delay1us();
    BK_CLK_LOW();
    Delay1us();
    BK_DATA_HIGH();
}

/*************************************************
  Function:       BEKEN_I2C_Stop
  Description:    BEKEN I2C transaction end
  Input:          None
                          
  Output:         None
  Return:         None
*************************************************/
void BEKEN_I2C_Stop(void)
{
    SDADIROUT();
    BK_DATA_LOW();
    Delay1us();
    BK_CLK_HIGH();
    Delay1us();
    BK_DATA_HIGH();
    Delay1us();
}

/*************************************************
  Function:       BEKEN_I2C_ack
  Description:    send ACK,accomplish a operation
  Input:          None
                          
  Output:         None
  Return:         None
*************************************************/
void BEKEN_I2C_ack(void)
{
    SDADIROUT();

    BK_CLK_LOW();
    BK_DATA_LOW();
    Delay1us();

    BK_CLK_HIGH();
    Delay1us();
    BK_CLK_LOW();
}      

/*************************************************
  Function:       BEKEN_I2C_nack
  Description:    send NACK,accomplish a operation
  Input:          None
                          
  Output:         None
  Return:         None
*************************************************/
void BEKEN_I2C_nack(void)
{
    SDADIROUT();

    BK_CLK_LOW();
    BK_DATA_HIGH();
    Delay1us();

    BK_CLK_HIGH();
    Delay1us();
    BK_CLK_LOW();
}

/*************************************************
  Function:       BEKEN_I2C_ReceiveACK
  Description:    wait ACK,accomplish a operation
  Input:          None
                          
  Output:         None
  Return:         ack flag
*************************************************/
u8 BEKEN_I2C_ReceiveACK(void)
{
    u32 ackflag;
    SDADIRIN();
    Delay1us();
    BK_CLK_HIGH();
    Delay1us();
    ackflag = (u8)BK_DATA_READ();
    BK_CLK_LOW();
    Delay1us();
    return ackflag;
}

/*************************************************
  Function:       BEKEN_I2C_sendbyte
  Description:    write a byte
  Input:          a byte written
                          
  Output:         None
  Return:         None
*************************************************/
void BEKEN_I2C_sendbyte(u8 I2CSendData)
{
   
    u8  i;
    SDADIROUT();
    Delay1us();;
    for(i = 0;i < 8;i++)
    {
        if(I2CSendData & 0x80)
        {
            BK_DATA_HIGH();     //if high bit is 1,SDA= 1
        }
        else
            BK_DATA_LOW();                               //else SDA=0

       	Delay1us();
        BK_CLK_HIGH();
       	Delay1us();
        I2CSendData <<= 1;                          //shift left 1 bit
        BK_CLK_LOW();
    }                       
}

/*************************************************
  Function:       BEKEN_I2c_Readbyte
  Description:    read a byte
  Input:          None
                          
  Output:         None
  Return:         a byte read
*************************************************/
u8 BEKEN_I2c_Readbyte(void)
{
    u8 i;
    u8 ucRDData = 0;                     //return value
    
    SDADIRIN();
    Delay1us();;
    for(i = 0;i < 8;i++)
    {
        BK_CLK_HIGH();
        ucRDData <<= 1;
        Delay1us();
        if(BK_DATA_READ())
            ucRDData|=0x01;
        BK_CLK_LOW();
        Delay1us();
    }
    return(ucRDData);
}

/*************************************************
  Function:       BEKEN_I2c_Read
  Description:    read a array
  Input:          reg: register number
                  len:the length of read data   
                          
  Output:         pBuff: a buffer contain read data
  Return:         None
*************************************************/
void BEKEN_I2c_Read(u8 reg,u8 *pBuf,u8 len)
{
    u8 i;
    u8 Addr;

    iic_busy = 1;

    Addr=CHIP_DEV_ID;//device address.

    BEKEN_I2C_Start();

    BEKEN_I2C_sendbyte(Addr);   
    BEKEN_I2C_ReceiveACK();

    reg=reg<<1;
    reg|=0x01;
    BEKEN_I2C_sendbyte(reg);
    BEKEN_I2C_ReceiveACK();

    for(i=0;i<len-1;i++)
    {
        pBuf[i] = BEKEN_I2c_Readbyte();
        BEKEN_I2C_ack();
    }
    pBuf[i] = BEKEN_I2c_Readbyte();
    BEKEN_I2C_nack();
    
    BEKEN_I2C_Stop();

     iic_busy = 0;

}

/*************************************************
  Function:       BEKEN_I2c_Write
  Description:    write a array
  Input:          reg: register number
                  pBuff: a buffer contain written data
                  len:the length of written data      
  Output:         None
  Return:         None
*************************************************/
void BEKEN_I2c_Write(u8 reg,u8 *pBuf,u8 len)
{
    u8 i;
    u8 Addr;

    iic_busy = 1;

    Addr=CHIP_DEV_ID;//device address.

    BEKEN_I2C_Start();

    BEKEN_I2C_sendbyte(Addr);
    BEKEN_I2C_ReceiveACK();

    reg=reg<<1;
    BEKEN_I2C_sendbyte(reg);   
    BEKEN_I2C_ReceiveACK();
	 
    for(i=0;i<len;i++)
    {
        BEKEN_I2C_sendbyte(pBuf[i]);
        BEKEN_I2C_ReceiveACK(); 
    }
    BEKEN_I2C_Stop();
	
    iic_busy = 0;
	
}


/**************************************************         
Function: EnableWire2()
Parameter: 
	b_enable: 1: wire2;0: wire3;                                         

Description:
	Enable wire2 or wire 3 mode
/**************************************************/ 
#if defined(USE_FM_GPIO)
void BK1080__gpio_ctrl(bool fm_ctrl_flag,u8 gpio_num)
{
	u8 TmpData[2];
	//printf(" BK1080__gpio_ctrl \r\n");
	BEKEN_I2c_Read(0x04,TmpData,2); //read reg2,with 4 bytes
	if(fm_ctrl_flag)
	{
		if(gpio_num==FM_GPIO_1)
		  TmpData[1]|=  0x03;
		else if(gpio_num==FM_GPIO_2)
		  TmpData[1]|=  0x0C;
	}
	else
	{
		if(gpio_num==FM_GPIO_1)
		  TmpData[1]&=~0x03;
		else if(gpio_num==FM_GPIO_2)
		  TmpData[1]&=~0x0C;
	}
	BEKEN_I2c_Write(0x04,TmpData,2); //write reg2,with 4 bytes
}
#endif
/**************************************************         
Function: BK1080_FreqToChan()
Parameter: 
	frequency: FM frequency *10 ,such as  1017,933,1077..                                      

Description:
	change from frequency to channel
/**************************************************/ 

u16 BK1080_FreqToChan(u16 frequency)
{
	u16 bottomOfBand;
	u8 channelSpacing;
	u16 channel;
	
	bottomOfBand = 760;
	channelSpacing=1;
		
	channel = (frequency - bottomOfBand) / channelSpacing;
	
	return (channel);	

}


u16 BK1080_Get_ID()
{
	u8 TmpData[2];
	u16 ChipID = 0xFFFF;

	//sys_printf(" FM SET BK1080_PowerOffProc ");
	BEKEN_I2c_Read(0x01,TmpData,2); //read reg2,with 4 bytes


	ChipID = TmpData[0];
    	ChipID = ((ChipID<<8) | TmpData[1]);
	printf(" BK1080ChipID %x \r\n",ChipID);
	return ChipID;
}


/**************************************************         
Function: Chip_wire2_Initialize()
Parameter: 
	None                                         

Description:
	BK1080 I2C mode initialization
/**************************************************/ 
void BK1080_Intialization()
{
	u8 index;
	u8 _xdata bk1080_writeData8[74];
	u8 TmpData[2];

	delay_10ms(50);//delay 1s,please revise delay time according to your MCU


	for(index = 0; index < 37; index++)
	{
		bk1080_writeData8[index*2] = (HW_Reg[index] >> 8)&0xff;
		bk1080_writeData8[index*2+1] = (HW_Reg[index])&0xff;
	}

	BEKEN_I2c_Write(0,&(bk1080_writeData8[0]),68);//start from reg2,total 60 byte

	delay_10ms(10);//delay 250ms
	bk1080_writeData8[25*2+1]&=0x7f;
	BEKEN_I2c_Write(25,&(bk1080_writeData8[25*2]),2);
	bk1080_writeData8[25*2+1]|=0x80;
	BEKEN_I2c_Write(25,&(bk1080_writeData8[25*2]),2);

	delay_10ms(3);//delay 60ms
	BEKEN_I2c_Read(0x04,TmpData,2); //read reg2,with 4 bytes

		//printf(" BK1080IntializationOK=%x ",TmpData[0]);


}

void BK1080_SetMute(bool mute)
{
	u8 TmpData[2];

	BEKEN_I2c_Read(0x02,TmpData,2); //read reg2,with 4 bytes

	if(mute)
		{
			//sys_printf(" FM SET BK1080_SetMute ");

	 	TmpData[0]|=  0x40;
		}
	else
		{
			//sys_printf(" FM SET BK1080_Set UNMute ");

		TmpData [0]&=0xbf;
		}

	BEKEN_I2c_Write(2,TmpData,2); //write reg2,with 4 bytes
}
void BK1080_SetVolume(u8 vol)
{
	u8 TmpData[2];
	
	if(vol ==0){
		BK1080_SetMute(TRUE);
		return;
	}
	else{
		BK1080_SetMute(FALSE);
	}
	delay_10ms(1);//delay 60ms
	BEKEN_I2c_Read(0x05,TmpData,2); //read reg2,with 4 bytes
	//delay_10ms(2);//delay 60ms

	TmpData[1] =((TmpData[1]&0xF0)|vol);

	BEKEN_I2c_Write(0x05,TmpData,2); //write reg2,with 4 bytes
	delay_10ms(2);//delay 60ms

}

void BK1080_PowerOffProc()
{
	u8 TmpData[2];

	//sys_printf(" FM SET BK1080_PowerOffProc ");
	BEKEN_I2c_Read(0x02,TmpData,2); //read reg2,with 4 bytes
		TmpData[1] |=0x41;

	BEKEN_I2c_Write(2,TmpData,2); //write reg2,with 4 bytes
}

/**************************************************         
Function: BK1080_SetFreq()
Parameter: 
	curFreq: FM frequency *10 ,such as  1017,933,1077..                                      

Description:
	set FM to a frequency
/**************************************************/ 
void  BK1080_SetFreq(u16 curFreq)
{  
	u16 curChan;
	u8 TmpData8[2];

	//BEKEN_I2c_Read(2,TmpData8,4); //read reg2,with 4 bytes

	curChan=BK1080_FreqToChan(curFreq); /*stop seek and tune*/

	//TmpData8[0]&=0xfe; 
	TmpData8[0] =0x0;//reset tune
	TmpData8[1]=curChan&0xff;
	BEKEN_I2c_Write(3,TmpData8,3); //write reg2,with 4 bytes


	TmpData8[0]=(curChan>>8)&0xff;
	TmpData8[0] |= 0x80;//start tune
	TmpData8[1]=curChan&0xff;
	BEKEN_I2c_Write(3,TmpData8,2); //write reg2,with 4 bytes

	
	TmpData8[0] &= 0x7F;//start tune
	BEKEN_I2c_Write(3,TmpData8,2); //write reg2,with 4 bytes



}


/**************************************************         
Function: BK1080_ValidStop()

Parameter:
	freq:FM frequency *10 ,such as  1017,933,1077...  
	start_freq:lowest frequency,in China,start_freq=875
Description:
	check a frequency is a valid.
Return:
	1:ok
	0:false	
/**************************************************/
u16 _xdata g_freq_deviation_array[1081-MIN_FRE];
bool BK1080_ValidStop(u16 freq,u16 start_freq)
{	
	static _xdata u16 last_tuned_freq=0;//static variable
	static _xdata u16 g_last_freq_deviation_value=0;
	u16 cur_freq_deviation;
	u8 TmpData8[8];

	BK1080_SetFreq(freq);
#if defined(VOL_TUNE_FREQ_VOL)||defined(VOL_TUNE_FREQ_ONLY)||defined(VOL_TUNE_NEW_VOLUME_KEY_FEATURE)
	if( get_radio_freq_tune_protect()){
		
	}
	else
#endif	
	{
#if defined(K000_HG_898_V001)||defined(FAST_BAND_SCAN_SPEED)
	delay_10ms(10);//delay 70ms
#else
	delay_10ms(20);//delay 70ms
#endif
	}
////////////////////////////////////
//new added 2009-05-30
	BEKEN_I2c_Read(0x07,TmpData8,2);//start from reg 0x7,with 2bytes

	cur_freq_deviation=TmpData8[0];
	cur_freq_deviation<<=8;
	cur_freq_deviation|=TmpData8[1];
	cur_freq_deviation=cur_freq_deviation>>4;

	    g_freq_deviation_array[freq-start_freq]=cur_freq_deviation;


////////////////////////////////////

	BEKEN_I2c_Read(7,TmpData8,8);//start from reg7,with 8bytes
	
	if(TmpData8[6]&0x10)    //check AFCRL bit12
	{
		last_tuned_freq=freq;//save last tuned freqency
		g_last_freq_deviation_value=cur_freq_deviation;
		return 0;//false
	}

	if(TmpData8[7]<12) //RSSI<10  信号强度


	//if(TmpData8[7]<10) //RSSI<10  信号强度

	//if(TmpData8[7]<12) //RSSI<10  信号强度
	{
		last_tuned_freq=freq;//save last tuned freqency
		g_last_freq_deviation_value=cur_freq_deviation;
		return 0;//false
	}

	//if( (TmpData8[1]&0xf) <3) //SNR<2  3---5 假台


	if( (TmpData8[1]&0xf) <2) //SNR<2  3---5 假台
	{
		last_tuned_freq=freq;//save last tuned freqency
		g_last_freq_deviation_value=cur_freq_deviation;
		return 0;//false
	}


//add frequency devation check
//if( (cur_freq_deviation>=0x64)&&(cur_freq_deviation<=(0xfff-0x64))) ///微调
if( (cur_freq_deviation>=250)&&(cur_freq_deviation<=(0xfff-250))) ///微调

//if( (cur_freq_deviation>=0x96)&&(cur_freq_deviation<=(0xfff-0x96))) ///微调
	{
		last_tuned_freq=freq;//save last tuned freqency
		g_last_freq_deviation_value=cur_freq_deviation;

		return 0;
		
	}


/*/new added 2009-05-30
	if( (freq>start_freq)&&( (freq-last_tuned_freq)==1) )
	{
		if(g_last_freq_deviation_value&0x800)
		{
			last_tuned_freq=freq;//save last tuned freqency
			g_last_freq_deviation_value=cur_freq_deviation;
			return 0;		
		}

		if(g_last_freq_deviation_value<200)
		{
			last_tuned_freq=freq;//save last tuned freqency
			g_last_freq_deviation_value=cur_freq_deviation;
			return 0;
		}

	}

	if( (freq>=start_freq)&&( (last_tuned_freq-freq)==1) )
	{
		if( (g_last_freq_deviation_value&0x800)==0)
		{
			last_tuned_freq=freq;//save last tuned freqency
			g_last_freq_deviation_value=cur_freq_deviation;
			return 0;
		}

		if(g_last_freq_deviation_value>(0xfff-200) )
		{
			last_tuned_freq=freq;//save last tuned freqency
			g_last_freq_deviation_value=cur_freq_deviation;
			return 0;
		}

	}
*/
#if 1
//new added 2009-08-25
	if( (freq>=876)&&( (freq-last_tuned_freq)==1) )
	{
		if(g_freq_deviation_array[freq-start_freq-1]&0x800)
		{
                      return 0;
		}

		if(g_freq_deviation_array[freq-start_freq-1]<50)//150
		{
                     return 0;
		}
	}
	
	if( (freq>=MIN_FRE)&&( (last_tuned_freq-freq)==1) )
	{
		if( (g_freq_deviation_array[freq-start_freq+1]&0x800)==0)
		{
                     return 0;
		}

		if(g_freq_deviation_array[freq-start_freq+1]>(0xfff-50) )//150
		{
                      return 0;
		}

	} 
#endif

	
	last_tuned_freq=freq;//save last tuned freqency
	//g_last_freq_deviation_value=cur_freq_deviation;


	return 1; //OK

}


/**************************************************         
Function: BK1080_SearchByTune()

Parameter:	 
	searched_freq:a buffer for search frequency list
Description:
	search all the frequency.
Return:
	the number of the searched frequency.
/**************************************************/
u8 BK1080_SearchByTune(u16* searched_freq)
{
	u16 freq;
	u8 i=0;

	for(freq=MIN_FRE;freq<1080;freq++)
	{
		if(BK1080_ValidStop(freq,MIN_FRE))
		{
			searched_freq[i++]=freq;
		}
	}
	
	return i;

}
#endif

