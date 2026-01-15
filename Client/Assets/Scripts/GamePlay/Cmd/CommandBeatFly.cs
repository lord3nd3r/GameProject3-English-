/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandBeatFly.cs */
﻿using UnityEngine;
using System.Collections;

/// <summary>
/// [TRANSLATED][TRANSLATED][TRANSLATED]
/// </summary>
public class CommandBeatFly : CommandAct
{
    public Vector3 Dir;

    public override Resp Do()
    {
        CmdHandler<CommandBeatFly> call = Del as CmdHandler<CommandBeatFly>;
        return call == null ? Resp.TYPE_NO : call(this);
    }

    public CommandBeatFly Update(Vector3 dir)
    {
        this.Dir = dir;
        return this;
    }
}

