#ifndef _GPIO_CONFIG_H_
#define _GPIO_CONFIG_H_

#include "Custom_config.h"

#ifdef MUTE_CTRL_LEVEL_NORMAL
#define MUTE_LEVEL		1
#define UNMUTE_LEVEL	0
#else
#define MUTE_LEVEL		0
#define UNMUTE_LEVEL	1
#endif

#ifdef LED_CTRL_LEVEL_NORMAL
#define ON_LEVEL		1
#define OFF_LEVEL		0
#else
#define ON_LEVEL		0
#define OFF_LEVEL		1
#endif

#ifdef LED_MODE_INDICATOR_ENABLE
#define LED_Indicator_init() 		DACCON0|=0x80;P2DIR &= ~(BIT(7)|BIT(5)|BIT(4));P2PU |= (BIT(7)|BIT(5)|BIT(4))
#define LED_MODE_USB			P27
#define LED_MODE_SD			P24
#define LED_MODE_FM			P25
#endif

#ifdef AC209_28PIN
//1 ac209 28pin

// msgfor_hot.c
#if defined(MUTE_PORT_USE_DUMP)
#define SET_MUTE_PORT_DIR()		
#define SET_MUTE_PORT_PU() 			
#define MUTE_PORT_HIGH()			
#define MUTE_PORT_LOW()		
#elif defined(MUTE_PORT_USE_P01)
#define SET_MUTE_PORT_DIR()		P0DIR &= ~0x02
#define SET_MUTE_PORT_PU() 			P0PU |= 0x02
#define MUTE_PORT_HIGH()			P01  = MUTE_LEVEL
#define MUTE_PORT_LOW()			P01  = UNMUTE_LEVEL
#elif defined(MUTE_PORT_USE_P00)
#define SET_MUTE_PORT_DIR()		P0DIR &= ~(BIT(0))
#define SET_MUTE_PORT_PU() 			P0PU |= (BIT(0))
#define MUTE_PORT_HIGH()			P00  =MUTE_LEVEL
#define MUTE_PORT_LOW()			P00  =UNMUTE_LEVEL
#elif defined(MUTE_PORT_USE_P02)
#define SET_MUTE_PORT_DIR()		P0DIR &= ~(BIT(2));P3DIR |= (BIT(4));P3PU &= ~(BIT(4));P3PD&= ~(BIT(4))
#define SET_MUTE_PORT_PU() 			P0PU |= (BIT(2))
#define MUTE_PORT_HIGH()			P02  =MUTE_LEVEL
#define MUTE_PORT_LOW()			P02  =UNMUTE_LEVEL
#elif defined(MUTE_PORT_USE_P04)
#define SET_MUTE_PORT_DIR()			P0DIR &= ~(BIT(4))
#define SET_MUTE_PORT_PU() 				P0PU |= (BIT(4))
#define MUTE_PORT_HIGH()				P04  =MUTE_LEVEL
#define MUTE_PORT_LOW()				P04  =UNMUTE_LEVEL
#elif defined(MUTE_PORT_USE_P05)
#define SET_MUTE_PORT_DIR()		P0DIR &= ~(BIT(5))
#define SET_MUTE_PORT_PU() 			P0PU |= (BIT(5))
#define MUTE_PORT_HIGH()			P05  =MUTE_LEVEL
#define MUTE_PORT_LOW()			P05  =UNMUTE_LEVEL

#define DISABLE_P05_OSC_OUTPUT

#elif defined(MUTE_PORT_USE_P17)
#define SET_MUTE_PORT_DIR()		P1DIR &= ~(BIT(7))
#define SET_MUTE_PORT_PU() 			P1PU |= BIT(7)
#define MUTE_PORT_HIGH()			P17  =MUTE_LEVEL
#define MUTE_PORT_LOW()			P17  =UNMUTE_LEVEL
#elif defined(MUTE_PORT_USE_P27)
#define SET_MUTE_PORT_DIR()		DACCON0|=0x80;P2DIR &= ~(BIT(7))
#define SET_MUTE_PORT_PU() 			P2PU |= BIT(7)
#define MUTE_PORT_HIGH()			P27  =MUTE_LEVEL
#define MUTE_PORT_LOW()			P27  =UNMUTE_LEVEL
#define AUX_P27_IN_USE
#else //MUTE_PORT_USE_P26
#define SET_MUTE_PORT_DIR()		DACCON0|=0x80;P2DIR &= ~(BIT(6))
#define SET_MUTE_PORT_PU() 			P2PU |= BIT(6)
#define MUTE_PORT_HIGH()			P26  =MUTE_LEVEL
#define MUTE_PORT_LOW()			P26  =UNMUTE_LEVEL
#define AUX_P26_IN_USE
#endif

#ifdef LED_1651_DRV

#ifdef LED_GPIO_DRV
#undef LED_GPIO_DRV
#endif

#else

#define NO_LED_DISPLAY
#ifdef DISPLAY_TEST
#undef NO_LED_DISPLAY
#endif

#endif

//led.h
#if defined(COMMON_CATHODE)
#define led_com_out() P3DIR &= ~0x1F; P3PU &=~(0x1F);P3PD|=0x1F
#define led_seg_out() P1DIR &= ~0xFF;P1PU |= 0xFF 
#else
#define led_com_out() P3DIR &= ~0x1F; P3PU |= 0x1F
#define led_seg_out() P1DIR &= ~0xFF;P1PU |= 0xFF 
#endif
#define LED_COM1   P30
#define LED_COM2   P31
#define LED_COM3   P32
#define LED_COM4   P33
#define LED_COM5   P34
#define LED_COM    P3
#define LED_SEG    P1
//display_common.h

//1 ac209 28pin
#if defined(PLAY_STATUS_LED_P27)
#define play_led_seg_out() 		DACCON0|=0x80;P2DIR &= ~(BIT(7));P2PU |= BIT(7)
#define PLAY_STATUS_PORT 		P27
#elif defined(PLAY_STATUS_LED_P26)
#define play_led_seg_out() 		DACCON0|=0x80;P2DIR &= ~(BIT(6));P2PU |= BIT(6)
#define PLAY_STATUS_PORT 		P26
#elif defined(PLAY_STATUS_LED_P05)
#define play_led_seg_out() 		P0DIR &= ~(BIT(5));P0PU |= BIT(5)
#define PLAY_STATUS_PORT 		P05
#elif defined(PLAY_STATUS_LED_P01)
#define play_led_seg_out() 		P0DIR &= ~(BIT(1));P0PU |= BIT(1)
#define PLAY_STATUS_PORT 		P01
#ifdef IIC_GPIO_USE_P00_P01
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL
#endif
#elif defined(PLAY_STATUS_LED_P00)
#define play_led_seg_out() 		P0DIR &= ~(BIT(0));P0PU |= BIT(0)
#define PLAY_STATUS_PORT 		P00
#else
#define play_led_seg_out() 		DACCON0|=0x80;P0DIR &= ~(1<<2);P0PU |= (1<<2); P3DIR |= (1<<4);P3PU &= ~(1<<4);P3PD&= ~(1<<4)
#define PLAY_STATUS_PORT 		P02
#endif

#if defined(TWO_PLAY_LED_IN_USE)
#if defined(TWO_PLAY_LED_USE_PORT_P00)
#define play_led_seg_out_NO2() 		P0DIR &= ~(BIT(0));P0PU |= (BIT(0))
#define PLAY_STATUS_PORT_NO2 		P00
#elif defined(TWO_PLAY_LED_USE_PORT_P01)
#define play_led_seg_out_NO2() 		P0DIR &= ~(BIT(1));P0PU |= (BIT(1))
#define PLAY_STATUS_PORT_NO2 		P01
#else
#define play_led_seg_out_NO2() 		DACCON0|=0x80;P0DIR &= ~(1<<2);P0PU |= (1<<2); P3DIR |= (1<<4);P3PU &= ~(1<<4);P3PD&= ~(1<<4)
#define PLAY_STATUS_PORT_NO2 		P02
#endif
#endif


#if defined(EARPHONE_DETECT_USE_VPP)
#define  EARPHONE_DETECT_GPIO  		(WKUPPND&BIT(7))
#define  hp_detect_begin()   				WKUPPND|=BIT(6)
#define  hp_detect_in_off()
#define INDEPENDENT_EARPHONE_DETECT_GPIO
#define USE_IR_VPP_PORT_FOR_DETECTION
#elif defined(EARPHONE_DETECT_USE_P01)
#define  EARPHONE_DETECT_GPIO  		P01
#define  hp_detect_begin()   				P0DIR &=~(BIT(1));P01=1; P0DIR |= BIT(1);P0PU |= BIT(1)
#define  hp_detect_in_off()				P0DIR &=~(BIT(1));
#if !defined(IIC_GPIO_USE_P01_P00)
#define INDEPENDENT_EARPHONE_DETECT_GPIO
#endif
#elif defined(EARPHONE_DETECT_USE_P02)
#define  EARPHONE_DETECT_GPIO  		P02
#define  hp_detect_begin()   				P0DIR &=~(BIT(2));P02=1; P0DIR |= BIT(2);P0PU |= BIT(2);P3DIR |= BIT(4);P3PU &= ~(BIT(4));P3PD&= ~(BIT(4))
#define  hp_detect_in_off()				P0DIR &=~(BIT(2));

#define INDEPENDENT_EARPHONE_DETECT_GPIO
#else
#define  EARPHONE_DETECT_GPIO  		P27
#define  hp_detect_begin()   				DACCON0|=0x80;P2DIR |= (BIT(7));P2DIR &= ~(BIT(6));P2PU |= (BIT(7));
#define  hp_detect_in_off()				P2DIR &=~(BIT(7));	
#define INDEPENDENT_EARPHONE_DETECT_GPIO
#endif

//1 ac209 28pin

