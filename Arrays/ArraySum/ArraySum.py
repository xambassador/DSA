def sumOfArrayElements(arr):
    sum = 0
    for i in arr:
        sum += i
    return sum

if __name__ == "__main__":
    n = int(input())
    arr = [int(i) for i in input().split()]
    ans = sumOfArrayElements(arr)
    print(ans)
