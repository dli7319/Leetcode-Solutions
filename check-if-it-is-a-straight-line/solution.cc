class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dy = coordinates[1][1] - coordinates[0][1];
        int dx = coordinates[1][0] - coordinates[0][0];
        for (int i = 2; i < coordinates.size(); i++) {
            int n_dy = coordinates[i][1] - coordinates[0][1];
            int n_dx = coordinates[i][0] - coordinates[0][0];
            if (dy * n_dx != dx * n_dy) return false;
        }
        return true;
    }
};
