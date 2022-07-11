#include<iostream>
#include<cstdlib> //c����� stdlib�� �����ϱ����� ���� ++ �� �տ� C������
// rand(), srand()
#include<ctime>
// time() <

#include<iomanip>
#include<random>
#include<map>


using namespace std;


int main()
{
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;

	//��?? �� ������鼭 �����Ҷ����� ��ӶȰ���????
	//	->�������� seed���� �ʱ⿡ �������־� �׳� �̹� �����Ȱ� �ҷ����´���

	//�׷�... seed ���� �����Ϸ���?


	cout << "start srand" << endl;
	srand(10);//seed�� ���� 
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;

	//�ٲ�� �ߴ´�,,, �׷��� �ѹ��� �޶����� ��� �Ȱ��� �������ڳ�..

	//����� �ߴ´� ctime�� ��������߿� time�̶� �Լ���
	//����ð��� �ʷ� ȯ���� ���� ��ȯ���ִ� �Լ��� �ֳ�?



	srand((int)time(nullptr));
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;
	cout << "���� : " << rand() << endl;

	//okok �ƴ� ���� �� ���������Ѵ� �� ������ ���̸� �ȵɱ�?
	// ����Ʈ : 0~32767 �̶�
	// ������ �����ڸ� Ȱ���ؼ� 0~99 0~9 �̷������� �ٿ�����?

	cout << "���� : " << rand()%10 << endl;
	cout << "���� : " << rand()%10 << endl;
	cout << "���� : " << rand()%10 << endl;
	cout << "���� : " << rand()%10 << endl;
	cout << "���� : " << rand()%10 << endl;
	cout << "���� : " << rand()%10 << endl;
	cout << "���� : " << rand()%10 << endl;
	cout << "���� : " << rand()%10 << endl;
	//������ ���� 32767 �̶�� �׷� 0~67�� ���� Ȯ���� 68~99���� ���� ����?
	//���� �̰� �ĳ ����....
	//�̷��� ���� ���α׷� �ϴ¾ֵ� �ִ´� �̷��� ����� �ݽô�.



	//�̰� ���� ���ڴٸ� ��....
	//�Ż��� �� 
	//random ������� ���� 


	//�õ尪�� ������� random_device ����
	random_device rd;

	//random device�� ���� �������� ������ �ʱ�ȭ �մϴ�
	mt19937 gen(rd());

	// 0~99 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����
	uniform_int_distribution<int> dis(0, 99);
	//uniform distibution = �յ����
	//		int          <int> = ���� �յ� ���� 
	//							dis(����)
	for (int i = 0; i < 5; i++)
	{
		cout << "���� : " << dis(gen) << endl;
	}


	// ����... ����?

	random_device rd_n;
	mt19937 gen_1(rd_n());
	normal_distribution<double> dist(/*��� : */0, /*ǥ�� ����*/ 1);

	map<int, int>hist{};
	for (int j = 0; j < 10000; ++j)
	{
		++hist[round(dist(gen_1))];
	}

	for (auto p : hist)
	{
		cout << setw(2) << p.first << ' ' << string(p.second / 100, '0') << " "
			<< p.second << '\n' << endl;
	}

	//���� ���Ժ��� ����? �ʿ��ϸ� ���� �ϼ��� 




	return 0;
}