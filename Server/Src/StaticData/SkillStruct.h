#ifndef __SKILL_STRUCT_H__
#define __SKILL_STRUCT_H__

#include "../Message/Game_Define.pb.h"

enum ECenterType
{
    ECT_TARGET_POS      = 1, // Centered on position selected by client
    ECT_TARTGT_OBJ      = 2, // Centered on object selected by client
    ECT_CASTER_POS      = 3, // Centered on caster
    ECT_CASTER_OFFSET   = 4, // Centered on caster with offset
};

enum ESkillCastType
{
    ESCT_TYPE_INSTANT       = 0,    // Instant (no targeting)
    ESCT_TYPE_TARGET        = 1,    // Target selection helper (object)
    ESCT_TYPE_DIRECTION     = 2,    // Direction decal helper (facing)
    ESCT_TYPE_POS           = 3,    // Ground decal helper (AOE area)
    ESCT_TYPE_DIRECTIONARC  = 4,    // Fan-shaped direction decal helper (facing)
    ESCT_TYPE_EFFECT        = 5,    // Model effect helper (summon)
    ESCT_TYPE_SIGHT         = 6,    // Crosshair UI change helper (shooting)
    ESCT_TYPE_PARABOLA      = 7,    // Parabola helper (throwing)
    ESCT_TYPE_DRAGLINE      = 8,    // Drag-line helper (wall-type summons)
    ESCT_TYPE_GESTURE       = 9,    // Mouse gesture helper (multi-segment points)
};

enum ERangeType
{
    ERT_OBJECTS     = 1, // Targets specified by client
    ERT_CYLINDER    = 2, // Sector cylinder
    ERT_CIRCLE      = 3, // Circular cylinder
    ERT_BOX         = 4, // Rectangular area
};

enum EBulletType
{
    EBT_CHASE           = 0, // Homing projectile
    EBT_FIXDIRECTION    = 1, // Fixed-direction projectile
    EBT_FIXTARGETPOS    = 2, // Fixed target position projectile
    EBT_POINT           = 3, // Fixed-point projectile
    EBT_LINK            = 4, // Linked projectile
    EBT_ANNULAR         = 5, // Annular projectile
    EBT_BACK            = 6, // Returning projectile
    EBT_EXTRACT         = 7, // Extracting projectile
    EBT_BOUNDCE         = 8, // Bouncing projectile
    EBT_WAVE            = 9, // Shockwave
};

enum ESkillStatus
{
    ESS_INIT        = 0,    // Initial state
    ESS_RUNNING     = 1,    // Running
    ESS_FINISHED    = 2,    // Finished
};

enum EAffectShip
{
    EAS_Self = 0, // Affects self
    EAS_Enem = 1, // Affects enemies
    EAS_Ally = 2, // Affects allies
    EAS_Each = 3, // Affects all
};

enum ESelectPolicy
{
    ESP_DEFAULT         = 0, // Default
    ESP_BY_MOREHEALTH   = 1, // Highest health percentage
    ESP_BY_LESSHEALTH   = 2, // Lowest health percentage
    ESP_BY_MOREDISTANCE = 3, // Furthest distance
    ESP_BY_LESSDISTANCE = 4, // Nearest distance
};

enum ESkillType
{
    EST_NONE = 0,
    ESTPHYSICS = 1,
    ESTMAGIC = 2
};

// enum EObjectStatus
// {
//  EOS_NONE = 0;//无
//  EOS_DEAD = 1;//死亡
//  EOS_IDLE = 2;//静止
//  EOS_WALK = 3;//走
//  EOS_RUN = 4;//跑
//  EOS_FLY = 5;//飞
//  EOS_NOT_MOVE = 6;//不能移动
//  EOS_NOT_CAST = 7;//不能放技能
//  EOS_NOT_BEHURT = 8;//不能被攻击
//  EOS_NOT_BECONTROL = 9;//无法被控制
//  EOS_STEALTH = 10;//隐身
//  EOS_BLIND = 11;//瞎的
// };





struct StBuffInfo
{
    UINT32 BuffID;                      //BuffID
    UINT32 EffectID;                  //Buff目标需要加的特效
    INT32  PtyValue[PROPERTY_NUM];      //加属性值
    INT32  PtyPercent[PROPERTY_NUM];    //加属性百分比
    INT32  TotalTime;                   //总时长(ms)
    INT32  Interval;                    //间隔时长
    UINT32 ChangeStatus;                //修改玩家的状态
    BOOL   OverLay;                     //是否可以叠加
    std::string   LuaAdd;               //是否有lua事件
    std::string   LuaTick;              //是否有lua事件
    std::string   LuaRemove;            //是否有lua事件
};

struct StBulletInfo
{
    UINT32      BulletID    = 0;                //Bullet ID
    EBulletType BulletType  = EBT_FIXDIRECTION; //Bullet Type
    FLOAT       InitSpeed   = 0;                //Initial Speed
    FLOAT       AccSpeed    = 0;                //Acceleration
    ERangeType  RangeType   = ERT_CIRCLE;       //Range Type
    FLOAT       RangeParams[5] = { 0 };         //Range Parameters
    UINT32      LifeTime    = 0;                //Life Time
    UINT32      HitActionID = 0;                 //Hit Action, 击退，击飞， 击倒
    UINT32      HitEffect = 0;                   //Hit Effect
    FLOAT       HitDistance = 0;                 //Hit Move Distance
};

struct StBulletObject
{
    UINT32 BulletID;    //Bullet ID
    FLOAT  fAngle;       //角度
};


struct StGoblinInfo
{
    UINT32 ActorID;     //角色ID
};


struct StSkillEvent
{
    UINT64 TrigerTime = 0;                  //Trigger Time
    UINT32 SelfBuffID = 0;                  //Self Buff ID
    UINT32 TargetBuffID = 0;                //Target Buff ID
    FLOAT  RangeParams[5] = {0};            //Range Parameters
    ERangeType RangeType = ERT_OBJECTS;     //Range Type
    UINT32 CenterType = 0;                  //中心点类型
    std::vector<StBulletObject> vtBullets;  //Bullet List
    std::vector<StGoblinInfo> vtGoblins;    //Summoned goblins list
    UINT32 HitActionID = 0;                 //Hit Action, 击退，击飞， 击倒
    UINT32 HitEffect = 0;                   //Hit Effect
    FLOAT  HitDistance = 0;                 //Hit Move Distance
};

struct StSkillInfo
{
    UINT32        SkillID;        //Skill ID
    UINT32        Level;          //技能Level
    UINT32        SkillType;      //Skill Type,1:物理伤害,2:法术伤害
    EHitShipType  HitShipType;    //Target relation,
    BOOL          HitMyself;      //HitMyself
    UINT32        CD;               //Skill CD
    UINT64        uDuration;      //Skill total duration
    INT32         HurtFix;        //Fixed damage
    INT32         HurtMuti;       //Bonus damage
};


struct StSkillEventInfo
{
    UINT32      nSkillID;                       //Skill ID
    UINT64      uDuration;                      //Skill total duration
    UINT32      dwCastType;                     //Target selection policy
    std::vector<StSkillEvent> vtEvents;         //Skill event list
};

struct StComboSkillInfo
{
    UINT32 SkillID;                     //主Skill ID
    std::vector<UINT32> vtComboSkill;   //Combo skills
};


#endif //__CONFIG_STRUCT_H__