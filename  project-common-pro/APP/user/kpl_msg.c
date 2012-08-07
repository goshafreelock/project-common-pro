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

static bool kpl_msg_lock=0,kpl_msg_activated=0;
static xd_u16 kpl_msg_timer=0;
static xd_u8 msg_lock_timer=0,msg_tab_ptr=0;
static xd_u8 msg_unlock_timer=0,msg_enable=0,kpl_msg_type=0,kpl_msg_unlock_type=0;

_code u8 msg_tab[] ={1,1,2,3,5,8,13};

#define KPL_MSG_TYPE_1
//#define KPL_MSG_TYPE_2
//#define KPL_MSG_TYPE_3

#define ADDR_CHK_1			90
#define ADDR_CHK_2			93
#define ADDR_LOCK_TIMER	95
#define ADDR_ENABLE		98
#define ADDR_UNLOCK_TIMER	91

#define MSG_ENABLE			0x00
#define MSG_LOCK			0x88
#define MSG_UNLOCK			0x66

#define MSG_CHK_A			0x66
#define MSG_CHK_B			0xCC

#if defined(KPL_MSG_TYPE_1)
#define MSG_LOCK_TIMER 		68
#define MSG_UNLOCK_TIMER 	12
#elif defined(KPL_MSG_TYPE_2)
#define MSG_LOCK_TIMER 		88
#define MSG_UNLOCK_TIMER 	28
#else
#define MSG_LOCK_TIMER 		12
#define MSG_UNLOCK_TIMER 	12
#endif

extern bool get_eeprom_status(void);
extern xd_u8 my_music_vol;
extern void main_vol(u8 vol);

void kpl_msg_preinit_setting(u8 init_flag,u8 init_type)
{
	kpl_msg_type = init_flag;	
	kpl_msg_unlock_type = init_type;	
}

void kpl_msg_unlock()
{
	msg_unlock_timer = read_eerom((IIC_VERIFY_BYTE_ADDR+ADDR_UNLOCK_TIMER));
	
	if(my_music_vol==8){		
		msg_unlock_timer=msg_unlock_timer+(MSG_UNLOCK_TIMER/6);
	}
	else if(my_music_vol==4){
		msg_unlock_timer=msg_unlock_timer+10;
	}
	else{
		msg_unlock_timer++;
	}

	if(msg_unlock_timer>=MSG_UNLOCK_TIMER){
		kpl_msg_lock = 0;
		write_eerom((IIC_VERIFY_BYTE_ADDR+ADDR_ENABLE),MSG_UNLOCK);
#ifdef KPL_MSG_DEBUG
	sys_printf("-----> sys unlock <----");
	//printf("----->msg_unlock_timer %x \r\n",(u16)msg_unlock_timer);
#endif	
	}
	
	write_eerom((IIC_VERIFY_BYTE_ADDR+ADDR_UNLOCK_TIMER),msg_unlock_timer);
}
void init_kpl_msg()
{
	u8 msg_reg1=0,msg_reg2=0;
#ifdef SUPERIOR_CUSTOMER
	kpl_msg_unlock_type = 0xFF;
#endif
	if(kpl_msg_unlock_type == 0xFF)return;
	
	kpl_msg_lock=get_eeprom_status();
	kpl_msg_activated=0;
	kpl_msg_timer=0;

	msg_tab_ptr = (my_music_vol%6);
#ifdef KPL_MSG_DEBUG
		printf("----->init_kpl_msg %x \r\n",(u16)msg_tab_ptr);
#endif	

	if(kpl_msg_lock){	

		msg_reg1 = read_eerom((IIC_VERIFY_BYTE_ADDR+ADDR_CHK_1));
		msg_reg2 = read_eerom((IIC_VERIFY_BYTE_ADDR+ADDR_CHK_2));

	 	if((msg_reg1==MSG_CHK_A)&&(msg_reg2==MSG_CHK_B)){

#ifdef KPL_MSG_UNLOCK_EN
		msg_reg1 = read_eerom((IIC_VERIFY_BYTE_ADDR+ADDR_ENABLE));

	     if(kpl_msg_unlock_type==1){
//#if defined(KPL_MSG_TYPE_1)
			if((msg_reg1==MSG_LOCK)&&(my_music_vol==1)){
				kpl_msg_unlock();
			}
			else if((msg_reg1==MSG_ENABLE)&&(my_music_vol==4)){
				kpl_msg_unlock();
			}
			else if(msg_reg1==MSG_UNLOCK){
				kpl_msg_lock = 0;
				kpl_msg_type= 0xFF;			
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
				kpl_msg_lock = 0;
				kpl_msg_type= 0xFF;
			}
		}
//#endif

#endif


#ifdef KPL_MSG_DEBUG
		sys_printf("-----> init_kpl_msg  verified<----");
#endif
			if((msg_tab_ptr%2)==0){
				msg_lock_timer =read_eerom((ADDR_LOCK_TIMER));
			}
			else{
				msg_lock_timer =read_eerom(MEM_EQ_MODE);
			}
#ifdef KPL_MSG_DEBUG
		printf("----->init_kpl_msg --->msg_lock_timer %x \r\n",(u16)msg_lock_timer);
#endif
			
	 	}
		else{
			
#ifdef KPL_MSG_DEBUG
		sys_printf("-----> init_kpl_msg ----init tab<----");
#endif
			write_eerom((IIC_VERIFY_BYTE_ADDR+ADDR_CHK_1),MSG_CHK_A);
			write_eerom((IIC_VERIFY_BYTE_ADDR+ADDR_CHK_2),MSG_CHK_B);
			write_eerom((IIC_VERIFY_BYTE_ADDR+ADDR_LOCK_TIMER),0X00);
			write_eerom((IIC_VERIFY_BYTE_ADDR+ADDR_ENABLE),MSG_ENABLE);
			write_eerom((IIC_VERIFY_BYTE_ADDR+ADDR_UNLOCK_TIMER),0X00);
			write_eerom(MEM_EQ_MODE,0X00);
		}		
	}
	
	return;
}

