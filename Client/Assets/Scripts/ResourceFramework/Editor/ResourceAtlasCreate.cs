/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___ResourceFramework___Editor___ResourceAtlasCreate.cs */
﻿using UnityEngine;
using System.Collections;
using UnityEditor;
using System.IO;

public class ResourceAtlasCreate
{
    public static void SetTextureImporterSettings(string path, TextureImporterFormat format, bool isReadEnabled)
    {
        TextureImporter textureImporter = AssetImporter.GetAtPath(path) as TextureImporter;
        if (textureImporter == null)
        {
            return;
        }
        textureImporter.spriteImportMode = SpriteImportMode.None;
        TextureImporterSettings ts = new TextureImporterSettings();
        textureImporter.ReadTextureSettings(ts);
        ts.readable = isReadEnabled;
        ts.mipmapEnabled = false;
        ts.aniso = 4;
        ts.alphaIsTransparency = true;
        ts.wrapMode = TextureWrapMode.Clamp;
        textureImporter.SetTextureSettings(ts);

        switch(EditorUserBuildSettings.activeBuildTarget)
        {
            case BuildTarget.Android:
                TextureImporterPlatformSettings tspAndroid = new TextureImporterPlatformSettings();
                tspAndroid.name = "Android";
                tspAndroid.format = format;
                tspAndroid.overridden = true;
                tspAndroid.maxTextureSize = 1024;
                textureImporter.SetPlatformTextureSettings(tspAndroid);
                break;
            case BuildTarget.iOS:
                TextureImporterPlatformSettings tspiOS = new TextureImporterPlatformSettings();
                tspiOS.name = "iPhone";
                tspiOS.format = format;
                tspiOS.overridden = true;
                tspiOS.maxTextureSize = 1024;
                textureImporter.SetPlatformTextureSettings(tspiOS);
                break;
        }
        AssetDatabase.ImportAsset(path, ImportAssetOptions.ForceUpdate | ImportAssetOptions.ForceSynchronousImport);
        AssetDatabase.SaveAssets();
        AssetDatabase.Refresh();
    }

    public static UIAtlas SetAtlasInfo(GameObject go, string path, Material mat)
    {
        if (AssetDatabase.LoadAssetAtPath(path.Replace(".png", ".txt"), typeof(TextAsset)))
        {
            UIAtlas uiAtlas = go.GetComponent<UIAtlas>();
            uiAtlas.spriteMaterial = mat;
            TextAsset ta = AssetDatabase.LoadAssetAtPath(path.Replace(".png", ".txt"), typeof(TextAsset)) as TextAsset;
            NGUIJson.LoadSpriteData(uiAtlas, ta);
            uiAtlas.MarkAsChanged();
            return uiAtlas;
        }
        return null;
    }

    /// <summary>
    /// [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    /// </summary>
    public static Object CreatePrefab(GameObject go, string name, string path)
    {
        Object tmpPrefab = PrefabUtility.CreateEmptyPrefab(path.Replace(".png", ".prefab"));
        tmpPrefab = PrefabUtility.ReplacePrefab(go, tmpPrefab, ReplacePrefabOptions.ConnectToPrefab);
        Object.DestroyImmediate(go);
        return tmpPrefab;
    }


    /// <summary>
    /// whether[TRANSLATED]alpha[TRANSLATED][TRANSLATED]
    /// </summary>
    /// <param name="_tex"></param>
    /// <returns></returns>
    public static bool HasAlphaChannel(Texture2D _tex)
    {
        for (int i = 0; i < _tex.width; ++i)
            for (int j = 0; j < _tex.height; ++j)
            {
                Color color = _tex.GetPixel(i, j);
                float alpha = color.a;
                if (alpha < 1.0f - 0.001f)
                {
                    return true;
                }
            }
        return false;
    }

    public static void SetTextureReadable(string path)
    {
        TextureImporter textureImporter = AssetImporter.GetAtPath(path) as TextureImporter;
        if (textureImporter == null) return;
        textureImporter.textureType = TextureImporterType.Default;
        textureImporter.isReadable = true;
        textureImporter.SetPlatformTextureSettings("Android", 2048, TextureImporterFormat.RGBA32);
        textureImporter.SetPlatformTextureSettings("Windows", 2048, TextureImporterFormat.RGBA32);
        textureImporter.SetAllowsAlphaSplitting(false);
        AssetDatabase.ImportAsset(path);
    }

    /// <summary>
    /// [TRANSLATED][TRANSLATED]whether[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    /// </summary>
    /// <param name="_path"></param>
    /// <returns></returns>
    public static bool IsTextureFile(string _path)
    {
        string path = _path.ToLower();
        return path.EndsWith(".psd") || path.EndsWith(".tga") || path.EndsWith(".png") || path.EndsWith(".jpg") || path.EndsWith(".dds") || path.EndsWith(".bmp") || path.EndsWith(".tif") || path.EndsWith(".gif");
    }

    /// <summary>
    /// [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    /// </summary>
    /// <param name="path"></param>
    /// <param name="val"></param>
    public static void ShowProgress(string path, float val)
    {
        EditorUtility.DisplayProgressBar("[TRANSLATED][TRANSLATED]handle[TRANSLATED]...", string.Format("Please wait...  Path:{0}", path), val);
    }

    public virtual void CreateUIAtlasPrefab(UnityEngine.Object obj)
    {

    }
}
