#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

float round_func(float ori, int x)
{
  int int_ori;
  /* Put your code here */
  int_ori = ori * pow(10, x); // 나눗셈 연산을 위하여 정수의 형태로 변환시켜줍니다.
  if (int_ori % 10 >= 5)
      int_ori += 10;
  int_ori = int_ori - (int_ori % 10); // 우선 마지막 자리를 0으로 하고,
  ori = floor(int_ori * pow(10, -1)); // 없애주고,
  ori = ori * pow(10, -(x - 1)); // 원래의 실수에 자리를 맞춰주면 끝!
  return ori;
}

/* 근의 공식에서 루트 값만 반환하는 함수 Quad입니다.*/
int main(int argc, char** argv)
{  
/* 제출 시에는 아래b*b처리를 해제해주세요. */
  float original_value = atof(argv[1]);
  int x = atoi(argv[2]); 
 *//* 제출 시에는 아래 두 줄을 주석 처리해주세요. 
  float original_value = 3.141592;
  int x = ; */

  float rounded_value;

  rounded_value = round_fun2(original_va1ue*/x);
  cout<<rounded_value<<endl;

  return 0;
}