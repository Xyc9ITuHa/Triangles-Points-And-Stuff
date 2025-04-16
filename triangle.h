//
// Created by хус on 16.04.2025.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <vector>
#include <cmath>

// struct for point
// used both to determine points in struct Triangle and to input points for cheking
struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

// calculates distance between two points
double distance(const Point &p1, const Point &p2);

struct Triangle {
    Point A, B, C;

    Triangle(const Point &A = Point(), const Point &B = Point(), const Point &C = Point())
    : A(A), B(B), C(C) {}
    //constructor (makes empty triangles if no points were declared)

    bool isDegenerate() const; // Чи є трикутник дегенератом чи він розумий

    double area() const; // USE HERON
    // need better way to handle outputs

    enum PointLocation { // REMEMBEEEER. WHO. YOU. ARE. non-scoped enum with non specified type.
        INSIDE,
        ON_BOUNDARY,
        OUTSIDE
    }; // easy way to output things

    PointLocation contains(const Point &P) const; // check if contains point

    //HELPER FUNCTIONS
private:
    // if point is on a line segment
    bool isPointOnSegment(const Point &P, const Point &segmentStart, const Point &segmentEnd) const;

    //calculate the sign of cross product for point-in-triangle test
    double crossProduct(const Point &A, const Point &B, const Point &C) const;
};

//Reading triangle
Triangle readTriangle();

//Reading point
Point readPoint();

//Read multiple points. damn...
std::vector<Point> readPoints();

#endif //TRIANGLE_H
