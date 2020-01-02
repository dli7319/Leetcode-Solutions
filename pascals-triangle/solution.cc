class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> memo(numRows);
        for (int i = 0; i < numRows; i++) {
            memo[i] = vector<int>(i+1);
            memo[i][0] = 1;
            memo[i][i] = 1;
            for (int j = 1; j < i; j++) {
                memo[i][j] = memo[i-1][j-1] + memo[i-1][j];
            }
        }
        return memo;
    }
};
