class Solution {
public:
    int minAddToMakeValid(string S) {
        int open = 0;
        int count = 0;
        const char *sc = S.c_str();
        int len = S.length();
        for (int i = 0; i < len; i++) {
            if (sc[i] == '(') {
                open++;
            } else {
                open--;
            }
            if (open < 0) {
                open++;
                count++;
            }
        }
        return count + open;
    }
};
