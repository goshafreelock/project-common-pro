/*--------------------------------------------------------------------------*/
/**@file    led.c
   @brief   4位LED驱动
   @details
   @author
   @date   2010-12-13
   @note
*/
/*----------------------------------------------------------------------------*/
#include "config.h"

#ifdef LED_1651_DRV

#include "led_1651.h"

_xdata u8 LED_BUFF[5];
extern bool iic_busy;


/*----------------------------------------------------------------------------*/
/**@brief    LED扫描函数
   @param
   @return
   @note     void disp_scan(void)
*/
/*----------------------------------------------------------------------------*/


#define     Tm1651_dio   P00 //P31           //1651  dat
#define     Ttm1651_clk   P01// P30           //1651 clk

void  iic_1651_init_io(void)
{
   
       P0DIR &= ~(1<<1);
       P0PU |= (1<<1) ;
	P0DIR &= ~(1<<0);
   	P0PU |= (1<<0);
}

//---------开始信号------------------
void start(void)
{
	    iic_1651_init_io();
	Ttm1651_clk = 1;										//给芯片发送开始信号
	Tm1651_dio = 1;
       _nop_();
       _nop_();
	Tm1651_dio = 0;
      _nop_();
      _nop_();
	Ttm1651_clk = 0;										//开始信号传送完
	 _nop_();;
} 

//---------结束信号-------------------
void stop(void)
{
	Ttm1651_clk = 0;
      _nop_();
      _nop_();
	Tm1651_dio = 0;
     _nop_();
     _nop_();
	Ttm1651_clk = 1;
     _nop_();
     _nop_();
     _nop_();
	Tm1651_dio = 1;
}

//给IC写数据（包括8位数据，ACK应答信号）
void write(unsigned char wr_data)
{
	unsigned int i,count1;

	for(i=0;i<8;i++)								//开始传送8位数据，每循环一次传送一位数据
	{
		Ttm1651_clk =0;
	     	 _nop_();
	     	 _nop_();
								//移位数据，低位在前!
		 _nop_();
	if(wr_data &0x01)	 
		Tm1651_dio =1;
	else
		Tm1651_dio =0;
		 _nop_();
		 _nop_();
		Ttm1651_clk =1;
		 _nop_();
	 	wr_data >>= 1;	
		 _nop_();
		 
	}  
   	//8位数据传送完1
	Ttm1651_clk = 0;										//判断芯片发过来的ACK应答信号
      _nop_();
      _nop_();
	Tm1651_dio = 1;
      _nop_();
      _nop_();
	Ttm1651_clk = 1;
     _nop_();
  	 _nop_();
//muzhe 	while(Tm1651_dio)
	{
		count1 +=1;
		if(count1 ==200)
		{
			Tm1651_dio  =0;
			count1 =0;
		}
	}
	 _nop_();
	 _nop_();										//ACK应答信号	
}
 

void disp_scan_1651(void)
{

	if(iic_busy)
	return;
	ET0=0;

	Tm1651_dio = 1;
	Ttm1651_clk = 1;
	start();										//调用开始信号
	write(0x40);									//写命令40H（数据设置），地址自动加一
	stop();											//调用结束信号，一个字节命令发送完毕，可以发送下一个命令
	 _nop_();
	 _nop_();
	 _nop_();
	 _nop_();
	start();										//调用开始信号
	write(0xc0);									//写起始地址命令（0C0H），地址从00H单元开始。
#if 0
	if(LED_STATUS&LED_PAUSE)
		LED_BUFF[4]|=BIT(LED_H);
	if(LED_STATUS&LED_2POINT)
		LED_BUFF[4]|=(BIT(LED_G));
	if(LED_STATUS&LED_PLAY)
		LED_BUFF[4]|=(BIT(LED_F));
	if(LED_STATUS&LED_SD)
		LED_BUFF[4]|=(BIT(LED_E));
	if(LED_STATUS&LED_MP3)
		LED_BUFF[4]|=(BIT(LED_C));
	if(LED_STATUS&LED_FM)
		LED_BUFF[4]|=(BIT(LED_B));
	if(LED_STATUS&LED_USB)
		LED_BUFF[4]|=(BIT(LED_A));	
#endif		
	write(0xff);
	write(LED_BUFF[1]);	
	write(LED_BUFF[2]);	
	write(LED_BUFF[3]);
	write(LED_BUFF[4]);	
	write(LED_BUFF[0]);	

	stop();											//将所有数据送完后，发结束信号，可以发送下一条命令
	_nop_();
	_nop_();
	_nop_();
	start();										//调用开始信号
	write(0x8b);									//送开屏命令，（8BH），亮度可以根据低三位调节。
	stop();
	
	ET0=1;

}
void disp_buf_clear(void)
{
    LED_BUFF[0] = 0;	  /* 千位 */
    LED_BUFF[1] = 0;	  /* 百位 */
    LED_BUFF[2] = 0;	  /* 十位 */
    LED_BUFF[3] = 0;	  /* 个位 */
    LED_BUFF[4] = 0;	  /* 状态位 */
}
void init_disp(void)
{
    disp_buf_clear();
    iic_1651_init_io();
}
void updataLCD(void)
{

}

#endif

