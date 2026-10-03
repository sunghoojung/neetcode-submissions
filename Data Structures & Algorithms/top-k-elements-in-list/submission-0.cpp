class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> list;
        for (int i = 0; i < nums.size(); i++) {
            list[nums[i]]++;
        }
        vector<int> empty;
        
        while (k != 0) {
            k--;
            int candidate = 0;
            int freq = INT_MIN;
            for (auto& pair : list) {
                if (pair.second > freq) {
                    candidate = pair.first;
                    freq = pair.second;
                }
            }
            empty.push_back(candidate);
            list.erase(candidate);
        }

        return empty;
    }
};