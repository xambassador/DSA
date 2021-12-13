
from sys import stdin

# Recursive solution
def isPalindromeRec(string, start, end):
    # If string is empty or contains only one character
    if start > end or start == end:
        return True

    # My Calculation
    if string[start] == string[end]:
        return isPalindromeRec(string, start + 1, end - 1)
    else:
        return False

# Iterative Solution
def isPalindrome(string):
    start = 0
    end = len(string) - 1
    while start <= end:
        if string[start] != string[end]:
            return False
        start += 1
        end -= 1
    return True

if __name__ == "__main__":
    string = stdin.readline().strip();
    # ans = isPalindrome(string)
    ans = isPalindromeRec(string, 0, len(string) - 1)
    if ans :
        print('true')
    else :
        print('false')
