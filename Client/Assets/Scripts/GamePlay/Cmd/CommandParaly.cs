/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandParaly.cs */
﻿using UnityEngine;
using System.Collections;

/// <summary>
/// [TRANSLATED][TRANSLATED]
/// </summary>
public class CommandParaly : CommandAct
{
    public float LastTime;

    public override Resp Do()
    {
        CmdHandler<CommandParaly> call = Del as CmdHandler<CommandParaly>;
        return call == null ? Resp.TYPE_NO : call(this);
    }

    public CommandParaly Update(float lastTime)
    {
        this.LastTime = lastTime;
        return this;
    }

    public CommandParaly Update(float lastTime, Callback exit, Callback stop)
    {
        this.ExitCallback = exit;
        this.StopCallback = stop;
        this.LastTime = lastTime;
        return this;
    }
}