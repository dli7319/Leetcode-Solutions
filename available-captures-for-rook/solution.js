/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    var rookPos = [-1,-1];
    var count = 0;
    for (let i = 0; i < 8; i++) {
        for (let j = 0; j < 8; j++) {
            if (board[i][j] == 'R') {
                rookPos = [i,j];
                i = 99;
                j = 99;
            }
        }
    }
    for (let i = rookPos[0] + 1; i < 8; i++) {
        if (board[i][rookPos[1]] == 'p') {
            count++;
            i = 99;
        } else if (board[i][rookPos[1]] == 'B') {
            i = 99;
        }
    }
    for (let i = rookPos[0] - 1; i >= 0 ; i--) {
        if (board[i][rookPos[1]] == 'p') {
            count++;
            i = -99;
        } else if (board[i][rookPos[1]] == 'B') {
            i = -99;
        }
    }
    for (let j = rookPos[1] + 1; j < 8 ; j++) {
        if (board[rookPos[0]][j] == 'p') {
            count++;
            j = 99;
        } else if (board[rookPos[0]][j] == 'B') {
            j = 99;
        }
    }
    for (let j = rookPos[1] - 1; j >= 0 ; j--) {
        if (board[rookPos[0]][j] == 'p') {
            count++;
            j = -99;
        } else if (board[rookPos[0]][j] == 'B') {
            j = -99;
        }
    }
    return count;
};
