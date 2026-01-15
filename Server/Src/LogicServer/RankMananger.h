/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___LogicServer___RankMananger.h */
﻿#ifndef __RANK_MANAGER_H__
#define __RANK_MANAGER_H__

#include "DBInterface/CppMysql.h"
#include "Rank.h"

class CRankManager
{
public:
	static CRankManager* GetInstancePtr();

private:
	CRankManager();
	~CRankManager();

public:
	BOOL    LoadData(CppMySQL3DB& tDBConnection);

	TRanker<UINT64, INT32> m_LevelRanker; //Level[TRANSLATED][TRANSLATED][TRANSLATED]

	TRanker<UINT64, INT32> m_FightRanker;  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
};
#endif