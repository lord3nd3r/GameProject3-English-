/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___AI___AIDefine.cs */
﻿using UnityEngine;
using System.Collections;

namespace BVT.AI
{
    public enum EAIFight
    {
        TYPE_FIGHTNONE,
        TYPE_FIGHT,
    }

    public enum EAIState
    {
        BORN,  //[TRANSLATED][TRANSLATED]
        IDLE,  //[TRANSLATED][TRANSLATED]
        FIGHT, //[TRANSLATED][TRANSLATED]
        FOLLOW,//[TRANSLATED][TRANSLATED]
        PATROL,//[TRANSLATED][TRANSLATED]
        DEAD,  //[TRANSLATED][TRANSLATED]
        BACK,  //[TRANSLATED][TRANSLATED]
        CHASE, //[TRANSLATED][TRANSLATED]
        FLEE,  //[TRANSLATED][TRANSLATED]
        ESCAPE,//[TRANSLATED][TRANSLATED]
        PLOT,  //[TRANSLATED][TRANSLATED]
    }

    public enum EAITarget
    {
        TYPE_SELF   = 0,
        TYPE_TARGET = 1,
        TYPE_HOST   = 2,
    }

    public class AIDefine
    {
        public const string KEY_WARNER_DIST   = "WarnerDist";
        public const string KEY_ATTACK_DIST   = "AttackDist";
        public const string KEY_GOHOME_DIST   = "GoHomeDist";
    }
}