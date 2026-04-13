class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        for (char c = 'A'; c <= 'Z'; c++) {
            int l = 0, cnt = 0;
            for (int r = 0; r < n; r++) {
                if (s[r] == c) cnt++;
                if (r - l + 1 - cnt > k) {
                    if (s[l] == c) cnt--;
                    l++;
                }
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};
