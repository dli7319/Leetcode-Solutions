class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = 0;
        int cur_max = 0;
        int largest = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            cur_max += nums[i];
            if (cur_max < 0) {
                cur_max = 0;
            }
            max_sum = max(max_sum, cur_max);
            largest = max(largest, nums[i]);
        }
        return max_sum > 0 ? max_sum : largest;
    }
};
