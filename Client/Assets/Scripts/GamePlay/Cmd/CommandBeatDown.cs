/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandBeatDown.cs */
﻿using UnityEngine;
using System.Collections;

/// <summary>
/// [TRANSLATED][TRANSLATED][TRANSLATED]
/// </summary>
public class CommandBeatDown : CommandAct
{
    public override Resp Do()
    {
        CmdHandler<CommandBeatDown> call = Del as CmdHandler<CommandBeatDown>;
        return call == null ? Resp.TYPE_NO : call(this);
    }
}
