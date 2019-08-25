class Solution {
public:
    int numSquares(int n) {
        int memo[n+1];
        memo[0] = 0;
        memo[1] = 1;
        for (int i = 2; i < n+1; i++) {
            int minVal = INT_MAX;
            for (int j = floor(sqrt(i)); j >= 1; j--) {
                minVal = min(minVal, 1 + memo[i - (int)pow(j, 2)]);
            }
            memo[i] = minVal;
        }
        return memo[n];
    }
};
