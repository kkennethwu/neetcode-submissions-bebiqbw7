class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> freq(26);
        map<vector<int>, vector<string>> M; // freq, group
        vector<vector<string>> ans;
        for (const auto& str : strs) {
            fill(freq.begin(), freq.end(), 0); // not clear
            for (auto c : str) freq[c - 'a']++;
            M[freq].push_back(str);
        }
        for (const auto& pair : M) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};
