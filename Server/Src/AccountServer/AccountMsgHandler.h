#ifndef _ACCOUNT_MSG_HANDLER_H_
#define _ACCOUNT_MSG_HANDLER_H_

#include "AccountManager.h"
class CAccountMsgHandler
{
public:
	CAccountMsgHandler();

	~CAccountMsgHandler();

	BOOL Init(INT32 nReserved);

	BOOL Uninit();

	BOOL DispatchPacket(NetPacket* pNetPacket);

	//********************* Message handlers begin ******************************
public:
	BOOL OnMsgAccountRegReq(NetPacket* pPacket);
	BOOL OnMsgAccontLoginReq(NetPacket* pPacket);
	BOOL OnMsgSealAccountReq(NetPacket* pPacket);
	BOOL OnMsgSetLastServerNty(NetPacket* pPacket);
	//********************* Message handlers end ******************************

public:

	CAccountObjectMgr m_AccountManager;
};

#endif //_DB_MSG_HANDLER_H_
