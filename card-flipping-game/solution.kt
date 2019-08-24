class Solution {
    fun flipgame(fronts: IntArray, backs: IntArray): Int {
        var forbidden = Array(2001) {0}
        for (i in 0 until fronts.size) {
            if (fronts[i] == backs[i]) {
                forbidden[fronts[i]] = 1
            }
        }
        var minNum = Int.MAX_VALUE
        for (i in 0 until fronts.size) {
            if (fronts[i] < minNum && forbidden[fronts[i]] < 1) {
                minNum = fronts[i]
            }
            if (backs[i] < minNum && forbidden[backs[i]] < 1) {
                minNum = backs[i]
            }
        }
        return if (minNum == Int.MAX_VALUE) 0 else minNum
    }
}
