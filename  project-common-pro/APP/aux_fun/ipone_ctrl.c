/*--------------------------------------------------------------------------*/
/**@file     ipone_ctrl.c
   @brief    ipone_ctrlÈÎÎñÄ£¿é
   @details
   @author
   @date   2011-3-7
   @note
*/
/*----------------------------------------------------------------------------*/
#include "Custom_config.h"
#include "typedef.h"
#include"clock.h"
#include"uart.h"
#include"key.h"

#if defined(IPONE_DOCK_FUNC_ENABLE)

#if defined(IPHONE_DETECT_IN_USE)
void iPod_Music_enable();
void iPod_Music_disable();
void iPodCommand(u8 button,u8 len);


#if defined(IPHONE_DETECT_USE_P04)
#define IPHONE_DETECT_PORT 	P04
#define IDENTIFY_LOGIC 			1
#elif defined(IPHONE_DETECT_USE_P02)
#define IPHONE_DETECT_PORT 	P02
#define IDENTIFY_LOGIC 			1
#else
#define IPHONE_DETECT_PORT 	P06
#define IDENTIFY_LOGIC 			1
#endif
bool iphone_tx_is_busy=0,iphone_status=0;
void iphone_tx_detect_polling()
{
	static u8 cnt_iphone_detect =0;
#if defined(IPHONE_DETECT_USE_P04)
	P0DIR |=(BIT(4));
	P0PU |=(BIT(4));
	
#else
	if(iphone_tx_is_busy)return;
	P0DIR |=(BIT(6));
	P0PU   |=(BIT(6));
#endif	
    	_nop_();
       _nop_();

	if(IPHONE_DETECT_PORT==IDENTIFY_LOGIC){

		if(cnt_iphone_detect++>12){
			
		        cnt_iphone_detect= 0;
		        if (iphone_status)
		        {
		            put_msg_lifo(MSG_IPOD_OUT);
		            iphone_status = 0;
		        }
		}
	}
	else{
		if(cnt_iphone_detect++>12){

		     cnt_iphone_detect= 0;
	            if (!iphone_status)
	            {
	                put_msg_lifo(MSG_IPOD_IN);
	                iphone_status = 1;
	            }
	        }
	}
}
#endif

extern void putbyte(u8 c);
void open_uart_ctrl()
{
    sysclock_div2(1);
    UTBAUD = 0x37;//(48000000/(8 * 9600)) - 1;	//25;//0x37;					/* 25: cpu 24M, 115200bps*/	/*77 for 384*/ /*0x137 for 9600*/
#if defined(IPHONE_TX_USE_P06)
	P0DIR &=~(BIT(6));
	UTCON = 0x11;
#else
    P3DIR &=~(BIT(2));							/* P32 for transmit */
    UTCON = 0x91;									/* enable uart */
#endif	
}
void close_uart_ctrl()
{
    UTCON = 0x00;								/* disable uart */
}
#if defined(IPHONE_DETECT_IN_USE)
//FF A4 D2 FF 04 24 	FF 84 24 FF 24 FC A1 

//FF A4 D2 FF 24 24 	FF 84 24 FF 24 FC A1

//FF A4 A4 FF 24 24 	FF A4 A4 FF 24 FC A1

//FF A4 A4 FF 24 24	FF A4 D2 FF 04 FC A0 

//FF A4 D2 FF 84 24 	FF 84 A4 EF 04 FC A0 

//FF 84 A4 FF 04 24 	FF 84 A4 EF 04 FC A0 
void iPod_Music_enable()
{
	open_uart_ctrl();
	putbyte(0xFF);
	putbyte(0xA4);
	putbyte(0xD2);
	
	putbyte(0xFF);
	putbyte(0x24);
	putbyte(0x24);
	
	close_uart_ctrl();
}
void iPod_Music_disable()
{
	open_uart_ctrl();
	putbyte(0xFF);
	putbyte(0x84);
	putbyte(0x24);
	
	putbyte(0xFF);
	putbyte(0x24);
	putbyte(0xFC);
	putbyte(0xA1);

	close_uart_ctrl();
}
#endif
void iPodCommand(u8 button,u8 len)
{
#if defined(IPHONE_CTRL_FAKE)
	return;
#endif

#if defined(IPHONE_DETECT_USE_TX)
	iphone_tx_is_busy=1;
	//open_uart_ctrl();
#endif
	putbyte(0xFF);
	putbyte(0x55);
	putbyte(len);
	putbyte(0x02);
	
	while(len>2)
	{
		putbyte(0x00);
		len--;
	}
	putbyte(button);		
	putbyte(0xFF-len-2-button);
	
#if defined(IPHONE_DETECT_USE_TX)
	iphone_tx_is_busy=0;
	//close_uart_ctrl();
#endif
	
}
#endif


