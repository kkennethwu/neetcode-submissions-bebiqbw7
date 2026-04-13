class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n); res[n - 1] = 0;
        for (int i = 0; i < n - 1; i++) {
            int tmp = temperatures[i];
            int j;
            for (j = i + 1; j < n; j++) {
                if (tmp < temperatures[j]) break;
            }
            if (j == n) res[i] == 0;
            else res[i] = (j - i);
        }
        return res;
    }
};
