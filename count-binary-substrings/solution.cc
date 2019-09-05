class Solution {
public:
    int countBinarySubstrings(string s) {
        int total = 0;
        int ones = 0;
        int zeros = 0;
        bool countingOnes = false;
        int len = s.length();
        const char *sc = s.c_str();
        for (int i = 0; i < len; i++) {
            if (countingOnes != (sc[i] == '1')) {
                total += min(ones, zeros);
                if (countingOnes) {
                    zeros = 0;
                } else {
                    ones = 0;
                }
                countingOnes = !countingOnes;
            }
            if (countingOnes) {
                ones++;
            } else {
                zeros++;
            }
        }
        total += min(ones, zeros);
        return total;
    }
};
