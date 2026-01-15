/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerData___BagData.h */
#ifndef __BAG_DATA_OBJECT_H__
#define __BAG_DATA_OBJECT_H__
#include "DBInterface/DBInterface.h"
struct BagDataObject : public ShareObject
{
	BagDataObject()
	{
		m_uGuid = 0;
		m_uRoleID = 0;
		m_ItemGuid = 0;
		m_ItemID = 0;
		m_nCount = 0;
		m_bBind = 0;
		m_nStatus = 0;
	}

	UINT64	m_uGuid;		//[TRANSLATED][TRANSLATED][TRANSLATED]guid
	UINT64	m_uRoleID;		//[TRANSLATED][TRANSLATED]ID
	UINT64	m_ItemGuid;		//[TRANSLATED][TRANSLATED]guid
	UINT32	m_ItemID;		//[TRANSLATED][TRANSLATED]ID
	INT64	m_nCount;		//[TRANSLATED][TRANSLATED]
	BOOL	m_bBind;		//whether[TRANSLATED][TRANSLATED][TRANSLATED]
	UINT32	m_nStatus;		//whether[TRANSLATED][TRANSLATED]

	BOOL Create(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("INSERT INTO bag (guid, roleid, itemguid, itemid, count, status) \
			VALUES(?,?,?,?,?,?);");
		csp.set_uint64(0, m_uGuid);
		csp.set_uint64(1, m_uRoleID);
		csp.set_uint64(2, m_ItemGuid);
		csp.set_int32(3,  m_ItemID);
		csp.set_int64(4,  m_nCount);
		csp.set_int32(5,  m_nStatus);
		return pDB->Execute(&csp);
	}

	BOOL Update(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("REPLACE INTO bag (guid, roleid, itemguid, itemid, count, status) \
			VALUES(?,?,?,?,?,?);");
		csp.set_uint64(0, m_uGuid);
		csp.set_uint64(1, m_uRoleID);
		csp.set_uint64(2, m_ItemGuid);
		csp.set_int32(3, m_ItemID);
		csp.set_int64(4, m_nCount);
		csp.set_int32(5, m_nStatus);
		return pDB->Execute(&csp);
	}

	BOOL Delete(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("delete from bag where guid = ?");
		csp.set_uint64(0, m_uGuid);
		return pDB->Execute(&csp);
	}
};

#endif //__BAG_DATA_OBJECT_H__