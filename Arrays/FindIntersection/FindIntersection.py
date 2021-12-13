import sys

# O(n^2)
def intersections(arr1, n, arr2, m) :
    for i in range(n):
        for j in range(m):
            if arr1[i] == arr2[j]:
                print(arr1[i], end=" ")
                arr2[j] = -(sys.maxsize)
                break
    print()

def takeInput() :
    n = int(sys.stdin.readline().strip())
    if n == 0:
        return list(), 0

    arr = list(map(int, sys.stdin.readline().strip().split(" ")))
    return arr, n


if __name__ == "__main__":
    t = int(sys.stdin.readline().strip())
    while t > 0 :
        arr1, n = takeInput()
        arr2, m = takeInput()

        intersections(arr1, n, arr2, m)
        print()

        t -= 1
