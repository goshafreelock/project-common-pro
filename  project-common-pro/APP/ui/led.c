/*--------------------------------------------------------------------------*/
/**@file    led.c
   @brief   4位LED驱动
   @details
   @author
   @date   2010-12-13
   @note
*/
/*----------------------------------------------------------------------------*/

#include "config.h"
#include "lcd.h"
#include "disp.h"
#include "led.h"

#if defined( LED_GPIO_DRV)||defined( LED_DRVER_USE_SM1628)
_xdata u8 LED_BUFF[5];   ///<LED显存
#if defined(K619_FXK_619_V001)
bool config_led_by_gpio=0;
#endif
void disp_buf_figure_buf()
{
    LED_BUFF[0] = 0;	  /* 千位 */
    LED_BUFF[1] = 0;	  /* 百位 */
    LED_BUFF[2] = 0;	  /* 十位 */
    LED_BUFF[3] = 0;	  /* 个位 */
    LED_STATUS &= ~LED_2POINT;
}
void disp_buf_clear(void)
{
    LED_BUFF[0] = 0;	  /* 千位 */
    LED_BUFF[1] = 0;	  /* 百位 */
    LED_BUFF[2] = 0;	  /* 十位 */
    LED_BUFF[3] = 0;	  /* 个位 */
    LED_BUFF[4] = 0;	  /* 状态位 */
}

void init_disp(void)
{
    disp_buf_clear();
    led_com_out();
    led_seg_out();
#if defined(EXTENED_LED_NUM_SCAN)
    DACCON0|=0x80;
    P2DIR &= ~((BIT(6))|(BIT(7)));
    P2PU |= ((BIT(6))|(BIT(7)));	
#endif	
}

#define 	SEG_A	0x01
#define 	SEG_B	0x02
#define 	SEG_C	0x04
#define 	SEG_D	0x08
#define 	SEG_E	0x10
#define 	SEG_F	0x20
#define 	SEG_G	0x40
#define 	SEG_H	0x80

#define 	COM_1	0x01
#define 	COM_2	0x02
#define 	COM_3	0x04
#define 	COM_4	0x08
#define 	COM_5	0x10
/*----------------------------------------------------------------------------*/
/**@brief    LED扫描函数
   @param
   @return
   @note     void disp_scan(void)
*/
/*----------------------------------------------------------------------------*/
#if defined(EXTENDED_LED_SPECTURM)
static bool spect_pattern_reflesh_en=0;
extern bool spectrum_reflesh_en;
extern u8 get_spect_power(void);

