/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___LogicServer___EquipModule.h */
﻿#ifndef __EQUIPMENT_MODULE_H__
#define __EQUIPMENT_MODULE_H__
#include "ModuleBase.h"
#include "EquipData.h"
#include "ServerDefine.h"
#include "../Message/Game_Define.pb.h"
struct EquipDataObject;
class CEquipModule  : public CModuleBase
{
public:
	CEquipModule(CPlayerObject* pOwner);

	~CEquipModule();

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
	UINT64 AddEquip(UINT32 dwEquipID);

	BOOL NotifyChange();

	EquipDataObject* GetEquipByGuid(UINT64 uGuid);

	//uguid：[TRANSLATED][TRANSLATED]guid, ubagguid， [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]guid
	UINT32 DressEquip(UINT64 uGuid, UINT64 uBagGuid);

	UINT32 UnDressEquip(UINT64 uGuid);

public:
	//********************* Message handlers begin ******************************
	BOOL OnMsgSetupEquipReq(NetPacket* pNetPacket);  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	BOOL OnMsgUnsetEquipReq(NetPacket* pNetPacket);  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	//********************* Message handlers end ******************************

public:
	std::map<UINT64, EquipDataObject*>m_mapEquipData;
	EquipDataObject* m_vtDressEquip[EQUIP_MAX_NUM];
};

#endif //__EQUIPMENT_MODULE_H__
