#include <cstring>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq1[26] = {0};
        int freq2[26] = {0};
        int windowSize = s1.size();
        int l = 0;
        int r = windowSize-1;
        for (int i = 0; i < s1.size(); i++) {
            freq1[s1[i] - 'a']++;
        }
        for (int j = 0; j < r+1; j++) {
            freq2[s2[j] - 'a']++;
        }
        while (r < s2.size()) { 
            if (memcmp(freq1, freq2, sizeof(freq1)) == 0) {
                return true;
            } 
            freq2[s2[l] - 'a']--;
            l++;
            r++;
            freq2[s2[r] - 'a']++;
        }
        return false;
    }
};
