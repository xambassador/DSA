(function () {


    (function() {

        let arr = [1,1,1,3,3];
        arr.sort(function(a,b) {
            if(a < b) return -1;
        });

        let start = arr.length - 3;
        let mid = arr.length - 2;
        let end = arr.length - 1;
        while(start+mid <= end) {
            start--;
            mid--;
            end--;
            if(start < 0) {
                console.log("-1");
                return;
            }
        }
        console.log(arr[start], " ", arr[mid], " ", arr[end]);

    }());    
}());