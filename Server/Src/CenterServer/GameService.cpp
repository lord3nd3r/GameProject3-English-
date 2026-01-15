/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___CenterServer___GameService.cpp */
﻿#include "stdafx.h"
#include "GameService.h"
#include "../Message/Msg_Game.pb.h"
#include "../Message/Msg_RetCode.pb.h"
#include "../Message/Msg_ID.pb.h"
#include "WatcherClient.h"
#include "LogicSvrMgr.h"

CGameService::CGameService(void)
{

}

CGameService::~CGameService(void)
{

}

CGameService* CGameService::GetInstancePtr()
{
    static CGameService _GameService;

    return &_GameService;
}

BOOL CGameService::Init()
{
    CommonFunc::SetCurrentWorkDir("");

    if(!CLog::GetInstancePtr()->Start("CenterServer", "log"))
    {
        return FALSE;
    }
    CLog::GetInstancePtr()->LogInfo("---------serverbeginstart--------");
    if(!CConfigFile::GetInstancePtr()->Load("servercfg.ini"))
    {
        CLog::GetInstancePtr()->LogError("Configuration file load Failure!");
        return FALSE;
    }

    if (CommonFunc::IsAlreadyRun("CenterServer"))
    {
        CLog::GetInstancePtr()->LogError("CenterServeralready[TRANSLATED]running!");
        return FALSE;
    }

    CLog::GetInstancePtr()->SetLogLevel(CConfigFile::GetInstancePtr()->GetIntValue("center_log_level"));


    UINT16 nPort = CConfigFile::GetInstancePtr()->GetIntValue("center_svr_port");
    if (nPort <= 0)
    {
        CLog::GetInstancePtr()->LogError("config[TRANSLATED][TRANSLATED]center_svr_portconfigerror!");
        return FALSE;
    }
    INT32 nMaxConn = CConfigFile::GetInstancePtr()->GetIntValue("center_svr_max_con");
    std::string strListenIp = CConfigFile::GetInstancePtr()->GetStringValue("center_svr_ip");
    if(!ServiceBase::GetInstancePtr()->StartNetwork(nPort, nMaxConn, this, strListenIp))
    {
        CLog::GetInstancePtr()->LogError("Start service Failure!");
        return FALSE;
    }

    ERROR_RETURN_FALSE(m_CenterMsgHandler.Init(0));

    //AsyncMySQLDB::GetInstancePtr()->Init();

    CLog::GetInstancePtr()->LogHiInfo("--------- Server started Success! --------");
    return TRUE;
}


BOOL CGameService::OnNewConnect(INT32 nConnID)
{
    CWatcherClient::GetInstancePtr()->OnNewConnect(nConnID);

    return TRUE;
}

BOOL CGameService::OnCloseConnect(INT32 nConnID)
{
    CWatcherClient::GetInstancePtr()->OnCloseConnect(nConnID);

    CLogicSvrMgr::GetInstancePtr()->OnCloseConnect(nConnID);

    return TRUE;
}

BOOL CGameService::OnSecondTimer()
{
    return TRUE;
}

BOOL CGameService::DispatchPacket(NetPacket* pNetPacket)
{
    if (m_CenterMsgHandler.DispatchPacket(pNetPacket))
    {
        return TRUE;
    }

    return FALSE;
}

BOOL CGameService::Uninit()
{
    CLog::GetInstancePtr()->LogHiInfo("========== Server shutting down =======================");

    ServiceBase::GetInstancePtr()->StopNetwork();


    m_CenterMsgHandler.Uninit();

    google::protobuf::ShutdownProtobufLibrary();

    CLog::GetInstancePtr()->LogHiInfo("========== Server shutdown complete =======================");

    return TRUE;
}

BOOL CGameService::Run()
{
    while (CWatcherClient::GetInstancePtr()->IsRun())
    {
        ServiceBase::GetInstancePtr()->Update();

        CommonFunc::Sleep(1);
    }

    return TRUE;
}


