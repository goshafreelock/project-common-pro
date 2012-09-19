
#include "Custom_config.h"

#include "bk1088.h"
#include "clock.h"
#include"uart.h"
#include "config.h"
#include "fm_rev.h"

#include "entry.h"

#ifdef FM_USE_BK1086		

 extern bool  sys_clock_flag;
//BK1088 initialization value

_code HW_Reg_AM[]=
{
0x8000,
0x1080,
0x0281,
0x0004,
0x60C0,//interrupt enable
0x1FDd,
0x0930,
0x2901,
0xAC8C,
0x1093,
0x402D,
0x004B,
0x0000,
0x0000,
0x0000,
0x0000,
0x7B11,//16
0x0C00,
0x4000,
0x4344,
0x878E,//20
0x7812,
0x4000,
0x0B55,//23
0x341C,
0x000D,
0x0001,
0x48D4,
0x0000,
0x0200,
0x80AA,//30
0x0000,//31
0x0EF7,
0x0600,
0x0000,
0xF438,//35
0x0880,
0x8c06,
0x8400,
0x0000,
0x4400//40
};

_code u16 HW_Reg[]=
{
0x8000,//0
0x1080,
0x0381,
0x0000,
0x60C0,
//#if(MIN_FRE==640)
0x365a,//5
//#elif(MIN_FRE==760)
//0x37D7,//5
//#else
//0x37Df,//5
//#endif
0x086E,
0x0901,
0x9C90,
0x17A0,
0x402B,//10
0x0040,
0x0000,
0x0000,
0x0000,
0x0000,//15
0x7B11,
0x0C00,
0x4000,
0x4144,
0x829A,//20
0x7812,
0x43BB,
0x0B41,
0x143C,
0x000E,//25
0x0000,
0x48D4,
0x0000,
0x0200,
0x80AA,//30
0x0000,
0x0EF7,
0x0600,
0x0000,
0x7000,//35
0x0880,
0x8D83,
0x8000,
0x0000,
0x4400//40
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
}


/**************************************************         
Function: EnableWire2()
Parameter: 
	b_enable: 1: wire2;0: wire3;                                         

Description:
	Enable wire2 or wire 3 mode
/**************************************************/  



/**************************************************         
Function: BK1088_FreqToChan()
Parameter: 
	frequency: FM frequency *10 ,such as  1017,933,1077..                                      

Description:
	change from frequency to channel
/**************************************************/ 

u16 BK1088_FreqToChan(u16 frequency)
{
	u8 TmpData[2];
	u8 bit_status=0;
      bool  TmAM_FM_lag=0;
	u16 bottomOfBand;
	u8 channelSpacing;
	u16 channel;
	BEKEN_I2c_Read(0x07,TmpData,2); //read reg2,with 4 bytes

if(TmpData[0]&BIT(5))
	TmAM_FM_lag=1;
if(TmAM_FM_lag)
{
	channel = (frequency - AM_MIN_FRE)/MW_CHANNEL_STEP ;
}

else
{
/*	BEKEN_I2c_Read(0x05,TmpData,2); //read reg2,with 4 bytes


	if (TmpData[1] &BIT(7))
		bit_status| = BIT(0);
	if (TmpData[0] &BIT(0))
		bit_status| = BIT(1);

if(bit_status==0)
bottomOfBand=640;
else if(bit_status==0x01)	
	bottomOfBand = 640;
else if(bit_status==0x02)	
	bottomOfBand = 760;
else if(bit_status==0x03)	
	bottomOfBand = 870;
	
	channelSpacing=1;

*/
	channelSpacing=1;
	channel = (frequency - 640) / channelSpacing;
}



	return (channel);	


	

}


u16 BK1088_Get_ID()
{
	u8 TmpData[2];
	u16 ChipID = 0xFFFF;

	//sys_printf(" FM SET BK1088_PowerOffProc ");
	BEKEN_I2c_Read(0x01,TmpData,2); //read reg2,with 4 bytes


	ChipID = TmpData[0];
    	ChipID = ((ChipID<<8) | TmpData[1]);
	//printf(" BK1088ChipID %x \r\n",ChipID);
	 return ChipID;
}


