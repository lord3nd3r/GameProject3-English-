/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___BVT___Behavior___Composites___BTParallel.cs */
﻿using UnityEngine;
using System.Collections;
using BVT;
using System.Collections.Generic;

namespace BVT
{
    [NodeAttribute(Type = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]")]
    [NodeDesc("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]“Success”[TRANSLATED]“Failure”[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]running[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]")]
    [NodeName("ff64cb", "Parallel")]
    public class BTParallel : BTComposite
    {
        private List<int> mFinishChildIndexList = new List<int>();

        public override ENST OnExecute()
        {
            for (int i = 0; i < Children.Count; i++)
            {
                if (mFinishChildIndexList.Contains(i))
                {
                    continue;
                }
                Node child = Children[i];
                child.OnTick();
                if (child.State != ENST.RUNNING)
                {
                    mFinishChildIndexList.Add(i);
                }
            }
            return mFinishChildIndexList.Count < Children.Count ? ENST.RUNNING : ENST.SUCCESS;
        }

        public override void OnReset()
        {
            base.OnReset();
            mFinishChildIndexList.Clear();
        }
    }
}
