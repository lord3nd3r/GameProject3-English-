/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___BVT___Behavior___Composites___BTParallelSequence.cs */
﻿using BVT;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BVT
{
    [NodeAttribute(Type = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "[TRANSLATED][TRANSLATED]-[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]")]
    [NodeDesc("[TRANSLATED]False[TRANSLATED][TRANSLATED][TRANSLATED]False，[TRANSLATED]True[TRANSLATED][TRANSLATED][TRANSLATED]True")]
    [NodeName("ff64cb", "ParallelSequence")]
    public class BTParallelSequence : BTComposite
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
                switch (child.State)
                {
                    case ENST.SUCCESS:
                        mFinishChildIndexList.Add(i);
                        continue;
                    case ENST.FAILURE:
                        mFinishChildIndexList.Add(i);
                        return ENST.FAILURE;
                    case ENST.RUNNING:
                        continue;
                }
            }
            return mFinishChildIndexList.Count >= Children.Count ? ENST.SUCCESS : ENST.RUNNING;
        }

        public override void OnReset()
        {
            base.OnReset();
            mFinishChildIndexList.Clear();
        }
    }
}