class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // remove element larger than target
        for (int i = 0; i < nums.size(); i++) {
            if (target < nums[i]) nums.erase(nums.begin() + i);
        }
        // bt
        vector<vector<int>> res;
        vector<int> subset;
        bt(nums, 0, target, subset, res);
        return res;
    }

    void bt(vector<int>& nums, int i, const int& target, vector<int>& subset, vector<vector<int>>& res) {
        if (i == nums.size()) return;
        int sum = accumulate(subset.begin(), subset.end(), 0);
        if (sum == target) {
            res.push_back(subset);
            return;
        } else if (sum > target) return;
        
        for (int j = i; j < nums.size(); j++) {
            subset.push_back(nums[j]);
            bt(nums, j, target, subset, res);
            subset.pop_back();
        }
    }
    // tree depth = t / m, where t is target, m is the minimum of nums
    // TC: O(2^(t/m)) since N is regular number
    // SC: O(t/m) since call stack depth = t / m, 每層O(1) since subset is passed by reference

};
