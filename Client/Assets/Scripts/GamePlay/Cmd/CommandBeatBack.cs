/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandBeatBack.cs */
﻿using UnityEngine;
using System.Collections;
using System;

/// <summary>
/// [TRANSLATED][TRANSLATED][TRANSLATED]
/// </summary>
public class CommandBeatBack : CommandAct
{
    public float MaxDis = 8;

    public override Resp Do()
    {
        CmdHandler<CommandBeatBack> call = Del as CmdHandler<CommandBeatBack>;
        return call == null ? Resp.TYPE_NO : call(this);
    }

    public CommandBeatBack Update(float maxDis)
    {
        this.MaxDis = maxDis;
        return this;
    }
}


