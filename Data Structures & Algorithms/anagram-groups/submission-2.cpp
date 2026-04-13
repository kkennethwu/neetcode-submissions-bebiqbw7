class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> freq(26);
        unordered_map<string, vector<string>> M; // freq, group
        vector<vector<string>> ans;
        for (const auto& str : strs) {
            fill(freq.begin(), freq.end(), 0); // not clear
            for (auto c : str) freq[c - 'a']++;
            string key = to_string(freq[0]); // cause unordered_map is faster, and not allow use vector<int> as key, so we change it to string here
            for (int i = 0; i < freq.size(); i++) {
                key += ("," + to_string(freq[i]));
            }
            M[key].push_back(str);
        }
        for (const auto& pair : M) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};
