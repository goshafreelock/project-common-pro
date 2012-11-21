#ifndef _KPL_MSG_H_
#define _KPL_MSG_H_

#include "typedef.h"
#include "key.h"
#include "msgfor_hot.h"


enum {
	MSG_TYPE_1,
	MSG_TYPE_2,
	MSG_TYPE_3,
	MSG_TYPE_4,
	MSG_TYPE_END=0xFF,
};


#ifdef __C51__

void kpl_msg_preinit_setting(u8 init_flag,u8 init_type);
void init_kpl_msg();
void kpl_msg_hdlr(u8 key);

#endif



#endif

