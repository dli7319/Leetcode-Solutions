import kotlin.math.*;

class Solution {
    fun smallestRangeI(A: IntArray, K: Int): Int {
        if (A.size == 0) {
            return 0;
        }
        var unionMax = A?.max()?.minus(K) ?: 0;
        var unionMin = A?.min()?.plus(K) ?: 0;
        return max(unionMax - unionMin, 0);
    }
}
