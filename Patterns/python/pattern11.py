# n = 4

# *
# **
# ***
# ****

n = int(input())
row = 1
while row <= n:
    col = 1
    while col <= row:
        print("*", end="")
        col += 1
    row += 1
    print("")