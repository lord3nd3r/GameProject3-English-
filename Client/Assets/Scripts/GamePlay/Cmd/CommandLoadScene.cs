/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandLoadScene.cs */
﻿using UnityEngine;
using System.Collections;

/// <summary>
/// [TRANSLATED][TRANSLATED]load
/// </summary>
public class CommandLoadScene : ICommand
{
    public int SceneID;

    public override Resp Do()
    {
        CmdHandler<CommandLoadScene> call = Del as CmdHandler<CommandLoadScene>;
        return call == null ? Resp.TYPE_NO : call(this);
    }

    public CommandLoadScene Update(int sceneID)
    {
        this.SceneID = sceneID;
        return this;
    }
}
