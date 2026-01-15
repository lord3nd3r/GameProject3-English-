/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___LogicServer___GemModule.h */
﻿#ifndef __GEM_MODULE_H__
#define __GEM_MODULE_H__
#include "ModuleBase.h"
#include "../ServerData/ServerDefine.h"
#include "../Message/Game_Define.pb.h"
struct GemDataObject;
class CGemModule : public CModuleBase
{
public:
	CGemModule(CPlayerObject* pOwner);

	~CGemModule();

public:
	BOOL OnCreate(UINT64 u64RoleID);

	BOOL OnDestroy();

	BOOL OnLogin();

	BOOL OnLogout();

	BOOL OnNewDay();

	BOOL ReadFromDBLoginData(DBRoleLoginAck& Ack);

	BOOL SaveToClientLoginData(RoleLoginAck& Ack);

	BOOL CalcFightValue(INT32 nValue[PROPERTY_NUM], INT32 nPercent[PROPERTY_NUM], INT32& FightValue);

	VOID RegisterMessageHanler();
public:
	UINT64 AddGem(UINT32 dwGemID);

	BOOL NotifyChange();

	GemDataObject* GetGemByGuid(UINT64 uGuid);

	UINT32 DressGem(UINT64 uGuid, UINT64 uBagGuid, INT32 Pos);

	UINT32 UnDressGem(UINT64 uGuid);

public:
	//********************* Message handlers begin ******************************
	BOOL OnMsgSetupGemReq(NetPacket* pNetPacket);  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	BOOL OnMsgUnsetGemReq(NetPacket* pNetPacket);  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	//********************* Message handlers end ******************************

public:
	std::map<UINT64, GemDataObject*>m_mapGemData;
	GemDataObject* m_vtDressGem[40];
};

#endif //__GEM_MODULE_H__
