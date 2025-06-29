int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxArea = 0;

    while (left < right) {
        int h = (height[left] < height[right]) ? height[left] : height[right];
        int width = right - left;
        int area = h * width;
        if (area > maxArea) {
            maxArea = area;
        }

        // Move the shorter wall inward
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}
