//
// Created by d00257746 on 17/04/2024.
//

#ifndef CA2_CRAWLER_H
#define CA2_CRAWLER_H

#include "Bug.h"



class Crawler: public Bug{
public:
    Crawler(int id, int x, int y, int direction, int size);
    void move();
    void display();
};



#endif //CA2_CRAWLER_H
