/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerData___PartnerData.h */
#ifndef __PARTNER_DATA_OBJECT_H__
#define __PARTNER_DATA_OBJECT_H__
#include "DBInterface/DBInterface.h"
struct PartnerDataObject : public ShareObject
{
	PartnerDataObject ()
	{
		m_uRoleID = 0;			//[TRANSLATED][TRANSLATED]ID
		m_uGuid = 0;			//guid
		m_PartnerID = 0;		//[TRANSLATED][TRANSLATED]ID
		m_StrengthLvl = 0;		//[TRANSLATED][TRANSLATED]Level
		m_RefineLevel = 0;		//[TRANSLATED][TRANSLATED]Level
		m_StarLevel = 0;		//[TRANSLATED][TRANSLATED]
		m_RefineExp = 0;		//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
		m_StarExp = 0;			//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
		m_SetPos = 0;			//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]position
	}

	UINT64 m_uRoleID;			//[TRANSLATED][TRANSLATED]ID
	UINT64 m_uGuid;			//guid
	UINT32 m_PartnerID;		//[TRANSLATED][TRANSLATED]ID
	INT32  m_StrengthLvl;   //[TRANSLATED][TRANSLATED]Level
	INT32  m_RefineLevel;   //[TRANSLATED][TRANSLATED]Level
	INT32  m_StarLevel;		//[TRANSLATED][TRANSLATED]
	INT32  m_RefineExp;		//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	INT32  m_StarExp;		//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	BOOL   m_SetPos;       //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

	BOOL Create(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("REPLACE INTO partner (guid, roleid, partnerid, setpos, strengthlvl, refinelvl, starlvl) \
			VALUES(?,?,?,?,?,?,?);");
		csp.set_uint64(0, m_uGuid);
		csp.set_uint64(1, m_uRoleID);
		csp.set_uint32(2, m_PartnerID);
		csp.set_int32(3, m_SetPos);
		csp.set_int32(4, m_StrengthLvl);
		csp.set_int32(5, m_RefineLevel);
		csp.set_int32(6, m_StarLevel);
		return pDB->Execute(&csp);
	}

	BOOL Update(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("REPLACE INTO partner (guid, roleid, partnerid, setpos, strengthlvl, refinelvl, starlvl) \
			VALUES(?,?,?,?,?,?,?);");
		csp.set_uint64(0, m_uGuid);
		csp.set_uint64(1, m_uRoleID);
		csp.set_uint32(2, m_PartnerID);
		csp.set_int32(3, m_SetPos);
		csp.set_int32(4, m_StrengthLvl);
		csp.set_int32(5, m_RefineLevel);
		csp.set_int32(6, m_StarLevel);
		return pDB->Execute(&csp);
	}

	BOOL Delete(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("delete from partner where guid = ?");
		csp.set_uint64(0, m_uGuid);
		return pDB->Execute(&csp);
	}
};


#endif //__PET_DATA_OBJECT_H__