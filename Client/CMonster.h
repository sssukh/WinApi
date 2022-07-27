#pragma once
#include "CObject.h"

class CMonster :
    public CObject
{
private:
    Vec2            m_vCenterPos;
    float           m_fSpeed;
    float           m_fMaxDistance;
    int             m_iDir; // 1, -1 

    int             m_iHP;

public:
    CMonster();
    ~CMonster();


    virtual void update();
    float GetSpeed() { return m_fSpeed; }
    void SetSpeed(float f) { m_fSpeed = f; }
    void SetMoveDistance(float _f) { m_fMaxDistance = _f; }
    void SetCenterPos(Vec2 _Pos) { m_vCenterPos = _Pos; }

    virtual void OnCollisionEnter(CCollider* _pOther);

    CLONE(CMonster);
};

