class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            array<bool, 9> t;
            fill(t.begin(), t.end(), 0);
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                char v = c - '1';
                if (c != '.') {
                    if (t[v])
                        return false;
                    t[v] = 1;
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            array<bool, 9> t;
            fill(t.begin(), t.end(), 0);
            for (int j = 0; j < 9; j++) {
                char c = board[j][i];
                char v = c - '1';
                if (c != '.') {
                    if (t[v])
                        return false;
                    t[v] = 1;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                array<bool, 9> t;
                fill(t.begin(), t.end(), 0);
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        char c = board[3*i+k][3*j+l];
                        char v = c - '1';
                        if (c != '.') {
                            if (t[v])
                                return false;
                            t[v] = 1;
                        }
                    }
                }
            }
        }
        return true;
    }
};
