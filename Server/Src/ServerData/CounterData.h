/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerData___CounterData.h */
#ifndef __COUNTER_DATA_OBJECT_H__
#define __COUNTER_DATA_OBJECT_H__
#include "DBInterface/DBInterface.h"

struct CounterDataObject : public ShareObject
{
	CounterDataObject()
	{
		m_uRoleID = 0;      //[TRANSLATED][TRANSLATED]ID
		m_uCounterID = 0;   //[TRANSLATED][TRANSLATED][TRANSLATED]ID
		m_dwIndex = 0;      //[TRANSLATED][TRANSLATED][TRANSLATED]
		m_uValue = 0;       //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
		m_uTime = 0;        //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
		m_dwParam1 = 0;     //params1
		m_dwParam2 = 0;     //params2
	}

	UINT64 m_uRoleID;       //[TRANSLATED][TRANSLATED]ID
	UINT32 m_uCounterID;    //[TRANSLATED][TRANSLATED][TRANSLATED]ID
	UINT32 m_dwIndex;       //[TRANSLATED][TRANSLATED][TRANSLATED]
	INT64  m_uValue;        //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	UINT64 m_uTime;         //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	UINT32 m_dwParam1;      //params1
	UINT32 m_dwParam2;      //params2

	BOOL Create(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("REPLACE INTO counter (id, roleid, cindex, time, value) VALUES(?,?,?,?,?);");
		csp.set_uint32(0, m_uCounterID);
		csp.set_uint64(1, m_uRoleID);
		csp.set_uint32(2, m_dwIndex);
		csp.set_uint64(3, m_uTime);
		csp.set_int64(4, m_uValue);
		return pDB->Execute(&csp);
	}

	BOOL Update(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("REPLACE INTO counter (id, roleid, cindex, time, value) VALUES(?,?,?,?,?);");
		csp.set_uint32(0, m_uCounterID);
		csp.set_uint64(1, m_uRoleID);
		csp.set_uint32(2, m_dwIndex);
		csp.set_uint64(3, m_uTime);
		csp.set_int64(4, m_uValue);
		return pDB->Execute(&csp);
	}

	BOOL Delete(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("delete from counter where id = ? and roleid = ? and index = ?");
		csp.set_uint32(0, m_uCounterID);
		csp.set_uint64(1, m_uRoleID);
		csp.set_uint32(2, m_dwIndex);
		return pDB->Execute(&csp);
	}
};

#endif //__COUNTER_DATA_OBJECT_H__