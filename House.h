#ifndef HOUSE_H
#define HOUSE_H

#include <vector>

#include "Wall.h"
#include "Geometry.h"

class House
{
public:
    inline void SetHeight(double h) { height = h; }

    void AddPoint(double x, double y);
    void AddWall(int start, int end);
    void AddHole(double left, double right, double top, double bottom = 0);

    const std::vector<Polygon>& GetPolygonMesh();

private:
    void updateOutputMesh();

    double height;
    std::vector<Point2D> inputPoints;
    std::vector<Wall> walls;
    std::vector<Polygon> outputMesh;
    bool needsUpdate = false;
};

#endif // HOUSE_H
