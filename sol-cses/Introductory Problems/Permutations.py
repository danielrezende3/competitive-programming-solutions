n = int(input())
flag = True
while flag:
    if n == 1:
        print(1)
        flag = False
    elif n == 2 or n == 3:
        print("NO SOLUTION")
        flag = False
    else:
        for i in range(2, n + 1, 2):
            print(i, end=" ")
        for i in range(1, n + 1, 2):
            print(i, end=" ")
        flag = False
