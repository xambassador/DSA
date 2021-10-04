(function () {
  let arr = [0, 1, 1, 0, 1, 0, 1];
  let nextZero = 0;

  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === 0) {
      let tmp = arr[i];
      arr[i] = arr[nextZero];
      arr[nextZero] = tmp;
      nextZero++;
    }
  }

  console.log(arr);
})();
