#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>

struct Point2D
{
    Point2D(double ix, double iy);
    double x, y;
};

struct Point3D
{
    Point3D(double ix, double iy, double iz);
    Point3D(const Point2D &point2D, double iz);
    double x, y, z;
};

struct Polygon
{
    std::vector<Point3D> points;
};

#endif // GEOMETRY_H
