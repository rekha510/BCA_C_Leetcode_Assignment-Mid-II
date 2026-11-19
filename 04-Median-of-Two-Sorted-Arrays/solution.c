#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/**
 * LeetCode #4: Median of Two Sorted Arrays
 * 
 * NOTE: LeetCode par submit karne ke liye sirf yeh function chahiye.
 * Function signature LeetCode C ke hisaab se hai:
 * double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
 * 
 * Approach: Binary Search on Partition
 * Time Complexity:  O(log(min(m, n)))
 * Space Complexity: O(1)
 */

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Chhote array par binary search karenge taaki time complexity O(log(min(m, n))) rahe
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;
    int low = 0, high = m;

    while (low <= high) {
        int i = low + (high - low) / 2;
        int j = (m + n + 1) / 2 - i;

        int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int minRight1 = (i == m) ? INT_MAX : nums1[i];

        int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int minRight2 = (j == n) ? INT_MAX : nums2[j];

        // Sahi partition mil gaya
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((m + n) % 2 == 1) {
                // Total length odd hai -> left part ka maximum median hoga
                return (double)MAX(maxLeft1, maxLeft2);
            } else {
                // Total length even hai -> left max aur right min ka average
                return ((double)MAX(maxLeft1, maxLeft2) + (double)MIN(minRight1, minRight2)) / 2.0;
            }
        } else if (maxLeft1 > minRight2) {
            // nums1 se zyada elements le liye hain, left me shift karein
            high = i - 1;
        } else {
            // nums1 se kam elements liye hain, right me shift karein
            low = i + 1;
        }
    }

    return 0.0;
}
