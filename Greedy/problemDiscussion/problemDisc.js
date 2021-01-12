(function(){

    let arr = [1,15,10]
    let k = 6;
    let n = arr.length;
    arr.sort(function(a,b) {
        if(a < b) return -1;
    });
    let ans = arr[n-1] - arr[0];
    let small = arr[0] + k;
    let big = arr[n-1] - k;
    if(small > big) {
        [small, big] = [big, small];
    }
    for(let i = 1; i < n-1; i++) {
        let sub = arr[i] - k;
        let add = arr[i] + k;
        if(sub >= small || add <= big) continue;
        if(big-sub <= add - small) small = sub;
        else big = add;
    }
    ans = Math.min(ans, big-small);
    console.log(ans);

}());