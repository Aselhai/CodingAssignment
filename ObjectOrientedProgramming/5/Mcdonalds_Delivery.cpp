#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

class Account {
private:
        /* 밖에서 함부로 접근할 수 없도록 아이디, 비밀번호를 string형 배열인 id, pw,
            돈, 주문리스트, 가격을 int형 배열인 money, order, price에 각각 private 변수로 지정하였습니다.*/
        string id[100], pw[100];

        int money[100];
        int order[100][10];

        int price[10];

    public:
        Account();
        int store_index();
        bool check_id(string i_id);
        void add_account(string i_id, string i_pw, int i_money);
        void find_account(string i_id, string i_pw, bool &i_exist, int &i_index);
        void order_list (int index, int i_order[]);
        int control_money (int index, int price);
        int control_order (int index, int i, int count);
        void reset_order (int index, int i);
        int total_price (int i_order[]);
        int return_price (int index);
};

void welcome(char &option) {
    cout<<"----------------------------------"<<endl;
    cout<<"-----Mcdonalds Delivery System----"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<endl;
    cout<<"1. Sign up"<<endl;
    cout<<"2. Show Menu"<<endl;
    cout<<"3. Order"<<endl;
    cout<<"4. Order condition"<<endl;
    cout<<"5. Refund"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"Select -> ";
    cin>>option;
}

void case1(Account& account) {
    /* string형으로 아이디를 입력받는 i_id와 비밀번호를 입력받는 i_pw를 입력받습니다. 만약 i_id가 "0"이라면 함수를 종료합니다.
        또한 class 내의 bool형 함수인 check_id를 돌려 true라면 "Duplicated user"를 출력합니다. 아무 이상이 없다면 반복문을
        탈출합니다. 다음으로 비밀번호와 int형 i_money에 초기 돈을 설정해줍니다. 마지막으로 class 내의 add_account 함수를 통해
        계정을 등록합니다.*/
    string i_id, i_pw;
    
    while (true) {
        // 옳은 ID가 입력될 때까지 입력받는 while(true)문입니다.
        cout<<"Input your ID(0-to main menu) : ";
        cin>>i_id;
        if (i_id == "0") {
            return;
        }
        if (account.check_id(i_id)) {
            cout<<"Duplicated user"<<endl;
            continue;
        }
        break;
    }

    cout<<"Input your password : ";
    cin>>i_pw;

    int i_money = 0;
    cout<<"Input your Initial Money: "; 
    cin>>i_money;

    // 입력받은 값을 바탕으로 class 내의 add_account 함수를 통해 계정을 등록합니다.
    account.add_account(i_id, i_pw, i_money);
    cout<<"Weclome, "<<i_id<<endl;
}

void case2() {
    cout<<"----------Mcdonalds Menu ---------"<<endl;
    cout<<"1. Hamburger                 - 1000"<<endl;
    cout<<"2. Cheeseburger              - 1500"<<endl;
    cout<<"3. Big Mac                   - 3000"<<endl;
    cout<<"4. Quarter Pounder Cheese    - 4000"<<endl;
    cout<<"5. Double Quarter Cheese     - 5000"<<endl;
    cout<<"6. Fries                     - 1500"<<endl;
    cout<<"7. Chicken McNuggets         - 2000"<<endl;
    cout<<"8. Coke                      - 1500"<<endl;
    cout<<"9. Vanilla Cone              -  500"<<endl;
    cout<<"10. McFlurry                 - 2000"<<endl;
}

void case3(Account& account) {
    /* case1과 마찬가지인 i_id, i_pw와 더불어 int형 index를 선언한 후 -1로 초기화하였습니다.
        class 내에는 크기가 100인 id 배열이 있는데 -1은 배열에서 값을 찾지 못한 것을 의미합니다. */
    string i_id, i_pw;
    int index = -1;
    
    while (true) {
        // i_id에 "0"이 입력된다면 함수를 탈출합니다.
        cout<<endl;
        cout<<"Input your ID(0-to main menu) : ";
        cin>>i_id;
        if (i_id == "0") {
            return;
        }

        cout<<"Input your password : ";
        cin>>i_pw;

        // 계정이 존재한지 판단하는 bool형 exist를 선언한 후 false로 초기화합니다.
        bool exist = false;
        account.find_account(i_id, i_pw, exist, index);
        /* find_account 함수에서 exist가 true가 아니거나(존재하지 않거나) index가 수정되지 않은 채
            계속 -1이라면 재입력을 요구하고 반복문을 다시 실행합니다.*/
        if (!exist or index == -1) {
            cout<<"Please check your ID and password."<<endl;
            continue;
        }

        // 위의 과정을 무사히 통과했다면 index의 값이 있을테니 while문을 탈출합니다.
        break;
    }

    int i_order[10] = {0};
    // 주문 내역을 저장하는 크기가 10인 int형 배열 i를 선언한 후 0으로 초기화합니다.
    while (true) {
        int menu_index = 0, many = 0;

        cout<<endl;
        cout<<"Select menu number(0-to main menu) : ";
        cin>>menu_index;

        if (menu_index == 0) {
            cout<<"Your total price is "<<account.total_price(i_order)<<endl;
            account.order_list(index, i_order);
            account.control_money(index, account.total_price(i_order));
            cout<<"Thanks"<<endl;
            cout<<endl;
            return;
        }

        if (!(0 <= menu_index and menu_index<= 10)) {
            cout<<"Please choose correct menu number"<<endl;
            continue;
        }

        // 배열의 시작은 0번째1
        menu_index -= 1;
        string menu[10] = {"Hamburger", "Cheeseburger", "Big Mac", "Quarter Pounder Cheese", "Double Quarter Cheese",
                            "Fries", "Chicken McNuggets", "Coke", "Vanilla Cone", "McFlurry"};
        cout<<"How many '"<<menu[menu_index]<<"' do you want : ";
        cin>>many;
        i_order[menu_index] += many;
        if (account.control_money(index, 0) < account.total_price(i_order)) {
            i_order[menu_index] -= many;
            cout<<"Over budget"<<endl;
            continue;
        }
    }
}

