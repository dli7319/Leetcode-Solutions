class Solution {
public:
    string convertToTitle(int n) {
        ostringstream a;
        while (n > 0) {
            int b = (n-1) % 26;
            a << (char)('A' + b);
            n = (n-1) / 26;
        }
        string ans = a.str();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
