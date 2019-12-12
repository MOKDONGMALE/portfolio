#pragma once
#include "Util.h"

using namespace std;

typedef struct _PCinfo
{
	string id;
	string pw;
	string name;
	int seat;		// 회원정보 속 본인의 자리 정보
	int cycle;		// 로그인 1번 --> 입장, 로그인 2번 --> 퇴장
	int money=0;		// 충전된 금액
	int time1;		// 시작 시간
	int time2;		// 끝 시간
	int birth;

}PCinfo;

