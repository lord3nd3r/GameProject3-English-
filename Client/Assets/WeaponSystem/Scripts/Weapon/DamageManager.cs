/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___WeaponSystem___Scripts___Weapon___DamageManager.cs */
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
	public class DamageManager : MonoBehaviour
	{
		public AudioClip[] HitSound;
		public GameObject Effect;
		public int HP = 100;
		private ObjectPool objPool;

		private void Awake ()
		{
			objPool = this.GetComponent<ObjectPool> ();	
		}
	
		private void Start ()
		{

		}

		public void ApplyDamage (int damage)
		{
			if (HP < 0)
				return;
	
			if (HitSound.Length > 0) {
				AudioSource.PlayClipAtPoint (HitSound [Random.Range (0, HitSound.Length)], transform.position);
			}
			HP -= damage;
			if (HP <= 0) {
				Dead ();
			}
		}

		private void Dead ()
		{
			if (Effect) {
				if (WeaponSystem.Pool != null) {
					WeaponSystem.Pool.Instantiate (Effect, transform.position, transform.rotation);
				} else {
					GameObject.Instantiate (Effect, transform.position, transform.rotation);
				}
			}
			if (objPool != null) {
				objPool.Destroying ();
			} else {
				Destroy (this.gameObject);
			}
			this.gameObject.SendMessage ("OnDead", SendMessageOptions.DontRequireReceiver);
		}

	}
}
