/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___LogServer___GameService.cpp */
﻿#include "stdafx.h"
#include "GameService.h"
#include "../Message/Msg_Game.pb.h"
#include "../Message/Msg_RetCode.pb.h"
#include "../Message/Msg_ID.pb.h"
#include "WatcherClient.h"

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

    if(!CLog::GetInstancePtr()->Start("LogServer", "log"))
    {
        return FALSE;
    }
    CLog::GetInstancePtr()->LogInfo("---------serverbeginstart--------");
    if(!CConfigFile::GetInstancePtr()->Load("servercfg.ini"))
    {
        CLog::GetInstancePtr()->LogError("Configuration file load Failure!");
        return FALSE;
    }

    if (CommonFunc::IsAlreadyRun("LogServer" + CConfigFile::GetInstancePtr()->GetStringValue("areaid")))
    {
        CLog::GetInstancePtr()->LogError("LogServeralready[TRANSLATED]running!");
        return FALSE;
    }

    CLog::GetInstancePtr()->SetLogLevel(CConfigFile::GetInstancePtr()->GetIntValue("log_log_level"));

    UINT16 nPort = CConfigFile::GetInstancePtr()->GetRealNetPort("log_svr_port");
    if (nPort <= 0)
    {
        CLog::GetInstancePtr()->LogError("config[TRANSLATED][TRANSLATED]log_svr_portconfigerror!");
        return FALSE;
    }

    INT32  nMaxConn = CConfigFile::GetInstancePtr()->GetIntValue("log_svr_max_con");
    if(!ServiceBase::GetInstancePtr()->StartNetwork(nPort, nMaxConn, this, "127.0.0.1"))
    {
        CLog::GetInstancePtr()->LogError("Start service Failure!");
        return FALSE;
    }

    ERROR_RETURN_FALSE(m_LogMsgHandler.Init(0));

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

    return TRUE;
}

BOOL CGameService::OnSecondTimer()
{

    return TRUE;
}

BOOL CGameService::DispatchPacket(NetPacket* pNetPacket)
{
    if (CWatcherClient::GetInstancePtr()->DispatchPacket(pNetPacket))
    {
        return TRUE;
    }

    if (m_LogMsgHandler.DispatchPacket(pNetPacket))
    {
        return TRUE;
    }

    return FALSE;
}

BOOL CGameService::Uninit()
{
    CLog::GetInstancePtr()->LogError("========== Server shutting down =======================");

    ServiceBase::GetInstancePtr()->StopNetwork();

    google::protobuf::ShutdownProtobufLibrary();

    CLog::GetInstancePtr()->LogError("========== Server shutdown complete =======================");

    return TRUE;
}

BOOL CGameService::Run()
{
    while (CWatcherClient::GetInstancePtr()->IsRun())
    {
        ServiceBase::GetInstancePtr()->Update();

        m_LogMsgHandler.OnUpdate(CommonFunc::GetTickCount());

        ServiceBase::GetInstancePtr()->FixFrameNum(30);
    }

    return TRUE;
}

