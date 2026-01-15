using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using BVT;

namespace BVT
{
    [NodeAttribute(Type = "装饰节点", Label = "逆转节点")]
    [NodeDesc("子节点返回Success，则返回Failure；子节点返回Failure，则返回Success")]
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
