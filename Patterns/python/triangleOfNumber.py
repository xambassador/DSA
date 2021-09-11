# n = 3
#     1
#   2 3 2
# 3 4 5 4 3

n = int(input())
row = 1
while row <= n:
    space = 1
    while space <= n - row:
        print(" ", end="")
        space += 1

    col = 1
    val = row
    while col <= row:
        print(val, end="")
        col += 1
        val += 1
    
    val -= 2
    col = 1
    while col <= row - 1:
        print(val, end="")
        col += 1
        val -= 1
    
    row += 1
    print("")