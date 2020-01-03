class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length()) return -1;
        if (needle.empty()) return 0;
        int start_idx = 0;
        while (haystack.length() - needle.length() >= start_idx) {
            int matching = 0;
            while (matching < needle.length() &&
                  haystack.at(start_idx + matching) == needle.at(matching))
                matching++;
            if (matching == needle.length()) return start_idx;
            start_idx++;
        }
        return -1;
    }
};
