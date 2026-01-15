/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerEngine___CrashReport.cpp */
#include "stdafx.h"

#ifdef WIN32
#pragma warning(disable: 4996)
#include <windows.h>

#include <Dbghelp.h>

#include "crashReport.h"
#include "time.h"

#pragma auto_inline (off)
#pragma comment( lib, "DbgHelp" )


void NewInvalidParamHandler(const wchar_t* expression, const wchar_t* function, const wchar_t* file, unsigned int line, uintptr_t pReserved)
{
    throw 1;
}

void NewPureCallHandler(void)
{
    throw 1;
}

LPTOP_LEVEL_EXCEPTION_FILTER g_preFilter;

std::string g_AppName;


_invalid_parameter_handler g_preInvalidParamHandler;

_purecall_handler g_prePureHandler;


long   __stdcall  CrashCallBack(_EXCEPTION_POINTERS* pExInfo)
{
    struct tm* pTime;
    time_t ctTime;
    time(&ctTime);
    pTime = localtime( &ctTime );
    TCHAR tem[256];
    memset(tem, 0, 256);
    snprintf(tem, 256, ("%s-%d-%d-%d_%d-%d-%d.dmp"), g_AppName.c_str(),
             1900 + pTime->tm_year, 1 + pTime->tm_mon, pTime->tm_mday, pTime->tm_hour, pTime->tm_min, pTime->tm_sec);

    HANDLE hFile = ::CreateFile( tem, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if( hFile != INVALID_HANDLE_VALUE)
    {
        MINIDUMP_EXCEPTION_INFORMATION einfo;
        einfo.ThreadId = ::GetCurrentThreadId();
        einfo.ExceptionPointers = pExInfo;
        einfo.ClientPointers = FALSE;
        ::MiniDumpWriteDump(::GetCurrentProcess(), ::GetCurrentProcessId(), hFile, MiniDumpNormal, &einfo, NULL, NULL);
        ::CloseHandle(hFile);
    }
    return EXCEPTION_EXECUTE_HANDLER;
}

void  SetCrashReport(std::string strAppName)
{
    g_AppName = strAppName;

    g_preFilter = SetUnhandledExceptionFilter(CrashCallBack);

    g_preInvalidParamHandler = _set_invalid_parameter_handler(NewInvalidParamHandler);

    g_prePureHandler = _set_purecall_handler(NewPureCallHandler);
}

void UnSetCrashReport()
{
    SetUnhandledExceptionFilter(g_preFilter);

    return;
}


#else
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <time.h>

std::string g_AppName;

void exceptionalStack(int signal)
{
    time_t nowtime;
    time(&nowtime);
    pid_t pid = getpid();
    char cmd[256];
    snprintf(cmd, 256, "gstack %d > core_%s_log_%d.core", pid, g_AppName.c_str(), nowtime);
    system(cmd);
    exit(-1);
}

void  SetCrashReport(std::string strAppName)
{
    return;
    g_AppName = strAppName;
    /*[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED] start*/
    signal(SIGABRT, &exceptionalStack); //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED](abort)
    signal(SIGBUS, &exceptionalStack); //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    signal(SIGFPE, &exceptionalStack); //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    signal(SIGILL, &exceptionalStack); //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    signal(SIGIOT, &exceptionalStack); //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    signal(SIGQUIT, &exceptionalStack); //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    signal(SIGSEGV, &exceptionalStack); //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    signal(SIGSYS, &exceptionalStack); //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    signal(SIGTRAP, &exceptionalStack); //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    signal(SIGXCPU, &exceptionalStack); //[TRANSLATED][TRANSLATED]CPU[TRANSLATED][TRANSLATED](setrlimit)
    signal(SIGXFSZ, &exceptionalStack); //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED](setrlimit)
    /*[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED] end*/

    setvbuf(stdout, NULL, _IONBF, 0);
    return ;
}

void UnSetCrashReport()
{
    return;
}

#endif