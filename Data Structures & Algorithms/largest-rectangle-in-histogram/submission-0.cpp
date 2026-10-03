class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextSmallerRight(heights.size(), -1);
        stack<int> stk;

        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                nextSmallerRight[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        vector<int> nextSmallerLeft(heights.size(), -1);
        stack<int> stk2;
        
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!stk2.empty() && heights[stk2.top()] > heights[i]) {
                nextSmallerLeft[stk2.top()] = i;
                stk2.pop();
            }
            stk2.push(i);
        }

        int max = 0;

        for (int i = 0; i < heights.size(); i++) {
            int maxArea = 0;
            if (nextSmallerRight[i] == -1 && nextSmallerLeft[i] == -1) {
                maxArea = heights.size() * heights[i];
            } else if (nextSmallerRight[i] == -1) {
                maxArea = (heights.size() - nextSmallerLeft[i] - 1) * heights[i];
            } else if (nextSmallerLeft[i] == -1) {
                maxArea = (nextSmallerRight[i]) * heights[i];
            } else {
                maxArea = (nextSmallerRight[i] - nextSmallerLeft[i] -1 ) * heights[i];
            }

            if (maxArea > max) {
                max = maxArea;
            }
        }

        return max;
    }
};