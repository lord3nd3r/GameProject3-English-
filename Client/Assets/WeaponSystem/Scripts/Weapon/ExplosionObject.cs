/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___WeaponSystem___Scripts___Weapon___ExplosionObject.cs */
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
	public class ExplosionObject : MonoBehaviour
	{
		public Vector3 Force;
		public GameObject Prefab;
		public int Num;
		public int Scale = 20;
		public AudioClip[] Sounds;
		public float LifeTimeObject = 2;
		public bool RandomScale;
	
		private void OnEnable ()
		{

			if (Sounds.Length > 0) {
				AudioSource.PlayClipAtPoint (Sounds [Random.Range (0, Sounds.Length)], transform.position);
			}
			if (Prefab) {
				for (int i = 0; i < Num; i++) {
					Vector3 pos = new Vector3 (Random.Range (-10, 10), Random.Range (-10, 20), Random.Range (-10, 10)) / 10f;
				
					GameObject obj;
					if (WeaponSystem.Pool != null) {
						obj = WeaponSystem.Pool.Instantiate (Prefab, transform.position + pos, Random.rotation, LifeTimeObject);
					} else {
						obj = (GameObject)Instantiate (Prefab, transform.position + pos, Random.rotation);
						Destroy (obj, LifeTimeObject);
					}
                	
					float scale = Scale;
					if (RandomScale) {
						scale = Random.Range (1, Scale);
					}

					if (scale > 0)
						obj.transform.localScale = new Vector3 (scale, scale, scale);
					if (obj.GetComponent<Rigidbody>()) {
						Vector3 force = new Vector3 (Random.Range (-Force.x, Force.x), Random.Range (-Force.y, Force.y), Random.Range (-Force.z, Force.z));
						obj.GetComponent<Rigidbody>().AddForce (force);
					}
				}
			}
		}
	
		private void Start ()
		{
		
		}

	}
}
