# N is always odd

# n = 7

#    *
#   ***
#  *****
# *******
#  *****
#   ***
#    *


n = int(input())

upperHalf = (n // 2) + 1
lowerHalf = n // 2

row = 1
while row <= upperHalf:
    space = 1
    while space <= upperHalf - row:
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

row = 1
while row <= lowerHalf:
    space = 1
    while space <= row:
        print(" ", end="")
        space += 1
    
    col = 1
    while col <= lowerHalf - row + 1:
        print("*", end="")
        col += 1
    
    col = 1
    while col <= lowerHalf - row:
        print("*", end="")
        col += 1
    row += 1
    print("")