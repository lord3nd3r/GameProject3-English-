/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandInterActive.cs */
﻿using UnityEngine;
using System.Collections;


/// <summary>
/// NPC[TRANSLATED][TRANSLATED]
/// </summary>
public class CommandInterActive : ICommand
{
    public float    LastTime;
    public string   AnimName = "idle";
    public Callback OnFinish;

    public override Resp Do()
    {
        CmdHandler<CommandInterActive> call = Del as CmdHandler<CommandInterActive>;
        return call == null ? Resp.TYPE_NO : call(this);
    }

    public CommandInterActive Update(string pAnimName, Callback onFinish)
    {
        this.OnFinish = onFinish;
        this.AnimName = pAnimName;
        return this;
    }
}
