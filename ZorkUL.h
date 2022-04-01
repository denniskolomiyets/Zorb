#ifndef ZORKUL_H_
#define ZORKUL_H_

#include <QString>
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include "mainwindow.h"

using namespace std;

class ZorkUL {
private:
    void createRooms();
    void printWelcome();
//    bool processCommand(Command command);
    void printHelp();

    void createItems();
    void displayItems();

protected:
    Room *currentRoom;

public:
    ZorkUL();
    void play();
    string goRoom(string dir);
    string go(string direction);
    string getRoom();
};

#endif /*ZORKUL_H_*/
