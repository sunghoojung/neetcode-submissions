class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        left = 0
        right = len(matrix) * len(matrix[0]) - 1
        
        while (left <= right):
            mid = (right - left) // 2 + left
            row_mid = mid // len(matrix[0])
            col_mid = mid % len(matrix[0])

            if (matrix[row_mid][col_mid] == target):
                return True
            elif (matrix[row_mid][col_mid] > target):
                right = mid - 1
            else:
                left = mid + 1
        return False