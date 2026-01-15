/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandMine.cs */
﻿using UnityEngine;
using System.Collections;

/// <summary>
/// [TRANSLATED][TRANSLATED]
/// </summary>
public class CommandMine : ICommand
{
    public float    LastTime;
    public Callback OnFinish;

    public override Resp Do()
    {
        CmdHandler<CommandMine> call = Del as CmdHandler<CommandMine>;
        return call == null ? Resp.TYPE_NO : call(this);
    }

    public CommandMine Update(Callback onFinish)
    {
        this.OnFinish = onFinish;
        return this;
    }
}
