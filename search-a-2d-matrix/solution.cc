class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Note that it would be faster to use 2x binary search instead
        // but i'm too lazy to implement it right now.
        // If your 2d matrix is that large, you might have bigger problems
        if (matrix.empty()) return false;
        for (int i = 0; i < matrix.size(); i++) {
            if (i == matrix.size()-1 || matrix[i+1][0] > target) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    if (matrix[i][j] == target) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
