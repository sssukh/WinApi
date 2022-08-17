#include "CPanelUI.h"

#include "CKeyMgr.h"


CPanelUI::CPanelUI()
	:CUI(false)
{
}

CPanelUI::~CPanelUI()
{
}

void CPanelUI::update()
{
}

void CPanelUI::render(HDC _dc)
{
	CUI::render(_dc);
}

void CPanelUI::MouseOn()
{
	// 마우스 왼쪽 버튼이 눌린 상태에서 마우스 커서가 위에 있다면
	if (IsLbtnDown())
	{
		Vec2 vDiff = MOUSE_POS - m_vDragStart;

		Vec2 vCurPos = GetPos();
		vCurPos += vDiff;
		SetPos(vCurPos);
		
		m_vDragStart = MOUSE_POS;		// 드래그 시작 지점 초기화
	}
}

void CPanelUI::MouseLbtnDown()
{
	m_vDragStart = MOUSE_POS;		// 드래그 시작 지점 설정
}

void CPanelUI::MouseLbtnUp()
{
}
