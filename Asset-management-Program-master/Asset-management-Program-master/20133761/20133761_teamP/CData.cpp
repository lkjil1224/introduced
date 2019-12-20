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
	cout << "��    �� : " << m_tInfo.Name << endl;
	cout << "��     ¥ : " << m_tInfo.Day << endl;
	cout << "���� or ���� : " << m_tInfo.Type << endl;
	cout << "��     �� : " << m_tInfo.Kind << endl << endl;
	cout << "��     �� : " << m_tInfo.Money << "��" << endl << endl;
}

void CData::Release()
{

}

void CData::CreateInfo()
{
	int Day, Type, Kind, Money;

	cout << "��¥ �Է� : ";
	cin >> Day;

	cout << "����(1) or ����(2)  ���� : ";
	cin >> Type;
	if (Type == 0 || Type >= 3)
	{
		cout << "�ٽ� �Է����ּ���" << endl;
		cout << "����(1) or ����(2)  ���� : ";
		cin >> Type;
	}

	if (Type == 2)
	{
		cout << "���� ����(1. ��ȭ��Ȱ , 2. ����, 3. �����, 4. �ĺ�) : ";
		cin >> Kind;
		if (Kind == 0 || Kind >= 5)
		{
			cout << "�ٽ��Է����ּ���.";
			cin >> Kind;
		}

	}
	else if (Type == 1)
	{
		cout << "���� ����(1.���� , 2. �뵷, 3. ��Ÿ ): ";
		cin >> Kind;
		if (Kind == 0 || Kind > 3)
		{
			cout << "�ٽ� �Է��� �ּ���. ";
			cin >> Kind;
		}

	}

	cout << "�ݾ� : ";
	cin >> Money;


	m_tInfo = INFO(Day, Type, Kind, Money);
	m_tInfo.Name = SetName();
}