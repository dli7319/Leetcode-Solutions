import kotlin.math.*
class Solution {
    fun minFlipsMonoIncr(S: String): Int {
        var cdf1 = Array(S.length) {0}
        var cdf2 = Array(S.length) {0}
        cdf1[S.length-1] = 0
        for (i in S.length - 2 downTo 0) {
            cdf1[i] =
                (if (S.get(i + 1) == '0') 1 else 0) + cdf1[i+1]
        }
        cdf2[0] = 0
        for (i in 1 until S.length) {
            cdf2[i] =
                (if (S.get(i - 1) == '1') 1 else 0) + cdf2[i-1]
        }
        var result = Int.MAX_VALUE
        for (i in 0 until S.length) {
            // Change all left to 0, all right to 1
            var needToChange = cdf1[i] + cdf2[i];
            result = min(result, needToChange)
        }
        return result
    }
}
