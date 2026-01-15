/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandStealthLeave.cs */
﻿using UnityEngine;
using System.Collections;

/// <summary>
/// [TRANSLATED][TRANSLATED]
/// </summary>
public class CommandStealthLeave : ICommand
{
    public override Resp Do()
    {
        CmdHandler<CommandStealthLeave> call = Del as CmdHandler<CommandStealthLeave>;
        return call == null ? Resp.TYPE_NO : call(this);
    }

}
