#include <iostream>

#include "mainwindow.h"


using namespace std;
#include "ZorkUL.h"
#include <QApplication>

//global variables

Room *a, *b, *c, *d, *e, *f, *g, *h, *i;



int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

ZorkUL::ZorkUL() {
    createRooms();
}

void ZorkUL::createRooms()  {


    a = new Room("Centre"); // middle
    b = new Room("East");
    c = new Room("West");
    d = new Room("South");
    e = new Room("Door"); // door / escape
    f = new Room("North");
    g = new Room("North-East"); //wordle puzzle
    h = new Room("North-West");
    i = new Room("key");
        i->addItem(new Item("key", 1, 11));

//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);

        currentRoom = a;
}

string ZorkUL::getRoom(){
    return currentRoom->shortDescription();
}
void ZorkUL::printWelcome() {
    cout << "start"<< endl;
    cout << "info for help"<< endl;
    cout << endl;
    cout << currentRoom->longDescription() << endl;
}

string ZorkUL::goRoom(string dir) {
    // Try to leave current room.
    Room* nextRoom = setRoom(dir);

    if (nextRoom == NULL)
        return "No exit this way";

    else {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }

}

inline Room* ZorkUL::setRoom(string dir) {  //inline Function :)
    Room* newRoom = currentRoom->nextRoom(dir);
    return newRoom;
}



