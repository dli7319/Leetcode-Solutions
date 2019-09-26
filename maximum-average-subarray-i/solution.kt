import kotlin.math.*
class Solution {
    fun findMaxAverage(nums: IntArray, k: Int): Double {
        var myMax = 0
        var run = 0
        for (a in 0 until k) {
            run += nums[a]
        }
        myMax = run
        for (a in k until nums.size) {
            run -= nums[a-k]
            run += nums[a]
            myMax = max(run, myMax)
        }
        return myMax.toDouble() / k
    }
}
