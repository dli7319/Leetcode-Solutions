class Solution {
    fun numUniqueEmails(emails: Array<String>): Int {
        return emails.map({
            it.split("@").mapIndexed {idx, x ->
                if (idx == 0)
                    x.replace(".", "").replace("""\+.*""".toRegex(),"")
                else
                    x
                }.joinToString("@")
        }).distinct().size
    }
}
