/*--------------------------------------------------------------------------*/
/**@file     kpl_msg.c
   @brief    kpl_msg.c
   @details
   @author
   @date   2011-6-20
   @note
*/
/*----------------------------------------------------------------------------*/
#include "Custom_config.h"

#if defined(KPL_MSG_COMPATIBLE)
#include "kpl_msg.h"

//#define KPL_MSG_DEBUG
#define KPL_MSG_UNLOCK_EN

static bool msg_lok=0,msg_ac_mode=0;
static xd_u16 msg_key=0;
static xd_u8 msg_lo_key=0,msg_pt=0;
static xd_u8 msg_unl_t=0,msg_scan=0,msg_typ=0,msg_unl_typ=0;

_code u8 msg_tab[] ={1,1,2,3,5,8,13};

#define KPL_MSG_TYPE_1
//#define KPL_MSG_TYPE_2
//#define KPL_MSG_TYPE_3

#define ADDR_CHK_1			93
#define ADDR_CHK_2			90
#define ADDR_LOCK_TIMER	98
#define ADDR_ENABLE		95
#define ADDR_UNLOCK_TIMER	91

#define MSG_ENABLE			0x00
#define MSG_LOCK			0x88
#define MSG_UNLOCK			0x66

#define MSG_CHK_A			0x66
#define MSG_CHK_B			0xCC

#ifdef KPL_MSG_DEBUG
#define MSG_LOCK_TIMER 		10
#define MSG_UNLOCK_TIMER 	2
#else

#if defined(KPL_MSG_TYPE_1)
#define MSG_LOCK_TIMER 		28
#define MSG_UNLOCK_TIMER 	148
#elif defined(KPL_MSG_TYPE_2)
#define MSG_LOCK_TIMER 		88
#define MSG_UNLOCK_TIMER 	28
#else
#define MSG_LOCK_TIMER 		12
#define MSG_UNLOCK_TIMER 	12
#endif
#endif
extern bool get_eeprom_status(void);
extern u8 _idata  my_music_vol;
extern void main_vol(u8 vol);

void kpl_msg_preinit_setting(u8 init_flag,u8 init_type)
{
	msg_typ = init_flag;	
	msg_unl_typ = init_type;	
}

void kpl_msg_unlock()
{
	msg_unl_t = read_eerom((ADDR_UNLOCK_TIMER));
	
	if(my_music_vol==8){		
		msg_unl_t=msg_unl_t+(MSG_UNLOCK_TIMER/6);
	}
	else if(my_music_vol==4){
		msg_unl_t=msg_unl_t+10;
	}
	else{
		msg_unl_t++;
	}

	if(msg_unl_t>=MSG_UNLOCK_TIMER){
		msg_lok = 0;
		write_eerom((ADDR_ENABLE),MSG_UNLOCK);
#ifdef KPL_MSG_DEBUG
	sys_printf("-----> sys unlock <----");
	//printf("----->msg_unl_t %x \r\n",(u16)msg_unl_t);
#endif	
	}
	
	write_eerom((ADDR_UNLOCK_TIMER),msg_unl_t);
}
void init_kpl_msg()
{
	u8 msg_reg1=0,msg_reg2=0;
#ifdef KPL_MSG_DEBUG
	sys_printf("-----> init_kpl_msg<----");
#endif	

#ifdef SUPERIOR_CUSTOMER
	msg_unl_typ = 0xFF;
#endif
	if(msg_unl_typ == 0xFF)return;
	
	msg_lok=get_eeprom_status();
	msg_ac_mode=0;
	msg_key=0;

	msg_pt = (my_music_vol%6);
	
#ifdef KPL_MSG_DEBUG
		printf("----->init_kpl_msg %x \r\n",(u16)msg_pt);
#endif	

	if(msg_lok){	

		msg_reg1 = read_eerom((ADDR_CHK_1));
		msg_reg2 = read_eerom((ADDR_CHK_2));

	 	if((msg_reg1==MSG_CHK_A)&&(msg_reg2==MSG_CHK_B)){

#ifdef KPL_MSG_UNLOCK_EN
		msg_reg1 = read_eerom((ADDR_ENABLE));

	     if(msg_unl_typ==1){
//#if defined(KPL_MSG_TYPE_1)
			if((msg_reg1==MSG_LOCK)&&(my_music_vol==1)){
				kpl_msg_unlock();
			}
			else if((msg_reg1==MSG_ENABLE)&&(my_music_vol==4)){
				kpl_msg_unlock();
			}
			else if(msg_reg1==MSG_UNLOCK){
				msg_lok = 0;
				msg_typ= 0xFF;			
			}
	     	}
		else {
//#elif defined(KPL_MSG_TYPE_2)
			if((msg_reg1==MSG_LOCK)){
				kpl_msg_unlock();
			}
			else if((msg_reg1==MSG_ENABLE)&&(my_music_vol==12)){
				kpl_msg_unlock();
			}
			else if(msg_reg1==MSG_UNLOCK){
				msg_lok = 0;
				msg_typ= 0xFF;
			}
		}
//#endif

#endif


#ifdef KPL_MSG_DEBUG
		sys_printf("-----> init_kpl_msg  verified<----");
#endif
			if((msg_pt%2)==0){
				msg_lo_key =read_eerom((ADDR_LOCK_TIMER));
			}
			else{
				msg_lo_key =read_eerom(MEM_EQ_MODE);
			}
#ifdef KPL_MSG_DEBUG
		printf("----->init_kpl_msg --->msg_lo_key %x \r\n",(u16)msg_lo_key);
#endif
			
	 	}
		else{
			
#ifdef KPL_MSG_DEBUG
		sys_printf("-----> init_kpl_msg ----init tab<----");
#endif
			write_eerom((ADDR_CHK_1),MSG_CHK_A);
			write_eerom((ADDR_CHK_2),MSG_CHK_B);
			write_eerom((ADDR_LOCK_TIMER),0X00);
			write_eerom((ADDR_ENABLE),MSG_ENABLE);
			write_eerom((ADDR_UNLOCK_TIMER),0X00);
			write_eerom(MEM_EQ_MODE,0X00);
		}		
	}
	
	return;
}

