class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            groups[sortedWord].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& entry : groups) {
            result.push_back(entry.second);
        }

        return result;
    }
};
