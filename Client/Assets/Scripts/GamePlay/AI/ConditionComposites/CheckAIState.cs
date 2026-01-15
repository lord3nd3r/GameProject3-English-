/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___AI___ConditionComposites___CheckAIState.cs */
﻿using UnityEngine;
using System.Collections;

namespace BVT.AI
{
    [NodeAttribute(Type = "AI/[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "CheckAIState")]
    public class CheckAIState : AICondition
    {
        [SerializeField]
        public EAIState ApplyAIState;

        public override string Name
        {
            get { return !Invert ? "AI Is "+ApplyAIState.ToString() : string.Format("AI Not {0}", ApplyAIState); }
        }

        public override bool Check()
        {
            Character aiOwner = this.AIOwner;
            return aiOwner == null ? false : aiOwner.AIState == ApplyAIState;
        }

#if UNITY_EDITOR
        public override void DrawNodeInspectorGUI()
        {
            base.DrawNodeInspectorGUI();
            this.ApplyAIState = (EAIState)UnityEditor.EditorGUILayout.EnumPopup("ApplyAIState", ApplyAIState);
        }       
#endif
    }

}
