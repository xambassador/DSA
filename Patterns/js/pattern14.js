/*
n = 3

A
B B
C C C

*/

function pattern(n) {
  let ans = "";
  let row = 1;
  let startingCharacter = 65;
  while (row <= n) {
    let col = 1;

    while (col <= row) {
      ans += String.fromCharCode(startingCharacter) + " ";
      col++;
    }

    startingCharacter++;
    row++;
    ans += "\n";
  }

  console.log(ans);
}

pattern(3);
pattern(5);
