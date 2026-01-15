// PressureTest.cpp : Defines the entry point for the console application.
//

#include "ClientObject.h"
#include "../../Src/ServerEngine/CommonFunc.h"
#include "../../Src/ServerEngine/CommonSocket.h"

#define RUN_TIME 50

std::vector<CClientObject*> g_vtClientList;

int main(int argc, char* argv[])
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int nRobotNum = 1;
	printf("Starting PressureTest with 1 bot...\n");
	// scanf("%d", &nRobotNum);

	CommonSocket::InitNetwork();

	if(nRobotNum <= 0)
	{
		return 0;
	}

	char szBuff[256];
	for(int i = 0; i < nRobotNum; i++)
	{
		CClientObject* pClientSpaceObject = new CClientObject();

		sprintf(szBuff, "test%d", i);
		pClientSpaceObject->m_strAccountName = szBuff;
		pClientSpaceObject->m_strPassword = "123456";

		sprintf(szBuff, "zhang%d", i);
		pClientSpaceObject->m_strRoleName = szBuff;

		pClientSpaceObject->m_dwCarrerID = rand() % 4 + 1;

		g_vtClientList.push_back(pClientSpaceObject);
	}


	// For fewer than ten bots, no separate threads are required

	while (true)
	{
		for (std::vector<CClientObject*>::iterator itor = g_vtClientList.begin(); itor != g_vtClientList.end(); itor++)
		{
			CClientObject* pClient = *itor;

			pClient->OnUpdate(0);
		}

		CommonFunc::Sleep(RUN_TIME);
	}

	return 0;
}

