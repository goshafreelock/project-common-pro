/*--------------------------------------------------------------------------*/
/**@file    led_drv.c
   @brief   4λLED����
   @details
   @author
   @date   2010-12-13
   @note
*/
/*----------------------------------------------------------------------------*/
#include "Custom_config.h"
#include "config.h"
#include "led_drv.h"
#include "key.h"

#ifdef LED_DRV_USE_SM1628

xd_u8 drv_led_buf[MAX_LED_BUF];

#define SPI_GPIO_Init() P3DIR &= ~0x07;P3PU |= 0x07; 

sbit TM_dio=P3^0;
sbit TM_stb=P3^2;
sbit TM_clk=P3^1;

volatile u8 _xdata TAB_keynum[5]={0};    //��5�������������ֵ
#define knum1 TAB_keynum[0] 
#define knum2 TAB_keynum[1] 
#define knum3 TAB_keynum[2] 
#define knum4 TAB_keynum[3] 
#define knum5 TAB_keynum[4] 

//����������ܱ��0-f
u8 code TAB_duan[]=  {0x8f,0x80,0x0d,0x89,0x82,0x8b,0x8f,0x81,0x8f,0x8b,   0x87,0x8f,0x0f,0x8f,0x0f,0x07};
u8 code TAB_duan1[]={0x02,0x01,0x03,0x03,0x03,0x02,0x01,0x02,0x03,0x03,    0x03,0x03,0x00,0x02,0x01,0x01};


void delayus()//��ʱ4us
{
	u8 i=20;
	while(i-->0);
}

void WR_TM1628_Byte(u8 TM_dat)
{
    u8 i;
    for(i=0;i<8;i++)
    {
        TM_dio=(bit)(TM_dat&0x01);//ǿ��ת��:λ����λ�ȷ���
        TM_clk=0;//---------|
        delayus();
        TM_dat>>=1;//-------|
        TM_clk=1;//---------|___|----/��������Ч
        delayus();        
    }
}

u8 Read_TM_Byte()
{
    u8 i,k;
    P1DIR |=0x01;
    for(i=0;i<8;i++)
    {
        TM_clk=0;
        delayus();		
        k>>=1;
        TM_clk=1;
        delayus();		
        if(TM_dio==1){k|=0x80;}//1000 0000
     // else k&=0x7f; 
    }
    P1DIR &=~0x01;
    return (k);
}

void Wr_TM_CMD(u8 TMcmd)
{
    TM_stb=0;//Ƭѡ��0��Ч
    WR_TM1628_Byte(TMcmd);
    TM_stb=1;//Ƭѡ��0��Ч
    TM_dio=1;
}
u8 ii=0;
void Read_keynumber()//��TM1628��keyֵ����5����������
{
    TM_stb=0;//Ƭѡ��0��Ч

    WR_TM1628_Byte(0x42);//����ֵ����0x42
    TM_dio=1;//****************��һ��ܹؼ�/�ڶ�����ʱ��һ��Ҫ�ͷ�DIO=1
    delayus();//��Ҫ��delay
    for(ii=0;ii<5;ii++)
    {
        TAB_keynum[ii]=Read_TM_Byte();//��keyֵ
    }

    TM_stb=1;//Ƭѡ��0��Ч
}
 u8 SM1628_Key_Scan(void)
{

	Read_keynumber();
    //printf("Read_keynumber 111  %x \r\n",(u16)TAB_keynum[1]);
    //printf("Read_keynumber 222  %x \r\n",(u16)TAB_keynum[2]);
	if((TAB_keynum[1] >0)&&(TAB_keynum[2]>0) ){

		return NO_KEY;	
	}

	if((TAB_keynum[1] >0)||(TAB_keynum[2]>0) )
	{
		if(TAB_keynum[1] ==0x08){
			
			return INFO_PLAY;
		}
		else if(TAB_keynum[1]==0x10){

			return INFO_MODE;
		}
		else if(TAB_keynum[1]==0x02){

			return INFO_PICK_FRE;
		}

		if(TAB_keynum[2] == 0x02){

			return INFO_NEXT_FIL;
		}
		else if(TAB_keynum[2]==0x08){

			return INFO_PREV_FIL;
		}
		else if(TAB_keynum[2]==0x01){

			return INFO_PLUS;
		}
		else if(TAB_keynum[2]==0x10){
			
			return INFO_MINUS;
		}
		else{
			
			return NO_KEY;

		}
	}
	else{

		return NO_KEY;
	}
}
void wirte_tm1628_disp_buf(void)
{
	u8 idx=0;
	
    	Wr_TM_CMD(0x03);//��ʾģʽ
    	Wr_TM_CMD(0x40);//��ַ�Զ���һ

	TM_stb=0;//Ƭѡ��0��Ч	
	WR_TM1628_Byte(0xC0);//��ַ0��ʼ
	for( idx=0;idx<MAX_LED_BUF;idx++)
	WR_TM1628_Byte(drv_led_buf[idx]);

    	TM_stb=1;//Ƭѡ��0��Ч

    	Wr_TM_CMD(0x8F);//������ָ��
}
void disp_buf_clear(void)
{
    my_memset(&drv_led_buf, 0x0,MAX_LED_BUF);
}
void init_disp()
{
   	SPI_GPIO_Init();
    	TM_dio=1;
   	TM_stb=1;
    	TM_clk=1;

	disp_buf_clear();
	//wirte_tm1628_disp_buf();	
}

void update_led_buf(void)
{

	EA= 0;
	wirte_tm1628_disp_buf();	
	EA =1;
   sys_printf("update_led_buf ...........  ");

}
#endif

