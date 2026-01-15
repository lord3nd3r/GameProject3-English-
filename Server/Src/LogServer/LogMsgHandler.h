#include "DBInterface/CppMysql.h"
#ifndef _LOG_MSG_HANDLER_H_
#define _LOG_MSG_HANDLER_H_

class CLogMsgHandler
{
public:
	CLogMsgHandler();

	~CLogMsgHandler();

	BOOL		Init(INT32 nReserved);

	BOOL		Uninit();

	BOOL		OnUpdate(UINT64 uTick);

	BOOL		DispatchPacket(NetPacket* pNetPacket);

public:
	//********************* Message handlers begin ******************************
	BOOL		OnMsgLogDataNtf(NetPacket* pNetPacket);
	//********************* Message handlers end ******************************

	CppMySQL3DB     m_DBConnection;

	UINT32			m_nWriteCount;

	UINT64          m_nLastWriteTime;

};

#endif //_STAT_MSG_HANDLER_H_
