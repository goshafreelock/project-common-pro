/*--------------------------------------------------------------------------*/
/**@file    uart.h
   @brief   ���ڴ�ӡͷ�ļ�
   @details
   @author
   @date   2010-12-13
   @note
*/
/*----------------------------------------------------------------------------*/
#ifndef _UART_
#define _UART_

#ifdef __C51__
#include "AC209N.h"
#include "intrins.h"


#include "typedef.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "entry.h"

void uartInit(void);
char putchar (char c);
void sys_printf(char *str);
#endif
#endif