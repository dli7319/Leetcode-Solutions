
data class Position(var x: Int, var y: Int) {}

class Solution {
    fun judgeCircle(moves: String): Boolean {
        var pos = Position(0,0);
        var movesArr = moves.toCharArray();
        for (move in movesArr) {
            if (move == 'U') {
                pos.y++;
            } else if (move == 'D') {
                pos.y--;
            } else if (move == 'L') {
                pos.x--;
            } else if (move == 'R') {
                pos.x++;
            }
        }
        return pos == Position(0,0);
    }
}
