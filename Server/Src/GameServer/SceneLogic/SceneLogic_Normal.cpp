/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___GameServer___SceneLogic___SceneLogic_Normal.cpp */
﻿#include "stdafx.h"
#include "SceneLogic_Normal.h"
#include "../GameObject/SceneObject.h"
#include "../Scene.h"
#include "../Message/Game_Define.pb.h"
#include "../ServerData/ServerDefine.h"

SceneLogic_Normal::SceneLogic_Normal(CScene* pScene): SceneLogicBase(pScene)
{

}

SceneLogic_Normal::~SceneLogic_Normal()
{

}

BOOL SceneLogic_Normal::OnObjectCreate(CSceneObject* pObject)
{
	if(pObject->GetObjType() == OT_PLAYER)
	{
		SceneLogicBase::OnObjectCreate(pObject);
	}

	return TRUE;
}

BOOL SceneLogic_Normal::OnObjectDie(CSceneObject* pObject)
{
	//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

	return TRUE;
}


BOOL SceneLogic_Normal::OnPlayerEnter(CSceneObject* pPlayer)
{
	//player[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

	return TRUE;
}

BOOL SceneLogic_Normal::OnPlayerLeave(CSceneObject* pPlayer, BOOL bDisConnect)
{
	//player[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	m_pScene->SetBattleResult(0, ECR_LOST);

	m_pScene->SendBattleResult();

	m_pScene->SetFinished();

	return FALSE;
}



BOOL SceneLogic_Normal::Update(UINT64 uTick)
{
	if (!m_pScene->IsAllDataReady())
	{
		return TRUE;
	}

	SceneLogicBase::Update(uTick);

	//[TRANSLATED][TRANSLATED]player[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]．
	if (m_pScene->IsCampAllDie(EBC_PLAYER))
	{
		m_pScene->SetBattleResult(0, ECR_LOST);

		m_pScene->SendBattleResult();

		m_pScene->SetFinished();

		return TRUE;
	}

	if(BattleResultCheck())
	{
		m_pScene->SetBattleResult(0, ECR_WIN);

		m_pScene->SendBattleResult();

		m_pScene->SetFinished();
	}

	return TRUE;
}

BOOL SceneLogic_Normal::OnTimeUP()
{


	return TRUE;
}

BOOL SceneLogic_Normal::BattleResultCheck()
{
	switch (m_BattleCondition.GetConditionType())
	{
		case EWC_KILL_ALL:
		{
			if (m_pScene->IsMonsterAllDie() && m_pScene->IsMonsterAllGen())
			{
				return TRUE;
			}
		}
		break;
		case EWC_DESTINATION:
		{

		}
		break;
		case EWC_PLAYER_ALIVE:
		{

		}
		break;
		case EWC_NPC_ALIVE:
		{

		}
		break;
		case EWC_KILL_NUM:
		{

		}
		break;
		default:
		{

		}
	}

	return FALSE;
}
