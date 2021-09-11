# n = 4

# 1
# 1 2
# 1 2 3 
# 1 2 3 4

n = int(input())
row = 1
while row <= n:
    col = 1
    while col <= row:
        print(col, end="")
        col += 1
    row += 1
    print("")