/*
n = 3
    1
  2 3 2
3 4 5 4 3

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

    let val = row;
    let col = 1;
    while (col <= row) {
      ans += val;
      val++;
      col++;
    }

    col = 1;
    val -= 2;
    while (col <= row - 1) {
      ans += val;
      val--;
      col++;
    }

    row++;
    ans += "\n";
  }

  console.log(ans);
}

pattern(3);
pattern(4);
