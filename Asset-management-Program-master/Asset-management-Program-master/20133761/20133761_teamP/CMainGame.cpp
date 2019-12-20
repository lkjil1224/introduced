#include "CMainGame.h"
#include "CData.h"

CMainGame::CMainGame(void)
{
}


CMainGame::~CMainGame(void)
{
	Release();
}


void CMainGame::Initialize()
{
	m_bOutput = false;

	m_pList = new CData;
	m_pList->Initialize();
}

void CMainGame::Progress()
{
	cout << "F2. 입력" << endl;
	cout << "F3. 출력" << endl;
	cout << "F4. 삭제" << endl;

	if (GetAsyncKeyState(VK_F2))
		CreateNode(m_pList);
	if (GetAsyncKeyState(VK_F3))
		m_bOutput = true;
	if (GetAsyncKeyState(VK_F4))
	{
		char str[128] = "";

		cout << "삭제할 사람 이름 입력 : ";
		cin >> str;

		char* pName = new char[strlen(str)];
		strcpy(pName, str);

		Delete(m_pList, pName);
	}
}

void CMainGame::Render()
{
	if (m_bOutput)
	{
		Output(m_pList);
		m_bOutput = false;
	}
}

void CMainGame::Release()
{
	delete m_pList;
	m_pList = NULL;
}

void CMainGame::CreateNode(CObj* _plist)
{
	if (_plist->GetBack() != NULL)
		CreateNode(_plist->GetBack());
	else
	{
		CObj* pList = new CData;
		pList->Initialize();

		pList->SetFront(_plist);
		_plist->SetBack(pList);
	}
}

void CMainGame::Output(CObj* _plist)
{
	_plist->Render();

	if (_plist->GetBack() != NULL)
		Output(_plist->GetBack());

	Sleep(500);
}

void CMainGame::Delete(CObj* _plist, char* pName)
{
	if (strcmp(_plist->GetInfo().Name, pName) == false)
	{
		if (_plist->GetFront() != NULL)
		{
			_plist->GetFront()->SetBack(NULL);
		}

		delete _plist;
		_plist = NULL;

		cout << pName << " 정보를 삭제 하였습니다. " << endl;
		Sleep(500);
		return;
	}
	else
	{
		if (_plist->GetBack() != NULL)
		{
			Delete(_plist->GetBack(), pName);
		}
	}
}