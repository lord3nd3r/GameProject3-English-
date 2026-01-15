/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___AI___Actions___TryClearTarget.cs */
﻿using UnityEngine;
using System.Collections;

namespace BVT.AI
{
    [NodeAttribute(Type = "AI/action[TRANSLATED][TRANSLATED]", Label = "TryClearTarget")]
    public class TryClearTarget : AITask
    {
        public override ENST OnExecute()
        {
            Character aiOwner = this.AIOwner;
            if (aiOwner != null)
            {
                CharacterHelper.ClearTarget(aiOwner);
                return ENST.SUCCESS;
            };
            return ENST.FAILURE;
        }
    }
}

