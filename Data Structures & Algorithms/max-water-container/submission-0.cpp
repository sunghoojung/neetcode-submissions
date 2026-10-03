class Solution {
public:
    int maxArea(vector<int>& height) {
        int lower = 0;
        int higher = height.size() - 1;
        int maxArea = 0;
        while (lower < higher) {
            int minHeight = min(height[lower], height[higher]);
            int area = minHeight * (higher - lower);

            maxArea = max(area, maxArea);
            
            if (height[lower] < height[higher]) {
                lower++;
            } else if (height[lower] > height[higher]) {
                higher--;
            } else {
                lower++;
            }
        }
        return maxArea;
    }
};