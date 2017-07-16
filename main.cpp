#include <iostream>

#include "Scene.h"

int main(int argc, char *argv[])
{
    std::ifstream fin("qqq.house");
    std::ofstream fout("yourhouse.obj");
    Scene s;
    s.ReadData(fin);
    s.WriteData(fout);
    return 0;
}
