/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___LoginServer___LoginClientMgr.h */
﻿#ifndef __LOGIN_CLIENT_MGR_H__
#define __LOGIN_CLIENT_MGR_H__
#include "AVLTree.h"


enum EClientStatue
{
    ECS_NONE            = 0,   //[TRANSLATED][TRANSLATED]
    ECS_VER_CHECKED     = 1,   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    ECS_PSD_CHECKED     = 2,   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
};

class  CLoginClient
{
public:
    CLoginClient();

    ~CLoginClient();

public:
    VOID    SetConnID(INT32 nConnID);

    INT32   GetConnID();

    EClientStatue GetClientStatue();
public:

    INT32          m_nConnID;

    EClientStatue  m_ClientStatue;
};

class CLoginClientMgr : public AVLTree<INT32, CLoginClient>
{
private:
    CLoginClientMgr(void);
    ~CLoginClientMgr(void);

public:
    static CLoginClientMgr* GetInstancePtr();

    CLoginClient*   GetByConnID(INT32 nConnID);

    BOOL            RemoveByConnID(INT32 nConnID);

    CLoginClient*   CreateLoginClient(INT32 nConnID);

    BOOL            CheckClientMessage(INT32 nConnID, INT32 nMsgID);

    BOOL            OnCloseConnect(INT32 nConnID);
};

#endif /*__LOGIN_CLIENT_MGR_H__*/