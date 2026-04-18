class Solution {
private:
    vector<string> hashMap = vector<string>(10);
    void initialize() {
        string tmp = "abc";
        for (int i = 2; i <= 6; i++) {
            hashMap[i] = tmp;
            tmp[0] += 3;
            tmp[1] += 3;
            tmp[2] += 3;
        }
        hashMap[7] = "pqrs";
        hashMap[8] = "tuv";
        hashMap[9] = "wxyz";
    }
public:
    vector<string> letterCombinations(string digits) {
        initialize();
        vector<string> res;
        string substring;
        if (digits.size() == 0) return res;
        bt(digits, 0, res, substring);
        return res;
    }

    void bt(const string& digits, int idx, vector<string>& res, string& substring) {
        if (idx == digits.size()) {
            res.push_back(substring);
            return;
        }

        int num = digits[idx] - '0';
        for (int i = 0; i < hashMap[num].size(); i++) {
            substring += hashMap[num][i];
            bt(digits, idx + 1, res, substring);
            substring.pop_back();
        }
        
    }
};
