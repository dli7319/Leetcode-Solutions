class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int min_len = INT_MAX;
        int current_sum = 0;
        while(l < nums.size()) {
            if (r >= nums.size()) {
                if (current_sum >= s)
                    min_len = min(min_len, r-l);
                current_sum -= nums[l];
                l++;
            } else if (current_sum < s) {
                current_sum += nums[r];
                r++;
            } else if (current_sum == s) {
                min_len = min(min_len, r-l);
                if (r < nums.size()) {
                    current_sum += nums[r];
                    r++;
                }
                current_sum -= nums[l];
                l++;
            } else if (current_sum > s) {
                min_len = min(min_len, r-l);
                current_sum -= nums[l];
                l++;
            }
        }
        if (min_len == INT_MAX) {
            return 0;
        }
        return min_len;
    }
};
