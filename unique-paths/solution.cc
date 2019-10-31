class Solution {
public:
    int64_t factorial(int s, int k) {
        int64_t t = 1;
        for (int i = s; i <= k; i++) {
            t *= i;
        }
        return t;
    }
    int uniquePaths(int m, int n) {
        int s = min(n,m);
        int l = max(n,m);
        return factorial(l,l-1+s-1)/factorial(1,s-1);
    }
};
