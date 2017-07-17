#ifndef WALL_H
#define WALL_H

#include <vector>

#include "Geometry.h"

class Wall
{
public:
    Wall(const Point2D &start, const Point2D &end, double h);

    void AddHole(double left, double right, double top, double bottom);

    const std::vector<Polygon>& GetPolygonMesh();

private:
    void updateOutputMesh();

    Point2D startPoint;
    Point2D endPoint;
    double height;

    struct HolePosition;
    std::vector<HolePosition> holes;
    std::vector<Polygon> outputMesh;
    bool needsUpdate;
};

struct Wall::HolePosition
{
    HolePosition(double l, double r, double t, double b);
    double left, right, top, bottom;
};

#endif // WALL_H
