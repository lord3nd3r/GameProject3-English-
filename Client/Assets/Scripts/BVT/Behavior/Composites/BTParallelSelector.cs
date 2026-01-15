/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___BVT___Behavior___Composites___BTParallelSelector.cs */
﻿using BVT;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BVT
{
    [NodeAttribute(Type = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "[TRANSLATED][TRANSLATED]-[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]")]
    [NodeDesc("[TRANSLATED]True[TRANSLATED][TRANSLATED][TRANSLATED]True，[TRANSLATED]False[TRANSLATED][TRANSLATED][TRANSLATED]False")]
    [NodeName("ff64cb", "ParallelSelector")]
    public class BTParallelSelector : BTComposite
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
                switch(child.State)
                {
                    case ENST.SUCCESS:
                        mFinishChildIndexList.Add(i);
                        return ENST.SUCCESS;
                    case ENST.FAILURE:
                        mFinishChildIndexList.Add(i);
                        continue;
                    case ENST.RUNNING:
                        continue;
                }
            }
            return mFinishChildIndexList.Count >= Children.Count ? ENST.FAILURE : ENST.RUNNING;
        }

        public override void OnReset()
        {
            base.OnReset();
            mFinishChildIndexList.Clear();
        }
    }
}