void spect_pattern_disp_reflesh(u8  spec_fresh)
{
#ifdef LED_ROLLING_FUNC	
	static xd_u8 led_rolling_timer=0;
#endif
	u8 spect_pwr=0;

	LED_COM_EXTEND_OFF();
	SPEC_ICON_BUF |=L1_ICON_MASK;
	SPEC_ICON_BUF |=L2_ICON_MASK;
	SPEC_ICON_BUF |=L3_ICON_MASK;
	SPEC_ICON_BUF |=L4_ICON_MASK;	
	SPEC_ICON_BUF |=L5_ICON_MASK;	
	
	if(spec_fresh==LED_RUN_STOP){	
		return;
	}
	else if(spec_fresh ==LED_RUN_SPECT){
		
		spect_pwr = get_spect_power();
		SPEC_PORT_INIT();

		//printf("__----spect_pattern_disp_reflesh  %d, \r\n",(u16)spect_pwr);

		switch(spect_pwr)
		{
			case 1:
				SPEC_ICON_BUF &=~L1_ICON_MASK;
				break;
			case 2:
				SPEC_ICON_BUF &=~(L1_ICON_MASK|L2_ICON_MASK);
				break;
			case 3:
				SPEC_ICON_BUF &=~(L1_ICON_MASK|L2_ICON_MASK|L3_ICON_MASK);
				break;
			case 4:
				SPEC_ICON_BUF &=~(L1_ICON_MASK|L2_ICON_MASK|L3_ICON_MASK|L4_ICON_MASK);
				break;
			case 5:
				SPEC_ICON_BUF &=~(L1_ICON_MASK|L2_ICON_MASK|L3_ICON_MASK|L4_ICON_MASK|L5_ICON_MASK);
				break;			
		}

		LED_COM_EXTEND_ON();
		
	}	
#ifdef LED_ROLLING_FUNC	
	else if(spec_fresh ==LED_RUN_ROLLING){
		
		led_rolling_timer++;		
		spect_pwr = led_rolling_timer/12;
		
		SPEC_PORT_INIT();
		SPEC_ICON_BUF &=~(L1_ICON_MASK);
		SPEC_ICON_BUF &=~(L2_ICON_MASK);
		SPEC_ICON_BUF &=~(L3_ICON_MASK);
		SPEC_ICON_BUF &=~(L4_ICON_MASK);
		SPEC_ICON_BUF &=~(L5_ICON_MASK);
		//printf("__----spect_pattern_disp_reflesh  %d, \r\n",(u16)spect_pwr);
#if defined(LED_ROLLING_TYPE_1)
		switch(spect_pwr)
		{
			case 1:
				SPEC_ICON_BUF |=L5_ICON_MASK;	
				break;
			case 2:
				SPEC_ICON_BUF |=L4_ICON_MASK;	
				break;
			case 3:
				SPEC_ICON_BUF |=L3_ICON_MASK;
				break;
			case 4:
				SPEC_ICON_BUF |=L2_ICON_MASK;
				break;
			case 5:
				SPEC_ICON_BUF |=L1_ICON_MASK;
 				break;
			case 6:
				SPEC_ICON_BUF |=L1_ICON_MASK;
				break;
			case 7:
				SPEC_ICON_BUF |=L2_ICON_MASK;
				break;
			case 8:
				SPEC_ICON_BUF |=L3_ICON_MASK;
				break;
			case 9:
				SPEC_ICON_BUF |=L4_ICON_MASK;	
				break;
			case 10:
				SPEC_ICON_BUF |=L5_ICON_MASK;	
				led_rolling_timer=0;
				break;				
		}
#else
		switch(spect_pwr)
		{
			case 1:
				SPEC_ICON_BUF &=~(L1_ICON_MASK|L2_ICON_MASK|L3_ICON_MASK|L4_ICON_MASK|L5_ICON_MASK);
				break;
			case 2:
				SPEC_ICON_BUF &=~(L1_ICON_MASK|L2_ICON_MASK|L3_ICON_MASK|L4_ICON_MASK);
				break;
			case 3:
				SPEC_ICON_BUF &=~(L1_ICON_MASK|L2_ICON_MASK|L3_ICON_MASK);
				break;
			case 4:
				SPEC_ICON_BUF &=~(L1_ICON_MASK|L2_ICON_MASK);
				break;
			case 5:
				SPEC_ICON_BUF &=~(L1_ICON_MASK);
 				break;
			case 6:
				SPEC_ICON_BUF &=~(L1_ICON_MASK);
				break;
			case 7:
				SPEC_ICON_BUF &=~(L1_ICON_MASK|L2_ICON_MASK);
				break;
			case 8:
				SPEC_ICON_BUF &=~(L1_ICON_MASK|L2_ICON_MASK|L3_ICON_MASK);
				break;
			case 9:
				SPEC_ICON_BUF &=~(L1_ICON_MASK|L2_ICON_MASK|L3_ICON_MASK|L4_ICON_MASK);
				break;
			case 10:
				SPEC_ICON_BUF &=~(L1_ICON_MASK|L2_ICON_MASK|L3_ICON_MASK|L4_ICON_MASK|L5_ICON_MASK);
				led_rolling_timer=0;
				break;				
		}
#endif

		LED_COM_EXTEND_ON();
	}
#endif
	
}
#endif

#if defined(LED_USE_ROUND_LED)

