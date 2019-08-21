import kotlin.text.*;
import kotlin.math.*;

class Solution {
    fun reverseStr(s: String, k: Int): String {
        val len = s.length;
        var finalString = StringBuilder(len);
        var idx = 0;
        while (idx < len) {
            var nextIndex = min(len, idx + k);
            if (idx.rem(2*k) == 0) {
                finalString.append(s.substring(idx, nextIndex).reversed());
            } else {
                finalString.append(s.substring(idx, nextIndex));
            }
            idx = nextIndex;
        }
        return finalString.toString();
    }
}
