#include "stdafx.h"
#include "GameService.h"
#include "TimerManager.h"
#include "../Message/Msg_Game.pb.h"
#include "../Message/Msg_RetCode.pb.h"
#include "../Message/Msg_ID.pb.h"
#include "LoginClientMgr.h"
#include "WebCommandMgr.h"
#include "WatcherClient.h"
#include "GiftCodeManager.h"
CGameService::CGameService(void)
{
    m_nAccountConnID   = 0;
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

    if(!CLog::GetInstancePtr()->Start("LoginServer", "log"))
    {
        return FALSE;
    }

    CLog::GetInstancePtr()->LogInfo("--------- Server starting -----------");

    if(!CConfigFile::GetInstancePtr()->Load("servercfg.ini"))
    {
        CLog::GetInstancePtr()->LogError("Configuration file load Failure!");
        return FALSE;
    }

    if (CommonFunc::IsAlreadyRun("LoginServer"))
    {
        CLog::GetInstancePtr()->LogError("LoginServeralready在running!");
        return FALSE;
    }

    CLog::GetInstancePtr()->SetLogLevel(CConfigFile::GetInstancePtr()->GetIntValue("login_log_level"));

    UINT16 nPort = CConfigFile::GetInstancePtr()->GetIntValue("login_svr_port");
    if (nPort <= 0)
    {
        CLog::GetInstancePtr()->LogError("config文件login_svr_portconfigerror!");
        return FALSE;
    }

    INT32 nMaxConn = CConfigFile::GetInstancePtr()->GetIntValue("login_svr_max_con");
    if(!ServiceBase::GetInstancePtr()->StartNetwork(nPort, nMaxConn, this))
    {
        CLog::GetInstancePtr()->LogError("Start service Failure!");
        return FALSE;
    }

    INT32 nIntervalTime = CConfigFile::GetInstancePtr()->GetIntValue("heart_interval_time");
    ServiceBase::GetInstancePtr()->SetHeartInterval(nIntervalTime);

    ERROR_RETURN_FALSE(CWebCommandMgr::GetInstancePtr()->Init());

    ERROR_RETURN_FALSE(m_LoginMsgHandler.Init());

    ERROR_RETURN_FALSE(GiftCodeManager::GetInstancePtr()->Init());

    CLog::GetInstancePtr()->LogHiInfo("--------- Server started Success! --------");

    return TRUE;
}


BOOL CGameService::Uninit()
{
    CLog::GetInstancePtr()->LogError("========== Server shutting down =======================");

    ServiceBase::GetInstancePtr()->StopNetwork();

    m_LoginMsgHandler.Uninit();

    google::protobuf::ShutdownProtobufLibrary();

    CLog::GetInstancePtr()->LogError("========== Server shutdown complete =======================");

    return TRUE;
}

BOOL CGameService::Run()
{
    while (CWatcherClient::GetInstancePtr()->IsRun())
    {
        ServiceBase::GetInstancePtr()->Update();

        GiftCodeManager::GetInstancePtr()->Update();

        ServiceBase::GetInstancePtr()->FixFrameNum(200);
    }

    return TRUE;
}


BOOL CGameService::SendCmdToAccountConnection(INT32 nMsgID, UINT64 u64TargetID, INT32 nUserData, const google::protobuf::Message& pdata)
{
    ERROR_RETURN_FALSE(m_nAccountConnID != 0);
    ERROR_RETURN_FALSE(ServiceBase::GetInstancePtr()->SendMsgProtoBuf(m_nAccountConnID, nMsgID, u64TargetID, nUserData, pdata));
    return TRUE;
}

BOOL CGameService::ConnectToAccountSvr()
{
    if (m_nAccountConnID != 0)
    {
        return TRUE;
    }
    INT32 nAccountPort = CConfigFile::GetInstancePtr()->GetIntValue("account_svr_port");
    ERROR_RETURN_FALSE(nAccountPort > 0);
    std::string strAccountIp = CConfigFile::GetInstancePtr()->GetStringValue("account_svr_ip");
    CConnection* pConnection = ServiceBase::GetInstancePtr()->ConnectTo(strAccountIp, nAccountPort);
    ERROR_RETURN_FALSE(pConnection != NULL);
    m_nAccountConnID = pConnection->GetConnectionID();
    pConnection->SetConnectionData(1);
    return TRUE;
}

BOOL CGameService::OnNewConnect(INT32 nConnID)
{
    CWatcherClient::GetInstancePtr()->OnNewConnect(nConnID);

    return TRUE;
}

BOOL CGameService::OnCloseConnect(INT32 nConnID)
{
    if(nConnID == m_nAccountConnID)
    {
        m_nAccountConnID = 0;
        CLog::GetInstancePtr()->LogError("CGameService::OnCloseConnect Disconnect From Account Server.");
    }

    CLoginClientMgr::GetInstancePtr()->OnCloseConnect(nConnID);

    CWatcherClient::GetInstancePtr()->OnCloseConnect(nConnID);

    m_LoginMsgHandler.OnCloseConnect(nConnID);

    return TRUE;
}

BOOL CGameService::OnSecondTimer()
{
    ConnectToAccountSvr();

    CWatcherClient::GetInstancePtr()->OnSecondTimer();

    return TRUE;
}

BOOL CGameService::DispatchPacket(NetPacket* pNetPacket)
{
    if (CWatcherClient::GetInstancePtr()->DispatchPacket(pNetPacket))
    {
        return TRUE;
    }

    if (CWebCommandMgr::GetInstancePtr()->DispatchPacket(pNetPacket))
    {
        return TRUE;
    }

    if (GiftCodeManager::GetInstancePtr()->DispatchPacket(pNetPacket))
    {
        return TRUE;
    }

    if (m_LoginMsgHandler.DispatchPacket(pNetPacket))
    {
        return TRUE;
    }

    return FALSE;
}
