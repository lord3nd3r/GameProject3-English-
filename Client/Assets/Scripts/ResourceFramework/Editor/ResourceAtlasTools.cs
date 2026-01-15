/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___ResourceFramework___Editor___ResourceAtlasTools.cs */
﻿using UnityEngine;
using System.Collections;
using UnityEditor;
using System.IO;


public class ResourceAtlasTools : Editor
{
    [MenuItem("[TRANSLATED][TRANSLATED]handle/[TRANSLATED][TRANSLATED][TRANSLATED]")]
    static void A()  
    {    
        ResourceAtlasCreate_RGBA32 ra = new ResourceAtlasCreate_RGBA32();
        ra.CreateUIAtlasPrefab(Selection.activeObject);
    }


    [MenuItem("[TRANSLATED][TRANSLATED]handle/[TRANSLATED][TRANSLATED][TRANSLATED]")]
    static void B_2()
    {
        ResourceAtlasCreate_RGBA16 ra = new ResourceAtlasCreate_RGBA16();
        ra.CreateUIAtlasPrefab(Selection.activeObject);
    }

    [MenuItem("[TRANSLATED][TRANSLATED]handle/[TRANSLATED][TRANSLATED][TRANSLATED]")]
    static void C()
    {
        switch (EditorUserBuildSettings.activeBuildTarget)
        {
            case BuildTarget.Android:
                {
                    ResourceAtlasCreate_ETC1_Alpha ra = new ResourceAtlasCreate_ETC1_Alpha();
                    ra.CreateUIAtlasPrefab(Selection.activeObject);
                }
                break;
            case BuildTarget.iOS:
                {
                    ResourceAtlasCreate_PVRTC4 ra = new ResourceAtlasCreate_PVRTC4();
                    ra.CreateUIAtlasPrefab(Selection.activeObject);
                }
                break;
            case BuildTarget.StandaloneWindows64:
            case BuildTarget.StandaloneWindows:
                {
                    ResourceAtlasCreate_RGBA32 ra = new ResourceAtlasCreate_RGBA32();
                    ra.CreateUIAtlasPrefab(Selection.activeObject);
                }
                break;
        }
    }
}
