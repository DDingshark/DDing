#include<iostream>
#include<string>
using namespace std;


int main_3()
{
	// �迭 : ���� ���������� ����
	// ����ü : ���δٸ� ���������鵵 ������ �� �ִ� ��������
	//    but. �迭���ٴ� ����ϱ� ����� 

	struct Character
	{
		string name;
		int HP;
		int Damage;
		int Level;
		int Exp;
		double Speed;

		//�� ģ������ �ɹ� 
	};

	Character Player; // ĳ���ͱ���ü�� ������ Player�̶�� ������ ���� 
	Player.name = "�b��";
	Player.Damage =10;
	Player.HP = 100;

	Character Player_2 = { "����", 100,10,3,12,12.1 };
	//�̷��� �˾Ƽ� ������ ��; 


	//����ü�� �迭�� ������ �� ����.
	Character Player_array[2] = {
		{"�b�� ���", 100,3,3,3,3},
		{"���� ���",100,2,2,2,2}
	};
	//�̷������� �迭�ν� ������ ���� ����
	Player_array[1].HP = 101;
	//�̷������ε� �ٷ�� ����.
	return 0;
}