#if defined(K619_FXK_619_V001)
void LED_COM_OUT(u8 COM_Data)
{
    	//LED_COM &= ~0x1f;
 	P10 =((COM_Data&0x01)>0)?1:0;
 	P11 =((COM_Data&0x02)>0)?1:0;
 	P13 =((COM_Data&0x04)>0)?1:0;
 	P14 =((COM_Data&0x08)>0)?1:0;
 	P12 =((COM_Data&0x10)>0)?1:0;
}
void LED_SEG_OUT(u8 SEG_Data)
{
 	P32 =((SEG_Data&0x01)>0)?1:0;
 	P31 =((SEG_Data&0x02)>0)?1:0;
 	P16 =((SEG_Data&0x04)>0)?1:0;
 	P15 =((SEG_Data&0x08)>0)?1:0;
 	P34 =((SEG_Data&0x10)>0)?1:0;
 	P30 =((SEG_Data&0x20)>0)?1:0;
 	P33 =((SEG_Data&0x40)>0)?1:0;
}
#elif defined(K2041_XFW_2041_V001)
void LED_COM_OUT(u8 COM_Data)
{
    	LED_COM &= ~0x1f;
 	P30 =((COM_Data&0x01)>0)?1:0;
 	P31 =((COM_Data&0x02)>0)?1:0;
 	P33 =((COM_Data&0x04)>0)?1:0;
 	P34 =((COM_Data&0x08)>0)?1:0;
 	P32 =((COM_Data&0x10)>0)?1:0;
}
void LED_SEG_OUT(u8 SEG_Data)
{
    	LED_COM &= ~0x1f;
 	P14 =((SEG_Data&0x01)>0)?1:0;
 	P13 =((SEG_Data&0x02)>0)?1:0;
 	P11 =((SEG_Data&0x04)>0)?1:0;
 	P10 =((SEG_Data&0x08)>0)?1:0;
 	P16 =((SEG_Data&0x10)>0)?1:0;
 	P12 =((SEG_Data&0x20)>0)?1:0;
 	P15 =((SEG_Data&0x40)>0)?1:0;
}
#else
void LED_COM_OUT(u8 COM_Data)
{
 	P34 =((COM_Data&0x01)>0)?1:0;
 	P33 =((COM_Data&0x02)>0)?1:0;
 	P31 =((COM_Data&0x04)>0)?1:0;
 	P30 =((COM_Data&0x08)>0)?1:0;
 	P32 =((COM_Data&0x10)>0)?1:0;
}
void LED_SEG_OUT(u8 SEG_Data)
{
    	LED_COM &= ~0x1f;
#ifdef PROTECT_P17_FROM_LED_SCAN
    	LED_SEG &=0x80;
#endif 	
	P12 =((SEG_Data&0x01)>0)?1:0;
 	P13 =((SEG_Data&0x02)>0)?1:0;
 	P15 =((SEG_Data&0x04)>0)?1:0;
 	P16 =((SEG_Data&0x08)>0)?1:0;
 	P10 =((SEG_Data&0x10)>0)?1:0;
 	P14 =((SEG_Data&0x20)>0)?1:0;
 	P11 =((SEG_Data&0x40)>0)?1:0;
}
#endif
void LED_scan(void)
{
#ifndef NO_LED_DISPLAY
    static _xdata  u8 cnt = 0;
    LED_SEG_OUT(~LED_BUFF[cnt]);
    LED_COM_OUT(BIT(cnt));
    cnt = (cnt >= 4)?( 0 ): (cnt+1);
#endif
}
#elif defined(IPONE_DOCK_FUNC_ENABLE)&&!defined(IPONE_INDEPENDENT_MODE)
void LED_COM_OUT(u8 COM_Data)
{
    	LED_COM &= ~0x1C;
	P17 =0;
	
 	P30 =((COM_Data&0x01)>0)?1:0;
 	P31 =((COM_Data&0x02)>0)?1:0;
 	P17 =((COM_Data&0x04)>0)?1:0;
 	P33 =((COM_Data&0x08)>0)?1:0;
	
 	P34 =((COM_Data&0x10)>0)?1:0;
}
void LED_SEG_OUT(u8 SEG_Data)
{
	LED_SEG &=~0x7F;
       LED_SEG |=(SEG_Data&0x7F);
#if 0
 	P12 =((SEG_Data&0x01)>0)?1:0;
 	P13 =((SEG_Data&0x02)>0)?1:0;
 	P15 =((SEG_Data&0x04)>0)?1:0;
 	P16 =((SEG_Data&0x08)>0)?1:0;
 	P10 =((SEG_Data&0x10)>0)?1:0;
 	P14 =((SEG_Data&0x20)>0)?1:0;
 	P11 =((SEG_Data&0x40)>0)?1:0;
#endif	
}
void LED_scan(void)
{
#ifndef NO_LED_DISPLAY
    static _xdata  u8 cnt = 0;
    LED_SEG_OUT(~LED_BUFF[cnt]);
    LED_COM_OUT(BIT(cnt));
    cnt = (cnt >= 4)?( 0 ): (cnt+1);
#endif
}
#elif defined(LED_REVERSE_VIEW)
#define 	DIG_A	0x01
#define 	DIG_B	0x02
#define 	DIG_C	0x04
#define 	DIG_D	0x08
#define 	DIG_E	0x10
#define 	DIG_F	0x20
#define 	DIG_G	0x40
#define 	DIG_H	0x80
u8 align_led_disp_buff(u8 raw_data)
{
	u8 reg_temp;
	reg_temp =(((raw_data&DIG_A)<<3)|((raw_data&DIG_B)<<3)|((raw_data&DIG_C)<<3)|((raw_data&DIG_D)>>3)|
			     ((raw_data&DIG_E)>>3)|((raw_data&DIG_F)>>3)|(raw_data&DIG_G));
	return reg_temp;
}
u8 align_led_disp_com(u8 com_cnt)
{
	switch(com_cnt){
		case 4:return 0x10;
		case 0:return 0x08;
		case 1:return 0x04;
		case 2:return 0x02;
		case 3:return 0x01;
		default:return 0x10;
	}
}
void LED_scan(void)
{
    static _xdata  u8 cnt = 0;
#if defined(COMMON_CATHODE)	
    LED_COM = 0x1f;
    LED_SEG &= ~0x7f;			 //清LED COM SEG
    LED_SEG |= (align_led_disp_buff(LED_BUFF[cnt]));
    LED_COM &= ~(align_led_disp_com(cnt));
    LED_COM5 =((((align_led_disp_buff(LED_BUFF[cnt])))&0x80)>0)?1:0;

#else

    LED_COM &= ~0x1f;
    LED_SEG |= 0x7f;			 //清LED COM SEG
	
#if defined(EXTENDED_LED_SPECTURM)

	//cnt =5;
	if(cnt<5){		
	    LED_COM_EXTEND_OFF();
	    //spect_pattern_disp_reflesh(0);
		spectrum_reflesh_en=0;

	    LED_COM = align_led_disp_com(cnt);
	    LED_SEG &= ~(align_led_disp_buff(LED_BUFF[cnt]));
		
	}
	else{
		//LED_COM_EXTEND_ON();
		spectrum_reflesh_en=1;

	    	//spect_pattern_disp_reflesh(1);
	}
#else	
    LED_COM = align_led_disp_com(cnt);
    LED_SEG &= ~(align_led_disp_buff(LED_BUFF[cnt]));
#endif


    //LED_COM |= BIT(cnt);
#endif

#if defined(EXTENDED_LED_SPECTURM)
    cnt = (cnt >= 5)?( 0 ): (cnt+1);
#else
    cnt = (cnt >= 4)?( 0 ): (cnt+1);
#endif
}
#elif defined(LED_GPIO_PORT_CUSTOMERIZED)

