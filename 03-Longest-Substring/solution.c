/**
 * LeetCode #3: Longest Substring Without Repeating Characters
 * 
 * NOTE: LeetCode par submit karne ke liye sirf yeh function chahiye.
 * Isme main() function mat lagayein kyunki LeetCode apna main() internally use karta hai.
 */

int lengthOfLongestSubstring(char* s) {
    if (s == 0 || *s == '\0') {
        return 0;
    }

    // 256 size array har character (ASCII) ka last seen index store karne ke liye
    int last_index[256];
    for (int i = 0; i < 256; i++) {
        last_index[i] = -1;
    }

    int max_len = 0;
    int left = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        unsigned char c = (unsigned char)s[right];

        // Agar character current window me pehle aa chuka hai
        if (last_index[c] >= left) {
            left = last_index[c] + 1;
        }

        // Character ka index update karein
        last_index[c] = right;

        // Current window length check karein
        int current_len = right - left + 1;
        if (current_len > max_len) {
            max_len = current_len;
        }
    }

    return max_len;
}
