class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> checker;
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (checker.find(board[i][j]) != checker.end()) {
                        return false;
                    }
                    checker.insert(board[i][j]);
                }
            }
            checker.clear();
        }
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    if (checker.find(board[j][i]) != checker.end()) {
                        return false;
                    }
                    checker.insert(board[j][i]);
                }
            }
            checker.clear();
        }
        
        int i = 0, j = 0, limit = 3;
        while (limit <= 9) {
            i = 0;
            while (i < 9) {
                while (j < limit) {
                    if (board[i][j] != '.') {
                        if (checker.find(board[i][j]) != checker.end()) {
                            return false;
                        }
                        checker.insert(board[i][j]);
                    }
                    j++;
                }
                i++;
                if (i % 3 == 0) checker.clear();
                j = limit - 3;
            }
            j = limit;
            limit += 3;
        }
        
        return true;
    }
};
