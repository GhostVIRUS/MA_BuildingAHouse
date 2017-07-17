#include "House.h"

void House::AddPoint(double x, double y)
{
    inputPoints.push_back(Point2D(x, y));
}

void House::AddWall(int start, int end)
{
    walls.push_back(Wall(inputPoints[start-1], inputPoints[end-1], height));
    needsUpdate = true;
}

void House::AddHole(double left, double right, double top, double bottom)
{
    walls.end()->AddHole(left, right, top, bottom);
    needsUpdate = true;
}

const std::vector<Polygon>& House::GetPolygonMesh() // I feel like this design sucks
{
    updateOutputMesh();
    return outputMesh;
}

void House::updateOutputMesh()
{
    if (!needsUpdate)
        return;
    outputMesh.clear();
    for (auto &wall : walls)
    {
        const auto &wallPolygonMesh = wall.GetPolygonMesh();
        outputMesh.insert(outputMesh.end(),
                          wallPolygonMesh.begin(), wallPolygonMesh.end());
    }
    // TODO: append ceiling and floor
    needsUpdate = false;
}
