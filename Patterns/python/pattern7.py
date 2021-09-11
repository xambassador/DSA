# n = 4

#    1
#   23
#  456
# 78910

n = int(input())
row = 1
val = 1
while row <= n :
    space = 1
    while space <= n - row:
        print(" ", end="")
        space += 1
    
    col = 1
    while col <= row:
        print(val, end="")
        col += 1
        val += 1
    row += 1
    print("")
