class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return vector<int>{0};
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(1);
        for (int i = 2; i <= n; i++) {
            int start = 1 << (i-1);
            int candidate = start | ans.back();
            ans.push_back(candidate);
            for (int j = ans.size()-3; j >= 0; j--) {
                candidate ^= (ans[j] ^ ans[j+1]);
                ans.push_back(candidate);
            }
        }
        return ans;
    }
};
