/*--------------------------------------------------------------------------*/
/**@file   DISP.C
   @brief    ��ʾģ��
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

extern _xdata u8 LCDBuff[LCDPAGE][LCDCOLUMN];      ///< ��Ļ�Դ�
extern coordinate LCDsite;                         ///< ��ǰ��Ļ��ʾ������
extern FSAPIMSG _pdata fs_msg;                     ///< �����ļ��ļ�ϵͳ��Ϣ�Ľṹ�����
extern u8 _idata  my_music_vol;  
extern u8 play_mode;                               ///< ��ǰ���ŵ�ѭ��ģʽ
extern u8 eq_mode;                                 ///< ��ǰ���ŵ���Чģʽ
extern u16 cfilenum;                               ///< ��ǰ��������Ľ��
extern u8 device_active;                           ///< ��ǰ����豸
extern xd_u8 all_channl;                              ///< FM������ǰ��������̨����
extern xd_u16 frequency;                              ///< ��ǰƵ��
extern xd_u8 fre_channl;                              ///< FM������ǰ���ڵ�̨��
extern xd_u8 fre_point[];                      ///< FM������������̨�Ļ���
extern MAD_DECODE_INFO _pdata mad_decode_dsc;      ///< ���н�����Ϣ�Ľṹ�����
extern u16 filename_len;                           ///< ��ǰ��ʾ���ļ����ĳ��ȣ����ܻ�ƴ����ID3V2��Ϣ��
extern _xdata u8 filename_buff[100];               ///< ��ǰ��ʾ���ļ����Ļ���BUFF�����ܻ�ƴ����ID3V2��Ϣ��
//extern u16 filenameCnt;                            ///< �ļ���������ʾ����



xd_u8 bcd_number[5];      ///<BCD��BUFF

u8 _code asc_number[] = "0123456789";    ///<0~9��ASCII���


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
};                                      ///<PLAY MODE ����
u8 _code playmode_x[4] =
{
    (LCDCOLUMN-3*8)/2,
    (LCDCOLUMN-6*8)/2,
    (LCDCOLUMN-3*8)/2,
    (LCDCOLUMN-6*8)/2,
};                                      ///<PLAY MODE �������ʾƫ��
u8 _code eqmodestr[5][8] =
{
    {"NORMAL"},
    {"POP"},
    {"ROCK"},
    {"JAZZ"},
    {"CLASSIC"},//CLASSIC
};                                ///<��Чģʽ����
u8 _code eqmode_x[5] =
{
    (LCDCOLUMN-6*8)/2,
    (LCDCOLUMN-3*8)/2,
    (LCDCOLUMN-4*8)/2,
    (LCDCOLUMN-4*8)/2,
    (LCDCOLUMN-7*8)/2,
};                    ///<��Чģʽ �������ʾƫ��



_code u16 * _code eq_tab[] =
{
    gImage_eqnor,
    gImage_eqpop,
    gImage_eqrck,
    gImage_eqjaz,
    gImage_cls,
};              ///<��Чģʽ��Сͼ��ָ��BUFF��ͼ�����CODE���У�


/*----------------------------------------------------------------------------*/
/**@brief  ��ȡһ��һλʮ���Ƶ����ĸ�λ
   @param  i:�����һ��һλʮ���Ƶ���
   @return ��
   @note   void itoa1(u8 i)
*/
/*----------------------------------------------------------------------------*/
void itoa1(u8 i)
{
    bcd_number[0] = asc_number[i % 10];
    bcd_number[1] = 0;
}

