/*--------------------------------------------------------------------------*/
/**@file     iic_api.c
   @brief    IIC_API模块
   @details
   @author
   @date   2011-3-7
   @note
*/
/*----------------------------------------------------------------------------*/




#include "Custom_config.h"

#include "iic.h"
#include "config.h"

bool iic_busy = 0;

/*----------------------------------------------------------------------------*/
/**@brief   IIC写函数
   @param   chip_id ：目标IC的ID号
   @param   iic_addr: 目标IC的目标寄存器的地址
   @param   *iic_dat: 写望目标IC的数据的指针
   @param   n:需要写的数据的数目
   @return  无
   @note    void  iic_write(u8 chip_id,u8 iic_addr,u8 *iic_dat,u8 n)
*/
/*----------------------------------------------------------------------------*/
void  iic_write(u8 chip_id,u8 iic_addr,u8 *iic_dat,u8 n) large
{
    iic_busy  = 1;
    iic_start();                //I2C启动
    iic_sendbyte(chip_id);         //写命令
    if (0xff != iic_addr)
    {
        iic_sendbyte(iic_addr);   //写地址
    }
    for (;n>0;n--)
    {
        iic_sendbyte(*iic_dat++);      //写数据
    }
    iic_stop();                 //I2C停止时序
    iic_busy = 0;
}
/*----------------------------------------------------------------------------*/
/**@brief   IIC总线向一个目标ID读取几个数据
   @param   address : 目标ID
   @param   *p     :  存档读取到的数据的buffer指针
   @param   number :  需要读取的数据的个数
   @return  无
   @note    void i2c_read_nbyte(u8 address,u8 *p,u8 number)
*/
/*----------------------------------------------------------------------------*/