#if defined(AUX_DETECT_USE_VPP)
#define  AUX_DETECT_GPIO  		(WKUPPND&BIT(7))
#define  aux_detect_in()   			WKUPPND|=BIT(6)
#define  aux_detect_in_off()
#define USE_IR_VPP_PORT_FOR_DETECTION
#elif defined(AUX_DETECT_USE_P26)
#define  aux_detect_in()      		DACCON0|=0x80;P2DIR |= (BIT(6));P2PU |= (BIT(6));
#define  AUX_DETECT_GPIO  		P26
#define  aux_detect_in_off()      	P2DIR &= ~(BIT(6)); //linein check port
#define INDEPENDENT_AUX_DETECT_GPIO
#elif defined(AUX_DETECT_USE_P02)
#define  aux_detect_in()      		P0DIR &=~(BIT(2));P02=1; P0DIR |= BIT(2);P0PU |= BIT(2);P3DIR |= (BIT(4));P3PU &= ~(BIT(4));P3PD&= ~(BIT(4))
#define  AUX_DETECT_GPIO  		P02
#define  aux_detect_in_off()      	P0DIR &= ~(BIT(2)); //linein check port
#define INDEPENDENT_AUX_DETECT_GPIO
#elif defined(AUX_DETECT_USE_P01)
#define  aux_detect_in()      		P0DIR &=~(BIT(1));P01=1; P0DIR |= BIT(1);P0PU |= BIT(1);
#define  AUX_DETECT_GPIO  		P01
#define  aux_detect_in_off()      	P0DIR &= ~(BIT(1)); //linein check port
#elif defined(AUX_DETECT_USE_P05)
#define  aux_detect_in()      		P0DIR &=~(BIT(5));P05=1; P0DIR |= BIT(5);P0PU |= BIT(5);
#define  AUX_DETECT_GPIO  		P05
#define  aux_detect_in_off()      	P0DIR &= ~(BIT(5)); //linein check port
#ifndef K1226_AP_750_V001
#define INDEPENDENT_AUX_DETECT_GPIO
#endif
#elif defined(AUX_DETECT_USE_P00)
#define  aux_detect_in()      		P0DIR &=~(BIT(0));P00=1; P0DIR |= BIT(0);P0PU |= BIT(0);
#define  AUX_DETECT_GPIO  		P00
#define  aux_detect_in_off()      	P0DIR &= ~(BIT(0)); //linein check port
#else
#define  aux_detect_in()      		DACCON0|=0x80;P2DIR |= BIT(7);P2PU |= BIT(7);//linein check port
#define  AUX_DETECT_GPIO  		P27
#define  aux_detect_in_off()        	DACCON0|=0x80;P2DIR &= ~(BIT(7)); //linein check port
#define INDEPENDENT_AUX_DETECT_GPIO
#endif
#if 0
#define  aux_detect_in()      P2DIR |= BIT(7);P0PU |= BIT(7);//linein check port
#define  AUX_DETECT_GPIO  P27
#define  aux_detect_in_off()        P2DIR &= ~(BIT(7)); //linein check port
#endif
//1 ac209 28pin
//iic.h
#if defined(IIC_GPIO_USE_DUMMY)
#define iic_data_out()    
#define iic_data_in()     
#define iic_data_r()      P00
#define iic_data_h()      
#define iic_data_l()     

#define iic_clk_out()    
#define iic_clk_h()      
#define iic_clk_l()      
#if 1	//for bk1080.h
#define BK_DATA_HIGH()   	iic_data_h()
#define BK_DATA_LOW()    	iic_data_l()
#define BK_DATA_READ()    	iic_data_r()
#define SDADIROUT()       		iic_data_out()
#define SDADIRIN()        		iic_data_in()

#define SCLDIROUT()        		iic_clk_out()
#define BK_CLK_HIGH()     		iic_clk_h()
#define BK_CLK_LOW()      		iic_clk_l()

#endif
#elif defined(IIC_GPIO_USE_P02_P01)

#define iic_data_out()    	P0DIR &= ~(BIT(1));P0PU |= BIT(1);
#define iic_data_in()     	P0DIR |= (BIT(1));P0PU |= BIT(1);	
#define iic_data_r()      	P01
#define iic_data_h()      	P01 = 1
#define iic_data_l()     	P01 = 0

#define iic_clk_out()    	P0DIR &= ~(BIT(2));P0PU |= (BIT(2));P3DIR |= (BIT(4));P3PU &= ~(BIT(4));P3PD&= ~(BIT(4)) 	
#define iic_clk_h()      	P02 = 1
#define iic_clk_l()      		P02 = 0

#if 1	//for bk1080.h
#define BK_DATA_HIGH()   	iic_data_h()
#define BK_DATA_LOW()    	iic_data_l()
#define BK_DATA_READ()    	iic_data_r()
#define SDADIROUT()       		iic_data_out()
#define SDADIRIN()        		iic_data_in()

#define SCLDIROUT()        		iic_clk_out()
#define BK_CLK_HIGH()     		iic_clk_h()
#define BK_CLK_LOW()      		iic_clk_l()

#endif

#elif defined(IIC_GPIO_USE_P01_P27)

#define iic_data_out()    	DACCON0|=0x80;P2DIR &= ~(BIT(7));P2PU |= BIT(7) 	
#define iic_data_in()     	DACCON0|=0x80;P2DIR |= (BIT(7));P2PU |= BIT(7)	
#define iic_data_r()      	P27
#define iic_data_h()      	P27= 1
#define iic_data_l()      	P27 = 0

#define iic_clk_out()    	P0DIR &= ~(BIT(1));P0PU |= (BIT(1))	
#define iic_clk_h()      	P01 = 1
#define iic_clk_l()      		P01 = 0

#if 1	//for bk1080.h
#define BK_DATA_HIGH()   	iic_data_h()
#define BK_DATA_LOW()    	iic_data_l()
#define BK_DATA_READ()    	iic_data_r()
#define SDADIROUT()       		iic_data_out()
#define SDADIRIN()        		iic_data_in()

#define SCLDIROUT()        		iic_clk_out()
#define BK_CLK_HIGH()     		iic_clk_h()
#define BK_CLK_LOW()      		iic_clk_l()

#endif

#elif defined(IIC_GPIO_USE_P01_P02)
//4 IIC gpio P01 P02
#define iic_data_out()    	P0DIR &= ~(BIT(2));P0PU |= BIT(2);P3DIR |= (BIT(4));P3PU &= ~(BIT(4));P3PD&= ~(BIT(4)) 	
#define iic_data_in()     	P0DIR |= (BIT(2));P0PU |= BIT(2);P3DIR |= (BIT(4));P3PU &= ~(BIT(4));P3PD&= ~(BIT(4))	
#define iic_data_r()      	P02
#define iic_data_h()      	P02 = 1
#define iic_data_l()     	P02 = 0

#define iic_clk_out()    P0DIR &= ~(BIT(1));P0PU |= (BIT(1))
#define iic_clk_h()      P01 = 1
#define iic_clk_l()      P01 = 0
#if 1	//for bk1080.h
#define BK_DATA_HIGH()   P02=1;
#define BK_DATA_LOW()    P02=0;
#define BK_DATA_READ()    P02
#define SDADIROUT()       P0DIR &= ~(BIT(2));P0PU |= (BIT(2));P3DIR |= (BIT(4));P3PU &= ~(BIT(4));P3PD&= ~(BIT(4))
#define SDADIRIN()        P0DIR |= (BIT(2));P0PU |= (BIT(2));P3DIR |= (BIT(4));P3PU &= ~(BIT(4));P3PD&= ~(BIT(4))

#define SCLDIROUT()        P0DIR &= ~(BIT(1));P0PU |= (BIT(1))
#define BK_CLK_HIGH()     P01=1
#define BK_CLK_LOW()      P01=0
#endif

#elif defined(IIC_GPIO_USE_P05_P02)

///IIC gpio P05 P02
#define iic_data_out()    P0DIR &= ~(BIT(2));P0PU |= BIT(2);P3DIR |= (BIT(4));P3PU &= ~(BIT(4));P3PD&= ~(BIT(4)) 	
#define iic_data_in()     P0DIR |= (BIT(2));P0PU |= BIT(2);P3DIR |= (BIT(4));P3PU &= ~(BIT(4));P3PD&= ~(BIT(4))	
#define iic_data_r()      P02
#define iic_data_h()      P02 = 1
#define iic_data_l()      P02 = 0

#define iic_clk_out()    P0DIR &= ~(BIT(5));P0PU |= (BIT(5))
#define iic_clk_h()      P05 = 1
#define iic_clk_l()      P05 = 0
#if 1	//for bk1080.h
#define BK_DATA_HIGH()   P02=1;
#define BK_DATA_LOW()    P02=0;
#define BK_DATA_READ()    P02
#define SDADIROUT()       P0DIR &= ~(BIT(2));P0PU |= (BIT(2));P3DIR |= (BIT(4));P3PU &= ~(BIT(4));P3PD&= ~(BIT(4))
#define SDADIRIN()        P0DIR |= (BIT(2));P0PU |= (BIT(2));P3DIR |= (BIT(4));P3PU &= ~(BIT(4));P3PD&= ~(BIT(4))

#define SCLDIROUT()        P0DIR &= ~(BIT(5));P0PU |= (BIT(5))
#define BK_CLK_HIGH()     P05=1
#define BK_CLK_LOW()      P05=0
#endif
#elif defined(IIC_GPIO_USE_P27_P26)
#define iic_data_out()    	DACCON0|=0x80;P2DIR &= ~(BIT(6));P2PU |= BIT(6) 	
#define iic_data_in()     	DACCON0|=0x80;P2DIR |= (BIT(6));P2PU |= BIT(6)	
#define iic_data_r()      	P26
#define iic_data_h()      	P26 = 1
#define iic_data_l()      	P26 = 0

#define iic_clk_out()    	DACCON0|=0x80;P2DIR &= ~(BIT(7));P2PU |= (BIT(7))
#define iic_clk_h()      	P27 = 1
#define iic_clk_l()      		P27 = 0
#if 1	//for bk1080.h
#define BK_DATA_HIGH()   	iic_data_h()
#define BK_DATA_LOW()    	iic_data_l()
#define BK_DATA_READ()    	iic_data_r()
#define SDADIROUT()       		iic_data_out()
#define SDADIRIN()        		iic_data_in()

#define SCLDIROUT()        		iic_clk_out()
#define BK_CLK_HIGH()     		iic_clk_h()
#define BK_CLK_LOW()      		iic_clk_l()

#endif
#elif defined(IIC_GPIO_USE_P24_P25)

#define iic_data_out()    DACCON0|=0x40;P2DIR &= ~(BIT(4));P2PU |= BIT(4) 	
#define iic_data_in()     DACCON0|=0x40;P2DIR |= (BIT(4));P2PU |= BIT(4)	
#define iic_data_r()      P24
#define iic_data_h()      P24 = 1
#define iic_data_l()      P24 = 0

#define iic_clk_out()    DACCON0|=0x40;P2DIR &= ~(BIT(5));P2PU |= (BIT(5))
#define iic_clk_h()      P25 = 1
#define iic_clk_l()      P25 = 0
#if 1	//for bk1080.h
#define BK_DATA_HIGH()   	iic_data_h()
#define BK_DATA_LOW()    	iic_data_l()
#define BK_DATA_READ()    	iic_data_r()
#define SDADIROUT()       		iic_data_out()
#define SDADIRIN()        		iic_data_in()

#define SCLDIROUT()        		iic_clk_out()
#define BK_CLK_HIGH()     		iic_clk_h()
#define BK_CLK_LOW()      		iic_clk_l()

#endif
#elif defined(IIC_GPIO_USE_P01_P00)
///IIC gpio P00 P01
#define iic_data_out()    P0DIR &= ~(BIT(0));P0PU |= BIT(0) 	
#define iic_data_in()     P0DIR |= (BIT(0));P0PU |= BIT(0)	
#define iic_data_r()      P00
#define iic_data_h()      P00 = 1
#define iic_data_l()      P00 = 0

