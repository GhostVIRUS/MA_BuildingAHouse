#include "House.h"

void House::AddPoint(double x, double y)
{
    inputPoints.push_back(Point2D(x, y));
}

void House::AddWall(int start, int end)
{
    walls.push_back(Wall(inputPoints[start-1], inputPoints[end-1], height));
}

std::vector<Polygon> House::GetPolygonMesh() const // I feel like this design sucks
{
    std::vector<Polygon> mesh;
    for (const auto &wall : walls)
    {
        auto wallMesh = wall.GetPolygonMesh(); // Too much copying probably
        mesh.insert(mesh.end(), wallMesh.begin(), wallMesh.end());
    }
    // TODO: append ceiling and floor
    return mesh;
}
