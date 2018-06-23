#ifndef GRASS_H
#define GRASS_H

#include <cstdlib>
#include <ctime>

using namespace std;

class Grass {
private:
    int _x, _y;
public:
    Grass() {
        srand(time(0));
        _x = rand() % 20;
        _y = rand() % 20;
    }

    void reset() {
        _x = rand() % 20;
        _y = rand() % 20;
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
};

#endif