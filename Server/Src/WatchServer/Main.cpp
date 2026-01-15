/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___WatchServer___Main.cpp */
﻿// WatchServer.cpp : definition[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]。
//

#include "stdafx.h"
#include "GameService.h"
#include "CrashReport.h"

int main(int argc, char* argv[])
{
    SetCrashReport("WatchServer");

    if (CGameService::GetInstancePtr()->Init())
    {
        CGameService::GetInstancePtr()->Run();
    }

    CGameService::GetInstancePtr()->Uninit();

    UnSetCrashReport();

    return 0;
}

