/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerData___RoleData.h */
#ifndef __ROLE_DATA_OBJECT_H__
#define __ROLE_DATA_OBJECT_H__
#include "DBInterface/DBStoredProc.h"
#include "DBInterface/DBInterface.h"
struct RoleDataObject : public ShareObject
{
	RoleDataObject()
	{
		m_uRoleID		= 0;            //[TRANSLATED][TRANSLATED]ID
		m_uAccountID	= 0;            //[TRANSLATED][TRANSLATED]ID
		m_Level			= 0;            //Level
		m_Exp			= 0;            //[TRANSLATED][TRANSLATED]
		m_nLangID		= 0;            //[TRANSLATED][TRANSLATED]ID
		m_u64Fight		= 0;            //[TRANSLATED][TRANSLATED]
		m_nVipLvl		= 0;            //VIPLevel
		m_nVipExp		= 0;            //VIP[TRANSLATED][TRANSLATED]
		m_CityCopyID	= 0;            //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]type
		m_bDelete       = FALSE;        //whether[TRANSLATED][TRANSLATED]
		m_CarrerID      = 0;            //[TRANSLATED][TRANSLATED]
		m_uCreateTime	= 0;            //[TRANSLATED][TRANSLATED]create time
		m_uLogonTime	= 0;            //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
		m_uLogoffTime	= 0;            //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
		m_nChannel      = 0;            //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
		memset(m_szName, 0, ROLE_NAME_LEN);
	}

	UINT64		m_uRoleID;              //[TRANSLATED][TRANSLATED]ID
	UINT64		m_uAccountID;           //[TRANSLATED][TRANSLATED]ID
	CHAR		m_szName[ROLE_NAME_LEN];//[TRANSLATED][TRANSLATED][TRANSLATED]
	INT32		m_CarrerID;             //[TRANSLATED][TRANSLATED]ID
	INT32		m_Level;                //Level
	INT64		m_Action[ACTION_NUM];   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	INT64		m_Actime[ACTION_NUM];   //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	INT64		m_Exp;                  //[TRANSLATED][TRANSLATED]
	INT32		m_nLangID;              //[TRANSLATED][TRANSLATED]ID
	INT64		m_u64Fight;             //[TRANSLATED][TRANSLATED]
	INT32		m_nVipLvl;               //VIPLevel
	INT32		m_nVipExp;               //VIP[TRANSLATED][TRANSLATED]
	INT32		m_CityCopyID;           //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]type
	INT32		m_nChannel;             //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	BOOL		m_bDelete;              //whether[TRANSLATED][TRANSLATED]
	INT64       m_uQQ;                  //QQ[TRANSLATED]
	UINT64      m_uCreateTime;          //[TRANSLATED][TRANSLATED]create time
	UINT64      m_uLogonTime;           //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	UINT64      m_uLogoffTime;          //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	UINT64      m_uGroupMailTime;       //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	UINT64      m_uGuildID;             //guildID
	UINT32      m_nOnlineTime;          //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	INT32		m_nSignNum;             //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	UINT32		m_nSignDay;             //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	UINT32		m_RecvAction;           //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]


	BOOL Create(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("REPLACE INTO player (id, accountid, name, carrerid,level, citycopyid,exp, langid, viplevel, vipexp, action1, action2, action3,action4, actime1, actime2, actime3,actime4, createtime, logontime, logofftime, grouptime, fightvalue, guildid) \
			VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);");
		csp.set_uint64(0, m_uRoleID);
		csp.set_uint64(1, m_uAccountID);
		csp.set_string(2, m_szName, strlen(m_szName));
		csp.set_int32(3,  m_CarrerID);
		csp.set_int32(4,  m_Level);
		csp.set_int64(5,  m_CityCopyID);
		csp.set_int64(6,  m_Exp);
		csp.set_int32(7,  m_nLangID);
		csp.set_int32(8,  m_nVipLvl);
		csp.set_int32(9,  m_nVipExp);
		csp.set_int64(10,  m_Action[0]);
		csp.set_int64(11,  m_Action[1]);
		csp.set_int64(12, m_Action[2]);
		csp.set_int64(13, m_Action[3]);
		csp.set_int64(14, m_Actime[0]);
		csp.set_int64(15, m_Actime[1]);
		csp.set_int64(16, m_Actime[2]);
		csp.set_int64(17, m_Actime[3]);
		csp.set_int64(18, m_uCreateTime);
		csp.set_int64(19, m_uLogonTime);
		csp.set_int64(20, m_uLogoffTime);
		csp.set_int64(21, m_uGroupMailTime);
		csp.set_int64(22, m_u64Fight);
		csp.set_int64(23, m_uGuildID);
		return pDB->Execute(&csp);
	}

	BOOL Update(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("REPLACE INTO player (id, accountid, name, carrerid,level, citycopyid,exp, langid, viplevel, vipexp, action1, action2, action3,action4, actime1, actime2, actime3,actime4, createtime, logontime, logofftime, grouptime, fightvalue, guildid) \
		VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);");
		csp.set_uint64(0, m_uRoleID);
		csp.set_uint64(1, m_uAccountID);
		csp.set_string(2, m_szName, strlen(m_szName));
		csp.set_int32(3, m_CarrerID);
		csp.set_int32(4, m_Level);
		csp.set_int64(5, m_CityCopyID);
		csp.set_int64(6, m_Exp);
		csp.set_int32(7, m_nLangID);
		csp.set_int32(8, m_nVipLvl);
		csp.set_int32(9, m_nVipExp);
		csp.set_int64(10, m_Action[0]);
		csp.set_int64(11, m_Action[1]);
		csp.set_int64(12, m_Action[2]);
		csp.set_int64(13, m_Action[3]);
		csp.set_int64(14, m_Actime[0]);
		csp.set_int64(15, m_Actime[1]);
		csp.set_int64(16, m_Actime[2]);
		csp.set_int64(17, m_Actime[3]);
		csp.set_int64(18, m_uCreateTime);
		csp.set_int64(19, m_uLogonTime);
		csp.set_int64(20, m_uLogoffTime);
		csp.set_int64(21, m_uGroupMailTime);
		csp.set_int64(22, m_u64Fight);
		csp.set_int64(23, m_uGuildID);
		return pDB->Execute(&csp);
	}

	BOOL Delete(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("update player set isdelete = 1 where id = ?");
		csp.set_uint64(0, m_uRoleID);
		return pDB->Execute(&csp);
	}
};


#endif //__SERVER_STRUCT_H__