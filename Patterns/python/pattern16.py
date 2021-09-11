# n = 5

# E
# D E
# C D E
# B C D E
# A B C D E

n = int(input())
row = 1
startChar = 65 + n - 1
while row <= n:
    col = 1
    val = startChar
    while col <= row:
        print(chr(val), end="")
        col += 1
        val += 1
    row += 1
    startChar -= 1
    print("")
