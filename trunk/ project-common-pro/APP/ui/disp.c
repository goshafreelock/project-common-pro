/*--------------------------------------------------------------------------*/
/**@file   DISP.C
   @brief    显示模块
   @details
   @author
   @date   2010-12-13
   @note
*/
/*----------------------------------------------------------------------------*/

#include "config.h"
#include "disp.h"
#include "lcd.h"
#include "resource.h"
#include "decode.h"
#include "mp3mode.h"
#include "rtc_mode.h"

extern _xdata u8 LCDBuff[LCDPAGE][LCDCOLUMN];      ///< 屏幕显存
extern coordinate LCDsite;                         ///< 当前屏幕显示的坐标
extern FSAPIMSG _pdata fs_msg;                     ///< 带有文件文件系统信息的结构体变量
extern u8 _idata  my_music_vol;  
extern u8 play_mode;                               ///< 当前播放的循环模式
extern u8 eq_mode;                                 ///< 当前播放的音效模式
extern u16 cfilenum;                               ///< 当前数字输入的结果
extern u8 device_active;                           ///< 当前活动的设备
extern xd_u8 all_channl;                              ///< FM收音当前搜索到的台总数
extern xd_u16 frequency;                              ///< 当前频率
extern xd_u8 fre_channl;                              ///< FM收音当前所在的台号
extern xd_u8 fre_point[];                      ///< FM收音搜索到的台的缓存
extern MAD_DECODE_INFO _pdata mad_decode_dsc;      ///< 带有解码信息的结构体变量
extern u16 filename_len;                           ///< 当前显示的文件名的长度（可能会拼接有ID3V2信息）
extern _xdata u8 filename_buff[100];               ///< 当前显示的文件名的缓存BUFF（可能会拼接有ID3V2信息）
//extern u16 filenameCnt;                            ///< 文件名滚动显示计数



xd_u8 bcd_number[5];      ///<BCD码BUFF

u8 _code asc_number[] = "0123456789";    ///<0~9的ASCII码表


_code u8 rtc_xy_len[][3]=
{
    {YEARCOM,0,32},
    {MONTHCOM,0,16},
    {DAYCOM,0,16},
    {HOURCOM,2,16},
    {MINCOM,2,16},
    {SECCOM,2,16},
};

_code u8  alm_xy_len[][3]=
{
    {ALMSWITCH,0,24},
    {HOURACOM,2,16},
    {MINACOM,2,16},
};



u8 _code playmodestr[4][7] =
{
    {"ALL"},
    {"FOLDER"},
    {"ONE"},
    {"RANDOM"}
};                                      ///<PLAY MODE 界面
u8 _code playmode_x[4] =
{
    (LCDCOLUMN-3*8)/2,
    (LCDCOLUMN-6*8)/2,
    (LCDCOLUMN-3*8)/2,
    (LCDCOLUMN-6*8)/2,
};                                      ///<PLAY MODE 界面的显示偏移
u8 _code eqmodestr[5][8] =
{
    {"NORMAL"},
    {"POP"},
    {"ROCK"},
    {"JAZZ"},
    {"CLASSIC"},//CLASSIC
};                                ///<音效模式界面
u8 _code eqmode_x[5] =
{
    (LCDCOLUMN-6*8)/2,
    (LCDCOLUMN-3*8)/2,
    (LCDCOLUMN-4*8)/2,
    (LCDCOLUMN-4*8)/2,
    (LCDCOLUMN-7*8)/2,
};                    ///<音效模式 界面的显示偏移



_code u16 * _code eq_tab[] =
{
    gImage_eqnor,
    gImage_eqpop,
    gImage_eqrck,
    gImage_eqjaz,
    gImage_cls,
};              ///<音效模式的小图标指针BUFF（图标放在CODE区中）


/*----------------------------------------------------------------------------*/
/**@brief  获取一个一位十进制的数的个位
   @param  i:输入的一个一位十进制的数
   @return 无
   @note   void itoa1(u8 i)
*/
/*----------------------------------------------------------------------------*/
void itoa1(u8 i)
{
    bcd_number[0] = asc_number[i % 10];
    bcd_number[1] = 0;
}

