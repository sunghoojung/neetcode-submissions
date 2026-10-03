class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack_tokens;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                cout << "this is a operator" << endl;
                int num1 = stack_tokens.top();
                stack_tokens.pop();
                int num2 = stack_tokens.top();
                stack_tokens.pop();
                if (tokens[i] == "+") {
                    int num3 = num1+num2;
                    stack_tokens.push(num3);
                } else if (tokens[i] == "-") {
                    int num3 = num2 - num1;
                    stack_tokens.push(num3);
                } else if (tokens[i] == "*") {
                    int num3 = num1 * num2;
                    stack_tokens.push(num3);
                } else if (tokens[i] == "/") {
                    int num3 = num2 / num1;
                    stack_tokens.push(num3);
                }
            } else {
                stack_tokens.push(stoi(tokens[i]));
            }
        }
        return stack_tokens.top();
    }
};
