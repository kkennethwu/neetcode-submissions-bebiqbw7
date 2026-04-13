class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // // BF
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = 0; j < nums.size(); j++) {
        //         int target = -(nums[i] + nums[j]);
        //         // check if target in the array, but not index i or j.
        //     }
        // }
        
        // -5 -4 1 3 4
        // -4, -1, -1, 0, 1, 2
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue; // avoid duplicate

            int front = i + 1, back = nums.size() - 1;
            while (front < back) {
                int sum = nums[i] + nums[front] + nums[back];
                if (sum > 0) {
                    back--;
                }
                else if (sum < 0) {
                    front++;
                }
                else {
                    ans.push_back({nums[i], nums[front], nums[back]});
                    front++;
                    back--;
                    // avoid duplicate
                    while (front < back && nums[front] == nums[front - 1]) {
                        front++;
                    } 
                }
            }
            
        }
        return ans;
    }
};
