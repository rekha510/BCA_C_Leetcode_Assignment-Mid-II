int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max_water = 0;

    while (left < right) {
        int h = (height[left] < height[right]) ? height[left] : height[right];
        int w = right - left;
        int area = h * w;

        if (area > max_water) {
            max_water = area;
        }

        // Move the pointer pointing to the shorter vertical line inward
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_water;
}
