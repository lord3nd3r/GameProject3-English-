/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandRideBegin.cs */
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
public class CommandRideBegin : ICommand
{
    public override Resp Do()
    {
        CmdHandler<CommandRideBegin> call = Del as CmdHandler<CommandRideBegin>;
        return call == null ? Resp.TYPE_NO : call(this);
    }
}
