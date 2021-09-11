/*
n = 4

*
**
***
****

*/

function pattern(n) {
  let ans = "";

  let row = 1;

  while (row <= n) {
    let col = 1;

    while (col <= row) {
      ans += "*";
      col++;
    }

    ans += "\n";
    row++;
  }

  console.log(ans);
}

pattern(4);
pattern(10);
