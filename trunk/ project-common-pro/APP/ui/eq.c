/*--------------------------------------------------------------------------*/
/**@file     eq.c
   @brief    ��Ч����ģ��
   @details
   @author
   @date   2011-3-7
   @note
*/
/*----------------------------------------------------------------------------*/
#include "Custom_config.h"

#include "eq.h"

extern void write_dsp(u8, u8 , u8 );
extern void set_dsp_eq(u8 * eq_table);
extern void close_dsp_eq(void);

#if defined(K637_ZX_306_V001)||defined(K646_ZhuoXing_308_V001)
u8 _code dsp_eq_table[4][5] =
{
    {0, 0, 0 , 25, 50},
    {0, 0, 50 , 0, 0},
    {0, 50, 0 , 0, 0},
    {50, 50, 0 , 0, 0}
};    ///<dsp��Ч�
#else
u8 _code dsp_eq_table[4][5] =
{
    {0, 0, 0 , 25, 50},
    {0, 0, 50 , 0, 0},
    {0, 50, 25 , 0, 0},
    {50, 25, 0 , 25, 0}
};    ///<dsp��Ч��
#endif
#if defined(USE_EQ_TABLE_CUSTOM)
u8 _code EQTableCode[5][11] =
{
    {0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x00}, //NORMAL
    //{0x0D,0x0D,0x0D,0x0D,0x0A,0x09,0x08,0x08,0x06,0x06,0x06}, //BASS
    {0x06,0x06,0x08,0x08,0x0A,0x0A,0x0D,0x0F,0x0F,0x0F,0x0F}, // 
    {0x0f,0x0d,0x0a,0x08,0x05,0x05,0x08,0x0c,0x0e,0x0e,0x0e}, //POP
    {0x05,0x0d,0x0e,0x0f,0x06,0x06,0x0d,0x0d,0x0f,0x0f,0x0e}, //ROCK
    //{0x09,0x09,0x09,0x0f,0x0f,0x0f,0x09,0x0a,0x0e,0x0f,0x09}, //JAZZ
    {0x04,0x08,0x08,0x0e,0x0e,0x08,0x08,0x08,0x0e,0x0e,0x0a},  //CLASSIC

};    ///<DECODER��Ч��
#elif defined(K170_ZK_170_V001)
u8 _code EQTableCode[6][11] =
{
    {0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x00}, //NORMAL
 #ifdef  K170_ZK_170_V001
        {0x09,0x0a,0x0a,0x0a,0x0A,0x09,0x08,0x08,0x06,0x06,0x06}, //BASS
#else
   {0x0D,0x0D,0x0D,0x0D,0x0A,0x09,0x08,0x08,0x06,0x06,0x06}, //BASS
#endif
    {0x06,0x06,0x08,0x08,0x0A,0x0A,0x0D,0x0F,0x0F,0x0F,0x0F}, // 
    //{0x0f,0x0d,0x0a,0x08,0x05,0x05,0x08,0x0c,0x0e,0x0e,0x0e}, //POP
    {0x05,0x0d,0x0e,0x0f,0x06,0x06,0x0d,0x0d,0x0f,0x0f,0x0e}, //ROCK
    //{0x09,0x09,0x09,0x0f,0x0f,0x0f,0x09,0x0a,0x0e,0x0f,0x09}, //JAZZ
    {0x04,0x08,0x08,0x0e,0x0e,0x08,0x08,0x08,0x0e,0x0e,0x0a},  //CLASSIC

  {0x0b,0x0b,0x0b,0x0b,0x0A,0x09,0x08,0x08,0x06,0x06,0x06},//USER


};    ///<DECODER��Ч��
#elif defined(K0000_GW_238_V001)
u8 _code EQTableCode[6][11] =
{
    {0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x00}, //NORMAL
    {0x0D,0x0D,0x0D,0x0D,0x0A,0x09,0x08,0x08,0x06,0x06,0x06}, //BASS
    {0x06,0x06,0x08,0x08,0x0A,0x0A,0x0D,0x0F,0x0F,0x0F,0x0F}, // 
    //{0x0f,0x0d,0x0a,0x08,0x05,0x05,0x08,0x0c,0x0e,0x0e,0x0e}, //POP
    {0x05,0x0d,0x0e,0x0f,0x06,0x06,0x0d,0x0d,0x0f,0x0f,0x0e}, //ROCK
    //{0x09,0x09,0x09,0x0f,0x0f,0x0f,0x09,0x0a,0x0e,0x0f,0x09}, //JAZZ
    {0x04,0x08,0x08,0x0e,0x0e,0x08,0x08,0x08,0x0e,0x0e,0x0a},  //CLASSIC
    {0x0F,0x0F,0x0F,0x0F,0x0A,0x0A,0x0D,0x0C,0x09,0x08,0x06}, // 
 };    ///<DECODER��Ч��
