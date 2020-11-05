#include<iostream>
#include<algorithm>
using namespace std;


bool isPossibleToDistribute(long long* arr, int n, long long k, long long candies) {
    long long tStudents {0};
    for(int i{}; i<n; i++) {
        long long d {arr[i]/candies};
        if(d > 0) tStudents += d;
    }
    if(tStudents >= k) return true;
    return false;
}


int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        long long k;
        cin >> k;
        long long arr[n];
        for(int i{}; i<n; i++) {
            cin >> arr[i];
        }


        long long ans {1};
        sort(arr,arr+n);
        long long minCandy {1};
        long long maxCandy {arr[n-1]};


        while(minCandy <= maxCandy) {
            long long mid {(minCandy + maxCandy)/2};
            if(isPossibleToDistribute(arr,n,k,mid)) {
                ans = mid;
                minCandy = mid+1;
            }else {
                maxCandy = mid-1;
            }
        }

        cout << ans << endl;
    }
}