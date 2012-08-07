#include "Custom_config.h"
#include "config.h"
#include "key.h"
#include "lcd_tm1721_drv.h"

#if defined(USE_LCD_DRV_TM1721)
//GPIO DEF
extern xd_u8 tm1721_buf[MAX_SEG_NUM/2 ];
volatile u8 _xdata TAB_keynum[3]={0};    //这5个数据来保存键值
bool tm1721_pwm_en=0;
#define LCD_spi_gpio_Init()	P1DIR &=~(( BIT(0))|( BIT(1))|( BIT(2)));P1PU |=(( BIT(0))|( BIT(1))|( BIT(2)))

#define LCD_SPI_CS_HIGH()		P12 =1;
#define LCD_SPI_CS_LOW()		P12 =0;
#define LCD_SPI_CLK_HIGH()		P11 =1;
#define LCD_SPI_CLK_LOW()		P11 =0;
#define LCD_SPI_DATA_HIGH()	P10 =1;
#define LCD_SPI_DATA_LOW()		P10 =0;

#define LCD_SPI_READ_INIT()		P1DIR |=(BIT(0));//P1PU &=~( BIT(0));//P10 =1;
#define LCD_SPI_DATA_PORT		P10


#define LCD_BACKLIGHT_LOW()		P07 =0;
#define LCD_BACKLIGHT_HIGH()		P07 =1;

u8 tm1721_key_value=0;

void TM1721_Delay(u16 t)
{ 
    while(--t);  
}
void TM1721_Wr_Data(u8 W_Data, u8 Num) 
{ 
    u8 i; 
    
    for (i = 0; i < Num; i++) 
    {   
        LCD_SPI_CLK_LOW();
        TM1721_Delay(TM1721_BIT_DELAY);
        if(W_Data & 0x01){
            LCD_SPI_DATA_HIGH();
        }
        else{
            LCD_SPI_DATA_LOW();                              
        }
        TM1721_Delay(TM1721_BIT_DELAY);
        LCD_SPI_CLK_HIGH();
        TM1721_Delay(TM1721_BIT_DELAY);
        W_Data >>= 1;  
    } 
} 
void TM1721_Wr_Cmd(u8 Cmd) 
{ 
    LCD_SPI_CS_LOW();
    TM1721_Delay(TM1721_BIT_DELAY);
    //TM1721_Wr_Data(0x80, 4);               //写入命令标志100 
    TM1721_Wr_Data(Cmd, 8);                //写入命令数据 
    LCD_SPI_CS_HIGH();
    TM1721_Delay(TM1721_BIT_DELAY); 
} 
void TM1721_WrAllData(u8 *buf_p, u8 Num) 
{ 
    u8 i=0; 
#if 0
    for (i = 0; i < Num; i++) 
    { 

	 TM1721_Wr_Cmd(0xC0+i);
	 TM1721_Wr_Cmd(*buf_p);         // 写入数据 
        buf_p++; 
    } 
#else
    LCD_SPI_CS_LOW();
   // TM1721_Wr_Data(0xa0, 3);           //写入数据标志101 
   // TM1721_Wr_Data(Addr << 2, 6);      //写入地址数据 
    for (i = 0; i < Num; i++) 
    { 
	 TM1721_Delay(1); 
	 TM1721_Wr_Data(*buf_p, 8);         // 写入数据 
        buf_p++; 
    } 
    LCD_SPI_CS_HIGH(); 
#endif	
}

