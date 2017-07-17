#ifndef SCENE_H
#define SCENE_H

#include <fstream>
#include "House.h"

class Scene
{
public:
    void ReadData(std::istream& dataStream);
    void WriteData(std::ostream& dataStream);
private:
    House house;
};

#endif // SCENE_H