/*----------------------------------------------------------------------------*/
/**@brief  ��ȡһ��2λʮ���Ƶ����ĸ���λ
   @param  i:�����һ��2λʮ���Ƶ���
   @return ��
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
/**@brief  ��ȡһ��3λʮ�������ĸ���λ
   @param  i:�����һ��3λʮ������
   @return ��
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
/**@brief  ��ȡһ��4λʮ���Ƶ����ĸ���λ
   @param  i:�����һ��4λʮ���Ƶ���
   @return ��
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
/**@brief  ���õ�ǰ��ʾ������
   @param  x : ������; y : ������;
   @return ��
   @note   LCD_Buff_position
*/
/*----------------------------------------------------------------------------*/
void LCD_Buff_position(u8 x,u8 y)  //������Ļ����  x:0~127 column address    y:0~3 page address
{
    LCDsite.x = x;
    LCDsite.y = y;
}
/*----------------------------------------------------------------------------*/
/**@brief   ��ģ�Ŵ󵽃ɱ�����
   @param   ��λ�Ć�����ģ
   @return  �Ŵ�16λ������ģ
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
/**@brief   �����е���ģ���뵽ָ����������
   @param   y:�����ꣻx�����ꣻdat:��λ����ģ
   @return  ��
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
/**@brief   ��һ��ָ����С��ͼƬ�����ִ���
   @param   y:�гߴ磻x���гߴ磻*bmpһ��ָ��ͼƬģ�͵�ָ�루ͼƬ����CODE����
   @return  ��
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
/**@brief  ��ʾһ���ַ�
   @param  chardata���ַ����ڵ�ASCII�룬�ַ��Ĵ�С
   @return 0:δ����ȫ��ʾ�ɹ�;1:��ȫ��ʾ�ɹ�;
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
/**@brief   �ڵ�ǰ������Ļ�������ƫ��
   @param   X����ƫ��;Y����ƫ��;
   @return  ��
   @note    void set_lcd_position(u8 y,u8 x)
*/
/*----------------------------------------------------------------------------*/
void set_lcd_position(u8 y,u8 x)
{
    LCDsite.x += x;
    LCDsite.y += y;
}
/*----------------------------------------------------------------------------*/
/**@brief    ��ʾһ���ַ���
   @param    *str : ����ָ��;size:������ַ���ʾ��С;
   @return   ��
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
/**@brief  ��ʾһ��16λ������
   @param  number:ʮ��λ������
   @return ��
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
/**@brief  ���ļ�����ʾ����
   @param  ��
   @return ��
   @note   void Disp_Nofile(void)
*/
/*----------------------------------------------------------------------------*/
void Disp_Nofile(void)
{
    LCD_Buff_position((LCDCOLUMN - (10 * 8)) / 2,2);
    disp_string("no file...",0);
}
/*----------------------------------------------------------------------------*/
/**@brief  �ȴ�����
   @param  ��
   @return ��
   @note   void Disp_waiting(void)
*/
/*----------------------------------------------------------------------------*/
void Disp_Waiting(void)
{
    LCD_Buff_position((LCDCOLUMN - (10 * 8)) / 2,2);
    disp_string("waiting...",0);
}
/*----------------------------------------------------------------------------*/
/**@brief  ���豸�Ľ���
   @param   ��
   @return  ��
   @note    void Disp_Nodevice(void)
*/
/*----------------------------------------------------------------------------*/
void Disp_Nodevice(void)
{
    LCD_Buff_position((LCDCOLUMN - (12*8)) / 2,2);
    disp_string("no device...",0);
}

/*----------------------------------------------------------------------------*/
/**@brief  ������ʾ����
   @param  ��
   @return ��
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
/**@brief   ѭ��ģʽ�Ŀ�����ʾ����
   @param   ��
   @return  ��
   @note    void Diap_Playmode(void)
*/
/*----------------------------------------------------------------------------*/
void Diap_Playmode(void)
{
    LCD_Buff_position(playmode_x[play_mode],1);
    disp_string(&playmodestr[play_mode][0],0);

}
/*----------------------------------------------------------------------------*/
/**@brief    �ڵ�ǰ��������ʾһ��С��ʮ���Ƶ�һλ����
   @param    num:С��10��ʮ������
   @return   ��
   @note     void disp_small_number(u8 num)
*/
/*----------------------------------------------------------------------------*/
void disp_small_number(u8 num)
{
    disp_bmp(1,5,gImage_number + ((num - '0') * 5));
    set_lcd_position(0,1);
}
/*----------------------------------------------------------------------------*/
/**@brief    ����С������������ʾ��ǰ���Ÿ��������ź͵�ǰ�豸���ܸ�����
   @param    ��
   @return   ��
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
/**@brief    ����С������������ʾ��ǰ���ŵ�ʱ�䣬�Լ���ǰ�ļ�����ʱ��
   @param    ��
   @return   ��
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
/**@brief    ������ͣ����
   @param    ��
   @return   ��
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
/**@brief    ���벥�Ž���
   @param    ��
   @return   ��
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
/**@brief    ��ʾ�ļ��������ܻ�ƴ����ID3V2��Ϣ��
   @param    ��
   @return   ��
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
/**@brief  ��Ч���ƽ���
   @param  ��
   @return ��
   @note   void Disp_Eq(void)
*/
/*----------------------------------------------------------------------------*/
void Disp_Eq(void)
{
    LCD_Buff_position(eqmode_x[eq_mode],1);
    disp_string(&eqmodestr[eq_mode][0],0);
}
/*----------------------------------------------------------------------------*/
/**@brief  USB�ӻ�����Ľ���
   @param  ��
   @return ��
   @note   void Disp_USB_Slave(void)
*/
/*----------------------------------------------------------------------------*/
void Disp_USB_Slave(void)
{
    LCD_Buff_position((LCDCOLUMN - (8 * 10)) /2,1);
    disp_string("connect pc",0);

}
/*----------------------------------------------------------------------------*/
/**@brief   �ϵ������
   @param   ��
   @return  ��
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
   @param   ��
   @return  ��
   @note    FM����������
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
/**@brief   �豸�ı����
   @param   flag �� ��ǰ�ı��豸�ı��
   @return  ��
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
/**@brief   ���޶������ڵ���ʾȡ��
   @param
   @return  ��
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
/**@brief   ���޶������ڵ���ʾȡ��
   @param
   @return  ��
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
/**@brief  RTC���ý���
   @param  ��
   @return ��
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
        //RTC_SET_MODEѡ������ȡ������
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
/**@brief   ��ʾ���д�����
   @param   LCDinterf �������
   @return  ��
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
