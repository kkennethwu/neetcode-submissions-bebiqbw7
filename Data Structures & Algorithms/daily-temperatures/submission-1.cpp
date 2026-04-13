class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<pair<int, int>> S; // index, temp
        
        for (int i = 0; i < n; i++) {
            int temp = temperatures[i];
            while (!S.empty()) {
                if (temp > S.top().second) {
                    res[S.top().first] = i - S.top().first;
                    S.pop();
                }
                else break;
            }
            S.push({i, temp});
        }
        while(!S.empty()) {
            res[S.top().first] = 0;
            S.pop();
        }
        return res;
    }
};