/*----------------------------------------------------------------------------*/
/**@brief  获取一个2位十进制的数的各个位
   @param  i:输入的一个2位十进制的数
   @return 无
   @note   void itoa2(u8 i)
*/
/*----------------------------------------------------------------------------*/
void itoa2(u8 i)
{
    bcd_number[0] = asc_number[(i % 100) / 10];
    bcd_number[1] = asc_number[i % 10];
    bcd_number[2] = 0;
}
/*----------------------------------------------------------------------------*/
/**@brief  获取一个3位十进制数的各个位
   @param  i:输入的一个3位十进制数
   @return 无
   @note   void itoa3(u8 i)
*/
/*----------------------------------------------------------------------------*/
void itoa3(u16 i)
{
    bcd_number[0] = asc_number[(i % 1000) / 100];
    bcd_number[1] = asc_number[(i % 100) / 10];
    bcd_number[2] = asc_number[i % 10];
    bcd_number[3] = 0;
}
/*----------------------------------------------------------------------------*/
/**@brief  获取一个4位十进制的数的各个位
   @param  i:输入的一个4位十进制的数
   @return 无
   @note   void itoa4(u8 i)
*/
/*----------------------------------------------------------------------------*/
void itoa4(u16 i)
{
    bcd_number[0] = asc_number[(i % 10000) / 1000];
    bcd_number[1] = asc_number[(i % 1000) / 100];
    bcd_number[2] = asc_number[(i % 100) / 10];
    bcd_number[3] = asc_number[i % 10];
    bcd_number[4] = 0;
}
/*----------------------------------------------------------------------------*/
/**@brief  设置当前显示的坐标
   @param  x : 列坐标; y : 行坐标;
   @return 无
   @note   LCD_Buff_position
*/
/*----------------------------------------------------------------------------*/
void LCD_Buff_position(u8 x,u8 y)  //设置屏幕坐标  x:0~127 column address    y:0~3 page address
{
    LCDsite.x = x;
    LCDsite.y = y;
}
/*----------------------------------------------------------------------------*/
/**@brief   字模放大到兩倍函數
   @param   八位的單列字模
   @return  放大到16位的列字模
   @note    u16 display_sizex2(u8 chardata)
*/
/*----------------------------------------------------------------------------*/
u16 display_sizex2(u8 chardata)
{
    u16 result = 0;
    u8 i;

    for (i = 0; i < 8; i++)
    {
        result <<= 1;
        if (chardata & 0x80)
            result++;
        result <<= 1;
        if (chardata & 0x80)
            result++;
        chardata <<= 1;
    }
    return result;
}
/*----------------------------------------------------------------------------*/
/**@brief   将单列的字模放入到指定的坐标中
   @param   y:行坐标；x列坐标；dat:八位的字模
   @return  无
   @note    void to_lcdbuff(u8 y,u8 x, u8 dat)
*/
/*----------------------------------------------------------------------------*/
void to_lcdbuff(u8 y,u8 x, u8 dat)
{
    if ( (x >= LCDCOLUMN ) || (y >= LCDPAGE ) )
    {
        return;
    }
    LCDBuff[y][x] = dat;
}
/*----------------------------------------------------------------------------*/
/**@brief   将一个指定大小的图片放在现存中
   @param   y:行尺寸；x：列尺寸；*bmp一个指向图片模型的指针（图片放在CODE区）
   @return  无
   @note    void disp_bmp(u8 y,u8 x,u8 _code *bmp)
*/
/*----------------------------------------------------------------------------*/
void disp_bmp(u8 y,u8 x,u8 _code *bmp)
{
    u8 i,j;

    for (i = 0;i < x;i++)
    {
        for (j = 0;j < y;j++)
        {
            to_lcdbuff(LCDsite.y+j,LCDsite.x,*(bmp+j*x+i));
        }
        LCDsite.x++;
    }
}
/*----------------------------------------------------------------------------*/
/**@brief  显示一个字符
   @param  chardata：字符对于德ASCII码，字符的大小
   @return 0:未能完全显示成功;1:完全显示成功;
   @note   u8 disp_char(u8 chardata,u8 size)
*/
/*----------------------------------------------------------------------------*/
u8 disp_char(u8 chardata,u8 size/*,u8 offset*/)
{
    u8 i;
    u16 temp;

    if (( chardata < ' ') || ( chardata > 127))
    {
        chardata = '~';
    }

    if (size)
    {
        for (i = 0;i<8;i++)
        {
            if (LCDsite.x >= (LCDCOLUMN - 2))
            {
                return 0;
            }
            temp = display_sizex2(chars_table_l[16*(chardata - ' ')+i]);//fontBuff[i]);
            to_lcdbuff(LCDsite.y,LCDsite.x,temp);
            to_lcdbuff(LCDsite.y,LCDsite.x+1,temp);
            to_lcdbuff(LCDsite.y+1,LCDsite.x,temp>>8);
            to_lcdbuff(LCDsite.y+1,LCDsite.x+1,temp>>8);

            temp = display_sizex2(chars_table_l[16*(chardata - ' ')+i+8]);//fontBuff[i+8]);
            to_lcdbuff(LCDsite.y+2,LCDsite.x,temp);
            to_lcdbuff(LCDsite.y+2,LCDsite.x+1,temp);
            to_lcdbuff(LCDsite.y+2+1,LCDsite.x,temp>>8);
            to_lcdbuff(LCDsite.y+2+1,LCDsite.x+1,temp>>8);
            LCDsite.x += 2;
        }
    }
    else
    {
        for (i = 0 ;i<8;i++)
        {
            if (LCDsite.x >= LCDCOLUMN)
            {
                return 0;
            }
            to_lcdbuff(LCDsite.y,LCDsite.x,chars_table_l[16*(chardata - ' ')+i]);//fontBuff[i]);
            to_lcdbuff(LCDsite.y+1,LCDsite.x,chars_table_l[16*(chardata - ' ')+i+8]);//fontBuff[i+8]);
            LCDsite.x++;
        }
    }
    return 1;
}
/*----------------------------------------------------------------------------*/
/**@brief   在当前的坐标的基础上做偏移
   @param   X：列偏移;Y：行偏移;
   @return  无
   @note    void set_lcd_position(u8 y,u8 x)
*/
/*----------------------------------------------------------------------------*/
void set_lcd_position(u8 y,u8 x)
{
    LCDsite.x += x;
    LCDsite.y += y;
}
/*----------------------------------------------------------------------------*/
/**@brief    显示一个字符串
   @param    *str : 数组指针;size:数组的字符显示大小;
   @return   无
   @note     void disp_string(u8 *str,u8 size)
*/
/*----------------------------------------------------------------------------*/
void disp_string(u8 *str,u8 size)
{
    while (0 != *str)
    {
        disp_char(*str,size);
        str++;
    }
}
/*----------------------------------------------------------------------------*/
/**@brief  显示一个16位的数据
   @param  number:十六位的数据
   @return 无
   @note   void disp_word_number(u16 number)
*/
/*----------------------------------------------------------------------------*/
void disp_word_number(u16 number)
{
    LCD_Buff_position((LCDCOLUMN - (4 * 16)) / 2,0);
    itoa4(number);
    disp_string(bcd_number, 1);
}
/*----------------------------------------------------------------------------*/
/**@brief  无文件的显示界面
   @param  无
   @return 无
   @note   void Disp_Nofile(void)
*/
/*----------------------------------------------------------------------------*/
void Disp_Nofile(void)
{
    LCD_Buff_position((LCDCOLUMN - (10 * 8)) / 2,2);
    disp_string("no file...",0);
}
/*----------------------------------------------------------------------------*/
/**@brief  等待界面
   @param  无
   @return 无
   @note   void Disp_waiting(void)
*/
/*----------------------------------------------------------------------------*/
void Disp_Waiting(void)
{
    LCD_Buff_position((LCDCOLUMN - (10 * 8)) / 2,2);
    disp_string("waiting...",0);
}
/*----------------------------------------------------------------------------*/
/**@brief  无设备的界面
   @param   无
   @return  无
   @note    void Disp_Nodevice(void)
*/
/*----------------------------------------------------------------------------*/
void Disp_Nodevice(void)
{
    LCD_Buff_position((LCDCOLUMN - (12*8)) / 2,2);
    disp_string("no device...",0);
}

