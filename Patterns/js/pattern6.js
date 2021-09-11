/*
n = 4

4 3 2 1
4 3 2 1
4 3 2 1
4 3 2 1

*/

function pattern(n) {
  let ans = "";
  let row = 1;

  while (row <= n) {
    let col = 1;

    while (col <= n) {
      ans += n - col + 1 + " ";
      col++;
    }

    ans += "\n";
    row++;
  }

  console.log(ans);
}

pattern(5);
pattern(4);
