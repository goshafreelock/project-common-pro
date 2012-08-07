#include "Custom_config.h"
#include "config.h"
#include "lcd_ht1621_drv.h"

#if defined(USE_LCD_DRV_HT1621)
//GPIO DEF

#define LCD_spi_gpio_Init()	P1DIR &=~(( BIT(0))|( BIT(1))|( BIT(2)));P1PU |=(( BIT(0))|( BIT(1))|( BIT(2)))

#define LCD_SPI_CS_HIGH()		P12 =1;
#define LCD_SPI_CS_LOW()		P12 =0;
#define LCD_SPI_CLK_HIGH()		P11 =1;
#define LCD_SPI_CLK_LOW()		P11 =0;
#define LCD_SPI_DATA_HIGH()	P10 =1;
#define LCD_SPI_DATA_LOW()		P10 =0;


#if defined(K000_XingChuang_x821_V002)
#define LCD_BL_INIT()				P3DIR &= ~(BIT(4));P3PU |=BIT(4);
#define LCD_BACKLIGHT_LOW()		P34 =0;
#define LCD_BACKLIGHT_HIGH()		P34 =1;
#else
#define LCD_BACKLIGHT_LOW()		P07 =0;
#define LCD_BACKLIGHT_HIGH()		P07 =1;
#endif
void Ht1621_Delay(u16 t)
{ 
    while(--t);  
}
void Ht1621_Wr_Data(u8 W_Data, u8 Num) 
{ 
    u8 i; 
    
    for (i = 0; i < Num; i++) 
    {   
        LCD_SPI_CLK_LOW();
        Ht1621_Delay(HT1621_BIT_DELAY);
        if(W_Data & 0x80){
            LCD_SPI_DATA_HIGH();
        }
        else{
            LCD_SPI_DATA_LOW();                              
        }
        Ht1621_Delay(HT1621_BIT_DELAY);
        LCD_SPI_CLK_HIGH();
        Ht1621_Delay(HT1621_BIT_DELAY);
        W_Data <<= 1;  
    } 
} 
void Ht1621_Wr_Cmd(u8 Cmd) 
{ 
    LCD_SPI_CS_LOW();
    Ht1621_Delay(HT1621_BIT_DELAY);
    Ht1621_Wr_Data(0x80, 4);               //写入命令标志100 
    Ht1621_Wr_Data(Cmd, 8);                //写入命令数据 
    LCD_SPI_CS_HIGH();
    Ht1621_Delay(HT1621_BIT_DELAY); 
} 
void Ht1621WrAllData(u8 Addr, u8 *buf_p, u8 Num) 
{ 
    u8 i; 
    LCD_SPI_CS_LOW();
    Ht1621_Wr_Data(0xa0, 3);           //写入数据标志101 
    Ht1621_Wr_Data(Addr << 2, 6);      //写入地址数据 
    for (i = 0; i < Num; i++) 
    { 
        Ht1621_Wr_Data(*buf_p, 8);         // 写入数据 
        buf_p++; 
    } 
    LCD_SPI_CS_HIGH(); 
}

void init_disp(void)
{

}
void lcd_backlight_ctrl(bool on)
{
	LCD_BL_INIT();
	if(on){
    		LCD_BACKLIGHT_HIGH();
	}
	else{
    		LCD_BACKLIGHT_LOW();
	}
}
void lcd_ht1621_init(void)
{
    LCD_spi_gpio_Init();

    lcd_backlight_ctrl(TRUE);
	
    Ht1621_Delay(HT1621_INI_DELAY);      //延时使LCD工作电压稳定 
    Ht1621_Wr_Cmd(HT1621_BIAS); 
    Ht1621_Wr_Cmd(HT1621_RC256);                 //使用内部振荡器 
    Ht1621_Wr_Cmd(HT1621_SYSDIS); 
    Ht1621_Wr_Cmd(HT1621_WDTDIS); 
    Ht1621_Wr_Cmd(HT1621_SYSEN); 
    Ht1621_Wr_Cmd(HT1621_LCDON); 
    //Ht1621_Wr_Cmd(HT1621_LCDOFF); 
    disp_buf_clear();
    sys_printf("  lcd_ht1621_init  ");
}
extern xd_u8 Ht1621_buf[MAX_SEG_NUM/2 ];
void UpdateLcd_HT_1621_Buf(void)
{
    EA  = 0;
    LCD_spi_gpio_Init();
    Lcd_check_buf();
    Ht1621WrAllData(0x00, Ht1621_buf, MAX_SEG_NUM/2);
    EA =1;
   // sys_printf("HUpdateLcd_HT_1621_Bufr ...........  ");
} 
#endif
