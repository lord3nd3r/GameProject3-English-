/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___AI___ConditionComposites___CheckMeDead.cs */
﻿using UnityEngine;
using System.Collections;

namespace BVT.AI
{
    [NodeAttribute(Type = "AI/[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "CheckMeDead")]
    public class CheckMeDead : AICondition
    {
        public override bool Check()
        {
            Character aiOwner = this.AIOwner;
            if (aiOwner == null)
            {
                return false;
            }
            if (aiOwner.IsDead())
            {
                return true;
            }
            return false;
        }
    }
}

