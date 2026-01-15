/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___BVT___Behavior___Decorators___BTReturnFailure.cs */
﻿using UnityEngine;
using System.Collections;
using BVT;

namespace BVT
{
    [NodeAttribute(Type = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "Failure[TRANSLATED][TRANSLATED]")]
    [NodeDesc("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]Success[TRANSLATED]Failure，[TRANSLATED][TRANSLATED][TRANSLATED]Failure")]
    [NodeName("05CBF2", "ReturnFailure")]
    public class BTReturnFailure : BTDecorator
    {
        public override ENST OnExecute()
        {
            FirstChild.OnTick();
            switch (FirstChild.State)
            {
                case ENST.SUCCESS:
                case ENST.FAILURE:
                    return ENST.FAILURE;
                default:
                    return FirstChild.State;
            }
        }
    }
}
