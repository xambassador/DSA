/*
n = 4

1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4


*/

function pattern(n) {
  let ans = "";
  let row = 1;

  while (row <= n) {
    let col = 1;

    while (col <= n) {
      ans += col + " ";
      col++;
    }

    ans += "\n";
    row++;
  }
  console.log(ans);
}

pattern(4);
