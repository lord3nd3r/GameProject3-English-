/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandVariation.cs */
﻿using UnityEngine;
using System.Collections;
using System;

/// <summary>
/// [TRANSLATED][TRANSLATED]
/// </summary>
public class CommandVariation : CommandAct
{
    public float LastTime;
    public Int32 VariModelID;

    public override Resp Do()
    {
        CmdHandler<CommandVariation> call = Del as CmdHandler<CommandVariation>;
        return call == null ? Resp.TYPE_NO : call(this);
    }

    public CommandVariation Update(float lastTime, int variModelID)
    {
        this.LastTime      = lastTime;
        this.VariModelID   = variModelID;
        return this;
    }

    public CommandVariation Update(float lastTime, int variModelID, Callback exit, Callback stop)
    {
        this.ExitCallback = exit;
        this.StopCallback = stop;
        this.LastTime     = lastTime;
        this.VariModelID  = variModelID;
        return this;
    }
}
