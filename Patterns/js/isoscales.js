/*

n = 4

      1
    1 2 1
  1 2 3 2 1
1 2 3 4 3 2 1

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
      ans += col;
      col++;
    }

    col = 1;
    let val = row - 1;
    while (col <= row - 1) {
      ans += val;
      col++;
      val--;
    }

    row++;
    ans += "\n";
  }

  console.log(ans);
}

pattern(4);
