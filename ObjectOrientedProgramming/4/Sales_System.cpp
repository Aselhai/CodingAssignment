#include <iostream>
using namespace std;

class Seller {
    public:
    /* Put your code here*/
        void set(int input_money, int input_pencil, int input_note) {
            money = input_money;
            pencil = input_pencil;
            note = input_note;
        }
        /* 입력받은 money, pencil, note만큼 더하는 함수 control입니다.
            음의 정수를 입력할 경우 뺄셈도 가능하며, 주로 Buyer class에서
            호출될 예정입니다. */
        void control(int input_money, int input_pencil, int input_note) {
            money += input_money;
            pencil += input_pencil;
            note += input_note;
        }

        int getMoney() {
            return money;
        }

        int getPencil() {
            return pencil;
        }

        int getNote() {
            return note;
        }

    private:
        int money, pencil, note;
};

class Buyer {
    public:

    /* Put your code here*/
        void set(int input_money) {
            money = input_money;
            pencil = 0;
            note = 0;
        }

        /* Seller class의 instance를 seller_name이라는 이름으로 받습니다.
            seller_name.control 함수로 class에 접근합니다.*/
        void buyPencil(Seller &seller_name, int input_pencil) {
            if (seller_name.getPencil() < input_pencil) {
                cout<<"seller has not enough items"<<endl;
            }
            else if (money < input_pencil*100) {
                cout<<"buyer has not enough money"<<endl;
            }
            else {
                money -= input_pencil*100;
                pencil += input_pencil;

                seller_name.control(input_pencil*100, -(input_pencil), 0);
            }
        }

        void buyNote(Seller &seller_name, int input_note) {
            if (seller_name.getNote() < input_note) {
                cout<<"seller has not enough items"<<endl;
            }
            else if (money < input_note*150) {
                cout<<"buyer has not enough money"<<endl;
            }
            else {
                money -= input_note*150;
                note += input_note;

                seller_name.control(input_note*150, 0, -(input_note));
            }
        }

        int getMoney() {
            return money;
        }

        int getPencil() {
            return pencil;
        }

        int getNote() {
            return note;
        }

    private:
        int money, pencil, note;
};

int main(int argc, char** argv)
{
    
    /* 제출 시에는 아래의 주석 처리를 해제해주세요. */
    int a = atoi(argv[1]), b = atoi(argv[2]), c = atoi(argv[3]), d = atoi(argv[4]), e = atoi(argv[5]), f = atoi(argv[6]), g = atoi(argv[7]), h = atoi(argv[8]);
    
    /* 제출 시에는 아래를 주석 처리해주세요. */
    // int a=1000, b=10, c=2, d=700, e=2, f=2, g=3, h=1;
    
    Seller seller_;
    seller_.set(a,b,c);
    Buyer buyer_;
    buyer_.set(d);
    
    buyer_.buyPencil(seller_, e);
    buyer_.buyNote(seller_, f);
    
    cout<<"seller_pencil : "<<seller_.getPencil()<<endl;
    cout<<"seller_note : "<<seller_.getNote()<<endl;
    cout<<"seller_money : "<<seller_.getMoney()<<endl;
    cout<<"buyer_pencil : "<<buyer_.getPencil()<<endl;
    cout<<"buyer_note : "<<buyer_.getNote()<<endl;
    cout<<"buyer_money : "<<buyer_.getMoney()<<endl<<endl;
    
    buyer_.buyPencil(seller_, g);
    buyer_.buyNote(seller_, h);
    
    cout<<"seller_pencil : "<<seller_.getPencil()<<endl;
    cout<<"seller_note : "<<seller_.getNote()<<endl;
    cout<<"seller_money : "<<seller_.getMoney()<<endl;
    cout<<"buyer_pencil : "<<buyer_.getPencil()<<endl;
    cout<<"buyer_note : "<<buyer_.getNote()<<endl;
    cout<<"buyer_money : "<<buyer_.getMoney()<<endl<<endl;
    
    return 0;
}