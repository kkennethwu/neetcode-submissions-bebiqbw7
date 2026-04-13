class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(9));
        vector<vector<int>> col(9, vector<int>(9));
        vector<vector<int>> box(9, vector<int>(9));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                int box_id = (i / 3) * 3 + j / 3;

                if (row[i][num]) return false;
                row[i][num] = 1;

                if (col[j][num]) return false;
                col[j][num] = 1;

                if (box[box_id][num]) return false;
                box[box_id][num] = 1;
            }
        }
        return true;
    }
};
