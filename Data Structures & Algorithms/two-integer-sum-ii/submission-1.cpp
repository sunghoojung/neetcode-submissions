class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int bottomIndex = 0; int topIndex = numbers.size()-1;
        while (bottomIndex != topIndex) {
            int sum = numbers[bottomIndex] + numbers[topIndex];
            if (sum == target) {
                return {bottomIndex+1, topIndex+1};
            } else if (sum > target) {
                topIndex--;
            } else {
                bottomIndex++;
            }
        }
        return {-1, -1};
    }
};
