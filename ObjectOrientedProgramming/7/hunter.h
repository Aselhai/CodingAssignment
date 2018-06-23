#ifndef HUNTER_H
#define HUNTER_H

#include <cstdlib>
#include <ctime>

using namespace std;

class Hunter {
private:
    int _step;
    int _x, _y;
    int _HP;
public:
    Hunter() {
        _step = 0;
        srand(time(0));
        _x = rand() % 20;
        _y = rand() % 20;
        _HP = 3;
    }

    void reset() {
        _x = rand() % 20;
        _y = rand() % 20;
    }
    
    int step() {
        return _step;
    }
    void step (int i) {
        _step += i;
    }

    int x() {
        return _x;
    }
    void x (int i) {
        _x += i;
    }

    int y() {
        return _y;
    }
    void y (int i) {
        _y += i;
    }

    int HP() {
        return _HP;
    }
    void HP (int i) {
        _HP += i;
    }

    void use() {
        _HP = 3;
    }

    void move (string s) {
        /* 이동할 때 마다 체력이 1씩 깎입니다.
            입력 받은 값에 대하여 이동할 수 없으면 아무 행동도 취하지 않습니다. ({})*/
        _HP -= 1;
        if (s == "w") {
                if (_x == 0) {}
                else {
                    _x -= 1;
                }
            }
        else if (s == "s") {
            if (_x == 19) {}
            else {
                _x += 1;
            }
        }
        else if (s == "a") {
            if (_y == 0) {}
            else {
                _y -= 1;
            }
        }
        else if (s == "d") {
            if (_y == 19) {}
            else {
                _y += 1;
            }
        }
        else if (s == "wa") {
            if ((_x == 0) and (_y == 0)) {}
            else {
                _x -= 1;
                _y -= 1;
            }
        }
        else if (s == "wd") {
            if ((_x == 0) and (_y == 19)) {}
            else {
                _x -= 1;
                _y += 1;
            }
        }
        else if (s == "sa") {
            if ((_x == 19) and (_y == 0)) {}
            else {
                _x += 1;
                _y -= 1;
            }
        }
        else if (s == "sd") {
            if ((_x == 19) or (_y == 19)) {}
            else {
                _x += 1;
                _y += 1;
            }
        }
    }
};

#endif