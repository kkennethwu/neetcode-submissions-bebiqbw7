class Solution {
public:
    void BT(int numOpen, int numClosed, int n, vector<string>& ans, string& s) {
        if (numOpen == n && numClosed == n) {
            ans.push_back(s);
            return;
        }

        if (numOpen < n) {
            s += '(';
            BT(numOpen + 1, numClosed, n, ans, s);
            s.pop_back();
        }
        if (numClosed < numOpen) {
            s += ')';
            BT(numOpen, numClosed + 1, n, ans, s);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        BT(0, 0, n, ans, s);
        return ans;
    }
};
