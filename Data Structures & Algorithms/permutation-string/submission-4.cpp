class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt1(26), cnt2(26);
        for (int i = 0; i < s1.size(); i++) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] == cnt2[i]) matches++;
        }

        int l = 0;    
        for (int r = s1.size(); r < s2.size(); r++) {
            if (matches == 26) return true;
            
            int idx = s2[r] - 'a';
            cnt2[idx]++;
            if (cnt1[idx] == cnt2[idx]) matches++;
            else if (cnt1[idx] + 1 == cnt2[idx]) matches--;

            idx = s2[l] - 'a';
            cnt2[idx]--;
            if (cnt1[idx] == cnt2[idx]) matches++;
            else if (cnt1[idx] - 1 == cnt2[idx]) matches--;
            l++;
        }
        return matches == 26;
    }
};
