import kotlin.math.*
class Solution {
    fun subsets(nums: IntArray): List<List<Int>> {
        var re = MutableList<MutableList<Int>>(2.0.pow(nums.size).toInt()) {mutableListOf<Int>()}
        if (nums.size == 0) {
            return re
        } else if (nums.size == 1) {
            return listOf(listOf<Int>(), listOf(nums[0]))
        }
        re[1] = mutableListOf(nums[0])
        for (i in 1 until nums.size) {
            for (j in 0 until 2.0.pow(i).toInt()) {
                var prevIdx = j
                re[2.0.pow(i).toInt() + j] = re[prevIdx].toMutableList()
                re[2.0.pow(i).toInt() + j].add(nums[i])
            }
        }

        return re
    }
}
