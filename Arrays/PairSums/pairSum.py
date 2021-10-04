from sys import stdin
import sys

def pairSum(arr, n, x) :
    ans = 0

    for i in range(n) :
        for j in range(i+1, n) :
            if arr[i] + arr[j] == x :
                ans += 1
    
    return ans


def takeInput() :
    n = int(stdin.readline().strip())
    if n == 0 :
        return list(), 0

    arr = list(map(int, stdin.readline().strip().split(" ")))
    return arr, n

t = int(stdin.readline().strip())

while t > 0 :
    
    arr, n = takeInput()
    x = int(stdin.readline().strip())
    print(pairSum(arr, n, x))

    t -= 1