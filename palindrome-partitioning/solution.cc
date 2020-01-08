class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) return vector<vector<string>>();
        vector<vector<bool>> memo(s.length(), vector<bool>(s.length(), false));
        for (int i = s.length(); i >= 0; i--) {
            for (int j = i; j < s.length(); j++) {
                if (i == j) {
                    memo[i][j] = true;
                } else if (i+1 == j) {
                    memo[i][j] = s.at(i) == s.at(j);
                } else {
                    memo[i][j] = s.at(i) == s.at(j) && memo[i+1][j-1];
                }
            }
        }
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                cout << memo[i][j] << ",";
            }
            cout << endl;
        }
        unordered_map<int, vector<vector<string>>> prev;
        prev[0].push_back(vector<string>{s.substr(0,1)});
        for (int i = 1; i < s.length(); i++) {
            prev[i] = vector<vector<string>>();
            for (int j = 0; j <= i; j++) {
                // cout << "i,j " << i << "," << j << endl;
                if (memo[j][i] && j == 0) {
                    prev[i].push_back(vector<string>{s.substr(0, i+1)});
                    // cout << "Push back " << s.substr(0, i+1) << endl;
                } else if (memo[j][i]) {
                    string my_substr = s.substr(j, (i-j)+1);
                    vector<vector<string>> exist = prev[j-1];
                    for (vector<string>& v : exist) {
                        v.push_back(my_substr);
                        prev[i].push_back(v);
                        // cout << "pushing: " << my_substr << endl;
                    }
                }
            }
        }
        return prev[s.length()-1];
    }
};
