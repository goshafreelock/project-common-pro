/*lcd segment*/
#include "lcdsegment.h"
#include "config.h"
#include "lcd.h"
#include "disp.h"

#ifdef LCD_GPIO_DRV

extern xd_u16 lcd_buff[4];
extern xd_u8 return_cnt;  

#if defined(K2038_DCX_2038_V001)||defined(K2045_AJR_2045_V001)||defined(LCD_BACKLIGHT_USE_PORT_WKUP)
extern void wkup_pin_ctrl(bool dir);
#elif defined(LCD_BACKLIGHT_USE_PORT_P04)
#define LCD_BACKLIGHT_LOW()		P04 =0;
#define LCD_BACKLIGHT_HIGH()		P04 =1;
#else
#define LCD_BACKLIGHT_LOW()		P02 =0;
#define LCD_BACKLIGHT_HIGH()		P02 =1;
#endif

#if defined(USE_BAT_MANAGEMENT)
#ifdef CUSTOM_BAT_ICON_DISP
extern void Disp_custom_bat_icon();
#endif	
#endif

void disp_buf_clear(void)
{
    lcd_buff[0] = 0x0000;
    lcd_buff[1] = 0x0000;
    lcd_buff[2] = 0x0000;
    lcd_buff[3] = 0x0000;
#ifdef K000_ZhuoYue_003_V001	
    lcd_buff[4] &= (L1_ICON_MASK|L2_ICON_MASK|L3_ICON_MASK|L4_ICON_MASK);
#else
    lcd_buff[4] = 0x0000;
#endif
}
void lcd_backlight_ctrl(bool on)
{
#if defined(K000_KT_AMFM_V001)

#elif defined(K2038_DCX_2038_V001)||defined(K2045_AJR_2045_V001)||defined(LCD_BACKLIGHT_USE_PORT_WKUP)

	if(on){
		wkup_pin_ctrl(1);
	}
	else{
		wkup_pin_ctrl(0);
	}
#elif defined(LCD_BACKLIGHT_USE_PORT_P04)
	if(on){

		P0DIR |= (BIT(4));P0PU|= (BIT(4)); 
    		LCD_BACKLIGHT_HIGH();
	}
	else{

		P0DIR |= (BIT(4));P0PU|= (BIT(4)); 
    		LCD_BACKLIGHT_LOW();
	}
#else
	if(!on){

		P0DIR |= (BIT(2));P0PU|= (BIT(2)); 
    		LCD_BACKLIGHT_HIGH();
	}
	else{

		P0DIR |= (BIT(2));P0PU|= (BIT(2)); 
    		LCD_BACKLIGHT_LOW();
	}
#endif
}
#if defined(K000_ZhuoYue_003_V001)
u8 align_lcd_seg_buf(u8 seg_dat)
{
	u8 reg_temp=0;

 	reg_temp |=((seg_dat&0x01)>0)?0x80:0;
 	reg_temp |=((seg_dat&0x02)>0)?0x40:0;
 	reg_temp |=((seg_dat&0x04)>0)?0x20:0;
 	reg_temp |=((seg_dat&0x08)>0)?0x10:0;
 	reg_temp |=((seg_dat&0x10)>0)?0x08:0;
 	reg_temp |=((seg_dat&0x20)>0)?0x04:0;
 	reg_temp |=((seg_dat&0x40)>0)?0x02:0;		
 	reg_temp |=((seg_dat&0x80)>0)?0x01:0;
	return reg_temp;
}
void lcd_gpio_scan(void)
{
    static u8 cnt = 0;
    u8 temp;
	
    temp = cnt>>1;
    close_com(temp);
    if(cnt & 0x01){
	    
	  seg07_port(align_lcd_seg_buf(lcd_buff[temp]));
	  //seg8_port(((lcd_buff[temp]>>8) & 0x01) );
	  clr_com(temp);
    }
    else
   {                            
	  seg07_port(~(align_lcd_seg_buf(lcd_buff[temp])));
	  //seg8_port(!((lcd_buff[temp]>>8) & 0x01));
	  set_com(temp);
   }

   cnt++;
  if(cnt>9)cnt = 0;
}
#elif defined(K000_KT_AMFM_V001)||defined(LCD_SEGMENT_USE_11_SEGS)
void lcd_gpio_scan(void)
{
    static u8 cnt = 0;
    xd_u8 temp;

    TRADEMARK_ICON |=TRADEMARK_MASK;
   	
    temp = cnt>>1;
    close_com(temp);
    if(cnt & 0x01){
	    
	  seg07_port(lcd_buff[temp]);
	  seg8_port( ( ((lcd_buff[temp]&0x0100)>0)?1:0 ) );
	  seg9_port( ( ((lcd_buff[temp]&0x0200)>0)?1:0 ) );
	  seg10_port( ( ((lcd_buff[temp]&0x0400)>0)?1:0 ) );	  	
	  clr_com(temp);
    }
    else
   {                            
	  seg07_port(~lcd_buff[temp]);
	  seg8_port( ( ((lcd_buff[temp]&0x0100)>0)?0:1 ) );
	  seg9_port(( ((lcd_buff[temp]&0x0200)>0)?0:1 ) );
	  seg10_port( ( ((lcd_buff[temp]&0x0400)>0)?0:1 ) );	  		  
	  set_com(temp);
   }

   cnt++;
  if(cnt>7)cnt = 0;
}
#elif defined(LCD_SEGMENT_USE_10_SEGS_4_COMS)
void lcd_gpio_scan(void)
{
    static u8 cnt = 0;
    xd_u8 temp;
  	
    temp = cnt>>1;
    close_com(temp);
    if(cnt & 0x01){
	    
	  seg07_port(lcd_buff[temp]);
	  seg8_port( ( ((lcd_buff[temp]&0x0100)>0)?1:0 ) );
	  seg9_port( ( ((lcd_buff[temp]&0x0200)>0)?1:0 ) );
	  clr_com(temp);
    }
    else
   {                            
	  seg07_port(~lcd_buff[temp]);
	  seg8_port( ( ((lcd_buff[temp]&0x0100)>0)?0:1 ) );
	  seg9_port(( ((lcd_buff[temp]&0x0200)>0)?0:1 ) );
	  set_com(temp);
   }

   cnt++;
  if(cnt>7)cnt = 0;
}
#elif defined(K000_XingChuang_x821_V001)||defined(K2038_DCX_2038_V001)||defined(LCD_SEGMENT_USE_8_SEGS_5_COMS)
void lcd_gpio_scan(void)
{
    static u8 cnt = 0;
    u8 temp;

#if defined(USE_BAT_MANAGEMENT)
#ifdef CUSTOM_BAT_ICON_DISP
	Disp_custom_bat_icon();
#endif	
#endif

    temp = cnt>>1;
    close_com(temp);
    if(cnt & 0x01){
	    
	  seg07_port(lcd_buff[temp]);
	  clr_com(temp);
    }
    else
   {                            
	  seg07_port(~(lcd_buff[temp]));
	  set_com(temp);
   }

   cnt++;
  if(cnt>9)cnt = 0;
}
#elif defined(K1150_LS_1150_V001)
void lcd_gpio_scan(void)
{
    static u8 cnt = 0;
    u8 temp;
#if defined(USE_BAT_MANAGEMENT)
#ifdef CUSTOM_BAT_ICON_DISP
	Disp_custom_bat_icon();
#endif	
#endif

    temp = cnt>>1;
    close_com(temp);
    if(cnt & 0x01){
	    
	  seg07_port(lcd_buff[temp]);
	  seg8_port( ( ((lcd_buff[temp]&0x0100)>0)?1:0 ) );	  
	  clr_com(temp);
    }
    else
   {                            
	  seg07_port(~(lcd_buff[temp]));
	  seg8_port(( ((lcd_buff[temp]&0x0100)>0)?0:1 ));	  
	  set_com(temp);
   }

   cnt++;
  if(cnt>9)cnt = 0;
}
#else
void lcd_gpio_scan(void)
{
    static u8 cnt = 0;
    u8 temp;

    temp = cnt>>1;
    close_com(temp);
    if(cnt & 0x01){
	    
	  seg07_port(lcd_buff[temp]);
	  seg8_port( ( ((lcd_buff[temp]&0x0100)>0)?1:0 ) );
	  clr_com(temp);
    }
    else
   {                            
	  seg07_port(~lcd_buff[temp]);
	  seg8_port(( ((lcd_buff[temp]&0x0100)>0)?0:1 ));
	  set_com(temp);
   }

   cnt++;
  if(cnt>7)cnt = 0;
}
#endif
void init_disp(void)
{
    	disp_buf_clear();
    	seg_init();
    	com_init();
	lcd_backlight_ctrl(1);		
    	//bklt_init();
}
void updateLcd(void)
{
}
void lcd_power_down(void)
{
	disp_buf_clear();
}
#endif


