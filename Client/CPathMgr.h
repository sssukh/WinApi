#pragma once
class CPathMgr
{
	SINGLE(CPathMgr);

private:
	wchar_t		m_szContentPath[255]; // 윈도우 파일 이름 제한이 255이다.
public:
	void init();
	const wchar_t* GetContentPath() { return m_szContentPath; }
};

