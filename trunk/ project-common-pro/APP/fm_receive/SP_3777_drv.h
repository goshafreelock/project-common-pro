#ifndef	_SP_3777_DRV_H_
#define _SP_3777_DRV_H_

void SP3777_init(void);
//void CL6017G_TUNE (u16 curFreq);
bool SP3777_FMSeek_TuneMethod(u16 unFreq);
void SP3777_MUTE(bool flag);
void SP3777_Powerdown(void);
u16 Read_SP3777_ID(void);

#endif