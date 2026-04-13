class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        map<int, int> M;
        for (int i = 0; i < nums.size(); i++) {
            if (M.count(nums[i])) return {M[nums[i]], i};
            M[target - nums[i]] = i;
        }
        return {0, 0};      
    }
};
