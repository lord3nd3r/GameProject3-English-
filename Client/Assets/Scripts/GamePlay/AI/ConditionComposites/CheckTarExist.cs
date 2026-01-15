/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___AI___ConditionComposites___CheckTarExist.cs */
﻿using UnityEngine;
using System.Collections;

namespace BVT.AI
{
    [NodeAttribute(Type = "AI/[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "CheckTarExist")]
    [NodeName("ff64cb", "<size=12>CheckTarExist</size>")]
    public class CheckTarExist : AICondition
    {
        public override bool Check()
        {
            Character aiOwner = this.AIOwner;
            return aiOwner == null ? false : aiOwner.Target != null;
        }

#if UNITY_EDITOR
        public override string DrawConnectionForChild(Node node, int index)
        {
            if (index == 0)
            {
                return Invert == false ? "[TRANSLATED][TRANSLATED]target[TRANSLATED]" : "[TRANSLATED][TRANSLATED][TRANSLATED]target[TRANSLATED]";
            }
            else
            {
                return Invert == false ? "[TRANSLATED][TRANSLATED][TRANSLATED]target[TRANSLATED]" : "[TRANSLATED][TRANSLATED]target[TRANSLATED]";
            }
        }
#endif
    }
}

