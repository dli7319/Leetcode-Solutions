class Solution {
public:
    int countVowelPermutation(int n) {
        int mod_val = pow(10,9) + 7;
        vector<vector<int64_t>> memo(n+1);
        memo[1].resize(5);
        for (int i = 0; i < 5; i++) {
            memo[1][i] = 1;
        }
        for (int i = 2; i <= n; i++) {
            memo[i].resize(5);
            memo[i][0] = memo[i-1][1];
            memo[i][1] = (memo[i-1][0] + memo[i-1][2]) % mod_val;
            memo[i][2] = (memo[i-1][0] + memo[i-1][1] + memo[i-1][3] + memo[i-1][4]) % mod_val;
            memo[i][3] = (memo[i-1][2] + memo[i-1][4]) % mod_val;
            memo[i][4] = memo[i-1][0];
        }
        int s = 0;
        for (int i = 0; i < 5; i++) {
            s = (s + memo[n][i]) % mod_val;
        }
        return s;
    }
};
