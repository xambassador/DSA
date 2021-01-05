(function(){



    function maxActivities(arr) {
        let currentTime = arr[0].et;
        let count = 1;
        for (let i of arr) {
            if (currentTime <= i.st) {
                count += 1;
                currentTime = i.et;
            }
        }
        return count;
    }


    (function main(){
        let startTime = [1,3,0,5,8,5];
        let endTime = [2,4,6,7,9,9];
        
        let arr = [];
        for(let i=0; i<startTime.length; i++) {
            let pair = {};
            pair.st = startTime[i];
            pair.et = endTime[i];
            arr.push(pair);
        }

        arr.sort((a,b)=>{
            if (a.et < b.et) {
                return -1;
            } else {
                return 1;
            }
        });

        let ans = maxActivities(arr);
        console.log(ans);

    }());
}());

