/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___BVT___Behavior___Composites___BTSequence.cs */
﻿using UnityEngine;
using System.Collections;
using BVT;
using System.Collections.Generic;

namespace BVT
{
    [NodeAttribute(Type = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]")]
    [NodeDesc("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]FALSE，[TRANSLATED][TRANSLATED][TRANSLATED]FALSE；[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]TRUE")]
    [NodeName("bf7fff", " Sequence")]
    public class BTSequence : BTComposite
    {
        private int mActiveChildIndex = 0;

        public override ENST OnExecute()
        {
            for (; mActiveChildIndex < Children.Count; mActiveChildIndex++)
            {
                Node child = Children[mActiveChildIndex];
                child.OnTick();
                switch (child.State)
                {
                    case ENST.RUNNING:
                        {
                            return ENST.RUNNING;
                        }
                    case ENST.SUCCESS:
                        {
                            continue;
                        }
                    case ENST.FAILURE:
                        {
  
                            return ENST.FAILURE;
                        }
                }
            }
            return ENST.SUCCESS;
        }

        public override void OnReset()
        {
            base.OnReset();
            mActiveChildIndex = 0;
        }
    }
}
