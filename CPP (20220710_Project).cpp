// c++로 떠나는 모험.
//1 차시. 입출력과 변수의 선언및 초기화
//  + 조건문 반복문
// 
//
// 
// 변수 : Data를 담는 공간 , 주소(address, location)+ 값(value) (L_value) <- Location value
//      -> 타입 : int(4) longlong(8)  float(8) -> double(8) unsigned int(4)-> 수의 범위는 같지만, 최댓값이 2배
//              : class 타입(변수와 함수들의 모임), point(다른 변수의 주소를 값으로 가지는) 타입도 있다.
//              : auto 타입 <- 나중에 설명해드릴게
// 
//상수 : 데이터의 값, 주소의 값, 혹은 그냥 숫자들 (R_value) <- Read only!! 



//int nData_C = 10; // C언어의 스타일
//int nData_CPP(10); // C++의 스타일
//
//double nDataF_C = 10;
//double nDataF_CPP(nDataF_C); // 이런식으로도 가능 -> nDataF_CPP = nDataF_C 랑 같은말
//
//for (int i = 0; i < 10; i++) // for(int i=0 <-이친구를이용해 반복문을 정의할거야 ; i<10 <- 조건 ; i++ 후속작업) 
//{
//    std::cout << "반복횟수 : " << i + 1 << std::endl;
//    // std::cout : 
//    // std : namespace : 가문 , 소속
//    // :: 스코프 연산자 ->  std의 가문의 cout을 호출하겠다 뭐 이런식
//    // cout console out 이라는 printf 보다 성능이 좋다 -> " %d ",a 이런식으로 안하고 그냥 형을 맞쳐줌 
//    // endl <- 엔드라인 print의 끝이다 뭐 이런느낌문장끝에 \n 대신 쳐주는 느낌.
//    // << 이거는... 그냥 나중에 설명 //그냥 외우는 방법도 있음.
//}


//
// Y=F(x) F(2)
// 반환값 : F(x)의 결과물 이후에 Y라는 변수에 대입시켜줘야한다.
//  F => 함수이름
//  X -> 인자값(Param) -> 연습할때 유명한 책들에서 
//   -> 함수를 실행기키기위한 재료들. 
//
//
//  그런거 니가 리신 = 피넛 리신.
//      말하기가 조금 모르겠어. 
//      프레임 생성 <- 자료구조 
//      익덱싱 <- ㅈ밥
//      수학계산 <- 수학을잘하자.
//       
//
#include <iostream>
#include<string>



using namespace std; // std가문애들은 생략하겠다.


void Start_Func(string mon, int Answer)
{
    while (1)
    {
        cout << "전방에" << mon << "가 있습니다 싸우시겠습니까 ? (Y = 1 / N = 2)" << endl;
        cin >> Answer;
        if (Answer == 1)
        {
            break;
        }
        else
        {
            cout << " 도망칠 수 없다!" << endl;
        }
    }
}

struct Play
{
    string Name;
    int HP;
    int Damage;
    double Speed;
    int Level;
    int Exp;
}; //구조체 : 변수들의 모임 . 


struct Monster
{
    string Name;
    int HP;
    int Damage;
    double Speed;

};

int Rest_HP(string player, string mon, int HP, int Damage)
{
    cout << mon << " 의 공격 !" << endl;
    HP -= Damage;
    if (HP < 0)
    {
        HP = 0;
    }
    cout << player <<" 남은 HP : " << HP << endl;

    return HP;
}


//게임을 하기 앞서 뭐먼저 해야하지? 로그인
int main()
{

    int Player_ID,Player_Password;
    cout << " Player_ID를 입력하시오 :  " << endl;
    cin >> Player_ID;
    int Answer_IN(2);
    int Player_Do;//변수의 선언
            cout << "확인되었습니다 캐릭터를 생성합니다 " << endl;

            // 로그인 완료

            string Player_Name;
            cin >> Player_Name;

            unsigned int Player_HP(100);// 변수의 선언 및 초기화
            int Player_Demege(10);
            double Player_Speed(5);

            cout << "당신의 캐릭터의 이름은 :" << Player_Name << "\n당신의 캐릭터의 HP,DEMEGE,SPEED는 각각 " << Player_Demege <<", "<< Player_HP <<", "<<Player_Speed <<"입니다"<< endl;

           

            string Computer_Mon("Hotdog");
            unsigned int Hotdog_HP(20);
            int Hotdog_Damage(3);
            const double Hotdog_Speed(6); // 상수화 시킨다 = 쓸수가 없다 = 읽기전용 
            

            
                    while(Player_HP ==0||Hotdog_HP==0)
                    {
                        cout << "전투가 시작되었다." << endl;
                        if (Hotdog_Speed >= Player_Speed)
                        {
                            Player_HP = Rest_HP(Player_Name, Computer_Mon, Player_HP, Hotdog_Damage);

                            cout << "어떤 행동을 하시겠습니까? : 1. 공격" << endl;
                            cin >> Player_Do;

                            if (Player_Do == 1)
                            {
                                Hotdog_HP = Rest_HP(Computer_Mon, Player_Name, Hotdog_HP, Player_Demege);
                            }
                        }
                    }
                    
                    cout << "HotDog가 도망쳤다! 전투를종료합니다." << endl;


                    Play Player = { Player_Name ,100,10,10.1,1,0 };
                    Monster Van;
                    Van.Name = "VanDark";
                    Van.Damage = 10;
                    Van.HP = 30;
                    Van.Speed = 10.2;

                    Monster Pig = { "Pig",30,10,10 };

                    while (Van.HP==0||Player.HP==0)
                    {
                        cout << "전투가 시작되었다." << endl;
                        if (Van.Speed >= Player.Speed)
                        {
                            Player.HP = Rest_HP(Player.Name, Van.Name, Player.HP, Van.Damage);

                            cout << "어떤 행동을 하시겠습니까? : 1. 공격" << endl;
                            cin >> Player_Do;

                            if (Player_Do == 1)
                            {
                                Van.HP = Rest_HP(Van.Name, Player.Name, Van.HP, Player.Damage);
                            }
                        }

                    }


                    return 0;

}




            







































