class Solution {
public:
    bool isValid(string s) {
        stack<char> hi;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (c == '(' || c == '{' || c == '[') {
                hi.push(c);
            } else {
                if (hi.empty()) return false;

                if ((c == ')' && hi.top() == '(') ||
                    (c == '}' && hi.top() == '{') ||
                    (c == ']' && hi.top() == '[')) {
                    hi.pop();
                } else {
                    return false;  // mismatched bracket
                }
            }
        }

        return hi.empty();  // all brackets matched
    }
};