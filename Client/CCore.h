#pragma once


// �̱��� ����
// ��ü�� ������ 1���� ����
// ���� ��𼭵� ���� ���� �����ؾ��Ѵ�.
/* ��� 1
class CCore
{
public :
	// ���� ��� �Լ�
	static CCore* GetInstance()
	{

		// ���� ȣ�� �� ���
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


//��� 2 ������ �Ű澲�� �ʾƵ� �ȴ�.
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
	HWND	m_hWnd;			// ���� ������ �ڵ�
	POINT	m_ptResolution; // ���� ������ �ػ�
	HDC		m_hDC;			// ���� �����쿡 Draw �� DC

	HBITMAP m_hBit;
	HDC		m_memDC;

	// ���� ����ϴ� GDI Object
	HBRUSH		m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN		m_arrPen[(UINT)PEN_TYPE::END];
};