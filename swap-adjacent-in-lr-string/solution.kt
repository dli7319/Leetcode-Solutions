class Solution {
    fun canTransform(start: String, end: String): Boolean {
        if (start.length == 0 && end.length == 0) {
            return true
        }
        if (start.length != end.length) {
            return false
        }
        val myStart = StringBuilder(start)
        var a = 0
        var b = 0
        while (a < start.length && b < start.length) {
            val c = myStart.get(a);
            if (c == end.get(b)) {
                if (a > b && c == 'R') {
                    return false;
                } else if (a < b && c == 'L') {
                    return false;
                }
                a++;
                b++;
            } else if (c == 'X' || end.get(b) == 'X') {
                while (a < start.length && start.get(a) == 'X') {
                    a++;
                }
                while (b < end.length && end.get(b) == 'X') {
                    b++;
                }
            } else {
                return false
            }
        }
        while (a < start.length && start.get(a) == 'X') {
            a++;
        }
        while (b < end.length && end.get(b) == 'X') {
            b++;
        }
        return b == start.length && a == start.length
    }
}
