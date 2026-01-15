/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___GameServer___Scene.h */
﻿#ifndef _SCENE_H_
#define _SCENE_H_
#include "GameObject/SceneObject.h"
#include "SceneLogic/SceneLogic_Base.h"
#include "../Message/Msg_Game.pb.h"
#include "GameObject/BulletObject.h"
#include "../ServerData/ServerStruct.h"
class MonsterCreator;

class CScene
{
public:
	CScene();

	~CScene();

	BOOL            DispatchPacket(NetPacket* pNetPack);

	BOOL            Init(UINT32 dwCopyID, UINT32 dwCopyGuid, UINT32 dwCopyType, UINT32 dwPlayerNum, UINT64 uCreateKey);

	BOOL            Uninit();

	BOOL            Reset();

	UINT32	        GetCopyGuid();

	UINT32          GetCopyID();

	UINT32          GetCopyType();

	BOOL            OnUpdate( UINT64 uTick );

	BOOL            CreateSceneLogic(UINT32 dwCopyType);

	BOOL            DestroySceneLogic(UINT32 dwCopyType);

	BOOL            BroadNewObject(CSceneObject* pSceneObject);

	BOOL            BroadMessage(INT32 nMsgID, const google::protobuf::Message& pdata);

	BOOL            BroadRemoveObject(CSceneObject* pSceneObject);

	BOOL            SendAllNewObjectToPlayer(CSceneObject* pSceneObject);

	BOOL            BroadDieNotify(UINT64 uObjectID);

	BOOL            UpdateBulletStatus(UINT64 uTick);

	BOOL            BackToMainCity(UINT64 uRoleID);

	BOOL            SyncObjectStatus();

	INT32	        GetPlayerCount();
	INT32			GetConnectCount();

	CSceneObject*   GetPlayer(UINT64 uID);
	BOOL            AddPlayer(CSceneObject* pSceneObject);
	VOID		    DeletePlayer(UINT64 uID);

	BOOL			AddMonster(CSceneObject* pSceneObject);
	VOID		    DeleteMonster(UINT64 uID);

	CSceneObject*   GetSceneObject(UINT64 uID);
	BOOL			RemoveDeadObject();

	BOOL			UpdateAiController(UINT64 uFilterID);
	UINT64			SelectController(UINT64 uFilterID);

	BOOL			SelectTargets(std::vector<CSceneObject*>& vTargets, UINT64 uExcludeID, UINT32 dwCamp, EHitShipType hitType, Vector3D hitPos, FLOAT fHitDir, ERangeType rangeType, FLOAT RangeParams[5]);

	//[TRANSLATED][TRANSLATED][TRANSLATED]PVE[TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	CSceneObject*   GetOwnPlayer();

	//////////////////////////////////////////////////////////////////////////
	//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	CSceneObject*	CreatePlayer(const TransRoleData& roleData, UINT64 uHostID, UINT32 dwCamp );
	CSceneObject*	CreatePet(const TransPetData& petData, UINT64 uHostID, UINT32 dwCamp );
	CSceneObject*	CreatePartner(const TransPartnerData& partnerData, UINT64 uHostID, UINT32 dwCamp );

	//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	CSceneObject*	CreateMonster( UINT32 dwActorID, UINT32 dwCamp, FLOAT x, FLOAT y, FLOAT z, FLOAT ft);

	//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	CSceneObject*	CreateSummon( UINT32 dwActorID, UINT64 uSummonerID, UINT32 dwCamp, FLOAT x, FLOAT y, FLOAT z, FLOAT ft);

	//[TRANSLATED][TRANSLATED]bullet[TRANSLATED][TRANSLATED]
	CBulletObject*	CreateBullet(UINT32 dwBulletID, StBulletInfo* pBulletInfo, CSkillObject* pSkillObject, Vector3D startPos);

