/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandJump.cs */
﻿using UnityEngine;
using System.Collections;


/// <summary>
/// [TRANSLATED]
/// </summary>
public class CommandJump : ICommand
{
    public Vector3 Direction;

    public override Resp Do()
    {
        CmdHandler<CommandJump> call = Del as CmdHandler<CommandJump>;
        return call == null ? Resp.TYPE_NO : call(this);
    }
}