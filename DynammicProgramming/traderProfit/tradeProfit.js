(function () {


    function maxProfit(arr, n, start, k, isTransactionOngoing) {
        // base case
        if (start === n) {
            return 0;
        }

        // not buying stock
        let option1 = maxProfit(arr,n,start+1, k, isTransactionOngoing);
        let option2 = Number.MIN_SAFE_INTEGER;
        let option3 = Number.MIN_SAFE_INTEGER;

        // i can buy stock on that day
        if (isTransactionOngoing) {
            option2 = maxProfit(arr,n,start+1,k-1,false) + arr[start];
        } else {
            if (k > 0) {
                option3 = maxProfit(arr,n,start+1,k,true) - arr[start];
            }
        }

        let ans = Math.max(option1, option2, option3);
        return ans;
    }    

    (function main(){

        let k = 2;
        let n = 6;
        let arr = [10,22,5,75,65,80];
        let ans = maxProfit(arr,n,0,k,false);
        console.log(ans);
    }());

}());