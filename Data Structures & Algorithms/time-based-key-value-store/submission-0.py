class TimeMap:

    def __init__(self):
        self.data = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.data:
            self.data[key] = []
        self.data[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.data:
            return ""

        left = 0
        right = len(self.data[key]) - 1
        bestCand = -1

        while left <= right:
            mid = (right - left) // 2 + left
            if self.data[key][mid][0] > timestamp:
                right = mid - 1
            elif self.data[key][mid][0] < timestamp:
                bestCand = mid
                left = mid + 1
            else:
                return self.data[key][mid][1]

        if bestCand == -1:
            return ""

        return self.data[key][bestCand][1]