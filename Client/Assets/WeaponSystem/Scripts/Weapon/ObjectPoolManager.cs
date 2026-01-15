/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___WeaponSystem___Scripts___Weapon___ObjectPoolManager.cs */
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
using System.Collections.Generic;

namespace HWRWeaponSystem
{
	public class ObjectPoolManager : MonoBehaviour
	{

		private List<ObjectPool> usedObject;

		void Start ()
		{
			usedObject = new List<ObjectPool> ();
		}

		public GameObject Instantiate (GameObject obj, Vector3 position, Quaternion rotation, float lifeTime)
		{
			if (usedObject == null)
				return null;
		
			foreach (ObjectPool bu in usedObject) {
				if (bu != null) {
					if (bu.Prefab.gameObject == obj.gameObject) {
						if (bu.Active == false) {
							bu.OnSpawn (position, obj.transform.localScale, rotation, obj, lifeTime);
							return bu.gameObject;
						}
					}
				}
			}
		
			GameObject newobj = (GameObject)GameObject.Instantiate (obj.gameObject, position, obj.transform.rotation);
			ObjectPool newpoolobj = newobj.GetComponent<ObjectPool> ();

			if (newpoolobj != null) {
				newpoolobj.OnSpawn (position, newobj.transform.localScale, rotation, obj, lifeTime);
				usedObject.Add (newpoolobj);
			}
		
			return newobj;
		}
	
		public GameObject Instantiate (GameObject obj, Vector3 position, Quaternion rotation)
		{
			if (usedObject == null)
				return null;
		
			foreach (ObjectPool bu in usedObject) {
				if (bu != null) {
					if (bu.Prefab.gameObject == obj.gameObject) {
						if (bu.Active == false) {
							bu.OnSpawn (position, obj.transform.localScale, rotation, obj, -1);
							return bu.gameObject;
						}
					}
				}
			}
		
			GameObject newobj = (GameObject)GameObject.Instantiate (obj.gameObject, position, obj.transform.rotation);
			ObjectPool newpoolobj = newobj.GetComponent<ObjectPool> ();

			if (newpoolobj != null) {
				newpoolobj.OnSpawn (position, newobj.transform.localScale, rotation, obj, -1);
				usedObject.Add (newpoolobj);
			}
		
			return newobj;
		}
	}
}
