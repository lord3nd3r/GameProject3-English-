/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___LogicServer___PlayerObject.h */
﻿#ifndef __WS_PLAYER_OBJECT_H__
#define __WS_PLAYER_OBJECT_H__
#include "AVLTree.h"
#include "Position.h"
#include "ModuleBase.h"
#include "../Message/Msg_Game.pb.h"
#include "../ServerData/ServerDefine.h"
#include "../ServerData/ServerStruct.h"
#include "MsgHandlerManager.h"

class CPlayerObject : public CHandlerManager
{
public:
    CPlayerObject();

    ~CPlayerObject();

    BOOL        Init(UINT64 uRoleID);

    BOOL        Uninit();

    BOOL        OnCreate(UINT64 uRoleID);

    BOOL        OnDestroy();

    BOOL        OnLogin();

    BOOL        OnLogout();

    BOOL        OnNewDay();

    BOOL        ReadFromDBLoginData(DBRoleLoginAck& Ack);

    BOOL        SendMsgProtoBuf(INT32 nMsgID, const google::protobuf::Message& pdata);

    BOOL        SendMsgRawData(INT32 nMsgID, const char* pdata, UINT32 dwLen);

    //[TRANSLATED]player[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]message
    BOOL        SendMsgToScene(INT32 nMsgID, const google::protobuf::Message& pdata);

    BOOL        ToTransferData(TransferDataItem* pTransItem);

    BOOL        NotifyTaskEvent(UINT32 dwEventID, UINT32 dwParam1, UINT32 dwParm2);

    BOOL        IsOnline();

    BOOL        SetOnline(BOOL bOnline);

    BOOL        NotifyChange();

public:
    //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    BOOL        SendIntoSceneNotify(UINT32 dwCopyGuid, UINT32 dwCopyID, UINT32 dwSvrID);
    BOOL        SendLeaveScene(UINT32 dwCopyGuid, UINT32 dwSvrID);
    BOOL        SendRoleLoginAck();
    BOOL        SendPlayerChange(EChangeType eChangeType, UINT64 uIntValue1, UINT64 uIntValue2, std::string strValue);

    BOOL        SetConnectID(UINT32 dwProxyID, UINT32 dwClientID);

    BOOL        ClearCopyStatus();
    BOOL        SetCopyStatus(UINT32 dwCopyGuid, UINT32 dwCopyID, UINT32 dwCopySvrID, BOOL bMainCity);

    //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    BOOL            CreateAllModule();
    BOOL            DestroyAllModule();
    CModuleBase*    GetModuleByType(UINT32 dwModuleType);

public:
    UINT32          CheckCopyConditoin(UINT32 dwCopyID);

public:
    UINT64          GetRoleID();
    UINT64          GetAccountID();
    UINT32          GetCityCopyID();
    UINT32          GetActorID();
    CHAR*           GetName();
    UINT32          GetCarrerID();
    INT64           GetProperty(ERoleProperty ePropertyID);
    //////////////////////////////////////////////////////////////////////////
    //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

    UINT64      m_uRoomID;      //[TRANSLATED][TRANSLATED]ID

    UINT64      GetRoomID();

    VOID        SetRoomID(UINT64 uRoomID);

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED]， [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    BOOL        CalcFightDataInfo();

    INT32       m_Propertys[PROPERTY_NUM];

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    //////////////////////////////////////////////////////////////////////////
public:
    //[TRANSLATED][TRANSLATED]message[TRANSLATED]

    UINT64          m_uRoleID;
    INT32           m_nProxyConnID;
    INT32           m_nClientConnID;
    BOOL            m_IsOnline;
    std::vector<CModuleBase*> m_MoudleList;

public:
    UINT32      m_dwCopyGuid;   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]ID
    UINT32      m_dwCopyID;     //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]type
    UINT32      m_dwCopySvrID;  //[TRANSLATED][TRANSLATED]server[TRANSLATED]ID
    BOOL        m_bMainCity;    //whether[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]




public:
    //********************* Message handlers begin ******************************
    //********************* Message handlers end ******************************
};


#endif //__WS_PLAYER_OBJECT_H__
