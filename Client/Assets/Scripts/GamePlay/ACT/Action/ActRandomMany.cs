/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___ACT___Action___ActRandomMany.cs */
﻿using UnityEngine;
using System.Collections;
using System.Collections.Generic;

namespace ACT
{
    public class ActRandomMany : ActItem
    {
        [SerializeField]
        public int            RandomNum  = 1; //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]count

        public List<ActItem>  RandomList
        {
            get;
            private set;
        }

        public ActRandomMany()
        {
            EventType = EActEventType.Instant;
        }

        protected override bool Trigger()
        {
            base.Trigger();
            this.RandomList = GTTools.RandomListFromBigList(Children, RandomNum);
            return true;
        }

        protected override void ExecuteChildren()
        {
            this.LoopChildren(RandomList);
        }
    }
}

