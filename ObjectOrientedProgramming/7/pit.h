#ifndef PIT_H
#define PIT_H

#include <cstdlib>
#include <ctime>

using namespace std;

class Pit {
private:
    int _x, _y;
public:
    Pit() {
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

    int y() {
        return _y;
    }

};

#endif