#ifndef ZORKUL_H_
#define ZORKUL_H_

#include <QString>
#include "Room.h"
#include "wordle.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
    Room *currentRoom;
    void createRooms();
    void printWelcome();
//    bool processCommand(Command command);
    void printHelp();

    void createItems();
    void displayItems();

public:
    ZorkUL();
    void play();
    string goRoom(string dir);
    string go(string direction);
};

#endif /*ZORKUL_H_*/
