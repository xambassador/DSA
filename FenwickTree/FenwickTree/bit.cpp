#include<iostream>
using namespace std;


void update(int index, int value, int* BIT, int n) {
    for (; index <= n; index += (index) & (-index)) {
        BIT[index] += value;
    }
}


int query(int index, int*& BIT) {
    int sum {};
    for (; index>0; index -= index & (-index)) {
        sum += BIT[index];
    }

    return sum;
}


int main() {
    int n;
    cin >> n;

    int* arr {new int[n+1]()};
    int* BIT {new int[n+1]()};


    for (int i{1}; i<n; i++) {
        cin >> arr[i];
        update(i, arr[i], BIT, n);   
    }


    cout << "Sum of elements from range 0 to 5 : => " << query(5,BIT) << endl; 
    cout << "Sum of elements from range 3 to 5 : => " << query(5,BIT) - query(2,BIT) << endl; 
}