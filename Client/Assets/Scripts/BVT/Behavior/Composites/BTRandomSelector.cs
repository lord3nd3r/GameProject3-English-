/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___BVT___Behavior___Composites___BTRandomSelector.cs */
﻿using BVT;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BVT
{
    [NodeAttribute(Type = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "[TRANSLATED][TRANSLATED]-[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]")]
    [NodeDesc("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]First True Child Node[TRANSLATED][TRANSLATED][TRANSLATED]")]
    [NodeName("b3ff7f", "RandomSelector")]
    public class BTRandomSelector : BTSelector
    {
        private List<int>  mChildIndexList;
        private Stack<int> mChildExecuteIndexList = new Stack<int>();

        public override bool OnEnter()
        {
            base.OnEnter();
            this.ShuffleChildren();
            return true;
        }

        public override ENST OnExecute()
        {
            if (mChildExecuteIndexList.Count > 0)
            {
                int activeIndex = mChildExecuteIndexList.Peek();
                Node child = Children[activeIndex];
                child.OnTick();
                switch (child.State)
                {
                    case ENST.RUNNING:
                        {
                            return ENST.RUNNING;
                        }
                    case ENST.SUCCESS:
                        {
                            return ENST.SUCCESS;
                        }
                    case ENST.FAILURE:
                        {
                            mChildExecuteIndexList.Pop();
                            break;
                        }
                }
            }
            return mChildExecuteIndexList.Count == 0 ? ENST.FAILURE : ENST.RUNNING;
        }

        public override void OnReset()
        {
            base.OnReset();
            mChildExecuteIndexList.Clear();
        }

        public void          ShuffleChildren()
        {
            if (mChildIndexList == null)
            {
                mChildIndexList = new List<int>();
                for (int i = 0; i < Children.Count; ++i)
                {
                    mChildIndexList.Add(i);
                }
            }

            for (int i = mChildIndexList.Count; i > 0; --i)
            {
                int j = UnityEngine.Random.Range(0, i);
                int index = mChildIndexList[j];
                mChildExecuteIndexList.Push(index);
                mChildIndexList[j] = mChildIndexList[i - 1];
                mChildIndexList[i - 1] = index;
            }
        }
    }
}
