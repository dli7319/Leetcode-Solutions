class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> memo(n);
        memo[0] = vector<string>{"()"};
        for (int i = 1; i < n; i++) {
            unordered_set<string> incl;
            for (string s : memo[i-1]) {
                for (int j = 0; j < s.length(); j++) {
                    string guess = s.substr(0, j) + "()" + s.substr(j, string::npos);
                    if (incl.find(guess) == incl.end()) {
                        incl.insert(guess);
                        memo[i].push_back(guess);
                    }
                }
            }
        }
        return memo[n-1];
    }
};
