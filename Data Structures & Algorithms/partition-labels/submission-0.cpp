class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        // a hash map to store <char, index at first meet>
        // starting by a single char as substring
        // f meet the char that appear before, merge the substring

        // x,
        // y,
        // xyx
        vector<int> hashMap(26, -1);
        vector<int> res; // the start index
        for (int i = 0; i < n; i++) {
            const int& c = s[i] - 'a';
            if (hashMap[c] == -1) {
                hashMap[c] = i;
                res.push_back(i);
            } else {
                while (!res.empty()) {
                    if (hashMap[c] < res.back()) { // 0 >= 1
                        res.pop_back();
                    } else break;
                }
            }
        }
        for (int i = 0; i < res.size() - 1; i++) {
            res[i] = res[i + 1] - res[i];
        }
        res[res.size() - 1] = s.size() - res[res.size() - 1];
        return res;
    }
};