#if defined(K000_JLH_309F_V001)||defined(K000_AOKAILIN_508_V001)
void LED_COM_OUT(u8 COM_Data)
{
    	LED_COM &= ~0x1C;
 	P31 =((COM_Data&0x01)>0)?1:0;
 	P32 =((COM_Data&0x02)>0)?1:0;
 	P33 =((COM_Data&0x04)>0)?1:0;
 	P34 =((COM_Data&0x08)>0)?1:0;
 	P30 =((COM_Data&0x10)>0)?1:0;
}
void LED_SEG_OUT(u8 SEG_Data)
{
	LED_SEG &=~0x7F;
       LED_SEG |=(SEG_Data&0x7F);
}
#elif defined(K0000_MC_Q21_V001)||defined(K0000_MC_TK19_V001)
void LED_COM_OUT(u8 COM_Data)
{
#if defined(COMMON_CATHODE)
	COM_Data = ~COM_Data;
 	P33=((COM_Data&0x01)>0)?1:0;
 	P32 =((COM_Data&0x02)>0)?1:0;
 	P30 =((COM_Data&0x04)>0)?1:0;
 	P34 =((COM_Data&0x08)>0)?1:0;
 	P31 =((COM_Data&0x10)>0)?1:0;
#endif
}
void LED_SEG_OUT(u8 SEG_Data)
{
#if defined(COMMON_CATHODE)
    	LED_COM |=0x1F;
 	P14=((SEG_Data&SEG_A)>0)?0:1;
 	P13=((SEG_Data&SEG_B)>0)?0:1;
 	P11=((SEG_Data&SEG_C)>0)?0:1;
 	P10=((SEG_Data&SEG_D)>0)?0:1;
 	P16=((SEG_Data&SEG_E)>0)?0:1;
 	P12=((SEG_Data&SEG_F)>0)?0:1;
 	P15=((SEG_Data&SEG_G)>0)?0:1;
#else

#endif	
}
#elif defined(K0000_MC_Q18A_V001)||defined(K0000_MC_Q18A_V002)
void LED_COM_OUT(u8 COM_Data)
{
#if defined(COMMON_CATHODE)
	COM_Data = ~COM_Data;
 	P31=((COM_Data&0x01)>0)?1:0;
 	P30 =((COM_Data&0x02)>0)?1:0;
 	P33 =((COM_Data&0x04)>0)?1:0;
 	P34 =((COM_Data&0x08)>0)?1:0;
 	P32 =((COM_Data&0x10)>0)?1:0;
#endif
}
void LED_SEG_OUT(u8 SEG_Data)
{
#if defined(COMMON_CATHODE)
    	LED_COM |=0x1F;
 	P14=((SEG_Data&SEG_A)>0)?0:1;
 	P13=((SEG_Data&SEG_B)>0)?0:1;
 	P11=((SEG_Data&SEG_C)>0)?0:1;
 	P10=((SEG_Data&SEG_D)>0)?0:1;
 	P16=((SEG_Data&SEG_E)>0)?0:1;
 	P12=((SEG_Data&SEG_F)>0)?0:1;
 	P15=((SEG_Data&SEG_G)>0)?0:1;
#else

#endif	
}
#elif defined(K0000_MC_Q16A_V001)
void LED_COM_OUT(u8 COM_Data)
{
#if defined(COMMON_CATHODE)
	COM_Data = ~COM_Data;
 	P33 =((COM_Data&0x01)>0)?1:0;
 	P32 =((COM_Data&0x02)>0)?1:0;
 	P31 =((COM_Data&0x04)>0)?1:0;
 	P30 =((COM_Data&0x08)>0)?1:0;
 	P34 =((COM_Data&0x10)>0)?1:0;
#endif
}
void LED_SEG_OUT(u8 SEG_Data)
{
#if defined(COMMON_CATHODE)
    	LED_COM |=0x1F;
 	P14=((SEG_Data&SEG_A)>0)?0:1;
 	P13=((SEG_Data&SEG_B)>0)?0:1;
 	P11=((SEG_Data&SEG_C)>0)?0:1;
 	P10=((SEG_Data&SEG_D)>0)?0:1;
 	P16=((SEG_Data&SEG_E)>0)?0:1;
 	P12=((SEG_Data&SEG_F)>0)?0:1;
 	P15=((SEG_Data&SEG_G)>0)?0:1;
#else

#endif	
}
#elif defined(K0000_MC_M73A_V001)||defined(K0000_MC_L2A_V001)||defined(K0000_MC_DYJ_V001)
void LED_COM_OUT(u8 COM_Data)
{
    	LED_COM &= ~0x1f;
    	LED_COM |= COM_Data;
}
void LED_SEG_OUT(u8 SEG_Data)
{
    	LED_COM &= ~0x1f;
	LED_SEG &=0x80;
	LED_SEG &=~0x7F;
 	P16=((SEG_Data&SEG_A)>0)?1:0;
 	P15=((SEG_Data&SEG_B)>0)?1:0;
 	P14=((SEG_Data&SEG_C)>0)?1:0;
 	P13=((SEG_Data&SEG_D)>0)?1:0;
 	P12=((SEG_Data&SEG_E)>0)?1:0;
 	P11=((SEG_Data&SEG_F)>0)?1:0;
 	P10=((SEG_Data&SEG_G)>0)?1:0;
}
#elif defined(K0000_MC_H2_V001)
void LED_COM_OUT(u8 COM_Data)
{
    	LED_COM &= ~0x1f;
    	LED_COM |= COM_Data;
}
void LED_SEG_OUT(u8 SEG_Data)
{
    	LED_COM &= ~0x1f;
	LED_SEG &=0x80;
	LED_SEG &=~0x7F;
 	P16=((SEG_Data&SEG_A)>0)?1:0;
 	P15=((SEG_Data&SEG_B)>0)?1:0;
 	P14=((SEG_Data&SEG_C)>0)?1:0;
 	P13=((SEG_Data&SEG_D)>0)?1:0;
 	P12=((SEG_Data&SEG_E)>0)?1:0;
 	P11=((SEG_Data&SEG_F)>0)?1:0;
 	P10=((SEG_Data&SEG_G)>0)?1:0;
}
#elif defined(K2321_JM_2321_V001)
void LED_COM_OUT(u8 COM_Data)
{
 	P30 =((COM_Data&0x01)>0)?0:1;
 	P17 =((COM_Data&0x02)>0)?0:1;
 	P13 =((COM_Data&0x04)>0)?0:1;
 	P33 =((COM_Data&0x08)>0)?0:1;
 	//P32 =((COM_Data&0x10)>0)?1:0;
}
void LED_SEG_OUT(u8 SEG_Data)
{
	P16 =((SEG_Data&0x01)>0)?0:1;
 	P14 =((SEG_Data&0x02)>0)?0:1;
 	P15 =((SEG_Data&0x04)>0)?0:1;
 	P31 =((SEG_Data&0x08)>0)?0:1;
 	P11 =((SEG_Data&0x10)>0)?0:1;
 	P12 =((SEG_Data&0x20)>0)?0:1;
 	P10 =((SEG_Data&0x40)>0)?0:1;
 	P32 =((SEG_Data&0x80)>0)?0:1;
}
#elif defined(K1123_WXD_1123_V001)||defined(K1132_ZK_963_V001)
void LED_COM_OUT(u8 COM_Data)
{
 	P30 =((COM_Data&0x01)>0)?1:0;
 	P31 =((COM_Data&0x02)>0)?1:0;
 	P33 =((COM_Data&0x04)>0)?1:0;
 	P17 =((COM_Data&0x08)>0)?1:0;
 	P32 =((COM_Data&0x10)>0)?1:0;
}
void LED_SEG_OUT(u8 SEG_Data)
{
    	LED_COM &= ~0x0f;
	LED_SEG &=~0x7F;
	P14 =((SEG_Data&0x01)>0)?1:0;
 	P13 =((SEG_Data&0x02)>0)?1:0;
 	P11 =((SEG_Data&0x04)>0)?1:0;
 	P10 =((SEG_Data&0x08)>0)?1:0;
 	P16 =((SEG_Data&0x10)>0)?1:0;
 	P12 =((SEG_Data&0x20)>0)?1:0;
 	P15 =((SEG_Data&0x40)>0)?1:0;
}
#elif defined(K568_ZX_568_V001)||defined(K0000_GW_ZX015_V001)
void LED_COM_OUT(u8 COM_Data)
{
    	LED_COM &= ~0x1f;
    	LED_COM |= COM_Data;
}
void LED_SEG_OUT(u8 SEG_Data)
{
 	P16=((SEG_Data&SEG_A)>0)?1:0;
 	P15=((SEG_Data&SEG_B)>0)?1:0;
 	P14=((SEG_Data&SEG_C)>0)?1:0;
 	P13=((SEG_Data&SEG_D)>0)?1:0;
 	P12=((SEG_Data&SEG_E)>0)?1:0;
 	P11=((SEG_Data&SEG_F)>0)?1:0;
 	P10=((SEG_Data&SEG_G)>0)?1:0;
}
#elif defined(K000_JR_210_V001)
void LED_COM_OUT(u8 COM_Data)
{
 	P30 =((COM_Data&COM_1)>0)?1:0;
 	P31 =((COM_Data&COM_2)>0)?1:0;
 	P32 =((COM_Data&COM_3)>0)?1:0;
 	P33 =((COM_Data&COM_4)>0)?1:0;
 	//P30 =((COM_Data&COM_5)>0)?1:0;
}
void LED_SEG_OUT(u8 SEG_Data)
{
    	LED_COM &= ~0x1f;
	LED_SEG &=~0x7F;
 	P10=((SEG_Data&SEG_A)>0)?1:0;
 	P11=((SEG_Data&SEG_B)>0)?1:0;
 	P12=((SEG_Data&SEG_C)>0)?1:0;
 	P13=((SEG_Data&SEG_D)>0)?1:0;
 	P14=((SEG_Data&SEG_E)>0)?1:0;
 	P15=((SEG_Data&SEG_F)>0)?1:0;
 	P16=((SEG_Data&SEG_G)>0)?1:0;
 	P34=((SEG_Data&SEG_H)>0)?1:0;
}
#elif defined(K000_XINGLEI_2092_V001)||defined(XINLEI_LED_DRIVE_TYPE)||defined(K000_XinLei_LC2092_V006)||defined(K000_XinLei_LC2092_V005)||defined(K000_XinLei_LC2092_V004)||defined(K000_XinLei_LC2092_V001)||defined(K000_XinLei_LC2092_V002)||defined(K000_XinLei_LC2092_V003)
void LED_COM_OUT(u8 COM_Data)
{
 	P31 =((COM_Data&0x01)>0)?1:0;
 	P32 =((COM_Data&0x02)>0)?1:0;
 	P33 =((COM_Data&0x04)>0)?1:0;
 	P34 =((COM_Data&0x08)>0)?1:0;
 	P30 =((COM_Data&0x10)>0)?1:0;
}
void LED_SEG_OUT(u8 SEG_Data)
{
    	LED_COM &= ~0x1f;
	LED_SEG &=~0x7F;
       LED_SEG |=(SEG_Data&0x7F);
}
#elif defined(K1119_LS_1119_V001)
void LED_COM_OUT(u8 COM_Data)
{
 	P33 =((COM_Data&0x01)>0)?1:0;
 	P31 =((COM_Data&0x02)>0)?1:0;
 	P30 =((COM_Data&0x04)>0)?1:0;
 	P32 =((COM_Data&0x08)>0)?1:0;
 	P17 =((COM_Data&0x10)>0)?1:0;
}
void LED_SEG_OUT(u8 SEG_Data)
{
    	LED_COM &= ~0x0f;
	LED_SEG &=~0x7F;
       LED_SEG |=(SEG_Data&0x7F);
}
#elif defined(K1140_AJR_1140_V001)||defined(K2056_AJR_2056_V001)
void LED_COM_OUT(u8 COM_Data)
{
 	P30 =((COM_Data&0x01)>0)?1:0;
 	P31 =((COM_Data&0x02)>0)?1:0;
 	P33 =((COM_Data&0x04)>0)?1:0;
 	P17 =((COM_Data&0x08)>0)?1:0;
 	P32 =((COM_Data&0x10)>0)?1:0;
}
void LED_SEG_OUT(u8 SEG_Data)
{
    	LED_COM &= ~0x0f;
	LED_SEG &=~0x7F;
 	P14=((SEG_Data&SEG_A)>0)?1:0;
 	P13=((SEG_Data&SEG_B)>0)?1:0;
 	P11=((SEG_Data&SEG_C)>0)?1:0;
 	P10=((SEG_Data&SEG_D)>0)?1:0;
 	P16=((SEG_Data&SEG_E)>0)?1:0;
 	P12=((SEG_Data&SEG_F)>0)?1:0;
 	P15=((SEG_Data&SEG_G)>0)?1:0;
}
#elif defined(K1154_YJH_1154_V001)||defined(K1154_HF_054_V001)
void LED_COM_OUT(u8 COM_Data)
{
    	LED_COM &= ~0x1f;
 	P30 =((COM_Data&0x01)>0)?1:0;
 	P31 =((COM_Data&0x02)>0)?1:0;
 	P33 =((COM_Data&0x04)>0)?1:0;
 	P34 =((COM_Data&0x08)>0)?1:0;
 	P32 =((COM_Data&0x10)>0)?1:0;
}
void LED_SEG_OUT(u8 SEG_Data)
{
    	LED_COM &= ~0x1f;
#ifdef PROTECT_P17_FROM_LED_SCAN
    	LED_SEG &=0x80;
#endif 	
		
 	P14 =((SEG_Data&0x01)>0)?1:0;
 	P13 =((SEG_Data&0x02)>0)?1:0;
 	P11 =((SEG_Data&0x04)>0)?1:0;
 	P10 =((SEG_Data&0x08)>0)?1:0;
 	P16 =((SEG_Data&0x10)>0)?1:0;
 	P12 =((SEG_Data&0x20)>0)?1:0;
 	P15 =((SEG_Data&0x40)>0)?1:0;
}
#elif defined(K1144_DCX_956_V001)||defined(K1165_YHD_Y002_V001)
void LED_COM_OUT(u8 COM_Data)
{
 	P30 =((COM_Data&0x01)>0)?1:0;
 	P31 =((COM_Data&0x02)>0)?1:0;
 	P33 =((COM_Data&0x04)>0)?1:0;
 	P17 =((COM_Data&0x08)>0)?1:0;
 	P32 =((COM_Data&0x10)>0)?1:0;
}
void LED_SEG_OUT(u8 SEG_Data)
{
    	LED_COM &= ~0x0f;
	LED_SEG &=~0xFF;
 	P14=((SEG_Data&SEG_A)>0)?1:0;
 	P13=((SEG_Data&SEG_B)>0)?1:0;
 	P11=((SEG_Data&SEG_C)>0)?1:0;
 	P10=((SEG_Data&SEG_D)>0)?1:0;
 	P16=((SEG_Data&SEG_E)>0)?1:0;
 	P12=((SEG_Data&SEG_F)>0)?1:0;
 	P15=((SEG_Data&SEG_G)>0)?1:0;
}
#elif defined(K1107_DCX_991_V001)||defined(K0000_XXX_SX_V001)||defined(LED_COMMON_SCAN_COM_USE_P17)
void LED_COM_OUT(u8 COM_Data)
{
 	P30 =((COM_Data&0x01)>0)?1:0;
 	P31 =((COM_Data&0x02)>0)?1:0;
 	P32 =((COM_Data&0x04)>0)?1:0;
 	P33 =((COM_Data&0x08)>0)?1:0;
 	P17 =((COM_Data&0x10)>0)?1:0;
}
void LED_SEG_OUT(u8 SEG_Data)
{
    	LED_COM &= ~0x0f;
	LED_SEG &=~0x7F;
       LED_SEG |=(SEG_Data&0x7F);
}
#elif defined(K731_YJH_731_V001)||defined(K731_YJH_820_V001)
void LED_COM_OUT(u8 COM_Data)
{
 	P14 =((COM_Data&0x01)>0)?1:0;
 	P13 =((COM_Data&0x02)>0)?1:0;
 	P12 =((COM_Data&0x04)>0)?1:0;
 	P11 =((COM_Data&0x08)>0)?1:0;
 	P10=((COM_Data&0x10)>0)?1:0;
}
void LED_SEG_OUT(u8 SEG_Data)
{
 	P34=((SEG_Data&0x01)>0)?1:0;
 	P33=((SEG_Data&0x02)>0)?1:0;
 	P32=((SEG_Data&0x04)>0)?1:0;
 	P31=((SEG_Data&0x08)>0)?1:0;
 	P30=((SEG_Data&0x10)>0)?1:0;
 	P16=((SEG_Data&0x20)>0)?1:0;
 	P15=((SEG_Data&0x40)>0)?1:0;
}
#elif defined(K1007_JinYiHeLi_1007_V001)
void LED_COM_OUT(u8 COM_Data)
{
    	//LED_COM &= ~0x1f;
 	P14 =((COM_Data&0x01)>0)?1:0;
 	P16 =((COM_Data&0x02)>0)?1:0;
 	P11 =((COM_Data&0x04)>0)?1:0;
 	P15 =((COM_Data&0x08)>0)?1:0;
 	P10 =((COM_Data&0x10)>0)?1:0;
}
void LED_SEG_OUT(u8 SEG_Data)
{
 	P34=((SEG_Data&0x01)>0)?1:0;
 	P32=((SEG_Data&0x02)>0)?1:0;
 	P13=((SEG_Data&0x04)>0)?1:0;
 	P12=((SEG_Data&0x08)>0)?1:0;
 	P30=((SEG_Data&0x10)>0)?1:0;
 	P33=((SEG_Data&0x20)>0)?1:0;
 	P31=((SEG_Data&0x40)>0)?1:0;
}
#elif defined(K769_JinRui_769_V002)
void LED_COM_OUT(u8 COM_Data)
{ 	
 	P32 =((COM_Data&0x01)>0)?1:0;
 	P31 =((COM_Data&0x02)>0)?1:0;
 	P33 =((COM_Data&0x04)>0)?1:0;
 	P30 =((COM_Data&0x08)>0)?1:0;
 	P34 =((COM_Data&0x10)>0)?1:0;
}
void LED_SEG_OUT(u8 SEG_Data)
{
    	LED_COM &= ~0x1f;
	LED_SEG=SEG_Data;
}
#elif defined(K769_JinRui_769_V001)
void LED_COM_OUT(u8 COM_Data)
{
    	LED_COM &= ~0x1f;
 	P33 =((COM_Data&0x01)>0)?1:0;
 	P31 =((COM_Data&0x02)>0)?1:0;
 	P30 =((COM_Data&0x04)>0)?1:0;
 	P32 =((COM_Data&0x08)>0)?1:0;
 	P34 =((COM_Data&0x10)>0)?1:0;
}
void LED_SEG_OUT(u8 SEG_Data)
{
	LED_SEG=SEG_Data;
}
#endif

