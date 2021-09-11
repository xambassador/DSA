/*

n = 4

A B C D
A B C D
A B C D
A B C D

*/

function pattern(n) {
  let ans = "";
  let row = 1;

  while (row <= n) {
    let col = 1;
    let val = 65;
    while (col <= n) {
      ans += String.fromCharCode(val) + " ";
      col++;
      val++;
    }
    ans += "\n";
    row++;
  }

  console.log(ans);
}

pattern(4);
pattern(5);
