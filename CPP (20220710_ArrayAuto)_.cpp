#include<iostream>
using namespace std;
int main_2()
{
	int a(10);
	int b(100);
	double a_D(10.0);
	double b_D(20.0);
	auto c(a + b);
	auto c_D(a_D + b_D);

	//auto �˾Ƽ� �ϰ� �Ǵ��ؼ� �ڷ����� ������!

	auto d_A(10.0);

	cout << c << endl;
	cout << c_D << endl;

	/*
	C++�� ���յ��������� �����Ѵ�.
	 >> ����� ���Ǵ�� ���ο� ���������� ���� �� �ִ�.
	 ���յ������� : �⺻�������� �ε��Ҽ������� ����
	*/

	/*
	�迭(arry)  : ���� ���������� ����
	typeName arryName[arrySize];
	*/
	short month[12];//�迭�� ����
	// short���������� ������ month��� �̸������� 12���� ũ��(����� ����(�ִ�))�� ���� �迭
	// 1. �迭�� ���Ҵ� ������ short���� 
	// 2. �迭�� ����� �ѱ�� ���� = 13���� ���� �ȴ�

	short month_1[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	//�迭�� �ʱ�ȭ �� 12���� �� �����ʿ�� ���� �κ������θ� �ʱ�ȭ�ϸ� <- �������� '0'
	cout << month[1] << endl;
	//����Ʈ�� �Ȱ��� �ε����� �������� ����� �� ����. + 0���� ���۵� �Ȱ���
	// + �迭������ ������ �������� X;

	short month_2[] = { 1,2,3 };
	//�̷����ص� �˾Ƽ� 3���� ũ�⸦ ������

	//���ڿ� : ������ ��
	char char_array[6] = { 'H','e','l','l','o','\0'};
	//  C++������ " �� ' �� ������ �ٸ� ' -> 1�� " ->���ڿ��� ǥ��
	//�������� \0 NULL �������ִ°� ������� �ȴ�...
	char Char_array[] = "Hello";
	// �䷸���ϸ� �˾Ƽ� \0�� �־��ְ� ũ�⵵ �˾Ƽ� ���� �ϰ���?
	cout << char_array << endl;


	// ���ڿ� �Է�
	// get .getline

	//cin.getline(name, Size); // stringŸ�Կ����� X , char �迭������ ��밡��
	// why string ������ �׷�. ���ڿ��� ���簡 ���� + ��� ������ �������� 
	


	
	return 0;
}