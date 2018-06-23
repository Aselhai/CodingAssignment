#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

#include "hunter.h"
#include "rabbit.h"
#include "tiger.h"
#include "grass.h"
#include "pit.h"

using namespace std;

void initial (int number[]) {
    /* 여러 개체의 수를 입력 받는 initial 함수입니다. 값을 입력받아 크기가 4인 int형 배열 number에 저장합니다.
        string으로 입력받아 atoi 했을 때 자연수가 아니라면 다시 입력받습니다. */
    string s;
    while (true) {
        cout << "Enter initial number of rabbits: ";
        cin >> s;
        if ((atoi(s.c_str()) == 0) or (atoi(s.c_str()) < 0)) {
            cout << "Please Input correct number of rabbits." << endl;
            continue;
        }
        number[0] = atoi(s.c_str());
        break;
    }

    while (true) {
        cout << "Enter initial number of tigers: ";
        cin >> s;
        if ((atoi(s.c_str()) == 0) or (atoi(s.c_str()) < 0)) {
            cout << "Please Input the correct number of tigers." << endl;
            continue;
        }
        number[1] = atoi(s.c_str());
        break;
    }
    
    while (true) {
        cout << "Enter initial number of grasses: ";
        cin >> s;
        if ((atoi(s.c_str()) == 0) or (atoi(s.c_str()) < 0)) {
            cout << "Please Input the correct number of grasses." << endl;
            continue;
        }
        number[2] = atoi(s.c_str());
        break;
    }

    while (true) {
        cout << "Enter initial number of pits: ";
        cin >> s;
        if ((atoi(s.c_str()) == 0) or (atoi(s.c_str()) < 0)) {
            cout << "Please Input the correct number of pits." << endl;
            continue;
        }
        number[3] = atoi(s.c_str());
        break;
    }
    
    while (true) {
        cout << "Enter initial number of potions: ";
        cin >> s;
        if ((atoi(s.c_str()) == 0) or (atoi(s.c_str()) < 0)) {
            cout << "Please Input the correct number of potions." << endl;
            continue;
        }
        number[4] = atoi(s.c_str());
        break;
    }
}

string input_hunter() {
    /* 어디로 갈지를 입력 받는 string형 함수 input_hunter입니다.
        string 배열 array에 있는 원소들만 입력받아서 반환합니다.*/
    while (true) {
            cout << "Input the moving direction( Up: 'w', Down: 's', Left: 'a', Right: 'd'): ";

            string where;
            cin >> where;
            
            string array[8] = {"w", "s", "a", "d", "wa", "wd", "sa", "sd"};
            for (int i = 0; i < 8; i++) {
                if (array[i] == where) {

                    return where;
                }
            }
            cout << "Please Input the correct direction." <<endl;
        }
}

void use_potion(Hunter &hunter, int &num_potion) {
    /* 포션을 사용하는 함수입니다. 당연히 포션이 1개 이상일 때에 작동합니다.*/
     if (num_potion > 0) {
        while (true) {
            cout << "Are you going to use potion( Yes: 'y', No : 'n' ) : ";

            string use;
            cin >> use;
            
            if (use == "y") {
                num_potion--;
                hunter.use();
            }
            else if (use == "n") {}
            else {
                cout << "Please Input the correct choose." <<endl;
                continue;
            }

            break;
        }
    }
}

void grid(char xy[20][20]) {
    /* xy 배열의 원소를 출력하는 void형 함수 grid 입니다.*/
    cout << endl;
    for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                cout << xy[i][j] << ' ';
            }
            cout << endl;
        }
    cout << endl;

}

