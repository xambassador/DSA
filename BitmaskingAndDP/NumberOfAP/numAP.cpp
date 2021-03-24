#include<iostream>
#include<unordered_map>
using namespace std;
#define m 100001

int numofAP(int *arr, int n){
   	int ans {n+1};
    unordered_map<int, int>*map {new unordered_map<int, int>[n]};
    for(int i{}; i<n-1; i++) {
        for(int j{i+1}; j<n; j++) {
            int diff {arr[j]-arr[i]};
            map[i][diff] += 1;
            ans = (ans+1)%m;
        }
    }
    
    for(int i{n-3}; i>=0; i--) {
        for(int j{i+1}; j<n; j++) {
            int diff {arr[j]-arr[i]};
            map[i][diff] = (map[i][diff]%m+map[j][diff]%m)%m;
            ans = (ans%m+map[j][diff]%m)%m;
        }
    }
    
    delete [] map;
    return ans;
}

int main() {
    int N;
    cin >> N;

    int *arr { new int[N+1] };
    for(int i{}; i < N; i++) {
        cin >> arr[i];
    }
    cout << numofAP(arr, N) << endl;
    return 0;
}
