/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___AI___ConditionComposites___CheckHomeDist.cs */
﻿using UnityEngine;
using System.Collections;

namespace BVT.AI
{
    [NodeAttribute(Type = "AI/[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "CheckHomeDist")]
    public class CheckHomeDist : AICondition
    {
        [SerializeField]
        public ShareFloat Distance;

        public override void OnCreate()
        {
            this.Distance = NodeFactory.CreateShareObject<ShareFloat>(Tree.Blackboard);
        }

        public override bool Check()
        {
            Character aiOwner = this.AIOwner;
            if (aiOwner == null)
            {
                return false;
            }
            Vector3 srcPos = aiOwner.Pos;
            Vector3 tarPos = aiOwner.BornData.Pos;
            srcPos.y = 0;
            tarPos.y = 0;
            return Vector3.Distance(srcPos, tarPos) < Distance.V;
        }

#if UNITY_EDITOR
        public override void DrawNodeWindowContents()
        {
            if (!Invert)
            {
                string s = string.Format("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]<{0}[TRANSLATED]", Distance.ToEncode());
                GUILayout.Label(s);
            }
            else
            {
                string s = string.Format("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]>{0}[TRANSLATED]", Distance.ToEncode());
                GUILayout.Label(s);
            }
        }

        public override void DrawNodeInspectorGUI()
        {
            base.DrawNodeInspectorGUI();
            BTHelper.DrawCoolTitle("ShareObjects");
            this.Distance.DrawGUI("Distance");
        }
#endif
    }
}

