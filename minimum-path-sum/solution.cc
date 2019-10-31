class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int h = grid.size();
        int w = grid[0].size();
        vector<vector<int>> memo(h);
        memo[0].resize(w);
        memo[0][0] = grid[0][0];
        for (int j = 1; j < w; j++) {
            memo[0][j] = grid[0][j] + memo[0][j-1];
        }
        for (int i = 1; i < h; i++) {
            memo[i].resize(w);
            memo[i][0] = grid[i][0] + memo[i-1][0];
            for (int j = 1; j < w; j++) {
                memo[i][j] = grid[i][j] + min(memo[i-1][j], memo[i][j-1]);
            }
        }
        return memo[h-1][w-1];
    }
};
