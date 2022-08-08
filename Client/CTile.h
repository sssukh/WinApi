#pragma once
#include "CObject.h"

class CTexture;

class CTile :
    public CObject
{
private:
    CTexture*   m_pTileTex;
    int         m_iIdx;         // 음수일 경우 아무것도 참조하지 않겠다.

public:
    void SetTexture(CTexture* _pTex)
    {
        m_pTileTex = _pTex;
    }
private:
    virtual void update();
    virtual void render(HDC _dc);

    CLONE(CTile);
public:
    CTile();
    ~CTile();


};


