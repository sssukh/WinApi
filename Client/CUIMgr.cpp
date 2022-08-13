#include "pch.h"
#include "CUIMgr.h"

#include "CSceneMgr.h"
#include "CScene.h"
#include "CUI.h"

#include "CKeyMgr.h"

CUIMgr::CUIMgr()
{

}

CUIMgr::~CUIMgr()
{

}

void CUIMgr::update()
{
	CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();
	const vector<CObject*>& vecUI = pCurScene->GetGroupObject(GROUP_TYPE::UI);

	bool bLbtnTap = KEY_TAP(KEY::LBTN);
	bool bLbtnAway = KEY_AWAY(KEY::LBTN);

	for (size_t i = 0; i < vecUI.size(); ++i)
	{
		CUI* pUI = (CUI*)vecUI[i];


		pUI = GetTargetedUI(pUI);

		if (nullptr != pUI)
		{
			pUI->MouseOn();

			if (bLbtnTap)
			{

				pUI->MouseLbtnDown();
				pUI->m_bLbtnDown = true;
			}
			else if (bLbtnAway)
			{
				pUI->MouseLbtnUp();

				if (pUI->m_bLbtnDown)
				{
					pUI->MouseLbtnClicked();
				}

				// ���� ��ư ����, ������ üũ�� �ٽ� �����Ѵ�.

				pUI->m_bLbtnDown = false;
			}
		}
	}
}

CUI* CUIMgr::GetTargetedUI(CUI* _pParentUI)
{
	bool bLbtnAway = KEY_AWAY(KEY::LBTN);

	CUI* pTargetUI = nullptr;

	// 1. �θ� UI ����, ��� �ڽĵ��� �˻� �Ѵ�.

	list<CUI*> queue;

	queue.push_back(_pParentUI);

	while (!queue.empty())
	{
		// ť���� ������ �ϳ� ������
		CUI* pUI = queue.front();
		queue.pop_front();

		// ť���� ������ UI�� TargetUI ���� Ȯ��
		// Ÿ�� UI �� ��, �� �켱������ ���� ������ �� ���� ������ �ڽ� UI
		if (pUI->IsMouseOn())
		{
			pTargetUI = pUI;
		}
		else
		{
			// ���� ��ư ����, ������ üũ�� �ٽ� �����Ѵ�.
			if (bLbtnAway)
			{
				pUI->m_bLbtnDown = false;
			}
		}
		

		const vector<CUI*>& vecChild = pUI->GetChildUI();
		for (size_t i = 0; i < vecChild.size(); ++i)
		{
			queue.push_back(vecChild[i]);
		}
	}
	return pTargetUI;
}
