class Solution {
    fun firstUniqChar(s: String): Int {
        val count = Array(26) {0}
        for (i in 0 until s.length) {
            count[s.get(i) - 'a']++
        }
        for (i in 0 until s.length) {
            if (count[s.get(i) - 'a'] == 1) {
                return i
            }
        }
        return -1
    }
}
