class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int64_t sm = 1;
        int64_t lg = x;
        while (sm < lg-1) {
            int64_t middle = (sm + lg) / 2;
            if (middle * middle > x) {
                lg = middle;
            } else {
                sm = middle;
            }
        }
        return sm;
    }
};
