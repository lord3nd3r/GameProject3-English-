/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerEngine___CrashReport.h */
#ifndef _CRASH_REPORT_H_
#define _CRASH_REPORT_H_

void NewInvalidParamHandler(const wchar_t* expression,
                            const wchar_t* function,
                            const wchar_t* file,
                            unsigned int line,
                            uintptr_t pReserved);

void NewPureCallHandler(void);

/*[TRANSLATED][TRANSLATED]crash[TRANSLATED][TRANSLATED]*/
void SetCrashReport(std::string strAppName);

void UnSetCrashReport();

#endif