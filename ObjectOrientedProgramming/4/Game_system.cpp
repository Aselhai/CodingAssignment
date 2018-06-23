#include <iostream>
using namespace std;

class User
{
public:

/* Put your code here*/
    void set(int input_oil, int input_money) {
        oilGauge = input_oil;
        money = input_money;
    }

    /* faster 함수에서는 oilGauge가 5 미만이라면 no oil을 출력하고,
        아니라면 oilGuage에서 5를 뺀 후, velocity에 5를 더하였습니다.
        cheat(?)를 방지하기 위하여 oilGauge를 velocity보다 먼저 코딩하였습니다.*/
    void faster() {
        if (oilGauge < 5) {
            cout<<"no oil"<<endl;
        }
        else {
            oilGauge -= 5;
            velocity += 5;
        }
    }

    /* 아래는 faster과 유사합니다. */
    void charge(int input_charge) {
        if (money <= 0) {
            cout<<"no money"<<endl;
        }
        else {
            money -= (input_charge * 10);
            oilGauge += input_charge;
        }
    }

    void insertMoney(int input_Money) {
        money += input_Money;
    }

    void slower() {
        velocity -= 5;
        if (velocity <= 0) {
            velocity = 0;
        } 
    }

    int getVel() {
        return velocity;
    }

    int getOil() {
        return oilGauge;
    }

    int getMoney() {
        return money;
    }
private:
    int oilGauge;
    int money;
    int velocity;
};

int main(int argc, char** argv)
{  
    /* 제출 시에는 아래 두 줄의 주석 처리를 해제해주세요. */
    int a = atoi(argv[1]), b = atoi(argv[2]), c = atoi(argv[3]), d = atoi(argv[4]), e = atoi(argv[5]);

    /* 제출 시에는 아래 두 줄을 주석 처리해주세요. */
    // int a=10, b=100, c=20, d=10, e=200;
        
    // Generate object.
    User cary;
    cary.set(a, b); 

    // Speed up!
    cary.faster();
    cary.faster();
    cout<<"CurrentVel : "<<cary.getVel()<<endl;
    cout<<"CurrentOil : "<<cary.getOil()<<endl;
    cout<<"CurrentMoney : "<<cary.getMoney()<<endl<<endl;

    // Fill up the oil!
    cary.faster();
    cary.charge(c);
    cary.charge(d);
    cout<<"CurrentVel : "<<cary.getVel()<<endl;
    cout<<"CurrentOil : "<<cary.getOil()<<endl;
    cout<<"CurrentMoney : "<<cary.getMoney()<<endl<<endl;

    // Charge a game money!
    cary.insertMoney(e);
    cout<<"CurrentMoney : "<<cary.getMoney()<<endl<<endl;

    // Slow down!
    cary.slower();
    cary.slower();
    cout<<"CurrentVel : "<<cary.getVel()<<endl;

    cary.slower();
    cout<<"CurrentVel : "<<cary.getVel()<<endl<<endl;

    return 0;
}