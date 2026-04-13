class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> M;
        
        int n = s.size();
        if (!n) return 0;
        int left = 0, right = left + 1;
        int ans = 1;
        M[s[left]] = left;
        while (left < right && right < n) {
            if (M.count(s[right]) && M[s[right]] >= left) left = M[s[right]] + 1;
            M[s[right]] = right;
            right++;
            ans = max(ans, right - left);
        }
        return ans;
    }
};
