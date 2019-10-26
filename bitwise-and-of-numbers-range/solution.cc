class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shifts = 0;
        int leading = 0;
        while ((m >> shifts) != (n >> shifts)) {
            shifts++;
        }
        leading = (m >> shifts) << shifts;
        return leading;
    }
};
