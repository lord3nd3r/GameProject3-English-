/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___AI___ConditionComposites___CheckHostAIState.cs */
﻿using UnityEngine;
using System.Collections;

namespace BVT.AI
{
    [NodeAttribute(Type = "AI/[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", Label = "CheckHostAIState")]
    public class CheckHostAIState : AICondition
    {
        [SerializeField]
        public EAIState ApplyAIState;

        public override string Name
        {
            get { return !Invert ? "[TRANSLATED][TRANSLATED]AI Is " + ApplyAIState.ToString() : string.Format("[TRANSLATED][TRANSLATED]AI Not {0}", ApplyAIState); }
        }

        public override bool Check()
        {
            Character aiOwner = this.AIOwner;
            Character aiHost = aiOwner == null ? null : aiOwner.Host;
            return aiHost == null ? false : aiHost.AIState == ApplyAIState;
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

