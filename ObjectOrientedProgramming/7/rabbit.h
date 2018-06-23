#ifndef RABBIT_H
#define RABBIT_H

#include <cstdlib>
#include <ctime>
#include <vector>

#include "grass.h"

using namespace std;

class Rabbit {
private:
    int _x, _y;
    int _life;
    int _age;
public:
    Rabbit() {
        srand(time(0));
        _x = rand() % 20;
        _y = rand() % 20;
        _life = 3;
        _age = 0;
    }

    void reset() {
        _x = rand() % 20;
        _y = rand() % 20;
    }

    int x() {
        return _x;
    }
    void x (int i) {
        _x = i;
    }

    int y() {
        return _y;
    }
    void y (int i) {
        _y = i;
    }

    int life() {
        return _life;
    }
    void life (int i) {
        _life = i;
    }
    
    int age() {
        return _age;
    }
    void age (int i) {
        _age = i;
    }

    void move(char xy[][20], vector <Grass> &grass) {
        /* hunter class의 move와 비슷하지만 값을 입력 받는 것이 아닌 무작위 수 s에 따라 이동합니다. 
            이동할 떄 마다 _life는 1씩 깎이며, _age는 1씩 증가합니다.*/
        srand(time(0));
        int s = rand() % 4;
        _life--;
        _age++;

        /* 주위에 풀이 있으면 무조건 그곳으로 이동합니다.
            풀로 이동하면 _life가 3이되며, 그 곳으로 이동후 그 곳의 grass는 삭제됩니다.*/
        if (xy[_x - 1][_y] == '*') {
            _life = 3;
            _x = _x - 1;
            for (int i = 0; i < grass.size(); i++) {
                if (grass[i].x() == _x and grass[i].y() == _y) {
                    grass.erase(grass.begin() + i);
                    break;
                }
            }
        }
        else if (xy[_x + 1][_y] == '*') {
            _life = 3;
            _x = _x + 1;
            for (int i = 0; i < grass.size(); i++) {
                if (grass[i].x() == _x and grass[i].y() == _y) {
                    grass.erase(grass.begin() + i);
                    break;
                }
            }
        }
        else if (xy[_x][_y - 1] == '*') {
            _life = 3;
            _y = _y - 1;
            for (int i = 0; i < grass.size(); i++) {
                if (grass[i].x() == _x and grass[i].y() == _y) {
                    grass.erase(grass.begin() + i);
                    break;
                }
            }
        }
        else if (xy[_x][_y + 1] == '*') {
            _life = 3;
            _y = _y + 1;
            for (int i = 0; i < grass.size(); i++) {
                if (grass[i].x() == _x and grass[i].y() == _y) {
                    grass.erase(grass.begin() + i);
                    break;
                }
            }
        }

        /* 주위에 grass가 없다면 '-'나 'O'로만 이동할 수 있게 합니다.*/
        else if (s == 0) {
            if (_x == 0) {}
            else {
                if (xy[_x - 1][_y] == '-' or xy[_x - 1][_y] == 'O') {
                    _x -= 1;
                }
            }
        }
        else if (s == 1) {
            if (_x == 19) {}
            else {
                if (xy[_x + 1][_y] == '-' or xy[_x - 1][_y] == 'O') {
                        _x += 1;
                }
            }
        }
        else if (s == 2) {
            if (_y == 0) {}
            else {
                if (xy[_x][_y - 1] == '-' or xy[_x - 1][_y] == 'O') {
                        _y -= 1;
                }
            }
        }
        else if (s == 3) {
            if (_y == 19) {}
            else {
                if (xy[_x][_y + 1] == '-' or xy[_x - 1][_y] == 'O') {
                        _y += 1;
                }
            }
        }
    }
};

#endif