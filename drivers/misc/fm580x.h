/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Definitions for fm580x chip.
 */
#ifndef __FM580X_H__
#define __FM580X_H__

#include <linux/ioctl.h>

#define FM580X_I2C_NAME		"fm580x"

#define FM5807_MAGIC 'H' //

#define FM_SET_ENABLE              _IOW(FM5807_MAGIC, 1, int)
#define FM_SET_DISABLE             _IOW(FM5807_MAGIC, 2, int)
#define FM_SET_STEREO              _IOW(FM5807_MAGIC, 3, int)
#define FM_GET_STEREO              _IOW(FM5807_MAGIC, 4, int)
#define FM_SET_FREQ                _IOW(FM5807_MAGIC, 5, int)
#define FM_SET_AREA                _IOW(FM5807_MAGIC, 6, int)
#define FM_STATION_ISAVAILABLE     _IOW(FM5807_MAGIC, 7, int)
#define FM_TR_FUN                  _IOW(FM5807_MAGIC, 8, int)
#define FM_TR_FUN_STOP             _IOW(FM5807_MAGIC, 9, int)
#define FM_MUTE                    _IOW(FM5807_MAGIC, 10, int)

#define REG_FM5807_MUTE     (1<<15)
#define _SHARE_CRYSTAL_32KHz_

const uint8_t RDA5807PE_initialization_reg[]={
#if defined(_SHARE_CRYSTAL_24MHz_)
0xc4, 0x51, //02H:
#elif defined(_SHARE_CRYSTAL_12MHz_)
0xc4, 0x11, //02H:
#elif defined(_SHARE_CRYSTAL_32KHz_)
0xc4, 0x01, //02H:
#else
0xC0, 0x01,
#endif

#if defined(_FM_STEP_50K_)
0x00, 0x12,
0x0C, 0x00,
#else       //Step 100K
0x00, 0x10,
0x04, 0x00,
#endif

0x86, 0xad, //05H:
0x80, 0x00,
0x5F, 0x1A, //07H
0x5e, 0xc6,
0x00, 0x00,
0x40, 0x6e, //0AH: 
0x2d, 0x80,
0x58, 0x03,
0x58, 0x04,
0x58, 0x04,
0x58, 0x04,
0x00, 0x47, //10H: 
0x90, 0x00,
0xF5, 0x87,
0x7F, 0x0B, //13H:
0x00, 0xF1,
0x42, 0xc0, //15H: 
0x41, 0xe0,
0x50, 0x6f,
0x55, 0x92,
0x00, 0x7d,
0x10, 0xC0,//1AH
0x07, 0x80,
0x41, 0x1d,//1CH,
0x40, 0x06,
0x1f, 0x9B,
0x4c, 0x2b,//1FH. 
0x81, 0x10, //20H: 
0x45, 0xa0,// 21H

#if defined(_FM_STEP_50K_)
0x55, 0x3F, //22H
#else
0x19, 0x3F, //22H
#endif

0xaf, 0x40, 
0x04, 0x81,
0x1b, 0x2a, //25H
0x0D, 0x04,
0x80, 0x2F, 
0x17, 0x8A,
0xD3, 0x49,
0x11, 0x42,
0xA0, 0xC4, //2BH
0x3C, 0x3B,
0x00, 0x00,
0x58, 0x04,
0x58, 0x04, //2FH
0x58, 0x04,
0x00, 0x74,
0x3D, 0x00,
0x03, 0x0C,
0x2F, 0x68,
0x38, 0x77, //35H
};

#endif /* __FM580X_H__ */

