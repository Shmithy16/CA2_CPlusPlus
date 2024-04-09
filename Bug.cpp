//
// Created by d00257746 on 09/04/2024.
//

#include "Bug.h"

Bug::Bug(int id,std::pair<int, int> position,int direction,int size,bool alive,std::list<std::pair<int,int>> path){
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;
    this->alive = alive;
    this->path = path;
}

int Bug::getId() const
{
    return id;
}
std::pair<int, int> Bug::getPosition() const
{
    return position;
}
