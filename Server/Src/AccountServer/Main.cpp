/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___AccountServer___Main.cpp */
// AccountServer.cpp : definition[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]。
//

#include "stdafx.h"
#include "GameService.h"
#include "CrashReport.h"
#include "WatcherClient.h"

int main(int argc, char* argv[])
{
    SetCrashReport("AccountServer");

    if (CGameService::GetInstancePtr()->Init())
    {
        CGameService::GetInstancePtr()->Run();
    }

    CGameService::GetInstancePtr()->Uninit();

    UnSetCrashReport();

    return 0;
}

