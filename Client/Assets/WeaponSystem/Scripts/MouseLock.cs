/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___WeaponSystem___Scripts___MouseLock.cs */
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
	public static class MouseLock
	{
		private static bool mouseLocked;
	
		public static bool MouseLocked {
			get {
				return mouseLocked;
			}
			set {
				mouseLocked = value;
			
			#if UNITY_4_6
				Screen.lockCursor = mouseLocked;
			#else
				Cursor.visible = !value;
				if (Cursor.visible) {	
					Cursor.lockState = CursorLockMode.None;
				} else {
					Cursor.lockState = CursorLockMode.Locked;
			
				}
			#endif
			}
		}
	}
}

