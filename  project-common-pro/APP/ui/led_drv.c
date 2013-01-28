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
#include "led_drv.h"
#include "key.h"

#ifdef LED_DRV_USE_SM1628

xd_u8 drv_led_buf[MAX_LED_BUF];
bool drv_led_ea=0;

#define SPI_GPIO_Init() P3DIR &= ~0x07;P3PU |= 0x07; 

#define spi_data_read_init()	    P3DIR |=0x01;
#define spi_data_out_init()	    P3DIR &=~0x01;

#define SPI_DATA_PIN	P30
#define SPI_STB_PIN		P32
#define SPI_CLK_PIN		P31

u8 _idata TAB_keynum[2]={0};    //这5个数据来保存键值
//#define knum1 TAB_keynum[0] 
//#define knum2 TAB_keynum[1] 
//#define knum3 TAB_keynum[2] 
//#define knum4 TAB_keynum[3] 
//#define knum5 TAB_keynum[4] 

//共阴的数码管表格0-f
//u8 code TAB_duan[]=  {0x8f,0x80,0x0d,0x89,0x82,0x8b,0x8f,0x81,0x8f,0x8b,   0x87,0x8f,0x0f,0x8f,0x0f,0x07};
//u8 code TAB_duan1[]={0x02,0x01,0x03,0x03,0x03,0x02,0x01,0x02,0x03,0x03,    0x03,0x03,0x00,0x02,0x01,0x01};


#define MAX_TM_KEY		6
_code u8 tm_Key_Tab[MAX_TM_KEY][3]=
{
	{1,0x02,INFO_PREV_FIL},			
	{1,0x01,INFO_MUTE},
	{0,0x10,INFO_NEXT_FIL},			
	{0,0x02,INFO_PLAY},	
	{0,0x01,INFO_MODE},
	{0,0x08,INFO_EQ_UP},
};


void delayus()//延时4us
{
	u8 i=6;
	while(i-->0);
}

void tm_write_byte(u8 TM_dat)
{
    u8 i;
    for(i=0;i<8;i++)
    {
        SPI_DATA_PIN=(bit)(TM_dat&0x01);//强制转成:位，低位先发送
        SPI_CLK_PIN=0;//---------|
        delayus();
        TM_dat>>=1;//-------|
        SPI_CLK_PIN=1;//---------|___|----/上升沿有效
        delayus();        
    }
}

u8 tm_read_byte()
{
    u8 i,k;
    spi_data_read_init();
    for(i=0;i<8;i++)
    {
        SPI_CLK_PIN=0;
        delayus();		
        k>>=1;
        SPI_CLK_PIN=1;
        delayus();		
        if(SPI_DATA_PIN==1){k|=0x80;}//1000 0000

    }
    spi_data_out_init();
    return (k);
}

void Wr_TM_CMD(u8 TMcmd)
{
    	SPI_STB_PIN=0;//片选，0有效
    	tm_write_byte(TMcmd);
    	SPI_STB_PIN=1;//片选，0有效
    	SPI_DATA_PIN=1;
}
#ifdef LED_DRV_USE_SM1628_KEY_FUNC
void Read_key()//读TM1628的key值并入5个数组里面
{
	u8 ii=0,read_reg=0;

	if(drv_led_ea)return;
	
    	SPI_STB_PIN=0;//片选，0有效
    	tm_write_byte(0x42);//读键值命令0x42
    	SPI_DATA_PIN=1;//****************这一句很关键/在读数据时，一定要释放DIO=1
    	delayus();//必要的delay
    	for(ii=0;ii<5;ii++)
    	{
    		read_reg =tm_read_byte();
    		if((ii==2)||(ii==3)){
        		TAB_keynum[ii-2]=read_reg;//读key值
		}
    	}

    	SPI_STB_PIN=1;//片选，0有效
}
extern bool get_super_mute_lock();
 u8 SM1628_Key_Scan(void)
{
	u8 ii=0;
	
	//Read_key();
    //printf("Read_keynumber 000  %x \r\n",(u16)TAB_keynum[0]);
    //printf("Read_keynumber 111  %x \r\n",(u16)TAB_keynum[1]);
    //printf("Read_keynumber 222  %x \r\n",(u16)TAB_keynum[2]);
    //printf("Read_keynumber 333  %x \r\n",(u16)TAB_keynum[3]);
    //printf("Read_keynumber 444  %x \r\n",(u16)TAB_keynum[4]);
	//return NO_KEY;

#if 1
	if((TAB_keynum[0] >0)||(TAB_keynum[1]>0))
	{
		for(ii=0;ii<MAX_TM_KEY;ii++){

			if(TAB_keynum[tm_Key_Tab[ii][0]]==tm_Key_Tab[ii][1]){

			    	//printf("Read_key index  %x \r\n",(u16)ii);
				if(get_super_mute_lock()){
					if((tm_Key_Tab[ii][2] != INFO_MUTE)&&(tm_Key_Tab[ii][2] != INFO_MODE)){
						return NO_KEY;
					}
					else{

						return (tm_Key_Tab[ii][2]);

					}
				}
				else{

					return (tm_Key_Tab[ii][2]);

				}
			}
		}
			
	}

	return NO_KEY;
		
#else

	if((TAB_keynum[tm_Key_Tab[0][0]] >0)||(TAB_keynum[tm_Key_Tab[2][0]]>0))
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
#endif	
}
#endif	
void wirte_tm1628_disp_buf(void)
{
	u8 idx=0;

	ET1 =0;
	drv_led_ea = 1;		

	Wr_TM_CMD(0x03);//显示模式
    	Wr_TM_CMD(0x40);//地址自动加一

	SPI_STB_PIN=0;//片选，0有效	
	tm_write_byte(0xC0);//地址0开始
	for( idx=0;idx<MAX_LED_BUF;idx++)
	tm_write_byte(drv_led_buf[idx]);

    	SPI_STB_PIN=1;//片选，0有效

    	Wr_TM_CMD(0x8F);//送亮度指令
	ET1 =1;

	drv_led_ea = 0;		
}
void disp_buf_clear(void)
{
    my_memset(&drv_led_buf, 0x0,MAX_LED_BUF);
}
void init_disp()
{
   	SPI_GPIO_Init();
    	SPI_DATA_PIN=1;
   	SPI_STB_PIN=1;
    	SPI_CLK_PIN=1;
		
	Wr_TM_CMD(0x03);//显示模式

	disp_buf_clear();
	//wirte_tm1628_disp_buf();	
}

void update_led_buf(void)
{

	//EA= 0;
	wirte_tm1628_disp_buf();	
	//EA =1;
   //sys_printf("update_led_buf ...........  ");

}
#endif