/**************************************************         
Function: Chip_wire2_Initialize()
Parameter: 
	None                                         

Description:
	BK1088 I2C mode initialization
/**************************************************/ 
void BK1088_Intialization(bool init_fmam)
{
	u8 index;
	//u8 _xdata bk1080_writeData8[68];
	u8 TmpData[2];

//	delay_10ms(50);//delay 1s,please revise delay time according to your MCU

//TmpData[0]=0x03;
//TmpData[1]=0x81;
//AM_FM_flag=0;
	//BEKEN_I2c_Write(2,TmpData,2); //write reg2,with 4 bytes

		//BEKEN_I2c_Read(0x02,TmpData,2); //read reg2,with 4 bytes

		//printf(" BK1088IntializationOK44=%x ",(u16)TmpData[0]);
		//printf(" BK1088IntializationOK44=%x ",(u16)TmpData[1]);
if(init_fmam)
{
	for(index = 0; index < 41; index++)
	{
	
			TmpData[1] = (u8)HW_Reg_AM[index];
		TmpData[0] = (u8)(HW_Reg_AM[index] >> 8);
			BEKEN_I2c_Write(index,TmpData,2);//start from reg2,total 60 byte
	}
}
else
{
	for(index = 0; index < 41; index++)
	{
			TmpData[1] = (u8)HW_Reg[index];
		TmpData[0] = (u8)(HW_Reg[index] >> 8);
			BEKEN_I2c_Write(index,TmpData,2);//start from reg2,total 60 byte

	}
}	
	delay_10ms(30);//delay 60ms

		//BEKEN_I2c_Read(0x06,TmpData,2); //read reg2,with 4 bytes

		//printf(" BK1088IntializationOK=%x ",(u16)TmpData[0]);
		//printf(" BK1088IntializationOK1=%x ",(u16)TmpData[1]);


	/*//BEKEN_I2c_Write(0,&(bk1080_writeData8[0]),68);//start from reg2,total 60 byte

	delay_10ms(10);//delay 250ms
	bk1080_writeData8[25*2+1]&=0x7f;
	BEKEN_I2c_Write(25,&(bk1080_writeData8[25*2]),2);
	bk1080_writeData8[25*2+1]|=0x80;
	BEKEN_I2c_Write(25,&(bk1080_writeData8[25*2]),2);

	BEKEN_I2c_Read(0x04,TmpData,2); //read reg2,with 4 bytes

		printf(" BK1088IntializationOK=%x ",TmpData[0]);
*/

}

void BK1088_SetMute(bool mute)
{
	u8 TmpData[2];

	BEKEN_I2c_Read(0x02,TmpData,2); //read reg2,with 4 bytes

	if(mute)
		{
			//sys_printf(" FM SET BK1088_SetMute ");

	 	TmpData[0]|=  0x60;
		}
	else
		{
			//sys_printf(" FM SET BK1088_Set UNMute ");

		TmpData [0]&=0x9f;
		}

	BEKEN_I2c_Write(2,TmpData,2); //write reg2,with 4 bytes
	
		//	BEKEN_I2c_Read(0x02,TmpData,2); //read reg2,with 4 bytes

	//	printf(" BK1088IntializationOK=%x ",(u16)TmpData[0]);
		//printf(" BK1088IntializationOK1=%x ",(u16)TmpData[1]);
	
}

void BK1088_SetGPIO2(bool mute)
{
	u8 TmpData[2];

	BEKEN_I2c_Read(0x04,TmpData,2); //read reg2,with 4 bytes

	if(mute)
		{
             //printf(" BK1088_SetGPIO2== %d \n",(u16)(TmpData));
	 	TmpData[1]|=  0x0C;
		}
	else
		{
             //printf("-- BK1088_SetGPIO2 ===%d \n",(u16)(TmpData));
	 	TmpData[1]&=~0x04;
	 	TmpData[1]|= 0x08;
		}

	BEKEN_I2c_Write(0x04,TmpData,2); //write reg2,with 4 bytes
	
}


