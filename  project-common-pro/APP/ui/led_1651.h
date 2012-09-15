#ifndef _LED_H_
#define	_LED_H_

#include "Custom_config.h"

#ifdef __C51__

 
#endif


#include "gpio_config.h"


#define LED_A   	0
#define LED_B	1
#define LED_C	2
#define LED_D	3
#define LED_E	4
#define LED_F	5
#define LED_G	6
#define LED_H	7

#if defined(LED_USE_PLAY_MODE)

#define LED_AUX	 	BIT(LED_A)
#define LED_FM		BIT(LED_C)
#define LED_USB		 BIT(LED_E)
#define LED_SD		 BIT(LED_D)
#define LED_2POINT	 BIT(LED_G)
#define LED_MP3		 BIT(LED_E)
#define LED_PAUSE	 0//BIT(LED_C)
#define LED_PLAY	 0//BIT(LED_G)
#define LED_STATUS   LED_BUFF[4]

#else

#define LED_AUX	 	0//BIT(LED_A)

#define LED_USB		 BIT(LED_A)
#define LED_FM		 BIT(LED_B)
#define LED_MP3		 BIT(LED_C)
#define LED_SD		 BIT(LED_D)
#define LED_PLAY	 BIT(LED_F)
#define LED_2POINT	 BIT(LED_G)
#define LED_PAUSE	 BIT(LED_H)
#define LED_STATUS   LED_BUFF[4]

#endif



#ifdef USE_BAT_MANAGEMENT

#ifdef EXCHANGE_LED_BAT_ICON
#ifdef BAT_LEVEL_LED_ICON_IND
#ifndef LED_BAT_L1
#define LED_BAT_L1 	BIT(LED_F)
#endif

#ifndef LED_BAT_L2
#define LED_BAT_L2 	BIT(LED_G)
#endif

#endif

#else

#ifdef BAT_LEVEL_LED_ICON_IND
#ifndef LED_BAT_L1
#define LED_BAT_L1 	BIT(LED_G)
#endif

#ifndef LED_BAT_L2
#define LED_BAT_L2 	BIT(LED_F)
#endif

#endif
#endif
#endif

void updateLED(void);
 void lcd_power_down(void);

#endif
