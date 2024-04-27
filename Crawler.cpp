//
// Created by d00257746 on 17/04/2024.
//

#include "Crawler.h"

Crawler::Crawler(int id,int x, int y,int direction,int size){
    this->id = id;
    this->position.first = x;
    this->position.second = y;
    this->direction = direction;
    this->size = size;
}

void Crawler::move(){
    while(Bug::isWayBlocked()){
        direction = rand() % 4 + 1;
    }
    //1=North, 2=East, 3=South, 4=West
    switch(direction){
        case 1:
            position.second--;
            break;
        case 2:
            position.first++;
            break;
        case 3:
            position.second++;
            break;
        case 4:
            position.first--;
            break;
    }
}
void Crawler::display() {
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
    std::cout << "Crawler " <<"id: "<< id <<" ("<< position.first <<","<< position.second <<") "<< dirName <<" Size: "<< size <<" "<<  status << std::endl;
}