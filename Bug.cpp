//
// Created by d00257746 on 09/04/2024.
//

#include "Bug.h"

Bug::Bug(int id,int x, int y,int direction,int size){
    this->id = id;
    this->position.first = x;
    this->position.second = y;
    this->direction = direction;
    this->size = size;
    this->alive = true;
}

Bug::Bug(){
    this->id = 1;
    this->position.first = 0;
    this->position.second = 0;
    this->direction = 1;
    this->size = 1;
    this->alive = true;
}



//1=North, 2=East, 3=South, 4=West
bool Bug::isWayBlocked() {
    switch(direction){
        case 1:
            if(position.second == 0){
                return true;
            }
            break;
        case 2:
            if(position.first == 9){
                return true;
            }
            break;
        case 3:
            if(position.second == 9){
                return true;
            }
            break;
        case 4:
            if(position.first == 0){
                return true;
            }
            break;
    }
    return false;
}

int Bug::getId() const
{
    return id;
}
std::pair<int, int> Bug::getPosition() const
{
    return position;
}
int Bug::getDirection() const {
    return direction;
}
int Bug::getSize() const {
    return size;
}
bool Bug::getAlive() const {
    return alive;
}
std::list<std::pair<int,int>> Bug::getPath() const {
    return path;
}
void Bug::setId(int id){
    this->id=id;
}
void Bug::setPosition(std::pair<int, int>){
    this->position=position;
};
void Bug::setDirection(int direction) {
    this->direction=direction;
}
void Bug::setSize(int size) {
    this->size=size;
}
void Bug::setAlive(bool alive) {
    this->alive=alive;
}
void Bug::setPath(std::list<std::pair<int, int>> path) {
    this->path=path;
}