int main () {
    int number[5];
    while (true) {
        /* 한 함수에서 쉽게 수정하기 위해서 배열을 사용했습니다.
            initial 함수에 넣은 후 배열의 원소를 더하여 400(격자의 크기)을 초과한다면 다시 입력 받습니다.*/
        initial (number);

        int amount = 0;
        for (int i = 0; i < 3; i++) {
            amount += number[i];
        }

        if (amount > 400) {
            cout << "Too many objects!" << endl;
            continue;
        }
        else {
            break;
        }
    }

    // 배열의 원소들을 변수로 지정해줍니다. 특히, 함정의 갯수는 const로 취급합니다.
    int num_rabbit = number[0];
    int num_tiger = number[1];
    int num_grass = number[2];
    int const num_pit = number[3];
    int num_potion = number[4];
    
    // char형 배열 xy를 만든 후 '-'로 채웁니다. 
    char xy[20][20];
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            xy[i][j] = '-';
        }
    }

    // 격자에 '-'인 곳을 xy 좌표로 설정한 후 'H'를 표시합니다.
    Hunter hunter;
    while (xy[hunter.x()][hunter.y()] != '-') {
        hunter.reset();  
    }
    xy[hunter.x()][hunter.y()] = 'H';

    // 위와 마찬가지이지만 vector 템플릿을 사용했습니다.
    vector <Rabbit> rabbit(num_rabbit);
    for (int i = 0; i < num_rabbit; i++) {
        while (xy[rabbit[i].x()][rabbit[i].y()] != '-') {
            rabbit[i].reset();
        }
        xy[rabbit[i].x()][rabbit[i].y()] = 'R';
    }

    vector <Tiger> tiger(num_tiger);
    for (int i = 0; i < num_tiger; i++) {
        while (xy[tiger[i].x()][tiger[i].y()] != '-') {
            tiger[i].reset();
        }
        xy[tiger[i].x()][tiger[i].y()] = 'T';
    }

    vector <Grass> grass(num_grass);
    for (int i = 0; i < num_grass; i++) {
        while (xy[grass[i].x()][grass[i].y()] != '-') {
            grass[i].reset();
        }
        xy[grass[i].x()][grass[i].y()] = '*';
    }

    vector <Pit> pit(num_pit);
    for (int i = 0; i < num_pit; i++) {
        while (xy[pit[i].x()][pit[i].y()] != '-') {
            pit[i].reset();
        }
        xy[pit[i].x()][pit[i].y()] = 'O';
    }

    // 단계를 표현할 step, 점수를 표현할 score, 토끼와 호랑이의 정보를 나타내는 크기가 4인 정수형 배열 r, t 입니다.
    int step = 0;
    int score = 0;
    int r[4] = {0};
    int t[4] = {0};
    // while (true) 문으로 반복합니다.
    while (true) {
        cout << "Time step: " << step << endl;
        step++;
        
        cout << "<Score:" << score << ", HP:" << hunter.HP() << ", Potions:" << num_potion << ">" << endl;

        grid(xy);
        
        cout << "number of rabbits: " << num_rabbit << " <born:" << r[0] << ", starve:" << r[1] << ", captured:" << r[2] << ", fall:" << r[3] << ">" << endl;
        cout << "number of tigers: " << num_tiger << " <born:" << t[0] << ", starve:" << t[1] << ", captured:" << t[2] << ", fall:" << t[3] << ">" << endl;
        cout << "number of grasses: " << num_grass << endl;
        cout << "number of pits: " << num_pit << endl;
        
        string where = input_hunter();
        use_potion(hunter, num_potion);

        cout << endl; 

        // 토끼 이동
        for (int i = 0; i < num_rabbit; i++) {
            rabbit[i].move(xy, grass);
        }
        // 토끼 배고픔
        while (true) {
            /* for 문을 이용하여 체력이 0이하인 토끼가 있다면 erase 메소드를 이용하여 삭제해줍니다.
                starve를 나타내는 r[1]에 1을 더해주고 bool형 inner를 false로 한 채 for 문을 탈출하여
                num_rabbit을 다시 설정한 후 inner가 true가 되어 while문을 탈출할 때까지 반복합니다.*/
            bool inner = true;
            for (int i = 0; i < num_rabbit; i++) {
                if (rabbit[i].life() <= 0) {
                    rabbit.erase(rabbit.begin() + i);
                    r[1]++;
                    inner = false;
                    break;
                }
            }
            num_rabbit = rabbit.size();
            if (inner) {
                break;
            }
        }
        // 이전의 'R'를 '-'로 바꾼 후 새로운 'R'로 설정합니다.
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (xy[i][j] == 'R') {
                    xy[i][j] = '-';
                }
            }
        }
        for (int i = 0; i < num_rabbit; i++) {
            xy[rabbit[i].x()][rabbit[i].y()] = 'R';
        }

        // 호랑이 이동
        for (int i = 0; i < num_tiger; i++) {
            tiger[i].move(xy, rabbit, r);
        }
        // 호랑이 배고픔
        while (true) {
            bool inner = true;
            for (int i = 0; i < num_tiger; i++) {
                if (tiger[i].life() <= 0) {
                    tiger.erase(tiger.begin() + i);
                    t[1]++;
                    inner = false;
                    break;
                }
            }
            num_tiger = tiger.size();
            if (inner) {
                break;
            }
        }
        // 이전의 'T'를 '-'로 바꾼 후 새로운 'T'로 설정합니다.
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (xy[i][j] == 'T') {
                    xy[i][j] = '-';
                }
            }
        }
        for (int i = 0; i < num_tiger; i++) {
            xy[tiger[i].x()][tiger[i].y()] = 'T';
        }

        // 사냥꾼 이동
        hunter.move(where);

        // 토끼 번식
        while (true) {
            bool inner = true;
            for (int i = 0; i < num_rabbit; i++) {
                if (rabbit[i].age() != 0 and rabbit[i].age() % 3 == 0) {
                    
                    vector <Rabbit> temp(1);
                    temp[0] = rabbit[num_rabbit - 1];
                    
                    int rx, ry;
                    srand(time(0));
                    rx = -1 + rand() % 3;
                    if (rx == 0) {
                        while (true) {
                            ry = -1 + rand() % 3;
                            if (ry != 0) {
                                break;
                            }
                        }
                    }

                    if (xy[rabbit[i].x() + rx][rabbit[i].y() + ry] == '-') {
                        temp[0].x(rabbit[i].x() + rx);
                        temp[0].y(rabbit[i].y() + ry);
                        xy[temp[0].x()][temp[0].y()] = 'R';
                        rabbit.push_back(temp[0]);
                        r[0]++;
                    }
                }
            }
            num_rabbit = rabbit.size();
            if (inner) {
                break;
            }
        }
        // 이전의 'R'를 '-'로 바꾼 후 새로운 'R'로 설정합니다.
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (xy[i][j] == 'R') {
                    xy[i][j] = '-';
                }
            }
        }
        for (int i = 0; i < num_rabbit; i++) {
            xy[rabbit[i].x()][rabbit[i].y()] = 'R';
        }

        // 호랑이 번식
        while (true) {
            bool inner = true;
            for (int i = 0; i < num_tiger; i++) {
                if (tiger[i].age() != 0 and tiger[i].age() % 4 == 0) {
                    
                    vector <Tiger> temp(1);
                    temp[0] = tiger[num_tiger - 1];
                    
                    int rx, ry;
                    srand(time(0));
                    rx = -1 + rand() % 3;
                    if (rx == 0) {
                        while (true) {
                            ry = -1 + rand() % 3;
                            if (ry != 0) {
                                break;
                            }
                        }
                    }

                    if (xy[tiger[i].x() + rx][tiger[i].y() + ry] == '-') {
                        temp[0].x(tiger[i].x() + rx);
                        temp[0].y(tiger[i].y() + ry);
                        xy[temp[0].x()][temp[0].y()] = 'T';
                        tiger.push_back(temp[0]);
                        t[0]++;
                    }
                }
            }
            num_tiger = tiger.size();
            if (inner) {
                break;
            }
        }
        // 이전의 'T'를 '-'로 바꾼 후 새로운 'T'로 설정합니다.
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (xy[i][j] == 'T') {
                    xy[i][j] = '-';
                }
            }
        }
        for (int i = 0; i < num_tiger; i++) {
            xy[tiger[i].x()][tiger[i].y()] = 'T';
        }

        // 토끼 사냥
        for (int i = 0; i < num_rabbit; i++) {
            /* 만약 토끼의 위치와 사냥꾼의 위치가 겹치는 것이 있다면 그 토끼는 지웁니다.
                captured를 나타내는 r[2]에 1을 추가해줍니다. */
            if ((rabbit[i].x() == hunter.x()) and (rabbit[i].y() == hunter.y())) {
                rabbit.erase(rabbit.begin() + i);
                score += 1;
                r[2]++;
                break;
            }
        }
        // 이전의 'R'를 '-'로 바꾼 후 새로운 'R'로 설정합니다.
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (xy[i][j] == 'R') {
                    xy[i][j] = '-';
                }
            }
        }
        for (int i = 0; i < num_rabbit; i++) {
            xy[rabbit[i].x()][rabbit[i].y()] = 'R';
        }

        //호랑이 사냥
        for (int i = 0; i < num_tiger; i++) {
            /* 만약 호랑이의 위치와 사냥꾼의 위치가 겹치는 것이 있다면 그 호랑이는 지웁니다.
                captured를 나타내는 t[2]에 1을 추가해줍니다. */
            if ((tiger[i].x() == hunter.x()) and (tiger[i].y() == hunter.y())) {
                tiger.erase(tiger.begin() + i);
                score += 2;
                t[2]++;
                break;
            }
        }
        // 이전의 'T'를 '-'로 바꾼 후 새로운 'T'로 설정합니다.
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (xy[i][j] == 'T') {
                    xy[i][j] = '-';
                }
            }
        }
        for (int i = 0; i < num_tiger; i++) {
            xy[tiger[i].x()][tiger[i].y()] = 'T';
        }

        // 이전의 'H'를 '-'로 바꾼 후 새로운 'H'로 설정합니다.
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (xy[i][j] == 'H') {
                    xy[i][j] = '-';
                }
            }
        }
        xy[hunter.x()][hunter.y()] = 'H';
        
        if (num_grass != grass.size()) {
            /* 만약 토끼가 풀을 뜯어 먹어 풀이 없어졌다면 풀을 다시 생성해줍니다.
                임시로 크기가 k인 Grass vector temp를 만들어 '-'이 되도록 좌표를 설정한 후
                grass vector에 push합니다.*/
            int k = num_grass - grass.size();
            vector <Grass> temp(k);
            for (int i = 0; i < k; i++) {
                 while (xy[temp[i].x()][temp[i].y()] != '-') {
                    temp[i].reset();
                }
                grass.push_back(temp[i]);
            }
        }
        // 이전의 '*'을 '-'로 바꾼 후 새로운 '*'로 설정합니다.
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (xy[i][j] == '*') {
                    xy[i][j] = '-';
                }
            }
        }
        for (int i = 0; i < num_grass; i++) {
            xy[grass[i].x()][grass[i].y()] = '*';
        }
        
        for (int i = 0; i < num_pit; i++) {
            xy[pit[i].x()][pit[i].y()] = 'O';

            // 만약 사냥꾼이 함정을 밟는다면 0을 반환하여 프로그램을 종료합니다.
            if ((pit[i].x() == hunter.x()) and (pit[i].y() == hunter.y()) or (hunter.HP() <= 0)) {
                cout << "Your final score is " << score << endl;
                cout << "End of the program" << endl; 
                return 0;
            }
            // 위의 배고픔과 비슷하게 토끼나 호랑이가 함정을 밟는다면 제거합니다.
            while (true) {
                bool inner = true;
                for (int j = 0; j < num_rabbit; j++) {
                    if ((pit[i].x() == rabbit[j].x()) and (pit[i].y() == rabbit[j].y())) {
                        rabbit.erase(rabbit.begin() + i);
                        r[3]++;
                        inner = false;
                        break;
                    }
                }
                num_rabbit = rabbit.size();
                if (inner) {
                    break;
                }
            }
            while (true) {
                bool inner = true;
                for (int j = 0; j < num_tiger; j++) {
                    if ((tiger[i].x() == tiger[j].x()) and (pit[i].y() == tiger[j].y())) {
                        tiger.erase(tiger.begin() + i);
                        t[3]++;
                        inner = false;
                        break;
                    }
                }
                num_tiger = tiger.size();
                if (inner) {
                    break;
                }
            }
        }
    }
    return 1;
}