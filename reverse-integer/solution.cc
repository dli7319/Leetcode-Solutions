class Solution {
public:
    int reverse(int x) {
        bool negative = x < 0;
        if (negative) {
            if (x < -INT_MAX) {
                return 0;
            }
            x *= -1;
        }
        int a = 0;
        while (x > 0) {
            if (a > INT_MAX / 10) {
                return 0;
            }
            a *= 10;
            a += (x % 10);
            x /= 10;
        }
        if (negative) {
            a *= -1;
        }
        return a;
    }
};
