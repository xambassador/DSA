/*
n = 4

1
2 2
3 3 3
4 4 4 4

*/
function pattern(n) {
  let ans = "";
  let row = 1;

  while (row <= n) {
    let col = 1;

    while (col <= row) {
      ans += row + " ";
      col++;
    }

    row++;
    ans += "\n";
  }

  console.log(ans);
}

pattern(4);
pattern(8);
pattern(10);
