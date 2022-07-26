#pragma once


// 싱글톤 패턴
// 객체의 생성을 1개로 제한
// 언제 어디서든 쉽게 접근 가능해야한다.
/* 방법 1
class CCore
{
public :
	// 정적 멤버 함수
	static CCore* GetInstance()
	{

		// 최초 호출 된 경우
		if (nullptr == g_pInst)
		{
			g_pInst = new CCore;
		}
		

		return g_pInst;
	}

	static void Release()
	{
		if (nullptr != g_pInst)
		{
			delete g_pInst;
			g_pInst = nullptr;
		}

	}

private:
	CCore();
	~CCore();
	static CCore* g_pInst;
};

*/


//방법 2 해제를 신경쓰지 않아도 된다.
class CCore
{
	SINGLE(CCore);
public:
	void progress();
	int init(HWND _hWnd, POINT _ptResolution);
	HWND GetMainHwnd() { return m_hWnd; }
	POINT GetResolution() { return m_ptResolution; }
	HDC GetMainDC() { return m_hDC; }
	HBRUSH GetBrush(BRUSH_TYPE _eType) { return m_arrBrush[(UINT)_eType]; }
	HPEN GetPen(PEN_TYPE _eType) { return m_arrPen[(UINT)_eType]; }

private:
	void CreateBrushPen();

private:
	HWND	m_hWnd;			// 메인 윈도우 핸들
	POINT	m_ptResolution; // 메인 윈도우 해상도
	HDC		m_hDC;			// 메인 윈도우에 Draw 할 DC

	HBITMAP m_hBit;
	HDC		m_memDC;

	// 자주 사용하는 GDI Object
	HBRUSH		m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN		m_arrPen[(UINT)PEN_TYPE::END];
};