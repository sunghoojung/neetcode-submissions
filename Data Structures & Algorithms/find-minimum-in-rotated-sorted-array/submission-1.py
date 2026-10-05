class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0 
        right = len(nums) - 1
        while (left < right):
            mid = (right-left) // 2 + left
            if (nums[right] < nums[mid]):
                left = mid + 1
            elif (nums[right] > nums[mid]):
                right = mid
        return nums[right]
        