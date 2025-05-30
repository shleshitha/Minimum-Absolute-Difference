#include <stdlib.h>
#include <limits.h>

int cmpInt(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    qsort(arr, arrSize, sizeof(int), cmpInt);

    int minDiff = INT_MAX;

    // First pass to find min diff
    for (int i = 1; i < arrSize; i++) {
        int diff = arr[i] - arr[i - 1];
        if (diff < minDiff) minDiff = diff;
    }

    // Count how many pairs have minDiff
    int count = 0;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] == minDiff) count++;
    }

    // Allocate return arrays
    int** res = (int**) malloc(sizeof(int*) * count);
    *returnColumnSizes = (int*) malloc(sizeof(int) * count);

    
    int idx = 0;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] == minDiff) {
            res[idx] = (int*) malloc(sizeof(int) * 2);
            res[idx][0] = arr[i - 1];
            res[idx][1] = arr[i];
            (*returnColumnSizes)[idx] = 2;
            idx++;
        }
    }

    *returnSize = count;
    return res;
}
