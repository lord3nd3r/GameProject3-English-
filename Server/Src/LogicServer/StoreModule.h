/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___LogicServer___StoreModule.h */
#ifndef __STORE_MODULE_H__
#define __STORE_MODULE_H__
#include "ModuleBase.h"
struct StoreDataObject;
class CStoreModule  : public CModuleBase
{
public:
	CStoreModule(CPlayerObject* pOwner);

	~CStoreModule();

public:
	BOOL OnCreate(UINT64 u64RoleID);

	BOOL OnDestroy();

	BOOL OnLogin();

	BOOL OnLogout();

	BOOL OnNewDay();

	VOID RegisterMessageHanler();

	BOOL ReadFromDBLoginData(DBRoleLoginAck& Ack);

	BOOL SaveToClientLoginData(RoleLoginAck& Ack);

	BOOL	NotifyChange();

public:
	//********************* Message handlers begin ******************************
	BOOL OnMsgStoreBuyReq(NetPacket* pNetPacket);  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	//********************* Message handlers end ******************************

public:


};

#endif //__STORE_MODULE_H__
