class Solution {
public:
    bool isOperator(const string& token) {
        return ((token == "+") || (token == "-") || (token == "*") || (token == "/"));
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> S;
        for (const auto& token : tokens) {
            if (!isOperator(token)) {
                S.push(stoi(token));
            }
            else {
                int b = S.top(); S.pop();
                int a = S.top(); S.pop();
                if (token == "+") S.push(a + b);
                if (token == "-") S.push(a - b);
                if (token == "*") S.push(a * b);
                if (token == "/") S.push(a / b);
            }
        }
        return S.top();
    }
};
 