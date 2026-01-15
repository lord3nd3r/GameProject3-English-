/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerData___GemData.h */
#ifndef __GEM_DATA_OBJECT_H__
#define __GEM_DATA_OBJECT_H__

#include "DBInterface/DBStoredProc.h"
#include "DBInterface/DBInterface.h"
struct GemDataObject : public ShareObject
{
	GemDataObject()
	{
		m_uRoleID = 0;
		m_uGuid = 0;
		m_GemID = 0;
		m_StrengthLvl = 0;
		m_RefineLevel = 0;
		m_StarLevel = 0;
		m_RefineExp = 0;
		m_StarExp = 0;
		m_EquipPos = 0;
	}

	UINT64 m_uRoleID;		//[TRANSLATED][TRANSLATED]ID
	UINT64 m_uGuid;			//guid
	UINT32 m_GemID;			//[TRANSLATED][TRANSLATED]ID
	INT32  m_StrengthLvl;   //[TRANSLATED][TRANSLATED]Level
	INT32  m_RefineLevel;   //[TRANSLATED][TRANSLATED]Level
	INT32  m_StarLevel;		//[TRANSLATED][TRANSLATED]
	INT32  m_RefineExp;		//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	INT32  m_StarExp;		//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	BOOL   m_EquipPos;            //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

	BOOL Create(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("REPLACE INTO gem (guid, roleid, gemid, pos, strengthlvl, refinelvl, starlvl) \
			VALUES(?,?,?,?,?,?,?);");
		csp.set_uint64(0, m_uGuid);
		csp.set_uint64(1, m_uRoleID);
		csp.set_uint32(2, m_GemID);
		csp.set_int32(3,  m_EquipPos);
		csp.set_int32(4,  m_StrengthLvl);
		csp.set_int32(5,  m_RefineLevel);
		csp.set_int32(6,  m_StarLevel);
		return pDB->Execute(&csp);
	}

	BOOL Update(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("REPLACE INTO gem (guid, roleid, gemid, pos, strengthlvl, refinelvl, starlvl) \
			VALUES(?,?,?,?,?,?,?);");
		csp.set_uint64(0, m_uGuid);
		csp.set_uint64(1, m_uRoleID);
		csp.set_uint32(2, m_GemID);
		csp.set_int32(3,  m_EquipPos);
		csp.set_int32(4, m_StrengthLvl);
		csp.set_int32(5, m_RefineLevel);
		csp.set_int32(6, m_StarLevel);
		return pDB->Execute(&csp);
	}

	BOOL Delete(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("delete from gem where guid = ?");
		csp.set_uint64(0, m_uGuid);
		return pDB->Execute(&csp);
	}
};



#endif //__GEM_DATA_OBJECT_H__