void LED_scan(void)
{
#ifndef NO_LED_DISPLAY
    static _xdata  u8 cnt = 0;
    LED_SEG_OUT(~LED_BUFF[cnt]);
    LED_COM_OUT(BIT(cnt));
    cnt = (cnt >= 4)?( 0 ): (cnt+1);
#endif
}


#elif defined(EXTENED_LED_NUM_SCAN)

#define EXTENED_NUM 	8

xd_u8 LED_BUFF_2[3]={0};
void LED_COM_OUT(u8 COM_Data)
{
    	LED_COM &= ~0x1f;
	
 	P30 =((COM_Data&0x01)>0)?1:0;
 	P31 =((COM_Data&0x02)>0)?1:0;
 	P32 =((COM_Data&0x04)>0)?1:0;
 	P33 =((COM_Data&0x08)>0)?1:0;
	P34 =((COM_Data&0x10)>0)?1:0;
 	P26 =((COM_Data&0x20)>0)?1:0;
 	P27 =((COM_Data&0x40)>0)?1:0;
 	P17 =((COM_Data&0x80)>0)?1:0;
}
void LED_SEG_OUT_2(u8 SEG_Data)
{

#ifdef PROTECT_P17_FROM_LED_SCAN
    	LED_SEG &=0x80;
#endif 	
 	P15=((SEG_Data&SEG_A)>0)?1:0;
 	P16=((SEG_Data&SEG_B)>0)?1:0;
 	P14=((SEG_Data&SEG_C)>0)?1:0;
 	P13=((SEG_Data&SEG_D)>0)?1:0;
 	P12=((SEG_Data&SEG_E)>0)?1:0;
 	P10=((SEG_Data&SEG_F)>0)?1:0;
 	P11=((SEG_Data&SEG_G)>0)?1:0;
}
void LED_SEG_OUT(u8 SEG_Data)
{
#ifdef PROTECT_P17_FROM_LED_SCAN
    	LED_SEG &=0x80;
#endif 	
	LED_SEG =SEG_Data;
}
void LED_scan(void)
{
#ifndef NO_LED_DISPLAY
    static _xdata  u8 cnt = 0;
    if(cnt >4){	
    	LED_SEG_OUT_2(~LED_BUFF_2[cnt-5]);
    }
    else{
    	LED_SEG_OUT(~LED_BUFF[cnt]);
    }
    LED_COM_OUT(BIT(cnt));
    cnt = (cnt >= (EXTENED_NUM-1))?( 0 ): (cnt+1);
#endif
}
#else
void LED_scan(void)
{
    static _xdata  u8 cnt = 0;
#if defined(COMMON_CATHODE)	

    LED_COM |= 0x1f;
    LED_SEG &= ~0x7f;			 //清LED COM SEG
#if defined(PWR_CTRL_P17)    
    LED_SEG |= (LED_BUFF[cnt])|0x80;
#else
	LED_SEG |= (LED_BUFF[cnt]);
#endif
    LED_COM &=~( BIT(cnt));
    //LED_COM &= ~BIT(cnt);
    
#else	//COMMON_CATHODE

#if defined(EXTENDED_LED_SPECTURM)
    	LED_COM &= ~0x1f;
    	LED_SEG |= 0x7f;			 //清LED COM SEG
    	
	//cnt =5;
	if(cnt<5){		
	      LED_COM_EXTEND_OFF();
	       //spect_pattern_disp_reflesh(0);
		spectrum_reflesh_en=0;
    		LED_SEG = ~LED_BUFF[cnt];
    		LED_COM |= BIT(cnt);
	}
	else{
		//LED_COM_EXTEND_ON();
		spectrum_reflesh_en=1;
	    	//spect_pattern_disp_reflesh(1);
	}
#else	//EXTENDED_LED_SPECTURM

    LED_COM &= ~0x1f;
#ifdef PROTECT_P17_FROM_LED_SCAN
    LED_SEG &=0x80;
    LED_SEG |= (~(LED_BUFF[cnt]))&0x7F;
#else
    LED_SEG = ~LED_BUFF[cnt];
#endif

#if defined(K080_YJH_985_V001)||defined(K081_YJH_973_V001)
    LED_COM5 =(((~LED_BUFF[cnt])&0x80)>0)?1:0;
#endif	
    LED_COM |= BIT(cnt);
    //LED_COM &= ~BIT(cnt);
    
#endif    //end  of  EXTENDED_LED_SPECTURM
#endif //end of  COMMON_CATHODE   

#if defined(EXTENDED_LED_SPECTURM)
    cnt = (cnt >= 5)?( 0 ): (cnt+1);
#else
    cnt = (cnt >= 4)?( 0 ): (cnt+1);
#endif
}

#endif
void updateLED(void)
{
#ifdef LED_DRVER_USE_SM1628
TM1628_display(LED_BUFF[4],LED_BUFF[0],LED_BUFF[1],LED_BUFF[2],LED_BUFF[3]);
#endif
}
void lcd_power_down(void)
{
    disp_buf_clear();
    LED_COM &= ~0x1f;
    LED_SEG &= ~0xEF;
}
#endif
