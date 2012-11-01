#include "config.h"
#include "disp.h"
#include "lcd.h"
#include "decode.h"
#include "mp3mode.h"
#include "lcdsegment.h"

#ifdef LCD_GPIO_DRV

u8 dispchar(u8 chardata,u8 offset);
void dispstring(u8 *,u8);

extern u8 _idata  my_music_vol;  
extern _xdata u8 filename_buff[100];

extern FSAPIMSG _pdata fs_msg;
extern u8 play_status;

extern volatile u8 play_mode;
extern volatile u8 eq_mode;

#ifdef RADIO_AM_WM_ENABLE
extern bool radio_mode;
#endif

extern xd_u8 all_channl;                              ///< FM收音当前搜索到的台总数

extern u16 cfilenum;
extern volatile u8 device_active;
//extern _code u8 _code * chars_table_l; 
extern _xdata SYS_WORK_MODE work_mode;

extern  xd_u16 frequency;
extern xd_u8 fre_channl;
extern xd_u8 fre_point[];
extern MAD_DECODE_INFO _pdata mad_decode_dsc;

xd_u16 lcd_buff[5];

u8 _code playmodestr[4][7] = 
{
	{"ALL"},
	{"FOD"},
	{"ONE"},
	{"RAN"}
};

u8 _code letter_tab[] = 
{
    0x77,0x40,0x40,0x5E,0x79,///<ABCDE
    0x71,0x40,0x76,0x06,0x40,///<FGHIJ
    0x40,0x38,0x40,0x37,0x3F,///<KLMNO
    0x73,0x40,0x50,0x6d,0x40,///<PQRST
    0x3e,0x3e,0x40,0x76,0x40,///<UVWXY
    0x40,///<Z

    0x77,0x40,0x40,0x5E,0x79,///<abcde
    0x71,0x40,0x40,0x30,0x40,///<fghij
    0x40,0x38,0x40,0x54,0x3F,///<klmno
    0x73,0x40,0x50,0x40,0x40,///<pqrst
    0x3e,0x3e,0x40,0x76,0x40,///<uvwxy
    0x40///<z
};
u8 _code figure_tab[] = 
{
    0x3f,0x06,0x5b,0x4f,0x66,  ///<0~4
    0x6d,0x7d,0x07,0x7f,0x6f   ///<5~9
};

#define 	DIG_A	0x01
#define 	DIG_B	0x02
#define 	DIG_C	0x04
#define 	DIG_D	0x08
#define 	DIG_E	0x10
#define 	DIG_F	0x20
#define 	DIG_G	0x40
#define 	DIG_H	0x80
#if defined(K000_XingChuang_x821_V001)
u8 get_lcd_disbuf_offset(u8 lcd_digit)
{
	switch(lcd_digit)
	{
		case 0:return 0;
		case 1:return 2;
		case 2:return 4;
		case 3:return 6;		
	}
	return 0xFF;
}
#elif defined(K820_LHD_820_V001)
u8 get_lcd_disbuf_offset(u8 lcd_digit)
{
	switch(lcd_digit)
	{
		case 0:return 5;
		case 1:return 3;
		case 2:return 1;
		case 3:return 0;		
	}
	return 0xFF;
}
#elif defined(K2038_DCX_2038_V001)	   
u8 get_lcd_disbuf_offset(u8 lcd_digit)
{
	switch(lcd_digit)
	{
		case 0:return 4;
		case 1:return 3;
		case 2:return 2;
		case 3:return 1;		
		//case 4:return 4;		
	}
	return 0xFF;
}
#elif defined(K1150_LS_1150_V001)

u8 _code get_lcd_disbuf_offset[4] ={6,4,2,0};

#elif defined(K5018_JK_5018_V001)

u8 _code get_lcd_disbuf_offset[4] ={6,4,2,0};

#elif defined(K2045_AJR_2045_V001)

u8 _code get_lcd_disbuf_offset[4] ={6,4,2,0};

#elif defined(K2083_KPL_2083_V003)||defined(K2083_SW_2083_V002)

u8 _code get_lcd_disbuf_offset[4] ={6,4,2,0};

#else
u8 get_lcd_disbuf_offset(u8 lcd_digit)
{
	switch(lcd_digit)
	{
		case 0:return 7;
		case 1:return 5;
		case 2:return 3;
		case 3:return 0;		
	}
	return 0xFF;
}
#endif

