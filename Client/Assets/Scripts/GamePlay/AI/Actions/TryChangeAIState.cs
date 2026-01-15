/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___AI___Actions___TryChangeAIState.cs */
﻿using UnityEngine;
using System.Collections;

namespace BVT.AI
{
    [NodeAttribute(Type = "AI/action[TRANSLATED][TRANSLATED]", Label = "TryChangeAIState")]
    [NodeName("ff64cb", "<size=12>TryChangeAIState</size>")]
    public class TryChangeAIState : AITask
    {
        [SerializeField]
        public EAIState   ApplyAIState = EAIState.IDLE;

        public override ENST OnExecute()
        {
            Character aiOwner = this.AIOwner;
            if (aiOwner != null)
            {
                if(aiOwner.AIState != ApplyAIState)
                {
                    aiOwner.AIState = ApplyAIState;
                    aiOwner.StopMove();
                }
                return ENST.SUCCESS;
            }
            else
            {
                return ENST.FAILURE;
            }
        }

#if UNITY_EDITOR
        public override void DrawNodeInspectorGUI()
        {
            base.DrawNodeInspectorGUI();
            this.ApplyAIState = (EAIState)UnityEditor.EditorGUILayout.EnumPopup("ApplyAIState", (System.Enum)ApplyAIState);
        }

        public override void DrawNodeWindowContents()
        {
            base.DrawNodeWindowContents();
            GUILayout.Label(string.Format("[TRANSLATED][TRANSLATED][TRANSLATED]：<color=#ff0000>{0}</color>", AIHelper.GetAIStateName(ApplyAIState)));   
        }
#endif
    }
}

