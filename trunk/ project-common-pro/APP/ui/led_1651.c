/*--------------------------------------------------------------------------*/
/**@file    led.c
   @brief   4λLED����
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
/**@brief    LEDɨ�躯��
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

//---------��ʼ�ź�------------------
void start(void)
{
	    iic_1651_init_io();
	Ttm1651_clk = 1;										//��оƬ���Ϳ�ʼ�ź�
	Tm1651_dio = 1;
       _nop_();
       _nop_();
	Tm1651_dio = 0;
      _nop_();
      _nop_();
	Ttm1651_clk = 0;										//��ʼ�źŴ�����
	 _nop_();;
} 

//---------�����ź�-------------------
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

//��ICд���ݣ�����8λ���ݣ�ACKӦ���źţ�
void write(unsigned char wr_data)
{
	unsigned int i,count1;

	for(i=0;i<8;i++)								//��ʼ����8λ���ݣ�ÿѭ��һ�δ���һλ����
	{
		Ttm1651_clk =0;
	     	 _nop_();
	     	 _nop_();
								//��λ���ݣ���λ��ǰ!
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
   	//8λ���ݴ�����1
	Ttm1651_clk = 0;										//�ж�оƬ��������ACKӦ���ź�
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
	 _nop_();										//ACKӦ���ź�	
}
 

void disp_scan_1651(void)
{

	if(iic_busy)
	return;
	ET0=0;

	Tm1651_dio = 1;
	Ttm1651_clk = 1;
	start();										//���ÿ�ʼ�ź�
	write(0x40);									//д����40H���������ã�����ַ�Զ���һ
	stop();											//���ý����źţ�һ���ֽ��������ϣ����Է�����һ������
	 _nop_();
	 _nop_();
	 _nop_();
	 _nop_();
	start();										//���ÿ�ʼ�ź�
	write(0xc0);									//д��ʼ��ַ���0C0H������ַ��00H��Ԫ��ʼ��
#if 0
	if(LED_STATUS1&LED_BAT_L1)
		LED_BUFF[2]|=BIT(LED_H);
	else  
		LED_BUFF[2]&=~(BIT(LED_H));
	if(LED_STATUS1&LED_BAT_L2)
		LED_BUFF[3]|=BIT(LED_H);
	else  
		LED_BUFF[3]&=~(BIT(LED_H));
	if(LED_STATUS1&LED_BAT_L3)
		LED_BUFF[4]|=BIT(LED_H);
	else  
		LED_BUFF[4]&=~(BIT(LED_H));
#endif		
	write(0xff);
	write(LED_BUFF[1]);	
	write(LED_BUFF[2]);	
	write(LED_BUFF[3]);	
	write(LED_BUFF[4]);	
	write(LED_BUFF[0]);	

	stop();											//��������������󣬷������źţ����Է�����һ������
	_nop_();
	_nop_();
	_nop_();
	start();										//���ÿ�ʼ�ź�
	write(0x8b);									//�Ϳ��������8BH�������ȿ��Ը��ݵ���λ���ڡ�
	stop();
	
	ET0=1;

}
void disp_buf_clear(void)
{
    LED_BUFF[0] = 0;	  /* ǧλ */
    LED_BUFF[1] = 0;	  /* ��λ */
    LED_BUFF[2] = 0;	  /* ʮλ */
    LED_BUFF[3] = 0;	  /* ��λ */
    LED_BUFF[4] = 0;	  /* ״̬λ */
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

