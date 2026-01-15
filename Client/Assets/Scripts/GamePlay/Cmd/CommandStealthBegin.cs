/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandStealthBegin.cs */
﻿using UnityEngine;
using System.Collections;

/// <summary>
/// [TRANSLATED][TRANSLATED]
/// </summary>
public class CommandStealthBegin : ICommand
{
    public float LastTime;

    public override Resp Do()
    {
        CmdHandler<CommandStealthBegin> call = Del as CmdHandler<CommandStealthBegin>;
        return call == null ? Resp.TYPE_NO : call(this);
    }

    public CommandStealthBegin Update(float lastTime)
    {
        this.LastTime =lastTime;
        return this;
    }
}
