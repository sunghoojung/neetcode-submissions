class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        items = deque()
        answer = []
        for i, num in enumerate(nums):
            if not items:
                items.append(i)
                if (i-k+1 >= 0):
                    answer.append(nums[items[0]])
                continue
            
            if (items[0] < i-k+1):
                #expired remove this from dequeue
                items.popleft()
            
            while (items and nums[items[-1]] <= num):
                items.pop()
            items.append(i)

            if (i-k+1 >= 0):
                answer.append(nums[items[0]])


        return answer
            
