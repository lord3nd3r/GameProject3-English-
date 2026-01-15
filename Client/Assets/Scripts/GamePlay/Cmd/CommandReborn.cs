/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandReborn.cs */
﻿using UnityEngine;
using System.Collections;

//[TRANSLATED][TRANSLATED]
public class CommandReborn : ICommand
{
    public float LastTime;

    public override Resp Do()
    {
        CmdHandler<CommandReborn> call = Del as CmdHandler<CommandReborn>;
        return call == null ? Resp.TYPE_NO : call(this);
    }

    public CommandReborn Update(float lastTime)
    {
        this.LastTime = lastTime;
        return this;
    }
}
