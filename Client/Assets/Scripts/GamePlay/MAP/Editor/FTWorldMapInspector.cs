/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___MAP___Editor___FTWorldMapInspector.cs */
﻿using UnityEngine;
using System.Collections;
using UnityEditor;
using System.Collections.Generic;
using CFG;

namespace MAP
{
    [CustomEditor(typeof(FTWorldMap), true)]
    public class FTWorldMapInspector : Editor
    {
        public override void OnInspectorGUI()
        {
            GUILayout.Space(10);
            FTWorldMap worldMap = target as FTWorldMap;
            base.OnInspectorGUI();
            GUILayout.Space(10);
            GUI.color = Color.red;
            GUILayout.BeginHorizontal();
            if (GUILayout.Button("[TRANSLATED][TRANSLATED]", FTGUIStyles.FTButtonStyle, GUILayout.Height(40)))
            {
                worldMap.Import();
            }

            GUI.color = Color.green;
            if (GUILayout.Button("[TRANSLATED][TRANSLATED]", FTGUIStyles.FTButtonStyle, GUILayout.Height(40)))
            {
                worldMap.Export();
            }
            GUILayout.EndHorizontal();
            GUILayout.Space(10);
        }
    }
}