# n = 4

#    1
#   212
#  32123
# 4321234

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
        val -= 1
        col += 1
    
    col = 1
    val += 2
    while col <= row - 1:
        print(val, end="")
        col += 1
        val += 1
    
    row += 1
    print("")