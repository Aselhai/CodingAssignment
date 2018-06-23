#include <iostream>
using namespace std;

/* 특별히 주석을 달 것이 없습니다. set 함수에서 private의 x, y 값을 지정하고,
    Current 함수는 그저 x, y를 return합니다. */
class Vector
{
public:
    /*Put your code here*/
    void set(int input_x, int input_y) {
        x = input_x;
        y = input_y;
    }
    void AddVector(int input_x, int input_y) {
        x += input_x;
        y += input_y;
    }
    void MulVector(int input) {
        x *= input;
        y *= input;
    }
    int xCurrent(){
        return x;
    }
    int yCurrent(){
        return y;
    }
private:
    int x, y;
};


int main(int argc, char** argv)
{  
    /* 제출 시에는 아래의 주석 처리를 해제해주세요. */
    int a = atoi(argv[1]), b = atoi(argv[2]), c = atoi(argv[3]), d = atoi(argv[4]), e = atoi(argv[5]);
    
    /* 제출 시에는 아래를 주석 처리해주세요. */
    // int a=2, b=3, c=-1, d=6, e=2;
        
    Vector vec1; // generate vec1
    vec1.set(a,b); // set x=a, y=b
    
    vec1.AddVector(c,d); // add vec1 to <c,d>
    cout<<vec1.xCurrent()<<','<<vec1.yCurrent()<<endl; // => 1,9
    
    vec1.MulVector(e); // multiply vec1 with e
    cout<<vec1.xCurrent()<<','<<vec1.yCurrent()<<endl; // => 2,18
    return 0;
}