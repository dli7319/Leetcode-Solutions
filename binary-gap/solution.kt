import kotlin.math.*;

class Solution {
    fun binaryGap(N: Int): Int {
        var longest : Int = 0;
        var foundOne = false;
        var count : Int = 0;
        var n = N;
        while (n > 0) {
            if (foundOne) {
                if (n and 1 > 0) {
                    longest = max(count, longest);
                    count = 1;
                } else {
                    count++;
                }
            } else {
                if (n and 1 > 0) {
                    foundOne = true;
                    count = 1;
                }
            }
            n = n shr 1;
        }
        return longest;
    }
}