void BK1088_SetGPIO1(bool mute)
{
	u8 TmpData[2];

	BEKEN_I2c_Read(0x04,TmpData,2); //read reg2,with 4 bytes

	if(mute)
		{
            // printf(" BK1088_SetGPIO2== %d \n",(u16)(TmpData));
	 	TmpData[1]|=  0x03;
		}
	else
		{
            // printf("-- BK1088_SetGPIO2 ===%d \n",(u16)(TmpData));
	 	TmpData[1]&=~0x03;
		}

	BEKEN_I2c_Write(0x04,TmpData,2); //write reg2,with 4 bytes
	
}


void BK1088_SetVolume(u8 vol)
{
	u8 TmpData[2];
	//        printf(" memey_vol== %d \n",(u16)(vol));

	if(vol ==0){
		BK1088_SetMute(TRUE);
		return;
	}
	else{
		BK1088_SetMute(FALSE);
	}
	delay_10ms(1);//delay 60ms
	BEKEN_I2c_Read(0x05,TmpData,2); //read reg2,with 4 bytes
	//delay_10ms(2);//delay 60ms

	TmpData[1] =((TmpData[1]&0xe0)|vol);

	BEKEN_I2c_Write(0x05,TmpData,2); //write reg2,with 4 bytes
	delay_10ms(2);//delay 60ms

}

void BK1088_PowerOffProc()
{
	u8 TmpData[2];

	//sys_printf(" FM SET BK1088_PowerOffProc ");
	BEKEN_I2c_Read(0x02,TmpData,2); //read reg2,with 4 bytes
		TmpData[1] |=0x41;

	BEKEN_I2c_Write(2,TmpData,2); //write reg2,with 4 bytes
}

/**************************************************         
Function: BK1088_SetFreq()
Parameter: 
	curFreq: FM frequency *10 ,such as  1017,933,1077..                                      

Description:
	set FM to a frequency
/**************************************************/ 
void  BK1088_SetFreq(u16 curFreq)
{  
	u16 curChan;
	u8 TmpData8[2];


	curChan=BK1088_FreqToChan(curFreq); /*stop seek and tune*/

	BEKEN_I2c_Read(0x02,TmpData8,2); //read reg2,with 4 bytes
	TmpData8[0] &=~0x01;
	BEKEN_I2c_Write(2,TmpData8,2); //write reg2,with 4 bytes
	TmpData8[0] =0;
	TmpData8[1] =0;
	BEKEN_I2c_Write(3,TmpData8,2); //write reg2,with 4 bytes

       TmpData8[1]=(u8)curChan;
	TmpData8[0]=(u8)(curChan>>8);
        TmpData8[0] |=0x80;
	BEKEN_I2c_Write(3,TmpData8,2); //write reg2,with 4 bytes

	BEKEN_I2c_Read(0x0b,TmpData8,2); //read reg2,with 4 bytes

	//printf(" 0x0b=%x ",(u16)TmpData8[0]);
	//printf(" 0x0b=%x ",(u16)TmpData8[1]);


	
/*
        reg2=bk1086_Read_reg(0x02);
        
        reg3=bk1086_Read_reg(0x03);
        
	curChan=BK1086_FreqToChan(freq);

        reg2 &=~0x0100;
        reg3 =0x0000;       
        bk1086_Write_reg(0x02, reg2);        
        bk1086_Write_reg(0x03, reg3);

        reg3 |=curChan;//&0xff00;        
        reg3 |=0x8000;
        
        bk1086_Write_reg(0x02, reg2);        
        bk1086_Write_reg(0x03, reg3);        
        DelayMs(2);


	//TmpData8[0]&=0xfe; 
	TmpData8[0] &=~0x0100;
	TmpData8[1]=curChan&0xff;
	BEKEN_I2c_Write(3,TmpData8,3); //write reg2,with 4 bytes


	TmpData8[0]=(curChan>>8)&0xff;
	TmpData8[0] |= 0x80;//start tune
	TmpData8[1]=curChan&0xff;
	BEKEN_I2c_Write(3,TmpData8,2); //write reg2,with 4 bytes

	
	TmpData8[0] &= 0x7F;//start tune
	BEKEN_I2c_Write(3,TmpData8,2); //write reg2,with 4 bytes
*/


}

