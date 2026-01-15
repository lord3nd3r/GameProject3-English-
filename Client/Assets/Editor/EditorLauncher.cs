using UnityEngine;
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
            bool musicActive  = EditorGUILayout.Toggle("关闭音乐", manager.MusicDisable);
            if(manager.MusicDisable != musicActive)
            {
                manager.MusicDisable = musicActive;
                PlayerPrefs.SetInt(GTAudioManager.MUSIC_ACTIVE_KEY, manager.MusicDisable ? 1 : 0);
            }
            manager.TestScene    = EditorGUILayout.Toggle("测试", manager.TestScene);
            if(manager.TestScene)
            {
                manager.TestActorID = EditorGUILayout.IntField("测试角色ID", manager.TestActorID);
            }
        }
    }
}