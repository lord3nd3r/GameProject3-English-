/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___GameServer___GameObject___BuffObject.h */
#ifndef __BUFF_OBJECT_H__
#define __BUFF_OBJECT_H__

class CSceneObject;
struct StBuffInfo;

class CBuffObject
{
public:
	CBuffObject(CSceneObject* pObject, UINT32 dwBuffID);

	~CBuffObject();

public:
	BOOL OnAddBuff();
	BOOL OnRemoveBuff();
	BOOL OnEffect(BOOL bFirst = FALSE);
	BOOL OnUpdate(UINT64 uTick);
	BOOL IsOver();
	VOID SetOver();

public:
	UINT32  m_dwBuffID;    //buffID
	UINT32  m_dwStartTime; //begin[TRANSLATED][TRANSLATED]
	UINT32  m_dwLastTime;  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	BOOL	m_bOver;
	INT32   m_PtyChange[PROPERTY_NUM];
	CSceneObject* m_pSceneObject;
	StBuffInfo*   m_pBuffInfo;

};

#endif //__BUFF_OBJECT_H__
