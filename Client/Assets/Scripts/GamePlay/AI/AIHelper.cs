/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___AI___AIHelper.cs */
﻿using UnityEngine;
using System.Collections;

namespace BVT.AI
{
    public class AIHelper
    {
        public static Character GetAIInterface(Transform trans)
        {
            if (trans == null)
            {
                return null;
            }
            CharacterView view = trans.GetComponent<CharacterView>();
            if (view == null)
            {
                return null;
            }
            return view.Owner;
        }

        public static Character GetAIInterface(GameObject go)
        {
            if (go == null)
            {
                return null;
            }
            CharacterView view = go.GetComponent<CharacterView>();
            if (view == null)
            {
                return null;
            }
            return view.Owner;
        }

        public static Character GetAIInterface(ShareTransform shareObj)
        {
            if (shareObj != null)
            {
                return GetAIInterface(shareObj.V);
            }
            else
            {
                return null;
            }
        }

        public static string    GetAIStateName(EAIState aiState)
        {
            switch (aiState)
            {
                case EAIState.IDLE:
                    return "[TRANSLATED][TRANSLATED]";
                case EAIState.BORN:
                    return "[TRANSLATED][TRANSLATED]";
                case EAIState.PATROL:
                    return "[TRANSLATED][TRANSLATED]";
                case EAIState.FOLLOW:
                    return "[TRANSLATED][TRANSLATED]";
                case EAIState.ESCAPE:
                    return "[TRANSLATED][TRANSLATED]";
                case EAIState.CHASE:
                    return "[TRANSLATED][TRANSLATED]";
                case EAIState.BACK:
                    return "[TRANSLATED][TRANSLATED]";
                case EAIState.FIGHT:
                    return "[TRANSLATED][TRANSLATED]";
                case EAIState.DEAD:
                    return "[TRANSLATED][TRANSLATED]";
                default:
                    return "[TRANSLATED][TRANSLATED]";
            }
        }
    }
}