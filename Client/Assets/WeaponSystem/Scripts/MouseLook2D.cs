/*
http://www.cgsoso.com/forum-211-1.html

CG Search Unity3d daily Unity3d plugin free updates, more VIP resources!

CGSOSO focuses on game development, film design and other CG resource materials.

If the plugin is used commercially, please be sure to purchase from the official website!

daily assets update for try.

U should buy the asset from home store if u use it in your project!
*/

using UnityEngine;
using System.Collections;

namespace HWRWeaponSystem
{
	public class MouseLook2D : MonoBehaviour
	{
		public Camera CurrentCamera;
		public float MaxAimRange = 10000;
		public Vector3 AimPoint;
		public bool LockX, LockY, LockZ;
		public GameObject AimObject;

		void Start ()
		{
	
		}
	
		void Update ()
		{
			if (CurrentCamera == null) {
			
				CurrentCamera = Camera.main;
			
				if (CurrentCamera == null)
					CurrentCamera = Camera.current;
			}
		
			RaycastHit hit;
			var ray = CurrentCamera.ScreenPointToRay (Input.mousePosition);
			if (Physics.Raycast (ray, out hit, MaxAimRange)) {
				AimPoint = hit.point;
				AimPoint = AxisLock (AimPoint);
				AimObject = hit.collider.gameObject;
			} else {
				AimPoint = ray.origin + (ray.direction * MaxAimRange);
				AimPoint = AxisLock (AimPoint);
				AimObject = null;
			}
			if (AimObject) {
				this.gameObject.transform.LookAt (AimObject.transform.position + AimPoint);
			} else {
				this.gameObject.transform.LookAt (AimPoint);
			}
		
		}
	
		public Vector3 AxisLock (Vector3 axis)
		{
			if (LockX)
				axis.x = this.transform.position.x;
		
			if (LockY)
				axis.y = this.transform.position.y;
		
			if (LockZ)
				axis.z = this.transform.position.z;
						
			return axis;
		}
	}
}
