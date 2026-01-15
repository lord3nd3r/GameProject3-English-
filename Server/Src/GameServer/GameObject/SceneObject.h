/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___GameServer___GameObject___SceneObject.h */
#ifndef _SCENE_OBJECT_H_
#define _SCENE_OBJECT_H_
#include "../Message/Msg_Move.pb.h"
#include "../Message/Msg_Game.pb.h"
#include "../Message/Game_Define.pb.h"
#include "../Message/Msg_Struct.h"

#include "Position.h"
#include "SkillObject.h"
#include "MapObject.h"
#include "CommonMath.h"
#include "../GameStruct.h"
#include "StaticStruct.h"

class CScene;
class ResultPlayer;
class CBuffObject;
class CSceneObject : public CMapObject
{
public:
	CSceneObject(UINT64 uGuid, CScene* pScene);

	~CSceneObject();
public:
	BOOL            SendMsgProtoBuf(INT32 nMsgID, const google::protobuf::Message& pdata);
	BOOL            SendMsgRawData(INT32 nMsgID, const char* pdata, UINT32 dwLen);
	BOOL            SetConnectID(UINT32 dwProxyID, UINT32 dwClientID);
	BOOL            OnUpdate(UINT64 uTick);
	BOOL            SaveNewData(ObjectNewNty& Nty);
	BOOL            SaveUpdateData(ObjectActionNty& Nty);
	BOOL            Reset();

	//[TRANSLATED][TRANSLATED]is[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
public:
	UINT32          GetHp();
	UINT32          GetMp();
	UINT64          GetObjectGUID();
	UINT32          GetActorID();
	UINT32          GetObjType();
	UINT32          GetCamp();
	UINT64          GetControllerID();
	VOID            SetControllerID(UINT64 uID);

	VOID            ChangeHp(INT32 nValue);
	VOID            ChangeMp(INT32 nValue);

	BOOL            IsChanged();

	BOOL            IsConnected();
	BOOL            IsEnterCopy();
	VOID            SetEnterCopy();

	VOID            SetActionID(UINT32 dwActionID);
	UINT32          GetActionID();

	BOOL            IsDead();
	BOOL			SetDead(BOOL bDead);

	BOOL			SetPos(FLOAT x, FLOAT y, FLOAT z, FLOAT ft = 0);
	Vector3D&       GetPos();

	FLOAT           GetFaceTo();

	BOOL			SaveBattleRecord(ResultPlayer* pResult);

	BOOL			ChangeEquip(INT32 nPos, UINT32 dwEquipID);
	BOOL            ChangeMount(UINT32 dwMountID);
	BOOL            SetRiding(BOOL bRiding);
	FLOAT           GetCurSpeed();
	BOOL            IsRobot();
public:
	//////////////////////////////////////////////////////////////////////////
	//buff[TRANSLATED]handle
	BOOL			AddBuff(UINT32 dwBuffID);
	BOOL			RemoveBuff(UINT32 dwBuffID);
	BOOL			UpdateBuff(UINT64 uTick);
	BOOL			ClearBuff();
	std::map<UINT32, CBuffObject*> m_mapBuff;
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	//skill
	std::vector<St_SkillData> m_vtNormals;
	std::vector<St_SkillData> m_vtSpecials;
	CSkillObject	m_SkillObject;
	UINT32			ProcessSkill(const SkillCastReq& Req);
	UINT32			ProcessAction(const ActionReqItem& Item);
	UINT64			GetLastSkillTick(UINT32 dwSkillID);
	BOOL			SetLastSkillTick(UINT32 dwSkillID, UINT64 uTick);
	St_SkillData*	GetSkillData(UINT32 dwSkillID);
	INT32			GetSkillLevel(UINT32 dwSkillID);
	BOOL			InitSkills(const google::protobuf::RepeatedPtrField<::SkillItem>& vtSkills);
	BOOL			InitSkills(); //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	UINT32          GetNextComboSkill(UINT32 dwSkillID);
	BOOL            CheckSkillCD(UINT32 dwSkillID, UINT64 uCD);
	INT32           GetShip(CSceneObject* pTarget);

	BOOL			IsInCircle(Vector3D hitPoint, float radius, float height);
	BOOL			IsInSquare(Vector3D hitPoint, float hitDegree, float length, float width);
	BOOL			IsInSector(Vector3D hitPoint, float hitDegree, float radius, float hAngle);
	VOID            SetBattleResult(ECopyResult nBattleResult);
	ECopyResult     GetBattleResult();

	//////////////////////////////////////////////////////////////////////////
	//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	BOOL            UpdatePosition(UINT64 uTick);
	//[TRANSLATED][TRANSLATED]
	BOOL            Revive();
	//////////////////////////////////////////////////////////////////////////

public:
	//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	//////////////////////////////////////////////////////////
	std::string     m_strName;						//[TRANSLATED][TRANSLATED][TRANSLATED]Name
	UINT64          m_uGuid;						//[TRANSLATED][TRANSLATED]ID, [TRANSLATED]player[TRANSLATED][TRANSLATED][TRANSLATED]ID
	UINT32          m_dwActorID;					//[TRANSLATED][TRANSLATED]ID
	UINT32          m_dwObjType;					//[TRANSLATED][TRANSLATED]type player，[TRANSLATED][TRANSLATED]， NPC[TRANSLATED][TRANSLATED][TRANSLATED]
	INT32           m_dwCamp;						//[TRANSLATED][TRANSLATED]
	UINT32          m_dwActionID;					//[TRANSLATED][TRANSLATED]action[TRANSLATED][TRANSLATED]
	Vector3D        m_Pos;							//position
	FLOAT           m_ft;							//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED], [TRANSLATED][TRANSLATED]
	UINT32          m_dwStatus;				        //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	INT32           m_dwLevel;						//Level
	INT32           m_Propertys[PROPERTY_NUM];		//15[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	UINT32          m_Equips[EQUIP_MAX_NUM];		//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	UINT32          m_dwMountID;                    //[TRANSLATED][TRANSLATED]ID
	BOOL            m_bRiding;                      //whether[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	BOOL            m_bRobot;                       //[TRANSLATED][TRANSLATED][TRANSLATED]
	St_ChangeStatus m_ChangeFlag;					//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

	UINT64          m_uHostGuid;					//[TRANSLATED][TRANSLATED][TRANSLATED]GUID
	UINT64          m_uControlerID;					//AI[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]GUID
	UINT64          m_uSummonerID;					//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]GUID
	UINT64          m_uPetGuid;                     //[TRANSLATED][TRANSLATED]guid
	UINT64          m_uPartnerGuid;                 //[TRANSLATED][TRANSLATED]guid
	UINT64          m_uLastMoveTick;

	BOOL            m_bIsCampCheck;					//whether[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	BOOL            m_bIsMonsCheck;					//whether[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED](player[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED], [TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED], config[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED])
	StActorInfo*    m_pActorInfo;                   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	ECopyResult     m_nBattleResult;                //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

	HitEffectNtf    m_EffectNtf;
	//////////////////////////////////////////////////////////
	//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	BOOL            m_bEnter;   //playerwhetheralready[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

	//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

	//[TRANSLATED][TRANSLATED][TRANSLATED]connection[TRANSLATED][TRANSLATED]，[TRANSLATED]player[TRANSLATED][TRANSLATED]
	////////////////////////////////////////////////////////////////
	UINT32          m_dwProxyConnID;
	UINT32          m_dwClientConnID;
};


#endif //_SCENE_OBJECT_H_
