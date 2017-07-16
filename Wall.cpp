#include "Wall.h"

Wall::Wall(const Point2D &start, const Point2D &end, double h)
    : startPoint(start), endPoint(end), height(h)
{}

void Wall::AddHole(double left, double right, double top, double bottom)
{
    holes.push_back(HolePosition(left, right, top, bottom));
}

std::vector<Polygon> Wall::GetPolygonMesh() const
{
    std::vector<Polygon> mesh;
    mesh.push_back(Polygon());
    mesh[0].points.push_back(Point3D(startPoint, 0));
    mesh[0].points.push_back(Point3D(startPoint, height));
    mesh[0].points.push_back(Point3D(endPoint, height));
    mesh[0].points.push_back(Point3D(endPoint, 0));

    return mesh;
}

Wall::HolePosition::HolePosition(double l, double r, double t, double b)
    : left(l), right(r), top(t), bottom(b)
{}
