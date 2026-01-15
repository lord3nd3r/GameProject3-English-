/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___WeaponSystem___Scripts___Weapon___DamageBase.cs */
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
	public class DamageBase : MonoBehaviour
	{
		public GameObject Effect;
		[HideInInspector]
		public GameObject Owner;
		public int Damage = 20;
		[HideInInspector]
		public ObjectPool objectPool;
		public string[] TargetTag = new string[1]{"Enemy"};
		public string[] IgnoreTag;
	
		public bool DoDamageCheck (GameObject gob)
		{
			for (int i=0; i<IgnoreTag.Length; i++) {
				if (IgnoreTag [i] == gob.tag)
					return false;
			}
			return true;
		}
		
		
		public void IgnoreSelf (GameObject owner)
		{
			if (GetComponent<Collider>() && owner && owner.GetComponent<Collider>()) {
				Physics.IgnoreCollision (GetComponent<Collider>(), owner.GetComponent<Collider>());
				if (Owner.transform.root) {
					foreach (Collider col in Owner.transform.root.GetComponentsInChildren<Collider>()) {
						Physics.IgnoreCollision (GetComponent<Collider>(), col);
					}
				}
			}
		}
	}
}
