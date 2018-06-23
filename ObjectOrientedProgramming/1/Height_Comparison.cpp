#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv)
{  
/* 제출 시에는 line 8~10의 주석 처리를 해제해주세요. */
   double A = stod(argv[1]);
   double B = stod(argv[2]);
   double C = stod(argv[3]); 
/* 제출 시에는 line 12~14를 주석 처리해주세요. 
  double A = 172.8;
  double B = 172.9;
  double C = 181.3; */
  
  
  /* Put your code here */
/* 큰 따옴표 내부에 식을 출력해야 하므로 모든 경우를 고려했습니다. */
if (A == B and B == C and C == A)
{
    cout<<"\"A = B = C\""<<endl;
}

else if (A == B and B > C)
{
    cout<<"\"A = B > C\""<<endl;
}
else if (A == C and C > B)
{
    cout<<"\"A = C > B\""<<endl;
}
else if (B == C and C > A)
{
    cout<<"\"B = C > A\""<<endl;
}

else if (A > B and B == C)
{
    cout<<"\"A > B = C\""<<endl;
}
else if (B > A and A == C)
{
    cout<<"\"B > A = C\""<<endl;
}
else if (C > A and A == B)
{
    cout<<"\"C > A = B\""<<endl;
}

else if (A > B and B > C)
{
    cout<<"\"A > B > C\""<<endl;
}
else if (A > C and C > B)
{
    cout<<"\"A > C > B\""<<endl;
}
else if (B > A and A > C)
{
    cout<<"\"B > A > C\""<<endl;
}
else if (B > C and C > A)
{
    cout<<"\"B > C > A\""<<endl;
}
else if (C > A and A > B)
{
    cout<<"\"C > A > B\""<<endl;
}
else if (C > B and B > A)
{
    cout<<"\"C > B > A\""<<endl;
}

  return 0;
}