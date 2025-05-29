#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../solutions/solution.c" 
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes);

int compareResults(int** actual, int actualSize, int* actualColSizes,
                   int expected[][2], int expectedSize) {
    if (actualSize != expectedSize) return 0;
    for (int i = 0; i < expectedSize; i++) {
        if (actualColSizes[i] != 2) return 0;
        if (actual[i][0] != expected[i][0] || actual[i][1] != expected[i][1]) return 0;
    }
    return 1;
}

void printResult(int** res, int size, int* colSizes) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("[%d,%d]", res[i][0], res[i][1]);
        if (i != size - 1) printf(", ");
    }
    printf("]\n");
}

int passedTests = 0;
int totalTests = 0;

void runTest(int* arr, int n, int expected[][2], int expectedSize, int testNum) {
    totalTests++;

    int returnSize = 0;
    int* returnColumnSizes = NULL;

    int** result = minimumAbsDifference(arr, n, &returnSize, &returnColumnSizes);

    if (compareResults(result, returnSize, returnColumnSizes, expected, expectedSize)) {
        printf("✅ Test %d passed.\n", testNum);
        passedTests++;
    } else {
        printf("❌ Test %d failed.\nExpected: ", testNum);
        for (int i = 0; i < expectedSize; i++) {
            printf("[%d,%d]", expected[i][0], expected[i][1]);
            if (i != expectedSize - 1) printf(", ");
        }
        printf("\nGot     : ");
        printResult(result, returnSize, returnColumnSizes);
    }

    for (int i = 0; i < returnSize; i++) free(result[i]);
    free(result);
    free(returnColumnSizes);
}

// Special runner for large input (test 10)
void runLargeTest(int* arr, int n, int testNum) {
    totalTests++;

    int returnSize = 0;
    int* returnColumnSizes = NULL;

    int** result = minimumAbsDifference(arr, n, &returnSize, &returnColumnSizes);

    // Minimum difference should be 1 for consecutive numbers
    int expectedCount = n - 1;

    if (returnSize == expectedCount) {
        // Spot check first 5 pairs
        int correct = 1;
        for (int i = 0; i < 5 && i < returnSize; i++) {
            if (returnColumnSizes[i] != 2) {
                correct = 0;
                break;
            }
            if (result[i][0] != arr[i] || result[i][1] != arr[i] + 1) {
                correct = 0;
                break;
            }
        }
        if (correct) {
            printf("✅ Test %d passed.\n", testNum);
            passedTests++;
        } else {
            printf("❌ Test %d failed on spot check pairs.\n", testNum);
        }
    } else {
        printf("❌ Test %d failed on count. Expected %d pairs, got %d.\n", testNum, expectedCount, returnSize);
    }

    for (int i = 0; i < returnSize; i++) free(result[i]);
    free(result);
    free(returnColumnSizes);
}

int main() {
    int testNum = 1;

    int arr1[] = {4, 2, 1, 3};
    int exp1[][2] = {{1, 2}, {2, 3}, {3, 4}};
    runTest(arr1, 4, exp1, 3, testNum++);

    int arr2[] = {1, 3, 6, 10, 15};
    int exp2[][2] = {{1, 3}};
    runTest(arr2, 5, exp2, 1, testNum++);

    int arr3[] = {3, 8, -10, 23, 19, -4, -14, 27};
    int exp3[][2] = {{-14, -10}, {19, 23}, {23, 27}};
    runTest(arr3, 8, exp3, 3, testNum++);

    int arr4[] = {1, 1};
    int exp4[][2] = {{1, 1}};
    runTest(arr4, 2, exp4, 1, testNum++);

    int arr5[] = {-1, -2, -3, -4};
    int exp5[][2] = {{-4, -3}, {-3, -2}, {-2, -1}};
    runTest(arr5, 4, exp5, 3, testNum++);

    int arr6[] = {100, 200, 300, 400};
    int exp6[][2] = {{100, 200}, {200, 300}, {300, 400}};
    runTest(arr6, 4, exp6, 3, testNum++);

    int arr7[] = {0, 5, 10, 15, 20};
    int exp7[][2] = {{0, 5}, {5, 10}, {10, 15}, {15, 20}};
    runTest(arr7, 5, exp7, 4, testNum++);

    int arr8[] = {-1000000, 1000000};
    int exp8[][2] = {{-1000000, 1000000}};
    runTest(arr8, 2, exp8, 1, testNum++);

    int arr9[] = {1, 2};
    int exp9[][2] = {{1, 2}};
    runTest(arr9, 2, exp9, 1, testNum++);

    // Large input test
    int* arr10 = malloc(100000 * sizeof(int));
    for (int i = 0; i < 100000; i++) arr10[i] = i - 50000;
    runLargeTest(arr10, 100000, testNum++);
    free(arr10);

    printf("\nSummary: Passed %d / %d test cases.\n", passedTests, totalTests);

    return 0;
}
