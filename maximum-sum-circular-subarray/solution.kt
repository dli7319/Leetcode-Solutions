import kotlin.math.*
class Solution {
    fun maxSubarraySumCircular(A: IntArray): Int {
        val cdf = Array(A.size) {0}
        val cdf2 = Array(A.size) {0}
        cdf[0] = A[0]
        for (i in 1 until cdf.size) {
            cdf[i] = cdf[i-1] + A[i]
        }
        cdf2[A.size - 1] = A[A.size - 1]
        for (i in A.size - 2 downTo 0) {
            cdf2[i] = cdf2[i+1] + A[i]
        }
        val cdfMax = Array(A.size) {0}
        cdfMax[0] = cdf[0]
        for (i in 1 until cdf.size) {
            cdfMax[i] = max(cdf[i], cdfMax[i-1])
        }
        val cdf2Max = Array(A.size) {0}
        cdf2Max[A.size - 1] = cdf2[A.size - 1]
        for (i in A.size - 2 downTo 0) {
            cdf2Max[i] = max(cdf2[i], cdf2Max[i+1])
        }
        val cdfLeft = Array(A.size) {0}
        cdfLeft[0] = A[0]
        for (i in 1 until A.size) {
            cdfLeft[i] = A[i] + max(cdfLeft[i], 0)
        }
        val cdfRight = Array(A.size) {0}
        cdfRight[A.size - 1] = 0
        for (i in A.size - 2 downTo 0) {
            cdfRight[i] = max(0, A[i+1] + max(0, cdfRight[i+1]))
        }

        var best = A[0]
        for (i in 0 until (A.size - 1)) {
            best = max(best, cdfMax[i] + cdf2Max[i + 1])
        }
        for (i in 0 until A.size) {
            best = max(best, cdfLeft[i] + cdfRight[i])
        }
        return best
    }
}
