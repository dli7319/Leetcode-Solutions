class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        vector<vector<uint64_t>> memo(obstacleGrid.size(), vector<uint64_t>(obstacleGrid[0].size()));
        for (int i = 0; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i][j]) {
                    memo[i][j] = 0;
                } else if (i == 0 && j == 0) {
                    memo[i][j] = 1;
                } else if (i == 0) {
                    memo[i][j] = memo[i][j-1];
                } else if (j == 0) {
                    memo[i][j] = memo[i-1][j];
                } else {
                    memo[i][j] = memo[i-1][j] + memo[i][j-1];
                }
            }
        }
        return memo.back().back();
    }
};
