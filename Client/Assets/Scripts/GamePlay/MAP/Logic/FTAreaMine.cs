/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___MAP___Logic___FTAreaMine.cs */
﻿using UnityEngine;
using System.Collections;
using System;
using System.Collections.Generic;
using CFG;

namespace MAP
{
    public class FTAreaMine : FTComponent, IFTContainer
    {       
        [FT] public Int32            MineID       = 0;
        [FT] public float            RebornCD     = 20;
        [FT] public Int32            RebornType   = 0;
        [FT] public Int32            DropMinCount = 1;
        [FT] public Int32            DropMaxCount = 4;
        [FT] public List<FTPoint>    Points       = new List<FTPoint>();

        public override void Startup()
        {

        }

        public override void Trigger()
        {

        }

        public override void Release()
        {

        }

        public override DCFG Export()
        {
            MapAreaMine data  = new MapAreaMine();
            data.Pos          = transform.position;
            data.ID           = this.ID;
            data.MineID       = this.MineID;
            data.RebornCD     = this.RebornCD;
            data.RebornType   = this.RebornType;
            data.DropMinCount = this.DropMinCount;
            data.DropMaxCount = this.DropMaxCount;
            for (int i = 0; i < Points.Count; i++)
            {
                MapPoint d = (MapPoint)Points[i].Export();
                data.Points.Add(d);
            }
            return data;
        }

        public override void Import(DCFG cfg)
        {
            MapAreaMine data  = cfg as MapAreaMine;
            this.Pos          = data.Pos;
            this.ID           = data.ID;
            this.MineID       = data.MineID;
            this.RebornCD     = data.RebornCD;
            this.RebornType   = data.RebornType;
            this.DropMinCount = data.DropMinCount;
            this.DropMaxCount = data.DropMaxCount;
            for (int i = 0; i < data.Points.Count; i++)
            {
                MapPoint d = data.Points[i];
                FTPoint  p = new GameObject().AddComponent<FTPoint>();
                p.transform.parent = transform;
                p.Import(d);
                Points.Add(p);
            }
        }

        public override void OnDrawGizmos()
        {
            transform.localScale = Vector3.one;
            for (int i = 0; i < Points.Count; i++)
            {
                FTPoint p = Points[i];
                if (p == null)
                {
                    Points.RemoveAt(i);
                }
                else
                {
                    FTDraw.DrawCube(p.transform.position, new Color32(245, 130, 32, 255), 0.2f);
                }
            }
        }

        public override void OnDrawInspector()
        {
#if UNITY_EDITOR
            GUILayout.Space(10);
            this.ID           = UnityEditor.EditorGUILayout.IntField("ID", this.ID);
            this.MineID       = UnityEditor.EditorGUILayout.IntField("MineID", this.MineID);
            this.RebornCD     = UnityEditor.EditorGUILayout.FloatField("RebornCD", this.RebornCD);
            this.RebornType   = UnityEditor.EditorGUILayout.IntField("RebornType", this.RebornType);
            this.DropMinCount = UnityEditor.EditorGUILayout.IntField("DropMinCount", this.DropMinCount);
            this.DropMaxCount = UnityEditor.EditorGUILayout.IntField("DropMaxCount", this.DropMaxCount);

            GUILayout.Space(10);
            GUILayout.BeginHorizontal();
            GUI.color = Color.green;
            if (GUILayout.Button("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", FTGUIStyles.FTButtonStyle, GUILayout.Height(40)))
            {
                this.AddElement();
            }
            GUILayout.Space(10);
            GUI.color = Color.green;
            if (GUILayout.Button("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", FTGUIStyles.FTButtonStyle, GUILayout.Height(40)))
            {
                UnityEditor.EditorWindow.GetWindow<FTComponentWindow>().SetGroup(this);
                UnityEditor.EditorWindow.GetWindow<FTComponentWindow>().Show();
            }
            GUILayout.EndHorizontal();

            GUI.color = Color.red;
            GUILayout.Space(10);
            if (GUILayout.Button("[TRANSLATED][TRANSLATED]target[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]", FTGUIStyles.FTButtonStyle, GUILayout.Height(40)))
            {
                List<FTPoint> list = Points;
                for (int i = 0; i < list.Count; i++)
                {
                    list[i].MoveToGround();
                }
            }
            GUILayout.Space(5);
#endif
        }

        public FTPoint       AddElement()
        {
            FTPoint t = new GameObject(typeof(FTPoint).Name).AddComponent<FTPoint>();
            t.transform.parent = transform;
            Points.Add(t);
            return t;
        }

        public          void AddElement(Vector3 pos, Vector3 eulerAngles)
        {
            FTPoint p = AddElement();
            p.transform.position = pos;
            p.transform.eulerAngles = eulerAngles;
        }

    }
}