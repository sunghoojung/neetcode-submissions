class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longest = 0;
    
        for (int num : num_set) {
            // only start counting if num is the start of a sequence
            if (!num_set.count(num - 1)) {
                int current_num = num;
                int streak = 1;
    
                while (num_set.count(current_num + 1)) {
                    current_num++;
                    streak++;
                }
    
                longest = max(longest, streak);
            }
        }
    
        return longest;
    }
};
