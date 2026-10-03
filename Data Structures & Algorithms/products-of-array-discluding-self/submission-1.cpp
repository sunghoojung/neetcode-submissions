class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        vector<int> result(nums.size());
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i-1] * nums[i];
        }

        suffix[nums.size()-1] = nums[nums.size()-1];
        for (int i = nums.size()-2; i > 0; i--) {
            suffix[i] = suffix[i+1] * nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                result[i] = suffix[i+1];
            } else if (i == nums.size()-1) {
                result[i] = prefix[i-1];
            } else {
                result[i] = suffix[i+1] * prefix[i-1];
            }             
        }
        return result;


    }
};