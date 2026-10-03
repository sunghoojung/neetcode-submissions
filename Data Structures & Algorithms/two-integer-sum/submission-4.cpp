class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;

        for (int i = 0; i < nums.size(); i++) {
            if (hashMap.find(target - nums[i]) != hashMap.end()) {


                return {hashMap[target - nums[i]], i};
            } else {
                hashMap.insert({nums[i], i});
            }
        }
    }
};
