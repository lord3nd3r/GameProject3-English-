/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___WeaponSystem___Scripts___Weapon___ChainDamage.cs */
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
	public class ChainDamage : DamageBase
	{
		public GameObject ChainObject;
		public int NumberChain = 5;
		public int Distance = 100;
		public float Direction = 0.5f;
		private bool actived = false;
	
		void Awake ()
		{
		
		}
	
		void Start ()
		{
			chainDamage ();
			actived = true;
		}
	
		void chainDamage ()
		{
		
			int count = 0;
			for (int t=0; t<TargetTag.Length; t++) {
				if (GameObject.FindGameObjectsWithTag (TargetTag [t]).Length > 0) {
					GameObject[] objs = GameObject.FindGameObjectsWithTag (TargetTag [t]);
					float distance = Distance;
				
				
					for (int i = 0; i < objs.Length; i++) {
						if (objs [i] != null) {
							Vector3 dir = (objs [i].transform.position - this.transform.position).normalized;
							float direction = Vector3.Dot (dir, this.transform.forward);
							float dis = Vector3.Distance (objs [i].transform.position, this.transform.position);
							if (dis < distance) {
								if (direction >= Direction) {
									if (ChainObject) {
										if (count <= NumberChain) {
											GameObject chain;
											Quaternion targetlook = Quaternion.LookRotation (objs [i].transform.position - this.transform.position);
											if (WeaponSystem.Pool != null) {
												chain = WeaponSystem.Pool.Instantiate (ChainObject, this.transform.position, targetlook);
											} else {
												chain = (GameObject)GameObject.Instantiate (ChainObject, this.transform.position, targetlook);
											}

											DamageBase dmg = chain.GetComponent<DamageBase> ();
											if (dmg) {
												dmg.TargetTag = TargetTag;	
											}
											count += 1;
										}
									}
								}
								distance = dis;
							}
						}			
					}
				}		
			}
		}
	
		void OnEnable ()
		{
			if (actived)
				chainDamage ();
		}

	}
}
