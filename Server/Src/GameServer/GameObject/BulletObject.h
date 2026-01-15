#ifndef __BULLET_OBJECT_H__
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
	UINT64          m_uStartTick;       //begin时间
	UINT64          m_uLastTick;        //上次更新时间
	Vector3D        m_Pos;              //当前position
	Vector3D        m_InitPos;          //初始position
	BOOL            m_bFinished;        //whether完成
	StBulletInfo*   m_pBulletInfo;      //bullet信息
	CSkillObject*   m_pSkillObject;     //skill对象
	CSceneObject*   m_pCastObject;      //源对象

	CSceneObject*   m_pTargetObject;    //target对象
	FLOAT           m_fAngle;           //bullet方向
	Vector3D        m_TargetPos;        //targetposition

	FLOAT           m_vx, m_vz;         //当前速度向量
	FLOAT           m_accx, m_accz;     //当前Acceleration向量

	std::vector<CSceneObject*> m_vtTargets;
};

#endif //__BULLET_OBJECT_H__
