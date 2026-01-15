/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerData___GlobalData.h */
#ifndef __GLOBAL_DATA_OBJECT_H__
#define __GLOBAL_DATA_OBJECT_H__
#include "DBInterface/DBStoredProc.h"
#include "DBInterface/DBInterface.h"

#define MAX_EXTRA_INDEX 60

struct GlobalDataObject : public ShareObject
{
	GlobalDataObject()
	{
		m_dwServerID		= 0;			//serverID
		m_u64Guid			= 0;			//[TRANSLATED][TRANSLATED]GUID
		m_dwMaxOnline		= 0;			//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
		memset(m_exData, 0, sizeof(INT32) * MAX_EXTRA_INDEX);
	}

	UINT32 m_dwServerID;        //serverID
	UINT64 m_u64Guid;			//[TRANSLATED][TRANSLATED]GUID
	UINT32 m_dwMaxOnline;		//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	INT32 m_exData[MAX_EXTRA_INDEX];      //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

	BOOL Create(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("REPLACE INTO globaldata (serverid, maxguid, maxonline, extradata) VALUES(?, ?, ?, ?);");
		csp.set_uint32(0, m_dwServerID);
		csp.set_uint64(1, m_u64Guid);
		csp.set_uint32(2, m_dwMaxOnline);
		csp.set_tinyblob(3, m_exData, sizeof(INT32) * MAX_EXTRA_INDEX);
		return pDB->Execute(&csp);
	}

	BOOL Update(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("REPLACE INTO globaldata (serverid, maxguid, maxonline, extradata) VALUES(?, ?, ?, ?);");
		csp.set_uint32(0, m_dwServerID);
		csp.set_uint64(1, m_u64Guid);
		csp.set_uint32(2, m_dwMaxOnline);
		csp.set_tinyblob(3, m_exData, sizeof(INT32) * MAX_EXTRA_INDEX);
		return pDB->Execute(&csp);
	}

	BOOL Delete(IDBInterface* pDB)
	{
		return TRUE;
	}
};


#endif //__GLOBAL_DATA_OBJECT_H__