#define PARAM_RSSI_FM 30
#define PARAM_RSSI_AM 16
#define PARAM_SNR_FM 4
#define PARAM_SNR_AM 15
bool BK1088_AMValidStop(u16 freq,u16 start_freq)
{	
	static _xdata u16 last_tuned_freq=0;//static variable
	static _xdata u16 g_last_freq_deviation_value=0;
	u16 _xdata cur_freq_deviation;
	u8 _xdata TmpData8[8];

	BK1088_SetFreq(freq);
#if defined(VOL_TUNE_FREQ_VOL)||defined(VOL_TUNE_FREQ_ONLY)||defined(VOL_TUNE_NEW_VOLUME_KEY_FEATURE)
	if( get_radio_freq_tune_protect()){
		
	}
	else
#endif	
	{
        delay_10ms(20);//delay 70ms
	}
////////////////////////////////////

	BEKEN_I2c_Read(7,TmpData8,8);//start from reg7,with 8bytes


	if((TmpData8[7]&0x7f)<PARAM_RSSI_AM) //RSSI<10  信号强度12


	//if(TmpData8[7]<10) //RSSI<10  信号强度

	//if(TmpData8[7]<12) //RSSI<10  信号强度
	{
		last_tuned_freq=freq;//save last tuned freqency
		g_last_freq_deviation_value=cur_freq_deviation;
		return 0;//false
	}

	if( (TmpData8[5]&0x7f) <PARAM_SNR_AM) //SNR<2  3---5 假台3
	{
		last_tuned_freq=freq;//save last tuned freqency
		g_last_freq_deviation_value=cur_freq_deviation;
		return 0;//false
	}
		return 1;//false



	
}

/**************************************************         
Function: BK1088_ValidStop()

Parameter:
	freq:FM frequency *10 ,such as  1017,933,1077...  
	start_freq:lowest frequency,in China,start_freq=875
Description:
	check a frequency is a valid.
Return:
	1:ok
	0:false	
/**************************************************/
//u16 _xdata g_freq_deviation_array[1081-MIN_FRE];

