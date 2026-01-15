/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___GameServer___GameObject___BulletObject.h */
﻿#ifndef __BULLET_OBJECT_H__
#define __BULLET_OBJECT_H__
#include "../Message/Msg_Move.pb.h"
#include "SkillStruct.h"

class CSceneObject;
class CSkillObject;

class CBulletObject
{
public:
	CBulletObject(UINT64 uGuid, StBulletInfo* pBulletInfo, CSkillObject* pSkillObject, Vector3D startPos);

	~CBulletObject();

public:
	BOOL Reset();

	BOOL OnUpdate(UINT64 uTick);

	BOOL SaveNewData(BulletNewNtf& Ntf);

	BOOL SetCastObject(CSceneObject* pObject);

	BOOL SetTargetObject(CSceneObject* pObject);

	CSceneObject* GetCastObject();

	BOOL CheckTargetObjects();

	BOOL CheckLifeOver(UINT64 uTick);

	BOOL FinishBullet();

	BOOL IsFinished();

	BOOL SetAngle(FLOAT fAngle);

	BOOL SetTargetPos(Vector3D& Pos);

	BOOL UpdateBulletPos(UINT64 uTick);

public:
	UINT64          m_uGuid;            //bulletGUID
	UINT64          m_uStartTick;       //begin[TRANSLATED][TRANSLATED]
	UINT64          m_uLastTick;        //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	Vector3D        m_Pos;              //[TRANSLATED][TRANSLATED]position
	Vector3D        m_InitPos;          //[TRANSLATED][TRANSLATED]position
	BOOL            m_bFinished;        //whether[TRANSLATED][TRANSLATED]
	StBulletInfo*   m_pBulletInfo;      //bullet[TRANSLATED][TRANSLATED]
	CSkillObject*   m_pSkillObject;     //skill[TRANSLATED][TRANSLATED]
	CSceneObject*   m_pCastObject;      //[TRANSLATED][TRANSLATED][TRANSLATED]

	CSceneObject*   m_pTargetObject;    //target[TRANSLATED][TRANSLATED]
	FLOAT           m_fAngle;           //bullet[TRANSLATED][TRANSLATED]
	Vector3D        m_TargetPos;        //targetposition

	FLOAT           m_vx, m_vz;         //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	FLOAT           m_accx, m_accz;     //[TRANSLATED][TRANSLATED]Acceleration[TRANSLATED][TRANSLATED]

	std::vector<CSceneObject*> m_vtTargets;
};

#endif //__BULLET_OBJECT_H__
