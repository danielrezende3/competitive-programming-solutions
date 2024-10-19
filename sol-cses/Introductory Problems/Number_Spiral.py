# open file input
# f_input = open("Introductory Problems/test_input.txt", "r")
# n = int(f_input.readline())
# save to output file
# f_output = open("Introductory Problems/test_output.txt", "w")
# teste = ""

# open terminal input
n = int(input())

# code
loop = 0
while loop < n:
    loop += 1
    i, j = map(int, input().split())

    if i == j:
        number = (i * j) - i + 1
    elif (i < j) and (j % 2 != 0):
        number = pow(j, 2) - i + 1
    elif (i < j) and (j % 2 == 0):
        number = pow(j - 1, 2) + i

    elif (i > j) and (i % 2 != 0):
        number = pow(i - 1, 2) + j

    elif (i > j) and (i % 2 == 0):
        number = pow(i, 2) - j + 1

    print(f"{number}")