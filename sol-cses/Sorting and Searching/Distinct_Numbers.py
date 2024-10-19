# Function to calculate the number of distinct values
def count_distinct_values(n, values):
    distinct_values = set(values)
    return len(distinct_values)

# Input
n = int(input())
values = list(map(int, input().split()))

# Output
result = count_distinct_values(n, values)
print(result)
