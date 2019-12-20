#pragma once
#include "Include.h"

class CObj;
class CMainGame
{
private:
	CObj* m_pList;
	bool m_bOutput;
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
public:
	void CreateNode(CObj* _list);
	void Output(CObj* _plist);
	void Delete(CObj* _plist, char* pName);
public:
	CMainGame(void);
	~CMainGame(void);
};