/*----------------------------------------------------------------------------*/
/**@brief  音量显示界面
   @param  无
   @return 无
   @note   void Disp_Vol(void)
*/
/*----------------------------------------------------------------------------*/
void Disp_Vol(void)
{
    LCD_Buff_position((LCDCOLUMN - (8*8)) / 2,0);
    disp_bmp(4,31,gImage_vol);
    itoa2(my_music_vol);
    disp_string(bcd_number, 1);
}
/*----------------------------------------------------------------------------*/
/**@brief   循环模式的控制显示界面
   @param   无
   @return  无
   @note    void Diap_Playmode(void)
*/
/*----------------------------------------------------------------------------*/
void Diap_Playmode(void)
{
    LCD_Buff_position(playmode_x[play_mode],1);
    disp_string(&playmodestr[play_mode][0],0);

}
/*----------------------------------------------------------------------------*/
/**@brief    在当前坐标上显示一个小的十进制的一位数字
   @param    num:小于10的十进制数
   @return   无
   @note     void disp_small_number(u8 num)
*/
/*----------------------------------------------------------------------------*/
void disp_small_number(u8 num)
{
    disp_bmp(1,5,gImage_number + ((num - '0') * 5));
    set_lcd_position(0,1);
}
/*----------------------------------------------------------------------------*/
/**@brief    用最小的数字字体显示当前播放歌曲的曲号和当前设备的总歌曲数
   @param    无
   @return   无
   @note     void disp_small_filenumber(void)
*/
/*----------------------------------------------------------------------------*/
void disp_small_filenumber(void)
{
    LCD_Buff_position(FILENUM_COLUMN,0);
    itoa4(fs_msg.fileNumber);

    disp_small_number(bcd_number[0]);
    disp_small_number(bcd_number[1]);
    disp_small_number(bcd_number[2]);
    disp_small_number(bcd_number[3]);

    LCD_Buff_position(FILENUM_COLUMN,1);

    itoa4(fs_msg.fileTotal);
    disp_small_number(bcd_number[0]);
    disp_small_number(bcd_number[1]);
    disp_small_number(bcd_number[2]);
    disp_small_number(bcd_number[3]);
}
/*----------------------------------------------------------------------------*/
/**@brief    用最小的数字字体显示当前播放的时间，以及当前文件的总时间
   @param    无
   @return   无
   @note     void disp_file_time(void)
*/
/*----------------------------------------------------------------------------*/
void disp_file_time(void)
{
    u8 sec;
    u8 min;
    u32 file_play_time;
    file_play_time = get_music_play_time();
//	printf("play for time %lu\n",file_play_time);
    sec = file_play_time % 60;
    min = (file_play_time/60) % 60;
    //deg("%02u:%02u  ",(u16)min,(u16)sec);
    LCD_Buff_position(PLAYTIME_COLUMN,0);
    itoa2(min);
    disp_small_number(bcd_number[0]);
    disp_small_number(bcd_number[1]);
    disp_bmp(1,3,gImage_small_dot);
    itoa2(sec);
    disp_small_number(bcd_number[0]);
    disp_small_number(bcd_number[1]);
    LCD_Buff_position(PLAYTIME_COLUMN,1);
    sec = mad_decode_dsc.total_time % 60;
    min = (mad_decode_dsc.total_time/60) % 60;
    itoa2(min);
    disp_small_number(bcd_number[0]);
    disp_small_number(bcd_number[1]);
    disp_bmp(1,3,gImage_small_dot);
    itoa2(sec);
    disp_small_number(bcd_number[0]);
    disp_small_number(bcd_number[1]);
}

