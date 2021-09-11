function pattern(n) {
  let ans = "";
  let row = 1;
  let val = 1;

  while (row <= n) {
    let space = n - row;
    let s = 1;
    while (s <= space) {
      ans += " ";
      s++;
    }
    let col = 1;
    while (col <= row) {
      ans += val;
      val++;
      col++;
    }

    ans += "\n";
    row++;
  }

  console.log(ans);
}

pattern(4);
