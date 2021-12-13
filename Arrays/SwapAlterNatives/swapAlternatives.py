from sys import stdin

def swapAlternate1(arr, n):
    for i in range(0, (n-1), 2):
        temp = arr[i]
        arr[i] = arr[i+1]
        arr[i+1] = temp


def swapAlternate(arr, n) :
    i = 0
    j = 1
    while i < n and j < n:
        arr[i], arr[j] = arr[j], arr[i]
        i += 2
        j += 2


def takeInput() :
    n = int(stdin.readline().rstrip())

    if n == 0 :
        return list(), 0

    arr = list(map(int, stdin.readline().rstrip().split(" ")))
    return arr, n

def printList(arr, n) :
    for i in range(n) :
        print(arr[i], end = " ")
    print()


if __name__ == "__main__":
    t = int(stdin.readline().rstrip())

    while t > 0 :
        arr, n = takeInput()
        if n != 0 :
            swapAlternate(arr, n)
            printList(arr, n)
        t -= 1
