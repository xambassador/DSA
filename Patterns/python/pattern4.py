# n = 4
# 4321
# 4321
# 4321
# 4321

n = int(input())
row = 1
while row <= n:
    col = 1
    val = n
    while col <= n:
        print(val, end="")
        col += 1
        val -= 1
    row += 1
    print("")