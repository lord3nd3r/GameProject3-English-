/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerData___FriendData.h */
#ifndef __FRIEND_DATA_OBJECT_H__
#define __FRIEND_DATA_OBJECT_H__
#include "DBInterface/DBInterface.h"

struct FriendDataObject : public ShareObject
{
	FriendDataObject()
	{

	}

	UINT64 m_uRoleID;		//[TRANSLATED][TRANSLATED]ID
	UINT64 m_uFriendID;     //[TRANSLATED][TRANSLATED]ID

	BOOL Create(IDBInterface* pDB)
	{
		return TRUE;
	}

	BOOL Update(IDBInterface* pDB)
	{
		return TRUE;
	}

	BOOL Delete(IDBInterface* pDB)
	{

		return TRUE;
	}
};

#endif //__FRIEND_DATA_OBJECT_H__