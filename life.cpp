#include "life.h"
mal mal::operator ++()
{

	++oper;
	return *this;
}

mal mal::operator --()
{

	--oper;
	return *this;
}

class game :public Player, public mal {
	int x;
	int y;
	int goal1;
	int goal2;
public:
	game() { goal1 = -1; goal2 = -1; };
	void Setgoal1(int a) { goal1 = a; };
	int Getgoal1() { return goal1; };
	void Setgoal2(int a) { goal2 = a; };
	int Getgoal2() { return goal2; };
	void Setgotoxy(int a, int b);
	void gamemain();
	void endgame();
	void clrscr();
	void gamedelay();
};

void game::clrscr()
{
	system("cls");
}

void game::gamedelay()
{
	delay(3000 / 200);
}
void game::Setgotoxy(int a, int b)
{
	x = a;
	y = b;
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

}

void game::gamemain()
{
	int battingm;
	int nowmoney;
	int playmal;
	cout << "\n";
	cout << "\t                         @@ 현메 경마 @@                          " << "\n";
	cout << "\t*****************************************************************" << "\n";
	cout << "\t*  (`ㅇωㅇ´) ｎ__                                             *" << "\n";
	cout << "\t*　n ＞　  ＼/ (_∃		배팅에 인생을 걸어라!           *" << "\n";
	cout << "\t* (∃)/ ∧　　＼_/                                              *" << "\n";
	cout << "\t*　＼_/　＼　 \                                                  *" << "\n";
	cout << "\t*　　　　／ 　 /	묻고 따블로 가!!			*" << "\n";
	cout << "\t*　　　／ ／　／                                                *" << "\n";
	cout << "\t* 　　 (　(　〈                                                 *" << "\n";
	cout << "\t* 　　　＼ ＼　＼                                               *" << "\n";
	cout << "\t* 　　 　(＿(＿＿)                                              *" << "\n";
	cout << "\t*****************************************************************" << "\n";
	cout << "\t* 본게임은 규정에 따라 19세 미만의 청소년이 이용하실수 없습니다.*" << "\n";
	cout << "\t*****************************************************************" << "\n";

	cout << "\n\n" << "현재 소지한 금액:" << Getmoney() << "\n";
	cout << "\n" << "얼마를 배팅 하시겠습니까??";
	cin >> battingm;

	while ((Getmoney() < Getbatting()) || (Getbatting() <= 0)) {
		cout << "\n" << "배팅한 금액이 올바르지 않습니다";
		cout << "얼마를 배팅하시겠습니까?";
		cin >> battingm;
		Setbatting(battingm);
	}
	nowmoney = Getmoney() - Getbatting();
	Setmoney(nowmoney);

	do {
		cout << "\n" << "몇번말에 배팅하시겠습니까?(1~6)";
		cin >> playmal;
		Setmal(playmal);
	} while ((Getmal() > 6) || (Getmal() < 1));
}
void game::endgame()
{
	clrscr();
	int bea;
	char restart;
	bea = random(5) + 2;

	if (Getmoney() <= 1) {
		cout << "더이상 게임을 진행할 돈이 없습니다" << endl;
		cout << "게임을 재시작 하시겠습니까?(y,n)" << endl;
		cin >> restart;

		if (restart == 'y') {
			Setmoney(3000);
			clrscr();
		}
		else
			exit(0);
	}
	else {
		if (Getmal() == Getgoal1()) {
			cout << "   축하드립니다. ^^*" << endl;
			cout << "   배팅금액 :" << Getbatting() << endl;
			cout << "   얻은 금액 (배팅액 *" << bea << "):" << Getbatting() * bea << endl;
			Setmoney(Getmoney() + Getbatting() * bea);
			cout << "   총재산 : " << Getmoney() << endl;
		}
		else if (Getmal() == Getgoal2()) {
			cout << "   이등이시므로 배당한 금액을 돌려드립니다." << endl;
			cout << "   배팅금액 :" << Getbatting() << endl;
			cout << "   얻은 금액 (배팅액 * 1) :" << Getbatting() << endl;
			Setmoney(Getmoney() + Getbatting());
			cout << "   총재산 : " << Getmoney() << endl;
		}
		else {
			cout << "   배당한 금액을 잃으셨습니다" << endl;
			cout << "   배팅금액 : " << Getbatting() << endl;
			cout << "   잃은 금액 : " << Getbatting() << endl;
			cout << "   총재산 : " << Getmoney() << endl;;
		}
	}

}



