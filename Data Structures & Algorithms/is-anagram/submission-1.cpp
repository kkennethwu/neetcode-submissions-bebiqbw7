class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> vec(26);
        for (auto c : s) {
            vec[c - 'a']++;
        }
        for (auto c : t) {
            if(--vec[c - 'a'] < 0) return false;
        }
        return true;
    }
};
