/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerEngine___CommonTime.h */
﻿#ifndef __COMMON_TIME__
#define __COMMON_TIME__

namespace CommonFunc
{
BOOL            IsSameDay(UINT64 uTime);

BOOL            IsSameWeek(UINT64 uTime);

BOOL            IsSameMonth(UINT64 uTime, UINT64 sTime = 0);

INT32           DiffWeeks(UINT64 uTimeSrc, UINT64 uTimeDest);

INT32           DiffDays(UINT64 uTimeSrc, UINT64 uTimeDest);

UINT64          GetCurrTime(); //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

BOOL            SetCurrTimeAdd(INT64 nTimeAdd);

UINT64          GetCurMsTime(); //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

tm              GetCurrTmTime(UINT64 uTime = 0);

UINT64          GetDayBeginTime(UINT64 uTime = 0); //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

UINT64          GetWeekBeginTime(UINT64 uTime = 0); //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

UINT64          GetMonthBeginTime(UINT64 uTime = 0);//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

UINT64          GetMonthRemainTime(UINT64 uTime = 0);   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

INT32           GetWeekDay();       //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

INT32           GetMonthDay();

INT32           GetMonth(UINT64 uTime = 0);

INT32           GetTimeZone();

time_t          YearTimeToSec(INT32 nYear, INT32 nMonth, INT32 nDay, INT32 nHour, INT32 nMin, INT32 nSec);

std::string     TimeToString(time_t tTime);

time_t          DateStringToTime(std::string strDate);

UINT64          GetTickCount();
}


#endif /* __COMMON_TIME__*/