void iic_readn(u8 chip_id,u8 iic_addr,u8 *iic_dat,u8 n) large
{

    iic_busy = 1;
    iic_start();                //I2C启动
    iic_sendbyte(chip_id);         //写命令
    if (0xff != iic_addr)
    {
        iic_sendbyte(iic_addr);   //写地址
    }
    for (;n>1;n--)
    {
        *iic_dat++ = iic_revbyte(0);      //写数据
    }
    *iic_dat++ = iic_revbyte(1);
    iic_stop();                 //I2C停止时序
    iic_busy = 0;
}
/*----------------------------------------------------------------------------*/
/**@brief   EEROM读函数
   @param   addr ：要写的EEROM的地址
   @param   无
   @return  无
   @note    u8 read_eerom(u8 iic_addr)
*/
/*----------------------------------------------------------------------------*/
u8 read_eerom(u8 iic_addr)
{
    u8  byte;
    iic_busy = 1;
    iic_start();                    //I2C启动
    iic_sendbyte(0xa0);             //写命令
    iic_sendbyte(iic_addr);       //写地址
    iic_start();                    //写转为读命令，需要再次启动I2C
    iic_sendbyte(0xa1);             //读命令
    byte = iic_revbyte(1);
    iic_stop();                     //I2C停止
    iic_busy = 0;
    return  byte;
}
/*----------------------------------------------------------------------------*/
/**@brief   带有毫秒延时的EEROM写函数
   @param   addr ：要写的EEROM的地址
   @param   dat    ：需要写的数据
   @return  无
   @note    void write_info(u8 addr,u8 dat)
*/
/*----------------------------------------------------------------------------*/
void write_eerom(u8 addr,u8 dat)
{
    iic_write(0xa0,addr,&dat,1);
    delay_10ms(2);
}
#if defined(EEPROM_RTC_RAM_COMPATIBLE)
static bool eeprom_type=0;
u8 _code eeprom_chk[2]={0x66,0xCC};
void check_eeprom_status(void)
{
	u8 read_back_1=0,read_back_2=0;
	iic_busy = 1;
	write_eerom(IIC_VERIFY_BYTE_ADDR,eeprom_chk[0]);
	write_eerom(IIC_VERIFY_BYTE_ADDR+1,eeprom_chk[1]);

	read_back_1 = read_eerom(IIC_VERIFY_BYTE_ADDR);
	read_back_2 = read_eerom(IIC_VERIFY_BYTE_ADDR+1);

	if((read_back_1==eeprom_chk[0])&&(read_back_2==eeprom_chk[1])){

		eeprom_type = 1;
	}
	else{
		eeprom_type = 0;
	}
#ifdef UART_ENABLE_EEPROM
	printf("eeprom_type %x \r\n",(u16)eeprom_type);
#endif	
	iic_busy = 0;
}
bool get_eeprom_status(void)
{
	return eeprom_type;
}
#endif
/*----------------------------------------------------------------------------*/
/**@brief   EEROM/RTC RAM读函数
   @param   addr ：要写的EEROM/RTC RAM的地址
   @return  读到的数据
   @note    u8 read_info(u8 addr)
*/
/*----------------------------------------------------------------------------*/
u8 read_info(u8 addr)
{

#ifdef UART_ENABLE_EEPROM
	printf("---->read_info  %d \r\n",(u16)addr);
#endif

#if defined(EEPROM_RTC_RAM_COMPATIBLE)

	if(eeprom_type==0)
    		return read_rtc_ram(addr);
	else
    		return read_eerom(addr);
#else

#if USE_RTC_RAM
    return read_rtc_ram(addr);
#else
    return read_eerom(addr);
#endif

#endif
}
/*----------------------------------------------------------------------------*/
/**@brief   EEROM/RTC RAM写函数
   @param   addr ：要读的EEROM/RTC RAM的地址
   @param   dat    ：需要读的数据
   @return  无
   @note    void write_info(u8 addr,u8 dat)
*/
/*----------------------------------------------------------------------------*/
void write_info(u8 addr,u8 dat)
{

#ifdef UART_ENABLE_EEPROM
	printf("---->write_info  %d ,write-data %x   \r\n",(u16)addr,(u16)dat);
#endif

#if defined(EEPROM_RTC_RAM_COMPATIBLE)

	if(eeprom_type==0)
    		write_rtc_ram(addr,dat);
	else
    		write_eerom(addr,dat);

#else

#if USE_RTC_RAM
    write_rtc_ram(addr,dat);
#else
    write_eerom(addr,dat);
#endif

#endif
}
void  SerialCommStart()
{
    iic_start();                    //I2C启动
}
void  SerialCommStop()
{
    iic_stop();                     //I2C停止
}
u8 SerialCommTxByte(u8 Tdata)
{
	return iic_sendbyte(Tdata);
	
}
void SerialCommRxByte(u8 *Rdata,u8 ack)
{
    u8  byte;
    byte = iic_revbyte_io();
    s_ack(ack);
   *Rdata = byte;

}
u16 OperationRDAFM_2w(u8 operation, u8 *R_T_data, u8 numBytes)
{
	u8 j;
	u16 acknowledge=0;

/***************************************************

START: make sure here SDIO_DIR =OUT, SCLK = 1,	SDIO = 1

****************************************************/
  SerialCommStart();

/***************************************************

WRITE CONTROL DATA: make sure here: SLCK = 0; SDIO = 0

****************************************************/

/***************************

CHECK ACK for control word

***************************/

	if(operation == READ)
		 acknowledge = SerialCommTxByte(ADRR);
	else 
		 acknowledge = SerialCommTxByte(ADRW);
	
   //printf("---------111>>>operation %x \r\n",acknowledge);


/***************************************

WRITE or READ data

****************************************/	

/******************************

CHECK ACK or SEND ACK=0

*******************************/

for(j = 0; j < numBytes; j++, R_T_data++)
{
	if(operation == READ)
	{
	if(j == (numBytes -1))
		SerialCommRxByte(R_T_data,1); 
	else
		SerialCommRxByte(R_T_data, 0); 
	}	 
	else 
		acknowledge = SerialCommTxByte(*R_T_data);   

   //printf("---------222>>>operation %x \r\n",acknowledge);

}
/****************************

STOP: make sure here: SCLK = 0

*****************************/
   SerialCommStop();
      return acknowledge;

}
u8 RDAFM_write_data(u8 regaddr, u16 *Tdata, u8 datalen)
{
	u8 i=0;
	u8 acknowledge;
	
	SerialCommStart();///start
	acknowledge=SerialCommTxByte(FM_SINGLE_REG_ADRW);//chip adress
	acknowledge=SerialCommTxByte(regaddr);

	for(i=0;i<datalen;i++,Tdata++)//data
	{
		acknowledge=SerialCommTxByte(*Tdata>>8);
		acknowledge=SerialCommTxByte(*Tdata);
	}
	SerialCommStop();
	return acknowledge;
}

//only 5803/5820
u8 RDAFM_read_data(u8 regaddr, u16 *Rdata, u8 datalen)
{
	u8 tempdata;
	u8 i=0;
	u8 acknowledge;
	
	SerialCommStart();///start
	acknowledge=SerialCommTxByte(FM_SINGLE_REG_ADRW);//chip adress
	acknowledge=SerialCommTxByte(regaddr);
	
	SerialCommStart();//start
	SerialCommTxByte(FM_SINGLE_REG_ADRR);//chip adress
	
	for( i=0;i<datalen-1;i++,Rdata++)//data
	{
		SerialCommRxByte(&tempdata, 0);
		*Rdata = (tempdata<<8);	
		SerialCommRxByte(&tempdata, 0);			
		*Rdata |= tempdata;		
	}
	
	SerialCommRxByte(&tempdata, 0);
	*Rdata = (tempdata<<8);	
	SerialCommRxByte(&tempdata, 1);			
	*Rdata |= tempdata;	

	SerialCommStop();
	return acknowledge;
}

