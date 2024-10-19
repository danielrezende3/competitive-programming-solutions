"""
You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.
On each move, you may increase the value of any element by one. What is the minimum number of moves required?
"""
# input
n = int(input())
a = list(map(int, input().split()))

# open file
# f = open("Increasing_Array_test1.txt", "r")
# n = int(f.readline())
# a = list(map(int, f.readline().split()))

count = 0
flag = True
while flag:
    flag = False
    for i in range(n - 1):
        if a[i] > a[i + 1]:
            diff = a[i] - a[i + 1]
            a[i + 1] += diff
            flag = True
            count += diff
            

print(count)
