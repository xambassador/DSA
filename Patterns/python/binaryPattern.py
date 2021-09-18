n = int(input())

row = 1
while row <= n:
    col = 1
    if row % 2 == 0:
        while col <= n - row + 1:
            print(0, end="")
            col += 1
    else:
        while col <= n - row + 1:
            print(1, end="")
            col += 1
    print("")
    row += 1