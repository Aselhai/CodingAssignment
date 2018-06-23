// 이 코드에서 사용될 라이브러리를 호출합니다.
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

/* 이용자에게 이 프로그램을 간단히 설명한 후 option을 입력받는 welcome 함수입니다.
  문장의 변경을 고려하여 main함수 내부가 아닌 int형 함수로 따로 처리하였습니다.*/
void welcome() {
  cout<<"*Options"<<endl;
  cout<<"(1-Secure password checker, 0-End the program)"<<endl;
  cout<<"Choose the option >> ";
}

/* actual password를 입력받는 input_actual 함수입니다.
  특히, 10000 미만의 정수 또는 100000 이상의 정수 즉 다섯 자리의 정수가 아니라면 다시
  입력받도록 요구합니다. 이는 정수가 아닌 다른 자료형까지 처리할 수 있을 것입니다.*/
int input_actual() {
  string input_password; // 우선 input_password를 string 자료형으로 받습니다.

  cout<<"Input an actual password = ";
  cin>>input_password;
  
  int int_password = atoi(input_password.c_str()); // 이후 string 자료형을 int 자료형으로 변환하면서 문자열이라면 0으로 바뀔 것입니다.

  // 다섯 자리가 아니라면 while로 집요하게 물을 것입니다.
  while ((10000 > int_password) or (int_password >= 100000)) { 
    cout<<"Please input an correct actual password form = ";
    cin.clear();
    cin>>input_password;
    int_password = atoi(input_password.c_str());
  }

  cout<<endl;
  return int_password;
}

/* 크기가 10인 정수형 배열에 rand 함수를 이용하여 1부터 3까지의 정수를 무작위로 지정합니다.
  이후 설명과 같이 'NUM : ' 이후 배열의 모든 원소를 출력합니다.
  마지막으로 정답인 answer를 call-by-reference를 이용하여 지정해줍니다.*/
void random_table_and_randomized(int actual_password, int& answer) {
  int num[10] = {0};

  for(int i = 0; i < 10; i++) { // 1부터 3까지의 정수를 무작위로 지정해줍니다.
    num[i] = rand() % 3 + 1;
  }

  cout<<"Random number table"<<endl;
  cout<<"PIN : 0 1 2 3 4 5 6 7 8 9"<<endl;
  cout<<"NUM : ";
  for (int i = 0; i<10; i++) { // 배열 num의 원소들을 출력해줍니다.
    if (i == 9)
      cout<<num[i]<<endl;
    else
      cout<<num[i]<<' ';
  }
  /* 다음은 actual_password의 자리에 따른 숫자를 num의 몇 번째 원소로 인식하는 것입니다.
    우선, actual_password를 10으로 나눈 나머지는 1의 자리가 될 것입니다.
    이를 for문을 이용하여 10의 i(=0)제곱으로 곱해줍니다.
    그리고 10으로 나누어주어 actual_password의 일의 자리를 날립니다.
    이렇게 반복하여 더하면 answer가 나옵니다. */
  // int a1 = 0, a2 =0, a
  for(int i = 0; i < 5; i++) {
    int mul = 1;
    for(int j = 0; j < i; j++)
      mul *= 10;
    answer += mul * num[actual_password % 10];
    actual_password /= 10;
  }
}

int main() {
  /* example에서는 계속 0 또는 1로 option을 선택하여 계속 진행할 수 있도록
    하는 것 같아서 while (true)를 이용한 후 0을 입력받으면
    break를 이용하여 while문을 탈출하도록 하였습니다.*/
  while (true) {
    string option = "2"; // 순수하게 입력 값 자체를 판단하기 위하여 string 자료형을 사용하였습니다.

    welcome();
    cin.clear();
    cin>>option;
    
    while (option != "0" and option != "1") { // "0"도 아니고 "1"도 아니라면 재입력받습니다.
        cout<<"Correct option please >> ";
        cin.clear();
        cin>>option;
    }

    if (option == "0") {
      cout<<"Exit the program."<<endl;
      break;
    }
    else if (option == "1") {
      int actual_password = input_actual(); // actual_password를 입력받습니다.
      int answer = 0;
          
      random_table_and_randomized(actual_password, answer);

      cout<<endl;

      /* 앞서 actual password와 같은 방식으로
        randomized password를 입력받습니다.*/
      string str_randomized_password;
      int randomized_password;
      cout<<"Input a randomized password = ";
      cin>>str_randomized_password;
      randomized_password = atoi(str_randomized_password.c_str());

      /* 아래의 while문 내부에는 if문을 이용하여 10000미만 또는 100000이상의 정수를
        입력하면 재입력을 요구합니다.
        더불어, if문을 벗어나면 또다시 0, 1, 2로만 구성되어있는지 검사합니다.*/
      bool finish = false;
      while (!finish) {
        if ((10000 > randomized_password) or (randomized_password >= 100000)) {
          cout<<"Please input an correct randomized password form = ";
          cin.clear();
          cin>>str_randomized_password;
          randomized_password = atoi(str_randomized_password.c_str());
        }
        else {
          int new_randomized = randomized_password;
          /* 아래의 반복문에서 만약 0 이하 또는 3 초과의 정수가 발견되면 재입력받고,
            for문을 탈출하여 다시 처음부터 시작합니다.
            만약, 1부터 3까지의 정수로만 이루어졌다면 finish는 true가 되어
            반복문을 탈출합니다. */
          for(int i = 0; i < sizeof(new_randomized); i++) {
            if (0 >= (new_randomized % 10) or (new_randomized % 10) > 3) {
              cout<<"Please input an correct randomized password form = ";
              cin.clear();
              cin>>str_randomized_password;
              randomized_password = atoi(str_randomized_password.c_str());
              finish = false;
              break;
            }
            else {
              new_randomized /=  10;
              finish = true;
            }
          if (finish == true) {
            break;
          }
          }
        }
      }
      
      
      /*if문을 이용하여 입력받은 randomized_password와 정답이 일치하면
      Correct Password!를 틀리다면 Incorrect password...를 출력합니다.*/
      if (answer == randomized_password) {
        cout<<endl;
        cout<<"Correct Password!"<<endl;
        cout<<"You are so smart, Toyo...";
        cout<<endl;
      }
      else if (answer != randomized_password) {
        cout<<endl;
        cout<<"Incorrect Password..."<<endl;
        cout<<"The answer is '"<<answer<<"'."<<endl;
        cout<<endl;
      }
    }
    cout<<"------------------------"<<endl;
  }
  return 0;
}