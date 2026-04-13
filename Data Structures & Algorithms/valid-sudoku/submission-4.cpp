class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // bitmask method
        int row[9] = {0};
        int col[9] = {0};
        int box[9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                int bitmask = 1 << num;
                int box_id = (i / 3) * 3 + j / 3;

                if ((row[i] & bitmask) || (col[j] & bitmask) || (box[box_id] & bitmask)) return false;
                row[i] |= bitmask;
                col[j] |= bitmask;
                box[box_id] |= bitmask;
            }
        }
        return true;
    }
};
