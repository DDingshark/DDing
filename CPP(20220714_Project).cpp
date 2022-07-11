#include<iostream>
#include<random>
#include<string>
#include<cstdlib>
using namespace std;
struct Player_Char
{
	string Name;
	int Leval;
	double Exp;
	int Hp;
	int Mp;
	int Damage;
	int ap[3] = { 0, };
	// ap 는 힘 스피드, 지력까지만 
	int skill[4] = { 0, };
	//캐릭터당 최대 스킬은 4개
	int Answer;
};
//구조체!

struct Monster
{
	string Name;
	int Hp;
	int Speed;
	int Damage;
};
int Random_Number(int num)
{
	random_device rd;

	mt19937 gen(rd());

	uniform_int_distribution<int> dis(0, num);

	return dis(gen);
}
//난수를 생성하는 함수 
void Login_Func()
{
	char Player_ID[] = "cpp";
	string Player_IN;
	int PassWord;
	cout << "Player_ID : " << endl;
	cin >> Player_IN;

	if (Player_ID == Player_IN)
	{
		cout << "비밀번호를 입력하여 주십쇼 : " << endl;
		cin >> PassWord;
	}
	else
	{
		exit(1); // 프로그램 종료
	}

	cout << "로그인이 완료되었습니다." << endl;
}


int Rest_Hp(Player_Char Player, Monster Monster)
{
	cout << Player.Name << " 의 공격 !" << endl;
	Monster.Hp -= Player.Damage * (Random_Number(9) % 10);
	if (Monster.Hp < 0)
	{
		Monster.Hp = 0;
	}
	cout << Monster.Name << " 의 남은 HP : " <<Monster.Hp<< endl;
	return Monster.Hp;
}

int Rest_Hp(Monster Monster, Player_Char Player)
{
	cout << Monster.Name << " 의 공격 !" << endl;
	Player.Hp -= Monster.Damage * (Random_Number(9) % 10);
	if (Player.Hp < 0)
	{
		Player.Hp = 0;
	}
	cout << Player.Name << " 의 남은 HP : "<<Player.Hp << endl;
	return Player.Hp;
}
//전에 말했던 이름은 같지만 파라미터에 따라 호출되는 함수가 다르다.


int Connet_Monster(string mon)
{
	int Player_Answer(99);
	while (Player_Answer != 1 && Player_Answer != 2)
	{
		cout << "전방에 " << mon << "이 나타났다! " << endl;
		cout << "1 : 싸우기\t2. : 도망가기" << endl;
		cin >> Player_Answer;
	}

	return Player_Answer;
}

int Fight_Start(Player_Char Player, Monster Monster)
{
	do
	{
		if (Player.ap[1] >= Monster.Speed)
		{
			do
			{
				cout << "행동을 선택 하세요." << endl;
				cout << "1.공격, 2. 도망가기" << endl;
				cin >> Player.Answer;
			} while (Player.Answer>=3);

			if (Player.Answer == 1)
			{
				Monster.Hp = Rest_Hp(Player, Monster);
				if (Monster.Hp == 0)
				{
					cout << "전투에서 이겼다!" << endl;
				}
				return 0;
			}
			else
			{
				int Run_p = Random_Number(Player.ap[1]);
				int Run_m = Random_Number(Monster.Speed);

				if (Run_p > Run_m)
				{
					cout << " 도망갔다 !" << endl;
					return 0; // 함수의 종료! 명령어라고 보면 댈듯
				}
				else
				{
					cout << "도망 갈 수 없다!" << endl;
				}

			}
			Player.Hp = Rest_Hp(Monster, Player);
			if (Player.Hp == 0)
			{
				cout << "전투에서 졌다." << endl;
				return 0;
			}
		}
		else
		{
			Player.Hp = Rest_Hp(Monster, Player);
			if (Player.Hp == 0)
			{
				cout << "전투에서 졌다." << endl;
				return 0;
			}
			do
			{
				cout << "행동을 선택 하세요." << endl;
				cout << "1.공격, 2. 도망가기" << endl;
				cin >> Player.Answer;
			} while (Player.Answer >= 3);

			if (Player.Answer == 1)
			{
				Monster.Hp = Rest_Hp(Player, Monster);
				if (Monster.Hp == 0)
				{
					cout << "전투에서 이겼다.!" << endl;
					Player.Exp += 10;
					return 0;
				}
			}
			else
			{
				int Run_p = Random_Number(Player.ap[1]);
				int Run_m = Random_Number(Monster.Speed);

				if (Run_p > Run_m)
				{
					cout << " 도망갔다 !" << endl;
					return 0; // 함수의 종료! 명령어라고 보면 댈듯
				}
				else
				{
					cout << "도망 갈 수 없다!" << endl;
				}
			}
		}
	
		
	} while (Player.Hp != 0 && Monster.Hp != 0);
	return 0;
	// 근대... 보니까 여기서 HP를 막 지지고 볶아도 결국에 싸움 끝나면 회복되는대??

	// 이걸 복사! 해서 넣으니까!
	// 그럼 원본을 수정하고 싶은대 어떻게 해야대?
	// 참조라는 개념을 알면 되는대 이건 포인터를 알아야합니다
	// 다음 시간에는 포인터를 통해서 좀더 정교한 게임을 만들어 보아요.

}


int main()
{
	int Player_Answer;
//	Login_Func();
	cout << "캐릭터를 생성 합니다. 닉네임을 적어주세요 : " << endl;
	Player_Char Player{" ",1,0,100,100,10,{1,1,1}};
	cin >> Player.Name;

	cout << " 갑자기 마왕이 나타나 용사가 죽여야 한다는 뭐 그런 이야기" << endl;
	cout << Player.ap[2] << endl;

	Monster Dog{ "Dog",11,2,10 };
	Player_Answer = Connet_Monster(Dog.Name);
	if (Player_Answer == 1)
	{
		Fight_Start(Player, Dog);
	}
	else
	{
		cout << "무사히 도망갔다" << endl;
	}

	cout <<"얻은 EXP : " << Player.Exp << endl;//어?? 내경험치....
	// 여기서 이제 복사해서 넣었으니까! 복사된게 바뀐다고 한들... 원본이 바뀔리가...

	// 다음시간부터 이러한 문제 해결을 위한 포인터 라는 것을 배울건대... 좀어려움..
	// 사실 포인터를 정복하면 cpp , c 를 정복했다? 한 60%는 맞는말
	return 0;
}
//쒯~~~ main 존나 줄어든거 뭐냐고~~~ 줸장~~~~~

// 시간남으면 교양과목으로 제작자코드 사용자코드 알려주기.