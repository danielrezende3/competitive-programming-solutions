from math import floor, log


def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)


def trailing_zeros(n):
    return float(n) / 5.0


def find_zeros(n):
    counter = 0
    while n % 10 == 0.0:
        print(type(n))
        if n == 0.0:
            break
        counter += 1
        n = n / 10
    return counter


def summation(k, n):
    if k == 0:
        return 0
    else:
        return floor(n / (pow(5, k))) + summation(k-1,n)


n = int(input())
k = floor(log(n, 5))
print(summation(k, n))
