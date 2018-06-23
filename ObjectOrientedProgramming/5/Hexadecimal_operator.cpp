#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;


class Calculator {
    private:
        int dec;
    public:
        Calculator();
        void setNum(char arr[], int size);
        void setNum(int num);
        // private 내의 dec을 반환하는 int형 함수 return_dec을 정의합니다.
        int return_dec();
        friend const Calculator operator+(const Calculator& ref1, const Calculator& ref2);
        friend const Calculator operator-(const Calculator& ref1, const Calculator& ref2);
        friend const bool operator>(const Calculator& ref1, const Calculator& ref2);
        friend const bool operator<(const Calculator& ref1, const Calculator& ref2);
        friend const bool operator==(const Calculator& ref1, const Calculator& ref2);
        friend ostream& operator<<(ostream & outputStream, const Calculator& ref);
};

bool hexonly(char hex[], int array_length) {
    /* char형 배열 hex가 '0'에서 '9'(닫힌 구간 p)또는 'A'에서 'F'(닫힌 구간 q)사이의 문자로만 이루어져있는지
        판별하는 bool형 함수입니다. 아래의 for문을 보시면 p 또는 q 구간의 여집합인 ~p 그리고 ~q에서 정의될 경우
        inner_bool에 false를 대입한 후 for문을 탈출합니다.
        for문을 끝까지 통과했다면 inner_bool의 초기값인 true를 반환합니다.*/
    bool inner_bool = true;
    for(int i = 0; i < array_length; i++) {
        if (!('0' <= hex[i] and hex[i] <= '9') and !('A' <= hex[i] and hex[i] <= 'F')) {
            inner_bool = false;
            break;
        }
    }
    return inner_bool;
}

void case1() {
    /* 16진수를 입력받는 크기가 10인 문자형 배열 hex1, hex2와
        입력받는 문자열의 길이를 나타낼 정수 array_length_1, array_length_2를
        생성합니다. */
    char hex1[10], hex2[10];
    int array_length_1, array_length_2;

    cout<<"Welcome to hexadecimal calculator!"<<endl;
    cout<<endl;
    cout<<endl;

    // while (true)를 이용하여 hexonly를 통과한 경우에만 종료가 됩니다.
    while (true) {
        cout<<"Input num1: ";
        cin>>hex1;
        array_length_1 = strlen(hex1);
        if (hexonly(hex1, array_length_1)) {
            break;
        }
        else{
            cout<<"Wrong Input!"<<endl;
        }
    }
    while (true) {
        cout<<"Input num2: ";
        cin>>hex2;
        array_length_2 = strlen(hex2);
        if (hexonly(hex2, array_length_2)) {
            break;
        }
        else{
            cout<<"Wrong Input!"<<endl;
        }
    }

    /* Object Calcuator의 instance인 cal1, cal2를 생성한 후
        생성자의 조건에 맞게 16진수 배열(hex)과 배열의 길이(array_length)를 전달인자에 넣습니다.*/
    Calculator cal1, cal2;
    cal1.setNum(hex1, array_length_1);
    cal2.setNum(hex2, array_length_2);

    cout<<endl;
    cout<<endl;

    cout<<"1. num1 + num2: "<<cal1 + cal2<<endl;
    cout<<"2. num2 - num1: "<<cal2 - cal1<<endl;

    cout<<"3. num1 == num2: ";
    if (cal1 == cal2) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }

    cout<<"4. num1 > num2: ";
    if (cal1 > cal2) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }

    cout<<"5. num1 < num2: ";
    if (cal1 < cal2) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }

    cout<<"6. num1: "<<hex1<<" num2: "<<hex2<<endl;

    cout<<endl;
    cout<<endl;
}


int main()  
{
    char option;
    while (true) {
        cout<<"===============Menu==============="<<endl;
        cout<<"1:Program start 0:program End"<<endl;
        cout<<"Menu Option: ";
        cin>>option;
        switch(option) {
            case '0':
                return 0;
            case '1':
                case1();
                break;
            default:
                cout<<"Please input correct charecter."<<endl;
                continue;
        }
    }
}

Calculator::Calculator() {}

void Calculator::setNum(char arr[], int size) {
    /*  닫힌 구간 p에 있는 문자형에 대하여 '0'을 빼준 값을 innder_dec에 대입합니다.
        닫힌 구간 q에 있는 문자형의 경우에는 'A'를 뺀 값에 10을 더하여 innder_dec에 대입합니다.
        이 innder_dec 값에 pow함수를 이용하여 16의 (size - i - 1)제곱한 값을 곱하여
        dec에 더합니다. */
    dec = 0;
    for(int i = 0 ; i < size; i++) {
        int inner_dec;
        if ('0' <= arr[i] and arr[i] <= '9') {
            inner_dec = arr[i] - '0';
        } 
        else if ('A' <= arr[i] and arr[i] <= 'F') {
            inner_dec = 10 + arr[i] - 'A';
        }
        dec += inner_dec * pow(16, size - i - 1);
    }
}

void Calculator::setNum(int num) {
    /* setNum의 또다른 오버로딩 함수입니다.*/
    dec = num;
}

int Calculator::return_dec() {
    return dec; 
}
const Calculator operator+(const Calculator& ref1, const Calculator& ref2) {
    Calculator cal;
    cal.setNum(ref1.dec + ref2.dec);
    return cal;
}

const Calculator operator-(const Calculator& ref1, const Calculator& ref2) {
    Calculator cal;
    cal.setNum(ref1.dec - ref2.dec);
    return cal;
}

const bool operator>(const Calculator& ref1, const Calculator& ref2) {
    return ref1.dec > ref2.dec;
}

const bool operator<(const Calculator& ref1, const Calculator& ref2) {
    return ref1.dec < ref2.dec;
}

const bool operator==(const Calculator& ref1, const Calculator& ref2) {
    return ref1.dec == ref2.dec;
}

ostream& operator<<(ostream& outputStream, const Calculator& ref) {
    // 16진수를 저장할 길이가 10인 hex 배열을 0으로 초기화해줍니다.
    char hex[10] = {0};
    int dec = ref.dec;
    /* 배열의 길이가 10이므로 (사실은 상관없음) 0이상 10미만의 정수를 hex의 i번째 원소로 돌려서
        만약 0이상 10 미만이라면 '0'에 16을 나눈 나머지를 더한 값,
        10이상 16미만이라면 'A'에 16을 나눈 나머지를 더한 후 10을 빼준 값을 저장합니다.
        그리고 dec의 자릿수를 낮춰가면서 결국 0이 되어버리면 for문은 종료됩니다.*/
    for(int i = 0; i < 10; i++) {
        int rem = dec % 16;
        if (0 <= rem and rem < 10) {
            hex[i] = '0' + rem;
        }
        else if (10 <= rem and rem < 16) {
            hex[i] = 'A' + rem - 10;
        }
        dec /= 16;
        if (dec== 0) {
            break;
        }
    }

    /* 사실 위의 코드에서는 일의 자리부터 거꾸로 했으므로 배열을 다시 올바른 순서로 뒤집어줍니다.*/
    int array_length = strlen(hex);
    for(int i = 0; i < array_length; i++) {
        outputStream<<hex[array_length - i - 1];
    }

    return outputStream;
}