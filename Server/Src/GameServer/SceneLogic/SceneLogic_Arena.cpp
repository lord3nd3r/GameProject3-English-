/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___GameServer___SceneLogic___SceneLogic_Arena.cpp */
﻿#include "stdafx.h"
#include "SceneLogic_Arena.h"
#include "../GameObject/SceneObject.h"
#include "../Scene.h"
#include "../Message/Game_Define.pb.h"

SceneLogic_Arena::SceneLogic_Arena(CScene* pScene): SceneLogicBase(pScene)
{
}

SceneLogic_Arena::~SceneLogic_Arena()
{
}

BOOL SceneLogic_Arena::OnObjectCreate(CSceneObject* pObject)
{
	//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	SceneLogicBase::OnObjectCreate(pObject);

	return TRUE;
}

BOOL SceneLogic_Arena::OnObjectDie(CSceneObject* pObject)
{
	return TRUE;
}


BOOL SceneLogic_Arena::OnPlayerEnter(CSceneObject* pPlayer)
{
	//player[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]。

	return TRUE;
}

BOOL SceneLogic_Arena::OnPlayerLeave(CSceneObject* pPlayer, BOOL bDisConnect)
{
	return FALSE;
}

BOOL SceneLogic_Arena::Update(UINT64 uTick)
{
	SceneLogicBase::Update(uTick);


	return TRUE;
}

BOOL SceneLogic_Arena::OnTimeUP()
{


	return TRUE;
}
