
function blessing(s1,s2,k,dp) {
    if(k === 0) {
        return 0;
    }

    if(k > s1.length || k > s2.length) {
        return 0;
    }

    let m = s1.length;
    let n = s2.length;

    if(dp[m][n][k] != -1) {
        return dp[m][n][k];
    }

    let ans = 0;
    if(s1[0] === s2[0]) {
        let ascaiiValue = s1.charCodeAt(0);
        let option1 = blessing(s1.substr(1), s2.substr(1), k-1,dp);
        if(option1 === 0 && k > 1) {
            option1 = 0;
        }else {
            option1 += ascaiiValue;
        }
        let option2 = blessing(s1.substr(1), s2,k,dp);
        let option3 = blessing(s1, s2.substr(1),k,dp);
        ans = Math.max(option1, option2, option3);
    }else {
        let option1 = blessing(s1.substr(1),s2, k , dp);
        let option2 = blessing(s1,s2.substr(1), k, dp);
        ans = Math.max(option1, option2);
    }

    dp[m][n][k] = ans;
    return ans;
}


let s1 = "asdf";
let s2 = "asdf";
let k = 3;

let dp = [];
for(let i = 0; i<101; i++) {
    dp[i] = [];
    for(let j = 0; j<101; j++) {
        dp[i][j] = [];
        for(let k = 0; k<101; k++) {
            dp[i][j][k] = -1;
        }
    }
}

let ans = blessing(s1,s2,k,dp);
console.log(ans);
