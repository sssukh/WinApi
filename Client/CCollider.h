#pragma once

class CObject;

class CCollider
{
private:
	static UINT g_iNextID;

	CObject*		m_pOwner;		// collider를 소유하고 있는 오브젝트
	Vec2			m_vOffsetPos;	// 오브젝트로 부터 상재거인 위치
	Vec2			m_vFinalPos;	// finalupdate에서 매 프레임마다 계산
	Vec2			m_vScale;		// 충돌체의 크기

	UINT			m_iID;
	UINT			m_iCol;

public:
	CCollider();
	CCollider(const CCollider& _origin);
	~CCollider();

	void finalupdate();
	void render(HDC _dc);

	CCollider& operator = (CCollider& _origin) = delete;


	void SetOffsetPos(Vec2 _vPos) { m_vOffsetPos = _vPos; }	
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	Vec2 GetOffsetPos() { return m_vOffsetPos; }
	Vec2 GetScale() { return m_vScale; }

	Vec2 GetFinalPos() { return m_vFinalPos; }

	CObject* GetObj() { return m_pOwner; }

	UINT GetID() { return m_iID; }


	// 충돌 시점 함수
	void OnCollision(CCollider* _pOther); // 충돌 중인 경우 호출되는 함수
	void OnCollisionEnter(CCollider* _pOther); // 충돌 진입 시
	void OnCollisionExit(CCollider* _pOther);	// 충돌 해제 시



	friend class CObject;
};

