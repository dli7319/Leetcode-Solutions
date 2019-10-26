class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        if (triangle.size() == 1) return triangle[0][0];
        vector<vector<int>> memo(triangle.size());
        memo[0] = vector<int>{triangle[0][0]};
        int min_path = INT_MAX;
        for (int level = 1; level < triangle.size(); level++) {
            memo[level] = vector<int>(triangle[level].size());
            for (int node = 0; node < level + 1; node++) {
                int left = node > 0 ? memo[level-1][node-1] : INT_MAX;
                int right = node < level ? memo[level-1][node] : INT_MAX;
                memo[level][node] = triangle[level][node] + std::min(left, right);
                if (level == triangle.size() - 1) {
                    min_path = min(min_path, memo[level][node]);
                }
            }
        }
        return min_path;
    }
};
