# n = 4

# A
# B C
# C D E
# D E F G

n = int(input())
row = 1
startChr = 65
while row <= n:
    col = 1
    val = startChr
    while col <= row:
        print(chr(val), end="")
        col += 1
        val += 1
    row += 1
    startChr += 1
    print("")
