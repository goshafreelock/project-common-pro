/*--------------------------------------------------------------------------*/
/**@file    uart.c
   @brief   ���ڴ�ӡ����
   @details
   @author
   @date   2010-12-13
   @note
*/
/*----------------------------------------------------------------------------*/
#include "Custom_config.h"
#include"uart.h"

/*----------------------------------------------------------------------------*/
/**@brief  ���ڳ�ʼ������
   @param  ��
   @return ��
   @note   void uartInit(void)
*/
/*----------------------------------------------------------------------------*/
void uartInit(void)
{

    UTBAUD = (48000000/(8 * 115200)) - 1;	//25;//0x37;					/* 25: cpu 24M, 115200bps*/	/*77 for 384*/ /*0x137 for 9600*/
    UTCON = 0x01;
#if defined (_USE_UART_P0_)
    P0DIR &= ~(1<<6);
    P0DIR |= (1<<7);
    UTCON = 0x41;							/* enable uart */
#elif defined(_USE_UART_P2_)
    P2DIR &= 0xef;							/* P06 for transmit */
    P2DIR |= 0x20;							/* P07 for receive */
    UTCON = 0x41;							/* enable uart */
#else
    UTCON = 0x00;							/* disable uart */
#endif
}
/*----------------------------------------------------------------------------*/
/**@brief  ���ڴ�ӡ��������������
   @param  c��һ��8λ����ֵ
   @return ��
   @note   void putbyte(u8 c)
*/
/*----------------------------------------------------------------------------*/
void putbyte(u8 c)
{
    UTBUF = c;
    while (!(UTSTA & 0x80))
    {
    }
}
/*----------------------------------------------------------------------------*/
/**@brief  ���ڴ�ӡ������������
   @param  c��һ��8λ����ֵ
   @return ��
   @note   char putchar (u8 c)
*/
/*----------------------------------------------------------------------------*/
char putchar (u8 c)
{
    if (c == '\n')
    {
        putbyte(0x0d);
        putbyte(0x0a);
    }
    else
    {
        putbyte(c);
    }

    return (c);
}

void sys_printf(char *str)
{
      printf(str);
      printf("\r\n"); 	  

}