/*----------------------------------------------------------------------------*/
/**@brief    解码暂停界面
   @param    无
   @return   无
   @note     void Disp_Pause(void)
*/
/*----------------------------------------------------------------------------*/
void Disp_Pause(void)
{
    LCD_Buff_position((LCDCOLUMN-(2*5)*8)/2,0);
    disp_string("PAUSE",1);
    //LCD_Buff_position(1,0);
    //disp_bmp(4,96,gImage_pause);
}
/*----------------------------------------------------------------------------*/
/**@brief    解码播放界面
   @param    无
   @return   无
   @note     void Disp_Play(void)
*/
/*----------------------------------------------------------------------------*/
void Disp_Play(void)
{
    LCD_Buff_position(DEVICE_COLUMN,0);
    if (device_active == BIT(SDMMC))
    {
        disp_bmp(2,16,gImage_sd);
    }
    else
        disp_bmp(2,16,gImage_udisk);
    disp_file_time();
    disp_small_filenumber();
    LCD_Buff_position(EQ_COLUMN,0);
    disp_bmp(2,17,(u8 _code *)eq_tab[eq_mode]);

    //filenameCnt = 0;
    dispfilename();
}



/*----------------------------------------------------------------------------*/
/**@brief    显示文件名（可能会拼接有ID3V2信息）
   @param    无
   @return   无
   @note     void dispfilename(void)
*/
/*----------------------------------------------------------------------------*/
void dispfilename(void)
{
    if (filename_len <= (LCDCOLUMN / 8))
        filenameCnt = 0;

    if (filenameCnt == 0)
    {
        LCD_Buff_position(0,2);
        disp_string(filename_buff,0);
    }
    else
    {
        my_memcpy( &LCDBuff[2][0],&LCDBuff[2][1] ,LCDCOLUMN-1);
        my_memcpy( &LCDBuff[3][0],&LCDBuff[3][1] ,LCDCOLUMN-1);
        LCDBuff[2][LCDCOLUMN - 1] = 0;
        LCDBuff[3][LCDCOLUMN - 1] = 0;
        LCD_Buff_position(LCDCOLUMN - 8 - (u8)filenameCnt % 8,2);
        disp_string(filename_buff + (filenameCnt / 8) + (LCDCOLUMN-8) / 8,0);

    }

    filenameCnt++;
    if (filenameCnt >= (filename_len*8))
    {
        filenameCnt = 0;
    }
}
/*----------------------------------------------------------------------------*/
/**@brief  音效控制界面
   @param  无
   @return 无
   @note   void Disp_Eq(void)
*/
/*----------------------------------------------------------------------------*/
void Disp_Eq(void)
{
    LCD_Buff_position(eqmode_x[eq_mode],1);
    disp_string(&eqmodestr[eq_mode][0],0);
}
/*----------------------------------------------------------------------------*/
/**@brief  USB从机任务的界面
   @param  无
   @return 无
   @note   void Disp_USB_Slave(void)
*/
/*----------------------------------------------------------------------------*/
void Disp_USB_Slave(void)
{
    LCD_Buff_position((LCDCOLUMN - (8 * 10)) /2,1);
    disp_string("connect pc",0);

}
/*----------------------------------------------------------------------------*/
/**@brief   上电机界面
   @param   无
   @return  无
   @note    void Disp_Power_up(void)
*/
/*----------------------------------------------------------------------------*/
void Disp_Power_up(void)
{
    LCD_Buff_position((LCDCOLUMN - (16*5)) / 2,0);
    disp_string("HELLO", 1);
}
/*----------------------------------------------------------------------------*/
/**@brief   Disp_Freq
   @param   无
   @return  无
   @note    FM收音主界面
*/
/*----------------------------------------------------------------------------*/
void Disp_Freq(void )
{
    LCD_Buff_position(FM_CHANNL_COLUMN,0);
    itoa2(fre_channl);
    disp_string(bcd_number, 0);

    disp_char(' ',0);

    itoa2(all_channl);
    disp_string(bcd_number, 0);

    //frequency
    if (frequency > 999)
    {
        LCD_Buff_position(FRE_4_COLUMN,2);
        disp_char(asc_number[(u8)((frequency/1000)%10)], 0);
    }
    else
    {
        LCD_Buff_position(FRE_3_COLUMN,2);
        //LCD_Buff_position(32+8,2);
    }
    disp_char(asc_number[(u8)((frequency/100)%10)],0);
    disp_char(asc_number[(u8)((frequency/10)%10)],0);
    disp_char('.',0);
    disp_char(asc_number[frequency%10], 0);
    disp_string("MHz",0);
}
/*----------------------------------------------------------------------------*/
/**@brief   设备改变界面
   @param   flag ： 当前改变设备的标记
   @return  无
   @note    void disp_devchange(u8 flag)
*/
/*----------------------------------------------------------------------------*/
void disp_devchange(u8 flag)
{
    if (2 == flag)
    {
        LCD_Buff_position((LCDCOLUMN-11*8)/2,1);
        disp_string("USB REMOVED",0);
    }
    else if (1 == flag)
    {
        LCD_Buff_position((LCDCOLUMN-12*8)/2,1);
        disp_string("CARD REMOVED",0);
    }
    else if (0 == flag)
    {
        LCD_Buff_position((LCDCOLUMN-10*8)/2,1);
        disp_string("PC REMOVED",0);
    }
}

