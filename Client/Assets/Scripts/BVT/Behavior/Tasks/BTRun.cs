/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___BVT___Behavior___Tasks___BTRun.cs */
﻿using UnityEngine;
using System.Collections;
using BVT;

namespace BVT
{
    [NodeAttribute(Type = "action[TRANSLATED][TRANSLATED]", Label = "BTRun")]
    public class BTRun : BTTask
    {
        public override ENST OnExecute()
        {
            return ENST.RUNNING;
        }
    }
}

