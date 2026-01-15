#ifndef _WATCH_MSG_HANDLER_H_
#define _WATCH_MSG_HANDLER_H_

#include "RapidXml.h"
#include "WebActionDef.h"
#include "HttpParameter.h"

enum EProcessStatus
{
    EPS_Stop,       //Stop status
    EPS_Start,      //Start status
    EPS_Checking,   //Checking status
};

struct ProcessInfo
{
    INT64           ProcessID;
    std::string     ProcessName;
    EProcessStatus  ProscessStatus;
};

struct ServerInfo
{
    INT32           nAreaID = 0;
    BOOL            bWatch = FALSE;
    UINT64          uLastOpTime = 0; //Last operation time
    std::vector<ProcessInfo> ProcessList;
};

class CWatchMsgHandler
{
public:
    CWatchMsgHandler();

    ~CWatchMsgHandler();

    BOOL        Init(INT32 nReserved);

    BOOL        Uninit();

    BOOL        DispatchPacket( NetPacket* pNetPacket);

    BOOL        OnNewConnect(INT32 nConnID);

    BOOL        OnCloseConnect(INT32 nConnID);

    BOOL        OnSecondTimer();

    BOOL        ReportStatusTimer(INT32 key);

    BOOL        RegExitSignal();

    BOOL        SendWebResult(INT32 nConnID, EWebResult eResult);
public:
    //*********************Message processing definition start******************************
    BOOL OnMsgWebCommandReq(NetPacket* pNetPacket);
    //*********************Message processing definition end******************************

public:
    //*********************WebAction processing definition start******************************
    void OnGmServerStart(HttpParameter& hParams, INT32 nConnID);
    void OnGmServerStop(HttpParameter& hParams, INT32 nConnID);
    void OnGmServerUpdate(HttpParameter& hParams, INT32 nConnID);
    void OnGmServerInfo(HttpParameter& hParams, INT32 nConnID);
    //*********************WebAction processing definition end******************************

protected:

    BOOL InitServerList();

    BOOL LoadCloudParam();

    BOOL CheckServerStatus(BOOL bFrist = FALSE);

    ServerInfo* GetServerInfo(INT32 nAreaID);

    std::map<INT32, ServerInfo> m_mapServer;

    std::string m_strRootPath;
    std::string m_strOuterIp;
    std::string m_strInnerIp;
    std::string m_strGmSvrIp;
    INT32       m_nCloudID;

    std::string m_strSvrName;
};

#endif //_WATCH_MSG_HANDLER_H_