void case4(Account& account, string menu[]) {
    /* 함수 case4와 case5에서 아이디와 비밀번호를 입력받는 부분은 case3과 유사하므로 주석을 달지 않겠습니다.*/
    string i_id, i_pw;
    int index = -1;

    while (true) {
        // i_id에 "0"이 입력된다면 함수를 탈출합니다.
        cout<<endl;
        cout<<"Input your ID(0-to main menu) : ";
        cin>>i_id;
        if (i_id == "0") {
            return;
        }

        cout<<"Input your password : ";
        cin>>i_pw;

        bool exist = false;
        account.find_account(i_id, i_pw, exist, index);
        if (!exist or index == -1) {
            cout<<"Please check your ID and password."<<endl;
            continue;
        }

        break;
    }
    
    /* 몇 번째인지를 표시하는 정수형 a를 선언한 후 1로 초기화합니다.*/
    int a = 1;
    cout<<endl;
    for(int i = 0; i < 10; i++) {
        /* 우선 for 문을 돌 때마다 정수형 order를 선언합니다.
            order에 class의 control_order를 통해 i번째 메뉴를 주문한 갯수를 대입합니다.
            만약 order가 0이 아니라면 a(=1)와 함께 그 값을 출력합니다.
            a가 사용되었다면 다음을 위해 a에 1을 더해줍니다.*/
        int order;
        order = account.control_order(index, i, 0);
        if (order != 0) {
            cout<<a<<". '"<<menu[i]<<"': "<<order<<endl;
            a++;
        }
    }

    cout<<endl;
    cout<<"Your total price is "<<account.return_price(index)<<endl;
    cout<<"Your total money is "<<account.control_money(index, 0)<<endl;
    cout<<endl;
}

void case5(Account& account, string menu[]) {
    string i_id, i_pw;
    int index = -1;

    while (true) {
        cout<<"Input your ID(0-to main menu) : ";
        cin>>i_id;
        if (i_id == "0") {
            return;
        }

        cout<<"Input your password : ";
        cin>>i_pw;

        bool exist = false;
        account.find_account(i_id, i_pw, exist, index);
        if (!exist or index == -1) {
            cout<<"Please check your ID and password."<<endl;
            continue;
        }

        break;
    }
    
    int a = 1;
    
    cout<<endl;
    /* 크기가 10인 정수형 배열 menu_array를 만듭니다.
        a가 출력될 때 a-1에 따른 i를 대입합니다.*/
    int menu_array[10] = {0};
    for(int i = 0; i < 10; i++) {
        int order;
        order = account.control_order(index, i, 0);
        if (order != 0) {
            menu_array[a-1] = i;
            cout<<a<<". '"<<menu[i]<<"': "<<order<<endl;
            a++;
        }
    }
    cout<<"Your total price is "<<account.return_price(index)<<endl;
    cout<<"Your total money is "<<account.control_money(index, 0)<<endl;
    cout<<endl;

    int order_menu = 0;
    cout<<"Choose number (0 - to main menu) : ";
    cin>>order_menu;
    // a의 값을 입력받은 것이므로 그에 맞는 값을 menu_array에서 찾아서 대입합니다.
    order_menu = menu_array[order_menu - 1];

    account.reset_order(index, order_menu);
    cout<<"Successfully refunded"<<endl;
    cout<<endl;

    a = 1;
    for(int i = 0; i < 10; i++) {
        int order;
        order = account.control_order(index, i, 0);
        if (order != 0) {
            cout<<a<<". '"<<menu[i]<<"': "<<order<<endl;
            a++;
        }
    }

    cout<<"Your total price is "<<account.return_price(index)<<endl;
    cout<<"Your total money is "<<account.control_money(index, 0)<<endl;
    cout<<endl;
}

