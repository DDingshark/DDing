#include<iostream>
#include<cstdlib> //c언어의 stdlib와 구별하기위해 보통 ++ 가 앞에 C를붙임
// rand(), srand()
#include<ctime>
// time() <

#include<iomanip>
#include<random>
#include<map>


using namespace std;


int main()
{
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;

	//어?? 왜 난수라면서 실행할때마다 계속똑같지????
	//	->난수생성 seed값이 초기에 정해져있어 그냥 이미 생성된거 불러오는느낌

	//그럼... seed 값을 변경하려면?


	cout << "start srand" << endl;
	srand(10);//seed값 변경 
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;

	//바뀌긴 했는대,,, 그래도 한번만 달라지고 계속 똑같은 값나오자나..

	//고민을 했는대 ctime에 헤더파일중에 time이란 함수가
	//현재시각을 초로 환산한 값을 반환해주는 함수가 있내?



	srand((int)time(nullptr));
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;
	cout << "난수 : " << rand() << endl;

	//okok 아니 난수 막 무지막지한대 좀 범위를 줄이면 안될까?
	// 디폴트 : 0~32767 이라내
	// 나머지 연산자를 활용해서 0~99 0~9 이런식으로 줄여볼까?

	cout << "난수 : " << rand()%10 << endl;
	cout << "난수 : " << rand()%10 << endl;
	cout << "난수 : " << rand()%10 << endl;
	cout << "난수 : " << rand()%10 << endl;
	cout << "난수 : " << rand()%10 << endl;
	cout << "난수 : " << rand()%10 << endl;
	cout << "난수 : " << rand()%10 << endl;
	cout << "난수 : " << rand()%10 << endl;
	//문제가 있지 32767 이라매 그럼 0~67이 나올 확률이 68~99까지 보다 높내?
	//ㅅㅂ 이게 어떠캐 난수....
	//이렇게 난수 프로그램 하는애들 있는대 이러면 비웃어 줍시다.



	//이건 이제 구닥다리 식....
	//신새대 식 
	//random 헤더파일 지원 


	//시드값을 얻기위한 random_device 생성
	random_device rd;

	//random device를 통해 난수생성 엔진을 초기화 합니다
	mt19937 gen(rd());

	// 0~99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의
	uniform_int_distribution<int> dis(0, 99);
	//uniform distibution = 균등분포
	//		int          <int> = 정수 균등 분포 
	//							dis(범위)
	for (int i = 0; i < 5; i++)
	{
		cout << "난수 : " << dis(gen) << endl;
	}


	// 조금... 교양?

	random_device rd_n;
	mt19937 gen_1(rd_n());
	normal_distribution<double> dist(/*평균 : */0, /*표준 편차*/ 1);

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

	//뭔가 정규분포 같죵? 필요하면 복붙 하세용 




	return 0;
}