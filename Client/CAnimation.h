#pragma once

class CAnimator;
class CTexture;

struct tAnimFrm
{
	Vec2	vLT;
	Vec2	vSlice;
	Vec2	vOffset;
	float	fDuration;
};

class CAnimation
{
private:
	wstring				m_strName;		
	CAnimator*			m_pAnimator;
	CTexture*			m_pTex;			// Animation이 사용하는 텍스쳐
	vector<tAnimFrm>	m_vecFrm;		// 모든 프레임 정보
	int					m_iCurFrm;		// 현재 프레임
	float				m_fAccTime;		// 시간 누적

	bool				m_bFinish;		// 재생 끝에 도달여부
public:
	CAnimation();
	~CAnimation();

	void update();
	void render(HDC _dc);

	void Create(CTexture* _pTex, Vec2 _vLT, Vec2 _vSliceSize, 
		Vec2 _vStep, float _fDuration, UINT _iFrameCount);
	

	const wstring& GetName() { return m_strName; }
	bool IsFinish() { return m_bFinish; }
	void SetFrame(int _iFrameIdx)
	{
		m_bFinish = false;
		m_iCurFrm = _iFrameIdx;
		m_fAccTime = 0.f;
	}

	// 받아간 쪽에서 수정할 수 있게 레퍼런스를 리턴
	tAnimFrm& GetFrame(int _iIdx) { return m_vecFrm[_iIdx]; }
	int GetMaxFrame() { return m_vecFrm.size(); }

private:
	// 한번 정한 이름은 변하면안된다.
	void SetName(const wstring& _strName) { m_strName = _strName; }

	friend class CAnimator;
};

