/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___AI___Actions___TryCastSkill.cs */
﻿using UnityEngine;
using System.Collections;
using ACT;

namespace BVT.AI
{
    [NodeAttribute(Type = "AI/action[TRANSLATED][TRANSLATED]", Label = "TryCastSkill")]
    public class TryCastSkill : AITask
    {
        public override ENST OnExecute()
        {
            Character aiOwner = this.AIOwner;
            if (aiOwner == null)
            {
                return ENST.FAILURE;
            }
            ActSkill skill = aiOwner.Skill.SelectSkillByEnemy(aiOwner.Target);
            if (skill == null)
            {
                return ENST.FAILURE;
            }
            if (aiOwner.Command.Get<CommandUseSkill>().Update(skill.ID).Do() == Resp.TYPE_YES)
            {
                return ENST.SUCCESS;
            }
            else
            {
                return ENST.FAILURE;
            }
        }
    }
}

