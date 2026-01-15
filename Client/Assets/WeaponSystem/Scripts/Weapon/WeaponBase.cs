/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___WeaponSystem___Scripts___Weapon___WeaponBase.cs */
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
	public class WeaponBase : MonoBehaviour
	{
		[HideInInspector]
		public GameObject Owner;
		[HideInInspector]
		public GameObject Target;
		[HideInInspector]
		public ObjectPool objectPool;
		public string[] TargetTag = new string[1]{"Enemy"};
		public string[] IgnoreTag;
		public bool RigidbodyProjectile;
		public Vector3 TorqueSpeedAxis;
		public GameObject TorqueObject;
	
		public bool DoDamageCheck (GameObject gob)
		{
			for (int i=0; i<IgnoreTag.Length; i++) {
				if (IgnoreTag [i] == gob.tag)
					return false;
			}
			return true;
		}

		public virtual void OnSpawn ()
		{
		
		}
	}
}
