# 
#   Author: Axmad Xurshetov
#   Date: 04.12.2023
#   Name: task 1
#  
def median_of_subarray(arr, length):
    """Finds the median of all odd-sized contiguous subarrays of the given array."""
    medians = []
    for i in range(length):
        for j in range(i, length, 2):
            subarray = arr[i:j+1]
            medians.append(sorted(subarray)[len(subarray)//2])
    return medians

def process_array(arr):
    """Processes the array as per the given rules and returns the sum of remaining elements."""
    while len(arr) > 2:
        medians = median_of_subarray(arr, len(arr))
        arr.remove(min(medians))
    return sum(arr)

def solve_problem(input_string):
    """Solves the problem for the given input string."""
    lines = input_string.strip().split('\n')
    num_test_cases = int(lines[0])
    results = []
    line_index = 1

    for _ in range(num_test_cases):
        n = int(lines[line_index])
        array = list(map(int, lines[line_index + 1].split()))
        result = process_array(array)
        results.append(result)
        line_index += 2

    return results
