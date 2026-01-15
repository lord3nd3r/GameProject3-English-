/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___GameServer___GameObject___SkillObject.h */
#ifndef __SKILL_OBJECT_H__
#define __SKILL_OBJECT_H__

#include "SkillStruct.h"
#include "CommonMath.h"
#include "BulletObject.h"
class CSceneObject;

class CSkillObject
{
public:
	CSkillObject();

	~CSkillObject();

public:
	BOOL OnUpdate(UINT64 uTick);

	BOOL OnSkillComplete();

	BOOL StartSkill(UINT32 dwSkillID, INT32 nLevel);

	BOOL StopSkill();

	BOOL ResetSkill();

	BOOL SetCastObject(CSceneObject* pObject);

	CSceneObject* GetCastObject();

	BOOL AddTargetObject(CSceneObject* pObject);

	INT32 GetTargetNum();

	BOOL AttackTarget(CSceneObject* pTarget, UINT32 HitActionID, UINT32 HitEffectID, FLOAT HitDistance);

	BOOL CalcTargetObjects(StSkillEvent& SkillEvent);

	BOOL ProcessSkillEvent(StSkillEvent& SkillEvent);

	ESkillStatus GetSkillStatus();

	BOOL SetComboSkill(BOOL bCombo);

	UINT32 GetSkillID();

	VOID SetCalcTargets(BOOL bCalc);

	CBulletObject* CreateBullet(StBulletObject& stBullet);

public:
	UINT64              m_dwStartTick; //begin[TRANSLATED][TRANSLATED]
	UINT32              m_dwSkillID;   //Skill ID
	UINT32              m_dwEventIndex;
	StSkillInfo*        m_pSkillInfo;
	StSkillEventInfo*   m_pSkillEventInfo;
	CSceneObject*       m_pCastObject;
	BOOL                m_bComboSkill;  //[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
	ESkillStatus        m_SkillStatus;
	BOOL                m_bCalcTargets;
	std::vector<CSceneObject*> m_vtTargets;
};

#endif //__SKILL_OBJECT_H__
