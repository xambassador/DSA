# n = 4

# 4 4 4 4
# 3 3 3
# 2 2 
# 1

n = int(input())
row = 1
while row <= n:
    col = 1
    while col <= n - row + 1:
        print(n - row + 1, end="")
        col += 1
    row += 1
    print("")