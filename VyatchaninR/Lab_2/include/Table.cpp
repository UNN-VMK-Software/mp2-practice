#include "Table.h"

Table::Table(int s)
{
	max = s;
	size = 0;
	flag = -1;
	r = new Record[s];
}

void Table::First()
{
	flag = NULL;
}

bool Table::Full()
{
	return false;
}

void Table::Next()
{
}

Record & Table::GetCurr()
{
	// TODO: вставьте здесь оператор return
}
