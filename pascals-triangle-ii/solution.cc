class Solution {
public:
    int64_t choose(int64_t n, int64_t k) {
        if (k > n/2) return choose(n, n-k);
        if (k == 0) return 1;
        if (k == 1) return n;
        return n * choose(n-1, k-1) / k;
    }

    vector<int> getRow(int rowIndex) {
        vector<int> memo(rowIndex + 1);
        for (int i = 0; i <= (rowIndex + 1)/2; i++) {
            memo[i] = choose(rowIndex, i);
            memo[rowIndex - i] = memo[i];
        }
        return memo;
    }
};
