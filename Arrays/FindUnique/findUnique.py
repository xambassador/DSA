import sys

# O(nlogn)
def findUnique1(arr, n):
    arr.sort()
    i, j = 0, 1
    while i < n and j < n:
        if arr[i] != arr[j]:
            return arr[i]
        i += 2
        j += 2
    """
    There is chance where j cross range but i still point
    last index
    """
    if i < n and j >= n:
        return arr[i]

    return -1


def findUnique(arr, n) :
    for i in range(n):
        currentElement = arr[i]
        isCurrentElementFound = False
        for j in range(n):
            if i == j:
                continue
            if currentElement == arr[j]:
                isCurrentElementFound = True
                break

        if not isCurrentElementFound:
            return currentElement
    return -1


def takeInput() :
    n = int(sys.stdin.readline().rstrip())

    if n == 0 :
        return list(), 0

    arr = list(map(int, sys.stdin.readline().rstrip().split(" ")))
    return arr, n


if __name__ == "__main__":
    t = int(sys.stdin.readline().rstrip())

    while t > 0 :
        arr, n = takeInput()
        print(findUnique(arr, n))
        print(findUnique1(arr, n))
        t -= 1
