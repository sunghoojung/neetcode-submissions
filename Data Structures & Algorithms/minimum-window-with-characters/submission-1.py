class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t or len(t) > len(s):
            return ""

        dictT = {}
        dictSubStr = {}

        for character in t:
            dictT[character] = dictT.get(character, 0) + 1

        satisfied = 0
        required = len(dictT)
        left = 0
        bestStart = 0
        bestLength = float("inf")

        for right, character in enumerate(s):
            dictSubStr[character] = dictSubStr.get(character, 0) + 1

            if character in dictT:
                if dictSubStr[character] == dictT[character]:
                    satisfied += 1

            while satisfied == required:
                windowLength = right - left + 1

                if windowLength < bestLength:
                    bestStart = left
                    bestLength = windowLength

                firstCharacter = s[left]
                dictSubStr[firstCharacter] -= 1

                if firstCharacter in dictT:
                    if dictSubStr[firstCharacter] < dictT[firstCharacter]:
                        satisfied -= 1

                left += 1

        if bestLength == float("inf"):
            return ""

        return s[bestStart:bestStart + bestLength]