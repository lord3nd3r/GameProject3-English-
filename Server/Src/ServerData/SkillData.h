/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerData___SkillData.h */
#ifndef __SKILL_DATA_OBJECT_H__
#define __SKILL_DATA_OBJECT_H__
#include "DBInterface/DBInterface.h"
#include "DBInterface/DBStoredProc.h"
struct SkillDataObject : public ShareObject
{
	SkillDataObject()
	{
		m_uRoleID = 0;	//[TRANSLATED][TRANSLATED]ID
		m_dwSkillID = 0;	//Skill ID
		m_nLevel = 0;
		m_nKeyPos = 0; //
	}

	UINT64 m_uRoleID;		//[TRANSLATED][TRANSLATED]ID
	UINT32 m_dwSkillID;		//Skill ID
	UINT32 m_nLevel;		//skillLevel
	UINT32 m_nKeyPos;		//[TRANSLATED][TRANSLATED]position

	BOOL Create(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("REPLACE INTO skill (id, roleid, level, key_pos) VALUES(?,?,?,?);");
		csp.set_uint32(0, m_dwSkillID);
		csp.set_uint64(1, m_uRoleID);
		csp.set_uint32(2, m_nLevel);
		csp.set_uint32(3, m_nKeyPos);
		return pDB->Execute(&csp);
	}

	BOOL Update(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("REPLACE INTO skill (id, roleid,level, key_pos) VALUES(?,?,?,?);");
		csp.set_uint32(0, m_dwSkillID);
		csp.set_uint64(1, m_uRoleID);
		csp.set_uint32(2, m_nLevel);
		csp.set_uint32(3, m_nKeyPos);
		return pDB->Execute(&csp);
	}

	BOOL Delete(IDBInterface* pDB)
	{
		return TRUE;
	}
};


#endif //__SKILL_DATA_OBJECT_H__