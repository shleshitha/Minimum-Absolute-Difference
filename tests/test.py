import sys
import os

# Ensure the parent directory is in the Python path
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from solutions.solution import Solution


def run_test_case(arr, expected, test_num):
    sol = Solution()
    result = sol.minimumAbsDifference(arr)
    # Sort results for comparison since order matters
    result_sorted = sorted(result)
    expected_sorted = sorted(expected)
    
    if result_sorted == expected_sorted:
        print(f"✅ Test {test_num} passed.")
        return True
    else:
        print(f"❌ Test {test_num} failed.")
        print(f"Input: {arr}")
        print(f"Expected: {expected_sorted}")
        print(f"Got:      {result_sorted}")
        return False

def main():
    tests = [
        ([4, 2, 1, 3], [[1, 2], [2, 3], [3, 4]]),
        ([1, 3, 6, 10, 15], [[1, 3]]),
        ([3, 8, -10, 23, 19, -4, -14, 27], [[-14, -10], [19, 23], [23, 27]]),
        ([1, 1], [[1, 1]]),
        ([-1, -2, -3, -4], [[-4, -3], [-3, -2], [-2, -1]]),
        ([100, 200, 300, 400], [[100, 200], [200, 300], [300, 400]]),
        ([0, 5, 10, 15, 20], [[0, 5], [5, 10], [10, 15], [15, 20]]),
        ([-1000000, 1000000], [[-1000000, 1000000]]),
        ([1, 2], [[1, 2]]),
        # Large test case
        (list(range(-50000, 50000)), [[i, i+1] for i in range(-50000, 49999)]),
    ]

    passed = 0
    total = len(tests)

    for i, (arr, expected) in enumerate(tests, 1):
        if run_test_case(arr, expected, i):
            passed += 1

    print(f"\nSummary: Passed {passed} / {total} test cases.")

if __name__ == "__main__":
    main()
