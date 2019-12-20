#include "CObj.h"


CObj::CObj(void)
{
}


CObj::~CObj(void)
{
}

char* CObj::SetName()
{
	char str[128] = "";

	cout << "이름 입력 : ";
	cin >> str;

	char* pName = new char[strlen(str)];
	strcpy(pName, str);

	return pName;
}
