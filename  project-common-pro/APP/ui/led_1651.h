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

#define LED_STATUS   LED_BUFF[0]

void updateLED(void);
 void lcd_power_down(void);

#endif
