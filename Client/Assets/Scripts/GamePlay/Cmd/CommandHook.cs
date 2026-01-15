/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandHook.cs */
﻿using UnityEngine;
using System.Collections;

/// <summary>
/// [TRANSLATED][TRANSLATED][TRANSLATED]
/// </summary>
public class CommandHook : CommandAct
{
    public float LastTime;

    public override Resp Do()
    {
        CmdHandler<CommandHook> call = Del as CmdHandler<CommandHook>;
        return call == null ? Resp.TYPE_NO : call(this);
    }

    public CommandHook Update(float lastTime)
    {
        this.LastTime = lastTime;
        return this;
    }

    public CommandHook Update(float lastTime, Callback exit, Callback stop)
    {
        this.ExitCallback = exit;
        this.StopCallback = stop;
        this.LastTime = lastTime;
        return this;
    }
}
