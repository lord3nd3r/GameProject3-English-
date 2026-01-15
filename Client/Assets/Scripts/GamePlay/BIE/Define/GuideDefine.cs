/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___BIE___Define___GuideDefine.cs */
﻿using UnityEngine;
using System.Collections;

namespace BIE
{
    public enum EGuideType
    {
        TYPE_PATH                      =  1,  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]  
        TYPE_OPERATION                 =  2,  //[TRANSLATED][TRANSLATED]UI[TRANSLATED][TRANSLATED]
        TYPE_DIALOGUE                  =  3,  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        TYPE_CG                        =  4,  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        TYPE_PLOT                      =  5,  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    }

    public enum EGuideState
    {
        TYPE_NONE                      =  0,  
        TYPE_ENTER                     =  1,  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        TYPE_EXECUTE                   =  2,  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        TYPE_FINISH                    =  3,  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    }

    public enum EGuideUIOperationType
    {
        TYPE_CLICK                     =  0,
        TYPE_PRESS                     =  1,
        TYPE_SWAP                      =  2,
        TYPE_JOYSTICK                  =  3,
    }

    public enum EGuideConditionRelation
    {
        AND                            =  0,  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        OR                             =  1   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    }

    public enum EGuideRowType
    {
        TYPE_NONE                      =  0,
        TYPE_UP                        =  1,  //[TRANSLATED][TRANSLATED]
        TYPE_UP_RIGHT                  =  2,  //[TRANSLATED][TRANSLATED]
        TYPE_RIGHT                     =  3,  //[TRANSLATED][TRANSLATED]
        TYPE_DOWN_RIGHT                =  4,  //[TRANSLATED][TRANSLATED]
        TYPE_DOWN                      =  5,  //[TRANSLATED][TRANSLATED]
        TYPE_DOWN_LEFT                 =  6,  //[TRANSLATED][TRANSLATED]
        TYPE_LEFT                      =  7,  //[TRANSLATED][TRANSLATED]
        TYPE_UP_LEFT                   =  8,  //[TRANSLATED][TRANSLATED]
    }

    public enum EGuideBoardType
    {
        TYPE_NONE                      =  0,   
        TYPE_RECTANGLE                 =  1,   //[TRANSLATED][TRANSLATED]
        TYPE_CIRCLE                    =  2,   //[TRANSLATED][TRANSLATED]
    }

    public enum EGuideGirlPos
    {
        TYPE_NONE                      =  0,
        TYPE_LEFT                      =  1,
        TYPE_RIGHT                     =  2,
    }

    public enum EGuideCondition
    {
        CheckItemAmount                =  1,   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]count
        CheckPlayerLevel               =  2,   //[TRANSLATED][TRANSLATED]playerLevel
        CheckPlayerVip                 =  3,   //[TRANSLATED][TRANSLATED]playerVip
        CheckOpenUI                    =  4,   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]UI
        CheckHideUI                    =  5,   //[TRANSLATED][TRANSLATED]shutdownUI
        CheckMonsterAppear             =  6,   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        CheckMonsterHP                 =  7,   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        CheckScene                     =  8,   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        CheckWeekday                   =  9,   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        CheckPlayerHP                  =  10,  //[TRANSLATED][TRANSLATED]playerHP
        CheckPlayerHPPercent           =  11,  //[TRANSLATED][TRANSLATED]playerHP[TRANSLATED][TRANSLATED][TRANSLATED]
    }
}
