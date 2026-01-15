/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandTalk.cs */
﻿using UnityEngine;
using System.Collections;

/// <summary>
/// [TRANSLATED][TRANSLATED]
/// </summary>
public class CommandTalk : ICommand
{
    public string  Word = string.Empty;

    public override Resp Do()
    {
        CmdHandler<CommandTalk> call = Del as CmdHandler<CommandTalk>;
        return call == null ? Resp.TYPE_NO : call(this);
    }

    public CommandTalk Update(string word)
    {
        this.Word     = word;
        return this;
    }
}
