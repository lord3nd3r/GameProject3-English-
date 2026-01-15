/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___WeaponSystem___Scripts___MenuGUI.cs */
/*
http://www.cgsoso.com/forum-211-1.html

CG[TRANSLATED][TRANSLATED] Unity3d [TRANSLATED][TRANSLATED]Unity3d[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED] [TRANSLATED][TRANSLATED]VIP[TRANSLATED][TRANSLATED]！

CGSOSO [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]CG[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]。

[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]！

daily assets update for try.

U should buy the asset from home store if u use it in your project!
*/

using UnityEngine;
using System.Collections;

namespace HWRWeaponSystem
{
	public class MenuGUI : MonoBehaviour
	{

		public Texture2D logo;
		public GUISkin skin;

		void Start ()
		{
	
		}

		void Update ()
		{
			MouseLock.MouseLocked = false;
		}
	
		void OnGUI ()
		{
			if (skin)
				GUI.skin = skin;
		
			GUI.skin.button.fontSize = 18;
			GUI.DrawTexture (new Rect (Screen.width / 2 - logo.width / 2, 10, logo.width, logo.height), logo);
			if (GUI.Button (new Rect (Screen.width / 2 - 400, 300, 200, 30), "Demo 1"))
				Application.LoadLevel ("Demo1");
			if (GUI.Button (new Rect (Screen.width / 2 - 400, 340, 200, 30), "Demo 2"))	
				Application.LoadLevel ("Demo2");
			if (GUI.Button (new Rect (Screen.width / 2 - 400, 380, 200, 30), "3D First Person"))	
				Application.LoadLevel ("Demo3");
			if (GUI.Button (new Rect (Screen.width / 2 - 400, 420, 200, 30), "2D Side Scrolling"))
				Application.LoadLevel ("Demo2D");
			if (GUI.Button (new Rect (Screen.width / 2 - 400, 460, 200, 30), "Tower Defend"))
				Application.LoadLevel ("TD");
		
			if (GUI.Button (new Rect (Screen.width - 320, Screen.height - 50, 300, 30), "Get this project"))
				Application.OpenURL ("https://www.assetstore.unity3d.com/#/content/7676");

		
		
		}
	}
}
