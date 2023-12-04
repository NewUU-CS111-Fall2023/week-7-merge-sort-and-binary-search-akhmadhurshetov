def calculate_beautifulness(permutation):
    """Calculates the beautifulness of the given permutation."""
    return sum(abs(p - i - 1) for i, p in enumerate(permutation))

# 
#   Author: Axmad Xurshetov
#   Date: 04.12.2023
#   Name: task 2
# 
def max_beautifulness_after_swap(permutation):
    """Calculates the maximum beautifulness after at most one swap."""
    n = len(permutation)
    initial_beautifulness = calculate_beautifulness(permutation)
    max_beautifulness = initial_beautifulness

    for i in range(n):
        for j in range(i + 1, n):
            # Swap elements at indices i and j
            permutation[i], permutation[j] = permutation[j], permutation[i]
            # Calculate beautifulness after the swap
            new_beautifulness = calculate_beautifulness(permutation)
            max_beautifulness = max(max_beautifulness, new_beautifulness)
            # Swap back to original
            permutation[i], permutation[j] = permutation[j], permutation[i]

    return max_beautifulness

# Sample input
n = 5
permutation = [1, 4, 2, 3, 5]

# Calculate the maximum beautifulness
max_beautifulness_after_swap(permutation)
