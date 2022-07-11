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
	// ap �� �� ���ǵ�, ���±����� 
	int skill[4] = { 0, };
	//ĳ���ʹ� �ִ� ��ų�� 4��
	int Answer;
};
//����ü!

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
//������ �����ϴ� �Լ� 
void Login_Func()
{
	char Player_ID[] = "cpp";
	string Player_IN;
	int PassWord;
	cout << "Player_ID : " << endl;
	cin >> Player_IN;

	if (Player_ID == Player_IN)
	{
		cout << "��й�ȣ�� �Է��Ͽ� �ֽʼ� : " << endl;
		cin >> PassWord;
	}
	else
	{
		exit(1); // ���α׷� ����
	}

	cout << "�α����� �Ϸ�Ǿ����ϴ�." << endl;
}


int Rest_Hp(Player_Char Player, Monster Monster)
{
	cout << Player.Name << " �� ���� !" << endl;
	Monster.Hp -= Player.Damage * (Random_Number(9) % 10);
	if (Monster.Hp < 0)
	{
		Monster.Hp = 0;
	}
	cout << Monster.Name << " �� ���� HP : " <<Monster.Hp<< endl;
	return Monster.Hp;
}

int Rest_Hp(Monster Monster, Player_Char Player)
{
	cout << Monster.Name << " �� ���� !" << endl;
	Player.Hp -= Monster.Damage * (Random_Number(9) % 10);
	if (Player.Hp < 0)
	{
		Player.Hp = 0;
	}
	cout << Player.Name << " �� ���� HP : "<<Player.Hp << endl;
	return Player.Hp;
}
//���� ���ߴ� �̸��� ������ �Ķ���Ϳ� ���� ȣ��Ǵ� �Լ��� �ٸ���.


int Connet_Monster(string mon)
{
	int Player_Answer(99);
	while (Player_Answer != 1 && Player_Answer != 2)
	{
		cout << "���濡 " << mon << "�� ��Ÿ����! " << endl;
		cout << "1 : �ο��\t2. : ��������" << endl;
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
				cout << "�ൿ�� ���� �ϼ���." << endl;
				cout << "1.����, 2. ��������" << endl;
				cin >> Player.Answer;
			} while (Player.Answer>=3);

			if (Player.Answer == 1)
			{
				Monster.Hp = Rest_Hp(Player, Monster);
				if (Monster.Hp == 0)
				{
					cout << "�������� �̰��!" << endl;
				}
				return 0;
			}
			else
			{
				int Run_p = Random_Number(Player.ap[1]);
				int Run_m = Random_Number(Monster.Speed);

				if (Run_p > Run_m)
				{
					cout << " �������� !" << endl;
					return 0; // �Լ��� ����! ��ɾ��� ���� ���
				}
				else
				{
					cout << "���� �� �� ����!" << endl;
				}

			}
			Player.Hp = Rest_Hp(Monster, Player);
			if (Player.Hp == 0)
			{
				cout << "�������� ����." << endl;
				return 0;
			}
		}
		else
		{
			Player.Hp = Rest_Hp(Monster, Player);
			if (Player.Hp == 0)
			{
				cout << "�������� ����." << endl;
				return 0;
			}
			do
			{
				cout << "�ൿ�� ���� �ϼ���." << endl;
				cout << "1.����, 2. ��������" << endl;
				cin >> Player.Answer;
			} while (Player.Answer >= 3);

			if (Player.Answer == 1)
			{
				Monster.Hp = Rest_Hp(Player, Monster);
				if (Monster.Hp == 0)
				{
					cout << "�������� �̰��.!" << endl;
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
					cout << " �������� !" << endl;
					return 0; // �Լ��� ����! ��ɾ��� ���� ���
				}
				else
				{
					cout << "���� �� �� ����!" << endl;
				}
			}
		}
	
		
	} while (Player.Hp != 0 && Monster.Hp != 0);
	return 0;
	// �ٴ�... ���ϱ� ���⼭ HP�� �� ������ ���Ƶ� �ᱹ�� �ο� ������ ȸ���Ǵ´�??

	// �̰� ����! �ؼ� �����ϱ�!
	// �׷� ������ �����ϰ� ������ ��� �ؾߴ�?
	// ������� ������ �˸� �Ǵ´� �̰� �����͸� �˾ƾ��մϴ�
	// ���� �ð����� �����͸� ���ؼ� ���� ������ ������ ����� ���ƿ�.

}


int main()
{
	int Player_Answer;
//	Login_Func();
	cout << "ĳ���͸� ���� �մϴ�. �г����� �����ּ��� : " << endl;
	Player_Char Player{" ",1,0,100,100,10,{1,1,1}};
	cin >> Player.Name;

	cout << " ���ڱ� ������ ��Ÿ�� ��簡 �׿��� �Ѵٴ� �� �׷� �̾߱�" << endl;
	cout << Player.ap[2] << endl;

	Monster Dog{ "Dog",11,2,10 };
	Player_Answer = Connet_Monster(Dog.Name);
	if (Player_Answer == 1)
	{
		Fight_Start(Player, Dog);
	}
	else
	{
		cout << "������ ��������" << endl;
	}

	cout <<"���� EXP : " << Player.Exp << endl;//��?? ������ġ....
	// ���⼭ ���� �����ؼ� �־����ϱ�! ����Ȱ� �ٲ�ٰ� �ѵ�... ������ �ٲ𸮰�...

	// �����ð����� �̷��� ���� �ذ��� ���� ������ ��� ���� ���Ǵ�... �������..
	// ��� �����͸� �����ϸ� cpp , c �� �����ߴ�? �� 60%�� �´¸�
	return 0;
}
//�F~~~ main ���� �پ��� ���İ�~~~ �k��~~~~~

// �ð������� ����������� �������ڵ� ������ڵ� �˷��ֱ�.