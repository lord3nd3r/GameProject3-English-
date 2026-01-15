/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GamePlay___Cmd___CommandUseSkill.cs */
﻿using UnityEngine;
using System.Collections;

/// <summary>
/// [TRANSLATED][TRANSLATED]skill
/// </summary>
public class CommandUseSkill : CommandAct
{
    public ESkillPos Pos       = ESkillPos.Skill_0;
    public int       ID;


    public override Resp Do()
    {
        CmdHandler<CommandUseSkill> call = Del as CmdHandler<CommandUseSkill>;
        return call == null ? Resp.TYPE_NO : call(this);
    }

    public CommandUseSkill Update(ESkillPos pos)
    {
        this.Pos = pos;
        return this;
    }

    public CommandUseSkill Update(int id)
    {
        this.ID = id;
        return this;
    }
}
