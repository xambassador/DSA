#include<iostream>
#include<cmath>
using namespace std;

class Point {
    public:
    double x;
    double y;
};


class Polygon {
    public:
    Point* points;
    Polygon(int numberOfPoints) {
        this->points = new Point[numberOfPoints];
    }
};

double area(Polygon p, int n) {
    double totalArea {};
    for (int i{1}; i<n-1; i++) {
        double x1 {p.points[i].x - p.points[0].x};
        double x2 {p.points[i+1].x - p.points[0].x};
        double y1 {p.points[i].y - p.points[0].y};
        double y2 {p.points[i+1].y - p.points[0].y};
        double crossProduct {x1*y2 - y1*x2};
        totalArea += crossProduct;
    }

    return abs(totalArea / 2);
}

int main() {
    int n;
    cin >> n;
    Polygon p(n);
    for (int i{}; i<n; i++) cin >> p.points[i].x;
    for (int i{}; i<n; i++) cin >> p.points[i].y;
    cout << (int)area(p,n) << endl;
}