/*
n = 4

1
2 1
3 2 1
4 3 2 1

*/

function pattern(n) {
  let ans = "";
  let row = 1;

  while (row <= n) {
    let col = 1;
    let val = row;
    while (col <= row) {
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
pattern(15);
