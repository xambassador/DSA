from sys import stdin

def arrange(arr, n) :
    number = 1
    start = 0
    end = n - 1

    while start <= end :
        if start == end:
            arr[start] = number
            start += 1
            end -= 1
            continue
        arr[start] = number
        number += 1
        arr[end] = number
        number += 1
        start += 1
        end -= 1


def printList(arr, n) :
    for i in range(n) :
        print(arr[i], end = ' ')
    print()

t = int(stdin.readline().strip())

while t > 0 :
    n = int(stdin.readline().strip())
    arr = n * [0]
    arrange(arr, n)
    printList(arr, n)
    t -= 1
