class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod = -9999;
        int l = 0;
        int r = 0;
        int current_prod = 1;
        while (l < nums.size() || r < nums.size()) {
            if (r < nums.size() && nums[r] == 0) {
                if (l == r || l+1 == r) {
                    l = r+1;
                    r++;
                    current_prod = 1;
                    max_prod = max(max_prod, 0);
                } else {
                    current_prod /= nums[l];
                    l++;
                    max_prod = max(max_prod, current_prod);
                }
            } else {
                if (r < nums.size()) {
                    current_prod *= nums[r];
                    max_prod = max(max_prod, current_prod);
                    r++;
                } else if (nums[l] != 0) {
                    if (l+1 < r) {
                        current_prod /= nums[l];
                        max_prod = max(max_prod, current_prod);
                    }
                    l++;
                }
            }
        }
        return max_prod;
    }
};