/*----------------------------------------------------------------------------*/
/**@brief
   @param  
   @return
   @note 
*/
/*----------------------------------------------------------------------------*/
u8 dispchar(u8 chardata,u8 offset)
{
    u16  letter_temp;
    u8 digit_idx=0;

#if defined(K000_ZhuoYue_003_V001)||defined(K5018_JK_5018_V001)||defined(K2045_AJR_2045_V001)||defined(K000_KT_AMFM_V001)||defined(K000_XingChuang_x821_V001)||defined(K2038_DCX_2038_V001)


#else	
	//if(offset>2)
	{
	//    return 0;
	}
#endif	
	
    if((chardata>='a')&&(chardata<='z'))
    {
        chardata -= 'a';
        letter_temp = letter_tab[chardata+26];        
    }
    else if((chardata>='A')&&(chardata<='Z'))
    {
        chardata -= 'A';
        letter_temp = letter_tab[chardata];
    }
    else if((chardata>='-'))
    {
        letter_temp -= 'Z';
    }
    else
    {
        return 0;
    }
 
#if defined(K000_ZhuoYue_003_V001)

	offset =3- offset;
	digit_idx= (offset*2);
	
	lcd_buff[0] &= ~(0x0003<<digit_idx);
	lcd_buff[1] &= ~(0x0003<<digit_idx);
	lcd_buff[2] &= ~(0x0003<<digit_idx);
	lcd_buff[3] &= ~(0x0003<<digit_idx);
	   
       lcd_buff[0] |= ((letter_temp & DIG_A)<<1)<<digit_idx;
       lcd_buff[1] |= ((letter_temp & DIG_B)|((letter_temp & DIG_F)>>5))<<digit_idx;
       lcd_buff[2] |= (((letter_temp & DIG_C)>>1)|((letter_temp & DIG_G)>>6))<<digit_idx;
       lcd_buff[3] |= (((letter_temp & DIG_D)>>2)|((letter_temp & DIG_E)>>4))<<digit_idx;
#elif defined(K2083_KPL_2083_V003)||defined(K2083_SW_2083_V002)


	digit_idx= get_lcd_disbuf_offset[offset];

	if(offset == 0){
		
		lcd_buff[0] &= ~(BIT(3)|BIT(5)|BIT(6));
		lcd_buff[1] &= ~(BIT(6));
		lcd_buff[2] &= ~(BIT(6));
		lcd_buff[3] &= ~(BIT(6));
		lcd_buff[4] &= ~(BIT(6));
		
	       lcd_buff[0] |= (((letter_temp & DIG_E)>>1)|((letter_temp & DIG_F))|((letter_temp & DIG_D)<<3));
	       lcd_buff[4] |= ((letter_temp & DIG_A)<<6);
	       lcd_buff[3] |= ((letter_temp & DIG_B)<<5);
	       lcd_buff[2] |= (((letter_temp & DIG_G)));
	       lcd_buff[1] |= (((letter_temp & DIG_C)<<4));

	}
	else{

		lcd_buff[1] &= ~(0x0003<<digit_idx);
		lcd_buff[2] &= ~(0x0003<<digit_idx);
		lcd_buff[3] &= ~(0x0003<<digit_idx);
		lcd_buff[4] &= ~(0x0002<<digit_idx);
		
	       lcd_buff[4] |= ((letter_temp & DIG_A)<<1)<<digit_idx;
	       lcd_buff[3] |= ((letter_temp & DIG_B)|((letter_temp & DIG_F)>>5))<<digit_idx;
	       lcd_buff[2] |= (((letter_temp & DIG_C)>>1)|((letter_temp & DIG_G)>>6))<<digit_idx;
	       lcd_buff[1] |= (((letter_temp & DIG_D)>>2)|((letter_temp & DIG_E)>>4))<<digit_idx;

	}
#elif defined(K1150_LS_1150_V001)


	digit_idx= get_lcd_disbuf_offset[offset];

	lcd_buff[1] &= ~(0x0003<<digit_idx);
	lcd_buff[2] &= ~(0x0003<<digit_idx);
	lcd_buff[3] &= ~(0x0003<<digit_idx);
	lcd_buff[4] &= ~(0x0002<<digit_idx);
	
       lcd_buff[1] |= (((letter_temp & DIG_A)<<1)|((letter_temp & DIG_F)>>5))<<digit_idx;
       lcd_buff[2] |= (((letter_temp & DIG_G)>>6)|((letter_temp & DIG_B)))<<digit_idx;
       lcd_buff[3] |= (((letter_temp & DIG_C)>>1)|((letter_temp & DIG_E)>>4))<<digit_idx;
       lcd_buff[4] |= (((letter_temp & DIG_D)>>2))<<digit_idx;  
#elif defined(K5018_JK_5018_V001)


	digit_idx= get_lcd_disbuf_offset[offset];

	lcd_buff[1] &= ~(0x0002<<digit_idx);
	lcd_buff[2] &= ~(0x0003<<digit_idx);
	lcd_buff[3] &= ~(0x0003<<digit_idx);
	lcd_buff[4] &= ~(0x0003<<digit_idx);

       lcd_buff[1] |= ((letter_temp & DIG_A)<<1)<<digit_idx;
       lcd_buff[2] |= (((letter_temp & DIG_B))|((letter_temp & DIG_F)>>5))<<digit_idx;
       lcd_buff[3] |= (((letter_temp & DIG_C)>>1)|((letter_temp & DIG_G)>>6))<<digit_idx;
       lcd_buff[4] |= (((letter_temp & DIG_D)>>2)|((letter_temp & DIG_E)>>4))<<digit_idx;   	
	   
#elif defined(K2045_AJR_2045_V001)

	digit_idx= get_lcd_disbuf_offset[offset];

	lcd_buff[0] &= ~(0x0003<<digit_idx);
	lcd_buff[1] &= ~(0x0003<<digit_idx);
	lcd_buff[2] &= ~(0x0003<<digit_idx);
	lcd_buff[3] &= ~(0x0002<<digit_idx);
	
       lcd_buff[0] |= (((letter_temp & DIG_A)<<1)|((letter_temp & DIG_F)>>5))<<digit_idx;
       lcd_buff[1] |= (((letter_temp & DIG_G)>>6)|((letter_temp & DIG_B)))<<digit_idx;
       lcd_buff[2] |= (((letter_temp & DIG_C)>>1)|((letter_temp & DIG_E)>>4))<<digit_idx;
       lcd_buff[3] |= (((letter_temp & DIG_D)>>2))<<digit_idx;  	   
#elif defined(K2038_DCX_2038_V001)

	digit_idx= get_lcd_disbuf_offset(offset);
	
	lcd_buff[digit_idx] = 0x00;
       lcd_buff[digit_idx] = (((letter_temp & DIG_A)<<3)|((letter_temp & DIG_B)<<1)|((letter_temp & DIG_D)<<3)|((letter_temp & DIG_C)>>1)|((letter_temp & DIG_E)<<1)|((letter_temp & DIG_F)>>1)|((letter_temp & DIG_G)>>6));

#elif defined(K000_KT_AMFM_V001)

	digit_idx= get_lcd_disbuf_offset(offset);
	
	lcd_buff[0] &= ~(0x0001<<digit_idx);
	lcd_buff[1] &= ~(0x0003<<digit_idx);
	lcd_buff[2] &= ~(0x0003<<digit_idx);
	lcd_buff[3] &= ~(0x0003<<digit_idx);
	   
       lcd_buff[0] |= ((letter_temp & DIG_A))<<digit_idx;
       lcd_buff[1] |= ((letter_temp & DIG_B)|((letter_temp & DIG_F)>>5))<<digit_idx;
       lcd_buff[2] |= (((letter_temp & DIG_E)>>4)|((letter_temp & DIG_G)>>5))<<digit_idx;
       lcd_buff[3] |= (((letter_temp & DIG_D)>>3)|((letter_temp & DIG_C)>>1))<<digit_idx;  
#elif defined(K000_XingChuang_x821_V001)

	digit_idx= get_lcd_disbuf_offset(offset);
	
	lcd_buff[0] &= ~(0x0001<<digit_idx);
	lcd_buff[1] &= ~(0x0003<<digit_idx);
	lcd_buff[2] &= ~(0x0003<<digit_idx);
	lcd_buff[3] &= ~(0x0003<<digit_idx);

       lcd_buff[0] |= ((letter_temp & DIG_A))<<digit_idx;
       lcd_buff[1] |= (((letter_temp & DIG_B)>>1)|((letter_temp & DIG_F)>>4))<<digit_idx;
       lcd_buff[2] |= (((letter_temp & DIG_C)>>2)|((letter_temp & DIG_G)>>5))<<digit_idx;
       lcd_buff[3] |= (((letter_temp & DIG_D)>>3)|((letter_temp & DIG_E)>>3))<<digit_idx;   	   
#elif defined(K820_LHD_820_V001)

	digit_idx= get_lcd_disbuf_offset(offset);
	   
	lcd_buff[0] &= ~(0x0003<<digit_idx);
	lcd_buff[1] &= ~(0x0003<<digit_idx);
	lcd_buff[2] &= ~(0x0003<<digit_idx);
	lcd_buff[3] &= ~(0x0001<<digit_idx);

       lcd_buff[0] |= ((letter_temp & DIG_A)|(letter_temp & DIG_B))<<digit_idx;
       lcd_buff[1] |= (((letter_temp & DIG_G)>>5)|((letter_temp & DIG_F)>>5))<<digit_idx;
       lcd_buff[2] |= (((letter_temp & DIG_C)>>1)|((letter_temp & DIG_E)>>4))<<digit_idx;
       lcd_buff[3] |= (((letter_temp & DIG_D)>>3)|((letter_temp & DIG_H)>>7))<<digit_idx;   	 	   
#else

	offset =3- offset;
	digit_idx= (offset*2)-1;
	
	lcd_buff[0] &= ~(0x0003<<digit_idx);
	lcd_buff[1] &= ~(0x0003<<digit_idx);
	lcd_buff[2] &= ~(0x0003<<digit_idx);
	lcd_buff[3] &= ~(0x0003<<digit_idx);
	   
       lcd_buff[0] |= (letter_temp & 0x03)<<digit_idx;
       lcd_buff[1] |= ((letter_temp & 0x60)>>5)<<digit_idx;
       lcd_buff[2] |= (((letter_temp & 0x10)>>4)|((letter_temp & 0x04)>>1))<<digit_idx;
       lcd_buff[3] |= (((letter_temp & 0x08)>>3)|((letter_temp & 0x80)>>7))<<digit_idx;
#endif	   

	return 1;
}
/*----------------------------------------------------------------------------*/
/**@brief
   @param  
   @return
   @note 
*/
/*----------------------------------------------------------------------------*/
void dispstring(u8 *str,u8 offset0)
{
#if defined(K000_ZhuoYue_003_V001)||defined(K5018_JK_5018_V001)||defined(K000_KT_AMFM_V001)||defined(K000_XingChuang_x821_V001)||defined(K2038_DCX_2038_V001)|| defined(K2083_KPL_2083_V003)||defined(K2083_SW_2083_V002)
    u8 cnt = 3;
#else
    u8 cnt = 2;
#endif
	str = str+offset0;	
	do
	{
	    dispchar(*str,cnt);
		str++;
		
	}while((0 != *str) && cnt--);
}
/*----------------------------------------------------------------------------*/
/**@brief
   @param  
   @return
   @note 
*/
/*----------------------------------------------------------------------------*/
u8 dispNum(u8 chardata,u8 cnt)
{
    u8  letter_temp;
    u8 digit_idx=0;

	letter_temp = figure_tab[chardata];

#if defined(K000_ZhuoYue_003_V001)	
	
	cnt =3- cnt;
	digit_idx= (cnt*2);

	lcd_buff[0] &= ~(0x0003<<digit_idx);
	lcd_buff[1] &= ~(0x0003<<digit_idx);
	lcd_buff[2] &= ~(0x0003<<digit_idx);
	lcd_buff[3] &= ~(0x0003<<digit_idx);

       lcd_buff[0] |= ((letter_temp & DIG_A)<<1)<<digit_idx;
       lcd_buff[1] |= ((letter_temp & DIG_B)|((letter_temp & DIG_F)>>5))<<digit_idx;
       lcd_buff[2] |= (((letter_temp & DIG_C)>>1)|((letter_temp & DIG_G)>>6))<<digit_idx;
       lcd_buff[3] |= (((letter_temp & DIG_D)>>2)|((letter_temp & DIG_E)>>4))<<digit_idx;
#elif defined(K2083_KPL_2083_V003)||defined(K2083_SW_2083_V002)

	digit_idx= get_lcd_disbuf_offset[cnt];

	if(cnt == 0){
		
		lcd_buff[0] &= ~(BIT(3)|BIT(5)|BIT(6));
		lcd_buff[1] &= ~(BIT(6));
		lcd_buff[2] &= ~(BIT(6));
		lcd_buff[3] &= ~(BIT(6));
		lcd_buff[4] &= ~(BIT(6));
		
	       lcd_buff[0] |= (((letter_temp & DIG_E)>>1)|((letter_temp & DIG_F))|((letter_temp & DIG_D)<<3));
	       lcd_buff[4] |= ((letter_temp & DIG_A)<<6);
	       lcd_buff[3] |= ((letter_temp & DIG_B)<<5);
	       lcd_buff[2] |= ((letter_temp & DIG_G));
	       lcd_buff[1] |= (((letter_temp & DIG_C)<<4));

	}
	else{
		
		lcd_buff[1] &= ~(0x0003<<digit_idx);
		lcd_buff[2] &= ~(0x0003<<digit_idx);
		lcd_buff[3] &= ~(0x0003<<digit_idx);
		lcd_buff[4] &= ~(0x0002<<digit_idx);
		
	       lcd_buff[4] |= ((letter_temp & DIG_A)<<1)<<digit_idx;
	       lcd_buff[3] |= ((letter_temp & DIG_B)|((letter_temp & DIG_F)>>5))<<digit_idx;
	       lcd_buff[2] |= (((letter_temp & DIG_C)>>1)|((letter_temp & DIG_G)>>6))<<digit_idx;
	       lcd_buff[1] |= (((letter_temp & DIG_D)>>2)|((letter_temp & DIG_E)>>4))<<digit_idx;	   
	}
#elif defined(K1150_LS_1150_V001)


	digit_idx= get_lcd_disbuf_offset[cnt];

	lcd_buff[1] &= ~(0x0003<<digit_idx);
	lcd_buff[2] &= ~(0x0003<<digit_idx);
	lcd_buff[3] &= ~(0x0003<<digit_idx);
	lcd_buff[4] &= ~(0x0002<<digit_idx);
	
       lcd_buff[1] |= (((letter_temp & DIG_A)<<1)|((letter_temp & DIG_F)>>5))<<digit_idx;
       lcd_buff[2] |= (((letter_temp & DIG_G)>>6)|((letter_temp & DIG_B)))<<digit_idx;
       lcd_buff[3] |= (((letter_temp & DIG_C)>>1)|((letter_temp & DIG_E)>>4))<<digit_idx;
       lcd_buff[4] |= (((letter_temp & DIG_D)>>2))<<digit_idx;  	
#elif defined(K5018_JK_5018_V001)


	digit_idx= get_lcd_disbuf_offset[cnt];

	lcd_buff[1] &= ~(0x0002<<digit_idx);
	lcd_buff[2] &= ~(0x0003<<digit_idx);
	lcd_buff[3] &= ~(0x0003<<digit_idx);
	lcd_buff[4] &= ~(0x0003<<digit_idx);

       lcd_buff[1] |= ((letter_temp & DIG_A)<<1)<<digit_idx;
       lcd_buff[2] |= (((letter_temp & DIG_B))|((letter_temp & DIG_F)>>5))<<digit_idx;
       lcd_buff[3] |= (((letter_temp & DIG_C)>>1)|((letter_temp & DIG_G)>>6))<<digit_idx;
       lcd_buff[4] |= (((letter_temp & DIG_D)>>2)|((letter_temp & DIG_E)>>4))<<digit_idx;   	
	   
#elif defined(K2045_AJR_2045_V001)


	digit_idx= get_lcd_disbuf_offset[cnt];

	lcd_buff[0] &= ~(0x0003<<digit_idx);
	lcd_buff[1] &= ~(0x0003<<digit_idx);
	lcd_buff[2] &= ~(0x0003<<digit_idx);
	lcd_buff[3] &= ~(0x0002<<digit_idx);
	
       lcd_buff[0] |= (((letter_temp & DIG_A)<<1)|((letter_temp & DIG_F)>>5))<<digit_idx;
       lcd_buff[1] |= (((letter_temp & DIG_G)>>6)|((letter_temp & DIG_B)))<<digit_idx;
       lcd_buff[2] |= (((letter_temp & DIG_C)>>1)|((letter_temp & DIG_E)>>4))<<digit_idx;
       lcd_buff[3] |= (((letter_temp & DIG_D)>>2))<<digit_idx;  
	   
#elif defined(K2038_DCX_2038_V001)	   

	digit_idx= get_lcd_disbuf_offset(cnt);
	
	lcd_buff[digit_idx] =0X0000;
       lcd_buff[digit_idx] = (((letter_temp & DIG_A)<<3)|((letter_temp & DIG_B)<<1)|((letter_temp & DIG_D)<<3)|((letter_temp & DIG_C)>>1)|((letter_temp & DIG_E)<<1)|((letter_temp & DIG_F)>>1)|((letter_temp & DIG_G)>>6));
	   
#elif defined(K000_KT_AMFM_V001)

	digit_idx= get_lcd_disbuf_offset(cnt);

	lcd_buff[0] &= ~(0x0001<<digit_idx);
	lcd_buff[1] &= ~(0x0003<<digit_idx);
	lcd_buff[2] &= ~(0x0003<<digit_idx);
	lcd_buff[3] &= ~(0x0003<<digit_idx);

       lcd_buff[0] |= ((letter_temp & DIG_A))<<digit_idx;
       lcd_buff[1] |= ((letter_temp & DIG_B)|((letter_temp & DIG_F)>>5))<<digit_idx;
       lcd_buff[2] |= (((letter_temp & DIG_E)>>4)|((letter_temp & DIG_G)>>5))<<digit_idx;
       lcd_buff[3] |= (((letter_temp & DIG_D)>>3)|((letter_temp & DIG_C)>>1))<<digit_idx;
#elif defined(K000_XingChuang_x821_V001)

	digit_idx= get_lcd_disbuf_offset(cnt);

	lcd_buff[0] &= ~(0x0001<<digit_idx);
	lcd_buff[1] &= ~(0x0003<<digit_idx);
	lcd_buff[2] &= ~(0x0003<<digit_idx);
	lcd_buff[3] &= ~(0x0003<<digit_idx);

       lcd_buff[0] |= ((letter_temp & DIG_A))<<digit_idx;
       lcd_buff[1] |= (((letter_temp & DIG_B)>>1)|((letter_temp & DIG_F)>>4))<<digit_idx;
       lcd_buff[2] |= (((letter_temp & DIG_C)>>2)|((letter_temp & DIG_G)>>5))<<digit_idx;
       lcd_buff[3] |= (((letter_temp & DIG_D)>>3)|((letter_temp & DIG_E)>>3))<<digit_idx;   	   
#elif defined(K820_LHD_820_V001)
	if(cnt == 3)
	{
	    if(chardata == 1)
	    {
            	F_NUM_1BC |= NUM_1BC_MASK;
	    }
	    else
	    {
            	F_NUM_1BC &= ~NUM_1BC_MASK;
	    }
	    return 1;
	}

	digit_idx= get_lcd_disbuf_offset(cnt);

	
	lcd_buff[0] &= ~(0x0003<<digit_idx);
	lcd_buff[1] &= ~(0x0003<<digit_idx);
	lcd_buff[2] &= ~(0x0003<<digit_idx);
	lcd_buff[3] &= ~(0x0001<<digit_idx);

       lcd_buff[0] |= ((letter_temp & DIG_A)|((letter_temp & DIG_B)))<<digit_idx;
       lcd_buff[1] |= (((letter_temp & DIG_G)>>5)|((letter_temp & DIG_F)>>5))<<digit_idx;
       lcd_buff[2] |= (((letter_temp & DIG_C)>>1)|((letter_temp & DIG_E)>>4))<<digit_idx;
       lcd_buff[3] |= (((letter_temp & DIG_D)>>3)|((letter_temp & DIG_H)>>7))<<digit_idx;   	 
#else
	if(cnt == 3)
	{
	    if(chardata == 1)
	    {
            	lcd_buff[0] |= 0x01;
	    }
	    else
	    {
            	lcd_buff[0] &= ~0x01;
	    }
	    return 1;
	}

	cnt =3- cnt;
	digit_idx= (cnt*2)-1;
	
	lcd_buff[0] &= ~(0x0003<<digit_idx);
	lcd_buff[1] &= ~(0x0003<<digit_idx);
	lcd_buff[2] &= ~(0x0003<<digit_idx);
	lcd_buff[3] &= ~(0x0003<<digit_idx);
	   
       lcd_buff[0] |= (letter_temp & 0x03)<<digit_idx;
       lcd_buff[1] |= ((letter_temp & 0x60)>>5)<<digit_idx;
       lcd_buff[2] |= (((letter_temp & 0x10)>>4)|((letter_temp & 0x04)>>1))<<digit_idx;
       lcd_buff[3] |= (((letter_temp & 0x08)>>3)|((letter_temp & 0x80)>>7))<<digit_idx;
#endif
#if 0
	printf("--00--dispNum >%x \r\n",(u16) lcd_buff[0]);
	printf("--11--dispNum >%x \r\n",(u16) lcd_buff[1]);
	printf("--22--dispNum >%x \r\n",(u16) lcd_buff[2]);
	printf("--33--dispNum >%x \r\n",(u16) lcd_buff[3]);
#endif
	
	return 1;	
}
void dispnull(void)
{
}
void Disp_Null(void)
{
    dispstring("-No",0);
}
void disp_active(void)
{
	if(device_active == BIT(SDMMC))
	{
		 F_USB_DEV &=~ USB_DEV_MASK;
		 F_SD_DEV  |= SD_DEV_MASK;
	}
	else if(device_active == BIT(USB_DISK))
	{
		 F_SD_DEV  &= ~SD_DEV_MASK;
		 F_USB_DEV |=USB_DEV_MASK;		 
	}

	F_FM_DEV  &= ~FM_DEV_MASK;

}
void Disp_Num(void)
{
	dispNum((u8)((cfilenum/1000)%10),3);
	dispNum((u8)((cfilenum/100)%10),2);
	dispNum((u8)((cfilenum/10)%10),1);
	dispNum(cfilenum%10,0);
}
void Disp_Filenum(void)
{
	disp_active();
	dispNum((u8)((fs_msg.fileNumber/1000)%10),3);
	dispNum((u8)((fs_msg.fileNumber/100)%10),2);
	dispNum((u8)((fs_msg.fileNumber/10)%10),1);
	dispNum(fs_msg.fileNumber%10,0);
}
void Disp_Freq(void )
{
	if(frequency > 999)
	{
		dispNum((u8)((frequency/1000)%10),3);	
	}

	dispNum((u8)((frequency/100)%10),2);
	dispNum((u8)((frequency/10)%10),1);
	dispNum(frequency%10,0);
#ifdef RADIO_AM_WM_ENABLE
	if(radio_mode){

	F_FM_DEV  |= FM_DEV_MASK;
#if defined(K000_KT_AMFM_V001)||defined(K5018_JK_5018_V001)
	F_MHZ_DEV |=FM_MHZ_MASK;
	F_P1_DEV |=FM_P1_MASK;
#endif

	}
	else{

#if defined(K5018_JK_5018_V001)
	F_KHZ_DEV |=AM_KHZ_MASK;
	F_AM_DEV|= AM_DEV_MASK;
#else
	F_KHZ_DEV |=AM_KHZ_MASK;
	SPK_ICON|=SPK_MUTE_MASK;
#endif	
	}
		
#else	
	F_FM_DEV  |= FM_DEV_MASK;
#if defined(K000_KT_AMFM_V001)
	F_MHZ_DEV |=FM_MHZ_MASK;
	F_P1_DEV |=FM_P1_MASK;
#elif defined(K1150_LS_1150_V001)
	F_P1_DEV |=FM_P1_MASK;
	F_FM_DEV  |= FM_DEV_MASK;
	
#endif
#endif

#if defined(FM_PLAY_KEY_PAUSE)    
#if defined(DISP_PAUS_STRING)
      if (play_status==0){
    		dispstring("PAUS",0);

      }
#elif defined(DISP_PAU_STRING_ONLY_IN_FM_MODE)
      if (play_status==0){
    		dispstring("PAU",0);
#ifndef DISP_FM_STR_WHEN_PAUS			
		LED_STATUS &=~LED_FM;
      	}
#endif	  
#endif
#endif
	
}
/*----------------------------------------------------------------------------*/
/**@brief
   @param  
   @return
   @note 
*/
/*----------------------------------------------------------------------------*/
void Disp_Nofile(void)
{
	dispnull();
}
/*----------------------------------------------------------------------------*/
/**@brief
   @param  
   @return
   @note 
*/
/*----------------------------------------------------------------------------*/
void Disp_Waiting(void)
{
	dispnull();
}
/*----------------------------------------------------------------------------*/
/**@brief
   @param  
   @return
   @note 
*/
/*----------------------------------------------------------------------------*/
void Disp_Nodevice(void)
{
    dispnull();
}
/*----------------------------------------------------------------------------*/
/**@brief
   @param  
   @return
   @note 
*/
/*----------------------------------------------------------------------------*/
void Disp_Vol(void)
{
#ifdef DISP_VOL_V_CHAR
	dispchar('V',2);
#endif
	dispNum((my_music_vol/10),1);
	dispNum(my_music_vol%10,0);
}
void Disp_mode_icon(void)
{
       if(play_mode == REPEAT_ONE){
		F_REP_ONE|= REP_ONE_MASK;
	}
	else if(play_mode == 0){
		F_REP_ALL|= REP_ALL_MASK;
	}
#if defined(K1150_LS_1150_V001)
	else if(play_mode == REPEAT_RANDOM){
		F_REP_RND|= REP_RND_MASK;
	}
#endif		
	else{
#if defined(K1150_LS_1150_V001)
		F_REP_RND &= ~REP_RND_MASK;
#endif		
		F_REP_ONE &= ~REP_ONE_MASK;
		F_REP_ALL  &= ~REP_ALL_MASK;
	}

	//F_FM_DEV  &= ~FM_DEV_MASK;
	
}
void Disp_Playmode(void)
{
#if defined( K820_LHD_820_V001)
	disp_file_time();
#else
	dispstring(&playmodestr[play_mode][0],0);
	Disp_mode_icon();
#endif
}
/*----------------------------------------------------------------------------*/
/**@brief
   @param  
   @return
   @note 
*/
/*----------------------------------------------------------------------------*/
void disp_file_time(void)
{
	
	u16 sec;		
	u16 min;
 	u32 file_play_time;
	
	file_play_time = get_music_play_time();
	sec = file_play_time % 60;
	min = (file_play_time/60) % 60;

	dispNum((u8)((min/10)%10),3);
	dispNum(min%10,2);
	dispNum((u8)((sec/10)%10),1);
	dispNum(sec%10,0);
	
	F_POINTS |= POINTS_MASK;

#if defined(K820_LHD_820_V001)||defined(K1150_LS_1150_V001)
	Disp_mode_icon();
#endif
}
void Disp_Pause(void)
{
    disp_active();

#if defined(K1150_LS_1150_V001)
    F_PAU_ICON |=PAU_ICON_MASK;
    dispstring("PAUS",0);
#elif defined(DISP_PAUS_STRING)	
    dispstring("PAUS",0);
#else	
    dispstring("PAU",0);
#endif
}

