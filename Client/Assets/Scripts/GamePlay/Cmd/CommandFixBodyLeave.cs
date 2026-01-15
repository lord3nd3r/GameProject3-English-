/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandFixBodyLeave.cs */
﻿using UnityEngine;
using System.Collections;

/// <summary>
/// [TRANSLATED][TRANSLATED]
/// </summary>
public class CommandFixBodyLeave : ICommand
{
    public override Resp Do()
    {
        CmdHandler<CommandFixBodyLeave> call = Del as CmdHandler<CommandFixBodyLeave>;
        return call == null ? Resp.TYPE_NO : call(this);
    }

}
