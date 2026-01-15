/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___AI___ConditionComposites___CheckTarDead.cs */
﻿using UnityEngine;
using System.Collections;

namespace BVT.AI
{
    [NodeAttribute(Type = "AI/[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "CheckTarDead")]
    public class CheckTarDead : AICondition
    {
        public override bool Check()
        {
            Character aiOwner = this.AIOwner;
            if (aiOwner == null)
            {
                return false;
            }
            if (aiOwner.Target == null)
            {
                return false;
            }
            if (aiOwner.Target.IsDead())
            {
                return true;
            }
            return  false;
        }
    }

}
