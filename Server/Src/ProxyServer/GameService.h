/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ProxyServer___GameService.h */
﻿#ifndef _GAME_SERVICE_H_
#define _GAME_SERVICE_H_
#include "ProxyMsgHandler.h"
class  CConnection;

class CGameService  : public IPacketDispatcher
{
private:
    CGameService(void);
    virtual ~CGameService(void);

public:
    static CGameService* GetInstancePtr();

    BOOL        Init();

    BOOL        Uninit();

    BOOL        Run();

    BOOL        OnNewConnect(INT32 nConnID);

    BOOL        OnCloseConnect(INT32 nConnID);

    BOOL        OnSecondTimer();

    BOOL        DispatchPacket( NetPacket* pNetPacket);

    INT32       GetLogicConnID();

    BOOL        ConnectToLogicSvr();

public:
    //handle[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]connection
    CProxyMsgHandler    m_ProxyMsgHandler;

    INT32               m_nLogicConnID;
    BOOL                m_bLogicConnect;
public:
    //********************* Message handlers begin ******************************
    //********************* Message handlers end ******************************
};

#endif
