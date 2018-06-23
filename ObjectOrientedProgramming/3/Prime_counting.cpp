#include <iostream>
#include <cstdlib>
using namespace std;
// 소수를 판단하는 determine_prime 함수입니다.
int determine_prime(int n) {
    bool inner_bool = false;
    
    if (n == 1) // 1은 소수도 합성수도 아니므로 0을 반환합니다.
        return 0;
    else if (n == 2) // 알고리즘이 2부터 나누어 나가므로 2는 1을 반환합니다.
        return 1;
    else {    // 아래는 정수 n에 대하여 2부터 n-1까지의 정수를 나누어 나누어 떨어진다면 inner_bool이 true가 되어 0을 반환하는 프로그램입니다.
        for(int div = 2; div < n; div++) {
            if( n % div == 0) 
                inner_bool = true;
            }
        if (inner_bool == true)
            return 0;
        else
            return 1;
        }
}

int prime_counting(int arr[]) {
    int many = 0;
    for(int i = 0; i < 10; i++) {
        many += determine_prime(arr[i]);
    }
    return many;
}

int main(int argc, char** argv)
{  
    int arr[10];
    /* 제출 시에는 line 8~10의 주석 처리를 해제해주세요. */
    for(int i = 0; i<10; i++){
        arr[i] = atoi(argv[i+1]);}
    /* 제출 시에는 line 12~14를 주석 처리해주세요. */
    // for(int i = 0; i<10; i++)
    //     arr[i] = i+1;

/*아래는 수정하지 말 것*/
    cout<<prime_counting(arr)<<endl;
    return 0;
}