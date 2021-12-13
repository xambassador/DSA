let weights = [1, 2, 4, 5];
let values = [5, 4, 8, 6];
let maxWeight = 5;

let ans = knapSack(weights, values, maxWeight);
console.log(ans);

// Bruteforce approach
function knapSackHelp(weight, value, maxWeight, start, end) {
  if (maxWeight === 0) {
    return 0;
  }

  if (start > end) {
    return 0;
  }

  let ans = 0;
  if (weight[start] <= maxWeight) {
    let ans1 =
      knapSackHelp(weight, value, maxWeight - weight[start], start + 1, end) +
      values[start];
    let ans2 = knapSackHelp(weight, value, maxWeight, start + 1, end);
    ans = Math.max(ans1, ans2);
  } else {
    ans = knapSackHelp(weight, value, maxWeight, start + 1, end);
  }

  return ans;
}

// Memoization

function knapSackMemo(weight, value, maxWeight, start, end, dp) {
  if (maxWeight === 0) {
    return 0;
  }

  if (start > end) {
    return 0;
  }

  if (dp[maxWeight][start] != -1) {
    return dp[maxWeight][start];
  }

  let ans = 0;
  if (weight[start] <= maxWeight) {
    let ans1 =
      knapSackMemo(
        weight,
        value,
        maxWeight - weight[start],
        start + 1,
        end,
        dp
      ) + values[start];
    let ans2 = knapSackMemo(weight, value, maxWeight, start + 1, end, dp);
    ans = Math.max(ans1, ans2);
  } else {
    ans = knapSackMemo(weight, value, maxWeight, start + 1, end, dp);
  }
  dp[maxWeight][start] = ans;
  return ans;
}

function knapSack(weight, values, maxWeight) {
  // return knapSackHelp(weight,values,maxWeight,0,weight.length-1);
  let dp = [];
  for (let i = 0; i <= maxWeight; i++) {
    dp[i] = [];
    for (let j = 0; j <= weights.length; j++) {
      dp[i][j] = -1;
    }
  }
  return knapSackMemo(weights, values, maxWeight, 0, weights.length, dp);
}
