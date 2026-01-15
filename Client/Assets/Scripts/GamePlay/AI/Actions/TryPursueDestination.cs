/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___AI___Actions___TryPursueDestination.cs */
﻿using UnityEngine;
using System.Collections;

namespace BVT.AI
{
    [NodeAttribute(Type = "AI/action[TRANSLATED][TRANSLATED]", Label = "TryPursueDestination")]
    public class TryPursueDestination : AITask
    {
        [SerializeField]
        public Vector3 DestPosition = Vector3.zero;

        public override ENST OnExecute()
        {
            Character aiOwner = this.AIOwner;
            if (aiOwner != null)
            {
                Resp resp = aiOwner.Command.Get<CommandMove>().Update(DestPosition, null).Do();
                return resp == Resp.TYPE_YES ? ENST.SUCCESS : ENST.FAILURE;
            };
            return ENST.FAILURE;
        }
    }
}

