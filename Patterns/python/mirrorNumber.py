# n = 4
#       1
#     1 2
#   1 2 3
# 1 2 3 4

n = int(input())
row = 1
while row <= n:
    space = 1
    while space <= n - row:
        print(" ", end="")
        space += 1
    col = 1
    while col <= row:
        print(col, end="")
        col += 1
    
    row += 1
    print("")