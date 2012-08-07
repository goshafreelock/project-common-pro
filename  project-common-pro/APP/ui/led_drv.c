/*--------------------------------------------------------------------------*/
/**@file    led_drv.c
   @brief   4位LED驱动
   @details
   @author
   @date   2010-12-13
   @note
*/
/*----------------------------------------------------------------------------*/
#include "Custom_config.h"
#include "config.h"
#include "led.h"
#include "key.h"

#ifdef LED_DRVER_USE_SM1628


sbit TM_dio=P1^0;
sbit TM_stb=P1^2;
sbit TM_clk=P1^1;

volatile u8 _xdata TAB_keynum[5]={0};    //这5个数据来保存键值
#define knum1 TAB_keynum[0] 
#define knum2 TAB_keynum[1] 
#define knum3 TAB_keynum[2] 
#define knum4 TAB_keynum[3] 
#define knum5 TAB_keynum[4] 

//共阴的数码管表格0-f
u8 code TAB_duan[]=  {0x8f,0x80,0x0d,0x89,0x82,0x8b,0x8f,0x81,0x8f,0x8b,   0x87,0x8f,0x0f,0x8f,0x0f,0x07};
u8 code TAB_duan1[]={0x02,0x01,0x03,0x03,0x03,0x02,0x01,0x02,0x03,0x03,    0x03,0x03,0x00,0x02,0x01,0x01};


void delayus()//延时4us
{
	u8 i=20;
	while(i-->0);
}

void WR_TM1628_Byte(u8 TM_dat)
{
    u8 i;
    for(i=0;i<8;i++)
    {
        TM_dio=(bit)(TM_dat&0x01);//强制转成:位，低位先发送
        TM_clk=0;//---------|
        delayus();
        TM_dat>>=1;//-------|
        TM_clk=1;//---------|___|----/上升沿有效
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
    TM_stb=0;//片选，0有效
    WR_TM1628_Byte(TMcmd);
    TM_stb=1;//片选，0有效
    TM_dio=1;
}
u8 ii=0;
void Read_keynumber()//读TM1628的key值并入5个数组里面
{
    TM_stb=0;//片选，0有效

    WR_TM1628_Byte(0x42);//读键值命令0x42
    TM_dio=1;//****************这一句很关键/在读数据时，一定要释放DIO=1
    delayus();//必要的delay
    for(ii=0;ii<5;ii++)
    {
        TAB_keynum[ii]=Read_TM_Byte();//读key值
    }

    TM_stb=1;//片选，0有效
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
void TM1628_display(u8 dat1,u8 dat2,u8 dat3,u8 dat4,u8 dat5)
{

u8 _xdata dat_a1=0,dat_a2=0,dat_a3=0,dat_a4=0,dat_a5=0;
u8 _xdata dat_temp1=0,dat_temp2=0,dat_temp3=0,dat_temp4=0,dat_temp5=0;
    Wr_TM_CMD(0x03);//显示模式
    Wr_TM_CMD(0x40);//地址自动加一
//dat1=0x7e;

if(dat1&0x01)
	dat_a1|=0x01;
else
	dat_a1&=0xfe;

if(dat1&0x02)
	dat_temp1|=0x02;
else
	dat_temp2&=0xfd;

if(dat1&0x04)
	dat_a1|=0x80;
else
	dat_a1&=0x7f;

if(dat1&0x08)
	dat_a1|=0x08;
else
	dat_a1&=0xf7;

if(dat1&0x10)
	dat_a1|=0x04;
else
	dat_a1&=0xfb;

if(dat1&0x20)
	dat_a1|=0x02;
else
	dat_a1&=0xfd;

if(dat1&0x40)
	dat_temp1|=0x01;
else
	dat_temp1&=0xfe;



if(dat2&0x01)
	dat_a2|=0x01;
else
	dat_a2&=0xfe;

if(dat2&0x02)
	dat_temp2|=0x02;
else
	dat_temp2&=0xfd;

if(dat2&0x04)
	dat_a2|=0x80;
else
	dat_a2&=0x7f;

if(dat2&0x08)
	dat_a2|=0x08;
else
	dat_a2&=0xf7;

if(dat2&0x10)
	dat_a2|=0x04;
else
	dat_a2&=0xfb;

if(dat2&0x20)
	dat_a2|=0x02;
else
	dat_a2&=0xfd;

if(dat2&0x40)
	dat_temp2|=0x01;
else
	dat_temp2&=0xfe;

if(dat3&0x01)
	dat_a3|=0x01;
else
	dat_a3&=0xfe;

if(dat3&0x02)
	dat_temp3|=0x02;
else
	dat_temp3&=0xfd;

if(dat3&0x04)
	dat_a3|=0x80;
else
	dat_a3&=0x7f;

if(dat3&0x08)
	dat_a3|=0x08;
else
	dat_a3&=0xf7;

if(dat3&0x10)
	dat_a3|=0x04;
else
	dat_a3&=0xfb;

if(dat3&0x20)
	dat_a3|=0x02;
else
	dat_a3&=0xfd;

if(dat3&0x40)
	dat_temp3|=0x01;
else
	dat_temp3&=0xfe;

if(dat4&0x01)
	dat_a4|=0x01;
else
	dat_a4&=0xfe;

if(dat4&0x02)
	dat_temp4|=0x02;
else
	dat_temp4&=0xfd;

if(dat4&0x04)
	dat_a4|=0x80;
else
	dat_a4&=0x7f;

if(dat4&0x08)
	dat_a4|=0x08;
else
	dat_a4&=0xf7;

if(dat4&0x10)
	dat_a4|=0x04;
else
	dat_a4&=0xfb;

if(dat4&0x20)
	dat_a4|=0x02;
else
	dat_a4&=0xfd;

if(dat4&0x40)
	dat_temp4|=0x01;
else
	dat_temp4&=0xfe;

if(dat5&0x01)
	dat_a5|=0x01;
else
	dat_a5&=0xfe;

if(dat5&0x02)
	dat_temp5|=0x02;
else
	dat_temp5&=0xfd;

if(dat5&0x04)
	dat_a5|=0x80;
else
	dat_a5&=0x7f;

if(dat5&0x08)
	dat_a5|=0x08;
else
	dat_a5&=0xf7;

if(dat5&0x10)
	dat_a5|=0x04;
else
	dat_a5&=0xfb;

if(dat5&0x20)
	dat_a5|=0x02;
else
	dat_a5&=0xfd;

if(dat5&0x40)
	dat_temp5|=0x01;
else
	dat_temp5&=0xfe;

TM_stb=0;//片选，0有效
WR_TM1628_Byte(0xC4);//地址0开始

 WR_TM1628_Byte(dat_a1);
WR_TM1628_Byte(dat_temp1);
	
WR_TM1628_Byte(dat_a2);
WR_TM1628_Byte(dat_temp2);

WR_TM1628_Byte(dat_a3);
 WR_TM1628_Byte(dat_temp3);

 WR_TM1628_Byte(dat_a4);
 WR_TM1628_Byte(dat_temp4);
		   
 WR_TM1628_Byte(dat_a5);
WR_TM1628_Byte(dat_temp5);


    TM_stb=1;//片选，0有效

    Wr_TM_CMD(0x8f);//送亮度指令
}
#define SPI_GPIO_Init() P1DIR &= ~0x07;//P1PU |= 0x07; 
void TM1628_init()
{
   SPI_GPIO_Init();
    TM_dio=1;
    TM_stb=1;
    TM_clk=1;
}
#endif

