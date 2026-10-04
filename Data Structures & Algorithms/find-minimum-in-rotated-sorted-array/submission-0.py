class Solution:
    def findMin(self, nums: List[int]) -> int:
        minVal = float("inf")
        for i in nums:
            minVal = min(minVal, i)

        return minVal