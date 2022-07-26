#pragma once

struct tEvent
{
	EVENT_TYPE	eEven;	// �̺�Ʈ �̸�
	DWORD_PTR	lParam;	
	DWORD_PTR	wParam;
};

class CEventMgr
{
	SINGLE(CEventMgr)
private:
	vector<tEvent> m_vecEvent;

	vector<CObject*> m_vecDead;

private:
	void Execute(const tEvent& _eve);

public:
	void update();

	void AddEvent(const tEvent& _eve)
	{
		m_vecEvent.push_back(_eve);
	}
};

