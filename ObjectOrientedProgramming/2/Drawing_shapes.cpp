#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv)
{  
/* 제출 시에는 line 8의 주석 처리를 해제해주세요. */
  int shape = atoi(argv[1]); 
  
/* 제출 시에는 line 11을 주석 처리해주세요. */
// int shape = 2;
char star = '*', space = ' ';
switch(shape)
{
  
/* Put your code here */
    case 1:
        for(int i = 0; i < 5; i++) // 정수 i를 선언한 후, for 문을 이용하여 5행을 만들도록 합니다.
        {
            for(int j = 0; j < 9; j++) // 정수 j를 선언한 후, for 문을 이용하여 9열을 만들도록 합니다.
            {
             cout<<star;
            }
            if (i != 4);
            {
                cout<<"\n";
            }
        }
    break;

    case 2:
        for(int i = 0; i < 5; i++) // 정수 i를 선언한 후, for 문을 이용하여 5행을 만들도록 합니다.
        {
            for (int k = 0; k < 4 - i; k++) // 4 - i의 규칙에 따라 공백을 만듭니다.
            {
                cout<<space;
            }
            for (int k = 0; k < 2 * i + 1; k++) // 2 * i + 1의 규칙에 따라 별을 그립니다.
            {
                cout<<star;
            }
            for (int k = 0; k < 4 - i; k++) // 4 - i의 규칙에 따라 공백을 만듭니다.
            {
                cout<<space;
            }
            if (i != 4);
            {
                cout<<"\n";
            }
        }
    break;

    case 3:
        for(int i = 0; i < 5; i++) // 정수 i를 선언한 후, for 문을 이용하여 5행을 만들도록 합니다.
        {
            for (int k = 0; k < i; k++) // i의 규칙에 따라 공백을 만듭니다.
            {
                cout<<space;
            }
            for (int k = 0; k < 9 - 2 * i; k++) // 9 - 2 * i의 규칙에 따라 별을 그립니다.
            {
                cout<<star;
            }
            for (int k = 0; k < i; k++) // i의 규칙에 따라 공백을 만듭니다.
            {
                cout<<space;
            }
            if (i != 4);
            {
                cout<<"\n";
            }
        }
        break;

    case 4:
        for(int i = 0; i < 2; i++) // 정수 i를 선언한 후, for 문을 이용하여 2행을 만들도록 합니다.
        {
            for (int j = 0; j < 2; j++) // 정수 j를 선언한 후, for 문을 이용하여 2열의 별을 그립니다.
            {
                cout<<star;
            }
            for (int j = 0; j < 5; j++) // 정수 j를 선언한 후, for 문을 이용하여 5열의 공백을 그립니다.
            {
                cout<<space;
            }
            for (int j = 0; j < 2; j++) // 정수 j를 선언한 후, for 문을 이용하여 2열의 별을 그립니다.
            {
                cout<<star;
            }
            cout<<"\n"; 
        }
        for (int j = 0; j < 9; j++) // i의 규칙에 따라 별을 그립니다.
        {
            cout<<star;
        }
        cout<<"\n"; \
        for(int i = 0; i < 2; i++) 
        {
            for (int j = 0; j < 2; j++)
            {
                cout<<star;
            }
            for (int j = 0; j < 5; j++)
            {
                cout<<space;
            }
            for (int j = 0; j < 2; j++)
            {
                cout<<star;
            }
            cout<<"\n"; 
        }
        cout<<"\n";
    break;
}
  
return 0;
}