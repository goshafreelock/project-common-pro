#ifndef _RDA_5807_H_
#define _RDA_5807_H_

#ifdef __C51__
#include "iic.h"
#include "typedef.h"



void init_rda5807(void);
bool set_fre_rda5807(u16 fre, u8 mode);
void rda5807_poweroff(void);
#endif

#endif