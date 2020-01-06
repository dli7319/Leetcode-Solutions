class Solution {
public:
    void helper(vector<vector<int>>& ans, int n, int m, vector<int>& st, int k) {
        if (st.size() == k) {
            ans.push_back(st);
        }
        if (st.size() >= k) {
            return;
        }
        if (m > n) {
            return;
        }
        helper(ans, n, m+1, st, k);
        st.push_back(m);
        helper(ans, n, m+1, st, k);
        st.pop_back();
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> st;
        helper(ans, n, 1, st, k);
        return ans;
    }
};
