class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        queue<array<int, 2>> to_check;
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') {
                to_check.push(array<int, 2>{i, 0});
            }
            if (board[i][board[0].size()-1] == 'O') {
                to_check.push(array<int, 2>{i, board[0].size()-1});
            }
        }
        for (int i = 0; i < board[0].size(); i++) {
            if (board[0][i] == 'O') {
                to_check.push(array<int, 2>{0, i});
            }
            if (board[board.size()-1][i] == 'O') {
                to_check.push(array<int, 2>{board.size()-1, i});
            }
        }
        while (!to_check.empty()) {
            array<int, 2> pt = to_check.front();
            to_check.pop();
            board[pt[0]][pt[1]] = '1';
            if (pt[0] > 0 && board[pt[0]-1][pt[1]] == 'O') {
                to_check.push(array<int, 2>{pt[0]-1, pt[1]});
            }
            if (pt[0]+1 < board.size() && board[pt[0]+1][pt[1]] == 'O') {
                to_check.push(array<int, 2>{pt[0]+1, pt[1]});
            }
            if (pt[1] > 0 && board[pt[0]][pt[1]-1] == 'O') {
                to_check.push(array<int, 2>{pt[0], pt[1]-1});
            }
            if (pt[1]+1 < board[0].size() && board[pt[0]][pt[1]+1] == 'O') {
                to_check.push(array<int, 2>{pt[0], pt[1]+1});
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
