class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<char>> memo(s.length());
        int max = 0;
        int max_start = 0;
        int max_end = 0;
        for (int i = 0; i < s.length(); i++) {
            memo[i] = vector<char>(s.length());
            std::fill(memo[i].begin(), memo[i].end(), false);
        }

        for (int j = 0; j < s.length(); j++) {
            for (int i = j; i >= 0; i--) {
                if (i == j) {
                    memo[i][j] = true;
                } else if (s.at(i) == s.at(j)) {
                    if (i+1 == j || memo[i+1][j-1]) {
                        memo[i][j] = true;
                        if (j-i+1 > max) {
                            max = j-i+1;
                            max_start = i;
                            max_end = j;
                        }
                    }
                }
            }
        }

        return s.substr(max_start, max_end-max_start+1);
    }
};
