class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        stack<int> stack;
        for (int i  = 0; i < temperatures.size(); i++) {
            while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
                answer[stack.top()] = (i - stack.top());
                stack.pop();
            }
            stack.push(i);
        }
        return answer;
    }
};
