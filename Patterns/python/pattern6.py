# n = 4

# 1
# 2 3
# 4 5 6
# 7 8 9 10

n = int(input())
row = 1
val = 1
while row <= n:
    col = 1
    while col <= row:
        print(val, end="")
        col += 1
        val += 1
    row += 1
    print("")