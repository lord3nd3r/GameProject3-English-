/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___WeaponSystem___Scripts___AILook.cs */
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
	public class AILook : MonoBehaviour
	{

		public string[] TargetTag = new string[1]{"Enemy"};
		public float Distance = 1000;
		private int indexWeapon;
		private GameObject target;
		private WeaponController weapon;
		private float timeAIattack;
	
		void Start ()
		{
			weapon = (WeaponController)this.GetComponent<WeaponController> ();
		}
	
		void Update ()
		{
		
			if (target) {
				Quaternion targetlook = Quaternion.LookRotation (target.transform.position - this.transform.position);
				this.transform.rotation = Quaternion.Lerp (this.transform.rotation, targetlook, Time.deltaTime * 3);
			
				Vector3 dir = (target.transform.position - transform.position).normalized;
				float direction = Vector3.Dot (dir, transform.forward);
			
				if (direction > 0.9f) {
					if (weapon) {
						weapon.LaunchWeapon (indexWeapon);
					}
				}
				// AI attack the target for a while (3 sec)
				if (Time.time > timeAIattack + 3) {
					target = null;	
					// AI forget this target and try to looking new target
				}
			} else {
				for (int t=0; t<TargetTag.Length; t++) {
					// AI find target only in TargetTag list
					if (GameObject.FindGameObjectsWithTag (TargetTag [t]).Length > 0) {
						GameObject[] objs = GameObject.FindGameObjectsWithTag (TargetTag [t]);
						float distance = Distance;
						for (int i = 0; i < objs.Length; i++) {
							float dis = Vector3.Distance (objs [i].transform.position, transform.position);
                       
							if (distance > dis) {
								// Select closer target
								distance = dis;
								target = objs [i];
								if (weapon) {
									indexWeapon = Random.Range (0, weapon.WeaponLists.Length);
								}
								timeAIattack = Time.time;
							}
						}
					}
				}	
			}
		}
	}
}
