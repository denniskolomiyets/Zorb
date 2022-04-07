#ifndef DARKROOM_H
#define DARKROOM_H Advanced pre-processor directives


#include <string>

using namespace std;

class DarkRoom
{
public:
    DarkRoom();
    virtual string figure() = 0;
};

#endif // DARKROOM_H
