using UnityEngine;
using System.Collections;

namespace BVT.AI
{
    [NodeAttribute(Type = "AI/action节点", Label = "TryIdle")]
    public class TryIdle : AITask
    {
        public override ENST OnExecute()
        {
            Character aiOwner = this.AIOwner;
            if (aiOwner == null)
            {
                return ENST.FAILURE;
            }
            else
            {
                if(aiOwner.Command.Get<CommandIdle>().Do() == Resp.TYPE_YES)
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
}

