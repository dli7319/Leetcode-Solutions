class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return false;
        int length = 0;
        bool started = false;
        for (int i = s.length()-1; i >= 0; i--) {
            if (s.at(i) != ' ') {
                length++;
                started = true;
            } else if (started) {
                return length;
            }
        }
        return length;
    }
};
