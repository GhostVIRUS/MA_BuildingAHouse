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
    //void AddHole(double left, double right, double top, double bottom = 0);

    std::vector<Polygon> GetPolygonMesh() const;

private:
    double height;
    std::vector<Point2D> inputPoints;
    std::vector<Wall> walls;

};

#endif // HOUSE_H
