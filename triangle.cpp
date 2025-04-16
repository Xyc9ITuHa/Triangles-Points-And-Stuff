//
// Created by хус on 16.04.2025.
//

#include "triangle.h"
//if you see this than you can read. WOW.
double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
} // V((x2-x1)^2 + (y2-y1)^2) vector product

bool Triangle::isDegenerate() const {
    return fabs(area()) < 1e-9;
} //comparing absolute value of triagnle are with 0.00000001 (or smth like that)
//if smaller, then its degenerate

double Triangle::area() const {
    double a = distance(A, B);
    double b = distance(B, C);
    double c = distance(C, A);

    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Triangle::crossProduct(const Point &A, const Point &B, const Point &C) const {
    // Calculate the cross product (A-C) × (B-C)
    return (A.x - C.x) * (B.y - C.y) - (A.y - C.y) * (B.x - C.x);
}

bool Triangle::isPointOnSegment(const Point &P, const Point &segStart, const Point &segEnd) const {
    // Check if point P lies on the line segment between segStart and segEnd
    double d1 = distance(P, segStart);
    double d2 = distance(P, segEnd);
    double segLength = distance(segStart, segEnd);

    // Check if the point is collinear with the segment endpoints and within the segment bounds
    return fabs(d1 + d2 - segLength) < 1e-9;
}

Triangle::PointLocation Triangle::contains(const Point &P) const {
    // First check if the triangle is degenerate
    if (isDegenerate()) {
        // For a degenerate triangle, check if the point lies on the line formed by the vertices
        if (isPointOnSegment(P, A, B) || isPointOnSegment(P, B, C) || isPointOnSegment(P, C, A)) {
            return ON_BOUNDARY;
        }
        return OUTSIDE;
    }

    // Check if point is on any of the edges
    if (isPointOnSegment(P, A, B) || isPointOnSegment(P, B, C) || isPointOnSegment(P, C, A)) {
        return ON_BOUNDARY;
    }

    // Using vector cross product method
    // The point is inside the triangle if all cross products have the same sign
    // (i.e., the point is on the same side of each edge)
    double cp1 = crossProduct( A, B, P);
    double cp2 = crossProduct(B, C, P);
    double cp3 = crossProduct(C, A, P);

    // all positive or all negative should mean that point is inside
    if ((cp1 > 0 && cp2 > 0 && cp3 > 0) || (cp1 < 0 && cp2 < 0 && cp3 < 0)) {
        return INSIDE;
    }
    //else if none of the above fits its outside
    return OUTSIDE;
}
// super random message to test commits and pushing
Triangle readTriangle() {
    Triangle t; //create triangle
    std::cout << "Enter the coordinates of triangle vertices:" << std::endl;

    // input user data to Point A > x and y
    std::cout << "Vertex A (x y): ";
    std::cin >> t.A.x >> t.A.y;

    // input user data to Point A > x and y
    std::cout << "Vertex B (x y): ";
    std::cin >> t.B.x >> t.B.y;

    // input user data to Point A > x and y
    std::cout << "Vertex C (x y): ";
    std::cin >> t.C.x >> t.C.y;

    return t;
}

// useless because replaced by better readPoints that writes them to vector
Point readPoint() {
    Point p;
    std::cout << "Enter point coordinates (x y): ";
    std::cin >> p.x >> p.y;
    return p;
}


std::vector<Point> readPoints() {
    std::vector<Point> points;
    int n;

    std::cout << "Enter the number of points to check: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cout << "Enter coordinates for point " << (i + 1) << " (x y): ";
        Point p;
        std::cin >> p.x >> p.y;
        points.push_back(p);
    }

    return points;
}