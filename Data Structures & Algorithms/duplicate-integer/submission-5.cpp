class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> num_count;
        for (int i = 0; i < nums.size(); i++) {
            num_count[nums[i]]++;
            if (num_count[nums[i]] > 1) {
                return true;
            }
        }
        return false;
    }
};