#define iic_clk_out()    P0DIR &= ~(BIT(1));P0PU |= (BIT(1))
#define iic_clk_h()      P01 = 1
#define iic_clk_l()      P01 = 0
#if 1	//for bk1080.h
#define BK_DATA_HIGH()   	iic_data_h()
#define BK_DATA_LOW()    	iic_data_l()
#define BK_DATA_READ()    	iic_data_r()
#define SDADIROUT()       		iic_data_out()
#define SDADIRIN()        		iic_data_in()

#define SCLDIROUT()        		iic_clk_out()
#define BK_CLK_HIGH()     		iic_clk_h()
#define BK_CLK_LOW()      		iic_clk_l()

#endif
#else
//4  IIC gpio P00 P01
#define iic_data_out()    P0DIR &= ~(BIT(1));P0PU |= BIT(1) 	
#define iic_data_in()     P0DIR |= (BIT(1));P0PU |= BIT(1)	
#define iic_data_r()      P01
#define iic_data_h()      P01 = 1
#define iic_data_l()      P01 = 0

#define iic_clk_out()    P0DIR &= ~(BIT(0));P0PU |= (BIT(0))
#define iic_clk_h()      P00 = 1
#define iic_clk_l()      P00 = 0
#if 1	//for bk1080.h
#define BK_DATA_HIGH()   	iic_data_h()
#define BK_DATA_LOW()    	iic_data_l()
#define BK_DATA_READ()    	iic_data_r()
#define SDADIROUT()       		iic_data_out()
#define SDADIRIN()        		iic_data_in()

#define SCLDIROUT()        		iic_clk_out()
#define BK_CLK_HIGH()     		iic_clk_h()
#define BK_CLK_LOW()      		iic_clk_l()

#endif
#endif

//1 ac209 28pin

//key.h
#define ADC_KEY_IO     0x4f
#define ADC_VDD_12     0x48
#define ADC_LDOIN      0x49
#define ADC_AUDIO     0x4C
#define ADC_LINE_IN    0x4A	//p02

#if defined(TWO_ADKEY_ENABLE)
#define ADC_KEY_IO_2  0x4C
#endif

#define ADKEY_USE_P07_PORT

#if defined(ADC_DETECT_LINE_IN)
#define ADC_MAX_USED 0x04
#elif defined(CUSTOM_DEFINE_ADPORT_FOR_VOLUME_ADJ)
#define ADC_MAX_USED 0x04
#elif defined(TWO_ADKEY_ENABLE)
#define ADC_MAX_USED 0x04
#else
#define ADC_MAX_USED 0x03
#endif
//1 ac209 28pin

#ifdef USE_POWER_KEY

#if defined(PWR_CTRL_P24_KEY_P25)
#define GPIO_POWER_CTRL 	P24
#define power_ctl(n)  			DACCON0|=0x40;P2DIR &= ~(BIT(4));P2PU |= (BIT(4));GPIO_POWER_CTRL = n

#define GPIO_POWER_KEY   	P25

#define Pwr_Key_Init()		DACCON0|=0x40; P2DIR &=~(BIT(5));P2PU |= (BIT(5));GPIO_POWER_KEY =1;;P2DIR |= (BIT(5));P2PU &= ~(BIT(5));
#define Pwr_Key_output()		DACCON0|=0x40; P2DIR &=~(BIT(5));P2PU |= (BIT(5));GPIO_POWER_KEY =1;
#define Pwr_Key_input()		DACCON0|=0x40; P2DIR |= (BIT(5));P2PU &= ~(BIT(5));
#elif defined(PWR_CTRL_P25_KEY_P24)
#define GPIO_POWER_CTRL 	P25
#define power_ctl(n)  			DACCON0|=0x40;P2DIR &= ~(BIT(5));P2PU |= (BIT(5));GPIO_POWER_CTRL = n

#define GPIO_POWER_KEY   	P24

#define Pwr_Key_Init()		DACCON0|=0x40; P2DIR &=~(BIT(4));P2PU |= (BIT(4));GPIO_POWER_KEY =1;;P2DIR |= (BIT(4));P2PU &= ~(BIT(4));
#define Pwr_Key_output()		DACCON0|=0x40; P2DIR &=~(BIT(4));P2PU |= (BIT(4));GPIO_POWER_KEY =1;
#define Pwr_Key_input()		DACCON0|=0x40; P2DIR |= (BIT(4));P2PU &= ~(BIT(4));
#elif defined(PWR_CTRL_P27_KEY_P26)
#define GPIO_POWER_CTRL 	P27
#define power_ctl(n)  			DACCON0|=0x80;P2DIR &= ~(BIT(7));P2PU |= (BIT(7));GPIO_POWER_CTRL = n

#define GPIO_POWER_KEY   	P26

#define Pwr_Key_Init()		DACCON0|=0x80; P2DIR &=~(BIT(6));P2PU |= (BIT(6));GPIO_POWER_KEY =1;;P2DIR |= (BIT(6));P2PU &= ~(BIT(6));
#define Pwr_Key_output()		DACCON0|=0x80; P2DIR &=~(BIT(6));P2PU |= (BIT(6));GPIO_POWER_KEY =1;
#define Pwr_Key_input()		DACCON0|=0x80; P2DIR |= (BIT(6));P2PU &= ~(BIT(6));
#elif defined(USE_ONLY_POWER_HOLD_CTRL)

#if defined(PWR_CTRL_P02)
#define GPIO_POWER_CTRL 	P02
#define power_ctl(n)  			P0DIR &= ~(BIT(2));P0PU |= (BIT(2));P3DIR |= (BIT(4));P3PU &= ~(BIT(4));P3PD&= ~(BIT(4));GPIO_POWER_CTRL = n

#define Pwr_Key_Init()		
#define Pwr_Key_output()		
#define Pwr_Key_input()		

#define GPIO_POWER_KEY

#elif defined(PWR_CTRL_P17)
#define GPIO_POWER_CTRL 	P17
#define power_ctl(n)  			P1DIR &= ~(BIT(7));P1PU |= (BIT(7));GPIO_POWER_CTRL = n

#define Pwr_Key_Init()		
#define Pwr_Key_output()		
#define Pwr_Key_input()		

#define GPIO_POWER_KEY  
#else
#define GPIO_POWER_CTRL 	P26
#define power_ctl(n)  			DACCON0|=0x80;P2DIR &= ~(1<<6);P2PU |= (1<<6);GPIO_POWER_CTRL = n

#define Pwr_Key_Init()		
#define Pwr_Key_output()		
#define Pwr_Key_input()		

#define GPIO_POWER_KEY   	
#endif
#else
#define GPIO_POWER_CTRL 	P26
#define power_ctl(n)  			DACCON0|=0x80;P2DIR &= ~(1<<6);P2PU |= (1<<6);GPIO_POWER_CTRL = n

#define Pwr_Key_Init()		DACCON0|=0x80; P2DIR &=~(1<<7);P2PU |= (1<<7);P27 =1;;P2DIR |= (1<<7);P2PU &= ~(1<<7);
#define Pwr_Key_output()		DACCON0|=0x80; P2DIR &=~(1<<7);P2PU |= (1<<7);P27 =1;
#define Pwr_Key_input()		DACCON0|=0x80; P2DIR |= (1<<7);P2PU &= ~(1<<7);

#define GPIO_POWER_KEY   	P27

#endif

#endif


#ifdef USE_AMP_MODE_SELECT
#if defined(AMP_MODE_SELECT_PORT_USE_P02)
#define D_CLASS_AMP_GPIO_INIT()		P0DIR &= ~(BIT(2));P0PU |= (BIT(2));P3DIR |= (BIT(4));P3PU &= ~(BIT(4));P3PD&= ~(BIT(4))
#define D_CLASS_AMP_HIGH()				P0|=(BIT(2))
#define D_CLASS_AMP_LOW()				P0&=~(BIT(2))
#endif
#endif


#ifdef USE_CUSTOMIED_GPIO_KEY
#define  GPIO_KEY_INIT()      		P0DIR |= BIT(7);P0PU |=(BIT(7))
#define  GPIO_KEY_PORT  			P07
#endif
//1 ac209 28pin			end      end



#else
//1 ac209 48pin

// msgfor_hot.c
#if defined(MUTE_PORT_USE_DUMP)
#define SET_MUTE_PORT_DIR()		
#define SET_MUTE_PORT_PU() 			
#define MUTE_PORT_HIGH()			
#define MUTE_PORT_LOW()	
#elif defined( MUTE_PORT_USE_P01)
#define SET_MUTE_PORT_DIR()			P0DIR &= ~(BIT(1))
#define SET_MUTE_PORT_PU() 				P0PU |= BIT(1)
#define MUTE_PORT_HIGH()				P01  =MUTE_LEVEL
#define MUTE_PORT_LOW()				P01  =UNMUTE_LEVEL
#elif defined(MUTE_PORT_USE_WKUP)
//dummy
#elif defined(MUTE_PORT_USE_P00)
#define SET_MUTE_PORT_DIR()			P0DIR &= ~(BIT(0))
#define SET_MUTE_PORT_PU() 				P0PU |= (BIT(0))
#define MUTE_PORT_HIGH()				P00  =MUTE_LEVEL
#define MUTE_PORT_LOW()				P00  =UNMUTE_LEVEL
#elif defined(MUTE_PORT_USE_P03)
#define SET_MUTE_PORT_DIR()			P0DIR &= ~(BIT(3))
#define SET_MUTE_PORT_PU() 				P0PU |= (BIT(3))
#define MUTE_PORT_HIGH()				P03  =MUTE_LEVEL
#define MUTE_PORT_LOW()				P03  =UNMUTE_LEVEL
#elif defined(MUTE_PORT_USE_P04)
#define SET_MUTE_PORT_DIR()			P0DIR &= ~(BIT(4))
#define SET_MUTE_PORT_PU() 				P0PU |= (BIT(4))
#define MUTE_PORT_HIGH()				P04  =MUTE_LEVEL
#define MUTE_PORT_LOW()				P04  =UNMUTE_LEVEL
#elif defined(MUTE_PORT_USE_P17)
#define SET_MUTE_PORT_DIR()			P1DIR &= ~(BIT(7))
#define SET_MUTE_PORT_PU() 				P1PU |= (BIT(7))
#define MUTE_PORT_HIGH()				P17  =MUTE_LEVEL
#define MUTE_PORT_LOW()				P17  =UNMUTE_LEVEL
#endif


//LED.H
#if defined(EXTENDED_LED_SPECTURM)
#define led_com_out() P3DIR &= ~0x1F; 	P3PU |= 0x1F;P0DIR &=~(BIT(2));P0PU |= BIT(2)
#define led_seg_out() P1DIR &= ~0xFF;		P1PU |= 0xFF; 
#else
#define led_com_out() P3DIR &= ~0x1F; 	P3PU |= 0x1F;
#define led_seg_out() P1DIR &= ~0xFF;		P1PU |= 0xFF; 
#endif
#define LED_COM1   P30
#define LED_COM2   P31
#define LED_COM3   P32
#define LED_COM4   P33
#define LED_COM5   P34
#define LED_COM    P3
#define LED_SEG    P1
#if defined(EXTENDED_LED_SPECTURM)
#define LED_COM_EXTEND_ON()	 		P02 = 1
#define LED_COM_EXTEND_OFF()	 		P02 = 0
#endif
//1 ac209 48pin

