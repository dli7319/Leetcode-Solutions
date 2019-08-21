class Solution {
    fun compareVersion(version1: String, version2: String): Int {
        val dot1 = version1.indexOf(".");
        val dot2 = version2.indexOf(".");
        val majorVersion1 = if (dot1 > 0) version1.substring(0, dot1).toInt() else version1.toInt();
        val majorVersion2 = if (dot2 > 0) version2.substring(0, dot2).toInt() else version2.toInt();
        val minorVersion1 = if (dot1 > 0) version1.substring(dot1 + 1) else "0";
        val minorVersion2 = if (dot2 > 0) version2.substring(dot2 + 1) else "0";
        if (majorVersion1 > majorVersion2) {
            return 1;
        } else if (majorVersion1 < majorVersion2) {
            return -1;
        } else if (dot1 < 0 && dot2 < 0) {
            return 0;
        } else {
            return compareVersion(minorVersion1, minorVersion2);
        }
    }
}
