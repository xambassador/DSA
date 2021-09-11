/*
n = 4

      *
    * *
  * * *
* * * *

*/

function pattern(n) {
  let ans = "";
  let row = 1;

  while (row <= n) {
    let space = 1;
    while (space <= n - row) {
      ans += " ";
      space++;
    }

    let col = 1;
    while (col <= row) {
      ans += "*";
      col++;
    }

    row++;
    ans += "\n";
  }

  console.log(ans);
}

pattern(4);
pattern(20);
