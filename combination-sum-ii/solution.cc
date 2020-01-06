class Solution {
public:
    string v2s(vector<int>& v) {
        string s;
        for (int& i : v) {
            s = s + "," + to_string(i);
        }
        return s;
    }
    void helper(vector<int>& candidates, int target, vector<int>& st,
                vector<vector<int>>& ans, unordered_set<string>& hash,
                int position, int subsum) {
        if (subsum > target) return;
        if (subsum == target) {
            vector<int> m = st;
            std::sort(m.begin(), m.end());
            string s = v2s(m);
            if (hash.find(s) == hash.end()) {
                ans.push_back(m);
                hash.insert(s);
            }
            return;
        }
        if (position >= candidates.size()) return;
        helper(candidates, target, st, ans, hash, position+1, subsum);
        st.push_back(candidates[position]);
        helper(candidates, target, st, ans, hash, position+1, subsum + candidates[position]);
        st.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        unordered_set<string> hash;
        vector<int> st;
        helper(candidates, target, st, ans, hash, 0, 0);
        return ans;
    }
};
