#include<iostream>
using namespace std;
//���� ���α׷��� �ϸ鼭 ������ ���´� �̻��ϰ� ���� �ѹ��� �� ����
// �˾Ƹ� ����? 

/*
	����ü (Union)
	 : ���δٸ� ���������� �ѹ��� �Ѱ������� ������ �� ����.
*/

/*
	����ü(enum)
	  : ��ȣ ����� ����� �Ϳ� ���� �Ǵٸ� ���.
		: ��ȣ ��� : ����� ��ȣ������ ����ϴ� ��?
*/
int main()
{
	union MyUnion
	{
		int intVal;
		long longVal;
		float floatVal;
	};

	MyUnion test;
	test.intVal = 3;
	cout << test.intVal << endl;
	
	test.longVal = 33;
	cout << test.intVal << endl;
	cout << test.longVal << endl;
	//?? �� ?? 33?????

	test.floatVal = 3.3;
	cout << test.intVal << endl;
	cout << test.longVal << endl;
	cout << test.floatVal << endl;
	//�� ???
	//�ѹ��� �Ѱ�������! �ٲٸ� ���������� �ٲ�.
	//�޸���������.... �� ���� ���� �����������?

	enum spectrum { red, orange, yellow, green, blue, violet};
	/*
		1. ����Ʈ���� ���ο� �������� �̸����� �����.
		2. red~ violet�� 0~6 ���� �������� ��Ÿ���� ��ȣ ����� �����.
	*/

	spectrum a;
	a = orange;
	cout << a << endl;
	//1�� ���. + �����ڵ鿡���� ������� ex. red +orange , red+3 ���� X
	
	int b = blue;
	b = blue + 3;
	cout << b << endl;
	//int �� �����Ҷ��� ������� 
	
	






	return 0;
}