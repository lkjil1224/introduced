#include "CData.h"


CData::CData(void)
{
}


CData::~CData(void)
{
}


void CData::Initialize()
{
	m_pFront = NULL;
	m_pBack = NULL;

	CreateInfo();
}

void CData::Progress()
{

}

void CData::Render()
{
	cout << "이    름 : " << m_tInfo.Name << endl;
	cout << "날     짜 : " << m_tInfo.Day << endl;
	cout << "수입 or 지출 : " << m_tInfo.Type << endl;
	cout << "종     류 : " << m_tInfo.Kind << endl << endl;
	cout << "금     액 : " << m_tInfo.Money << "원" << endl << endl;
}

void CData::Release()
{

}

void CData::CreateInfo()
{
	int Day, Type, Kind, Money;

	cout << "날짜 입력 : ";
	cin >> Day;

	cout << "수입(1) or 지출(2)  설정 : ";
	cin >> Type;
	if (Type == 0 || Type >= 3)
	{
		cout << "다시 입력해주세요" << endl;
		cout << "수입(1) or 지출(2)  설정 : ";
		cin >> Type;
	}

	if (Type == 2)
	{
		cout << "종류 설정(1. 문화생활 , 2. 쇼핑, 3. 교통비, 4. 식비) : ";
		cin >> Kind;
		if (Kind == 0 || Kind >= 5)
		{
			cout << "다시입력해주세요.";
			cin >> Kind;
		}

	}
	else if (Type == 1)
	{
		cout << "종류 설정(1.월급 , 2. 용돈, 3. 기타 ): ";
		cin >> Kind;
		if (Kind == 0 || Kind > 3)
		{
			cout << "다시 입력해 주세요. ";
			cin >> Kind;
		}

	}

	cout << "금액 : ";
	cin >> Money;


	m_tInfo = INFO(Day, Type, Kind, Money);
	m_tInfo.Name = SetName();
}