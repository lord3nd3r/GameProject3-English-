/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___WeaponSystem___Scripts___Weapon___RayShoot.cs */
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
	public class RayShoot : DamageBase
	{
		public int Range = 10000;
		public Vector3 AimPoint;
		public GameObject Explosion;
		public float LifeTime = 1;
		public LineRenderer Trail;
		private ObjectPool objPool;
		private bool actived = false;
	
		private void Awake ()
		{
			objPool = this.GetComponent<ObjectPool> ();	
		}
	
		void Start ()
		{
			ShootRay ();
			actived = true;
		}
	
		private void OnEnable ()
		{
			if (objPool)
				objPool.SetDestroy (LifeTime);
		
			if (actived)
				ShootRay ();
		}
	
		void ShootRay ()
		{
			if (GetComponent<Collider>()) {
				Physics.IgnoreCollision (GetComponent<Collider>(), Owner.GetComponent<Collider>());
				if (Owner.transform.root) {
					foreach (Collider col in Owner.transform.root.GetComponentsInChildren<Collider>()) {
						Physics.IgnoreCollision (GetComponent<Collider>(), col);
					}
				}
			}
		
			RaycastHit hit;
			GameObject explosion = null;
			if (Physics.Raycast (this.transform.position, this.transform.forward, out hit, Range)) {
				AimPoint = hit.point;
				if (Explosion != null) {
					if (WeaponSystem.Pool != null) {
						explosion = WeaponSystem.Pool.Instantiate (Explosion, AimPoint, this.transform.rotation);
					} else {
						explosion = (GameObject)GameObject.Instantiate (Explosion, AimPoint, this.transform.rotation);
					}
				}
				hit.collider.gameObject.SendMessage ("ApplyDamage", Damage, SendMessageOptions.DontRequireReceiver);
			} else {
				AimPoint = this.transform.position + this.transform.forward * Range;
				if (Explosion != null) {
					if (WeaponSystem.Pool != null) {
						explosion = WeaponSystem.Pool.Instantiate (Explosion, AimPoint, this.transform.rotation);
					} else {
						explosion = (GameObject)GameObject.Instantiate (Explosion, AimPoint, this.transform.rotation);
					}
				}
			}
			if (explosion) {
				explosion.transform.forward = this.transform.forward;
				DamageBase dmg = explosion.GetComponent<DamageBase> ();
				if (dmg) {
					dmg.TargetTag = TargetTag;	
				}
			}
			if (Trail) {
				Trail.SetPosition (0, this.transform.position);
				Trail.SetPosition (1, AimPoint);
			
			}
		
			if (WeaponSystem.Pool == null) {
				Destroy (this.gameObject, LifeTime);
			}
		}
	
		void Update ()
		{
		
		}
	}
	
}
