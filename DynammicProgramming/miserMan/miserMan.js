(function () {
  function minimum_fair(arr, n, m, i, j) {
    // base case, if we rich to destination
    if (i == n) {
      return 0;
    }

    let option1 = minimum_fair(arr, n, m, i + 1, j) + arr[i][j];
    let option2 = Number.MAX_SAFE_INTEGER;
    if (j + 1 < m) {
      option2 = minimum_fair(arr, n, m, i + 1, j + 1) + arr[i][j];
    }

    let option3 = Number.MAX_SAFE_INTEGER;
    if (j - 1 >= 0) {
      option3 = minimum_fair(arr, n, m, i + 1, j - 1) + arr[i][j];
    }
    let ans = Math.min(option1, option2, option3);
    return ans;
  }

  (function main() {
    let n = 5;
    let m = 5;
    let arr = [
      [1, 3, 1, 2, 6],
      [10, 2, 5, 4, 15],
      [10, 9, 6, 7, 1],
      [2, 7, 1, 5, 3],
      [8, 2, 6, 1, 9],
    ];

    let minimum = Number.MAX_SAFE_INTEGER;
    for (let bus = 0; bus < m; bus++) {
      minimum = Math.min(minimum, minimum_fair(arr, n, m, 0, bus));
    }

    console.log(minimum);
  })();
})();
