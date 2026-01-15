/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandRideLeave.cs */
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
public class CommandRideLeave : ICommand
{
    public override Resp Do()
    {
        CmdHandler<CommandRideLeave> call = Del as CmdHandler<CommandRideLeave>;
        return call == null ? Resp.TYPE_NO : call(this);
    }
}
