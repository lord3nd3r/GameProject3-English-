/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___LoginServer___LogicSvrManager.h */
#ifndef _LOGIC_SEVER_MANAGERH_
#define _LOGIC_SEVER_MANAGERH_
#include "DBInterface/CppMysql.h"
#include "LockFreeQueue.h"

enum EStatusFlag
{
    ESF_NONE        = 0,//[TRANSLATED][TRANSLATED]
    ESF_GOOD        = 1,//[TRANSLATED][TRANSLATED]
    ESF_BUSY        = 2,//[TRANSLATED][TRANSLATED]
    ESF_FULL        = 3,//[TRANSLATED][TRANSLATED]
    ESF_MAINTAIN    = 4,//[TRANSLATED][TRANSLATED]
    ESF_SHUTDOWN    = 5,//shutdown
    ESF_REVIEW      = 6,//[TRANSLATED][TRANSLATED]
};

enum ECornerMark
{
    ECM_NONE = 0,//[TRANSLATED]
    ECM_NEW = 1, //[TRANSLATED][TRANSLATED]
    ECM_SURGEST = 2,//[TRANSLATED][TRANSLATED]
};

enum EUpdateStatus
{
    EUS_NONE = 0,   //[TRANSLATED][TRANSLATED][TRANSLATED]
    EUS_UPDATE = 1, //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    EUS_RE_REG = 2, //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    EUS_NEW_REG = 3 //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
};

enum EServerStatus
{
    ESS_SVR_OFFLINE     = 0, //[TRANSLATED][TRANSLATED]
    ESS_SVR_ONLINE      = 1, //[TRANSLATED][TRANSLATED]
    ESS_SVR_STARTING    = 2, //start[TRANSLATED]
    ESS_SVR_UPDATING    = 3, //[TRANSLATED][TRANSLATED][TRANSLATED]
};

struct LogicServerNode
{
    LogicServerNode()
    {
        m_nConnID      = 0;
        m_nServerID    = 0;
        m_nPort        = 0;
        m_nHttpPort    = 0;
        m_ServerFlag    = ESF_GOOD;
        m_CornerMark    = 0;
        m_uLastUpdate   = 0;
        m_nMinVersion  = 0;
        m_nMaxVersion  = 0;
        m_nMaxOnline   = 0;    //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        m_nCurOnline   = 0;    //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        m_nTotalNum    = 0;    //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        m_nCacheNum    = 0;    //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
        m_uSvrOpenTime  = 0;
        m_nErrorCnt    = 0;
        m_nFileVer     = 0;
        m_eChangeStatus = EUS_NONE;
        m_ServerStatus  = ESS_SVR_OFFLINE;
    }

    BOOL CheckIP(UINT32 dwIPaddr);

    BOOL CheckChannel(INT32 nChannel);

    BOOL CheckVersion(std::string strVersion);

    INT32       m_nConnID;     //connectionID
    INT32       m_nServerID;   //serverID
    INT32       m_nPort;       //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    INT32       m_nHttpPort;   //http[TRANSLATED][TRANSLATED]
    INT32       m_ServerFlag;   //server[TRANSLATED][TRANSLATED]
    INT32       m_CornerMark;   //server[TRANSLATED][TRANSLATED]
    INT32       m_nMinVersion; //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    INT32       m_nMaxVersion; //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    UINT64      m_uSvrOpenTime; //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    std::string m_strSvrName;   //serverName
    std::string m_strOuterAddr; //server[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    std::string m_strInnerAddr; //server[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    UINT64      m_uLastUpdate;  //server[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    std::set<INT32> m_CheckIpList;   //IP[TRANSLATED][TRANSLATED][TRANSLATED]
    std::set<INT32>  m_CheckChannelList; //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    std::set<UINT64>  m_CheckAccountList; //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    EServerStatus    m_ServerStatus;   //server[TRANSLATED][TRANSLATED]

    INT32       m_nMaxOnline;   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    INT32       m_nCurOnline;   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    INT32       m_nTotalNum;    //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    INT32       m_nCacheNum;    //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    INT32       m_nErrorCnt;    //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]Failure[TRANSLATED][TRANSLATED]
    INT32       m_nFileVer;     //server[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

    EUpdateStatus       m_eChangeStatus;

};

struct GameParamNode
{
    INT32 m_nChannel;  //[TRANSLATED][TRANSLATED]
    std::string m_strParamKey;//
    std::string m_strParamValue; //[TRANSLATED][TRANSLATED]serverID
};

class LogicSvrManager : public std::map<INT32, LogicServerNode*>
{
public:
    LogicSvrManager(void);
    ~LogicSvrManager(void);

public:
    BOOL    Init();

    BOOL    Uninit();

    BOOL    RegisterLogicServer(INT32 nConnID, INT32 nServerID, INT32 nPort, INT32 nHttpPort, const std::string& strSvrName, const std::string& strInnderIp);

    BOOL    UnregisterLogicServer(INT32 nConnID, INT32 nServerID);

    BOOL    UpdateLogicServerInfo(INT32 nServerID, INT32 nMaxOnline, INT32 nCurOnline, INT32 nTotal, INT32 nCacheNum, INT32 nStatus, INT32 nErrorCount, const std::string& strSvrName);

    BOOL    ReloadServerList(INT32 nServerID = 0);

    BOOL    SaveLogicServerThread();

    INT32   GetLogicConnID(INT32 nServerID);

    LogicServerNode* GetSuggestServer(BOOL bReview, INT32 nChannel, UINT32 dwIpaddr);

    LogicServerNode* GetLogicServerInfo(INT32 nServerID);

    BOOL    OnCloseConnect(INT32 nConnID);

    BOOL                m_IsRun;

    std::thread*        m_pThread;

    ArrayLockFreeQueue<LogicServerNode*, 1024>      m_ArrChangedNode;
    std::vector<GameParamNode>  m_vtGameParam;
};

#endif //_LOGIC_SEVER_MANAGERH_