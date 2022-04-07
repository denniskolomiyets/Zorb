#ifndef ZORKUL_H_
#define ZORKUL_H_

#include <QString>
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include "mainwindow.h"

using namespace std;//namespace

class ZorkUL {
private:
    void createRooms();
    void printWelcome();
//    bool processCommand(Command command);
    void printHelp();
    void createItems();
    void displayItems();
     Room* setRoom(string dir);

protected:
    Room *currentRoom;

public:
    ZorkUL();
    void play();
    string goRoom(string dir);
    string go(string direction);
    string getRoom();
    void resetRoom();
};

#endif /*ZORKUL_H_*/
