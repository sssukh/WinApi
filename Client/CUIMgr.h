#pragma once

class CUI;

class CUIMgr
{
	SINGLE(CUIMgr);

private:

public:
	void update();

private:
	// �θ� UI ������ ������ Ÿ���� �� UI �� ã�Ƽ� ��ȯ�Ѵ�.
	CUI* GetTargetedUI(CUI* _pParentUI); 
};

