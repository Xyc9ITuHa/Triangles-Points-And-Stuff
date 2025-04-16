#include "triangle.h"

using namespace std;
int main() {
    int choice;
    cout << "Choose an option:" << endl;
    cout << "1. Use default triangle and point" << endl;
    cout << "2. Enter triangle and points manually" << endl;
    cout << "Enter your choice:   ";
    cin >> choice;

    Triangle triangle;
    vector<Point> points;

    if (choice == 1) {
        // for testing purposes
        triangle = Triangle(Point(0, 0), Point(5, 0), Point(2, 5));
        points.push_back(Point(0, 0));
    } else {
        // Reading points and triangle
        triangle = readTriangle();
        if (triangle.isDegenerate()) {
            cout << "Warning: The triangle is degenerate (area = 0)." << endl;
            cout << "\t [area - S]\n" << endl;
        }
        points = readPoints();
        //got rid of readPoint that reads only one point. more versatile to use vector
    }

    // Letting user know that triangle is degenerate


    // Process each point
    for (size_t i = 0; i < points.size(); i++) {
        const Point& p = points[i];
        cout << "Point " << (i + 1) << " (" << p.x << ", " << p.y << "): ";

        Triangle::PointLocation location = triangle.contains(p);

        switch (location) {
            case Triangle::INSIDE:
                cout << "The point is inside the triangle." << endl;
            break;
            case Triangle::ON_BOUNDARY:
                cout << "The point is on the boundary of the triangle." << endl;
            break;
            case Triangle::OUTSIDE:
                cout << "The point is outside the triangle." << endl;
            break;
        }
    }

    return 0;
}