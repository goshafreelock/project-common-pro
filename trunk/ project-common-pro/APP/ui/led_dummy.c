#include "Custom_config.h"
#include "config.h"

#if !defined(LED_GPIO_DRV)&&!defined(LED_DRV_USE_SM1628)&&!defined(LCD_GPIO_DRV)&&!defined(USE_LCD_DRV_HT1621)&&!defined(USE_LCD_DRV_TM1721)
void disp_buf_clear(void)
{
}
void init_disp(void)
{
}
void Disp_Null(void)
{
}
void Disp_Num(void)
{
}

void Disp_Filenum(void)
{
}
void Disp_Nofile(void)
{
}
void Disp_Waiting(void)
{
}
void Disp_Nodevice(void)
{
}
void Disp_Vol(void)
{
}
void Disp_Error(void)
{

}
void Disp_Playmode(void)
{
}void disp_file_time(void)
{
}

void Disp_Pause(void)
{
}
void Disp_Play(void)
{
}

void Disp_File_Name(void)
{

}
void Disp_Eq(void)
{
}
void Disp_USB_Slave(void)
{
}
void Disp_AUX(void)
{
}
void Disp_Start(void)
{
}
void Disp_PwrOFF(void)
{

}
void Disp_Power_up(void)
{
}

void Disp_Freq(void )
{
}
void Disp_CH_NO(void )
{
}
void Disp_Scan_NO(void )
{
}
void Disp_CH_Sel()
{
}
void Disp_Stop()
{
}
void Disp_Dev_Change(u8 flag)
{
}
#if(RTC_ENABLE)

void oppo_area_rtc(u8 setting)
{
}
void get_curr_setting_data(u8 setting)
{
}
void Disp_RTC_POINT()
{
}
#ifdef USE_RTC_YEAR_FUNCTION
void Disp_RTC_Date()
{
}
#endif
void Disp_RTC()
{
}
void Disp_Alm_Up(void)
{
}
#endif
#endif
