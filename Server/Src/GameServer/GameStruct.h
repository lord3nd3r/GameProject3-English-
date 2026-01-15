/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___GameServer___GameStruct.h */
﻿#ifndef __GAME_STRUCT_H__
#define __GAME_STRUCT_H__

struct St_SkillData
{
	UINT32 dwSkillID;
	INT32  nLevel;
	INT32  nKeyPos;
	INT64  uLastTime;
};

typedef struct St_ObjectStatus
{
    union
    {
        UINT32   dwValues;
        struct
        {
            UINT32  nDir    : 9;    // [TRANSLATED][TRANSLATED]
            UINT32  bDead   : 1;    // whether[TRANSLATED][TRANSLATED]
        };
    };
} St_ObjectStatus;

typedef struct St_ChangeStatus
{
    union
    {
        UINT32   dwValue;
        struct
        {
            UINT32  bBase   : 1;    // [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED],[TRANSLATED][TRANSLATED], [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED], [TRANSLATED][TRANSLATED], [TRANSLATED][TRANSLATED]
            UINT32  bDead   : 1;    // whether[TRANSLATED][TRANSLATED]
            UINT32  bEquip  : 1;    // [TRANSLATED][TRANSLATED]
            UINT32  bActor  : 1;    // [TRANSLATED][TRANSLATED]
            UINT32  bAction : 1;    // [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
            UINT32  bBuff   : 1;    // BUFF
            UINT32  bLevel  : 1;    // Level
            UINT32  bControl: 1;    // [TRANSLATED][TRANSLATED][TRANSLATED]
            UINT32  bCamp   : 1;    // [TRANSLATED][TRANSLATED]
            UINT32  bMount  : 1;    // [TRANSLATED][TRANSLATED]
        };
    };
} St_ChangeStatus;


#endif //__GAME_STRUCT_H__