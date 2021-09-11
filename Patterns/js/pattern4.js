/*
n = 4

1111
2222
3333
4444

*/

function pattern(n) {
  let ans = "";
  let row = 1;

  while (row <= n) {
    let col = 1;
    while (col <= n) {
      ans += row;
      col++;
    }
    ans += "\n";
    row++;
  }

  console.log(ans);
}

pattern(4);
pattern(10);
