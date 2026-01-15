/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___BVT___Behavior___Decorators___BTInterrupt.cs */
﻿using UnityEngine;
using System.Collections;
using BVT;

namespace BVT
{
    [NodeAttribute(Type = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]")]
    [NodeDesc("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED]Failure；[TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED]running[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]Success[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]Failure")]
    [NodeName("05CBF2", "Interrupt")]
    public class BTInterrupt : BTDecorator
    {
        [SerializeField]
        public ShareBool Condition;

        public override void OnCreate()
        {
            this.Condition = NodeFactory.CreateShareObject<ShareBool>(this.Tree.Blackboard);
        }

        public override bool OnEnter()
        {
            base.OnEnter();
            return FirstChild != null;
        }

        public override ENST OnExecute()
        {
            if (Condition.V == false)
            {
                FirstChild.OnTick();
                return FirstChild.State;
            }
            else
            {
                FirstChild.OnExit(ENST.FAILURE);
                return ENST.FAILURE;
            }
        }

#if UNITY_EDITOR
        public override void DrawNodeWindowContents()
        {
            base.DrawNodeWindowContents();
            GUILayout.Label(string.Format("IF {0}", Condition.key));
        }

        public override void DrawNodeInspectorGUI()
        {
            base.DrawNodeInspectorGUI();
            this.Condition.DrawGUI("Condition");
        }
#endif
    }
}