void Disp_Play(void)
{
    disp_active();
    disp_file_time();
#if defined(K2038_DCX_2038_V001)
    F_MP3_FAT |=MP3_FAT_MASK;
#elif defined(K1150_LS_1150_V001)
    F_MP3_FAT |=MP3_FAT_MASK;
    F_PLAY_ICON |=PLAY_ICON_MASK;
#endif
}
void Disp_File_Name(void)
{

}
void Disp_Stop()
{
    dispstring("Stop",0);

}
#if defined(IPONE_DOCK_FUNC_ENABLE)
void Disp_IPOD(void)
{
    dispstring("IPOD",0);
}
#endif

/*----------------------------------------------------------------------------*/
/**@brief
   @param  
   @return
   @note 
*/
/*----------------------------------------------------------------------------*/

void Disp_Eq(void)
{
	dispchar('E',2);
	dispNum(eq_mode,1);

}
void Disp_USB_Slave(void)
{
	dispstring("Usb",0);
}
void Disp_AUX(void)
{


    F_AUX_DEV  |= AUX_DEV_MASK;
#if defined(K5018_JK_5018_V001)|| defined(K2083_KPL_2083_V003)
    dispstring(" AUX",0);
#else
    dispstring("AUX",0);
#endif


#if defined(LINE_IN_PLAY_KEY_PAUSE)

#if defined(DISP_PAUS_STRING)
#ifndef LINE_IN_NO_DISP_PAUS
	if(play_status == MUSIC_PAUSE){
	    	dispstring("PAUS",0);
	}
#endif	
#else
#if !defined(LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR)
	if(play_status){
		LED_STATUS &= ~LED_PAUSE;
		LED_STATUS |= LED_PLAY;
	}
	else{
		LED_STATUS |= LED_PAUSE;
		LED_STATUS &= ~LED_PLAY;
	}
#endif
#endif
#endif

}
void Disp_Error(void)
{
       dispstring("err",0);
}

