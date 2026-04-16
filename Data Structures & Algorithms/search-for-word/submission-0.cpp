class Solution {
private:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int rows;
    int cols;
    bool inRange(int x, int y) {
        return (0 <= x && x < rows) && (0 <= y && y < cols);
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    if (bt(board, word, 0, i, j)) return true;
                }
            }
        }
        
        return false;
    }

    bool bt(vector<vector<char>>& board, string& word, int idx, int x, int y) {
        if (idx == word.size()) return true;
        if (!inRange(x, y) || word[idx] != board[x][y]) return false;
        
        char tmp = board[x][y];
        board[x][y] = '#';
        for (const auto& dir : dirs) {
            int xo = dir[0], yo = dir[1];
            if (bt(board, word, idx + 1, x + xo, y + yo)) return true;
        }
        board[x][y] = tmp;
        return false;
    }
};
