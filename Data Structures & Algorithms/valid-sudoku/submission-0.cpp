class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!checkSqr(board, i, j)) return 0;
            }
        }
        for (int i = 0; i < 9; i++) {
            if (!checkRow(board, i)) return 0;
        }
        for (int j = 0; j < 9; j++) {
            if (!checkCol(board, j)) return 0;
        }
        return 1;
    }
    bool checkSqr(vector<vector<char>>& board, int x, int y) {
        set<int> sett;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char c = board[x + i][y + j];
                if (c != '.' && sett.contains(c))
                    return 0;
                else
                    sett.insert(c);
            }
        }
        return 1;
    }
    bool checkRow(vector<vector<char>>& board, int x) {
        set<int> sett;
        for (int j = 0; j < 9; j++) {
            char c = board[x][j];
            if (c != '.' && sett.contains(c))
                return 0;
            else
                sett.insert(c);
        }
        return 1;
    }
    bool checkCol(vector<vector<char>>& board, int y) {
        set<int> sett;
        for (int i = 0; i < 9; i++) {
            char c = board[i][y];
            if (c != '.' && sett.contains(c))
                return 0;
            else
                sett.insert(c);
        }
        return 1;
    }
};
