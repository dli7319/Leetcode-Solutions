class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.empty() && s2.empty() && s3.empty()) {
            return true;
        }
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        if (l3 != l1 + l2) {
            return false;
        }
        std::vector<std::vector<int>> memo(l1+1);
        for (int i = 0; i <= l1; i++) {
            memo[i] = std::vector<int>(l2+1);
        }
        for (int i = 0; i <= l1; i++) {
            for (int j = 0; j <= l2; j++) {
                if (i == 0 && j == 0) {
                    memo[0][0] = 1;
                } else {
                    memo[i][j] =
                        (i > 0 && s1.at(i-1) == s3.at(i+j-1) && (i == 0 || memo[i-1][j])) ||
                        (j > 0 && s2.at(j-1) == s3.at(i+j-1) && (j == 0 || memo[i][j-1]));
                }
            }
        }
        return memo[l1][l2] > 0;
    }
};
