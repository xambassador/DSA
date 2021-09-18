n = int(input())

row = 1
while row <= n:
    space = 1
    while space <= row - 1:
        print(" ", end="")
        space += 1

    col = 1
    val = row
    while col <= n - row + 1:
        print(val, end="")
        col += 1
        val += 1
    row += 1
    print("")

row = 1
while row <= n:
    if row == 1:
        row += 1
        continue
    
    space = 1
    while space <= n - row:
        print(" ", end="")
        space += 1
    
    col = 1
    val = n - row + 1
    while col <= row:
        print(val, end="")
        val += 1
        col += 1
    row += 1
    print("")