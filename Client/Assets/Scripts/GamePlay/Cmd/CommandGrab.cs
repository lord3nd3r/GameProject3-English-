/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandGrab.cs */
﻿using UnityEngine;
using System.Collections;

/// <summary>
/// [TRANSLATED][TRANSLATED][TRANSLATED]
/// </summary>
public class CommandGrab : ICommand
{
    public override Resp Do()
    {
        CmdHandler<CommandGrab> call = Del as CmdHandler<CommandGrab>;
        return call == null ? Resp.TYPE_NO : call(this);
    }
}

