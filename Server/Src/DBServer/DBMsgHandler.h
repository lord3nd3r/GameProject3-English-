/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___DBServer___DBMsgHandler.h */
#ifndef _DB_MSG_HANDLER_H_
#define _DB_MSG_HANDLER_H_
#include "DBManager.h"
#include "LockFreeQueue.h"

class CDBMsgHandler
{
public:
	CDBMsgHandler();

	~CDBMsgHandler();

	BOOL AddPacket(NetPacket* pNetPacket);

	BOOL DispatchPacket(NetPacket* pNetPacket);

	BOOL OnUpdate( UINT64 uTick );

	BOOL Init(INT32 nReserved);

	BOOL Run();

	BOOL Uninit();
	//********************* Message handlers begin ******************************
public:
	BOOL OnMsgRoleListReq(NetPacket* pPacket);
	BOOL OnMsgRoleLoginReq(NetPacket* pPacket);
	BOOL OnMsgRoleDeleteReq(NetPacket* pPacket);
	BOOL OnMsgExeSqlReq(NetPacket* pPacket);
	BOOL OnMsgLogicSvrRegReq(NetPacket* pPacket);
	//********************* Message handlers end ******************************

public:
	//[TRANSLATED][TRANSLATED][TRANSLATED]definition
	CDBManager							m_DBManager;

	ArrayLockFreeQueue<NetPacket*>		m_PacketQueue;

	std::thread*					   	m_pThread;

	BOOL								m_bRun;
};

#endif //_DB_MSG_HANDLER_H_
