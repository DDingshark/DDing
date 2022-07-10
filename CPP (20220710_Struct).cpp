#include<iostream>
#include<string>
using namespace std;


int main_3()
{
	// 배열 : 같은 데이터형의 집합
	// 구조체 : 서로다른 데이터형들도 포함할 수 있는 데이터형
	//    but. 배열보다는 사용하기 어려움 

	struct Character
	{
		string name;
		int HP;
		int Damage;
		int Level;
		int Exp;
		double Speed;

		//이 친구들을 맴버 
	};

	Character Player; // 캐릭터구조체를 가지는 Player이라는 변수를 생성 
	Player.name = "꼉래";
	Player.Damage =10;
	Player.HP = 100;

	Character Player_2 = { "띵주", 100,10,3,12,12.1 };
	//이러면 알아서 쭉쭉쭉 들어감; 


	//구조체도 배열로 선언할 수 있음.
	Character Player_array[2] = {
		{"꼉래 따까리", 100,3,3,3,3},
		{"띵주 따까리",100,2,2,2,2}
	};
	//이런식으로 배열로써 선언할 수도 있음
	Player_array[1].HP = 101;
	//이런식으로도 다룰수 잇음.
	return 0;
}