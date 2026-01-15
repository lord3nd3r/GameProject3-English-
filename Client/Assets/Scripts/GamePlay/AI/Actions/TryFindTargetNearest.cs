/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___AI___Actions___TryFindTargetNearest.cs */
﻿using UnityEngine;
using System.Collections;

namespace BVT.AI
{
    [NodeAttribute(Type = "AI/action[TRANSLATED][TRANSLATED]", Label = "TryFindTargetNearest")]
    [NodeName("ff64cb", "<size=10>TryFindTargetNearest</size>")]
    public class TryFindTargetNearest : AITask
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
                Character enemy = aiOwner.FindEnemyNearest(aiOwner.Skill.WarnerDist);
                if (enemy != null)
                {
                    CharacterHelper.SetTarget(aiOwner, enemy);
                }
                return ENST.SUCCESS;
            }
        }
    }
}

