//
// Created by d00257746 on 24/04/2024.
//

#include "Hopper.h"

Hopper::Hopper(int hopLength,int id,int x, int y,int direction,int size){
    this->hopLength = hopLength;
    this->id = id;
    this->position.first = x;
    this->position.second = y;
    this->direction = direction;
    this->size = size;
}

void Hopper::move(){
    while(Bug::isWayBlocked()){
        direction = rand() % 4 + 1;
    }

    for(int i =0;i<hopLength;i++){
        //1=North, 2=East, 3=South, 4=West
        if(!isWayBlocked()){
            switch(direction) {
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
    }
}