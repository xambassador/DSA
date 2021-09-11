/*
n = 4

A
B C
C D E
D E F G

*/

function pattern(n) {
  let ans = "";
  let row = 1;
  let startingCharacter = 65;

  while (row <= n) {
    let col = 1;
    let val = startingCharacter;
    while (col <= row) {
      ans += String.fromCharCode(val) + " ";
      col++;
      val++;
    }

    startingCharacter++;
    row++;
    ans += "\n";
  }

  console.log(ans);
}

pattern(4);
