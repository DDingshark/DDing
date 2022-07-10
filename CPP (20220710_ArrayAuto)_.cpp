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

	//auto 알아서 니가 판단해서 자료형을 맞쳐줘!

	auto d_A(10.0);

	cout << c << endl;
	cout << c_D << endl;

	/*
	C++는 복합데이터형을 제공한다.
	 >> 사용자 정의대로 새로운 데이터형을 만들 수 있다.
	 복합데이터형 : 기본정수형과 부동소수점형의 조합
	*/

	/*
	배열(arry)  : 같은 데이터형의 집합
	typeName arryName[arrySize];
	*/
	short month[12];//배열의 선언
	// short데이터형을 가지는 month라는 이름을가진 12개의 크기(요소의 갯수(최대))를 가진 배열
	// 1. 배열의 원소는 무조건 short형태 
	// 2. 배열의 사이즈를 넘길수 없음 = 13개가 들어가면 안대

	short month_1[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	//배열의 초기화 꼭 12개를 다 넣을필요는 없음 부분적으로만 초기화하면 <- 나머지는 '0'
	cout << month[1] << endl;
	//리스트와 똑같이 인덱스의 개념으로 사용할 수 있음. + 0부터 시작도 똑같음
	// + 배열끼리의 연산은 제공하지 X;

	short month_2[] = { 1,2,3 };
	//이렇게해도 알아서 3으로 크기를 정해줌

	//문자열 : 문자의 열
	char char_array[6] = { 'H','e','l','l','o','\0'};
	//  C++에서는 " 와 ' 의 역할이 다름 ' -> 1개 " ->문자열을 표현
	//마지막에 \0 NULL 지정해주는거 까먹으면 안대...
	char Char_array[] = "Hello";
	// 요렇게하면 알아서 \0도 넣어주고 크기도 알아서 지정 하겠죵?
	cout << char_array << endl;


	// 문자열 입력
	// get .getline

	//cin.getline(name, Size); // string타입에서는 X , char 배열에서는 사용가능
	// why string 을쓰냐 그럼. 문자열의 복사가 편함 + 몇가지 연산을 제공해중 
	


	
	return 0;
}