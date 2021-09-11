/*
N is always odd

n = 7

   *
  ***
 *****
*******
 *****
  ***
   *

*/

function pattern(n) {
  let ans = "";

  let upperTriangleRows = Math.floor(n / 2) + 1;
  let lowerTriangleRows = Math.floor(n / 2);

  let row = 1;
  while (row <= upperTriangleRows) {
    let space = 1;
    while (space <= upperTriangleRows - row) {
      ans += " ";
      space++;
    }

    let col = 1;
    while (col <= row) {
      ans += "*";
      col++;
    }

    col = 1;
    while (col <= row - 1) {
      ans += "*";
      col++;
    }

    row++;
    ans += "\n";
  }

  row = 1;
  while (row <= lowerTriangleRows) {
    let space = 1;
    while (space <= row) {
      ans += " ";
      space++;
    }

    let col = 1;
    while (col <= lowerTriangleRows - row + 1) {
      ans += "*";
      col++;
    }

    col = 1;
    while (col <= lowerTriangleRows - row) {
      ans += "*";
      col++;
    }

    row++;
    ans += "\n";
  }

  console.log(ans);
}

pattern(7);
pattern(11);
pattern(21);