void Disp_Start(void)
{
#if defined(K820_LHD_820_V001)
      // dispstring("HI",0);
#elif defined(K1150_LS_1150_V001)||defined(K2083_SW_2083_V002)
       dispstring("HI",0);
#else
       dispstring(" HI",0);
#endif
}
void Disp_PwrOFF(void)
{

}
/*----------------------------------------------------------------------------*/
/**@brief
   @param  
   @return
   @note 
*/
/*----------------------------------------------------------------------------*/
void Disp_Power_up(void)
{
      lcd_buff[0] = 0x0000;	  /* 千位 */	
      lcd_buff[1] = 0x0000;	  /* 百位 */
      lcd_buff[2] = 0x0000;	  /* 十位 */
      lcd_buff[3] = 0x0000;	  /* 十位 */
      lcd_buff[4] = 0x0000;	  /* 十位 */
}
void Disp_CH_NO(void )
{

    dispchar('P',2);
    dispNum((u8)((fre_channl/10)%10),1);
    dispNum(fre_channl%10,0);

}
void Disp_Scan_NO(void )
{

    dispchar('P',2);
    dispNum((u8)((all_channl/10)%10),1);
    dispNum(all_channl%10,0);

}
void Disp_Dev_Change(u8 flag)
{
    if(2 == flag)
	{
		dispstring("USB OUT",0);
	}
	else if(1 == flag)
	{
		dispstring("SD OUT",0);
	}

}
#if(RTC_ENABLE)
#include "rtc_mode.h"
extern _xdata RTC_TIME curr_date;
extern _xdata ALM_TIME curr_alm;

