#ifndef DERIVED_H
#define DERIVED_H //Advanced pre-processor directive

#include "darkroom.h"
#include <string>

using namespace std;

class derived: public DarkRoom // inheritance
{
public:
    derived();
    string figure() {    return "It's too dark to see\n\nWhispers echo in the tunnel. \nDoesn't feel real, does it?\nLike its abstract or.. virtual";
}
};

#endif // DERIVED_H
