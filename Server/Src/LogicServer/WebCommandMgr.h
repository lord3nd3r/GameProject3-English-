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

	BOOL   SendWebResult(INT32 nConnID, EWebResult eResult);

public:
	//********************* Message handlers begin ******************************
	BOOL OnMsgGmCommandReq(NetPacket* pNetPacket);
	//********************* Message handlers end ******************************

public:
	//*********************WebActionhandledefinitionbegin******************************
	void OnGmReloadTable(HttpParameter& hParams, INT32 nConnID);
	void OnGmSealRole(HttpParameter& hParams, INT32 nConnID);
	void OnGmSingleMail(HttpParameter& hParams, INT32 nConnID); //Send single mail
	void OnGmGroupMail(HttpParameter& hParams, INT32 nConnID);  //Send group mail
	void OnGmDeleteMail(HttpParameter& hParams, INT32 nConnID); //Delete mail
	void OnGmCommand(HttpParameter& hParams, INT32 nConnID);
	//*********************WebActionhandledefinitionbegin******************************

};
#endif