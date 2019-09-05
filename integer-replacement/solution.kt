import kotlin.math.*
class Solution {
    fun integerReplacement(n: Int): Int {
        if (n == Int.MAX_VALUE) {
            return 32
        }
        var x = n
        var ct = 0
        while (x > 1) {
            if (x and 1 == 0) {
                x = x shr 1
            } else {
                if (x and 0b10 > 0 && x - 3 > 0) {
                    x = x + 1
                } else {
                    x = x - 1
                }
            }
            ct++
        }
        return ct + max(x-1, 0)
    }
}
