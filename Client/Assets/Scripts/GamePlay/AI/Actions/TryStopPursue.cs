/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___AI___Actions___TryStopPursue.cs */
﻿using UnityEngine;
using System.Collections;

namespace BVT.AI
{
    [NodeAttribute(Type = "AI/action[TRANSLATED][TRANSLATED]", Label = "TryStopPursue")]
    public class TryStopPursue : AITask
    {
        public override ENST OnExecute()
        {
            Character aiOwner = this.AIOwner;
            if (aiOwner == null)
            {
                return ENST.FAILURE;
            }
            else
            {
                aiOwner.Move.Stop();
                return ENST.SUCCESS;
            }
        }
    }
}