//display_common.h
#if 0//def ADKEY_USE_P07_PORT
#define play_led_seg_out() 
#define PLAY_STATUS_PORT		P07

#define  EARPHONE_DETECT_GPIO  P07
#define  hp_detect_begin() 
#else

#if defined(K1028_WOKA_1028_APPLE_V001)||defined(INVERT_LED_IN_USE)
#define play_led_seg_out2() 	P0DIR &= ~(BIT(2));P0PU |= (BIT(2));
#define PLAY_STATUS_PORT2 	P02

#endif

#if defined(NEW_CUSTOMIZED_LED_METHOD)

#elif defined(PLAY_STATUS_LED_P04)
#define play_led_seg_out() 	P0DIR &= ~(BIT(4));P0PU |= BIT(4)
#define PLAY_STATUS_PORT 	P04
#elif defined(PLAY_STATUS_LED_P02)
#define play_led_seg_out() 	P0DIR &= ~(BIT(2));P0PU |= BIT(2)
#define PLAY_STATUS_PORT 	P02
#elif defined(PLAY_STATUS_LED_P05)
#define play_led_seg_out() 	P0DIR &= ~(BIT(5));P0PU |= BIT(5)
#define PLAY_STATUS_PORT 	P05
#elif defined(PLAY_STATUS_LED_P10)
#define play_led_seg_out() 	P1DIR &= ~(BIT(0));P1PU |= BIT(0)
#define PLAY_STATUS_PORT 	P10
#elif defined(PLAY_STATUS_LED_P01)
#define play_led_seg_out() 		P0DIR &= ~(BIT(1));P0PU |= BIT(1)
#define PLAY_STATUS_PORT 		P01
#ifdef IIC_GPIO_USE_P00_P01
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL
#endif
#elif defined(PLAY_STATUS_LED_P17)
#define play_led_seg_out() 	P1DIR &= ~(BIT(7));P1PU |= BIT(7)
#define PLAY_STATUS_PORT 	P17
#ifndef NO_LED_DISPLAY
#define PROTECT_P17_FROM_LED_SCAN
#endif
#elif defined(PLAY_STATUS_LED_P00)
#define play_led_seg_out() 	P0DIR &= ~(BIT(0));P0PU |= BIT(0)
#define PLAY_STATUS_PORT 	P00
#else

#if !defined(ADKEY_USE_P07_PORT)&&!defined(TWO_ADKEY_USE_PORT_P07)
#define play_led_seg_out() 	P0DIR &= ~0x80;P0PU |= BIT(7)
#define PLAY_STATUS_PORT 	P07
#else
#define NO_PLAY_STATUS_LED
#endif

#endif
//1 ac209 48pin

#if defined(EARPHONE_DETECT_USE_VPP)
#define  EARPHONE_DETECT_GPIO  	(WKUPPND&BIT(7))
#define  hp_detect_begin()   			WKUPPND|=BIT(6)
#define hp_detect_in_off()		
#define INDEPENDENT_EARPHONE_DETECT_GPIO
#define USE_IR_VPP_PORT_FOR_DETECTION
#elif defined(EARPHONE_DETECT_USE_P01)
#define  EARPHONE_DETECT_GPIO  		P01
#define  hp_detect_begin()   				P0DIR &=~(BIT(1));P01=1; P0DIR |= BIT(1);P0PU |= BIT(1)
#define  hp_detect_in_off()				P0DIR &=~(BIT(1));
#elif defined(EARPHONE_DETECT_USE_P02)
#define  EARPHONE_DETECT_GPIO  	P02
#define  hp_detect_begin()   			P0DIR |= (BIT(2))//P0PU |= (BIT(2)); 
#define hp_detect_in_off()			P0DIR &= ~(BIT(2))
#define INDEPENDENT_EARPHONE_DETECT_GPIO
#elif defined(EARPHONE_DETECT_USE_P34)
#define  EARPHONE_DETECT_GPIO  	P34
#define  hp_detect_begin()   			P3DIR |= (BIT(4))//P0PU |= (BIT(2)); 
#define hp_detect_in_off()			P3DIR &=~(BIT(4))
#define INDEPENDENT_EARPHONE_DETECT_GPIO
#elif defined(EARPHONE_DETECT_USE_P04)
#define  EARPHONE_DETECT_GPIO  	P04
#define  hp_detect_begin()   			P0DIR |= (BIT(4))//P0PU |= (BIT(2)); 
#define hp_detect_in_off()			P0DIR &=~(BIT(4))
#define INDEPENDENT_EARPHONE_DETECT_GPIO
#elif defined(EARPHONE_DETECT_USE_P03)
#define  EARPHONE_DETECT_GPIO  	P03
#define  hp_detect_begin()   			P0DIR |= (BIT(3));P0PU |= (BIT(3))
#define hp_detect_in_off()			P0DIR &=~(BIT(3))
#elif defined(EARPHONE_DETECT_USE_P11)
#define  EARPHONE_DETECT_GPIO  	P11
#define  hp_detect_begin()   			P1DIR |= (BIT(1));P1PU |= (BIT(1))
#define hp_detect_in_off()			P1DIR &=~(BIT(1))
#define INDEPENDENT_EARPHONE_DETECT_GPIO
#elif defined(EARPHONE_DETECT_USE_P17)
#define  EARPHONE_DETECT_GPIO  	P17
#define  hp_detect_begin()   			P1DIR |= (BIT(7));P1PU |= (BIT(7))
#define hp_detect_in_off()			P1DIR &=~(BIT(7))
#define INDEPENDENT_EARPHONE_DETECT_GPIO
#else
#if !defined(ADKEY_USE_P07_PORT)&&!defined(TWO_ADKEY_USE_PORT_P07)
#define  EARPHONE_DETECT_GPIO  	P07
#define  hp_detect_begin()   			P0DIR |= (BIT(7)); P0PU |= (BIT(7))
#define hp_detect_in_off()			P0DIR &=~(BIT(7))
#endif
#endif

#ifdef PLAY_STATUS_LED_SHARE_WITH_DET
#undef INDEPENDENT_EARPHONE_DETECT_GPIO
#endif
#endif
//main.c
//1 ac209 48pin
#ifdef AUX_DETECT_HIGH_LEVEL
#define  aux_detect_in()      		P0DIR &= ~(BIT(2)); P02=0; P0DIR |= BIT(2);P0PD|= BIT(2);//linein check port
#define  AUX_DETECT_GPIO  		P02
#define  aux_detect_in_off()        	P0DIR &= ~(BIT(2));P02=0;  //linein check port
#else

#if defined(K116_FXK_V001)||defined(K619_FXK_619_V001)||defined(AUX_DETECT_USE_P02)
#define  aux_detect_in()      		P0DIR &= ~(BIT(2)); P02=1; P0DIR |= BIT(2);P0PU |= BIT(2);//linein check port
#define  AUX_DETECT_GPIO  		P02
#define  aux_detect_in_off()        	P0DIR &= ~(BIT(2));P02=1;  //linein check port
#elif defined(AUX_DETECT_USE_VPP)
#define  AUX_DETECT_GPIO  		(((WKUPPND&BIT(7))>0)?1:0)
#define  aux_detect_in()   				WKUPPND|=BIT(6)
#define aux_detect_in_off()		
#define USE_IR_VPP_PORT_FOR_DETECTION
#elif defined(AUX_DETECT_USE_P34)
#define  aux_detect_in()      		P3DIR &= ~(BIT(4)); P34=1; P3DIR |= BIT(4);P3PU |= BIT(4);//linein check port
#define  AUX_DETECT_GPIO  		P34
#define  aux_detect_in_off()        	P3DIR &= ~(BIT(4));P34=1;  //linein check port
#define INDEPENDENT_AUX_DETECT_GPIO
#elif defined(AUX_DETECT_USE_P04)
#define  aux_detect_in()      		P0DIR &= ~(BIT(4)); P04=1; P0DIR |= BIT(4);P0PU |= BIT(4);//linein check port
#define  AUX_DETECT_GPIO  		P04
#define  aux_detect_in_off()        	P0DIR &= ~(BIT(4));P04=1;  //linein check port
#define INDEPENDENT_AUX_DETECT_GPIO
#elif defined(AUX_DETECT_USE_P03)
#define  aux_detect_in()      		P0DIR &= ~(BIT(3)); P03=1; P0DIR |= BIT(3);P0PU |= BIT(3);//linein check port
#define  AUX_DETECT_GPIO  		P03
#define  aux_detect_in_off()        	P0DIR &= ~(BIT(3));P03=1//;  //linein check port
#elif defined(AUX_DETECT_USE_P07)
#define  aux_detect_in()      		P0DIR |= BIT(7);P0PU |= BIT(7)//;//linein check port
#define  AUX_DETECT_GPIO  		P07
#define  aux_detect_in_off()        	P0DIR &= ~(BIT(7));P07=1 //linein check port
#elif defined(AUX_DETECT_USE_P06)
#define  aux_detect_in()      		P0DIR |= BIT(6);P0PU |= BIT(6);//linein check port
#define  AUX_DETECT_GPIO  		P06
#define  aux_detect_in_off()        	P0DIR &= ~(BIT(6));P06=1 //linein check port
#elif defined(AUX_DETECT_USE_P17)
#define  aux_detect_in()      		P1DIR |= BIT(7);P1PU |= BIT(7)//linein check port
#define  AUX_DETECT_GPIO  		P17
#define  aux_detect_in_off()        	P1DIR &= ~(BIT(7));P17=1 //linein check port
#define INDEPENDENT_AUX_DETECT_GPIO
#else
#define  aux_detect_in()      		P0DIR |= BIT(1);P0PU |= BIT(1);//linein check port
#define  AUX_DETECT_GPIO  		P01
#define  aux_detect_in_off()        	P0DIR &= ~(BIT(1));P01=1 //linein check port
#endif
#endif
//iic.h
//1 ac209 48pin
#if defined(IIC_GPIO_USE_P02_P03)
#define iic_data_out()    P0DIR &= ~(1<<2);P0PU |= (1<<2)
#define iic_data_in()     P0DIR |= (1<<2);P0PU |= (1<<2)
#define iic_data_r()      P02
#define iic_data_h()      P02 = 1
#define iic_data_l()      P02 = 0
#define iic_clk_out()    P0DIR &= ~(1<<3);P0PU |= (1<<3)
#define iic_clk_h()      P03 = 1
#define iic_clk_l()      P03 = 0
#if 1	//for bk1080.h
#define BK_DATA_HIGH()   P02=1;
#define BK_DATA_LOW()    P02=0;
#define BK_DATA_READ()    P02
#define SDADIROUT()       P0DIR &= ~(1<<2);P0PU |= (1<<2)
#define SDADIRIN()        P0DIR |= (1<<2);P0PU |= (1<<2)

