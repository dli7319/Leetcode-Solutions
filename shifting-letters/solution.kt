class Solution {
    fun shiftingLetters(S: String, shifts: IntArray): String {
        val cdf = Array(shifts.size) {0}
        for (i in shifts.indices) {
            cdf[i] = shifts[i].rem(26)
        }
        for (i in cdf.size - 2 downTo 0) {
            cdf[i] += cdf[i+1]
        }
        var newString = StringBuilder(S.length)
        for (i in 0 until S.length) {
            newString.append('a' + (S.get(i) - 'a' + cdf[i]).rem(26))
        }
        return newString.toString()
    }
}
