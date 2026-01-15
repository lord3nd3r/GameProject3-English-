/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___ACT___ActBuffSystem.cs */
﻿using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Xml;

namespace ACT
{
    public class ActBuffSystem
    {
        public static Dictionary<int, ActBuff> Buffs = new Dictionary<int, ActBuff>();

        public static void Read(string path)
        {
            TextAsset asset = GTResourceManager.Instance.Load<TextAsset>(path);
            if (asset == null)
            {
                return;
            }
            XmlDocument doc = new XmlDocument();
            doc.LoadXml(asset.text);
            XmlElement root = doc.FirstChild as XmlElement;
            XmlElement child = root.FirstChild as XmlElement;
            while (child != null)
            {
                string idStr = child.GetAttribute("ID");
                if(idStr==null)
                {
                    continue;
                }
                int id = idStr.ToInt32();
                ActBuff skill = new ActBuff();
                skill.LoadDoc(child);
                Buffs.Add(id, skill);
                child = child.NextSibling as XmlElement;
            }
        }

        public static ActBuff Create(int id, Character carryer, Character caster)
        {
            ActBuff tempBuff = null;
            Buffs.TryGetValue(id, out tempBuff);
            if (tempBuff == null)
            {
                Debug.LogError("[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]Buff[TRANSLATED][TRANSLATED][TRANSLATED], ID =" + id);
                return null;
            }
            else
            {
                ActBuff buff = ActBuffItem.Clone<ActBuff>(tempBuff);
                buff.ID = id;
                buff.Carryer = carryer;
                buff.Caster = caster;
                for(int i = 0;i<buff.Children.Count;i++)
                {
                    buff.Children[i].Buff = buff;
                    buff.Children[i].Carryer = carryer;
                    buff.Children[i].Caster = caster;
                }
                return buff;
            }
        }

        public static ActBuff Get(int id)
        {
            ActBuff tempBuff = null;
            Buffs.TryGetValue(id, out tempBuff);
            return tempBuff;
        }
    }
}

