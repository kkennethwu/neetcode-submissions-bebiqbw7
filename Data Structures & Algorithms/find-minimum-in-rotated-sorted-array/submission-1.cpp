class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[left] > nums[right]) {
                if (nums[mid] < nums[left]) {
                    right = mid;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                return nums[left];
            }
        }
        return -1;
    }
};
