/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___LogicServer___GameSvrMgr.h */
﻿#ifndef __GAME_SVR_MGR__
#define __GAME_SVR_MGR__

#include "../Message/Msg_Copy.pb.h"
#include "../Message/Msg_Game.pb.h"
#include "AVLTree.h"
struct GameSvrInfo
{
    GameSvrInfo(UINT32 nSvrID, INT32 nConnID)
    {
        m_nSvrID = nSvrID;
        m_nConnID = nConnID;
        m_nLoad   = 0;
    }
    INT32 m_nSvrID;
    INT32 m_nConnID;
    INT32 m_nLoad;      //[TRANSLATED][TRANSLATED][TRANSLATED]
};

struct CityInfo
{
    CityInfo(UINT32 dwCopyID, UINT32 dwSvrID, UINT32 dwConID, UINT32 dwCopyGuid)
    {
        m_dwSvrID  = dwSvrID;
        m_nConnID = dwConID;
        m_dwCopyID = dwCopyID;
        m_dwCopyGuid = dwCopyGuid;

    }
    UINT32 m_dwCopyID;
    UINT32 m_dwSvrID;
    UINT32 m_nConnID;
    UINT32 m_dwCopyGuid;
};

struct CWaitItem
{
    CWaitItem()
    {
        memset(uID, 0, sizeof(uID));
        memset(nCamp, 0, sizeof(nCamp));
    }
    ~CWaitItem()
    {
        memset(uID, 0, sizeof(uID));
        memset(nCamp, 0, sizeof(nCamp));
    }

    UINT64 uID[10] = {0};
    INT32 nCamp[10] = {0};
};

class CWaitCopyList : public AVLTree<UINT64, CWaitItem>
{
public:
    CWaitCopyList();
    ~CWaitCopyList();
public:
    CWaitItem*      GetWaitItem(UINT64 uParam);
};

class CGameSvrMgr
{
private:
    CGameSvrMgr(void);
    ~CGameSvrMgr(void);
public:
    static CGameSvrMgr* GetInstancePtr();

public:
    BOOL        Init();

    BOOL        Uninit();

    BOOL        TakeCopyRequest(UINT64 uID, INT32 dwCamp, UINT32 dwCopyID, UINT32 dwCopyType);

    BOOL        TakeCopyRequest(UINT64 uID[], INT32 dwCamp[], INT32 nNum, UINT32 dwCopyID, UINT32 dwCopyType);

    UINT32      GetConnIDBySvrID(UINT32 dwServerID);

    BOOL        SendPlayerToMainCity(UINT64 u64ID, UINT32 dwCopyID);

    BOOL        CreateScene(UINT32 dwCopyID, UINT64 CreateParam, UINT32 dwCopyType);

    VOID        RegisterMessageHanler();

    BOOL        BroadMsgToAll(INT32 nMsgID, CHAR* pData, INT32 nSize);
private:
    UINT32      GetServerIDByCopyGuid(UINT32 dwCopyGuid);

    UINT32      GetBestGameServerID();

    GameSvrInfo* GetGameSvrInfo(UINT32 dwSvrID);

    BOOL        SendCreateSceneCmd(UINT32 dwServerID, UINT32 dwCopyID, UINT32 dwCopyType, UINT64 CreateParam, UINT32 dwPlayerNum);

    BOOL        SendPlayerToCopy(UINT64 u64ID, UINT32 dwServerID, UINT32 dwCopyID, UINT32 dwCopyGuid, UINT32 dwCamp);

    BOOL        GetMainCityInfo(UINT32 dwCopyID, UINT32& dwServerID, UINT32& nConnID, UINT32& dwCopyGuid);

    BOOL        AddWaitItem(UINT64 u64ID, INT32 dwCamp);

    BOOL        AddWaitItem(UINT64 uKey, UINT64 uID[], INT32 dwCamp[], INT32 nNum);

    BOOL        CreateScene(UINT32 dwCopyID, UINT64 CreateParam, UINT32 dwPlayerNum, UINT32 dwCopyType);

public:

    //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    //////////////////////////////////////////////////////////////////////////
    BOOL        OnMainCopyResult(BattleResultNty& Nty);

    //********************* Message handlers begin ******************************
public:
    BOOL    OnCloseConnect(INT32 nConnID);
    BOOL    OnMsgGameSvrRegister(NetPacket* pNetPacket); //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]server[TRANSLATED][TRANSLATED]
    BOOL    OnMsgCreateSceneAck(NetPacket* pNetPacket);  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]Success
    BOOL    OnMsgTransRoleDataAck(NetPacket* pNetPacket);//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]Success
    BOOL    OnMsgCopyReportReq(NetPacket* pNetPacket);
    BOOL    OnMsgBattleResultNty(NetPacket* pNetPacket);
    //********************* Message handlers end ******************************
public:
    std::map<UINT32, GameSvrInfo>   m_mapGameSvr; //serverID-->[TRANSLATED][TRANSLATED]Server information

    std::map<UINT32, CityInfo>      m_mapCity;

    std::map<UINT32, UINT32>        m_GuidToSvrID;    //[TRANSLATED][TRANSLATED]guid->[TRANSLATED][TRANSLATED]serverID

    CWaitCopyList                   m_WaitCopyList;
};

#endif