#define SCLDIROUT()        P0DIR &= ~(1<<3);P0PU |= (1<<3)
#define BK_CLK_HIGH()     P03=1;
#define BK_CLK_LOW()      P03=0;
#endif
#elif defined(IIC_GPIO_USE_P01_P00)
#define iic_data_out()    P0DIR &= ~(BIT(0));P0PU |= BIT(0) 	
#define iic_data_in()     P0DIR |= (BIT(0));P0PU |= BIT(0)	
#define iic_data_r()      P00
#define iic_data_h()      P00 = 1
#define iic_data_l()      P00 = 0

#define iic_clk_out()    P0DIR &= ~(BIT(1));P0PU |= (BIT(1))
#define iic_clk_h()      P01= 1
#define iic_clk_l()      P01 = 0
#if 1	//for bk1080.h
#define BK_DATA_HIGH()   P00=1;
#define BK_DATA_LOW()    P00=0;
#define BK_DATA_READ()    P00
#define SDADIROUT()       P0DIR &= ~(BIT(0));P0PU |= (BIT(0))
#define SDADIRIN()        P0DIR |= (BIT(0));P0PU |= (BIT(0))

#define SCLDIROUT()        P0DIR &= ~(BIT(1));P0PU |= (BIT(1))
#define BK_CLK_HIGH()     P01=1
#define BK_CLK_LOW()      P01=0
#endif
#elif defined(IIC_GPIO_USE_P00_P01)
#define iic_data_out()    P0DIR &= ~(BIT(1));P0PU |= BIT(1) 	
#define iic_data_in()     P0DIR |= (BIT(1));P0PU |= BIT(1)	
#define iic_data_r()      P01
#define iic_data_h()      P01 = 1
#define iic_data_l()      P01 = 0

#define iic_clk_out()    P0DIR &= ~(BIT(0));P0PU |= (BIT(0))
#define iic_clk_h()      P00 = 1
#define iic_clk_l()      P00 = 0
#if 1	//for bk1080.h
#define BK_DATA_HIGH()   P01=1;
#define BK_DATA_LOW()    P01=0;
#define BK_DATA_READ()    P01
#define SDADIROUT()       P0DIR &= ~(BIT(1));P0PU |= (BIT(1))
#define SDADIRIN()        P0DIR |= (BIT(1));P0PU |= (BIT(1))

#define SCLDIROUT()        P0DIR &= ~(BIT(0));P0PU |= (BIT(0))
#define BK_CLK_HIGH()     P00=1
#define BK_CLK_LOW()      P00=0
#endif

#endif
//key.h
//1 ac209 48pin

#ifdef IPHONE_TX_USE_P06
#ifndef ADKEY_USE_P07_PORT
#define ADKEY_USE_P07_PORT
#endif
#endif

#if defined(ADKEY_USE_P07_PORT)
#define ADC_KEY_IO     0x4F
#elif defined(ADKEY_USE_P05_PORT)
#define ADC_KEY_IO  		0x4D//P04
#elif defined(ADKEY_USE_P04_PORT)
#define ADC_KEY_IO  		0x4C//P04
#else
#define ADC_KEY_IO     0x4e
#endif
#define ADC_VDD_12     0x48
#define ADC_LDOIN      0x49
#define ADC_AUDIO     0x4C

#if defined(TWO_ADKEY_ENABLE)
#if defined(TWO_ADKEY_USE_PORT_P07)
#define ADC_KEY_IO_2  0x4F
#elif defined(TWO_ADKEY_USE_PORT_P02)
#define ADC_KEY_IO_2  0x4A
#else
#define ADC_KEY_IO_2  0x4C//P04
#endif
#elif defined(CUSTOM_DEFINE_ADPORT_FOR_VOLUME_ADJ)
#define ADC_KEY_IO_2  0x4F
#endif

#if defined(BAT_MEASURE_USE_P04_PORT)
#define BAT_LEVEL_MEASURE_BY_GPIO
#define ADC_BAT_IO  		0x4C//P04
#elif defined(BAT_MEASURE_USE_P03_PORT)
#define BAT_LEVEL_MEASURE_BY_GPIO
#define ADC_BAT_IO  		0x4B//P04
#elif defined(BAT_MEASURE_USE_P02_PORT)
#define BAT_LEVEL_MEASURE_BY_GPIO
#define ADC_BAT_IO  		0x4A//P04
#endif

#if defined(AD_MEASURE_TEMP_FUNC)
#define ADC_TEMP_IO  		0x4A//P02
#define ADC_TEMP_IO_A  		0x4A//P02
#define ADC_TEMP_IO_B  		0x4B//P02
#endif


#define ADC_LINE_IN    0x4A	//p02

#if defined(ADC_DETECT_LINE_IN)
#define ADC_MAX_USED 0x04
#elif defined(AD_MEASURE_TEMP_FUNC)
#define ADC_MAX_USED 0x04
#elif defined(TWO_ADKEY_ENABLE)
#define ADC_MAX_USED 0x04
#elif defined(CUSTOM_DEFINE_ADPORT_FOR_VOLUME_ADJ)
#define ADC_MAX_USED 0x04
#else
#define ADC_MAX_USED 0x03
#endif
//1 ac209 48pin

#ifdef USE_POWER_KEY

#if defined(PWR_CTRL_P10_KEY_P04)
#define GPIO_POWER_CTRL 	P10
#define power_ctl(n)  			P1DIR &= ~(BIT(1));P1PU |= (BIT(1));GPIO_POWER_CTRL = n

#define GPIO_POWER_KEY   	P04
#define Pwr_Key_Init()		P0DIR |= (BIT(4));//P2PU |= (BIT(4));
#define Pwr_Key_output()		P0DIR &= ~(BIT(4));GPIO_POWER_KEY =1;//P2PU |= (BIT(4));GPIO_POWER_KEY =1;
#define Pwr_Key_input()		P0DIR |= (BIT(4));//P2PU |= (BIT(4));
//#define Pwr_Key_Input()		P2DIR &= ~(1<<6);
#elif defined(PWR_CTRL_WKUP)

#if defined(K000_XinLei_LC2092_V001)||defined(K000_XinLei_LC2092_V002)||defined(K000_XinLei_LC2092_V006)||defined(K000_XinLei_LC2092_V005)||defined(K000_XinLei_LC2092_V005_A8B)
#define GPIO_POWER_CTRL 	0
#define power_ctl(n)  			0

#define GPIO_POWER_KEY   	P01
#define Pwr_Key_Init()		P0DIR |= (BIT(1));P0PD |= (BIT(1));
#define Pwr_Key_output()		P0DIR &= ~(BIT(1));GPIO_POWER_KEY =0;//P2PU |= (BIT(4));GPIO_POWER_KEY =1;
#define Pwr_Key_input()		P0DIR |= (BIT(1));P0PD |= (BIT(1));
//#define Pwr_Key_Input()		P2DIR &= ~(1<<6);
#elif defined(K3031_AP_668_V001)
#define GPIO_POWER_CTRL 	0
#define power_ctl(n)  			0

#define GPIO_POWER_KEY   	P04
#define Pwr_Key_Init()		P0DIR |= (BIT(4));P0PD |= (BIT(4));
#define Pwr_Key_output()		P0DIR &= ~(BIT(4));GPIO_POWER_KEY =0;//P2PU |= (BIT(4));GPIO_POWER_KEY =1;
#define Pwr_Key_input()		P0DIR |= (BIT(4));P0PD |= (BIT(4));
#elif defined(PWR_CTRL_WKUP_POWER_ONLY)
#define GPIO_POWER_CTRL 	0
#define power_ctl(n)  			0

#define GPIO_POWER_KEY   	//P01
#define Pwr_Key_Init()		//P0DIR |= (BIT(1));P0PD |= (BIT(1));
#define Pwr_Key_output()		//P0DIR &= ~(BIT(1));GPIO_POWER_KEY =0;//P2PU |= (BIT(4));GPIO_POWER_KEY =1;
#define Pwr_Key_input()		//P0DIR |= (BIT(1));P0PD |= (BIT(1));
//#define Pwr_Key_Input()		P2DIR &= ~(1<<6);
#else
#define GPIO_POWER_CTRL 	0
#define power_ctl(n)  			0

#define GPIO_POWER_KEY   	P01
#define Pwr_Key_Init()		P0DIR |= (BIT(1));//P2PU |= (BIT(4));
#define Pwr_Key_output()		P0DIR &= ~(BIT(1));GPIO_POWER_KEY =1;//P2PU |= (BIT(4));GPIO_POWER_KEY =1;
#define Pwr_Key_input()		P0DIR |= (BIT(1));//P2PU |= (BIT(4));
//#define Pwr_Key_Input()		P2DIR &= ~(1<<6);
#endif

#elif defined(PWR_CTRL_P10_KEY_P02)
#define GPIO_POWER_CTRL 	P10
#define power_ctl(n)  			P1DIR &= ~(BIT(1));P1PU |= (BIT(1));GPIO_POWER_CTRL = n

#define GPIO_POWER_KEY   	P02
#define Pwr_Key_Init()		P0DIR |= (BIT(2));//P2PU |= (BIT(2));
#define Pwr_Key_output()		P0DIR &= ~(BIT(2));GPIO_POWER_KEY =1;//P2PU |= (BIT(2));
#define Pwr_Key_input()		P0DIR |= (BIT(2));//P2PU |= (BIT(2));
//#define Pwr_Key_Input()		P2DIR &= ~(1<<6);
#elif defined(PWR_CTRL_P02_KEY_P04)
#define GPIO_POWER_CTRL 	P02
#define power_ctl(n)  			P0DIR &= ~(BIT(2));P0PU |= (BIT(2));GPIO_POWER_CTRL = n

#define GPIO_POWER_KEY   	P04
#define Pwr_Key_Init()		P0DIR |= (BIT(4));//P2PU |= (BIT(4));
#define Pwr_Key_output()		P0DIR &= ~(BIT(4));GPIO_POWER_KEY =1;//P2PU |= (BIT(4));GPIO_POWER_KEY =1;
#define Pwr_Key_input()		P0DIR |= (BIT(4));//P2PU |= (BIT(4));
//#define Pwr_Key_Input()		P2DIR &= ~(1<<6);
#elif defined(PWR_CTRL_P04_KEY_P02)
#define GPIO_POWER_CTRL 	P04
#define power_ctl(n)  			P0DIR &= ~(BIT(4));P0PU |= (BIT(4));GPIO_POWER_CTRL = n

#define GPIO_POWER_KEY   	P02
#define Pwr_Key_Init()		P0DIR |= (BIT(2));//P2PU |= (BIT(2));
#define Pwr_Key_output()		P0DIR &= ~(BIT(2));GPIO_POWER_KEY =1;//P2PU |= (BIT(2));GPIO_POWER_KEY =1;
#define Pwr_Key_input()		P0DIR |= (BIT(2));//P2PU |= (BIT(2));
//#define Pwr_Key_Input()		P2DIR &= ~(1<<6);
#elif defined(USE_ONLY_POWER_HOLD_CTRL)

