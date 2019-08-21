import kotlin.text.*;

class Solution {
    fun reverseWords(s: String): String {
        var finalStr = StringBuilder();
        var words = s.split(" ");
        for (i in 0 until words.size) {
            // println(words[i]);
            finalStr.append(words[i].reversed());
            if (i < words.size - 1) {
                finalStr.append(" ");
            }
        }
        return finalStr.toString();
    }
}
