#include<iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#define MAX 6
#define ESC 27
#define randomize() srand((unsigned)time(NULL))
#define random(n) (rand() % (n))
#define delay(n) Sleep(n)
using namespace std;
class Player {
	static int money;//재산
	int batting;//배팅금
	int selectmal;//선택한말
public:
	void Setmoney(int j) { money = j; }
	void Setbatting(int i) {
		batting = i;
	}
	int Getbatting() { return batting; }

	void Setmal(int j) {
		selectmal = j;
	}
	int Getmal() { return selectmal; }
	int Getmoney() { return money; }
};
int Player::money = 3000;
class mal {
	int x;
	int y;
	int oper;
	const char* ch_1;
	const char* ch_2;
	char ch[3];
	int nFrame;               // 속도
	int nStay;				// 속도에 대한 카운트
	bool RL;

public:
	mal() { RL = true; };
	mal operator --();
	mal operator ++();
	void gotomal(int x, int y) {
		COORD Cur;
		Cur.X = x;
		Cur.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);


	};
	void Setgotoxy(int a, int b);
	void Setx(int a) { x = a; };
	void Sety(int b) { y = b; };
	int Getx() { return x; };
	int Gety() { return y; };
	void SetRL(bool a) { RL = a; };
	bool GetRL() { return RL; };
	//	void Setch_1(string ch = "o_") { ch_1 = ch; };
	void Setch_1(const char* a = "(..^)~<") { ch_1 = a; };
	void Getch_1() { puts(ch_1); }
	void Setch_2(const char* b = ">-(^,,)") { ch_2 = b; };
	void Getch_2() { puts(ch_2); };
	void SetF(int a) { nFrame = a; };
	int GetF() { return nFrame; };
	void SetS(int a) { nStay = a; };
	int GetS() { return nStay; };
	void Setoper(int a) { oper = a; };
	int Getoper() { return oper; };

};