extern _xdata u8 rtc_set;
extern _xdata u8 alm_set;
extern _xdata u8 rtc_mode;
extern bool alm_sw;
void oppo_area_rtc(u8 setting)
{
	static bit led_flash = 0;
	if(led_flash){
		led_flash =0;
		return;
	}
	//printf("oppo_area_rtc %x \r\n",(u16)setting);
	led_flash =1;
	switch(setting)
	{
		case 0:
			lcd_buff[0]&=~(0x00F0);
			lcd_buff[1]&=~(0x00F0);			
			lcd_buff[2]&=~(0x00F0);
			lcd_buff[3]&=~(0x00F0);	
			break;
		case 1:
#ifdef K000_ZhuoYue_003_V001
			lcd_buff[0]&=~(0x000A);
			lcd_buff[1]&=~(0x000F);			
			lcd_buff[2]&=~(0x000F);
			lcd_buff[3]&=~(0x000F);
#elif defined(K2083_KPL_2083_V003)	
			lcd_buff[4]&=~(0x000F);
			lcd_buff[1]&=~(0x000F);			
			lcd_buff[2]&=~(0x000F);
			lcd_buff[3]&=~(0x000F);			
#elif defined(K5018_JK_5018_V001)
			lcd_buff[4]&=~(0x000F);
			lcd_buff[1]&=~(0x000A);			
			lcd_buff[2]&=~(0x000F);
			lcd_buff[3]&=~(0x000F);
#else				
			lcd_buff[0]&=~(0x003);
			lcd_buff[1]&=~(0x003);			
			lcd_buff[2]&=~(0x003);
			lcd_buff[3]&=~(0x003);	
#endif			
			break;		
		case 2:
#ifdef K000_ZhuoYue_003_V001
			lcd_buff[0]&=~(0x00A0);
			lcd_buff[1]&=~(0x00F0);			
			lcd_buff[2]&=~(0x00F0);
			lcd_buff[3]&=~(0x00F0);
#elif defined(K2083_KPL_2083_V003)	
			lcd_buff[0]&=~(0x0068);
			lcd_buff[4]&=~(0x00F0);
			lcd_buff[1]&=~(0x00F0);			
			lcd_buff[2]&=~(0x00F0);
			lcd_buff[3]&=~(0x00F0);				
#elif defined(K5018_JK_5018_V001)			
			lcd_buff[4]&=~(0x00F0);
			lcd_buff[1]&=~(0x00A0);			
			lcd_buff[2]&=~(0x00F0);
			lcd_buff[3]&=~(0x00F0);			
#else				
			lcd_buff[0]&=~(0x003<<2);
			lcd_buff[1]&=~(0x003<<2);			
			lcd_buff[2]&=~(0x003<<2);
			lcd_buff[3]&=~(0x003<<2);
#endif			
			break;
		case 3:
#ifdef K000_ZhuoYue_003_V001
			lcd_buff[0]&=~(0x000A);
			lcd_buff[1]&=~(0x000F);			
			lcd_buff[2]&=~(0x000F);
			lcd_buff[3]&=~(0x000F);	
#elif defined(K2083_KPL_2083_V003)	
			//lcd_buff[0]&=~(0x0078);
			lcd_buff[4]&=~(0x000F);
			lcd_buff[1]&=~(0x000f);			
			lcd_buff[2]&=~(0x000F);
			lcd_buff[3]&=~(0x000F);	
#elif defined(K5018_JK_5018_V001)	
			lcd_buff[4]&=~(0x000F);
			lcd_buff[1]&=~(0x000A);			
			lcd_buff[2]&=~(0x000F);
			lcd_buff[3]&=~(0x000F);			
#else			
			lcd_buff[0]&=~(0x0007);
			lcd_buff[1]&=~(0x0007);			
			lcd_buff[2]&=~(0x0007);
			lcd_buff[3]&=~(0x0007);	
#endif			
			break;
		case 4:		
#ifdef K000_ZhuoYue_003_V001
			lcd_buff[0]&=~(0x00A0);
			lcd_buff[1]&=~(0x00F0);			
			lcd_buff[2]&=~(0x00F0);
			lcd_buff[3]&=~(0x00F0);
#elif defined(K2083_KPL_2083_V003)	
			lcd_buff[0]&=~(0x0068);
			lcd_buff[4]&=~(0x00F0);
			lcd_buff[1]&=~(0x00F0);			
			lcd_buff[2]&=~(0x00F0);
			lcd_buff[3]&=~(0x00F0);	
#elif defined(K5018_JK_5018_V001)
			lcd_buff[4]&=~(0x00F0);
			lcd_buff[1]&=~(0x00A0);			
			lcd_buff[2]&=~(0x00F0);
			lcd_buff[3]&=~(0x00F0);			
#else			
			lcd_buff[0]&=~(0x0078);
			lcd_buff[1]&=~(0x0078);			
			lcd_buff[2]&=~(0x0078);
			lcd_buff[3]&=~(0x0078);
#endif			
			break;		
		default:break;			
	}

}
void get_curr_setting_data(u8 setting)
{
	u8  setting_buff_high=0,setting_buff_low=0;
	switch(setting)
	{
		case 0:
			setting_buff_high=curr_date.year/100%100;
			setting_buff_low=curr_date.year%100;
	    		F_POINTS &= ~POINTS_MASK;			
			break;
		case 1:
		case 2:
			if(rtc_mode == ALM_SET_MODE){
				setting_buff_high=curr_alm.hour;
				setting_buff_low =curr_alm.minutes;				
			}				
			else{
				setting_buff_high=curr_date.month;
				setting_buff_low = curr_date.day;
			}			
	    		F_POINTS |= POINTS_MASK;		
			break;
		case 3:
		case 4:
			if(rtc_mode == ALM_SET_MODE){
				setting_buff_high=curr_alm.hour;
				setting_buff_low =curr_alm.minutes;	

			}
			else{
#ifdef AM_PM_RTC_TIME_DISP_MODE	
				
				if(curr_date.hour>12){
					setting_buff_high=curr_date.hour-12;
				}
				else{
					setting_buff_high=curr_date.hour;
				}
				if(setting_buff_high==0){
					setting_buff_high = 12;
				}
#else
				setting_buff_high=curr_date.hour;

#endif
				setting_buff_low =curr_date.minutes;	
			}
	    		F_POINTS |= POINTS_MASK;				
		break;
		case 5:
  				setting_buff_low = curr_date.date;
	    		F_POINTS &= ~POINTS_MASK;					
			break;		
		default:break;			
	}	    

	    dispNum(((setting_buff_high/10)%10),3);
	    dispNum((setting_buff_high%10),2);
		
	    dispNum(((setting_buff_low/10)%10),1);
	    dispNum((setting_buff_low%10),0);

}
/*----------------------------------------------------------------------------*/
/**@brief  RTC设置界面
   @param  无
   @return 无
   @note   void disp_rtc(void)
*/
/*----------------------------------------------------------------------------*/
void Disp_RTC_POINT()
{
    	static bit LED_Point = 0;
		
	if(rtc_mode != RTC_PLAY_MODE)return;
	
	if(LED_Point){
	    LED_Point = 0;			
	F_POINTS |= POINTS_MASK;
	}
	else{
		
	    LED_Point = 1;
  	    F_POINTS &= ~POINTS_MASK;
	}
#ifdef K000_ZhuoYue_003_V001
	F_RTC_ICON |=RTC_ICON_MASK;
#endif
}
void Disp_Show_AMPM()
{
	if(curr_date.hour>=12){
	    F_RTC_PM |= RTC_PM_MASK;
	    F_RTC_AM&= ~RTC_AM_MASK;
	}
	else{
	    F_RTC_AM |= RTC_AM_MASK;
	    F_RTC_PM &= ~RTC_PM_MASK;
	}
}
void Disp_Show_ALM_Flag()
{
	if(alm_sw){
	    F_RTC_ALM|= RTC_ALM_MASK;
	}
	else{
	    F_RTC_ALM&= ~RTC_ALM_MASK;
	}
}
#ifdef USE_RTC_YEAR_FUNCTION
void Disp_RTC_Date()
{
	static _xdata u8 date_show=0;

	if(date_show++>4)date_show=0;
	get_curr_setting_data(date_show);

}
#endif
void Disp_RTC()
{
	u8  setting_buff_high=0;

    if (rtc_mode == RTC_PLAY_MODE)
    {

#ifdef AM_PM_RTC_TIME_DISP_MODE	
    		if(curr_date.hour>12){
			setting_buff_high=curr_date.hour-12;
		}
		else{
			setting_buff_high=curr_date.hour;
	 	}
		if(setting_buff_high==0){
			setting_buff_high = 12;
		}
#else
		setting_buff_high=curr_date.hour;
#endif
	    dispNum((u8)((setting_buff_high/10)%10),3);
	    dispNum(setting_buff_high%10,2);
	    dispNum((u8)((curr_date.minutes/10)%10),1);
	    dispNum(curr_date.minutes%10,0);

    }	
    else if(rtc_mode == RTC_SET_MODE)
    {
	    get_curr_setting_data(rtc_set);
	    oppo_area_rtc(rtc_set);	
	F_POINTS |= POINTS_MASK;

    }
    else if(rtc_mode == ALM_SET_MODE)
    {
    	if(alm_set==0){
			
    	  if (alm_sw)
            dispstring("ON",0);
        else
            dispstring("OFF",0);
    	}
	else{
	    get_curr_setting_data(alm_set);
	    oppo_area_rtc(alm_set);	
	}
    }
	Disp_RTC_POINT();	
	Disp_Show_AMPM();
	Disp_Show_ALM_Flag();
}
void Disp_Alm_Up(void)
{

#if defined(K2083_KPL_2083_V003)||defined(K2083_SW_2083_V002)
	lcd_buff[2]=0x0055;
#else
    dispstring("----",0);
#endif
}
#endif
void Disp_CLR(void)
{
       dispstring("    ",0);
}
#if defined(USE_BAT_MANAGEMENT)
#ifdef CUSTOM_BAT_ICON_DISP
extern u8 bat_level;
void Disp_custom_bat_icon()
{
#ifdef USE_RTC_FUNCTION
	if(work_mode > SYS_RTC)return;
#endif	

	BAT_ICON |=BATTERY_MASK;

	switch(bat_level)
	{
		case 1:
			L1_ICON_BUF |=L1_ICON_MASK;
			break;
		case 2:
			L1_ICON_BUF |=L1_ICON_MASK;
			L2_ICON_BUF |=L2_ICON_MASK;

			break;
		case 3:
			L1_ICON_BUF |=L1_ICON_MASK;
			L2_ICON_BUF |=L2_ICON_MASK;
			L3_ICON_BUF |=L3_ICON_MASK;
			break;
		case 4:
			L1_ICON_BUF |=L1_ICON_MASK;
			L2_ICON_BUF |=L2_ICON_MASK;
			L3_ICON_BUF |=L3_ICON_MASK;
			L4_ICON_BUF |=L4_ICON_MASK;
			break;
		case 0:
			L1_ICON_BUF &=~L1_ICON_MASK;
			L2_ICON_BUF &=~L2_ICON_MASK;
			L3_ICON_BUF &=~L3_ICON_MASK;
			L4_ICON_BUF &=~L4_ICON_MASK;
			break;	
	}	
}
#endif
#endif
#if defined(USE_SPECTRUM_PARTTERN)
xd_u8 patern_idx=0;
extern bool get_lcd_flash_lock(void);
void Disp_Patern()
{
#ifdef USE_RTC_FUNCTION
	if(work_mode > SYS_RTC)return;
#endif	
	if(patern_idx++>4)patern_idx =0;
	if(get_lcd_flash_lock())patern_idx = 4;
	switch(patern_idx)
	{
		case 0:
			L_ICON_BUF |=L1_ICON_MASK;
			break;
		case 1:
			L_ICON_BUF |=L1_ICON_MASK;
			L_ICON_BUF |=L2_ICON_MASK;

			break;
		case 2:
			L_ICON_BUF |=L1_ICON_MASK;
			L_ICON_BUF |=L2_ICON_MASK;
			L_ICON_BUF |=L3_ICON_MASK;
			break;
		case 3:
			L_ICON_BUF |=L1_ICON_MASK;
			L_ICON_BUF |=L2_ICON_MASK;
			L_ICON_BUF |=L3_ICON_MASK;
			L_ICON_BUF |=L4_ICON_MASK;
			break;
		case 4:
			L_ICON_BUF &=~L1_ICON_MASK;
			L_ICON_BUF &=~L2_ICON_MASK;
			L_ICON_BUF &=~L3_ICON_MASK;
			L_ICON_BUF &=~L4_ICON_MASK;
			break;	
	}	
}
#endif
void lcd_buf_icon_disp_update()
{
#if(RTC_ENABLE)
    	  if (alm_sw){

		F_RTC_ALM |= RTC_ALM_MASK;
	}
	else{

		F_RTC_ALM &= ~RTC_ALM_MASK;
	}
#endif
}
#if 0//defined(SPECTRUM_FUNC_ENABLE)
void clear_spectrum_buf(void)
{
#if defined(K000_KT_AMFM_V001)
	L1_ICON_BUF &=~L1_ICON_MASK;
	L2_ICON_BUF &=~L2_ICON_MASK;
	L3_ICON_BUF &=~L3_ICON_MASK;
	L4_ICON_BUF &=~L4_ICON_MASK;
#else
	L_ICON_BUF &=~L1_ICON_MASK;
	L_ICON_BUF &=~L2_ICON_MASK;
	L_ICON_BUF &=~L3_ICON_MASK;
	L_ICON_BUF &=~L4_ICON_MASK;
#endif	
}
u8 get_spect_limit(u8 spect_energy)
{
     	//printf("get_spect_limit  %d, \r\n",(u16)spect_energy);

	if(spect_energy>30){
		return 4;
	}
	else if(spect_energy>22){
		return 3;
	}
	else if(spect_energy>16){
		return 2;
	}
	else if(spect_energy>12){
		return 2;
	}
	else{
		return 1;
	}
}
void update_spect_buffer(u8 spect_limit)
{
#if defined(K000_KT_AMFM_V001)
	switch(spect_limit)
	{
		case 1:
			L1_ICON_BUF |=L1_ICON_MASK;
			break;
		case 2:
			L1_ICON_BUF |=L1_ICON_MASK;
			L2_ICON_BUF |=L2_ICON_MASK;

			break;
		case 3:
			L1_ICON_BUF |=L1_ICON_MASK;
			L2_ICON_BUF |=L2_ICON_MASK;
			L3_ICON_BUF |=L3_ICON_MASK;
			break;
		case 4:
			L1_ICON_BUF |=L1_ICON_MASK;
			L2_ICON_BUF |=L2_ICON_MASK;
			L3_ICON_BUF |=L3_ICON_MASK;
			L4_ICON_BUF |=L4_ICON_MASK;
			break;
	}	
#else
	switch(spect_limit)
	{
		case 1:
			L_ICON_BUF |=L1_ICON_MASK;
			break;
		case 2:
			L_ICON_BUF |=L1_ICON_MASK;
			L_ICON_BUF |=L2_ICON_MASK;

			break;
		case 3:
			L_ICON_BUF |=L1_ICON_MASK;
			L_ICON_BUF |=L2_ICON_MASK;
			L_ICON_BUF |=L3_ICON_MASK;
			break;
		case 4:
			L_ICON_BUF |=L1_ICON_MASK;
			L_ICON_BUF |=L2_ICON_MASK;
			L_ICON_BUF |=L3_ICON_MASK;
			L_ICON_BUF |=L4_ICON_MASK;
			break;
	}	
#endif	
}
void spectrum_pattern(u16 *spect_buf)
{
	u8 i;
       u16 spect_line=0;

	clear_spectrum_buf();
	
	spect_line = (spect_buf[7]+spect_buf[5]+spect_buf[2])/3;
		//printf("__----spectrum_pattern  %d, \r\n",spect_line);
	update_spect_buffer(get_spect_limit(spect_line));
		
}

