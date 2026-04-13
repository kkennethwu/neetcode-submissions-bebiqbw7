class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> ans(n + 1);
        ans[0] = {""};
        // ans represent all the valid parenthesis list for n pairs
        // ans[i + 1] = for list in ans[i], 
        // split the string in the list into left & right
        // newone = '(' + left + ')' + right 
        
        for (int k = 0; k <= n; k++) {
            for (int i = 0; i < k; i++) {
                for (const string& left : ans[i]) {
                    for (const string& right : ans[k - i - 1]) {
                        ans[k].push_back("(" + left + ")" + right);
                    }
                }
            }
        }

        return ans[n];
    }
};
