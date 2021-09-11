/*
n = 4

   1
  212
 32123
4321234

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
    let val = row;
    while (col <= row) {
      ans += val;
      val--;
      col++;
    }

    col = 1;
    val += 2;
    while (col <= row - 1) {
      ans += val;
      val++;
      col++;
    }

    row++;
    ans += "\n";
  }

  console.log(ans);
}

pattern(4);
