class Solution {
    fun addStrings(num1: String, num2: String): String {
        var result = StringBuilder()
        var carry = 0
        var i = num1.length - 1
        var j = num2.length - 1
        while (i >= 0 || j >= 0) {
            var newNum = carry
            if (i >= 0 && j >= 0) {
                newNum += (num1.get(i) - '0') + (num2.get(j) - '0')
            } else if (i >= 0) {
                newNum += num1.get(i) - '0'
            } else {
                newNum += num2.get(j) - '0'
            }
            carry = newNum / 10
            result.append((newNum.rem(10)).toString())
            i = i-1
            j = j-1
        }
        if (carry > 0) {
            result.append(carry.toString())
        }
        return result.reverse().toString()
    }
}
