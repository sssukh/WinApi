#pragma once

// ���漱��
class CObject;

class CScene
{
private:
	vector<CObject*>	 m_arrObj[(UINT)GROUP_TYPE::END]; // ������Ʈ�� ���� & ������ ���͸� �׷� ������ŭ ����
	wstring				 m_strName; // Scene �̸�

public:
	void AddObject(CObject* _pObj, GROUP_TYPE _eType)
	{
		m_arrObj[(UINT)_eType].push_back(_pObj);
	}

public:
	CScene();
	virtual ~CScene();

	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	const vector<CObject*>& GetGroupObject(GROUP_TYPE _eType)
	{
		return m_arrObj[(UINT)_eType];
	}

	void DeleteGroup(GROUP_TYPE _eTarget);
	void DeleteAll();

	virtual void Enter() = 0;	// �ش� Scene �� ���� �� ȣ��
	virtual void Exit() = 0;	// �ش� Scene �� Ż�� �� ȣ��

	virtual void update();
	virtual void finalupdate();
	virtual void render(HDC _dc);
};

