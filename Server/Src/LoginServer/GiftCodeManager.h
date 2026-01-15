/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___LoginServer___GiftCodeManager.h */
﻿#ifndef _GIFT_CODE_MANAGER_H_
#define _GIFT_CODE_MANAGER_H_

#include "DBInterface/CppMysql.h"
#include "LockFreeQueue.h"

#define GIFT_AWARD_ITEM_NUM 8

struct AwardNode
{
    AwardNode()
    {
        m_nAwardID = 0;   //[TRANSLATED][TRANSLATED]ID
    }

    UINT64      m_nAwardID = 0;    //[TRANSLATED][TRANSLATED]ID
    INT32       m_nItemID[GIFT_AWARD_ITEM_NUM] = { 0 };
    INT32       m_nItemNum[GIFT_AWARD_ITEM_NUM] = { 0 };
};

struct CodeReqNode
{
    CodeReqNode()
    {
        m_uAccountID    = 0;   //[TRANSLATED][TRANSLATED]ID
        m_uRoleID       = 0;   //[TRANSLATED][TRANSLATED]ID
        m_nAreaID      = 0;   //[TRANSLATED][TRANSLATED]ID
        m_nChannel     = 0;   //[TRANSLATED][TRANSLATED][TRANSLATED]
        m_nResult      = 0;
        m_nConnID      = 0;
    }

    std::string m_strCode;      //[TRANSLATED][TRANSLATED][TRANSLATED]
    UINT64      m_uAccountID;   //[TRANSLATED][TRANSLATED]ID
    UINT64      m_uRoleID;      //[TRANSLATED][TRANSLATED]ID
    INT32       m_nAreaID;     //[TRANSLATED][TRANSLATED]ID
    INT32       m_nChannel;    //[TRANSLATED][TRANSLATED][TRANSLATED]
    INT32       m_nResult;     //[TRANSLATED][TRANSLATED][TRANSLATED]
    INT32       m_nConnID;     //connectionID
    INT32       m_nItemID[GIFT_AWARD_ITEM_NUM] = { 0 };
    INT32       m_nItemNum[GIFT_AWARD_ITEM_NUM] = { 0 };
};

class GiftCodeManager
{
public:
    GiftCodeManager(void);
    ~GiftCodeManager(void);

public:
    static GiftCodeManager* GetInstancePtr();

public:
    BOOL    Init();

    BOOL    Uninit();

    BOOL    ProceeGiftCodeThread();

    BOOL    Update();

    BOOL    DispatchPacket(NetPacket* pNetPacket);

public:
    //********************* Message handlers begin ******************************
    BOOL OnMsgRecvGiftCodeReq(NetPacket* pNetPacket);
    //********************* Message handlers end ******************************

public:
    BOOL                m_IsRun;

    std::thread*        m_pThread;

    ArrayLockFreeQueue<CodeReqNode*, 1024>      m_ArrPrepareNode;
    ArrayLockFreeQueue<CodeReqNode*, 1024>      m_ArrFinishNode;


};

#endif //_PAY_ORDER_MANAGERH_