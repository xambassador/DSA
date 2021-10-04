(function () {
  let arr = [1, 3, 6, 2, 5, 4, 3, 2, 4];
  let x = 7;
  let ans = 0;

  for (let i = 0; i < arr.length; i++) {
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[i] + arr[j] == x) {
        ans++;
      }
    }
  }

  console.log(ans);
})();
