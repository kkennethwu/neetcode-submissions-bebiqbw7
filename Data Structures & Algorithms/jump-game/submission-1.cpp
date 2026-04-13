class Solution {
public:
    bool canJump(vector<int>& nums) {
        // [1, 3, 2, 4, -1]
        //  0. 1. 2. 3.  4
        // [1, 3, 3, 3, 5]
        vector<int> destination(nums.size());
        int n = nums.size();

        int last = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (i + nums[i] >= last) {
                last = i;
            }
        }
        
        return last == 0 ? true : false;
    }
};
