(function() {


    /* 
    Time complexity : O(n^2) 
    Space complexity : O(n)
    */
    function maxProfit(arr,n) {
        let dp = [];
        dp[0] = arr[0].profit;
        for(let i = 1; i<n; i++) {
            let currentJobProfit = arr[i].profit;
            for(let j = i-1; j>=0; j--) {
                if(arr[j].endTime <= arr[i].startTime) {
                    currentJobProfit += dp[j];
                    break;
                }
            }
            dp[i] = Math.max(currentJobProfit, dp[i-1]);
        }
        return dp[n-1];
    }



    function search(arr,start,end,currentJobIndex) {
        if (start > end) return -1; 

        let mid = parseInt((start + end) / 2);
        if (arr[mid].endTime <= arr[currentJobIndex].startTime) {
            if(arr[mid+1].endTime <= arr[currentJobIndex].startTime) {
                return search(arr,mid+1,end,currentJobIndex);
            } else {
                return mid;
            }
        } else {
            return search(arr,start, mid-1, currentJobIndex);
        }
    }

    function maxProfit1(arr,n) {
        let dp = [];
        dp[0] = arr[0].profit;
        for(let i = 1; i<n; i++) {
            let currentJobIndex = arr[i].profit;
            let lastConflictJobIndex = search(arr,0,i-1,i);
            if(lastConflictJobIndex != -1) {
                currentJobIndex += dp[lastConflictJobIndex];
            }
            dp[i] = Math.max(dp[i-1], currentJobIndex);
        }
        return dp[n-1];
    }



    (function main(){

        let n = 4;
        let startTime = [3,1,6,2];
        let endTime = [10,2,19,100];
        let profit = [20,50,100,200];

        let arr = [];
        for(let i = 0; i<n; i++) {
            let job = {};
            job.startTime = startTime[i];
            job.endTime = endTime[i];
            job.profit = profit[i];
            arr.push(job);
        }

        arr.sort((a,b) => {
            return a.endTime - b.endTime;
        });

        let ans = maxProfit(arr,n);
        console.log(ans);
        ans = maxProfit1(arr,n);
        console.log(ans);

    }());




}());