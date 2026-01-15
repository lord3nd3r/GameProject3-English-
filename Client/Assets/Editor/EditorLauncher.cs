/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Editor___EditorLauncher.cs */
﻿using UnityEngine;
using UnityEditor;

namespace EDT
{
    [CustomEditor(typeof(GTLauncher), false)]
    public class EditorLauncher : Editor
    {
        public override void OnInspectorGUI()
        {
            base.OnInspectorGUI();
            GTLauncher manager = target as GTLauncher;

            EditorGUILayout.LabelField("Current scene name",   manager.CurrSceneName);
            EditorGUILayout.LabelField("Current game status", manager.CurrSceneType.ToString());
            EditorGUILayout.LabelField("Next game status", manager.NextSceneType.ToString());

            manager.UseGuide     = EditorGUILayout.Toggle("Use novice guide", manager.UseGuide);
            bool musicActive  = EditorGUILayout.Toggle("shutdown[TRANSLATED][TRANSLATED]", manager.MusicDisable);
            if(manager.MusicDisable != musicActive)
            {
                manager.MusicDisable = musicActive;
                PlayerPrefs.SetInt(GTAudioManager.MUSIC_ACTIVE_KEY, manager.MusicDisable ? 1 : 0);
            }
            manager.TestScene    = EditorGUILayout.Toggle("[TRANSLATED][TRANSLATED]", manager.TestScene);
            if(manager.TestScene)
            {
                manager.TestActorID = EditorGUILayout.IntField("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]ID", manager.TestActorID);
            }
        }
    }
}