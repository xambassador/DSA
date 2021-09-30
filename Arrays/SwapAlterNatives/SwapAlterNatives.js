(function () {
  const arr = [1, 2, 3, 4, 5, 6];

  for (let i = 0, j = 1; i < arr.length && j < arr.length; i += 2, j += 2) {
    let tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }

  console.log(arr);
})();
