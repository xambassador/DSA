/*
n = 4

1
1 2
1 2 3 
1 2 3 4

*/

function pattern(n) {
  let row = 1;
  let ans = "";
  while (row <= n) {
    let val = 1;
    let col = 1;
    while (col <= row) {
      ans += val + " ";
      val++;
      col++;
    }

    ans += "\n";
    row++;
  }

  console.log(ans);
}

pattern(4);
pattern(10);
