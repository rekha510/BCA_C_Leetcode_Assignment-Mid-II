#include <stdlib.h>

/**
 * Comparator function for qsort to sort integers in ascending order.
 */
int compareInts(const void* a, const void* b) {
    int valA = *(const int*)a;
    int valB = *(const int*)b;
    if (valA < valB) return -1;
    if (valA > valB) return 1;
    return 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (!nums || numsSize < 3) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Sort the array in non-decreasing order
    qsort(nums, numsSize, sizeof(int), compareInts);

    int capacity = 64;
    int count = 0;
    int** result = (int**)malloc(capacity * sizeof(int*));
    int* colSizes = (int*)malloc(capacity * sizeof(int));

    if (!result || !colSizes) {
        free(result);
        free(colSizes);
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Fix the first element of the triplet
    for (int i = 0; i < numsSize - 2; i++) {
        // Optimization: if current element is positive, since array is sorted,
        // no subsequent elements can sum to 0.
        if (nums[i] > 0) {
            break;
        }

        // Skip duplicates for the first element
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                // Expand capacity dynamically if needed
                if (count == capacity) {
                    capacity *= 2;
                    int** newResult = (int**)realloc(result, capacity * sizeof(int*));
                    int* newColSizes = (int*)realloc(colSizes, capacity * sizeof(int));
                    if (!newResult || !newColSizes) {
                        for (int k = 0; k < count; k++) {
                            free(result[k]);
                        }
                        free(result);
                        free(colSizes);
                        *returnColumnSizes = NULL;
                        return NULL;
                    }
                    result = newResult;
                    colSizes = newColSizes;
                }

                // Allocate memory for the found triplet
                int* triplet = (int*)malloc(3 * sizeof(int));
                if (!triplet) {
                    for (int k = 0; k < count; k++) {
                        free(result[k]);
                    }
                    free(result);
                    free(colSizes);
                    *returnColumnSizes = NULL;
                    return NULL;
                }

                triplet[0] = nums[i];
                triplet[1] = nums[left];
                triplet[2] = nums[right];

                result[count] = triplet;
                colSizes[count] = 3;
                count++;

                // Skip duplicate elements for left and right pointers
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }

                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    *returnSize = count;
    *returnColumnSizes = colSizes;
    return result;
}
