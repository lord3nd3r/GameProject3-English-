/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___BVT___Behavior___Composites___BTParallelHybird.cs */
﻿using UnityEngine;
using System.Collections;
using BVT;
using System.Collections.Generic;

namespace BVT
{
    [NodeAttribute(Type = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "[TRANSLATED][TRANSLATED]-Hybird[TRANSLATED][TRANSLATED]")]
    [NodeDesc("[TRANSLATED][TRANSLATED]count[TRANSLATED]Child Node[TRANSLATED][TRANSLATED]True[TRANSLATED]False[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]")]
    [NodeName("ff64cb", "ParallelHybird")]
    public class BTParallelHybird : BTComposite
    {
        public enum EChildResult
        {
            SUCCESS,
            FAITURE
        }

        [NodeVariable]
        public EChildResult AppointResult = EChildResult.SUCCESS;
        [NodeVariable]
        public int          AppointCount  = 1;

        private List<int>   mFinishChildIndexList    = new List<int>();
        private int         mFinishChildAppointCount = 0;


        public override bool OnEnter()
        {
            if (AppointCount < 1)
            {
                return false;
            }
            if (AppointCount > Children.Count)
            {
                return false;
            }
            return base.OnEnter();
        }

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
                if (AppointResult == EChildResult.SUCCESS)
                {
                    switch (child.State)
                    {
                        case ENST.SUCCESS:
                            mFinishChildIndexList.Add(i);
                            mFinishChildAppointCount++;
                            return ENST.SUCCESS;
                        case ENST.FAILURE:
                            mFinishChildIndexList.Add(i);
                            continue;
                        case ENST.RUNNING:
                            continue;
                    }
                }
                else
                {
                    switch (child.State)
                    {
                        case ENST.SUCCESS:
                            mFinishChildIndexList.Add(i);
                            return ENST.SUCCESS;
                        case ENST.FAILURE:
                            mFinishChildIndexList.Add(i);
                            mFinishChildAppointCount++;
                            continue;
                        case ENST.RUNNING:
                            continue;
                    }
                }
            }
            return mFinishChildAppointCount >= AppointCount ? ENST.SUCCESS : ENST.RUNNING;
        }

        public override void OnReset()
        {
            base.OnReset();
            mFinishChildIndexList.Clear();
            mFinishChildAppointCount = 0;
        }
    }
}

