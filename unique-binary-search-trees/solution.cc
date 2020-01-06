class Solution {
public:
    int numTrees(int n) {
        vector<int> memo(n+2);
        memo[0] = 1;
        memo[1] = 1;
        for (int i = 2; i <= n; i++) {
            int total = 0;
            for (int j = 0; j <= i-1; j++) {
                total += memo[j] * memo[i-1-j];
            }
            memo[i] = total;
        }
        return memo[n];
    }
};
