# n = 4

# A B C D
# A B C D
# A B C D
# A B C D

n = int(input())

row = 1
while row <= n:
    col = 1
    startingCharacter = 65
    while col <= n:
        print(chr(startingCharacter), end="")
        startingCharacter += 1
        col += 1
    row += 1
    print("")