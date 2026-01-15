/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandFloat.cs */
﻿using UnityEngine;
using System.Collections;

/// <summary>
/// [TRANSLATED][TRANSLATED]
/// </summary>
public class CommandFloat : CommandAct
{
    public override Resp Do()
    {
        CmdHandler<CommandFloat> call = Del as CmdHandler<CommandFloat>;
        return call == null ? Resp.TYPE_NO : call(this);
    }
}
