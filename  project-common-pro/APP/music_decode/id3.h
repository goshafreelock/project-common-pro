#ifndef _ID3_H_
#define _ID3_H_

#ifdef __C51__
#include "config.h"
#include "uart.h"

#include "filesystem.h"

#include "device.h"
#include "decode.h"


typedef struct _ID3V2_PARSE
{
    u8 isv34;
    u8 unsync;
    u8 tunsync;
    u8 id3v2_version;
    u8 id2v3_flags;
    u8 taghdrlen;
    u32 id3v2_len;				/* ID3 �ܳ���, ������֡ͷ��Footer preset */
    u32 tlen;					/* ��ǰID3 frame���ȣ�������֡ͷ */
} ID3V2_PARSE;

enum
{
    SEEK_SET = 0,
    SEEK_CUR
};
void get_filetag(u8 _xdata * buffer);
#endif

#endif