void disp_aux(void)
{
    LCD_Buff_position((LCDCOLUMN-(2*3)*8)/2,0);
    disp_string("AUX",1);
}

/*----------------------------------------------------------------------------*/
/**@brief   将限定区域内的显示取反
   @param
   @return  无
   @note    void oppo_area_rtc(u8 i)
*/
/*----------------------------------------------------------------------------*/
void oppo_area_rtc(u8 i)
{
    u8 cnt;
    for (cnt=0;cnt < rtc_xy_len[i][2];cnt++)
    {			//y				//x
        LCDBuff[rtc_xy_len[i][1]][rtc_xy_len[i][0]+cnt]= ~LCDBuff[rtc_xy_len[i][1]][rtc_xy_len[i][0]+cnt];
        LCDBuff[rtc_xy_len[i][1]+1][rtc_xy_len[i][0]+cnt]= ~LCDBuff[rtc_xy_len[i][1]+1][rtc_xy_len[i][0]+cnt];
    }
}
/*----------------------------------------------------------------------------*/
/**@brief   将限定区域内的显示取反
   @param
   @return  无
   @note    void oppo_area_sec(u8 i)
*/
/*----------------------------------------------------------------------------*/
void oppo_area_alm(u8 i)
{
    u8 cnt;
    for (cnt=0;cnt < alm_xy_len[i][2];cnt++)
    {							//y					//x
        LCDBuff[alm_xy_len[i][1]][alm_xy_len[i][0]+cnt]= ~LCDBuff[alm_xy_len[i][1]][alm_xy_len[i][0]+cnt];
        LCDBuff[alm_xy_len[i][1]+1][alm_xy_len[i][0]+cnt]= ~LCDBuff[alm_xy_len[i][1]+1][alm_xy_len[i][0]+cnt];
    }
}

