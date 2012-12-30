#include "Custom_config.h"

#ifndef _M62429_H_
#define _M62429_H_
#include "config.h"

/******************************************

D0:0 1ch,;1 2ch
D1:0 Both channels at a time;1 A channel at a time
D2-D6:4db step,max (0x15)0x54
D7-D8:1db step,
D9-D10:11

okvolbak=0x0600;
*******************************************/
#define M62429_gpio_Init()  	P0DIR &= ~ (BIT(1)|BIT(7));P0PU |= (BIT(1)|BIT(7))
#define M62429_clk_pin  		P07
#define M62429_dat_pin		P01 //PT2313_data



#define CHAN_A_VOL_MAX		32
#define CHAN_B_VOL_MAX		18

#define CHAN_A_VOL_DEF		22
#define CHAN_B_VOL_DEF		12

enum {

	ADJ_UP,
	ADJ_DOWN,
	ADJ_CURR,
};
enum {
	CHAN_SEL_A=0,
	CHAN_SEL_B,
	CHAN_SEL_BOTH,
};
enum {
	CHAN_W_ALL=0,
	CHAN_W_SINGLE,
};


typedef union M62429_DATA_TYPE{
	
	unsigned int reg_data;		
	
	struct { 
		unsigned char
				ch_no:1,		//LSBit
				ch_sel:1,
				vol_4db:5,
				vol_1db:2,
				none:7;
	}reg_bit;
}M62429_DATA_TYPE;


//void M62429_config_Data(u8 adj_dir,u8 adj_channel,u16 reg_data);
//void M62429_Init(void);


#endif
