N = int(input())

x = 0

while N % 3 == 0:
    N = N / 3
    x = x + 1
print(N)
