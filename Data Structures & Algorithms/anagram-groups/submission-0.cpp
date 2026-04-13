class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> M;
        vector<vector<string>> ans;
        for (auto str : strs) {
            string tmp = str;
            sort(str.begin(), str.end());
            M[str].push_back(tmp);
        }
        for (auto iter = M.begin(); iter != M.end(); iter++) {
            ans.push_back(iter->second);
        }
        return ans;
    }
};
