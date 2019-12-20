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
				cout << "\t 사용자 정보를 추가합니다\n" << endl;
				cout << "\t 사용자 이름:";
				cin.getline(card[card_Count].name, INPUT_SIZE);
				cout << "\t 날짜:";
				cin.getline(card[card_Count].day, INPUT_SIZE);
				cout << "\t 종류:";
				cin.getline(card[card_Count].type, INPUT_SIZE);
				cout << "\t 가격:";
				cin >> card[card_Count].price;
				cin.ignore(1024, '\n');
			

				card_Count++;
				cout << "\n\t추가완료!";
			}
			else
			{
				cout << "\t저장공간부족" << endl;
			}
			break;
		}
		case DELETE:
			char delete_name[INPUT_SIZE];
			cout << "\n\t삭제할 사용자의 이름을 입력하세요:";
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
					strcpy_s(delete_name, "\n\n\t삭제완료");
					cout << delete_name;
					break;
				}
			}//for()
			if (strcmp(delete_name, "\n\n\t삭제완료"))
				cout << "\n\n\t삭제실패";
			break;
		case SEARCH:
			char search_name[INPUT_SIZE];
			cout << "\n\t검색할 사용자의 이름을 입력하세요:";
			cin.getline(search_name, INPUT_SIZE);

			cout << "\n" << endl;

			for (int i = 0; i < card_Count; i++)
			{
				if (!strcmp(search_name, card[i].name))
				{
					cout << "\t 이름:" << card[i].name << endl;
					cout << "\t 날짜:" << card[i].day << endl;
					cout << "\t 종류:" << card[i].type << endl;
					cout << "\t 가격:" << card[i].price << endl;
					cout << "\n\n";
					strcpy_s(search_name, "\n\n\t검색완료");
					break;
				}
			}//for()

			if (strcmp(search_name, "\n\n\t검색완료") != false)
				cout << "\n\n\t검색실패";

			break;
		case PRINT:
		{
			cout << "\t 사용자 정보리스트 출력\n\n" << endl;
			for (int i = 0; i < card_Count; i++)
			{
				cout << "\t 이름:" << card[i].name << endl;
				cout << "\t 날짜:" << card[i].day << endl;
				cout << "\t 종류:" << card[i].type << endl;
				cout << "\t 가격:" << card[i].price << endl;
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
		cout << "\t잘못된 입력입니다";
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
	cout << "\t------------ 사용자관리 프로그램 ------------\n" << endl;
	cout << "\t[1]추가 [2]검색 [3]출력 [4]삭제 [5]종료\n" << endl;
	cout << "\t선택할 번호를 입력하세요:";
	cin >> select;
	system("cls");
	Buffer();
	return select;
}//End of Input()



