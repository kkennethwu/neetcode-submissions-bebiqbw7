class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // '(' num should be larger or equal to ')' num
        vector<string> res;
        string substring = "";
        bt(n, 0, 0, res, substring);
        return res;
    }

    void bt(int n, int lnum, int rnum, vector<string>& res, string& substring) {
        if (rnum > lnum) return;
        if (lnum == n && rnum == n) {
            res.push_back(substring);
            return;
        }
        
        if (lnum < n) {
            substring.push_back('(');
            bt(n, lnum + 1, rnum, res, substring);
            substring.pop_back();
        } 
        if (rnum < n) {
            substring.push_back(')');
            bt(n, lnum, rnum + 1, res, substring);
            substring.pop_back();
        }
    }


};
