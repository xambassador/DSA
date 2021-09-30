function linearSearch(arr, searchElement) {
  for (let index = 0; index < arr.length; index++) {
    if (arr[index] === searchElement) return index;
  }

  return -1;
}

(function () {
  const arr = [2, 13, 4, 1, 3, 6, 28];
  let searchElement = 3;

  console.log(linearSearch(arr, searchElement));
})();
