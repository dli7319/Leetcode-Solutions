import kotlin.math.*;

class Solution {
    fun minIncrementForUnique(A: IntArray): Int {
        var increments = 0
        var map = HashMap<Int, Int>()
        for (i in A.indices) {
            var num = A[i]
            var newCount = map.getOrElse(num) {0}
            num += newCount;
            while (newCount > 0) {
                val oldCount = newCount
                newCount = map.getOrElse(num) {0}
                map.put(num - oldCount, oldCount + newCount + 1)
                num += newCount;
                increments += max(oldCount, 1)
            }
            map.put(num, 1)
        }
        return increments
    }
}
