using UnityEngine;
using System.Collections;
using BVT;

namespace BVT
{
    [NodeAttribute(Type = "装饰节点", Label = "Failure节点")]
    [NodeDesc("无论子节点返回Success或Failure，均返回Failure")]
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
