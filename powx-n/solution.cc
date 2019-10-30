class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n < 0) return 1.0 / (x * myPow(x, -n-1));
        int c = 1;
        double newt = x;
        while (c < n / 2) {
            newt *= newt;
            c *= 2;
        }
        return newt * myPow(x, n-c);
    }
};
