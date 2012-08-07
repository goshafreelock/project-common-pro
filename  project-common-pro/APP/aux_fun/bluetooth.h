#ifndef _BLUE_TOOTH_H_
#define _BLUE_TOOTH_H_



#ifdef __C51__

#include "typedef.h"
#include "key.h"
#include "display_common.h"
#include "msgfor_hot.h"
#include "rtc_mode.h"

void blue_tooth_hdlr(void);

#endif

enum {

	BT_PP,
	BT_NEXT_FILE,	
	BT_PREV_FILE,	
	BT_VOL_UP,	
	BT_VOL_DOWN,
	BT_VOL_UP_HOLD,	
	BT_VOL_DOWN_HOLD,	
	BT_VOL_HOLD_RELEASE,
};

#endif

