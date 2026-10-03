class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *std::max_element(piles.begin(), piles.end());
        while (low < high) {
            int mid = low + (high - low) / 2;
            long long hours = 0;

            for (int i : piles) {
                hours += (i + mid - 1LL) / mid;
            }
            if (hours > h) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
};