#ifndef _CENTER_MSG_HANDLER_H_
#define _CENTER_MSG_HANDLER_H_

class CCenterMsgHandler
{
public:
    CCenterMsgHandler();

    ~CCenterMsgHandler();

    BOOL        Init(INT32 nReserved);

    BOOL        Uninit();

    BOOL        DispatchPacket( NetPacket* pNetPacket);

public:
    //********************* Message handlers begin ******************************
    BOOL        OnMsgLogicSvrRegReq(NetPacket* pPacket);
    //********************* Message handlers end ******************************
};

#endif //_CENTER_MSG_HANDLER_H_
