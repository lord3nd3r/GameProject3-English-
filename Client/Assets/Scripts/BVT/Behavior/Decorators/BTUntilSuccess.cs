/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___BVT___Behavior___Decorators___BTUntilSuccess.cs */
﻿using UnityEngine;
using System.Collections;
using BVT;

namespace BVT
{
    [NodeAttribute(Type = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "BTUntilSuccess")]
    [NodeDesc("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]Success，[TRANSLATED][TRANSLATED][TRANSLATED]Success")]
    [NodeName("05CBF2", "UntilSuccess")]
    public class BTUntilSuccess : BTDecorator
    {
        public override ENST OnExecute()
        {
            FirstChild.OnTick();
            switch (FirstChild.State)
            {
                case ENST.SUCCESS:
                    return ENST.SUCCESS;
                case ENST.FAILURE:
                    FirstChild.OnReset();
                    return ENST.RUNNING;
                default:
                    return ENST.RUNNING;
            }
        }
    }
}

