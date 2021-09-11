/*
n = 4

1
2 3
4 5 6
7 8 9 10

*/

function pattern(n) {
  let row = 1;
  let val = 1;
  let ans = "";
  while (row <= n) {
    let col = 1;
    while (col <= row) {
      ans += val + " ";
      val++;
      col++;
    }
    ans += "\n";
    row++;
  }
  console.log(ans);
}

pattern(4);
pattern(10);
