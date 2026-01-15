/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___WeaponSystem___Scripts___Weapon___Explosion.cs */
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
	public class Explosion : MonoBehaviour
	{
		public int Force;
		public int Radius;
		public AudioClip[] Sounds;

		private void Start ()
		{
      		
		}
	
		private void OnEnable ()
		{
			Vector3 explosionPos = transform.position;
			Collider[] colliders = Physics.OverlapSphere (explosionPos, Radius);
			if (Sounds.Length > 0) {
				AudioSource.PlayClipAtPoint (Sounds [Random.Range (0, Sounds.Length)], transform.position);
			}
			foreach (Collider hit in colliders) {
				if (hit.GetComponent<Rigidbody>()) {
					hit.GetComponent<Rigidbody>().AddExplosionForce (Force, explosionPos, Radius, 3.0f);
				}
			}
		}
	}
}
