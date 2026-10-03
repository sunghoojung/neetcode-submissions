class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = set()
        curr = ""
        maxSize = 0
        for i in s:
            if i not in seen:
                seen.add(i)
                curr += i
                maxSize = max(maxSize, len(curr))
            else: 
                while (i in seen):
                    letter = curr[0]
                    seen.remove(letter)
                    curr = curr[1:]
                curr += i
                seen.add(i)
        return maxSize