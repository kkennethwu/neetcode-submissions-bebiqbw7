class Solution {
public:
    bool valid(string s) {
        int diff = 0;
        for (char c : s) {
            if (c == '(') diff++;
            else diff--;
            if (diff < 0) return false;  
        }
        if (diff == 0) return true;
        else return false;
    }

    void dfs(string s, vector<string>& ans, int n) {
        if (s.size() == 2 * n) {
            if (valid(s)) ans.push_back(s);
            return;
        }
        dfs(s + '(', ans, n);
        dfs(s + ')', ans, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string tmp = "";
        dfs(tmp, ans, n);
        return ans;
    }
};
