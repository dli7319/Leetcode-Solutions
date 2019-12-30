class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_set<string> memo1;
        unordered_set<string> memo2;
        for (int i = 0; i < digits.length(); i++) {
            char c = digits.at(i) - '0';
            vector<char> p;
            if (c <= 6) {
                char d = c - 2;
                p = vector<char>{(char)(3*d + 'a'),
                                 (char)(3*d + 'a' + 1),
                                 (char)(3*d + 'a' + 2) };
            } else if (c == 7) {
                p = vector<char>{'p', 'q', 'r', 's'};
            } else if (c == 8) {
                p = vector<char>{'t', 'u', 'v'};
            } else if (c == 9) {
                p = vector<char>{'w', 'x', 'y', 'z'};
            }
            for (auto new_c : p) {
                if (i == 0) {
                    memo2.insert(string(1, new_c));
                } else {
                    for (auto st : memo1) {
                        memo2.insert(st + string(1, new_c));
                        // cout << "Adding: " << (st + string(1, new_c)) << endl;
                    }
                }
            }
            memo1 = std::move(memo2);
        }
        vector<string> ans;
        for (auto a : memo1) {
            ans.push_back(a);
        }
        return ans;
    }
};
