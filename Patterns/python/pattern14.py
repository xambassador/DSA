# n = 3

# A
# B B
# C C C

n = int(input())
row = 1
startChar = 65
while row <= n:
    col = 1
    while col <= row:
        print(chr(startChar), end="")
        col += 1
    row += 1
    startChar += 1
    print("")
