/*--------------------------------------------------------------------------*/
/**@file    uart.h
   @brief   串口打印头文件
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