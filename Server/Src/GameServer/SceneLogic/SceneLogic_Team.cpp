/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___GameServer___SceneLogic___SceneLogic_Team.cpp */
#include "stdafx.h"
#include "SceneLogic_Team.h"
#include "../GameObject/SceneObject.h"
#include "../Scene.h"
#include "../Message/Game_Define.pb.h"

SceneLogic_Team::SceneLogic_Team(CScene* pScene): SceneLogicBase(pScene)
{

}

SceneLogic_Team::~SceneLogic_Team()
{

}

BOOL SceneLogic_Team::OnObjectCreate(CSceneObject* pObject)
{
	SceneLogicBase::OnObjectCreate(pObject);
	//player[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]。
	if(pObject->GetObjType() == OT_PLAYER)
	{
		ERROR_RETURN_TRUE(pObject->m_dwCamp > 0);
		ERROR_RETURN_TRUE(pObject->m_dwCamp < m_vtBornPos.size());
		pObject->SetPos(m_vtBornPos[pObject->m_dwCamp].m_x, m_vtBornPos[pObject->m_dwCamp].m_y, m_vtBornPos[pObject->m_dwCamp].m_z);

		return TRUE;
	}

	return TRUE;
}

BOOL SceneLogic_Team::OnObjectDie(CSceneObject* pObject)
{
	//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

	return TRUE;
}


BOOL SceneLogic_Team::OnPlayerEnter(CSceneObject* pPlayer)
{
	//player[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

	return TRUE;
}

BOOL SceneLogic_Team::OnPlayerLeave(CSceneObject* pPlayer, BOOL bDisConnect)
{
	//player[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	m_pScene->BroadRemoveObject(pPlayer);

	m_pScene->DeletePlayer(pPlayer->GetObjectGUID());

	if (!bDisConnect)
	{
		m_pScene->BackToMainCity(pPlayer->GetObjectGUID());
	}

	return FALSE;
}



BOOL SceneLogic_Team::Update(UINT64 uTick)
{
	SceneLogicBase::Update(uTick);

	//[TRANSLATED][TRANSLATED]player[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]．
	if (m_pScene->IsCampAllDie(EBC_PLAYER))
	{
		m_pScene->SetFinished();




		return TRUE;
	}

	if(BattleResultCheck())
	{

	}

	return TRUE;
}

BOOL SceneLogic_Team::OnTimeUP()
{


	return TRUE;
}

BOOL SceneLogic_Team::BattleResultCheck()
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
			//if(PlayerManager->initFengCeGift())
		}
		break;
		case EWC_PLAYER_ALIVE:
		{
			//if(is->isaaa)
			//{

			//}
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
