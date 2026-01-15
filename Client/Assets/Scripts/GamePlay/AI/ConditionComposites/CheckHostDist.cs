/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___AI___ConditionComposites___CheckHostDist.cs */
﻿using UnityEngine;
using System.Collections;

namespace BVT.AI
{
    [NodeAttribute(Type = "AI/[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "CheckHostDist")]
    public class CheckHostDist : AICondition
    {
        [NodeVariable]
        public float Distance = 10;

        public override bool Check()
        {
            Character aiOwner = this.AIOwner;
            if (aiOwner == null)
            {
                return false;
            }
            if (aiOwner.Host == null)
            {
                return false;
            }
            Vector3 srcPos = aiOwner.Pos;
            Vector3 tarPos = aiOwner.Host.Pos;
            srcPos.y = 0;
            tarPos.y = 0;
            return Vector3.Distance(srcPos, tarPos) < Distance;
        }

#if UNITY_EDITOR
        public override void DrawNodeWindowContents()
        {
            if (!Invert)
            {
                string s = string.Format("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]<{0}[TRANSLATED]", Distance);
                GUILayout.Label(s);
            }
            else
            {
                string s = string.Format("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]>{0}[TRANSLATED]", Distance);
                GUILayout.Label(s);
            }
        }
#endif

    }
}

