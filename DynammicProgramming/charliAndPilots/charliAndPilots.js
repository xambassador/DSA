(function(){


    function minSalary(captain, assistant, n, start, X) {
        if (start === n) {
            return 0;
        }

        let ans;
        if (X === 0) {
            ans = minSalary(captain,assistant,n,start+1, X+1) + assistant[start];
        } else if (X === n - start) {
            ans = minSalary(captain,assistant,n,start+1, X-1) + captain[start];
        } else {
            let option1 = minSalary(captain,assistant,n,start+1,X+1) + assistant[start];
            let option2 = minSalary(captain,assistant,n,start+1, X-1) + captain[start];
            ans = Math.min(option1, option2);
        }
        return ans;
    }


    (function main(){

        let n = 4;
        let captain = [5000,6000,8000,9000];
        let assistant = [3000,2000,1000,6000];

        let ans = minSalary(captain,assistant,n,0,0);
        console.log(ans);

    }());



}());