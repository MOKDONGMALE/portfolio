#pragma once
#include "Util.h"

using namespace std;

typedef struct _PCinfo
{
	string id;
	string pw;
	string name;
	int seat;		// ȸ������ �� ������ �ڸ� ����
	int cycle;		// �α��� 1�� --> ����, �α��� 2�� --> ����
	int money=0;		// ������ �ݾ�
	int time1;		// ���� �ð�
	int time2;		// �� �ð�
	int birth;

}PCinfo;

