/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandRoll.cs */
﻿using UnityEngine;
using System.Collections;

/// <summary>
/// [TRANSLATED][TRANSLATED]
/// </summary>
public class CommandRoll : ICommand
{
    public float LastTime;

    public override Resp Do()
    {
        CmdHandler<CommandRoll> call = Del as CmdHandler<CommandRoll>;
        return call == null ? Resp.TYPE_NO : call(this);
    }

    public CommandRoll Update(float lastTime)
    {
        this.LastTime = lastTime;
        return this;
    }
}