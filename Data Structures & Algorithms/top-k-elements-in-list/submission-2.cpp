class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> M;
        priority_queue<pair<int, int>> Q;
        for (const auto &num : nums) {
            M[num]++;
        }
        for (const auto &pair : M) {
            Q.push({pair.second, pair.first});
        }
        while(k-- && !Q.empty()) {
            ans.push_back(Q.top().second);
            Q.pop();
        }
        return ans;
    }
};
