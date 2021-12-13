from sys import stdin

def merge(arr, start, mid, end) :
    n = (mid - start) + 1
    m = end - mid
    left = [0] * n
    right = [0] * m

    for i in range(n) :
        left[i] = arr[i+start]

    for i in range(m) :
        right[i] = arr[mid + 1 + i]

    i, j, k = 0, 0, start

    while i < n and j < m :
        if left[i] <= right[j] :
            arr[k] = left[i]
            i += 1
            k += 1
        else :
            arr[k] = right[j]
            j += 1
            k += 1

    while i < n :
        arr[k] = left[i]
        k += 1
        i += 1

    while j < m :
        arr[k] = right[j]
        j += 1
        k += 1

def util(arr, start, end) :
    if start < end :
        mid = start + (end - start) // 2
        util(arr, start, mid)
        util(arr, mid+1, end)
        merge(arr, start, mid, end)

def sort01(arr,n) :
    util(arr, 0, n-1)

def sortZeroesAndOne(arr, n) :
    nextZero = 0
    for i in range(n) :
        if arr[i] == 0 :
            arr[nextZero], arr[i] = arr[i], arr[nextZero]
            nextZero += 1

def takeInput():
    n = int(stdin.readline().strip())

    if n == 0 :
        return list(), 0

    arr = list(map(int, stdin.readline().strip().split(" ")))
    return arr, n


def printList(arr, n) :
    for i in range(n) :
        print(arr[i], end = ' ')
    print()

if __name__ == "__main__":
    t = int(stdin.readline().strip())
    while t > 0 :
        arr, n = takeInput()
        sortZeroesAndOne(arr, n)
        printList(arr, n)
        sort01(arr,n)
        printList(arr,n)
        print()
        t -= 1
