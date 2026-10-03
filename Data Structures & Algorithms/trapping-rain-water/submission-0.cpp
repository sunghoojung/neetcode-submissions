class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> rightMax(height.size(), 0);
        vector<int> leftMax(height.size(), 0);
        
        for (int i = 1; i < height.size(); i++) {
            leftMax[i] = max(leftMax[i-1], height[i-1]);
        }

        for (int i = height.size() - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i+1]);
        }

        for (int i : rightMax) {
            cout << i << endl;
        }
        
        int water = 0;
        for (int i = 0; i < height.size(); i++) {
            int minHeight = min(leftMax[i], rightMax[i]);
            if (height[i] >= minHeight) {
                continue;
            }
            water += (minHeight - height[i]);
        }
        return water;
    }
};