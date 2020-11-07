#include<iostream>
using namespace std;
 

bool solve(long long n, int k) {
    long long mrSharmaCount {};
    long long mrSinghCount {};
    long long totalBalls {n};
    while(totalBalls >= k) {
        mrSharmaCount += k;
        totalBalls -= k;
        mrSinghCount += totalBalls/10;
        totalBalls -=  totalBalls/10;
    }
    // if n < k, then remaining ball takes by mr sharma
    mrSharmaCount += totalBalls;
    if(n % 2 == 0) {
        if(mrSharmaCount >= n/2) {
            return true;
        }
    }else if(n % 2 != 0) {
        if(mrSharmaCount >= (n/2)+1) {
            return true;
        }
    }
    return false;
}


long long int minK(long long n) {
    long long minBall {1};
    long long maxBall {n};
    long long mid {(minBall+maxBall)/2};
    while(minBall+1 <= maxBall) {
        mid = (minBall+maxBall)/2;
        if(solve(n,mid)) {
            maxBall = mid;
        }else {
            minBall = mid;
        }
        if(maxBall - minBall == 1) {
            if(solve(n,minBall)) {
                return minBall;
            }
            return maxBall;
        }
    }
    return mid;
}


int main() {
    long long n;
    cin >> n;   
    if(n == 1) {
        cout << n << endl;
        return 0;
    }
    cout << minK(n);
}   