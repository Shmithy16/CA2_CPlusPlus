//
// Created by user on 28/04/2024.
//

#ifndef SPINNER_H
#define SPINNER_H

#include "Bug.h"

class Spinner: public Bug {
public:
    Spinner(int id, int x, int y, int direction, int size);
    void move();
    void display();
};



#endif //SPINNER_H
