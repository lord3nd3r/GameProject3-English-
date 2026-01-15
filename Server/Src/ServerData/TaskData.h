/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerData___TaskData.h */
﻿#ifndef __TASK_DATA_OBJECT_H__
#define __TASK_DATA_OBJECT_H__
#include "DBInterface/DBInterface.h"
#include "DBInterface/DBStoredProc.h"
struct TaskDataObject : public ShareObject
{
    TaskDataObject ()
    {
        m_uRoleID = 0;  //[TRANSLATED][TRANSLATED]ID
        m_nTaskID = 0;  //[TRANSLATED][TRANSLATED]ID
        m_nTaskStatus = 0;
        m_nProgress = 0; //
    }

    UINT64 m_uRoleID;       //[TRANSLATED][TRANSLATED]ID
    INT32  m_nTaskID;       //[TRANSLATED][TRANSLATED]ID
    INT32  m_nTaskStatus;   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
    INT32  m_nProgress; //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

    BOOL Create(IDBInterface* pDB)
    {
        static CDBStoredProcedure csp("REPLACE INTO task (id, roleid, task_status, progress) VALUES(?,?,?,?);");
        csp.set_int32(0, m_nTaskID);
        csp.set_uint64(1, m_uRoleID);
        csp.set_int32(2, m_nTaskStatus);
        csp.set_int32(3, m_nProgress);
        return pDB->Execute(&csp);
    }

    BOOL Update(IDBInterface* pDB)
    {
        static CDBStoredProcedure csp("REPLACE INTO task (id, roleid, task_status, progress) VALUES(?,?,?,?);");
        csp.set_int32(0, m_nTaskID);
        csp.set_uint64(1, m_uRoleID);
        csp.set_int32(2, m_nTaskStatus);
        csp.set_int32(3, m_nProgress);
        return pDB->Execute(&csp);
    }

    BOOL Delete(IDBInterface* pDB)
    {
        return TRUE;
    }
};


#endif //__TASK_DATA_OBJECT_H__