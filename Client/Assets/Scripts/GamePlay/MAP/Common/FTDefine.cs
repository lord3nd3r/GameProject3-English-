/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___MAP___Common___FTDefine.cs */
﻿using UnityEngine;
using System.Collections;

namespace MAP
{
    public enum EAreaShape
    {
        TYPE_CIRCLE   = 0,
        TYPE_RECT     = 1,
    }

    public enum EPathNodeType
    {
        Linear        = 0,
        Bezier        = 1,
    }

    public enum EMapGroup
    {
        Barrier       = 1,
        Born          = 2,
        Mine          = 3,
        Boss          = 4,
        Monster       = 5,
        Npc           = 6,
        Path          = 7,
        Portal        = 8,
        Area          = 9,
    }

    public enum EChunkType
    {
        TYPE_GROUND   = 0,
        TYPE_LIGHT    = 1,
        TYPE_BUILD    = 2,
        TYPE_CLOUD    = 3,
        TYPE_WATER    = 4,
        TYPE_TREE     = 5,
        TYPE_GRASS    = 6,
        TYPE_STONE    = 7,
        TYPE_EFFECT   = 8,
        TYPE_SOUND    = 9,
    }

    public enum EWeatherType
    {
        None          = 0,
        Sunny         = 1,   //[TRANSLATED][TRANSLATED]
        Thunder       = 2,   //[TRANSLATED][TRANSLATED]
        Rain          = 4,   //[TRANSLATED][TRANSLATED]
        Snow          = 8,   //[TRANSLATED][TRANSLATED]
        Hail          = 16,  //[TRANSLATED][TRANSLATED]
        Storm         = 32,  //[TRANSLATED][TRANSLATED]
    }

    public enum EOpenConditionRelation
    {
        And           = 0,
        Or            = 1,
    }

    public enum EFTEventType
    {
        FTEventBegin               = 0,

        FTEventTriggerArea         = 1,  //trigger[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        FTEventDestroyArea         = 2,  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        FTEventTriggerBarrier      = 3,  //trigger[TRANSLATED][TRANSLATED]
        FTEventDestroyBarrier      = 4,  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        FTEventTriggerSkill        = 5,  //trigger[TRANSLATED][TRANSLATED]skill
        FTEventTriggerSound        = 6,  //trigger[TRANSLATED][TRANSLATED]
        FTEventTriggerStep         = 7,  //trigger[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        FTEventTriggerTask         = 8,  //trigger[TRANSLATED][TRANSLATED]
        FTEventTriggerTeleport     = 9,  //trigger[TRANSLATED][TRANSLATED]
        FTEventTriggerTimer        = 10, //trigger[TRANSLATED][TRANSLATED][TRANSLATED]
        FTEventDestroyTimer        = 11, //stop[TRANSLATED][TRANSLATED][TRANSLATED]
        FTEventKillMe              = 12, //[TRANSLATED][TRANSLATED][TRANSLATED]
        FTEventTriggerEffect       = 13, //triggereffect
        FTEventDestroyEffect       = 14, //[TRANSLATED][TRANSLATED]effect

        FTEventDestroyAllMonsters  = 15, 
        FTEventDestroyAllObjs      = 16,
        
        FTEventCallMonster         = 17,
        FTEventCallMine            = 18,

        FTEventTaskCameraEffect    = 19,
        FTEventTaskCG              = 20,
        FTEventTaskCutscene        = 21,
        FTEventTaskDelay           = 22,
        FTEventTaskDialogue        = 23,
    }
}