bool BK1088_FMValidStop(u16 freq,u16 start_freq)
{	
	static _xdata u16 last_tuned_freq=0;//static variable
	static _xdata u16 g_last_freq_deviation_value=0;
	u16 cur_freq_deviation;
	u8 TmpData8[8];

	BK1088_SetFreq(freq);
#if defined(VOL_TUNE_FREQ_VOL)||defined(VOL_TUNE_FREQ_ONLY)||defined(VOL_TUNE_NEW_VOLUME_KEY_FEATURE)
	if( get_radio_freq_tune_protect()){
		
	}
	else
#endif	
	{
        delay_10ms(10);//delay 70ms
	}
////////////////////////////////////
//new added 2009-05-30
	BEKEN_I2c_Read(0x09,TmpData8,2);//start from reg 0x7,with 2bytes

	cur_freq_deviation=TmpData8[0];
	cur_freq_deviation<<=1;
	if(TmpData8[1]&BIT(7))
	cur_freq_deviation|=BIT(0);
	//cur_freq_deviation=cur_freq_deviation>>4;

//	    g_freq_deviation_array[freq-start_freq]=cur_freq_deviation;
		

////////////////////////////////////

	BEKEN_I2c_Read(7,TmpData8,8);//start from reg7,with 8bytes








#if 1
	
	if(TmpData8[6]&0x10)    //check AFCRL bit12
	{
		last_tuned_freq=freq;//save last tuned freqency
		g_last_freq_deviation_value=cur_freq_deviation;
		return 0;//false
	}

	/*if(TmpData8[6]&0x01)    // st 
	{
		last_tuned_freq=freq;//save last tuned freqency
		g_last_freq_deviation_value=cur_freq_deviation;
		return 0;//false
	}
	*/
    //    printf("\n\rfreq=%d \n" ,freq);

	if((TmpData8[7]&0x7f)<PARAM_RSSI_FM) //RSSI<10  信号强度12


	//if(TmpData8[7]<10) //RSSI<10  信号强度

	//if(TmpData8[7]<12) //RSSI<10  信号强度
	{
		last_tuned_freq=freq;//save last tuned freqency
		g_last_freq_deviation_value=cur_freq_deviation;
		return 0;//false
	}

	//if( (TmpData8[1]&0xf) <3) //SNR<2  3---5 假台


	if( (TmpData8[5]&0x7f) <PARAM_SNR_FM) //SNR<2  3---5 假台3
	{
		last_tuned_freq=freq;//save last tuned freqency
		g_last_freq_deviation_value=cur_freq_deviation;
		return 0;//false
	}


//add frequency devation check
//if( (cur_freq_deviation>=0x64)&&(cur_freq_deviation<=(0xfff-0x64))) ///微调
if( (cur_freq_deviation>=60)&&(cur_freq_deviation<=(0x1ff-60))) ///微调128

//if( (cur_freq_deviation>=0x96)&&(cur_freq_deviation<=(0xfff-0x96))) ///微调
	{
		last_tuned_freq=freq;//save last tuned freqency
		g_last_freq_deviation_value=cur_freq_deviation;

		return 0;
		
	}


//new added 2009-05-30
	if( (freq>start_freq)&&( (freq-last_tuned_freq)==1) )
	{
		if(g_last_freq_deviation_value&0x100)
		{
			last_tuned_freq=freq;//save last tuned freqency
			g_last_freq_deviation_value=cur_freq_deviation;
			return 0;		
		}

		if(g_last_freq_deviation_value<25)
		{
			last_tuned_freq=freq;//save last tuned freqency
			g_last_freq_deviation_value=cur_freq_deviation;
			return 0;
		}

	}

	if( (freq>=start_freq)&&( (last_tuned_freq-freq)==1) )
	{
		if( (g_last_freq_deviation_value&0x100)==0)
		{
			last_tuned_freq=freq;//save last tuned freqency
			g_last_freq_deviation_value=cur_freq_deviation;
			return 0;
		}

		if(g_last_freq_deviation_value>(0x1ff-25) )
		{
			last_tuned_freq=freq;//save last tuned freqency
			g_last_freq_deviation_value=cur_freq_deviation;
			return 0;
		}

	}
//*/
#if 0
//new added 2009-08-25
	if( (freq>=876)&&( (freq-last_tuned_freq)==1) )
	{
		if(g_freq_deviation_array[freq-start_freq-1]&0x100)
		{
                      return 0;
		}

		if(g_freq_deviation_array[freq-start_freq-1]<25)//128
		{
                     return 0;
		}
	}
	
	if( (freq>=MIN_FRE)&&( (last_tuned_freq-freq)==1) )
	{
		if( (g_freq_deviation_array[freq-start_freq+1]&0x100)==0)
		{
                     return 0;
		}

		if(g_freq_deviation_array[freq-start_freq+1]>(0x1ff-25) )//128
		{
                      return 0;
		}

	} 
#endif

	
	last_tuned_freq=freq;//save last tuned freqency
	//g_last_freq_deviation_value=cur_freq_deviation;
 /*   printf("\n\rTmpData8[6]=%d \n\r" ,(u16)TmpData8[6]);		
        printf("\n\rTmpData8[7]=%d \n" ,(u16)TmpData8[7]);
        printf("\n\rTmpData8[1]=%d \n" ,(u16)TmpData8[1]);
        printf("\n\rcur_freq_deviation=%d \n" ,cur_freq_deviation);
        printf("\n\rg_freq_deviation_array[freq-start_freq+1]=%d \n" ,g_freq_deviation_array[freq-start_freq+1]);
*/

	return 1; //OK
	
#endif

}

#endif