	BOOL			IsCampAllDie(UINT32 dwCamp);  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]whether[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED].
	BOOL			IsMonsterAllDie();            //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]whether[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED].
	BOOL            IsMonsterAllGen();            //whether[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]already[TRANSLATED][TRANSLATED]

	//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]config[TRANSLATED][TRANSLATED]
	BOOL			ReadSceneXml();
public:
	BOOL			IsFinished();
	VOID			SetFinished();
	BOOL            IsAllDataReady();
	BOOL			IsAllLoginReady();
	UINT64			GetStartTime();
	UINT64			GetCreateTime();
	UINT64			GetTotalTime();
	UINT64          GetLastTick();
	BOOL			SetLastTick(UINT64 uTick);
	UINT64			GenNewGuid();

public:
	UINT32			m_dwPlayerNum;  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	UINT32			m_dwLoginNum;   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	UINT32			m_dwCopyGuid;	//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]ID
	UINT32			m_dwCopyID;		//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]TYPE
	UINT32			m_dwCopyType;	//[TRANSLATED][TRANSLATED]type
	UINT64          m_uCreateTime;  //[TRANSLATED][TRANSLATED]create time
	UINT64			m_uStartTime;   //[TRANSLATED][TRANSLATED]begin[TRANSLATED][TRANSLATED]
	UINT64			m_uTotalTime;	//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	UINT64			m_dwLastTick;	//[TRANSLATED][TRANSLATED][TRANSLATED]tick[TRANSLATED][TRANSLATED]
	UINT64			m_uMaxGuid;	    //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]GUID
	UINT64			m_uCreateKey;	//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]params
	BOOL			m_bFinished;	//[TRANSLATED][TRANSLATED]whether[TRANSLATED][TRANSLATED]
	SceneLogicBase*	m_pSceneLogic;
	MonsterCreator*	m_pMonsterCreator;

	std::map<UINT64, CSceneObject*>	 m_mapPlayer;		//player[TRANSLATED][TRANSLATED][TRANSLATED]
	std::map<UINT64, CSceneObject*>  m_mapMonster;      //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	std::map<UINT64, CBulletObject*> m_mapBullet;		//bullet[TRANSLATED][TRANSLATED][TRANSLATED]

	//////////////////////////////////////////////////////////////////////////
	//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	HitEffectNtf    m_HitEffectNtf;
	BOOL            AddHitEffect(UINT64 uAttackerID, UINT64 uTargetID, INT32 nHurtValue, BOOL bCritHit, INT32 nHitActionID, INT32 nHitEffectID, FLOAT fHitDistance);
	BOOL            BroadHitEffect();

	//////////////////////////////////////////////////////////////////////////
	BOOL SetBattleResult(UINT32 dwCamp, ECopyResult nBattleResult);
	BOOL SendBattleResult();
	//********************* Message handlers begin ******************************
public:
	BOOL OnMsgTransRoleDataReq(NetPacket* pNetPacket);
	BOOL OnMsgEnterSceneReq(NetPacket* pNetPacket);
	BOOL OnMsgLeaveSceneReq(NetPacket* pNetPacket);
	BOOL OnMsgAbortSceneReq(NetPacket* pNetPacket);
	BOOL OnMsgRoleDisconnect(NetPacket* pNetPacket);
	BOOL OnMsgHeartBeatReq(NetPacket* pNetPacket);
	BOOL OnMsgUseHpBottleReq(NetPacket* pNetPacket);
	BOOL OnMsgUseMpBottleReq(NetPacket* pNetPacket);
	BOOL OnMsgBattleChatReq(NetPacket* pNetPacket);
	BOOL OnMsgObjectActionReq(NetPacket* pNetPacket);
	BOOL OnMsgSkillCastReq(NetPacket* pNetPacket);
	BOOL OnMsgObjectChangeNtf(NetPacket* pNetPacket);
	BOOL OnMsgMountRidingReq(NetPacket* pNetPacket);
	BOOL OnMsgRoleRebornReq(NetPacket* pNetPacket);
	//********************* Message handlers end ******************************
};

#endif //_MAP_H_


