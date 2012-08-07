#ifndef _AUX_H_
#define _AUX_H_



#ifdef __C51__

#include "typedef.h"
#include "key.h"
#include "display_common.h"
#include "msgfor_hot.h"
#include "rtc_mode.h"

void deal_aux( void );
void aux_function(void);

#if defined(IPONE_INDEPENDENT_MODE)
void iphone_func(void);
#endif

#endif

enum {

	AUX_CH_EXIT,
	AUX_CH_SET_UP,	
};

#endif
