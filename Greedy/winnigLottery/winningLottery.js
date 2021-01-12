(function(){

    let s = 9;
    let d = 2;

    let arr = [];
    for(let i = 0; i<d; i++) arr[i] = 0;
    arr[0] = 1;
    s = s - 1;
    let i = d-1;
    while(i >=0) {
        if(i === 0) {
            arr[i] += s;
        }
        if(s > 9) {
            arr[i] = 9;
            s -= 9;
        } else if(s <= 9) {
            arr[i] += s;
            s = 0;
        }
        i--;
    }
    let ans = arr.join("");
    console.log(ans);
}());