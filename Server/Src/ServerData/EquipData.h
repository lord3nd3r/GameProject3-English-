/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerData___EquipData.h */
﻿#ifndef __EQUIP_DATA_OBJECT_H__
#define __EQUIP_DATA_OBJECT_H__

#include "DBInterface/DBStoredProc.h"
#include "DBInterface/DBInterface.h"
struct EquipDataObject : public ShareObject
{
	EquipDataObject()
	{
		m_uRoleID = 0;
		m_uGuid = 0;
		m_EquipID = 0;
		m_StrengthLvl = 0;
		m_RefineLevel = 0;
		m_StarLevel = 0;
		m_RefineExp = 0;
		m_StarExp = 0;
		m_IsUsing = 0;
	}

	UINT64 m_uRoleID;		//[TRANSLATED][TRANSLATED]ID
	UINT64 m_uGuid;			//guid
	UINT32 m_EquipID;		//[TRANSLATED][TRANSLATED]ID
	INT32  m_StrengthLvl;   //[TRANSLATED][TRANSLATED]Level
	INT32  m_RefineLevel;   //[TRANSLATED][TRANSLATED]Level
	INT32  m_StarLevel;		//[TRANSLATED][TRANSLATED]
	INT32  m_RefineExp;		//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	INT32  m_StarExp;		//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	BOOL   m_IsUsing;       //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]

	BOOL Create(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("REPLACE INTO equip (guid, roleid, equipid, isuse, strengthlvl, refinelvl, starlvl) \
			VALUES(?,?,?,?,?,?,?);");
		csp.set_uint64(0, m_uGuid);
		csp.set_uint64(1, m_uRoleID);
		csp.set_uint32(2, m_EquipID);
		csp.set_bool(3, m_IsUsing);
		csp.set_int32(4, m_StrengthLvl);
		csp.set_int32(5, m_RefineLevel);
		csp.set_int32(6, m_StarLevel);
		return pDB->Execute(&csp);
	}

	BOOL Update(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("REPLACE INTO equip (guid, roleid, equipid, isuse, strengthlvl, refinelvl, starlvl) \
			VALUES(?,?,?,?,?,?,?);");
		csp.set_uint64(0, m_uGuid);
		csp.set_uint64(1, m_uRoleID);
		csp.set_uint32(2, m_EquipID);
		csp.set_bool(3, m_IsUsing);
		csp.set_int32(4, m_StrengthLvl);
		csp.set_int32(5, m_RefineLevel);
		csp.set_int32(6, m_StarLevel);
		return pDB->Execute(&csp);
	}

	BOOL Delete(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("delete from equip where guid = ?");
		csp.set_uint64(0, m_uGuid);
		return pDB->Execute(&csp);
	}
};



#endif //__EQUIP_DATA_OBJECT_H__