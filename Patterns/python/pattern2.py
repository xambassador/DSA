# n = 4
# 1111
# 2222
# 3333
# 4444

n = int(input())
row = 1
while row <= n:
    col = 1
    while col <= n:
        print(row, end="");
        col+=1
    row += 1
    print("")