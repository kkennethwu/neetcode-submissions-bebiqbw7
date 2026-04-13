class Solution {
public:
    int jump(vector<int>& nums) {
        // 2 4 1 1 1 1
        // 2 5 3 4 5 6
        //   1 3 2 1 0
        // int res = INT_MAX;
        int n = nums.size();
        if (n < 2) return 0;

        int jump = 0, l = 0, r = 0;
        while (r < nums.size() - 1) {
            int far = 0;
            for (int i = l; i <= r; i++) {
                far = max(far, i + nums[i]);
            }
            l = r + 1;
            r = far;
            jump++;
        }
        return jump;
    }
};
