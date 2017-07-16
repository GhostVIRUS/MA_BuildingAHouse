#include "Scene.h"

#include <string>
//#include <map>

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

void Scene::WriteData(std::ostream &dataStream) const
{
    // This method was intended to ensure that every point has only 1 index in .obj file
    // That's obviously an overkill
    // I could complete it tho, but I am too lazy to overload the operator
    // And it turns out that it is not required
//    auto mesh = house.GetPolygonMesh();
//    std::map<Point3D, int> pointsMap; // define < operator for Point3D in order to finish this
//    int pointIndex = 1;
//    for (const auto &polygon : mesh)
//    {
//        std::vector<int> polygonIndexes;
//        for (const auto &point : polygon.points)
//        {
//            if (pointsMap.find(point) == pointsMap.end())
//            {
//                pointsMap[point] = pointIndex;
//                ++pointIndex;
//                dataStream << "v " << point.x << " " << point.y << " " << point.z << std::endl;
//            }
//            polygonIndexes.push_back(pointsMap.find(point)->second);
//        }
//        dataStream << "f ";
//        for (const auto &index : polygonIndexes)
//            dataStream << index << " ";
//        dataStream << std::endl;
//    }
    auto mesh = house.GetPolygonMesh();
    int pointIndex = 1;
        for (const auto &polygon : mesh)
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
