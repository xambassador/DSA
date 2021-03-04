#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

class Coder {
    public:
    int x;
    int y;
    int index;
};

bool compare(Coder c1, Coder c2) {
    if (c1.x == c2.x) {
        return c1.y < c2.y;
    }
    return c1.x < c2.x;
}


void update(int y, int* bit) {
    for (; y<=100000; y+= y & (-y)) {
        bit[y]++;
    }
}

int query(int y, int* bit) {
    int cnt{};
    for (; y>0; y -= y & (-y)) {
        cnt += bit[y];
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    Coder* arr {new Coder[n]};
    for (int i{}; i<n; i++) {
        cin >> arr[i].x >> arr[i].y;
        arr[i].index = i;
    }

    sort(arr, arr+n, compare);
    int* bit {new int[100001]};
    int* ans {new int[n]};
    for (int i{}; i<n;) {
        int endIndex {i};
        while (endIndex < n && arr[i].x == arr[endIndex].x && arr[i].y == arr[endIndex].y) endIndex++;
        for (int j{i}; j<endIndex; j++) {
            ans[arr[j].index] = query(arr[j].y,bit);
        }

        for (int j{i}; j<endIndex; j++) update(arr[j].y, bit);
        i = endIndex;
    }
    for (int i{}; i<n; i++) cout << ans[i] << endl;

    return 0;
}