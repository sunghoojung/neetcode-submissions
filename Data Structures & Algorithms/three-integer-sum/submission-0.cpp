class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answers;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicate `i`
            
            int lower = i + 1;
            int higher = nums.size() - 1;

            while (lower < higher) {
                int sum = nums[i] + nums[lower] + nums[higher];
                if (sum < 0) {
                    lower++;
                } else if (sum > 0) {
                    higher--;
                } else {
                    answers.push_back({nums[i], nums[lower], nums[higher]});
                    
                    // Move pointers
                    lower++;
                    higher--;

                    // Skip duplicate lower
                    while (lower < higher && nums[lower] == nums[lower - 1]) {
                        lower++;
                    }

                    // Skip duplicate higher
                    while (lower < higher && nums[higher] == nums[higher + 1]) {
                        higher--;
                    }
                }
            }
        }
        return answers;
    }
};