int main() {
    Account account;
    string menu[10] = {"Hamburger", "Cheeseburger", "Big Mac", "Quarter Pounder Cheese", "Double Quarter Cheese",
                        "Fries", "Chicken McNuggets", "Coke", "Vanilla Cone", "McFlurry"};
    while (true) {
        char option = '0';
        welcome(option);
        switch(option) {
            case '0':
                return 0;
            case '1':
                case1(account);
                break;
            case '2':
                case2();
                break;
            case '3':
                case3(account);
                break;
            case '4':
                case4(account, menu);
                break;
            case '5':
                case5(account, menu);
                break;
            default:
                cout<<"Please input correct charecter."<<endl;
                continue;
        }
    }
}

Account::Account() {
    /* 생성자의 역할 답게private의 모든 변수를 string인 경우에는 "", order에는 0, price의 경우
    새로운 배열을 선언과 동시에 초기화한 후 for 문을 이용하여 모든 값을 대입하였습니다.*/
    for(int i = 0; i < 100; i++) {
        id[i] = "";
        pw[i] = "";
    }

    for (int i = 0; i < 100; i++) {
        for(int j = 0; j < 10; j++) {
            order[i][j] = 0;
        }
    }

    int i_price[10] = {1000, 1500, 3000, 4000, 5000, 1500, 2000, 1500, 500, 2000};
    for(int i = 0; i < 10; i++) {
        price[i] = i_price [i];
    }
}

int Account::store_index() {
    /* ""로 초기화를 완료한 string형 배열 id와 pw에서 사용되지 않은("") index를 찾아 반환합니다.*/
    int index = 0;
    for(index; index < 100; index++){
        if ((id[index] == "") and (pw[index] == "")) {
            break;
        }
    }
    return index;
}

bool Account::check_id(string i_id) {
    /* string형 i_id를 입렫받아 string형 배열 id에 같은 값이 있다면 true, 없다면 false를 반환합니다. */
    for(int i = 0; i < 100; i++) {
        if (id[i] == i_id) {
            return true;
        }
    }
    return false;
}

void Account::add_account(string i_id, string i_pw, int i_money) {
    /* string형 i_id와 i_pw, 정수형 i_money를 입력받아 store_index에서 적절한 index를 받습니다.
        적절한 index에 대하여 id, pw, money 배열에 i_id, i_pw, i_money를 대입합니다. */
    int index = store_index();
    id[index] = i_id;
    pw[index] = i_pw;
    money[index] = i_money;
}

void Account::find_account(string i_id, string i_pw, bool &i_exist, int &i_index) {
    /* 모든 id 배열에서 i_id와 같은 값을 찾고 같은데다가 그 pw까지 같다면 i_exist를 true로,
        i_index를 i로 수정한 후 종료합니다.*/
    for(int i = 0; i < 100; i++) {
        if (id[i] == i_id) {
            if(pw[i] == i_pw) {
                i_exist = true;
                i_index = i;
                return;
            }
        }
    }
}

void Account::order_list (int index, int i_order[]) {
    /* 전달받은 i_order의 값 만큼 order에 더해줍니다.*/
    for(int i = 0; i < 10; i++) {
        order[index][i] += i_order[i];
    }
}

int Account::control_money (int index, int price) {
    /* 전달받은 price의 값 만큼 price에서 빼줍니다.*/
    money[index] -= price;
    return money[index];
}

int Account::control_order (int index, int i, int count) {
    // 위의 함수와 유사합니다.
    order[index][i] -= count;
    return order[index][i];
}

void Account::reset_order (int index, int i) {
    /* 우선 order에 price를 곱한 만큼을 money에 환불해줍니다.
        그 다음 order에 주문하지 않은 상태인 0을 대입합니다.*/
    money[index] += order[index][i] * price[i];
    order[index][i] = 0;
}

int Account::total_price (int i_order[]) {
    /* 정수형 return_price를 선언한 후 0으로 초기화합니다.
        이후, 전달받은 정수형 배열인 i_order에 각 갯수에 맞게
        가격을 곱한 값을 더해나가 최종적인 return_price를 반환합니다.*/
    int return_price = 0;
    for (int i = 0; i < 10; i++) {
        return_price += i_order[i] * price[i];
    }
    return return_price;
}

int Account::return_price (int index) {
    /* 위의 함수의 class 내부 버젼이라고 보시면 됩니다.*/
    int return_price = 0;
    for (int i = 0; i < 10; i++) {
        return_price += order[index][i] * price[i];
    }
    return return_price;
}