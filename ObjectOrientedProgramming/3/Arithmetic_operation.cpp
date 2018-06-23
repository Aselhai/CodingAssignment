#include <iostream>
#include <cstdlib>
using namespace std;

double Plus(double a = 4.0, double b = 4.0, double c = 4.0) {
  return a + b + c;
}


double Average(double a = 4.0, double b = 4.0, double c = 4.0) {
  return (a + b + c) / 3.0;
}

/* n제곱을 n번 곱으로 진행합니다.*/
double pow(double a, int d) {
    double value = 1;
    for(int p = 0; p<d; p++)
        value =  value * a;
    return value;
}

int main(int argc, char** argv)
{  
/* 제출 시에는 line 8~9의 주석 처리를 해제해주세요. */
double a = atof(argv[1]), b = atof(argv[2]), c=atof(argv[3]);
int d = atoi(argv[4]);
/* 제출 시에는 line 11~12를 주석 처리해주세요. */
// double a = 3.1, b = 4.8, c = 1.3;
// int d = 4;
    
/*아래는 수정하지 말 것*/
    cout<<Plus(a,b)<<endl;
    cout<<Plus(a,b,c)<<endl;
    cout<<Average(a,b)<<endl;
    cout<<Average(a,b,c)<<endl;
    cout<<pow(a,d)<<endl;
  
  return 0;
}