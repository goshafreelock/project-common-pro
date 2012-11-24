/*--------------------------------------------------------------------------*/
/**@file     iic_api.c
   @brief    IIC_APIģ��
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
/**@brief   IICд����
   @param   chip_id ��Ŀ��IC��ID��
   @param   iic_addr: Ŀ��IC��Ŀ��Ĵ����ĵ�ַ
   @param   *iic_dat: д��Ŀ��IC�����ݵ�ָ��
   @param   n:��Ҫд�����ݵ���Ŀ
   @return  ��
   @note    void  iic_write(u8 chip_id,u8 iic_addr,u8 *iic_dat,u8 n)
*/
/*----------------------------------------------------------------------------*/
void  iic_write(u8 chip_id,u8 iic_addr,u8 *iic_dat,u8 n) large
{
    iic_busy  = 1;
    iic_start();                //I2C����
    iic_sendbyte(chip_id);         //д����
    if (0xff != iic_addr)
    {
        iic_sendbyte(iic_addr);   //д��ַ
    }
    for (;n>0;n--)
    {
        iic_sendbyte(*iic_dat++);      //д����
    }
    iic_stop();                 //I2Cֹͣʱ��
    iic_busy = 0;
}
/*----------------------------------------------------------------------------*/
/**@brief   IIC������һ��Ŀ��ID��ȡ��������
   @param   address : Ŀ��ID
   @param   *p     :  �浵��ȡ�������ݵ�bufferָ��
   @param   number :  ��Ҫ��ȡ�����ݵĸ���
   @return  ��
   @note    void i2c_read_nbyte(u8 address,u8 *p,u8 number)
*/
/*----------------------------------------------------------------------------*/

void iic_readn(u8 chip_id,u8 iic_addr,u8 *iic_dat,u8 n) large
{

    iic_busy = 1;
    iic_start();                //I2C����
    iic_sendbyte(chip_id);         //д����
    if (0xff != iic_addr)
    {
        iic_sendbyte(iic_addr);   //д��ַ
    }
    for (;n>1;n--)
    {
        *iic_dat++ = iic_revbyte(0);      //д����
    }
    *iic_dat++ = iic_revbyte(1);
    iic_stop();                 //I2Cֹͣʱ��
    iic_busy = 0;
}
/*----------------------------------------------------------------------------*/
/**@brief   EEROM������
   @param   addr ��Ҫд��EEROM�ĵ�ַ
   @param   ��
   @return  ��
   @note    u8 read_eerom(u8 iic_addr)
*/
/*----------------------------------------------------------------------------*/
u8 read_eerom(u8 iic_addr)
{
    u8  byte;
    iic_busy = 1;
    iic_start();                    //I2C����
    iic_sendbyte(0xa0);             //д����
    iic_sendbyte(iic_addr);       //д��ַ
    iic_start();                    //дתΪ�������Ҫ�ٴ�����I2C
    iic_sendbyte(0xa1);             //������
    byte = iic_revbyte(1);
    iic_stop();                     //I2Cֹͣ
    iic_busy = 0;
    return  byte;
}
/*----------------------------------------------------------------------------*/
/**@brief   ���к�����ʱ��EEROMд����
   @param   addr ��Ҫд��EEROM�ĵ�ַ
   @param   dat    ����Ҫд������
   @return  ��
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
#ifdef UART_ENABLE
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
/**@brief   EEROM/RTC RAM������
   @param   addr ��Ҫд��EEROM/RTC RAM�ĵ�ַ
   @return  ����������
   @note    u8 read_info(u8 addr)
*/
/*----------------------------------------------------------------------------*/
u8 read_info(u8 addr)
{

#ifdef UART_ENABLE
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
/**@brief   EEROM/RTC RAMд����
   @param   addr ��Ҫ����EEROM/RTC RAM�ĵ�ַ
   @param   dat    ����Ҫ��������
   @return  ��
   @note    void write_info(u8 addr,u8 dat)
*/
/*----------------------------------------------------------------------------*/
void write_info(u8 addr,u8 dat)
{

#ifdef UART_ENABLE
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
    iic_start();                    //I2C����
}
void  SerialCommStop()
{
    iic_stop();                     //I2Cֹͣ
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
