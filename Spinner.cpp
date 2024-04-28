//
// Created by user on 28/04/2024.
//

#include "Spinner.h"


Spinner::Spinner(int id, int x, int y, int direction, int size) {
    this->id = id;
    this->position.first = x;
    this->position.second = y;
    this->direction = direction;
    this->size = size;
}

void Spinner::move(){
    while(Bug::isWayBlocked()){
        direction = rand() % 4 + 1;
    }
    switch(direction){
        case 1:
            position.second--;
            direction = rand() % 4 + 1;
        break;
        case 2:
            position.first++;
            direction = rand() % 4 + 1;
        break;
        case 3:
            position.second++;
            direction = rand() % 4 + 1;
        break;
        case 4:
            position.first--;
            direction = rand() % 4 + 1;
        break;
    }
    path.push_back(position);
}
void Spinner::display() {
    std::string dirName;
    switch(direction){
        case 1:
            dirName = "North";
        break;
        case 2:
            dirName = "East";
        break;
        case 3:
            dirName = "South";
        break;
        case 4:
            dirName = "West";
        break;
    }
    std::string status;
    if(alive)
        status = "Alive";
    else
        status = "Dead";
    std::cout << "Spinner  " <<"id: "<< id <<" ("<< position.first <<","<< position.second <<") "<< dirName <<" Size: "<< size <<" " <<  status << std::endl;
}
