class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        
        int curSum = 0;
        for (int i = 0; i < nums.size(); i++) {
             if (curSum < 0) curSum = 0;
             curSum += nums[i];
             res = max(res, curSum);
        }
        return res;

    }
};