#if RTC_ENABLE
extern _xdata RTC_TIME curr_date;
extern _xdata ALM_TIME curr_alm;

extern _xdata u8 rtc_set;
extern _xdata u8 alm_set;
extern _xdata u8 rtc_mode;
extern  bool alm_sw;

void disp_alm_clock(void)
{
    LCD_Buff_position(HOURACOM,2);
    itoa2(curr_alm.hour);
    disp_string(bcd_number,0);
    disp_char(':',0);
    itoa2(curr_alm.minutes);
    disp_string(bcd_number,0);

}
/*----------------------------------------------------------------------------*/
/**@brief  RTC设置界面
   @param  无
   @return 无
   @note   void disp_rtc(void)
*/
/*----------------------------------------------------------------------------*/

void disp_rtc()
{
    if (rtc_mode != ALM_SET_MODE)
    {
        //year
        LCD_Buff_position(YEARCOM,0);
        itoa4(curr_date.year);
        disp_string(bcd_number,0);

        disp_char('/',0);

        //month
        itoa2(curr_date.month);
        disp_string(bcd_number,0);

        disp_char('/',0);

        //day
        itoa2(curr_date.day);
        disp_string(bcd_number,0);


        //hour
        LCD_Buff_position(HOURCOM,2);
        itoa2(curr_date.hour);
        disp_string(bcd_number,0);

        disp_char(':',0);

        //minutes
        itoa2(curr_date.minutes);
        disp_string(bcd_number,0);

        disp_char(':',0);

        //second
        itoa2(curr_date.second);
        disp_string(bcd_number,0);

        disp_char('*',0);

        itoa1(curr_date.date);
        disp_string(bcd_number,0);
        //RTC_SET_MODE选中区域取反函数
        if (rtc_mode == RTC_SET_MODE)
            oppo_area_rtc(rtc_set);
    }

    if (rtc_mode == ALM_SET_MODE)
    {
        LCD_Buff_position((LCDCOLUMN-9*8)/2,0);
        disp_string("ALARM:",0);
        if (alm_sw)
            disp_string("ON",0);
        else
            disp_string("OFF",0);
        //hour
        disp_alm_clock();
        oppo_area_alm(alm_set);
    }
}


