/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___BVT___Behavior___Composites___BTRandomSequence.cs */
﻿using BVT;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using UnityEngine;

namespace BVT
{
    [NodeAttribute(Type = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "[TRANSLATED][TRANSLATED]-[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]")]
    [NodeDesc("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]")]
    [NodeName("b3ff7f", "RandomSequence")]
    public class BTRandomSequence : BTComposite
    {
        private List<int>  mChildIndexList = new List<int>();
        private Stack<int> mChildExecuteIndexList = new Stack<int>();

        public override bool OnEnter()
        {
            base.OnEnter();
            this.ShuffleChildren();
            return true;
        }

        public override ENST OnExecute()
        {
            if(mChildExecuteIndexList.Count>0)
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
                            mChildExecuteIndexList.Pop();
                            break;
                        }
                    case ENST.FAILURE:
                        {
                            return ENST.FAILURE;
                        }
                }
            }
            return mChildExecuteIndexList.Count == 0 ? ENST.SUCCESS : ENST.RUNNING;
        }

        public override void OnReset()
        {
            base.OnReset();
            mChildExecuteIndexList.Clear();
            mChildIndexList.Clear();
        }

        public          void ShuffleChildren()
        {
            mChildIndexList.Clear();
            mChildExecuteIndexList.Clear();
            for (int i = 0; i < Children.Count; ++i)
            {
                mChildIndexList.Add(i);
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

