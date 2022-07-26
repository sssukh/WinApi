#pragma once
#include "CObject.h"


class CMissile :
    public CObject
{
private:
    float       m_fTheta; // 이동방향
    Vec2        m_vDir;

public:
    CMissile();
    ~CMissile();

    virtual void update();
    virtual void render(HDC _dc);

    virtual void OnCollisionEnter(CCollider* _pOther);


    void Setdir(float _fTheta) {  m_fTheta = _fTheta; }
    void SetDir(Vec2 _vDir) 
    {
        m_vDir = _vDir; 
        m_vDir.Normalize();
    }
};

