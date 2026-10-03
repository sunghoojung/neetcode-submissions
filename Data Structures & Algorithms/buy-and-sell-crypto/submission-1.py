class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min = float("inf")
        maxVal = 0
        for index, value in enumerate(prices):
            if value < min:
                min = value
            maxVal = max(maxVal, value - min)

        return maxVal