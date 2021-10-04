(function () {
  arr1 = [6, 9, 8, 5];
  arr2 = [9, 2, 4, 8, 1];
  ans = "";

  for (let i in arr1) {
    for (let j in arr2) {
      if (arr1[i] === arr2[j]) {
        ans += arr2[j] + " ";
        arr2[j] = Number.NEGATIVE_INFINITY;
        break;
      }
    }
  }

  console.log(ans);
})();
