#ifndef WALL_H
#define WALL_H

#include <vector>

#include "Geometry.h"

class Wall
{
public:
    Wall(const Point2D &start, const Point2D &end, double h);

    void AddHole(double left, double right, double top, double bottom);

    std::vector<Polygon> GetPolygonMesh() const;

private:
    Point2D startPoint;
    Point2D endPoint;
    double height;

    struct HolePosition;
    std::vector<HolePosition> holes;
};

struct Wall::HolePosition
{
    HolePosition(double l, double r, double t, double b);
    double left, right, top, bottom;
};

#endif // WALL_H