#if defined(PWR_CTRL_P02)
#define GPIO_POWER_CTRL 	P02
#define power_ctl(n)  			P0DIR &= ~(BIT(2));P0PU |= (BIT(2));GPIO_POWER_CTRL = n

#define Pwr_Key_Init()		
#define Pwr_Key_output()		
#define Pwr_Key_input()		

#define GPIO_POWER_KEY

#elif defined(PWR_CTRL_P04)
#define GPIO_POWER_CTRL 	P04
#define power_ctl(n)  			P0DIR &= ~(BIT(4));P0PU |= (BIT(4));GPIO_POWER_CTRL = n

#define Pwr_Key_Init()		
#define Pwr_Key_output()		
#define Pwr_Key_input()		

#define GPIO_POWER_KEY

#elif defined(PWR_CTRL_P17)
#define GPIO_POWER_CTRL 	P17
#define power_ctl(n)  			P1DIR &= ~(BIT(7));P1PU |= (BIT(7));GPIO_POWER_CTRL = n

#define Pwr_Key_Init()		
#define Pwr_Key_output()		
#define Pwr_Key_input()		

#define GPIO_POWER_KEY  

#elif defined(PWR_CTRL_P34)
#define GPIO_POWER_CTRL 	P34
#define power_ctl(n)  			P3DIR &= ~(BIT(4));P3PU |= (BIT(4));GPIO_POWER_CTRL = n

#define Pwr_Key_Init()		
#define Pwr_Key_output()		
#define Pwr_Key_input()		

#define GPIO_POWER_KEY  

#else
#define GPIO_POWER_CTRL 	P26
#define power_ctl(n)  			DACCON0|=0x80;P2DIR &= ~(1<<6);P2PU |= (1<<6);GPIO_POWER_CTRL = n

#define Pwr_Key_Init()		
#define Pwr_Key_output()		
#define Pwr_Key_input()		

#define GPIO_POWER_KEY   	
#endif
#else
#define GPIO_POWER_CTRL 	P26
#define power_ctl(n)  			P2DIR &= ~(1<<6);P2PU |= (1<<6);GPIO_POWER_CTRL = n

#define Pwr_Key_Init()		P2DIR |= (1<<7);P2PU |= (1<<6);
//#define Pwr_Key_Input()		P2DIR &= ~(1<<6);
#define GPIO_POWER_KEY   	P27
#endif
#endif


#ifdef USE_MICPHONE_GPIO_DETECTION

#if defined(MICPHONE_GPIO_DET_USE_P02)
#define MICPHONE_GPIO_INIT()			P0DIR |=(BIT(2));P0PU |=BIT(2)
#define MICPHONE_GPIO_READ			P02
#define MICPHONE_GPIO_RELEASE()		P0DIR &=~(BIT(2));P02=1
#elif defined(MICPHONE_GPIO_DET_USE_P17)
#define MICPHONE_GPIO_INIT()			P1DIR |=(BIT(7));P1PU |=BIT(7)
#define MICPHONE_GPIO_READ			P17
#define MICPHONE_GPIO_RELEASE()		P1DIR &=~(BIT(7));P17=1
#else
#define MICPHONE_GPIO_INIT()			P0DIR |=(BIT(4));P0PU |=BIT(4)
#define MICPHONE_GPIO_READ			P04
#define MICPHONE_GPIO_RELEASE()		P0DIR &=~(BIT(4));P04=1
#endif

#endif

#ifdef USE_BT_GPIO_DETECTION

#if defined(BT_GPIO_DETECTION_USE_PORT_P15)
#define BT_GPIO_INIT()				P1DIR |=(BIT(5));P1PU &=~(BIT(5))
#define BT_GPIO_READ				P15
#define BT_GPIO_RELEASE()			P1DIR &=~(BIT(5));P15=1
#elif defined(BT_GPIO_DETECTION_USE_PORT_P33)
#define BT_GPIO_INIT()				P3DIR |=(BIT(3));P3PU &=~(BIT(3))
#define BT_GPIO_READ				P33
#define BT_GPIO_RELEASE()			P3DIR &=~(BIT(3));P33=1
#else
#define BT_GPIO_INIT()				P3DIR |=(BIT(1));P3PU &=~(BIT(1));P3PD |=BIT(1)
#define BT_GPIO_READ				P31
#define BT_GPIO_RELEASE()			P3DIR &=~(BIT(1));P31=1
#endif
#endif

#if defined(BAT_LEVEL_GPIO_DRV_LED_IND)
#define BAT_LEVEL_LED_INIT()	P0DIR &= ~(BIT(3)|BIT(7));P0PU |= (BIT(3)|BIT(7))

#define BAT_LEVEL_LED_1_H()		P03=0
#define BAT_LEVEL_LED_1_L()		P03=1

#define BAT_LEVEL_LED_2_H()		P07=0
#define BAT_LEVEL_LED_2_L()		P07=1
#endif


#if defined(USE_LINE_IN_GPIO_SEL_MODE)
#define AUX_GPIO_INIT()				P0DIR |=(BIT(4));P0PU |=(BIT(4))
#define AUX_GPIO_READ				P04
#endif


#ifdef USE_CUSTOMIED_GPIO_KEY
#if defined(K0000_XP_TN891_V001)
#define  GPIO_KEY_INIT()      		P1DIR |=(BIT(0)| BIT(1)| BIT(2));P1PU |=(BIT(0)| BIT(1)| BIT(2))
#define  GPIO_KEY_1_PORT  		P10
#define  GPIO_KEY_2_PORT  		P11
#define  GPIO_KEY_3_PORT  		P12
#endif
#endif


#endif

#if defined(USE_BT_GPIO_SEL_MODE)
#if defined(USE_BT_GPIO_SEL_MODE_USE_PORT_P15)
#define BT_GPIO_SEL_INIT()				P1DIR |=(BIT(5));P1PU |=(BIT(5))
#define BT_GPIO_SEL_READ				P15
#define BT_GPIO_SEL_END()				P1DIR &= ~(BIT(5));P1PU &= ~(BIT(5));P15 =0
#else
#define BT_GPIO_SEL_INIT()				P0DIR |=(BIT(5));P0PU |=(BIT(5))
#define BT_GPIO_SEL_READ				P05
#define BT_GPIO_SEL_END()				P0DIR &= ~(BIT(5));P0PU &= ~(BIT(5));P0PD|=BIT(5);P05 =0
#endif
#endif

#ifdef USE_AMP_MODE_SELECT

#ifdef HI_AB_LOW_D_CLASS_LEVEL
#define AB_CLASS_LEVEL		1
#define D_CLASS_LEVEL		0
#else
#define AB_CLASS_LEVEL		0
#define D_CLASS_LEVEL		1
#endif

#if defined(AMP_MODE_SELECT_PORT_USE_P04)
#define D_CLASS_AMP_GPIO_INIT()			P0DIR &= ~(BIT(4));P0PU |=BIT(4);
#define D_CLASS_AMP_HIGH()					P04=D_CLASS_LEVEL
#define D_CLASS_AMP_LOW()					P04=AB_CLASS_LEVEL
#elif defined(AMP_MODE_SELECT_PORT_USE_P05)
#define D_CLASS_AMP_GPIO_INIT()			P0DIR &= ~(BIT(5));P0PU |=BIT(5);
#define D_CLASS_AMP_HIGH()					P05=D_CLASS_LEVEL
#define D_CLASS_AMP_LOW()					P05=AB_CLASS_LEVEL
#elif defined(AMP_MODE_SELECT_PORT_USE_P34)
#define D_CLASS_AMP_GPIO_INIT()			P3DIR &= ~(BIT(4));P3PU |=BIT(4)
#define D_CLASS_AMP_HIGH()					P34=D_CLASS_LEVEL
#define D_CLASS_AMP_LOW()					P34=AB_CLASS_LEVEL
#elif defined(AMP_MODE_SELECT_PORT_USE_P17)
#define D_CLASS_AMP_GPIO_INIT()			P1DIR &= ~(BIT(7));P1PU |=BIT(7);
#define D_CLASS_AMP_HIGH()					P17=D_CLASS_LEVEL
#define D_CLASS_AMP_LOW()					P17=AB_CLASS_LEVEL
#elif defined(AMP_MODE_SELECT_PORT_USE_P10)
#define D_CLASS_AMP_GPIO_INIT()			P1DIR &= ~(BIT(0));P1PU |=BIT(0);
#define D_CLASS_AMP_HIGH()					P10=D_CLASS_LEVEL
#define D_CLASS_AMP_LOW()					P10=AB_CLASS_LEVEL
#else
#define D_CLASS_AMP_GPIO_INIT()			P0DIR &= ~(BIT(7));P0PU |=BIT(7);
#define D_CLASS_AMP_HIGH()					P07=D_CLASS_LEVEL
#define D_CLASS_AMP_LOW()					P07=AB_CLASS_LEVEL
#endif
#endif


#ifdef BLUETOOTH_GPIO_CTRL

#if defined( K000_XingChuang_x821_V002)
#define BT_PWR_PORT_INIT() 		P3DIR &= ~(BIT(2));P3PU |=BIT(2)
#define BT_PWR_ON() 			P32 =1
#define BT_PWR_OFF() 			P32 =0

#define BT_RST_PORT_INIT() 		P3DIR &= ~(BIT(0));P3PU |=BIT(0);
#define BT_RST_ON() 				P30 =1
#define BT_RST_OFF() 			P30 =0

#define BT_PP_PORT_INIT() 		P1DIR &= ~(BIT(7));P1PU |=BIT(7);P17 =0
#define BT_PP_ON() 				P17 =1
#define BT_PP_OFF() 				P17 =0

#define BT_NEXT_PORT_INIT() 		P1DIR &= ~(BIT(3));P1PU |=BIT(3);P13 =0
#define BT_NEXT_ON() 				P13 =1
#define BT_NEXT_OFF() 				P13 =0

#define BT_PREV_PORT_INIT() 		P1DIR &= ~(BIT(4));P1PU |=BIT(4);P14 =0
#define BT_PREV_ON() 				P14 =1
#define BT_PREV_OFF() 				P14 =0

#define BT_VOLU_PORT_INIT() 		P1DIR &= ~(BIT(6));P1PU |=BIT(6);P16 =0
#define BT_VOL_UP_ON() 				P16 =1
#define BT_VOL_UP_OFF() 			P16 =0

#define BT_VOLD_PORT_INIT() 		P1DIR &= ~(BIT(5));P1PU |=BIT(5);P15 =0
#define BT_VOL_DOWN_ON() 			P15 =1
#define BT_VOL_DOWN_OFF() 			P15 =0

#elif defined(K000_JK_LBR_BT_V001)
#define BT_PWR_PORT_INIT() 			P0DIR &= ~(BIT(2));P0PU |= (BIT(2));P3DIR |= (BIT(4));P3PU &= ~(BIT(4));P3PD&= ~(BIT(4))
#define BT_PWR_ON() 				P02 =1
#define BT_PWR_OFF() 				P02 =0	

