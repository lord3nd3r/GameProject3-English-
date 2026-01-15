/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandIdle.cs */
﻿using UnityEngine;
using System.Collections;

/// <summary>
/// [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
/// </summary>
public class CommandIdle : ICommand
{
    public override Resp Do()
    {
        CmdHandler<CommandIdle> call = Del as CmdHandler<CommandIdle>;
        return call == null ? Resp.TYPE_NO : call(this);
    }
}