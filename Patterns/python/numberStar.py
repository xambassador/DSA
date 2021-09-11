# n = 5

# 1234554321
# 1234**4321
# 123****321
# 12******21
# 1********1

n = int(input())
row = 1
starCol = 0
while row <= n:
    col = 1
    while col <= n - row + 1:
        print(col, end="")
        col += 1
    
    col = 1
    while col <= starCol:
        print("*", end="")
        col += 1
    
    starCol += 2

    col = 1
    val = n - row + 1
    while col <= n - row + 1:
        print(val, end="")
        val -= 1
        col += 1
    
    row += 1
    print("")