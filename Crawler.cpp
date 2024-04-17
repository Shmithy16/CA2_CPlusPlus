//
// Created by d00257746 on 17/04/2024.
//

#include "Crawler.h"


void Crawler::move(){
    while(Bug::isWayBlocked()){
        srand (time(NULL));
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