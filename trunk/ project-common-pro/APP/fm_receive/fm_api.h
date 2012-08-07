#ifndef _FM_API_H_
#define _FM_API_H_


#ifdef __C51__
#include "rda5807.h"
#include "typedef.h"
#include "display_common.h"
#include "fm_rev.h"

void get_channl(u8 flag);
void init_fm_rev(void);
bool set_fre(u16 fre, u8 mode);
void fm_rev_powerdown(void);
void save_fre(u16 fre);
void auto_scan(u8 Dir);
#if defined(USE_FM_GPIO)
extern void fm_chip_gpio_ctrl(bool fm_ctrl_flag);
#endif

#endif

#endif
