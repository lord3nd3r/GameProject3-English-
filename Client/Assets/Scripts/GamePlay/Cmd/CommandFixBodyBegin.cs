/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandFixBodyBegin.cs */
﻿using UnityEngine;
using System.Collections;
using System;

/// <summary>
/// [TRANSLATED][TRANSLATED]
/// </summary>
public class CommandFixBodyBegin : CommandAct
{
    public float LastTime;

    public override Resp Do()
    {
        CmdHandler<CommandFixBodyBegin> call = Del as CmdHandler<CommandFixBodyBegin>;
        return call == null ? Resp.TYPE_NO : call(this);
    }

    public CommandFixBodyBegin Update(float lastTime)
    {
        this.LastTime = lastTime;
        return this;
    }

    public CommandFixBodyBegin Update(float lastTime, Callback exit, Callback stop)
    {
        this.ExitCallback = exit;
        this.StopCallback = stop;
        this.LastTime = lastTime;
        return this;
    }
}
