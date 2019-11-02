class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> t;
        unordered_map<string, int> memo;
        for (auto str : strs) {
           array<int,26> ct;
            std::fill(ct.begin(), ct.end(), 0);
            for (int i = 0; i < str.length(); i++) {
                auto ch = str.at(i);
                ct[ch - 'a']++;
            }
            ostringstream st;
            for (int i = 0; i < 26; i++) {
                st << ct[i] << ",";
            }
            if (memo.find(st.str()) == memo.end()) {
                t.push_back(vector<string>());
                t[t.size()-1].reserve(5);
                memo[st.str()] = t.size()-1;
            }
            t[memo[st.str()]].push_back(str);
        }
        return t;
    }
};
