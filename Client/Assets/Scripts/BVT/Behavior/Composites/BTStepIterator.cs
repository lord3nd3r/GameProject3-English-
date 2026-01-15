/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___BVT___Behavior___Composites___BTStepIterator.cs */
﻿using UnityEngine;
using System.Collections;
using BVT;

namespace BVT
{
    [NodeAttribute(Type = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]")]
    [NodeName("ff64cb", "StepIterator")]
    public class BTStepIterator : BTComposite
    {
        private int mCurrent;

        public override bool OnEnter()
        {
            base.OnEnter();
            return Children.Count > 0;
        }

        public override ENST OnExecute()
        {
            mCurrent = mCurrent % Children.Count;
            Children[mCurrent].OnTick();
            return Children[mCurrent].State;
        }

        public override void OnReset()
        {
            base.OnReset();
            mCurrent++;
        }
    }
}


