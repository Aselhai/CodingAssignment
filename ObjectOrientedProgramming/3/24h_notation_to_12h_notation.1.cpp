#include <iostream>
#include <cstdlib>  
#include <cstring>

using namespace std;

void conv_time(int &hh, int &mm, char &a_p, char time_input[]) {
  hh = atoi(&time_input[0]); // atoi 함수를 이용하여 char에서 int를 추출합니다.
  mm = atoi(&time_input[3]);

  if (hh == 24 or hh == 0) {
    hh = 0; // 0과 24의 특수한 경우에는 hh를 0으로 반환합니다.
    a_p = 'A';
  }
  else if (hh == 12) {
    a_p = 'P'; // 12의 특수한 경우에는 무조건 P로 바꿉니다.
  }
  else if (hh > 12) {
    hh -= 12; // 나머지 12를 넘는 정수에 대해서는 12를 뺀후 P로 바꿔줍니다.
    a_p = 'P';
  }
  else {
    a_p = 'A'; // 나머지는 A!
  }
}

void print_time(int hh,int mm, char a_p) {
  // 특히 아래에서는 hh와 mm이 한 자리수인 경우를 생각해줍니다.
  if (hh < 10)
    if (mm < 10)
      cout<<"The time in 12-hour notation is 0"<<hh<<":0"<<mm<<' '<<a_p<<".M."<<endl;
    else
    cout<<"The time in 12-hour notation is 0"<<hh<<':'<<mm<<' '<<a_p<<".M."<<endl;
  else
  if (mm < 10)
    cout<<"The time in 12-hour notation is "<<hh<<":0"<<mm<<' '<<a_p<<".M."<<endl;
  else
    cout<<"The time in 12-hour notation is "<<hh<<':'<<mm<<' '<<a_p<<".M."<<endl;
}

int main(int argc, char** argv)
{ 
/* 제출 시에는 line 10의 주석 처리를 해제해주세요. */
  char time_input[6]; strcpy(time_input, argv[1]); 
/* 제출 시에는 line 12를 주석 처리해주세요. */
    // char time_input[6] = "24:00";
   /*아래는 수정하지 마세요.*/
  int hh, mm; char a_p;   
  conv_time(hh,mm, a_p, time_input);
  print_time(hh,mm, a_p);
  return 0;
}