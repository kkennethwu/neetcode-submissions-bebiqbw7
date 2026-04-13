class Solution {
public:
    // struct cmp {
    //     bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
    //         return a.second < b.second;
    //     }
    // };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> M;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> Q;
        using P = std::pair<int,int>;
        auto cmp = [](const P& a, const P& b){
            return a.second < b.second;
        };
        priority_queue<P, std::vector<P>, decltype(cmp)> Q(cmp);
        
        for (const auto& num : nums) {
            M[num]++;
        }
        for (const auto& pair : M) {
            Q.push({pair.first, pair.second});
        }
        while(k-- && !Q.empty()) {
            ans.push_back(Q.top().first);
            Q.pop();
        }
        return ans;
    }
};
