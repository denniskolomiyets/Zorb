#ifndef ZORKUL_H_
#define ZORKUL_H_

#include <QString>
#include "command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
    Parser parser;
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
