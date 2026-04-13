class Solution {
public:
    int characterReplacement(string s, int k) {
        // aazccc, k = 3
        int n = s.size();
        int ans = 1;
        // (r - l + 1) - cnt: means the number of *C* needs to be replace
        // so if above <= k, means sliding window can keep growing 
        for (char c = 'A'; c <= 'Z'; c++) {
            int cnt = 0, l = 0;
            for (int r = 0; r < s.size(); r++) {
                if (s[r] == c) cnt++;
                while ((r - l + 1) - cnt > k) {
                    if (s[l] == c) cnt--;
                    l++;
                }
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};
