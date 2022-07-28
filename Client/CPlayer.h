#pragma once
#include "CObject.h"

class CTexture;

class CPlayer :
    public CObject
{
private:
    

public:
    CPlayer();
    
    ~CPlayer();
    virtual void update();
    virtual void render(HDC _dc);
private:
    void CreateMissile();

    CLONE(CPlayer);
};

