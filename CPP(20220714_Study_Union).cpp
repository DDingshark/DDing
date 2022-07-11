#include<iostream>
using namespace std;
//별로 프로그래밍 하면서 쓸일은 없는대 이상하게 가끔 한번씩 툭 나옴
// 알아만 두자? 

/*
	공용체 (Union)
	 : 서로다른 데이터형을 한번에 한가지만을 보관할 수 있음.
*/

/*
	열거체(enum)
	  : 기호 상수를 만드는 것에 대한 또다른 방법.
		: 기호 상수 : 상수를 기호적으로 사용하는 것?
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
	//?? 왜 ?? 33?????

	test.floatVal = 3.3;
	cout << test.intVal << endl;
	cout << test.longVal << endl;
	cout << test.floatVal << endl;
	//왜 ???
	//한번에 한가지씩만! 바꾸면 데이터형도 바뀜.
	//메모리절약이점.... 잘 쓰진 않음 교양과목정도?

	enum spectrum { red, orange, yellow, green, blue, violet};
	/*
		1. 스팩트럼을 새로운 데이터형 이름으로 만든다.
		2. red~ violet를 0~6 까지 정수값을 나타내는 기호 상수로 만든다.
	*/

	spectrum a;
	a = orange;
	cout << a << endl;
	//1이 출력. + 열거자들에대한 산술연산 ex. red +orange , red+3 지원 X
	
	int b = blue;
	b = blue + 3;
	cout << b << endl;
	//int 에 대입할때는 상관없음 
	
	






	return 0;
}