#ifndef __SERVER_STRUCT_H__
#define __SERVER_STRUCT_H__

struct BattleRecord
{
	UINT32			m_dwResult;		//0:未结算，1:胜利，2: Failure 3: 平局
	UINT32			m_dwKill;		//击杀数
	UINT32          m_dwDeath;		//被杀次数
	UINT32			m_dwHeal;		//治疗值
	UINT32          m_dwDamage;		//总伤害值
};

enum EChangeType
{
	ECT_EQUIP = 1,//装备改变
	ECT_MOUNT = 2,//坐骑改变
	ECT_LEVEL = 3,//Level
	ECT_PARTNER = 4,//伙伴
	ECT_PET = 5,//宠物
};

enum EWinCondition
{
	EWC_NONE,
	EWC_KILL_ALL,       //击杀全部怪物
	EWC_KILL_NUM,       //击杀指定count怪物
	EWC_DESTINATION,    //达到目的地
	EWC_PLAYER_ALIVE,   //存活下来
	EWC_NPC_ALIVE,      //护送npc
	EWC_END
};

enum EBattleCamp
{
	EBC_NONE,     //中立阵营
	EBC_PLAYER,   //player阵营
	EBC_MONSTER,  //怪物阵营
};

enum ETriggerType
{
	ETT_NORMAL,     //直接trigger
	ETT_TRIBOX,     //trigger盒trigger
	ETT_TIME,       //时间trigger
};


#endif //__SERVER_STRUCT_H__