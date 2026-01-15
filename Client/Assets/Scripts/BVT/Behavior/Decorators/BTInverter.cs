/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___BVT___Behavior___Decorators___BTInverter.cs */
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using BVT;

namespace BVT
{
    [NodeAttribute(Type = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]")]
    [NodeDesc("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]Success，[TRANSLATED][TRANSLATED][TRANSLATED]Failure；[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]Failure，[TRANSLATED][TRANSLATED][TRANSLATED]Success")]
    [NodeName("05CBF2", "Inverter")]
    public class BTInverter : BTDecorator
    {
        public override ENST OnExecute()
        {
            FirstChild.OnTick();
            switch (FirstChild.State)
            {
                case ENST.SUCCESS:
                    return ENST.FAILURE;
                case ENST.FAILURE:
                    return ENST.SUCCESS;
                default:
                    return FirstChild.State;
            }
        }
    }
}
