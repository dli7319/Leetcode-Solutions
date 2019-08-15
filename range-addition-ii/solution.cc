class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minM = m;
        int minN = n;
        for (vector<int> pos : ops) {
            int x = pos[0];
            int y = pos[1];
            if (y >= 0 && x >= 0) {
                minM = minM < x ? minM : x;
                minN = minN < y ? minN : y;
            }
        }
        return minM * minN;
    }
};
