#ifndef __WEB_COMMAND_MGR_H__
#define __WEB_COMMAND_MGR_H__

#include "WebActionDef.h"
#include "HttpParameter.h"

class CWebCommandMgr
{
    CWebCommandMgr();
    ~CWebCommandMgr();
public:
    static CWebCommandMgr* GetInstancePtr();

    BOOL   DispatchPacket(NetPacket* pNetPacket);

    BOOL   Init();

    BOOL   Uninit();

    BOOL SendWebResult(INT32 nConnID, EWebResult eResult);
public:
    //********************* Message handlers begin ******************************
    BOOL OnMsgGmCommandReq(NetPacket* pNetPacket);

    //********************* Message handlers end ******************************

public:
    //*********************WebActionhandledefinitionbegin******************************
    void OnGmSealAccount(HttpParameter& hParams, INT32 nConnID);
    void OnGmServerChange(HttpParameter& hParams, INT32 nConnID);
    //*********************WebActionhandledefinitionbegin******************************
};
#endif