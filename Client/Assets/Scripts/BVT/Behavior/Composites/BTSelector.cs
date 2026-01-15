/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___BVT___Behavior___Composites___BTSelector.cs */
﻿using UnityEngine;
using System.Collections;
using BVT;

namespace BVT
{
    [NodeAttribute(Type = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]")]
    [NodeDesc("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]TRUE，[TRANSLATED][TRANSLATED][TRANSLATED]TRUE；[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]FALSE")]
    [NodeName("b3ff7f", "Selector")]
    public class BTSelector : BTComposite
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
                            return ENST.SUCCESS;
                        }
                    case ENST.FAILURE:
                        {
                            continue;                          
                        }
                }
            }
            return ENST.FAILURE;
        }

        public override void OnReset()
        {
            base.OnReset();
            mActiveChildIndex = 0;
        }
    }
}
