#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);  // Add a sentinel to flush the stack at the end
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxRect = 0;

        for (int i = 0; i < rows; ++i) {
            // Build up the histogram
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }

            // Compute max rectangle for this row
            maxRect = max(maxRect, largestRectangleArea(heights));
        }

        return maxRect;
    }
};
