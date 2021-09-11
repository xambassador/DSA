# n = 4

#    *
#   ***
#  *****
# *******

n = int(input())
row = 1
while row <= n:
    space = 1
    while space <= n - row:
        print(" ", end="")
        space += 1
    
    col = 1
    while col <= row:
        print("*", end="")
        col += 1
    
    col = 1
    while col <= row - 1:
        print("*", end="")
        col += 1
    
    row += 1
    print("")