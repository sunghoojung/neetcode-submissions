class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], speed[i]};
        }

        // ✅ FIX: Correct sort, only by position descending
        sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        stack<double> stack;
        for (int i = 0; i < n; ++i) {
            int distance = target - cars[i].first;
            double time = (double) distance / cars[i].second;

            if (!stack.empty() && time <= stack.top()) {
                // This car joins fleet ahead → do nothing
                continue;
            }
            stack.push(time);
        }

        return stack.size();
    }
};
