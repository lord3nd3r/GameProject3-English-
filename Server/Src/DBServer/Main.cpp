/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___DBServer___Main.cpp */
// DBServer.cpp : definition[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]。
//

#include "stdafx.h"
#include "GameService.h"
#include "CrashReport.h"
#include "WatcherClient.h"

int main(int argc, char* argv[])
{
    SetCrashReport("DBServer");

    if (!CGameService::GetInstancePtr()->Init())
    {
        return 0;
    }

    CGameService::GetInstancePtr()->Run();

    CGameService::GetInstancePtr()->Uninit();

    UnSetCrashReport();

    return 0;
}

