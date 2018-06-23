#include <iostream>
#include <cstdlib>
using namespace std;


int main(int argc, char** argv)
{  
/* 제출 시에는 line 8의 주석 처리를 해제해주세요. */
  int n = atoi(argv[1]); 
  
/* 제출 시에는 line 11을 주석 처리해주세요. */
    //int n = 1;
  
  
  /* Put your code here */
    long f_n = 1, f_n1 = 1, f_n2 = 1; // 일단 뒤의 연산을 위해 일반항을 모두 1로 선언합니다.

    if (n == 1 or n == 2)
        cout<<1<<endl;

    else if (n >= 3)
    {
        for(int i = 0; i < n - 2;i++) { // 여기서 의미없는 2번째 항까지는 제외해주는 것이 옳습니다.
            f_n2 = f_n1;
            f_n1 = f_n;
            f_n = f_n1 + f_n2;
        }
        cout<<f_n<<endl; 
    }
    
    return 0;
}