#endif

#if 0
/*----------------------------------------------------------------------------*/
/**@brief
   @param
   @return
   @note
*/
/*----------------------------------------------------------------------------*/
void Disp_Con(u8 LCDinterf)
{
	///*
	return_cnt = 0;
	curr_menu = LCDinterf;

       if(DISP_NULL == LCDinterf)
	{
	    return;
	}  
	disp_clear();

	//printf("----->Disp ON %x \r\n",(u16)LCDinterf);
	
	switch(LCDinterf)
	{
	case DISP_NULL:
		Disp_null();
	    	break;
	case DISP_DWORD_NUMBER:
	     	Disp_Num();
	 	break;
	case DISP_FILENUM:					   
	    	Disp_Filenum();
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
	    	Disp_Playmode();   
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
    	case DISP_CH_NO:
	  	Disp_CH_NO();		
		break;
    	case DISP_SCAN_NO:
	 	Disp_Scan_NO();		
		break;	
	case DISP_USBOUT:
	    	disp_devchange(2);
		break;
	case DISP_SDOUT:
		disp_devchange(1);
	    	break;	  
    	case DISP_AUX:
        	Disp_AUX();
     	 	break;		
    	case DISP_START:
	 	Disp_Start();
	 	break;
    	case DISP_PWR_OFF:
	 	Disp_PwrOFF();
		break;
#if RTC_ENABLE
	case DISP_RTC_POINT:
        	Disp_RTC_POINT();
        	Disp_RTC();		
		break;
#ifdef USE_RTC_YEAR_FUNCTION	
    	case DISP_RTC_DATE:
        	Disp_RTC_Date();
        	break;
#endif
    	case DISP_RTC:
        	Disp_RTC();
        	break;		
    	case DISP_RTC_PWD:
        	break;
    	case DISP_ALM_UP:
        	Disp_Alm_Up();
        	break;
#endif	 
    	default:break;
    }
	updateLcd();
}
#endif
#endif