u8 TM1721_read_reg()
{
	u8 i=0,key_reg=0;
	LCD_SPI_READ_INIT();

    	for(i=0;i<8;i++)
    	{
	        LCD_SPI_CLK_LOW();
	        TM1721_Delay(TM1721_BIT_DELAY);
	        LCD_SPI_CLK_HIGH();
	        TM1721_Delay(TM1721_BIT_DELAY);
	        TM1721_Delay(TM1721_BIT_DELAY);
			
		if(LCD_SPI_DATA_PORT){
			key_reg|=(0x01<<i);
		}

    	}
	return key_reg;
}
static u8 key_cnt=0;
void TM1721_key_scan()
{
	u8 i=0;
	EA =0;
	LCD_spi_gpio_Init();
	
       TM1721_Wr_Cmd(0x3F); 
    	LCD_SPI_CS_LOW();

    	TM1721_Wr_Data(0x42,8);
		
       TM1721_Delay(10);
	   
	for(i=0;i<3;i++){
		TAB_keynum[i] = TM1721_read_reg();
	}     
    	LCD_SPI_CS_HIGH(); 

#if 1
	if((TAB_keynum[1] >0)||(TAB_keynum[2]>0)||(TAB_keynum[0]>0)){
             //printf("TM1721_key_scan TAB_keynum0000=%x---\r\n",(u16)TAB_keynum[0]);
             // printf("TM1721_key_scan TAB_keynum1111=%x--- \r\n",(u16)TAB_keynum[1]);
              //printf("TM1721_key_scan TAB_keynum2222=%x--- \r\n",(u16)TAB_keynum[2]);
			  
		if(TAB_keynum[0]==0x04){

			tm1721_key_value = INFO_PLAY;

		}
		else if(TAB_keynum[0]==0x40){

			tm1721_key_value = INFO_PREV_FIL;

		}
		else if(TAB_keynum[0]==0x80){

			tm1721_key_value = INFO_STOP;

		}
		else if(TAB_keynum[1]==0x08){
			tm1721_key_value = INFO_MUTE;

		}
		else if(TAB_keynum[1]==0x04){

			tm1721_key_value = INFO_NEXT_FIL;

		}
		else if(TAB_keynum[0]==0x08){

			tm1721_key_value = INFO_MODE;

		}
     //         printf(" tm1721_key_value=%x--- \r\n",(u16)tm1721_key_value);		
	}
	else{

			if(key_cnt++>5){
				key_cnt = 0;
				tm1721_key_value = NO_KEY;
			}
	}

#endif
	EA =1;

}
void lcd_backlight_ctrl(bool on)
{
	if(on){
		tm1721_pwm_en = 1;
	}
	else{
		tm1721_pwm_en = 0;
	}
}
void lcd_TM1721_init(void)
{
    LCD_spi_gpio_Init();

    lcd_backlight_ctrl(TRUE);
    disp_buf_clear();

    TM1721_Wr_Cmd(0x3F); 
    TM1721_Wr_Cmd(0x40);                  
    TM1721_Wr_Cmd(0xC0);
    TM1721_WrAllData(tm1721_buf, MAX_SEG_NUM/2);
	
    TM1721_Wr_Cmd(0x41); 
    TM1721_Wr_Cmd(0x3F); 
	
    TM1721_Wr_Cmd(0x97); 
    sys_printf("  lcd_TM1721_init  ");
}
void UpdateLcd_TM1721_Buf(void)
{
    EA  = 0;
    LCD_spi_gpio_Init();
    Lcd_check_buf();

    TM1721_Wr_Cmd(0x3F); 
    TM1721_Wr_Cmd(0x40);                  
    TM1721_Wr_Cmd(0xC0); 
    TM1721_WrAllData(tm1721_buf, MAX_SEG_NUM/2);
	
    if(tm1721_pwm_en){	
    	  TM1721_Wr_Cmd(0x41); 
    	  TM1721_Wr_Cmd(0x3F);   		
    }
    else{
    	  TM1721_Wr_Cmd(0x41); 
    	  TM1721_Wr_Cmd(0x00);   	
	}
	
    TM1721_Wr_Cmd(0x97);
    EA =1;

    sys_printf("  --->UpdateLcd_TM1721_Buf  ");
	
} 
void init_disp(void)
{
	lcd_TM1721_init();
}
#endif
