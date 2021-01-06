#include<iostream>
#include<algorithm>

struct Job {
    int startTime;
    int endTime;
    int profit;
};


bool compare(Job a, Job b) {
    return a.endTime < b.endTime;
}

// Time complexity : O(n^2)
// Space complexity : O(n)
int maxProgfit(Job* arr, int n) {
    int dp[n];
    dp[0] = arr[0].profit;
    for(int i{1}; i<n; i++) {
        int lastNonConflictJob {};
        for(int j{i-1}; j>=0; j--) {
            if(arr[j].endTime <= arr[i].startTime) {
                lastNonConflictJob = j;
                break;
            }
        }
        dp[i] = std::max(dp[i-1], dp[lastNonConflictJob] + arr[i].profit);
    }
    return dp[n-1];
}


int search(Job* arr,int start, int end, int currentJobindex) {
    if (start > end) return -1;

    int mid {(start+end)/2};
    if(arr[mid].endTime <= arr[currentJobindex].startTime) {
        if(arr[mid+1].endTime <= arr[currentJobindex].startTime) {
            return search(arr,mid+1,end,currentJobindex);
        } else {
            return mid;
        }
    } else {
        return search(arr,start,mid-1,currentJobindex);
    }
}

// Time coplexity : O(n*logn)
int maxProfit2(Job* arr, int n) {
    int dp[n];
    dp[0] = arr[0].profit;
    for(int i{1}; i<n; i++) {
        int lastNonConflictJob {search(arr,0,i,i-1)};
        int currentJobProfit {arr[i].profit};
        if (lastNonConflictJob != -1) {
            currentJobProfit += dp[lastNonConflictJob];
        }
        dp[i] = std::max(dp[i-1], currentJobProfit);
    }
    return dp[n-1];
}


int main(){
    int n;
    std::cin >> n; 

    Job arr[n];

    for(int i{}; i<n; i++) {
        std::cin >> arr[i].startTime >> arr[i].endTime >> arr[i].profit;
    }

    std::sort(arr,arr+n, compare);
    int ans {maxProgfit(arr,n)};
    std::cout << ans << std::endl;
    std::cout << maxProfit2(arr,n) << std::endl;

}