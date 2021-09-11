# n = 4

# 1
# 2 2
# 3 3 3
# 4 4 4 4

n = int(input())
row = 1
while row <= n:
    col = 1
    while col <= row:
        print(row, end="")
        col += 1
    row += 1
    print("")
    