
#include "Custom_config.h"

#ifdef SUPPORT_M62429

#include "m62429.h"

_xdata M62429_DATA_TYPE M62429; 

xd_u8 M62429_ch1_vol=0,M62429_ch2_vol=0;
	
void M62429_Write_reg(u16 updata)
{
	u16 i;
	for (i = 0x0001;i<0x0800;i<<=1)
	{
	
	    	M62429_dat_pin=0;
		_nop_();_nop_();_nop_();
		_nop_();_nop_();_nop_();
	    	M62429_clk_pin=0;
		_nop_();_nop_();_nop_();
		_nop_();_nop_();_nop_();

		if ((updata & i)>0)
	            M62429_dat_pin=1;
	        else
	            M62429_dat_pin=0;
		     _nop_();_nop_();_nop_();
		_nop_();_nop_();_nop_();

	        M62429_clk_pin=1;  
		_nop_();_nop_();_nop_();
		_nop_();_nop_();_nop_();
      }	
      M62429_dat_pin=1;
	_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();
      M62429_clk_pin=0;
}

void M62429_config_Data(u8 adj_dir,u8 adj_channel,u16 reg_data)
{
	u16 reg_temp=0;
	if (adj_dir==ADJ_UP)
	{
		if(adj_channel == CHAN_SEL_A){

			M62429_ch1_vol++;
			if(M62429_ch1_vol>CHAN_A_VOL_MAX){
				M62429_ch1_vol=CHAN_A_VOL_MAX;
			}			
		}
		else{			
			M62429_ch2_vol++;
			if(M62429_ch2_vol>CHAN_B_VOL_MAX){
				M62429_ch2_vol=CHAN_B_VOL_MAX;
			}
		}
	}
	else if(adj_dir==ADJ_DOWN)
	{
		if(adj_channel == CHAN_SEL_A){
			if(M62429_ch1_vol>0)
				M62429_ch1_vol--;
		}
		else{			
			if(M62429_ch2_vol>0)
				M62429_ch2_vol--;
		}
	}
	else if(adj_dir==ADJ_CURR){


	}

	if(adj_channel == CHAN_SEL_A){

		reg_temp=CHAN_A_VOL_MAX-M62429_ch1_vol;

		reg_temp =0;
#ifdef UART_ENABLE_M62429		
		printf(" M62429_config_Data ----> CHAN_SEL_A =%d DB \r\n",(u16)reg_temp);
#endif
		M62429.reg_data =0;
		M62429.reg_bit.ch_no = CHAN_SEL_A;
		M62429.reg_bit.ch_sel=CHAN_W_SINGLE;	
		M62429.reg_bit.vol_4db=(21-(reg_temp/4));	
		M62429.reg_bit.vol_1db=(3-(reg_temp%4));	

	}
	else if(adj_channel == CHAN_SEL_B){

		reg_temp=CHAN_B_VOL_MAX-M62429_ch2_vol;
		reg_temp =0;
		
#ifdef UART_ENABLE_M62429		
		printf(" M62429_config_Data ----> CHAN_SEL_B  =%d DB \r\n",(u16)reg_temp);
#endif
		M62429.reg_data =0;
		M62429.reg_bit.ch_no = CHAN_SEL_B;
		//M62429.reg_bit.ch_sel=CHAN_W_SINGLE;	
		//M62429.reg_bit.vol_4db=(21-(reg_temp/4));
		//M62429.reg_bit.vol_1db=(3-(reg_temp%4));	

	}
	else{

		reg_temp=CHAN_A_VOL_MAX-M62429_ch1_vol;
#ifdef UART_ENABLE_M62429		
		printf(" M62429_config_Data ----> CHAN_SEL_A AND B =%d DB \r\n",(u16)reg_temp);
#endif
		M62429.reg_data =0;
		M62429.reg_bit.ch_no = CHAN_SEL_B;
		M62429.reg_bit.ch_sel=CHAN_W_ALL;	
		M62429.reg_bit.vol_4db=(21-(M62429_ch1_vol/4));		
		M62429.reg_bit.vol_1db=(3-(M62429_ch1_vol%4));	

	}

#ifdef UART_ENABLE_M62429		
		printf(" M62429_config_Data ----> M62429.reg_data =  %x   \r\n",(u16)M62429.reg_data);
#endif
	
	M62429_Write_reg(M62429.reg_data);
}


void M62429_Init(void)
{
	M62429_gpio_Init();
	
	 M62429_clk_pin=0;
	 
	M62429_ch1_vol=CHAN_A_VOL_DEF;
	M62429_ch2_vol=CHAN_B_VOL_DEF;
	
	M62429_config_Data(ADJ_CURR,CHAN_SEL_A,M62429_ch1_vol);
	M62429_config_Data(ADJ_CURR,CHAN_SEL_B,M62429_ch2_vol);
}

#endif

