# n = 4
# 1
# 2 1
# 3 2 1
# 4 3 2 1

n = int(input())
row = 1
while row <= n:
    col = 1
    val = row
    while col <= row:
        print(val, end="")
        val -= 1
        col += 1
    row += 1
    print("")