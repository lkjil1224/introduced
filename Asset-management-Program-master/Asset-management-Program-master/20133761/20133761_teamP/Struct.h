#pragma once

typedef struct tagInfo
{
	char* Name;
	int Day;
	int Type;
	int Kind;
	int Money;

	tagInfo() {};
	tagInfo(int _day, int _type, int _kind, int _money)
		: Day(_day), Type(_type), Kind(_kind), Money(_money) {};
}INFO;