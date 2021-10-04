(function () {
  let arr = [1, 2, 3, 4, 5, 6, 7];
  let x = 12;
  let ans = 0;

  for (let i = 0; i < arr.length; i++) {
    for (let j = i + 1; j < arr.length; j++) {
      for (let k = j + 1; k < arr.length; k++) {
        if (arr[i] + arr[j] + arr[k] === x) ans++;
      }
    }
  }

  console.log(ans);
})();
