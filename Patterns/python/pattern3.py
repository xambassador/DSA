# n = 4
# 1234
# 1234
# 1234
# 1234

n = int(input())
row = 1
while row <= n:
    col = 1
    while col <= n:
        print(col, end="")
        col += 1
    row += 1
    print("")
    