class Solution {
    fun checkInclusion(s1: String, s2: String): Boolean {
        var ct = Array<Int>(26) {0}
        for (i in 0 until s1.length) {
            var c = s1.get(i) - 'a'
            ct[c] += 1
        }
        var lidx = -1
        var ridx = -1
        while (ridx + 1 < s2.length) {
            ridx += 1
            var c = s2.get(ridx) - 'a'
            if (ct[c] > 0) {
                ct[c] -= 1
                if (lidx < 0) {
                    lidx = ridx;
                }
            } else {
                if (lidx >= 0) {
                    var reset = true
                    while (lidx < ridx) {
                        var d = s2.get(lidx) - 'a'
                        if (d == c) {
                            reset = false
                            lidx +=1;
                            break;
                        } else {
                            ct[d] += 1
                            lidx += 1
                        }
                    }
                    if (reset) {
                        lidx = -1
                    }
                }
            }
            if (lidx >= 0 && ridx - lidx + 1 == s1.length) {
                return true
            }
        }
        return false
    }
}