void disp_alm_up(void)
{
    LCD_Buff_position((LCDCOLUMN-9*8)/2,0);
    disp_string("CLOCK UP",0);
    disp_alm_clock();
}
#endif
#if 0
/*----------------------------------------------------------------------------*/
/**@brief   显示集中处理函数
   @param   LCDinterf 界面参数
   @return  无
   @note    void Disp_Con(u8 LCDinterf)
*/
/*----------------------------------------------------------------------------*/
void Disp_Con(u8 LCDinterf)
{
    return_cnt = 0;
    curr_menu = LCDinterf;
    if (DISP_NULL == LCDinterf)
    {
        return;
    }
    clear_lcd();
    switch (LCDinterf)
    {
    case DISP_NULL:
        //Disp_Play();
        break;
    case DISP_DWORD_NUMBER:
        disp_word_number(cfilenum);
        break;
    case DISP_FILENUM:
        disp_word_number(fs_msg.fileNumber);
        break;
    case DISP_NOFILE:
        Disp_Nofile();
        break;
    case DISP_NODEVICE:
        Disp_Nodevice();
        break;
    case DISP_PLAY:
        Disp_Play();
        break;
    case DISP_PAUSE:
        Disp_Pause();
        break;
    case DISP_VOL:
        Disp_Vol();
        break;
    case DISP_EQ:
        Disp_Eq();
        break;
    case DISP_POWER_UP:
        Disp_Power_up();
        break;
    case DISP_PLAYMODE:
        Diap_Playmode();
        break;
    case DISP_WAIT:
        Disp_waiting();
        break;
    case DISP_USBDEV:
        Disp_USB_Slave();
        break;
    case DISP_FREQ:
        Disp_Freq();
        break;
    case DISP_USBOUT:
        disp_devchange(2);
        break;
    case DISP_SDOUT:
        disp_devchange(1);
        break;
    case DISP_AUX:
        disp_aux();
        break;
#if RTC_ENABLE
    case DISP_RTC:
        disp_rtc();
        break;
    case DISP_RTC_PWD:
        break;
    case DISP_ALM_UP:
        disp_alm_up();
        break;
#endif
    }
    draw_lcd(0, 4);
}
#endif
