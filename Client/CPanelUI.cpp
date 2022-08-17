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
	// ���콺 ���� ��ư�� ���� ���¿��� ���콺 Ŀ���� ���� �ִٸ�
	if (IsLbtnDown())
	{
		Vec2 vDiff = MOUSE_POS - m_vDragStart;

		Vec2 vCurPos = GetPos();
		vCurPos += vDiff;
		SetPos(vCurPos);
		
		m_vDragStart = MOUSE_POS;		// �巡�� ���� ���� �ʱ�ȭ
	}
}

void CPanelUI::MouseLbtnDown()
{
	m_vDragStart = MOUSE_POS;		// �巡�� ���� ���� ����
}

void CPanelUI::MouseLbtnUp()
{
}
