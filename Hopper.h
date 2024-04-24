//
// Created by d00257746 on 24/04/2024.
//

#ifndef CA2_HOPPER_H
#define CA2_HOPPER_H

#include "Bug.h"


class Hopper: public Bug{
private:
    Hopper(int hopLength,int id,int x, int y, int direction, int size);
    int hopLength;

public:

    int getHopLength();
    void move();
    void setHopLength(int hopLength);
};




#endif //CA2_HOPPER_H
