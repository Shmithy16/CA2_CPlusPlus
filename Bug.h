//
// Created by d00257746 on 09/04/2024.
//

#ifndef CA2_BUG_H
#define CA2_BUG_H
#include <utility>
#include <iostream>
#include <list>

class Bug {
protected:
    Bug(int id, std::pair<int, int> position, int direction, int size, bool alive, std::list<std::pair<int, int>> path);

    int id;
    std::pair<int, int> position;
    int direction;
    int size;
    bool alive;
    std::list<std::pair<int,int>> path;

public:
    virtual void move();
    bool isWayBlocked();
    int getId() const;
    std::pair<int, int> getPosition() const;
    int getDirection() const;
    int getSize() const;
    bool getAlive() const;
    std::list<std::pair<int,int>> getPath() const;

    void setId(int id);
    void setPosition(std::pair<int, int>);
    void setDirection(int direction);
    void setSize(int size);
    void setAlive(bool alive);
    void setPath(std::list<std::pair<int,int>> path);
};


#endif //CA2_BUG_H
