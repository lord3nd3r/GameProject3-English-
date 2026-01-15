/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___ResourceFramework___Editor___ResourceAnimOptimize.cs */
﻿using UnityEngine;
using System.Collections;
using UnityEditor;
using System;
using System.IO;
using System.Diagnostics;

class ExportFormate
{
    public static string BINARY = "0";
    public static string ASCII = "1";
}

public class ResourceAnimOptimize
{
    private static int number = 0;
    static string ExePath = "F:/[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]/Unity[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]/FBX/FBXCompress.exe";
    static DateTime time;

    [MenuItem("[TRANSLATED][TRANSLATED]/[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]")]
    static void Execute()
    {
        number = 0;
        time = DateTime.Now;
        foreach (UnityEngine.Object o in Selection.GetFiltered(typeof(AnimationClip), SelectionMode.DeepAssets))
        {
            number++;
            ForFun((GameObject.Instantiate(o) as AnimationClip), EditorUtility.GetAssetPath(o));
        }
        AssetDatabase.SaveAssets();
        Log("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]" + number + "[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]!");
        Log("[TRANSLATED][TRANSLATED]:" + ((DateTime.Now - time).TotalMilliseconds / 1000) + "[TRANSLATED].");
    }

    [MenuItem("[TRANSLATED][TRANSLATED]/[TRANSLATED][TRANSLATED]FBX")]
    static void ExecuteFBX()
    {
        string RootPath = Application.dataPath;
        RootPath = RootPath.Substring(0, RootPath.LastIndexOf("/")) + "/";
        Directory.CreateDirectory("C:/FBXCompress/");
        StreamWriter writer = File.CreateText("C:/FBXCompress/FBX.txt");
        foreach (UnityEngine.Object o in Selection.GetFiltered(typeof(UnityEngine.Object), SelectionMode.DeepAssets))
        {
            string fbxPath = RootPath + AssetDatabase.GetAssetPath(o);
            if (fbxPath.Contains(".FBX") || fbxPath.Contains(".fbx"))
            {
                writer.WriteLine(fbxPath);
            }
        }
        writer.Flush();
        writer.Close();
        Process.Start(ExePath, ExportFormate.BINARY);
    }

    static void ForFun(AnimationClip clip, string clipName)
    {
        AnimationClipCurveData[] curves = AnimationUtility.GetAllCurves(clip);
        Keyframe key;
        Keyframe[] keyFrames;
        foreach (AnimationClipCurveData curveDate in curves)
        {
            keyFrames = curveDate.curve.keys;
            for (int i = 0; i < keyFrames.Length; i++)
            {
                key = keyFrames[i];
                key.value = float.Parse(key.value.ToString("f3"));
                key.inTangent = float.Parse(key.inTangent.ToString("f3"));
                key.outTangent = float.Parse(key.outTangent.ToString("f3"));
                keyFrames[i] = key;
            }
            curveDate.curve.keys = keyFrames;
            clip.SetCurve(curveDate.path, curveDate.type, curveDate.propertyName, curveDate.curve);
        }
        AssetDatabase.CreateAsset(clip, clipName);
    }

    static void Log(string content)
    {
        UnityEngine.Debug.Log(content);
    }
}
