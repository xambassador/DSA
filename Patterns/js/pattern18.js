/*
n = 4

****
***
**
*

*/

function pattern(n) {
  let ans = "";
  let row = 1;

  while (row <= n) {
    let col = 1;

    while (col <= n - row + 1) {
      ans += "*";
      col++;
    }

    row++;
    ans += "\n";
  }

  console.log(ans);
}

pattern(4);
pattern(10);