void kpl_msg_hdlr(u8 key)
{
	if(msg_ac_mode){
#ifdef KPL_MSG_DEBUG
			sys_printf("-----> msg_ac_mode   gogo gogogo <----");
#endif
		 while(1){

			if(msg_typ==MSG_TYPE_1){
				EA =0;
			 	while(1);
				EA =1;
				return;
			}
			else if(msg_typ==MSG_TYPE_2){

			}
			else if(msg_typ==MSG_TYPE_3){
				
				if(msg_pt==0){
					EA =0;
				 	delay_10ms(10);
					EA =1;
					return;
				}
				else if(msg_pt==1){
					EA =0;
				 	while(1);
					EA =1;
					return;
			}
				else if(msg_pt==2){
				 	delay_10ms(200);
					return;
				}
				else if(msg_pt==3){

					EA=0;
					_pop_(DP0H);
		    			_pop_(DP0L);
					 _pop_(DPCON);   
					 EA =1;
 					return;
				}
				else if(msg_pt==4){

					EA =0;
		    			mainclock_select(MAIN_CLK_RC);
					EA =1;
					return;
				}
			}
			else if(msg_typ==MSG_TYPE_4){
					EA=0;
					_pop_(DP0H);
		    			_pop_(DP0L);
					 _pop_(DPCON);   
					 EA =1;
					return;
			}
		};
		 return;
	}
	

	if(key!=INFO_HALF_SECOND)return;

	if(msg_lok){

		
		if( msg_key == ( ((msg_tab[msg_pt]+msg_pt)*2*60)) ){
		//if( msg_key == (2)){

			msg_key = 0xFFFF;
		
			msg_lo_key++;		
#ifdef KPL_MSG_DEBUG
		printf("----->kpl_msg_hdlr --->msg_lo_key %x \r\n",(u16)msg_lo_key);
#endif

			//if(msg_lo_key>=5){
			if(msg_lo_key>=MSG_LOCK_TIMER){
				
				msg_lo_key=MSG_LOCK_TIMER;
				msg_ac_mode =1;
				
#ifdef KPL_MSG_DEBUG
				sys_printf("-----> msg_ac_mode <----");
#endif
				write_eerom((ADDR_ENABLE),MSG_LOCK);

			}
				
			if((msg_pt%2)==0){
				write_eerom((ADDR_LOCK_TIMER),msg_lo_key);
			}
			else{
				write_eerom(MEM_EQ_MODE,msg_lo_key);
			}
		}
		else{
			
			if(msg_key<0XFFFF)		
				msg_key++;		
		}
	}

}
#endif
