#include "triangle.h"

int main() {
    int choice;
    std::cout << "Choose an option:" << std::endl;
    std::cout << "1. Use default triangle and point" << std::endl;
    std::cout << "2. Enter triangle and points manually" << std::endl;
    std::cout << "Enter your choice:   ";
    std::cin >> choice;

    Triangle triangle;
    std::vector<Point> points;

    if (choice == 1) {
        // for testing purposes
        triangle = Triangle(Point(0, 0), Point(5, 0), Point(2, 5));
        points.push_back(Point(0, 0));
    } else {
        // Reading points and triangle
        triangle = readTriangle();
        if (triangle.isDegenerate()) {
            std::cout << "Warning: The triangle is degenerate (area = 0)." << std::endl;
            std::cout << "\t [area - S]\n" << std::endl;
        }
        points = readPoints();
        //got rid of readPoint that reads only one point. more versatile to use vector
    }

    // Letting user know that triangle is degenerate


    // Process each point
    for (size_t i = 0; i < points.size(); i++) {
        const Point& p = points[i];
        std::cout << "Point " << (i + 1) << " (" << p.x << ", " << p.y << "): ";

        Triangle::PointLocation location = triangle.contains(p);

        switch (location) {
            case Triangle::INSIDE:
                std::cout << "The point is inside the triangle." << std::endl;
            break;
            case Triangle::ON_BOUNDARY:
                std::cout << "The point is on the boundary of the triangle." << std::endl;
            break;
            case Triangle::OUTSIDE:
                std::cout << "The point is outside the triangle." << std::endl;
            break;
        }
    }

    return 0;
}