int main() {
	while (1) {
		mal playmal[MAX];
		game me;
		me.gamemain();
		me.clrscr();
		randomize();
		int i;
		//********************************************게임시작메인*******************************************
		for (i = 0; i < MAX; i++) {

			//		memcpy(S[i].ch,ch_1,sizeof(ch_1));
			playmal[i].Setch_1();
			playmal[i].Setch_2();
			playmal[i].Setx(74);
			playmal[i].Sety((i * 3) + 3);
			me.Setgotoxy(76, playmal[i].Gety());
			//playmal[i].Getch_1();
			cout << i + 1 << endl;
			playmal[i].SetF(random(15) + 5);
			playmal[i].SetS(random(15) + 5);
			//me.Setgotoxy(74,playmal[i].Gety());		
		}
		me.Setgotoxy(50, 20);
		cout << "\n" << "\n" << "게임포기는 ESC키 입니다" << endl;
		me.Setgotoxy(50, 23);
		cout << "\n" << "배팅액:" << me.Getbatting() << " 말번호:" << me.Getmal() << endl;
		//******************************************게임 시작****************************************************
		for (; me.Getgoal2() < 0;) {
			for (i = 0; i < MAX; i++) {
				// 왼쪽으로 달리는 경우
				if (playmal[i].GetRL() == TRUE) {
					playmal[i].Setoper(playmal[i].GetS());
					--playmal[i];
					playmal[i].SetS(playmal[i].Getoper());

					if (playmal[i].GetS() == 0) {
						playmal[i].SetS(playmal[i].GetF());
						playmal[i].gotomal(playmal[i].Getx(), playmal[i].Gety());
						puts("  ");

						if (playmal[i].Getx() > 0) {
							playmal[i].Setoper(playmal[i].Getx());
							--playmal[i];
							playmal[i].Setx(playmal[i].Getoper());
							playmal[i].gotomal(playmal[i].Getx(), playmal[i].Gety());
							playmal[i].Getch_1();

						}
					}
				}

				//오른으로 달리는 경우
				else if (playmal[i].GetRL() == FALSE) {
					if (playmal[i].GetF() == 0)
						continue;
					playmal[i].Setoper(playmal[i].GetS());
					--playmal[i];
					playmal[i].SetS(playmal[i].Getoper());
					if (playmal[i].GetS() == 0) {
						playmal[i].SetS(playmal[i].GetF());
						playmal[i].gotomal(playmal[i].Getx(), playmal[i].Gety());
						puts("  ");

						if (playmal[i].Getx() < 75) {
							playmal[i].Setoper(playmal[i].Getx());
							++playmal[i];
							playmal[i].Setx(playmal[i].Getoper());
							playmal[i].gotomal(playmal[i].Getx(), playmal[i].Gety());
							playmal[i].Getch_2();
						}

						//들어오나말 확인
						else {
							if (me.Getgoal1() < 0) {
								me.Setgoal1(i + 1);
								me.Setgotoxy(9, 21);
								cout << "1등은" << me.Getgoal1() << "번말이 승리를 차지하였습니다" << endl;
								playmal[i].SetF(0);
							}
							else if (me.Getgoal2() < 0) {
								me.Setgoal2(i + 1);
								me.Setgotoxy(9, 22);
								cout << "2등은" << me.Getgoal2() << "번말이 승리를 차지하였습니다" << endl;
								//playmal[i].SetF(0);
								delay(1500);
							}
						}
					}
				}
				//반환점찍었는지 확인
				if (playmal[i].GetRL() == TRUE) {
					if (playmal[i].Getx() == 1) {
						playmal[i].SetRL(FALSE);
						randomize();
						playmal[i].SetF(random(18) + 5);
						playmal[i].SetS(random(18) + 5);
					}
				}


			}delay(1000 / 100);

		}
		me.endgame();
	}
	return 0;
}