#include "Geometry.h"

Point2D::Point2D(double ix, double iy) : x(ix), y(iy)
{}

Point3D::Point3D(double ix, double iy, double iz) : x(ix), y(iy), z(iz)
{}

Point3D::Point3D(const Point2D &point2D, double iz)
    : x(point2D.x), y(point2D.y), z(iz)
{}