#elif defined(K2012_MY_M90_V001)
u8 _code EQTableCode[5][11] =
{
    {0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x00}, //NORMAL
    {0x0D,0x0D,0x0D,0x0D,0x0A,0x09,0x08,0x08,0x06,0x06,0x06}, //BASS
    {0x06,0x06,0x08,0x08,0x0A,0x0A,0x0C,0x0E,0x0E,0x0D,0x0D}, // 
    //{0x0f,0x0d,0x0a,0x08,0x05,0x05,0x08,0x0c,0x0e,0x0e,0x0e}, //POP
    {0x05,0x0d,0x0e,0x0f,0x06,0x06,0x0d,0x0d,0x0f,0x0f,0x0e}, //ROCK
    //{0x09,0x09,0x09,0x0f,0x0f,0x0f,0x09,0x0a,0x0e,0x0f,0x09}, //JAZZ
    {0x04,0x08,0x08,0x0e,0x0e,0x08,0x08,0x08,0x0e,0x0e,0x0a},  //CLASSIC

};    ///<DECODER��Ч��
#else
u8 _code EQTableCode[5][11] =
{
    {0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x00}, //NORMAL
    {0x0D,0x0D,0x0D,0x0D,0x0A,0x09,0x08,0x08,0x06,0x06,0x06}, //BASS
    {0x06,0x06,0x08,0x08,0x0A,0x0A,0x0D,0x0F,0x0F,0x0F,0x0F}, // 
    //{0x0f,0x0d,0x0a,0x08,0x05,0x05,0x08,0x0c,0x0e,0x0e,0x0e}, //POP
    {0x05,0x0d,0x0e,0x0f,0x06,0x06,0x0d,0x0d,0x0f,0x0f,0x0e}, //ROCK
    //{0x09,0x09,0x09,0x0f,0x0f,0x0f,0x09,0x0a,0x0e,0x0f,0x09}, //JAZZ
    {0x04,0x08,0x08,0x0e,0x0e,0x08,0x08,0x08,0x0e,0x0e,0x0a},  //CLASSIC

};    ///<DECODER��Ч��
#endif
/*----------------------------------------------------------------------------*/
/**@brief   ����DSP��Ч
   @param   * eq_table �� ��Ч����ָ��
   @return  ��
   @note    void set_dsp_eq(u8 * eq_table)
*/
/*----------------------------------------------------------------------------*/
void set_dsp_eq(u8 * eq_table)
{
    u8 i;
//    printf("eq1\n");
    write_dsp(0x7f, 0xff, 0x20);
    for (i = 0; i < 5; i++)
    {
//        printf(" %u ",(u16)i);
        write_dsp(eq_table[i], 0, 0x20);
    }
//    printf("\n eq2\n");
    write_dsp(0x7f, 0xfe, 0x20);
}
/*----------------------------------------------------------------------------*/
/**@brief   ����decode ��Ч
   @param   n : ��Чģʽ
   @return  ��
   @note    void EQ_SET(u8 n)
*/
/*----------------------------------------------------------------------------*/
void decode_eq(u8 n)
{
    if (NORMAL == n)
    {
        set_decode_eq(0);
    }
    else
    {
        set_decode_eq(EQTableCode[n]);
    }
}

/*----------------------------------------------------------------------------*/
/**@brief   ��Ч���ƽӿں���
   @param   n : ��Чģʽ
   @return  ��
   @note    void set_eq(u8 n)
*/
/*----------------------------------------------------------------------------*/

void set_eq(u8 n)
{
#if EQ_WORK_USE == DECODE_EQ
    decode_eq(n);
#else
    if (NORMAL == n)
    {
        close_dsp_eq();
    }
    else
    {
        set_dsp_eq(dsp_eq_table[n-1]);
    }
#endif
}



