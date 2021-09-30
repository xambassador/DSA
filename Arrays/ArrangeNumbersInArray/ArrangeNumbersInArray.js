(function () {
  let n = 10;
  const arr = [];

  let start = 0,
    end = n - 1,
    number = 1;

  while (start <= end) {
    if (start === end) {
      arr[start] = number;
      start++;
      end++;
    }

    arr[start++] = number++;
    arr[end--] = number++;
  }

  console.log(arr);
})();