#define BT_RST_PORT_INIT() 		
#define BT_RST_ON() 				
#define BT_RST_OFF() 			

#define BT_PP_PORT_INIT() 			//P1DIR &= ~(BIT(0));P1PU |=BIT(0);P10 =0
#define BT_PP_ON() 					//P10 =1
#define BT_PP_OFF() 					//P10 =0

#define BT_NEXT_PORT_INIT() 		//P1DIR &= ~(BIT(1));P1PU |=BIT(1);P11 =0
#define BT_NEXT_ON() 				//P11 =1
#define BT_NEXT_OFF() 				//P11 =0

#define BT_PREV_PORT_INIT() 		//P1DIR &= ~(BIT(2));P1PU |=BIT(2);P12 =0
#define BT_PREV_ON() 				//P12 =1
#define BT_PREV_OFF() 				//P12 =0

#define BT_VOLU_PORT_INIT() 		
#define BT_VOL_UP_ON() 				
#define BT_VOL_UP_OFF() 			

#define BT_VOLD_PORT_INIT() 		
#define BT_VOL_DOWN_ON() 			
#define BT_VOL_DOWN_OFF() 	

#define BT_CONFIG_PORT_INIT() 			
#define BT_CONFIG_ON() 					
#define BT_CONFIG_OFF() 				
#elif defined(K015_SW_005B_V001)
#define BT_PWR_PORT_INIT() 			P0DIR |= (BIT(7));P0PU &= ~(BIT(7));P07 =1
#define BT_PWR_ON() 				P0DIR &= ~(BIT(7));	P07 =0
#define BT_PWR_OFF() 				P0DIR |= (BIT(7));	P07 =1

#define BT_RST_PORT_INIT() 		
#define BT_RST_ON() 				
#define BT_RST_OFF() 			

#define BT_PP_PORT_INIT() 			P0DIR &= ~(BIT(4));P0PU |=BIT(4);P04 =0
#define BT_PP_ON() 					P04 =1
#define BT_PP_OFF() 					P04 =0

#define BT_NEXT_PORT_INIT() 		P0DIR &= ~(BIT(2));P0PU |=BIT(2);P02 =0
#define BT_NEXT_ON() 				P02 =1
#define BT_NEXT_OFF() 				P02 =0

#define BT_PREV_PORT_INIT() 		P3DIR &= ~(BIT(4));P3PU |=BIT(4);P34 =0
#define BT_PREV_ON() 				P34=1
#define BT_PREV_OFF() 				P34 =0

#define BT_VOLU_PORT_INIT() 		
#define BT_VOL_UP_ON() 				
#define BT_VOL_UP_OFF() 			

#define BT_VOLD_PORT_INIT() 		
#define BT_VOL_DOWN_ON() 			
#define BT_VOL_DOWN_OFF() 	

#define BT_CONFIG_PORT_INIT() 			
#define BT_CONFIG_ON() 					
#define BT_CONFIG_OFF() 
#elif defined(K000_XC_BC_BT_V001)
#define BT_PWR_PORT_INIT() 			P3DIR &= ~(BIT(0)|BIT(1)|BIT(2));P3PU &= ~(BIT(0)|BIT(1)|BIT(2));P30=1;P31=1;P32=1;
#define BT_PWR_ON() 				P30=1;P31=1;P32=0;delay_10ms(90);P30=1;P31=1;P32=1;
#define BT_PWR_OFF() 				P30=0;P31=0;P32=0;delay_10ms(25);P30=1;P31=1;P32=1;

#define BT_RST_PORT_INIT() 		
#define BT_RST_ON() 				
#define BT_RST_OFF() 			

#define BT_PP_PORT_INIT() 			P3DIR &= ~(BIT(2));P3PU |=BIT(2);P32=1
#define BT_PP_ON() 					P32=0
#define BT_PP_OFF() 					P32=1

#define BT_NEXT_PORT_INIT() 		P3DIR &= ~(BIT(0));P3PU |=BIT(0);P30 =1
#define BT_NEXT_ON() 				P30 =0
#define BT_NEXT_OFF() 				P30 =1

#define BT_PREV_PORT_INIT() 		P3DIR &= ~(BIT(1));P3PU |=BIT(1);P31 =1
#define BT_PREV_ON() 				P31=0
#define BT_PREV_OFF() 				P31=1

#define BT_VOLU_PORT_INIT() 		
#define BT_VOL_UP_ON() 				
#define BT_VOL_UP_OFF() 			

#define BT_VOLD_PORT_INIT() 		
#define BT_VOL_DOWN_ON() 			
#define BT_VOL_DOWN_OFF() 	

#define BT_CONFIG_PORT_INIT() 		P3DIR &= ~(BIT(0)|BIT(1)|BIT(2));P3PU &= ~(BIT(0)|BIT(1)|BIT(2));P30=1;P31=1;P32=1;
#define BT_CONFIG_ON() 				P30=0;P31=0;P32=1;delay_10ms(25);P30=1;P31=1;P32=1;delay_10ms(25);
#define BT_CONFIG_OFF() 			P30=1;P31=1;P32=1;	


#define BT_MUTE_DETECT_INIT()		P1DIR |=(BIT(4));P1PU |=(BIT(4));
#define BT_MUTE_DETECT_PORT		P14==0
#define BT_MUTE_DETECT_RELEASE()	P1DIR &= ~(BIT(4));P14=1


#define BT_STATUS_DETECT_INIT()		P1DIR |=(BIT(6));P1PU |=(BIT(6));
#define BT_STATUS_DETECT_PORT			P16
#define BT_STATUS_DETECT_RELEASE()	P1DIR &= ~(BIT(6));P16=1

#define BT_STATUS_DETECT_INIT_2()		P1DIR |=(BIT(7));P1PU |=(BIT(7));
#define BT_STATUS_DETECT_PORT_2			P17
#define BT_STATUS_DETECT_RELEASE_2()	P1DIR &= ~(BIT(7));P17=1

#elif defined(K0000_MY_FT18_BT_V001)

#define BT_PWR_PORT_INIT() 			P1DIR &= ~(BIT(3));P1PU &= ~(BIT(3));P13 =0
#define BT_PWR_ON() 				P13 =1
#define BT_PWR_OFF() 				P13 =0	

#define BT_RST_PORT_INIT() 		
#define BT_RST_ON() 				
#define BT_RST_OFF() 			

#define BT_PP_PORT_INIT() 			P1DIR &= ~(BIT(0));P1PU |=BIT(0);P10 =0
#define BT_PP_ON() 					P10 =1
#define BT_PP_OFF() 					P10 =0

#define BT_NEXT_PORT_INIT() 		P1DIR &= ~(BIT(1));P1PU |=BIT(1);P11 =0
#define BT_NEXT_ON() 				P11 =1
#define BT_NEXT_OFF() 				P11 =0

#define BT_PREV_PORT_INIT() 		P1DIR &= ~(BIT(2));P1PU |=BIT(2);P12 =0
#define BT_PREV_ON() 				P12 =1
#define BT_PREV_OFF() 				P12 =0

#define BT_VOLU_PORT_INIT() 		
#define BT_VOL_UP_ON() 				
#define BT_VOL_UP_OFF() 			

#define BT_VOLD_PORT_INIT() 		
#define BT_VOL_DOWN_ON() 			
#define BT_VOL_DOWN_OFF() 	

#elif defined(K0000_ZG_BT260_V001)

#define BT_PWR_PORT_INIT() 			P1DIR &= ~(BIT(3));P1PU &= ~(BIT(3));P13=0
#define BT_PWR_ON() 				P13 =1
#define BT_PWR_OFF() 				P13 =0

#define BT_RST_PORT_INIT() 		
#define BT_RST_ON() 				
#define BT_RST_OFF() 			

#define BT_PP_PORT_INIT() 		
#define BT_PP_ON() 				
#define BT_PP_OFF() 				

#define BT_NEXT_PORT_INIT() 		
#define BT_NEXT_ON() 				
#define BT_NEXT_OFF() 				

#define BT_PREV_PORT_INIT() 		
#define BT_PREV_ON() 				
#define BT_PREV_OFF() 				

#define BT_VOLU_PORT_INIT() 		
#define BT_VOL_UP_ON() 				
#define BT_VOL_UP_OFF() 			

#define BT_VOLD_PORT_INIT() 		
#define BT_VOL_DOWN_ON() 			
#define BT_VOL_DOWN_OFF() 			

#elif defined(K2094_DYT_2094_V001)

#define BT_PWR_PORT_INIT() 			//P0DIR &= ~(BIT(2));P0PU &= ~(BIT(2));P02=0
#define BT_PWR_ON() 				//P02 =1
#define BT_PWR_OFF() 				//P02 =0

#define BT_RST_PORT_INIT() 		
#define BT_RST_ON() 				
#define BT_RST_OFF() 			

#define BT_PP_PORT_INIT() 			P3DIR &= ~(BIT(4));P3PU &= ~(BIT(4));P34=0
#define BT_PP_ON() 					P34 =1
#define BT_PP_OFF() 					P34 =0

#define BT_NEXT_PORT_INIT() 		P0DIR &= ~(BIT(4));P0PU &= ~(BIT(4));P04=0
#define BT_NEXT_ON() 				P04 =1
#define BT_NEXT_OFF() 				P04 =0

#define BT_PREV_PORT_INIT() 		P0DIR &= ~(BIT(7));P0PU &= ~(BIT(7));P07=0
#define BT_PREV_ON() 				P07 =1
#define BT_PREV_OFF() 				P07 =0

#define BT_VOLU_PORT_INIT() 		
#define BT_VOL_UP_ON() 				
#define BT_VOL_UP_OFF() 			

#define BT_VOLD_PORT_INIT() 		
#define BT_VOL_DOWN_ON() 			
#define BT_VOL_DOWN_OFF() 			

#elif defined(K000_ZG_HA8919_BT_V001)
#define BT_PWR_PORT_INIT() 			P0DIR &= ~(BIT(5));P0PU &= ~(BIT(5));P05 =0
#define BT_PWR_ON() 				P05 =1
#define BT_PWR_OFF() 				P05 =0

#define BT_RST_PORT_INIT() 		
#define BT_RST_ON() 				
#define BT_RST_OFF() 			

#define BT_PP_PORT_INIT() 		
#define BT_PP_ON() 				
#define BT_PP_OFF() 				

#define BT_NEXT_PORT_INIT() 		
#define BT_NEXT_ON() 				
#define BT_NEXT_OFF() 				

#define BT_PREV_PORT_INIT() 		
#define BT_PREV_ON() 				
#define BT_PREV_OFF() 				

#define BT_VOLU_PORT_INIT() 		
#define BT_VOL_UP_ON() 				
#define BT_VOL_UP_OFF() 			

#define BT_VOLD_PORT_INIT() 		
#define BT_VOL_DOWN_ON() 			
#define BT_VOL_DOWN_OFF() 	

#define BT_CONFIG_PORT_INIT() 			
#define BT_CONFIG_ON() 					
#define BT_CONFIG_OFF() 	

