#ifndef TIGER_H
#define TIGER_H

#include <cstdlib>
#include <ctime>

using namespace std;

// 주석은 rabbit 참조
class Tiger {
private:
    int _x, _y;
    int _life;
    int _age;
public:
    Tiger() {
        srand(time(0));
        _x = rand() % 20;
        _y = rand() % 20;
        _life = 4;
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

    void move(char xy[][20], vector <Rabbit> &rabbit, int r[]) {
        int s = rand() % 4;
        _life--;
        _age++;

        if (xy[_x - 1][_y] == 'R') {
            xy[_x - 1][_y] = 't';
            _life = 4;
            _x = _x - 1;
            for (int i = 0; i < rabbit.size(); i++) {
                if (rabbit[i].x() == _x and rabbit[i].y() == _y) {
                    rabbit.erase(rabbit.begin() + i);
                    break;
                }
            }
        }
        else if (xy[_x + 1][_y] == 'R') {
            xy[_x + 1][_y] = 't';
            _life = 4;
            _x = _x + 1;
            for (int i = 0; i < rabbit.size(); i++) {
                if (rabbit[i].x() == _x and rabbit[i].y() == _y) {
                    rabbit.erase(rabbit.begin() + i);
                    break;
                }
            }
        }
        else if (xy[_x][_y - 1] == 'R') {
            xy[_x][_y - 1] = 't';
            _life = 4;
            _y = _y - 1;
            for (int i = 0; i < rabbit.size(); i++) {
                if (rabbit[i].x() == _x and rabbit[i].y() == _y) {
                    rabbit.erase(rabbit.begin() + i);
                    break;
                }
            }
        }
        else if (xy[_x][_y + 1] == 'R') {
            xy[_x][_y + 1] = 't';
            _life = 4;
            _y = _y + 1;
            for (int i = 0; i < rabbit.size(); i++) {
                if (rabbit[i].x() == _x and rabbit[i].y() == _y) {
                    rabbit.erase(rabbit.begin() + i);
                    break;
                }
            }
        }
        else if (s == 0) {
            if (_x == 0) {}
            else {
                if (xy[_x - 1][_y] == '-' or xy[_x - 1][_y] == '*'  or xy[_x - 1][_y] == 'O') {
                    _x -= 1;
                }
            }
        }
        else if (s == 1) {
            if (_x == 19) {}
            else {
                if (xy[_x + 1][_y] == '-' or xy[_x + 1][_y] == '*'  or xy[_x - 1][_y] == 'O') {
                        _x += 1;
                }
            }
        }
        else if (s == 2) {
            if (_y == 0) {}
            else {
                if (xy[_x][_y - 1] == '-' or xy[_x][_y - 1] == '*'  or xy[_x - 1][_y] == 'O') {
                        _y -= 1;
                }
            }
        }
        else if (s == 3) {
            if (_y == 19) {}
            else {
                if (xy[_x][_y + 1] == '-' or xy[_x][_y + 1] == '*'  or xy[_x - 1][_y] == 'O') {
                        _y += 1;
                }
            }
        }
    }
};

#endif