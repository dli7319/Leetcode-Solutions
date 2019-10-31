class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return vector<int>();
        vector<int> memo(matrix.size() * matrix[0].size());
        array<int, 2> pos{0,0};
        memo[0] = matrix[pos[0]][pos[1]];
        int h = matrix.size();
        int w = matrix[0].size();
        for (int i = 1; i < memo.size(); i++) {
            if (pos[1] >= pos[0] && w-1 - (pos[1] + 1) >= pos[0] && pos[0] < (h+1)/2) {
                pos[1]++;
                // cout << "right" << endl;
            } else if (w-1 - (pos[1] + 1) < pos[0] && pos[0] < (h - (w-pos[1])) && pos[1] >= w/2) {
                pos[0]++;
                // cout << "down" << endl;
            } else if (pos[0] >= (h - (w-pos[1])) && (pos[1] - 1) >= (h-1-pos[0])) {
                pos[1]--;
                // cout << "left" << endl;
            } else if ((pos[1] - 1) < (h-1-pos[0]) && pos[0] - 1 > pos[1]) {
                pos[0]--;
                // cout << "up" << endl;
            } else {
                pos[1]++;
                // cout << "right2" << endl;
            }
            memo[i] = matrix[pos[0]][pos[1]];
            // cout << "Pos " << pos[0] << ", " << pos[1] << endl;
        }
        return memo;
    }
};
