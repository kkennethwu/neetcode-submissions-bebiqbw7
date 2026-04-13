class Solution {
public:
    bool isLeft(char c) {
        return (c == '(' || c == '[' || c == '{');
    }

    bool isValid(string s) {
        stack<char> S;
        for (auto const& c : s) {
            if (isLeft(c)) S.push(c);
            else if (!S.empty()) {
                char top = S.top();
                if ((c == '}' && top != '{') || (c == ']' && top != '[') || (c == ')' && top != '(')) return false;
                S.pop();
            }
            else return false;
        }
        if (S.empty()) return true;
        else return false;
    }
};
