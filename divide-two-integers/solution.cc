class Solution {
public:
    int divide(int dividend, int divisor) {
        int64_t abs_dividend = abs((int64_t)dividend);
        int64_t abs_divisor = abs((int64_t)divisor);
        if (abs_dividend < abs_divisor) return 0;
        int64_t best = 0;
        int64_t best_amount = 0;
        int64_t val = abs_divisor;
        int64_t amount = 1;
        bool negative = (divisor < 0 && dividend >= 0) ||
            (divisor >= 0 && dividend < 0);
        while (best <= abs_dividend - val) {
            if (best > abs_dividend - val - val) {
                best += val;
                best_amount += amount;
                val = abs_divisor;
                amount = 1;
            } else {
                val = val + val;
                amount = amount + amount;
            }
        }
        if (negative) {
            return min(max(-best_amount, (int64_t)INT_MIN), (int64_t)INT_MAX);
        }
        return min(max(best_amount, (int64_t)INT_MIN), (int64_t)INT_MAX);
    }
};
