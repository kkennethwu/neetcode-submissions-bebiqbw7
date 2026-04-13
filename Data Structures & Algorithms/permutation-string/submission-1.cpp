class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt1(26), cnt2;
        for (int i = 0; i < s1.size(); i++) {
            cnt1[s1[i] - 'a']++;
        }
                
        for (int i = 0; i < s2.size(); i++) {
            cnt2 = cnt1;
            for (int j = i; i < s2.size(); j++) {
                if (!cnt2[s2[j] - 'a']) break;
                cnt2[s2[j] - 'a']--;
                if (j - i + 1 == s1.size()) return true;
            }
        }
        return false;
    }
};
