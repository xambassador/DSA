
from sys import stdin


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
    ans = isPalindrome(string)

    if ans :
        print('true')
    else :
        print('false')
