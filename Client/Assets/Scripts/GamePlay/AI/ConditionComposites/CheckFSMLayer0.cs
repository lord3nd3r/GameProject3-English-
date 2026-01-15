/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___AI___ConditionComposites___CheckFSMLayer0.cs */
﻿using UnityEngine;
using System.Collections;

namespace BVT.AI
{
    [NodeAttribute(Type = "AI/[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "CheckFSMLayer0")]
    public class CheckFSMLayer0 : AICondition
    {
        public override bool Check()
        {
            Character aiOwner = this.AIOwner;
            return aiOwner == null ? false : aiOwner.IsFSMLayer0();
        }
    }
}

