class Solution {
private:
    vector<vector<int>> dp;;
public:
    bool isPalidrome(const string& s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) return false;
            left++; right--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        // dp[i][j] == true, if s.substr(i, j - i + 1) is palidrome
        dp = vector<vector<int>>(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                if (i == j) dp[i][j] = true;
                else if (isPalidrome(s, i, j)) {
                    dp[i][j] = 1;
                }
            }
        }

        // backtracking
        vector<vector<string>> res;
        vector<string> pars;
        bt(s, 0, res, pars);
        return res;
    }

    void bt(const string& s, int idx, vector<vector<string>>& res, vector<string>& pars) {
        if (idx == s.size()) {
            res.push_back(pars);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (dp[idx][i]) { // we can use dp to preprocess to speed up the palidrome check
                pars.push_back(s.substr(idx, i - idx + 1));
                bt(s, i + 1, res, pars);
                pars.pop_back();
            }
        }
        // TC:O(2^n) * O(n)
    }
};
