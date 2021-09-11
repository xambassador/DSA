/*
n = 5

1234554321
1234**4321
123****321
12******21
1********1

*/
function pattern(n) {
  let ans = "";
  let row = 1;
  let starCol = 0;
  while (row <= n) {
    let col = 1;
    while (col <= n - row + 1) {
      ans += col;
      col++;
    }

    col = 1;
    while (col <= starCol) {
      ans += "*";
      col++;
    }

    starCol += 2;

    col = 1;
    let val = n - row + 1;
    while (col <= n - row + 1) {
      ans += val;
      val--;
      col++;
    }

    row++;
    ans += "\n";
  }

  console.log(ans);
}

pattern(5);
pattern(8);
