/*

n = 5

E
D E
C D E
B C D E
A B C D E

*/

function pattern(n) {
  let ans = "";
  let row = 1;
  let startingCharacter = 65 + n - 1;
  while (row <= n) {
    let col = 1;
    let val = startingCharacter;
    while (col <= row) {
      ans += String.fromCharCode(val) + " ";
      col++;
      val++;
    }

    startingCharacter--;
    row++;
    ans += "\n";
  }

  console.log(ans);
}

pattern(5);
pattern(8);
