using UnityEngine;
using System.Collections;
using BVT;

namespace BVT
{
    [NodeAttribute(Type = "装饰节点", Label = "BTUntilSuccess")]
    [NodeDesc("直到子节点返回Success，才返回Success")]
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

