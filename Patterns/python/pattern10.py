# n = 4

# A B C D
# B C D E
# C D E F
# D E F G

n = int(input())
row = 1
startingChar = 65
while row <= n:
    col = 1
    val = startingChar
    while col <= n:
        print(chr(val), end="")
        val += 1
        col += 1
    row += 1
    startingChar += 1
    print("")
