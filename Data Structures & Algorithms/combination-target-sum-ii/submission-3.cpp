class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        vector<vector<int>> res;
        bt(candidates, 0, 0, target, res, subset);
        sort(res.begin(), res.end());  // lexicographical sort
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }

    void bt(vector<int>& candis, int i, int sum, int target, vector<vector<int>>& res, vector<int>& subset) {
        
        // int sum = accumulate(subset.begin(), subset.end(), 0);
        if (sum == target) {
            res.push_back(subset);
            return;
        } else if (sum > target) return;

        for (int j = i; j < candis.size(); j++) {
            if (j > i && candis[j] == candis[i]) continue; // pruning for the same level
            subset.push_back(candis[j]); sum += candis[j];
            bt(candis, j + 1, sum, target, res, subset);
            subset.pop_back(); sum -= candis[j];
        }
    }
};