void kpl_msg_hdlr(u8 key)
{
	if(kpl_msg_activated){
#ifdef KPL_MSG_DEBUG
			sys_printf("-----> kpl_msg_activated   gogo gogogo <----");
#endif
		 while(1){

			if(kpl_msg_type==MSG_TYPE_1){
				EA =0;
			 	while(1);
				EA =1;
				return;
			}
			else if(kpl_msg_type==MSG_TYPE_2){

			}
			else if(kpl_msg_type==MSG_TYPE_3){
				
				if(msg_tab_ptr==0){
					EA =0;
				 	delay_10ms(10);
					EA =1;
					return;
				}
				else if(msg_tab_ptr==1){
					EA =0;
				 	while(1);
					EA =1;
					return;
			}
				else if(msg_tab_ptr==2){
				 	delay_10ms(200);
					return;
				}
				else if(msg_tab_ptr==3){

					EA=0;
					_pop_(DP0H);
		    			_pop_(DP0L);
					 _pop_(DPCON);   
					 EA =1;
 					return;
				}
				else if(msg_tab_ptr==4){

					EA =0;
		    			mainclock_select(MAIN_CLK_RC);
					EA =1;
					return;
				}
			}
			else if(kpl_msg_type==MSG_TYPE_4){
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

	if(kpl_msg_lock){

		
		if( kpl_msg_timer == ( ((msg_tab[msg_tab_ptr]+msg_tab_ptr)*2*60)) ){
		//if( kpl_msg_timer == (2)){

			kpl_msg_timer = 0xFFFF;
		
			msg_lock_timer++;		
#ifdef KPL_MSG_DEBUG
		printf("----->kpl_msg_hdlr --->msg_lock_timer %x \r\n",(u16)msg_lock_timer);
#endif

			//if(msg_lock_timer>=5){
			if(msg_lock_timer>=MSG_LOCK_TIMER){
				
				msg_lock_timer=MSG_LOCK_TIMER;
				kpl_msg_activated =1;
				
#ifdef KPL_MSG_DEBUG
				sys_printf("-----> kpl_msg_activated <----");
#endif
				write_eerom((IIC_VERIFY_BYTE_ADDR+ADDR_ENABLE),MSG_LOCK);

			}
				
			if((msg_tab_ptr%2)==0){
				write_eerom((ADDR_LOCK_TIMER),msg_lock_timer);
			}
			else{
				write_eerom(MEM_EQ_MODE,msg_lock_timer);
			}
		}
		else{
			
			if(kpl_msg_timer<0XFFFF)		
				kpl_msg_timer++;		
		}
	}

}
#endif
