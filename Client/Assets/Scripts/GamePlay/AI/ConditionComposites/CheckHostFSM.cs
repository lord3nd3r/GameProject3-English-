/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___AI___ConditionComposites___CheckHostFSM.cs */
﻿using UnityEngine;
using System.Collections;

namespace BVT.AI
{
    [NodeAttribute(Type = "AI/[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "CheckHostFSM")]
    public class CheckHostFSM : AICondition
    {
        [SerializeField]
        public FSMState ApplyFSM;

        public override bool Check()
        {
            Character aiOwner = this.AIOwner;
            if (aiOwner == null)
                return false;
            if (aiOwner.Host == null)
                return false;
            return aiOwner.Host.FSM == ApplyFSM;
        }

#if UNITY_EDITOR
        public override void DrawNodeWindowContents()
        {
            if (!Invert)
            {
                string s = string.Format("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]{0}[TRANSLATED][TRANSLATED]", ApplyFSM);
                GUILayout.Label(s);
            }
            else
            {
                string s = string.Format("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]{0}[TRANSLATED][TRANSLATED]", ApplyFSM);
                GUILayout.Label(s);
            }
        }

        public override void DrawNodeInspectorGUI()
        {
            base.DrawNodeInspectorGUI();
            this.ApplyFSM = (FSMState)UnityEditor.EditorGUILayout.EnumPopup("ApplyFSM", (System.Enum)ApplyFSM);
        }
#endif
    }
}

