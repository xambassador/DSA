#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct point {
    int x, y;
};

bool crosser(point p, point q, point r) {
    int x1{q.x - p.x};
    int y1{q.y - p.y};
    int x2{r.x - q.x};
    int y2{r.y - q.y};
    int value{(x1 * y2) - (y1 * x2)};
    return value < 0;
}

void convex_hull(point *points, int n) {
    vector<point> hull;
    int left {};
    for (int i{1}; i < n; i++) if (points[i].x < points[left].x) left = i;
    int p{left};
    do {
        hull.push_back(points[p]);
        int q{(p + 1) % n};
        for (int i{}; i < n; i++) if (crosser(points[p], points[q], points[i])) q = i;
        p = q;
    } while (p != left);
    for (auto i : hull) cout << i.x << " " << i.y << endl;
}

int main() {
    int n;
    cin >> n;
    int* arr_x{new int[n]};
    int* arr_y{new int[n]};
    for (int i{}; i < n; i++) cin >> arr_x[i];
    for (int i{}; i < n; i++) cin >> arr_y[i];
    point* points {new point[n]};
    for (int i{}; i < n; i++) {
        point p;
        p.x = arr_x[i];
        p.y = arr_y[i];
        points[i] = p;
    }
    convex_hull(points, n);
}
