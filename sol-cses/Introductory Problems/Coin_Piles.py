# Python

# Get the number of test cases
num_cases = int(input())

# Loop through each test case
for _ in range(num_cases):
    # Get the two numbers for this test case
    pile_sizes = list(map(int, input().split()))

    # Assign the larger number to 'larger_pile' and the smaller one to 'smaller_pile'
    larger_pile = max(pile_sizes)
    smaller_pile = min(pile_sizes)

    # Check if the larger pile is more than twice the size of the smaller pile
    # or if the sum of the piles is not divisible by 3
    if larger_pile > 2 * smaller_pile or (sum(pile_sizes) % 3 != 0):
        print("NO")
    else:
        print("YES")
