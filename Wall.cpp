#include "Wall.h"

Wall::Wall(const Point2D &start, const Point2D &end, double h)
    : startPoint(start), endPoint(end), height(h), needsUpdate(true)
{}

void Wall::AddHole(double left, double right, double top, double bottom)
{
    holes.push_back(HolePosition(left, right, top, bottom));
    needsUpdate = true;
}

const std::vector<Polygon>& Wall::GetPolygonMesh()
{
    updateOutputMesh();
    return outputMesh;
}

void Wall::updateOutputMesh()
{
    if (!needsUpdate)
        return;
    outputMesh.clear();
    outputMesh.push_back(Polygon());
    outputMesh[0].points.push_back(Point3D(startPoint, 0));
    outputMesh[0].points.push_back(Point3D(startPoint, height));
    outputMesh[0].points.push_back(Point3D(endPoint, height));
    outputMesh[0].points.push_back(Point3D(endPoint, 0));
    needsUpdate = false;
}

Wall::HolePosition::HolePosition(double l, double r, double t, double b)
    : left(l), right(r), top(t), bottom(b)
{}
