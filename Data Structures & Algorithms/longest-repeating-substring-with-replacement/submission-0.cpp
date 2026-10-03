class Solution {
public:
    int getMaxCount(int freq[]) {
        int maxCount = 0;
        for (int i = 0; i < 26; i++) {
            maxCount = max(freq[i], maxCount);
        }
        return maxCount;
    }
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int l = 0;
        int r = 0;
        int largestSlidingWindow = 0;
        while (r < s.size()) {
            freq[s[r] - 'A']++;
            while ((r - l + 1) - getMaxCount(freq) > k) {
                freq[s[l] - 'A']--;
                l++;
            }
            largestSlidingWindow = max(r - l + 1, largestSlidingWindow);
            r++;
        }
        return largestSlidingWindow;
    }
};
