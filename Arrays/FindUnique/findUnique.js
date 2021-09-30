(function () {
  const arr = [1, 2, 2, 1, 3, 5, 3, 4, 5];
  let ans = undefined;
  for (let i in arr) {
    let isCurrentElementIsFound = false;

    for (let j in arr) {
      if (i === j) continue;

      if (arr[i] === arr[j]) {
        isCurrentElementIsFound = true;
        break;
      }
    }

    if (!isCurrentElementIsFound) {
      ans = arr[i];
      break;
    }
  }

  console.log(ans);
})();
