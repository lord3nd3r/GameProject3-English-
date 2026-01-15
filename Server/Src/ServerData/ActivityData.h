/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerData___ActivityData.h */
#ifndef __ACTIVITY_DATA_OBJECT_H__
#define __ACTIVITY_DATA_OBJECT_H__
#include "DBInterface/DBInterface.h"

//[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
struct LoginAward
{

};

struct  FirstCharge
{

};

struct  OpenFund
{

};

struct  LevelGift
{
	UINT32 GiftID[20];
	UINT32 BuyTimes[20];
	UINT32 DeadLine[20];
};


struct  VipGift
{
	UINT32 GiftID[20];
	UINT32 BuyTimes[20];
	UINT32 DeadLine[20];
};

//[TRANSLATED][TRANSLATED]
struct  SumRecharge
{
	UINT32 m_SumMoney;  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	BOOL   m_AwardMark; //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
};

//[TRANSLATED][TRANSLATED]
struct  SinRecharge
{

};



struct ActivityDataObject : public ShareObject
{
	ActivityDataObject()
	{
		m_dwActivityID = 0;
		m_uRoleID = 0;
		m_dwActivityType = 0;
		m_uJoinTime = 0;
		m_dwDataLen = 0;
		memset(m_Data.m_Bytes, 0, sizeof(m_Data.m_Bytes));
	}

	UINT32 m_dwActivityID;  //[TRANSLATED][TRANSLATED]ID
	UINT64 m_uRoleID;		//[TRANSLATED][TRANSLATED]ID
	UINT32 m_dwActivityType;//[TRANSLATED][TRANSLATED]type
	UINT64 m_uJoinTime;     //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	UINT32 m_dwDataLen;     //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	union
	{
		BYTE			m_Bytes[1024];    //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
		FirstCharge		m_FirstCharge;
		OpenFund		m_OpenFund;
		LevelGift       m_LevelGift;
		VipGift			m_VipGift;
		SumRecharge		m_SumRecharge;
		SinRecharge	    m_SinRecharge;
	} m_Data;

	BOOL Create(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("REPLACE INTO activity (id, type, roleid, join_time, data_len, data) \
			VALUES(?,?,?,?,?,?);");
		csp.set_uint64(0, m_dwActivityID);
		csp.set_uint64(1, m_dwActivityType);
		csp.set_uint64(2, m_uRoleID);
		csp.set_uint64(3, m_uJoinTime);
		csp.set_int32(4, m_dwDataLen);
		csp.set_blob(5, m_Data.m_Bytes, m_dwDataLen);
		return pDB->Execute(&csp);
	}

	BOOL Update(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("REPLACE INTO activity (id, type, roleid, join_time, data_len, data) \
			VALUES(?,?,?,?,?,?);");
		csp.set_uint64(0, m_dwActivityID);
		csp.set_uint64(1, m_dwActivityType);
		csp.set_uint64(2, m_uRoleID);
		csp.set_uint64(3, m_uJoinTime);
		csp.set_int32(4, m_dwDataLen);
		csp.set_blob(5, m_Data.m_Bytes, m_dwDataLen);
		return pDB->Execute(&csp);
	}

	BOOL Delete(IDBInterface* pDB)
	{
		return TRUE;
	}
};

#endif //__ACTIVITY_DATA_OBJECT_H__