#elif defined(K0000_JK_KHT_842_BT_V001)
#define BT_PWR_PORT_INIT() 			
#define BT_PWR_ON() 				
#define BT_PWR_OFF() 				

#define BT_RST_PORT_INIT() 		
#define BT_RST_ON() 				
#define BT_RST_OFF() 			

#define BT_PP_PORT_INIT() 			//P1DIR &= ~(BIT(0));P1PU |=BIT(0);P10 =0
#define BT_PP_ON() 					//P10 =1
#define BT_PP_OFF() 					//P10 =0

#define BT_NEXT_PORT_INIT() 		P1DIR &= ~(BIT(2));P1PU |=BIT(2);P12 =0
#define BT_NEXT_ON() 				P12 =1
#define BT_NEXT_OFF() 				P12 =0

#define BT_PREV_PORT_INIT() 		P1DIR &= ~(BIT(3));P1PU |=BIT(3);P13 =0
#define BT_PREV_ON() 				P13 =1
#define BT_PREV_OFF() 				P13 =0

#define BT_VOLU_PORT_INIT() 		
#define BT_VOL_UP_ON() 				
#define BT_VOL_UP_OFF() 			

#define BT_VOLD_PORT_INIT() 		
#define BT_VOL_DOWN_ON() 			
#define BT_VOL_DOWN_OFF() 	

#define BT_CONFIG_PORT_INIT() 			P1DIR &= ~(BIT(6));P1PU &= ~(BIT(6));P16 =0
#define BT_CONFIG_ON() 					P16 =1
#define BT_CONFIG_OFF() 				P16 =0	

#elif defined(K2078_MY_2078_V001)
#define BT_PWR_PORT_INIT() 			P1DIR &= ~(BIT(3));P1PU &= ~(BIT(3));P13 =0
#define BT_PWR_ON() 				P13 =1
#define BT_PWR_OFF() 				P13 =0	

#define BT_RST_PORT_INIT() 		
#define BT_RST_ON() 				
#define BT_RST_OFF() 			

#define BT_PP_PORT_INIT() 		P1DIR &= ~(BIT(0));P1PU |=BIT(0);P10 =0
#define BT_PP_ON() 				P10 =1
#define BT_PP_OFF() 				P10 =0

#define BT_NEXT_PORT_INIT() 		P1DIR &= ~(BIT(2));P1PU |=BIT(2);P12 =0
#define BT_NEXT_ON() 				P12 =1
#define BT_NEXT_OFF() 				P12 =0

#define BT_PREV_PORT_INIT() 		P1DIR &= ~(BIT(1));P1PU |=BIT(1);P11 =0
#define BT_PREV_ON() 				P11 =1
#define BT_PREV_OFF() 				P11 =0

#define BT_VOLU_PORT_INIT() 		
#define BT_VOL_UP_ON() 				
#define BT_VOL_UP_OFF() 			

#define BT_VOLD_PORT_INIT() 		
#define BT_VOL_DOWN_ON() 			
#define BT_VOL_DOWN_OFF() 	

#elif defined(K000_JK_BTONLY_V001)
#define BT_PWR_PORT_INIT() 		P0DIR |=~ (BIT(2));P0PU &=~(BIT(2));P3DIR &=~(BIT(4));P3PU |=(BIT(4));P3PD&= ~(BIT(4));
#define BT_PWR_ON() 			P34 =1
#define BT_PWR_OFF() 			P34 =0

#define BT_RST_PORT_INIT() 		
#define BT_RST_ON() 				
#define BT_RST_OFF() 			

#define BT_PP_PORT_INIT() 		
#define BT_PP_ON() 				
#define BT_PP_OFF() 				

#define BT_NEXT_PORT_INIT() 		
#define BT_NEXT_ON() 				
#define BT_NEXT_OFF() 				

#define BT_PREV_PORT_INIT() 		
#define BT_PREV_ON() 				
#define BT_PREV_OFF() 				

#define BT_VOLU_PORT_INIT() 		
#define BT_VOL_UP_ON() 				
#define BT_VOL_UP_OFF() 			

#define BT_VOLD_PORT_INIT() 		
#define BT_VOL_DOWN_ON() 			
#define BT_VOL_DOWN_OFF() 	

#define BT_MUTE_DETECT_INIT()		P0DIR |=(BIT(7));P0PU |=(BIT(7));
#define BT_MUTE_DETECT_PORT		P07==1
#define BT_MUTE_DETECT_RELEASE()	P0DIR &= ~(BIT(7));P07=1

#elif defined(K000_QG_Q6_V001)
#define BT_PWR_PORT_INIT() 		P0DIR &= ~(BIT(2));P0PU |=(BIT(2));P3DIR |=(BIT(4));P3PU &= ~(BIT(4));P3PD&= ~(BIT(4));
#define BT_PWR_ON() 			P02 =1
#define BT_PWR_OFF() 			P02 =0

#define BT_RST_PORT_INIT() 		
#define BT_RST_ON() 				
#define BT_RST_OFF() 			

#define BT_PP_PORT_INIT() 		P0DIR &= ~(BIT(5));P0PU |=BIT(5);P05 =0
#define BT_PP_ON() 				P05 =1
#define BT_PP_OFF() 				P05 =0

#define BT_NEXT_PORT_INIT() 		
#define BT_NEXT_ON() 				
#define BT_NEXT_OFF() 				

#define BT_PREV_PORT_INIT() 		
#define BT_PREV_ON() 				
#define BT_PREV_OFF() 				

#define BT_VOLU_PORT_INIT() 		
#define BT_VOL_UP_ON() 				
#define BT_VOL_UP_OFF() 			

#define BT_VOLD_PORT_INIT() 		
#define BT_VOL_DOWN_ON() 			
#define BT_VOL_DOWN_OFF() 					
#else
#define BT_PWR_PORT_INIT() 		P3DIR &= ~(BIT(4));P3PU |=BIT(4)
#define BT_PWR_ON() 			P34 =1
#define BT_PWR_OFF() 			P34 =0

#define BT_RST_PORT_INIT() 		P1DIR &= ~(BIT(0));P1PU |=BIT(0);
#define BT_RST_ON() 				P10 =1
#define BT_RST_OFF() 			P10 =0

#define BT_PP_PORT_INIT() 		P1DIR &= ~(BIT(1));P1PU |=BIT(1);P11 =0
#define BT_PP_ON() 				P11 =1
#define BT_PP_OFF() 				P11 =0

#define BT_NEXT_PORT_INIT() 		P1DIR &= ~(BIT(3));P1PU |=BIT(3);P13 =0
#define BT_NEXT_ON() 				P13 =1
#define BT_NEXT_OFF() 				P13 =0

#define BT_PREV_PORT_INIT() 		P1DIR &= ~(BIT(2));P1PU |=BIT(2);P12 =0
#define BT_PREV_ON() 				P12 =1
#define BT_PREV_OFF() 				P12 =0

#define BT_VOLU_PORT_INIT() 		P1DIR &= ~(BIT(2));P1PU |=BIT(2);P12 =0
#define BT_VOL_UP_ON() 				P12 =1
#define BT_VOL_UP_OFF() 			P12 =0

#define BT_VOLD_PORT_INIT() 		P1DIR &= ~(BIT(2));P1PU |=BIT(2);P12 =0
#define BT_VOL_DOWN_ON() 			P12 =1
#define BT_VOL_DOWN_OFF() 			P12 =0
#endif
#endif

#if defined(DC_CHARGE_GPIO_DRV_LED_IND)||defined(DC_CHARGE_GPIO_DRV_LED_IND_2)
#if defined(DC_CHARGE_GPIO_DRV_LED_P00)
#define DC_CHARGE_LED_INIT()	P0DIR &= ~(BIT(0));P0PU |= (BIT(0))
#define DC_CHARGE_LED_H()		P00=1
#define DC_CHARGE_LED_L()		P00=0
#elif defined(DC_CHARGE_GPIO_DRV_LED_VPP)
#define DC_CHARGE_LED_INIT()	WKUPPND&=~(BIT(6))
#define DC_CHARGE_LED_H()		WKUPPND|=BIT(6)
#define DC_CHARGE_LED_L()		WKUPPND&=~(BIT(6))
#elif defined(DC_CHARGE_GPIO_DRV_LED_P07)
#define DC_CHARGE_LED_INIT()	P0DIR &= ~(BIT(7));P0PU |= (BIT(7))
#define DC_CHARGE_LED_H()		P07=1
#define DC_CHARGE_LED_L()		P07=0
#elif defined(DC_CHARGE_GPIO_DRV_LED_P05)
#define DC_CHARGE_LED_INIT()	P0DIR &= ~(BIT(5));P0PU |= (BIT(5))
#define DC_CHARGE_LED_H()		P05=1
#define DC_CHARGE_LED_L()		P05=0
#define DISABLE_P05_OSC_OUTPUT
#elif defined(DC_CHARGE_GPIO_DRV_LED_P10)
#define DC_CHARGE_LED_INIT()	P1DIR &= ~(BIT(0));P1PU |= (BIT(0))
#define DC_CHARGE_LED_H()		P10=1
#define DC_CHARGE_LED_L()		P10=0	
#elif defined(DC_CHARGE_GPIO_DRV_LED_P13)
#define DC_CHARGE_LED_INIT()	P1DIR &= ~(BIT(3));P1PU |= (BIT(3))
#define DC_CHARGE_LED_H()		P13=1
#define DC_CHARGE_LED_L()		P13=0	
#else
#define DC_CHARGE_LED_INIT()	DACCON0|=0x80;P0DIR &= ~(1<<2);P0PU |= (1<<2); P3DIR |= (1<<4);P3PU &= ~(1<<4);P3PD&= ~(1<<4)
#define DC_CHARGE_LED_H()		P02=1
#define DC_CHARGE_LED_L()		P02=0	
#endif
#endif

#ifdef USB_SD_PORTABLE_BAT_CHARGER

#define BATT_CHARGER_PORT_INIT()	P1DIR &=~(BIT(6)|BIT(7));P17=0;P16=0; P1DIR |=(BIT(6)|BIT(7));P1PU&=~(BIT(6)|BIT(7))
#define BATT_CHRG_PORT				P17
#define BATT_STBY_PORT				P16

#define OUTPUT_CHARGER_PORT_INIT()	P1DIR &=~(BIT(4));P14=0;P1DIR |=(BIT(4));P1PU &=~(BIT(4));P1PDA&=~(BIT(4))
#define OUTPUT_CHRG_PORT_EN()			P0DIR &=~(BIT(3));P03=1
#define OUTPUT_CHRG_PORT_DIS()			P0DIR &=~(BIT(3));P03=0
#define OUTPUT_STBY_PORT				P14

#define OUTPUT_DEVICE_PORT_INIT()		P1DIR &=~(BIT(5));P15=0;P1DIR |=(BIT(5));P1PU &=~(BIT(5));P1PDA&=~(BIT(5))
#define OUTPUT_DEVICE_PORT				P15

#endif

#endif


