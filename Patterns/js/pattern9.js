/*

n = 4

A B C D
B C D E
C D E F
D E F G

*/

function pattern(n) {
  let ans = "";
  let row = 1;
  let startingChar = 65;
  while (row <= n) {
    let col = 1;
    let val = startingChar;
    while (col <= n) {
      ans += String.fromCharCode(val) + " ";
      val++;
      col++;
    }
    startingChar++;
    row++;
    ans += "\n";
  }

  console.log(ans);
}

pattern(4);
pattern(10);
