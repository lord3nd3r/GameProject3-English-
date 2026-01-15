/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___BVT___Behavior___Decorators___BTUntilFailure.cs */
﻿using UnityEngine;
using System.Collections;
using BVT;

namespace BVT
{
    [NodeAttribute(Type = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "BTUntilFailure")]
    [NodeDesc("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]Failure，[TRANSLATED][TRANSLATED][TRANSLATED]Failure")]
    [NodeName("05CBF2", "UntilFailure")]
    public class BTUntilFailure : BTDecorator
    {
        public override ENST OnExecute()
        {
            FirstChild.OnTick();
            switch (FirstChild.State)
            {
                case ENST.FAILURE:
                    return ENST.FAILURE;
                case ENST.SUCCESS:
                    FirstChild.OnReset();
                    return ENST.RUNNING;
                default:
                    return ENST.RUNNING;
            }
        }
    }
}

