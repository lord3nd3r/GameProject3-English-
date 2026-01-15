/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandFrost.cs */
﻿using UnityEngine;
using System.Collections;

/// <summary>
/// [TRANSLATED][TRANSLATED]
/// </summary>
public class CommandFrost : CommandAct
{
    public float LastTime;

    public override Resp Do()
    {
        CmdHandler<CommandFrost> call = Del as CmdHandler<CommandFrost>;
        return call == null ? Resp.TYPE_NO : call(this);
    }

    public CommandFrost Update(float lastTime)
    {
        this.LastTime = lastTime;
        return this;
    }

    public CommandFrost Update(float lastTime, Callback exit, Callback stop)
    {
        this.ExitCallback = exit;
        this.StopCallback = stop;
        this.LastTime = lastTime;
        return this;
    }
}
