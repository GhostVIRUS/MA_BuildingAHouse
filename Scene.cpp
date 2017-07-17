#include "Scene.h"

#include <string>

void Scene::ReadData(std::istream &dataStream)
{
    std::string command;
    while (dataStream >> command)
    if (command == "height")
    {
        double h;
        dataStream >> h;
        house.SetHeight(h);
    }
    else if (command == "point")
    {
        double x, y;
        dataStream >> x >> y;
        house.AddPoint(x, y);
    }
    else if (command == "wall")
    {
        int s, f;
        dataStream >> s >> f;
        house.AddWall(s, f);
    }
    else
    {
        double l, r, t, b = 0;
        if (command == "window")
            dataStream >> l >> r >> t >> b;
        else if(command == "door")
            dataStream >> l >> r >> t;
        else
            break;
        //house.AddHole();
    }
}

void Scene::WriteData(std::ostream &dataStream)
{
    int pointIndex = 1;
    for (const auto &polygon : house.GetPolygonMesh())
    {
        std::vector<int> polygonIndexes;
        for (const auto &point : polygon.points)
        {
            dataStream << "v " << point.x << " " << point.y << " " << point.z << std::endl;
            polygonIndexes.push_back(pointIndex);
            ++pointIndex;
        }
        dataStream << "f ";
        for (const auto &index : polygonIndexes)
            dataStream << index << " ";
        dataStream << std::endl;
    }
}
