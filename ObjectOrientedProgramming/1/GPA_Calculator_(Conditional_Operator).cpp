#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv)
{  
/* 제출 시에는 line 8~12의 주석 처리를 해제해주세요. */
   char OOP= argv[1][0];
   char ComputerProgramming= argv[2][0];
   char DiscreteMathematics= argv[3][0]; 
   char LogicCircuitDesign= argv[4][0];
   char HolisticEducatiosnI= argv[5][0];
   
/* 제출 시에는 line 14~18를 주석 처리해주세요. 
  char OOP= 'A';
  char ComputerProgramming= 'B';
  char DiscreteMathematics= 'A'; 
  char LogicCircuitDesign= 'C';
  char HolisticEducationI= 'P'; */
  
  double result = 0.0;
  
  /* Put your code here */
char score_char; // 문자형 자료형 score_char에 학점을 입력받습니다.
int number_of_class = 0; // 정수형 자료형 number_of_class에 평균 계산에 쓰일 과목 갯수를 저장합니다.
double score = 0; // 실수형 자료형 score에 점수를 다 저장합니다,
double compare_score; // 점수가 추가되었는지 확인하는 변수입니다.

int n = 1; //
while (n <= 5) // 당연히 반복문을 써야겠죠...?
{
    score_char = argv[n++][0]; // score_char에 argv[n][0]을 하고  연산 후 n을 더합니다.
    compare_score = score;
    score += score_char == 'A'? 4.0 : 0.0;
    score += score_char == 'B'? 3.0 : 0.0;
    score += score_char == 'C'? 2.0 : 0.0;
    score += score_char == 'D'? 1.0 : 0.0;
    if (score != compare_score)
    {
        number_of_class++;
    }
    if (score_char == 'F')
        number_of_class++;
}
result = score / number_of_class; // resylt를 좌측과 같이 정의합니다.
cout<<result<<endl; // result를 출력합니다.
return 0;
}