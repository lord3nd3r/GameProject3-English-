/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___WeaponSystem___Scripts___Weapon___WeaponController.cs */
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
	public class WeaponController : MonoBehaviour
	{
		public string[] TargetTag = new string[1]{"Enemy"};
		public WeaponLauncher[] WeaponLists;
		public int CurrentWeapon = 0;
		public bool ShowCrosshair;
	
		void Awake ()
		{
			// find all attached weapons.
			if (this.transform.GetComponentsInChildren (typeof(WeaponLauncher)).Length > 0) {
				var weas = this.transform.GetComponentsInChildren (typeof(WeaponLauncher));
				WeaponLists = new WeaponLauncher[weas.Length];
				for (int i=0; i<weas.Length; i++) {
					WeaponLists [i] = weas [i].GetComponent<WeaponLauncher> ();
					WeaponLists [i].TargetTag = TargetTag;
				}
			}
		}

		public WeaponLauncher GetCurrentWeapon ()
		{
			if (CurrentWeapon < WeaponLists.Length && WeaponLists [CurrentWeapon] != null) {
				return WeaponLists [CurrentWeapon];
			}
			return null;
		}
	
		private void Start ()
		{
			for (int i=0; i<WeaponLists.Length; i++) {
				if (WeaponLists [i] != null) {
					WeaponLists [i].TargetTag = TargetTag;
					WeaponLists [i].ShowCrosshair = ShowCrosshair;
				}
			}
		}

		private void Update ()
		{
		
			for (int i=0; i<WeaponLists.Length; i++) {
				if (WeaponLists [i] != null) {
					WeaponLists [i].OnActive = false;
				}
			}
			if (CurrentWeapon < WeaponLists.Length && WeaponLists [CurrentWeapon] != null) {
				WeaponLists [CurrentWeapon].OnActive = true;
			}
	
		}
	
		public void LaunchWeapon (int index)
		{
			CurrentWeapon = index;
			if (CurrentWeapon < WeaponLists.Length && WeaponLists [index] != null) {
				WeaponLists [index].Shoot ();
			}
		}
	
		public void SwitchWeapon ()
		{
			CurrentWeapon += 1;
			if (CurrentWeapon >= WeaponLists.Length) {
				CurrentWeapon = 0;	
			}
		
			for (int i=0; i<WeaponLists.Length; i++) {
				if (CurrentWeapon == i) {
					WeaponLists [i].OnActive = true;
					//HideWeapon(WeaponLists[i].gameObject,true);
				} else {
					//HideWeapon(WeaponLists[i].gameObject,false);
					WeaponLists [i].OnActive = false;
				}
			}
		}
	
		public void HideWeapon (GameObject weapon, bool show)
		{
			foreach (Renderer render in weapon.GetComponentsInChildren<Renderer>()) {
				render.enabled = show;
			}
		}
	
		public void LaunchWeapon ()
		{
			if (CurrentWeapon < WeaponLists.Length && WeaponLists [CurrentWeapon] != null) {
				WeaponLists [CurrentWeapon].Shoot ();
			}
		}
	
	}
}
