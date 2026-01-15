#ifndef _GAME_MONSTER_CREATOR_H_
#define _GAME_MONSTER_CREATOR_H_

class CScene;
class CSceneObject;
class MonsterData
{
public:
	MonsterData()
	{
		m_dwActorID     = 0;	//Monster type ID
		m_dwType        = 0;	//Monster category
		m_dwCamp        = 0;	//Camp
		m_dwDropID      = 0;	//Drop ID
		m_bCheckCamp    = 0;    //Whether affects settlement
		m_bCheckDie     = 0;    //Whether affects monster spawning
		m_x             = 0;
		m_y             = 0;
		m_z             = 0;
		m_ft            = 0;	//Monster spawn position

		m_uObjectGuid   = 0;
		m_bDead         = FALSE;
	}

	~MonsterData()
	{
	}


	UINT32 m_dwActorID;         //Monster type ID
	UINT32 m_dwType;            //Monster category
	UINT32 m_dwCamp;            //Camp
	UINT32 m_dwDropID;          //Drop ID
	BOOL   m_bCheckCamp;        //Whether affects settlement
	BOOL   m_bCheckDie;         //Whether affects monster spawning
	FLOAT  m_x, m_y, m_z, m_ft; //Monster spawn position

	UINT64 m_uObjectGuid;       //刷出怪的实例ID
	BOOL   m_bDead;             //刷出怪是否死亡

};

class MonsterWave
{
public:
	MonsterWave()
	{
		m_bTriggerDone = FALSE;
	}

	~MonsterWave()
	{
		m_bTriggerDone = FALSE;
	}

public:
	std::vector<MonsterData>  m_vtMonsterList;
	UINT32 m_dwTriggerType;
	Rect2D m_TriggerBox;
	BOOL   m_bTriggerDone;
};

class MonsterCreator
{
public:
	MonsterCreator(CScene* pScene);
	~MonsterCreator();

	BOOL		ReadFromXml(rapidxml::xml_node<char>* pNode);

	BOOL		OnUpdate(UINT64 uTick);

	BOOL		GenMonsterWave(INT32 dwWaveIndex);

	BOOL		IsAllFinished();

	BOOL		OnObjectDie(CSceneObject* pObject);

	BOOL        OnPlayerMove(FLOAT x, FLOAT z);

	CScene*		m_pScene;

	std::vector<MonsterWave> m_MonsterVaveList;
};

#endif