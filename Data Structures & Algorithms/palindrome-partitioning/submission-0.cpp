class Solution {
public:
    bool isPalidrom(const string& s) {
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            if (s[left] != s[right]) return false;
            left++; right--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        // abbacddccddcabba
        vector<vector<string>> res;
        vector<string> pars;
        bt(s, 0, res, pars);
        return res;
    }

    void bt(const string& s, int idx, vector<vector<string>>& res, vector<string>& pars) {
        if (idx == s.size()) {
            res.push_back(pars);
        }

        for (int i = idx; i < s.size(); i++) {
            int len = i - idx + 1;
            if (isPalidrom(s.substr(idx, len))) {
                pars.push_back(s.substr(idx, len));
                bt(s, i + 1, res, pars);
                pars.pop_back();
            }
        }
    }
};
