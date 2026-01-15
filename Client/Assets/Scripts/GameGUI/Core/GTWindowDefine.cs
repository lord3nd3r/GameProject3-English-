/* NOTE: original file backed up at /tmp/chinese_backups/Client___Assets___Scripts___GameGUI___Core___GTWindowDefine.cs */
﻿using UnityEngine;
using System.Collections;


public enum EWindowType
{
    Bottom,
    Window,
    Message,
    NewBie,
    Loaded,
}

public enum EWindowShowMode
{
    DoNothing,              //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    HideOther,              //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]shutdown[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    SaveTarget,             //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
}

public enum EWindowID
{
    UINone,

    UILogin,
    UIAccount,
    UIServer,
    UINotice,

    UINetWaiting,
    UILoading,
    UIMask,

    UISetting,

    UIMessageTip,
    UIMessageBox,
    UIMessageBoxForNetwork,
    UIAwardTip,
    UIAwardBox,
    UIDialogue,

    UICreateRole,
    UIHome,
    UIBag,
    UIEquip,
    UIGem,
    UIPet,
    UIStore,
    UIWorldMap,
    UIAdventure,
    UISkill,
    UIReborn,

    UITask,
    UITaskTalk,
    UITaskInterActive,

    UIHeroInfo,
    UIItemInfo,
    UIItemUse,
    UIEquipInfo,
    UIGemInfo,
    UIChipInfo,
    UIFashionInfo,
    UIRuneInfo,

    UIRoleEquip,
    UIRoleGem,
    UIRoleFashion,
    UIRoleRune,
    UIRoleFetter,

    UIMainRaid,
    UIMainCopy,
    UIMainResult,
    UIMainBossHP,



    UIPartner,
    UIPartnerAdvance,
    UIPartnerStrength,
    UIPartnerStar,
    UIPartnerWake,
    UIPartnerWash,
    UIPartnerSkill,
    UIPartnerFetter,
    UIPartnerProperty,
    UIPartnerBattle,

    UIMount,
    UIMountLibrary,
    UIMountBlood,
    UIMountTame,
    UIMountTurned,

    UIRelics,
    UIRelicsSkill,

    UIGuide,

    UIPlotCutscene,
}

public enum EWindowMaskType
{
    None,
    BlackTransparent,
    WhiteTransparent,
    Blur,
    Black,
}

public enum EWindowHideType
{
    Normal,
    Scale,
}

public enum EWindowOpenType
{
    Normal,
    Scale,
}