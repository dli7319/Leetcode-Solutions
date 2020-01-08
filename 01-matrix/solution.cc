class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) return vector<vector<int>>();
        int big_num = INT_MAX - 99999;
        vector<vector<int>> memo1(matrix.size(), vector(matrix[0].size(), big_num));
        vector<vector<int>> memo2(matrix.size(), vector(matrix[0].size(), big_num));
        for (int i = 0; i < memo1.size(); i++) {
            for (int j = 0; j < memo1[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    memo1[i][j] = 0;
                } else if (i == 0 && j == 0) {
                    memo1[i][j] = big_num;
                } else if (i == 0) {
                    memo1[i][j] = 1 + memo1[i][j-1];
                } else if (j == 0) {
                    memo1[i][j] = 1 + memo1[i-1][j];
                } else {
                    memo1[i][j] = 1 + min(memo1[i-1][j], memo1[i][j-1]);
                }
            }
        }
        for (int i = memo2.size()-1; i >= 0; i--) {
            for (int j = memo2[0].size()-1; j >= 0; j--) {
                if (matrix[i][j] == 0) {
                    memo2[i][j] = 0;
                } else if (i == memo2.size()-1 && j == memo2[0].size()-1) {
                    memo2[i][j] = big_num;
                } else if (i == memo2.size()-1) {
                    memo2[i][j] = 1 + memo2[i][j+1];
                } else if (j == memo2[0].size()-1) {
                    memo2[i][j] = 1 + memo2[i+1][j];
                } else {
                    memo2[i][j] = 1 + min(memo2[i+1][j], memo2[i][j+1]);
                }
                memo2[i][j] = min(memo2[i][j], memo1[i][j]);
            }
        }
        return memo2;
    }
};
