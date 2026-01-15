/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___WeaponSystem___Scripts___TankMover2D.cs */
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
	public class TankMover2D : MonoBehaviour
	{

		public float Speed = 20;
		public float TurnSpeed = 100;
		public WeaponController weapon;
	
		void Start ()
		{
			weapon = this.transform.GetComponentInChildren (typeof(WeaponController)).GetComponent<WeaponController> ();
		}

		void Update ()
		{
			if (Input.GetButton ("Fire1")) {
				if (weapon)
					weapon.LaunchWeapon ();
			}

			this.transform.position += Vector3.right * Input.GetAxis ("Horizontal") * Speed * Time.deltaTime;
		}
	}
}
