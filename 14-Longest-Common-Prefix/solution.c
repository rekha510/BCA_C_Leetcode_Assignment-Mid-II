#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Function to find the longest common prefix string amongst an array of strings.
 * 
 * @param strs An array of strings.
 * @param strsSize The number of strings in the array.
 * @return A dynamically allocated string representing the longest common prefix.
 *         The caller is responsible for freeing the allocated memory.
 */
char* longestCommonPrefix(char** strs, int strsSize) {
    // If the input array is empty, return an empty string
    if (strs == NULL || strsSize == 0) {
        char* empty = (char*)malloc(1 * sizeof(char));
        if (empty == NULL) return NULL;
        empty[0] = '\0';
        return empty;
    }

    // Vertical scanning: compare character by character
    for (int i = 0; strs[0][i] != '\0'; i++) {
        char c = strs[0][i];
        for (int j = 1; j < strsSize; j++) {
            // Check if current index i exceeds the length of strs[j]
            // or if the characters do not match
            if (strs[j][i] != c) {
                char* prefix = (char*)malloc((i + 1) * sizeof(char));
                if (prefix == NULL) return NULL;
                strncpy(prefix, strs[0], i);
                prefix[i] = '\0';
                return prefix;
            }
        }
    }

    // If all characters of strs[0] matched across all strings
    int len = strlen(strs[0]);
    char* prefix = (char*)malloc((len + 1) * sizeof(char));
    if (prefix == NULL) return NULL;
    strcpy(prefix, strs[0]);
    return prefix;
}
