class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h = matrix.size(), w = matrix[0].size();
        int left = 0, right = w * h - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int i = mid / w, j = mid % w;
            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return false;
    }
};
