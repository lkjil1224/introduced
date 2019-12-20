#pragma warning (disable:4996)
#include <iostream>


using namespace std;

#define CARD_SIZE 10
#define INPUT_SIZE 100 

int card_Count;

enum MENU
{
	INSERT = 1,
	SEARCH,
	PRINT,
	DELETE,
	EXIT
};

typedef struct PersonCard
{
	char name[INPUT_SIZE];
	char day[INPUT_SIZE];
	char type[INPUT_SIZE];
	int price;
};

void Buffer(void);
int Input(void);

int main()
{
	PersonCard card[CARD_SIZE] = {};

	while (true)
	{
		switch (Input())
		{
		case INSERT:
		{
			if (card_Count < CARD_SIZE) {
				cout << "\t ����� ������ �߰��մϴ�\n" << endl;
				cout << "\t ����� �̸�:";
				cin.getline(card[card_Count].name, INPUT_SIZE);
				cout << "\t ��¥:";
				cin.getline(card[card_Count].day, INPUT_SIZE);
				cout << "\t ����:";
				cin.getline(card[card_Count].type, INPUT_SIZE);
				cout << "\t ����:";
				cin >> card[card_Count].price;
				cin.ignore(1024, '\n');
			

				card_Count++;
				cout << "\n\t�߰��Ϸ�!";
			}
			else
			{
				cout << "\t�����������" << endl;
			}
			break;
		}
		case DELETE:
			char delete_name[INPUT_SIZE];
			cout << "\n\t������ ������� �̸��� �Է��ϼ���:";
			cin.getline(delete_name, INPUT_SIZE);

			for (int i = 0; i < card_Count; i++)
			{
				if (!strcmp(delete_name, card[i].name))
				{
					for (int j = i; j < card_Count; j++)
					{
						card[j] = card[j + 1];
					}//for()
					card_Count--;
					strcpy_s(delete_name, "\n\n\t�����Ϸ�");
					cout << delete_name;
					break;
				}
			}//for()
			if (strcmp(delete_name, "\n\n\t�����Ϸ�"))
				cout << "\n\n\t��������";
			break;
		case SEARCH:
			char search_name[INPUT_SIZE];
			cout << "\n\t�˻��� ������� �̸��� �Է��ϼ���:";
			cin.getline(search_name, INPUT_SIZE);

			cout << "\n" << endl;

			for (int i = 0; i < card_Count; i++)
			{
				if (!strcmp(search_name, card[i].name))
				{
					cout << "\t �̸�:" << card[i].name << endl;
					cout << "\t ��¥:" << card[i].day << endl;
					cout << "\t ����:" << card[i].type << endl;
					cout << "\t ����:" << card[i].price << endl;
					cout << "\n\n";
					strcpy_s(search_name, "\n\n\t�˻��Ϸ�");
					break;
				}
			}//for()

			if (strcmp(search_name, "\n\n\t�˻��Ϸ�") != false)
				cout << "\n\n\t�˻�����";

			break;
		case PRINT:
		{
			cout << "\t ����� ��������Ʈ ���\n\n" << endl;
			for (int i = 0; i < card_Count; i++)
			{
				cout << "\t �̸�:" << card[i].name << endl;
				cout << "\t ��¥:" << card[i].day << endl;
				cout << "\t ����:" << card[i].type << endl;
				cout << "\t ����:" << card[i].price << endl;
				cout << "\n\n";
			}//for()
			break;
		}
		case EXIT:
			exit(0);
		}
		_sleep(3000);
		system("cls");
	}//while()
	return 0;
}//End of main()

void Buffer(void)
{
	if (cin.fail())
	{
		cout << "\t�߸��� �Է��Դϴ�";
		cin.clear();
		cin.ignore(1024, '\n');
	}
	else
		cin.ignore(1024, '\n');
}//End of Buffer()

int Input(void)
{
	int select;
	system("cls");
	cout << "\t------------ ����ڰ��� ���α׷� ------------\n" << endl;
	cout << "\t[1]�߰� [2]�˻� [3]��� [4]���� [5]����\n" << endl;
	cout << "\t������ ��ȣ�� �Է��ϼ���:";
	cin >> select;
	system("cls");
	Buffer();
	return select;
}//End of Input()



