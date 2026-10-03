class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string sub = "";
        int longestLen = 0;
        for (int i = 0; i < s.length(); i++) {
            size_t pos = sub.find(s[i]);
            int len;
            if (pos == string::npos) {
                sub += s[i];
                len = sub.length();
                longestLen = max(longestLen, len);
            } else {
                sub = sub.substr(pos + 1); 
    
    // 2. Add the NEW current character
                sub += s[i];          
            }
        }
        return longestLen;
    }
};
