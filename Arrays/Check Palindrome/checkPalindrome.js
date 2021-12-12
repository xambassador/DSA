// Iterative solution
function checkPalindrome(str) {
  let start = 0,
    end = str.length - 1;
  while (start <= end) {
    if (str[start] !== str[end]) return false;
    start++;
    end--;
  }
  return true;
}

// Recursive
function checkPalindromeRec(str, start, end) {
  // Base case: If string is empty or it contains only one character
  if (start > end || start === end) return true;

  // My calculation
  if (str[start] === str[end])
    return checkPalindromeRec(str, start + 1, end - 1);
  else return false;
}

(function () {
  const strings = ["abcdcba", "a", "ab", "racecar"];
  const ans1 = [];
  const ans2 = [];
  for (str of strings) {
    ans1.push(checkPalindrome(str));
    ans2.push(checkPalindromeRec(str, 0, str.length - 1));
  }
  console.log(ans1);
  console.log(ans2);
})();
