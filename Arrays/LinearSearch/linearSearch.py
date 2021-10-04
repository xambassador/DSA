from sys import stdin

def linearSearch(arr, n, x) :
    #Your code goes here
    for i in range(len(arr)):
        if arr[i] == x:
            return i
    return -1


#Taking Input Using Fast I/O
def takeInput() :
    n = int(stdin.readline().strip())

    if n == 0 :
        return list(), 0

    arr = list(map(int, stdin.readline().rstrip().split(" ")))
    return arr, n


t = int(stdin.readline().strip())

while t > 0 :
    
    arr, n = takeInput()
    val = int(stdin.readline().strip())
    print(linearSearch(arr, n, val))
    t -= 1