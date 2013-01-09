
#include "Custom_config.h"

#ifdef SUPPORT_M62429

#include "m62429.h"
#ifdef GPIO_SEL_M62429_FUNC
extern bool select_m62429;
#endif 

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
u16 align_m62429_reg_data(u8 vol_db,u8 reg_ch)
{
	return ((((3-(vol_db%4))<<7)|((21-(vol_db/4))<<2)|(CHAN_W_SINGLE)|(reg_ch))|0x0600);
}
void M62429_config_Data(u8 adj_dir,u8 adj_channel,u16 reg_data)
{
	static bool vol_lock=0;
	u16 reg_temp=0,REG=0;
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
#ifdef UART_ENABLE_M62429		
		printf(" M62429_config_Data ----> CHAN_SEL_A =%x DB \r\n",(u16)reg_temp);
#endif
		REG =align_m62429_reg_data(reg_temp,CHAN_SEL_A);

	}
	else if(adj_channel == CHAN_SEL_B){

		reg_temp=CHAN_B_VOL_MAX-M62429_ch2_vol;
		
#ifdef UART_ENABLE_M62429		
		printf(" M62429_config_Data ----> CHAN_SEL_B  =%d DB \r\n",(u16)reg_temp);
#endif
		REG =align_m62429_reg_data(reg_temp,CHAN_SEL_B);
	}
	else{

		reg_temp=CHAN_A_VOL_MAX-M62429_ch1_vol;
#ifdef UART_ENABLE_M62429		
		printf(" M62429_config_Data ----> CHAN_SEL_A AND B =%d DB \r\n",(u16)reg_temp);
#endif
		//M62429.reg_data =0;
		REG =align_m62429_reg_data(reg_temp,CHAN_SEL_A);
	}


	if((vol_lock)&&(M62429_ch2_vol>0)){

		vol_lock=0;
		
		reg_temp=CHAN_A_VOL_MAX-M62429_ch1_vol;
		REG =align_m62429_reg_data(reg_temp,CHAN_SEL_A);
		M62429_Write_reg(REG);

		reg_temp=CHAN_B_VOL_MAX-M62429_ch2_vol;
		REG =align_m62429_reg_data(reg_temp,CHAN_SEL_B);
		M62429_Write_reg(REG);	
	}
	

	if((M62429_ch2_vol==CHAN_B_VOL_MAX)&&(adj_channel == CHAN_SEL_B)){		//4 MIC VOL  EQU   ZERO

		vol_lock=1;
		REG =0x0600;
	}

#ifdef UART_ENABLE_M62429		
	printf(" M62429_config_Data ----> M62429.reg_data =  %x   \r\n",(u16)REG);
#endif
	
	M62429_Write_reg(REG);
}


void M62429_Init(void)
{
#ifdef GPIO_SEL_M62429_FUNC
	if(!select_m62429)return;
#endif
	M62429_gpio_Init();
	
	 M62429_clk_pin=0;
	 
	M62429_ch1_vol=CHAN_A_VOL_DEF;
	M62429_ch2_vol=CHAN_B_VOL_DEF;
	
	M62429_config_Data(ADJ_CURR,CHAN_SEL_A,M62429_ch1_vol);
	M62429_config_Data(ADJ_CURR,CHAN_SEL_B,M62429_ch2_vol);
}

#endif

