/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandDead.cs */
﻿using UnityEngine;
using System.Collections;

/// <summary>
/// [TRANSLATED][TRANSLATED]
/// </summary>
public class CommandDead : ICommand
{
    public EDeadReason Reason;

    public override Resp Do()
    {
        CmdHandler<CommandDead> call = Del as CmdHandler<CommandDead>;
        return call == null ? Resp.TYPE_NO : call(this);
    }

    public CommandDead Update(EDeadReason reason)
    {
        this.Reason = reason;
        return this;
    }
}
