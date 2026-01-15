/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___CenterServer___Main.cpp */
﻿// CenterServer.cpp : definition[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]。
//

#include "stdafx.h"
#include "GameService.h"
#include "CrashReport.h"
#include "CommandLine.h"
#include "WatcherClient.h"

int main(int argc, char* argv[])
{
    SetCrashReport("CenterServer");

    CCommandLine cmdLine(argc, argv);

    if (!CGameService::GetInstancePtr()->Init())
    {
        return 0;
    }

    CGameService::GetInstancePtr()->Run();

    CGameService::GetInstancePtr()->Uninit();

    UnSetCrashReport();

    return 0;
}

