import sys

def duplicateNumber1(arr, n):
    arr.sort()
    for i in range(n):
        if i+1 < n and arr[i] == arr[i+1]:
            return arr[i]
    return -1

def duplicateNumber(arr, n) :
    for i in range(n):
        isCurrentElementFound = False
        for j in range(n):
            if i == j:
                continue
            if arr[i] == arr[j]:
                isCurrentElementFound = True
                break
        
        if isCurrentElementFound:
            return arr[i]
    return -1


def takeInput() :
    n = int(sys.stdin.readline().strip())

    if n == 0 :
        return list(), 0

    arr = list(map(int, sys.stdin.readline().strip().split()))
    return arr, n

t = int(sys.stdin.readline().strip())

while t > 0 :
    
    arr, n = takeInput()
    print(duplicateNumber(arr, n))
    print(duplicateNumber1(arr, n))

    t -= 1
    