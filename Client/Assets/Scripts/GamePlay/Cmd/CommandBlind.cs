/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandBlind.cs */
﻿using UnityEngine;
using System.Collections;

/// <summary>
/// [TRANSLATED][TRANSLATED]
/// </summary>
public class CommandBlind : CommandAct
{
    public float LastTime;

    public override Resp Do()
    {
        CmdHandler<CommandBlind> call = Del as CmdHandler<CommandBlind>;
        return call == null ? Resp.TYPE_NO : call(this);
    }

    public CommandBlind Update(float lastTime)
    {
        this.LastTime = lastTime;
        return this;
    }

    public CommandBlind Update(float lastTime, Callback exit, Callback stop)
    {
        this.ExitCallback = exit;
        this.StopCallback = stop;
        this.LastTime = lastTime;
        return this;
    }
}
