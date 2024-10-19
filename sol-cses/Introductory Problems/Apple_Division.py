def min_difference(weights, index, group1_sum, group2_sum):
    # Base case: if all apples are considered
    if index == len(weights):
        return abs(group1_sum - group2_sum)

    # Recursive case: include the current apple in the first group
    diff1 = min_difference(weights, index + 1, group1_sum + weights[index], group2_sum)

    # Recursive case: include the current apple in the second group
    diff2 = min_difference(weights, index + 1, group1_sum, group2_sum + weights[index])

    # Return the minimum difference between the two groups
    return min(diff1, diff2)


# Input: Number of apples
n = int(input())

# Input: Weights of each apple
weights = list(map(int, input().split()))

# Calculate and print the minimum difference
result = min_difference(weights, 0, 0, 0)
print(result)
